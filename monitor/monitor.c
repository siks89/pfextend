#include <stdio.h>
#include "mnt_common.h"
#include "mnt_token_list.h"
#include <stdlib.h>
#include <string.h>
#include "cmp.h"
#include <inttypes.h>

/*
 * List of commands. 
 */
#define CMD_SEQUENCE {C_REG_SP, \
                      C_REG_RP, \
                      C_DATA_STATE, \
                      C_END};

int main()
{
    uint16_t cmd_sequence[] = CMD_SEQUENCE;
    uint8_t cmd_sequence_size = sizeof(cmd_sequence) / sizeof(uint16_t);
    uint8_t cmd_sequence_cnt = 0;

    char mnt_send_buffer[MNT_MQ_MAX_MSG_LENGTH];
    char mnt_recv_buffer[MNT_MQ_MAX_MSG_LENGTH + 1];
    uint16_t cmd;
    uint16_t ret_cmd;
    uint64_t value;
    ssize_t mnt_recv_size;
    bool fl_monitor = true;

    uint8_t buffer[MNT_MQ_MAX_MSG_LENGTH * 3];
    struct state_data ret_data;
    ret_data.token_name = (char *)buffer;
    ret_data.data_stack = &buffer[MNT_MQ_MAX_MSG_LENGTH * 1];
    ret_data.return_stack = &buffer[MNT_MQ_MAX_MSG_LENGTH * 2];

    printf("Monitor:\n");

    /* start buffers */

    if(!mnt_com_cli_start(&mnt_mq_in, MNT_MQ_CLI_NAME))
    {
        return EXIT_FAILURE;
    }
    if(!mnt_com_cli_start(&mnt_mq_out, MNT_MQ_SRV_NAME))
    {
        return EXIT_FAILURE;
    }

    /* main request loop */

    while(fl_monitor)
    {
        if(!(cmd_sequence_cnt < cmd_sequence_size))
        {
            // reset the command sequence
            cmd_sequence_cnt = 0; 
        }

        /* send a request  */
        
        if(!mnt_build_request(mnt_send_buffer, cmd_sequence[cmd_sequence_cnt]))
        {
            fprintf(stderr, "Error: Build request!\n"); 
            return EXIT_FAILURE;
        }
        if(mq_send(mnt_mq_out,
                    mnt_send_buffer,
                    sizeof(mnt_send_buffer), 0) < 0)
        {
            perror("Error: mq_seng");
            return EXIT_FAILURE;
        }

        /* wait for response */

        mnt_recv_size = mq_receive(
                            mnt_mq_in,
                            mnt_recv_buffer,
                            MNT_MQ_MAX_MSG_LENGTH,
                            NULL);
        if(mnt_recv_size < 0)
        {
            perror("Error: mq_received");
            return EXIT_FAILURE;
        }

        /* process response */

        cmd = C_NULL;
        if(!mnt_parse_cmd(mnt_recv_buffer, &cmd))
        {
            return EXIT_FAILURE;
        }

        switch(cmd)
        {
        case C_DATA_STATE: 
            if(!mnt_parse_state_message(mnt_recv_buffer, &ret_data))
            {
                fprintf(stderr, "Error: mnt_parse_state_message!\n");
                return EXIT_FAILURE;
            }

            ret_data.token_name[ret_data.token_name_size] = '\0';
            printf("%s:", ret_data.token_name);
            echo_msg_uint64((uint64_t *)ret_data.data_stack,
                ret_data.data_stack_size / sizeof(uint64_t));
            printf(":");
            echo_msg_uint64((uint64_t *)ret_data.return_stack,
                ret_data.return_stack_size / sizeof(uint64_t));
            printf("\n");

            break;

        case C_REG_SP:
        case C_REG_RP:
            if(!mnt_parse_cell_message(mnt_recv_buffer, &ret_cmd, &value))
            {
                printf("Error: mnt_parse_cell_message!\n");
                return EXIT_FAILURE;
            }
            printf("%"PRIu64":", value);

            break;
        case C_END:
            break;

        case C_EXIT:
            fl_monitor = false;
            break;

        case C_NULL:
            fprintf(stderr, "Error: C_NULL received!\n");
            break;

        default:
            fprintf(stderr, "Error: Unknown command [%"PRIu16"]!\n",
                cmd);
            return EXIT_FAILURE;
        }

        cmd_sequence_cnt++;
    }

    /* stop communication */

    mnt_com_cli_stop(mnt_mq_in);
    mnt_com_cli_stop(mnt_mq_out);
    
    return EXIT_SUCCESS;
}
