#include "mnt_common.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

bool mnt_com_cli_start(mqd_t *mq, const char *name)
{
    *mq = mq_open(name, O_RDWR);
    if((int)(*mq) == -1)
    {
        perror("Error: mq_open");
        return false;
    }
    return true;
}

bool mnt_com_cli_stop(mqd_t mq)
{
    if(mq_close(mq) < 0)
    {
        perror("Error: mq_close");
        return false;
    }
    return true;
}

bool mnt_com_srv_start(mqd_t *mq, const char *name)
{
    struct mq_attr attr;

    /* try to unlink the message queue */
    mq_unlink(name);

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MNT_MQ_MAX_MSG_LENGTH;
    attr.mq_curmsgs = 0;

    *mq = mq_open(name, O_CREAT | O_RDWR, 0644, &attr);
    if((int)(*mq) == -1)
    {
        printf("NEW\n");
        perror("Error: mq_open");
        return false;
    }

    return true;
}

bool mnt_com_srv_stop(mqd_t mq, const char *name)
{
    if(mq_close(mq) < 0)
    {
        perror("Error: mq_close"); 
    }
    if(mq_unlink(name) < 0)
    {
        perror("Error: mq_unlink"); 
    }
    return true;
}

bool mnt_build_request(char *buffer, const uint16_t cmd)
{
    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_writer_pointer_reset();

    if(!cmp_write_array(&cmp, 1))
    {
        fprintf(stderr, "Error: mnt_build_cmd: cmp_write_array!\n");
        return false;
    }

    if(!cmp_write_u16(&cmp, cmd))
    {
        fprintf(stderr, "Error: mnt_build_cmd: cmp_write_u16!\n");
        return false;
    }

    return true;
}

bool mnt_parse_request(char *buffer, uint16_t *cmd)
{
    uint32_t arr_size;

    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_reader_pointer_reset();

    if(!cmp_read_array(&cmp, &arr_size))
    {
        fprintf(stderr, "Error: mnt_parse_cmd: cmp_read_array!\n");
        return false;
    }
    if(arr_size != 1)
    {
        fprintf(stderr, "Error: mnt_parse_cmd: command form!\n");
        return false;
    }

    /* get command */ 

    if(!cmp_read_u16(&cmp, cmd))
    {
        fprintf(stderr, "Error: mnt_parse_cmd: cmp_read_u16!\n");
        return false;
    }

    return true;
}

bool mnt_build_cell_message(char *buffer,
                            const uint16_t cmd,
                            const uint64_t cell)
{
    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_writer_pointer_reset();

    if (!cmp_write_array(&cmp, 2))
    {
        fprintf(stderr, "Error: mnt_build_cell_message: cmp_write_array!\n");
        return false;
    }

    if(!cmp_write_u16(&cmp, cmd))
    {
        fprintf(stderr, "Error: mnt_build_cell_message: cmp_write_u16!\n");
        return false;
    }

    if(!cmp_write_u64(&cmp, cell))
    {
        fprintf(stderr, "Error: mnt_build_cell_message: cmp_write_u64!\n");
        return false;
    }

    return true;
}

bool mnt_parse_cell_message(char *buffer,
                                uint16_t *cmd,
                                uint64_t *cell)
{
    uint32_t arr_size;

    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_reader_pointer_reset();

    if(!cmp_read_array(&cmp, &arr_size))
    {
        fprintf(stderr, "Error: mnt_parse_cell_message: cmp_read_array!\n");
        return false;
    }
    if(arr_size != 2)
    {
        fprintf(stderr, "Error: mnt_parse_cell_message: command form!\n");
        return false;
    }

    /* check command */ 

    if(!cmp_read_u16(&cmp, cmd))
    {
        fprintf(stderr, "Error: mnt_parse_cell_message: cmp_read_u16!\n");
        return false;
    }

    /* get data */ 

    if(!cmp_read_u64(&cmp, cell))
    {
        fprintf(stderr, "Error: mnt_parse_cell_message: cmp_write_u64!\n");
        return false;
    }

    return true;
}

bool mnt_build_state_message(char *buffer,
                        const struct state_data data)
{
    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_writer_pointer_reset();

    if (!cmp_write_array(&cmp, 4))
    {
        fprintf(stderr, "Error: mnt_build_cell_message: cmp_write_array!\n");
        return false;
    }

    if(!cmp_write_u16(&cmp, C_DATA_STATE))
    {
        return false;
    }

    if(!cmp_write_str(&cmp, data.token_name, data.token_name_size))
    {
        fprintf(stderr, "Error: mnt_build_state_message: cmp_write_str!\n");
        return false;
    }

    if(!cmp_write_bin(&cmp, data.data_stack, data.data_stack_size))
    {
        fprintf(stderr, "Error: mnt_build_state_message: cmp_write_bin!\n");
        return false;
    }

    if(!cmp_write_bin(&cmp, data.return_stack, data.return_stack_size))
    {
        fprintf(stderr, "Error: mnt_build_state_message: cmp_write_bin!\n");
        return false;
    }

    return true;
}

bool mnt_parse_state_message(char *buffer,
                             struct state_data *data)
{
    uint32_t arr_size;
    uint16_t cmd;

    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_reader_pointer_reset();

    if(!cmp_read_array(&cmp, &arr_size))
    {
        fprintf(stderr, "Error: mnt_parse_state_message: cmp_read_array!\n");
        return false;
    }
    if(arr_size != 4)
    {
        fprintf(stderr, "Error: mnt_parse_state_message: command form!\n");
        return false;
    }

    /* check command */ 

    if(!cmp_read_u16(&cmp, &cmd))
    {
        fprintf(stderr, "Error: mnt_parse_state_message: cmp_read_u16!\n");
        return false;
    }
    if(cmd != C_DATA_STATE)
    {
        fprintf(stderr, "Error: mnt_parse_state_message: command!\n");
        return false;
    }

    /* get data */

    data->token_name_size = MNT_MQ_MAX_MSG_LENGTH;
    if(!cmp_read_str(&cmp, data->token_name, &data->token_name_size))
    {
        fprintf(stderr, "Error: mnt_parse_state_message: cmp_read_str!\n");
        return false;
    }

    data->data_stack_size = MNT_MQ_MAX_MSG_LENGTH;
    if(!cmp_read_bin(&cmp, data->data_stack, &data->data_stack_size))
    {
        fprintf(stderr, "Error: mnt_parse_state_message: cmp_read_str!\n");
        return false;
    }

    data->return_stack_size = MNT_MQ_MAX_MSG_LENGTH;
    if(!cmp_read_bin(&cmp, data->return_stack, &data->return_stack_size))
    {
        fprintf(stderr, "Error: mnt_parse_state_message: cmp_read_str!\n");
        return false;
    }

    return true;
}

bool mnt_parse_cmd(char *buffer, uint16_t *cmd)
{
    uint32_t arr_size;

    cmp_ctx_t cmp;
    cmp_init(&cmp, (void *)buffer, cmp_buffer_reader, cmp_buffer_writer);
    cmp_reader_pointer_reset();

    if(!cmp_read_array(&cmp, &arr_size))
    {
        fprintf(stderr, "Error: mnt_parse_cmd: cmp_read_array!\n");
        return false;
    }
    if(arr_size  < 2)
    {
        fprintf(stderr, "Error: mnt_parse_cmd: command form!\n");
        return false;
    }

    /* check command */ 

    if(!cmp_read_u16(&cmp, cmd))
    {
        fprintf(stderr, "Error: mnt_parse_cmd: cmp_read_u16!\n");
        return false;
    }

    return true;
}

static size_t cmp_reader_pointer = 0;
static size_t cmp_writer_pointer = 0;

void cmp_reader_pointer_reset(void)
{
    cmp_reader_pointer = 0; 
}

void cmp_writer_pointer_reset(void)
{
    cmp_writer_pointer = 0;
}

bool cmp_buffer_reader(cmp_ctx_t *ctx, void *data, size_t count)
{
    memcpy(data, (void *)(((char *)ctx->buf) + cmp_reader_pointer), count);
    cmp_reader_pointer += count;

    return true;
}

size_t cmp_buffer_writer(cmp_ctx_t *ctx, const void *data, size_t count)
{
    memcpy((void *)(((char *)ctx->buf) + cmp_writer_pointer), data, count);
    cmp_writer_pointer += count;
    return true;
}

void echo_msg_8b(const uint8_t *buffer, const size_t size)
{
    size_t i = 0;
    while(i < size)
    {
        printf("0x%02x, ", (uint8_t)buffer[i]);
        i++;    
    }
}

void echo_msg_uint64(const uint64_t *buffer, const size_t size)
{
    size_t i = 0;
        while(i < size)
    {
        printf(",%" PRIu64, (uint64_t)buffer[i]);
        i++;    
    }
}

void countedStringToCString( const char *countStr, char *cStr)
{
    char *firstChar;
    intptr_t len;

    firstChar = (char *)countStr + 1;
    len = *countStr & 0x1F;

    memcpy(cStr, firstChar, len);
    cStr[len] = '\0';
}
