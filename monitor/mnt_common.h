#ifndef H_MNT_COMMON
#define H_MNT_COMMON

#include <stddef.h>
#include "cmp.h"
#include <mqueue.h>
#include <stdbool.h>

#define MNT_MQ_SRV_NAME "/mnt_mq_srv"
#define MNT_MQ_CLI_NAME "/mnt_mq_cli"

#define MNT_MQ_MAX_MSG_LENGTH 512

#define MNT_COMMAND_TAG "cmd"
#define MNT_COMMAND_TAG_SIZE 3

/* request commands */
enum COMMAND_REQ
{
    C_NULL = 0,
    C_REG_SP,
    C_REG_RP,
    C_DATA_STATE,
    C_END,
    C_MAX
};

/* response commands */
enum COMMAND_RSP
{
    C_EXIT = C_MAX + 1
};

/* communication */

bool mnt_fl;

mqd_t mnt_mq_in;
mqd_t mnt_mq_out;

/**
 * @brief Start com
 */
bool mnt_com_cli_start(mqd_t *mq, const char *name);
bool mnt_com_cli_stop(mqd_t mq);

bool mnt_com_srv_start(mqd_t *mq, const char *name);
bool mnt_com_srv_stop(mqd_t mq, const char *name);


/* message formation */

/**
 * @brief Build a request message.
 * @param buffer A buffer used for the request message storage.
 *      Has to be large enough.
 * @param cmd A command used in the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_build_request(char *buffer, const uint16_t cmd);
/**
 * @brief Parse a request message.
 * @param buffer A buffer that contains the request message.
 * @param cmd A command returned from the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_parse_request(char *buffer, uint16_t *cmd);

/**
 * @brief Build a cell message.
 * @param buffer A buffer used for the cell message storage.
 *      Has to be large enough.
 * @param cmd A command used in the message.
 * @param cell The data used in the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_build_cell_message(char *buffer,
                            const uint16_t cmd,
                            const uint64_t cell);
/**
 * @brief Parse a cell message.
 * @param buffer A buffer that contains the cell message.
 * @param cmd A command returned from the message.
 * @param cell The data returned from the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_parse_cell_message(char *buffer,
                            uint16_t *cmd,
                            uint64_t *cell);

/*
 * The structure contains information regarding the PForth state.
 */
struct state_data
{
    char *token_name;
    uint32_t token_name_size;
    uint8_t *data_stack;
    uint32_t data_stack_size;
    uint8_t *return_stack;
    uint32_t  return_stack_size;
};

/**
 * @brief Build a state message.
 * @param buffer A buffer used for the state message storage.
 *      Has to be large enough.
 * @param data The state data used in the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_build_state_message(char *buffer,
                             const struct state_data data);
/**
 * @brief Parse a state message.
 * @param buffer A buffer that contains the state message.
 * @param data The state data returned from the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_parse_state_message(char *buffer,
                             struct state_data *data);
/**
 * @brief Parse a command from the message.
 * @param buffer A buffer that contains the message.
 * @param cmd The command returned from the message.
 * @param Returns false if message transformation was not successful.
 */
bool mnt_parse_cmd(char *buffer, uint16_t *cmd);

/* CMP related functions */

bool cmp_buffer_reader(cmp_ctx_t *ctx, void *data, size_t count);
size_t cmp_buffer_writer(cmp_ctx_t *ctx, const void *data, size_t count);

void cmp_reader_pointer_reset(void);
void cmp_writer_pointer_reset(void);


/* debug */

void echo_msg_8b(const uint8_t *buffer, const size_t size);
void echo_msg_uint64(const uint64_t *buffer, const size_t size);
void countedStringToCString( const char *countStr, char *cStr);

#endif
