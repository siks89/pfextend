#include "mnt_token_list.h"

char *mnt_token_list[] = 
{   
    "ID_EXIT",
    "ID_1MINUS",
    "ID_1PLUS",
    "ID_2DUP",
    "ID_2LITERAL",
    "ID_2LITERAL_P",
    "ID_2MINUS",
    "ID_2OVER",
    "ID_2PLUS",
    "ID_2SWAP",
    "ID_2_R_FETCH",
    "ID_2_R_FROM",
    "ID_2_TO_R",
    "ID_ACCEPT_P",
    "ID_ALITERAL",
    "ID_ALITERAL_P",
    "ID_ALLOCATE",
    "ID_AND",
    "ID_ARSHIFT",
    "ID_BAIL",
    "ID_BODY_OFFSET",
    "ID_BRANCH",
    "ID_BYE",
    "ID_CALL_C",
    "ID_CFETCH",
    "ID_CMOVE",
    "ID_CMOVE_UP",
    "ID_COLON",
    "ID_COLON_P",
    "ID_COMPARE",
    "ID_COMP_EQUAL",
    "ID_COMP_GREATERTHAN",
    "ID_COMP_LESSTHAN",
    "ID_COMP_NOT_EQUAL",
    "ID_COMP_U_GREATERTHAN",
    "ID_COMP_U_LESSTHAN",
    "ID_COMP_ZERO_EQUAL",
    "ID_COMP_ZERO_GREATERTHAN",
    "ID_COMP_ZERO_LESSTHAN",
    "ID_COMP_ZERO_NOT_EQUAL",
    "ID_CR",
    "ID_CREATE",
    "ID_CREATE_P",
    "ID_CSTORE",
    "ID_DEFER",
    "ID_DEFER_P",
    "ID_DEPTH",
    "ID_DIVIDE",
    "ID_DOT",
    "ID_DOTS",
    "ID_DO_P",
    "ID_DROP",
    "ID_DUMP",
    "ID_DUP",
    "ID_D_MINUS",
    "ID_D_MTIMES",
    "ID_D_MUSMOD",
    "ID_D_PLUS",
    "ID_D_UMSMOD",
    "ID_D_UMTIMES",
    "ID_EMIT",
    "ID_EMIT_P",
    "ID_EOL",
    "ID_ERRORQ_P",
    "ID_EXECUTE",
    "ID_FETCH",
    "ID_FILE_CLOSE",
    "ID_FILE_CREATE",
    "ID_FILE_OPEN",
    "ID_FILE_POSITION",
    "ID_FILE_READ",
    "ID_FILE_REPOSITION",
    "ID_FILE_RO",
    "ID_FILE_RW",
    "ID_FILE_SIZE",
    "ID_FILE_WRITE",
    "ID_FILL",
    "ID_FIND",
    "ID_FINDNFA",
    "ID_FLUSHEMIT",
    "ID_FREE",
    "ID_HERE",
    "ID_NUMBERQ_P",
    "ID_I",
    "ID_INCLUDE_FILE",
    "ID_J",
    "ID_KEY",
    "ID_LEAVE_P",
    "ID_LITERAL",
    "ID_LITERAL_P",
    "ID_LOADSYS",
    "ID_LOCAL_COMPILER",
    "ID_LOCAL_ENTRY",
    "ID_LOCAL_EXIT",
    "ID_LOCAL_FETCH",
    "ID_LOCAL_FETCH_1",
    "ID_LOCAL_FETCH_2",
    "ID_LOCAL_FETCH_3",
    "ID_LOCAL_FETCH_4",
    "ID_LOCAL_FETCH_5",
    "ID_LOCAL_FETCH_6",
    "ID_LOCAL_FETCH_7",
    "ID_LOCAL_FETCH_8",
    "ID_LOCAL_PLUSSTORE",
    "ID_LOCAL_STORE",
    "ID_LOCAL_STORE_1",
    "ID_LOCAL_STORE_2",
    "ID_LOCAL_STORE_3",
    "ID_LOCAL_STORE_4",
    "ID_LOCAL_STORE_5",
    "ID_LOCAL_STORE_6",
    "ID_LOCAL_STORE_7",
    "ID_LOCAL_STORE_8",
    "ID_LOOP_P",
    "ID_LSHIFT",
    "ID_MAX",
    "ID_MIN",
    "ID_MINUS",
    "ID_NAME_TO_PREVIOUS",
    "ID_NAME_TO_TOKEN",
    "ID_NOOP",
    "ID_NUMBERQ",
    "ID_OR",
    "ID_OVER",
    "ID_PICK",
    "ID_PLUS",
    "ID_PLUSLOOP_P",
    "ID_PLUS_STORE",
    "ID_QDO_P",
    "ID_QDUP",
    "ID_QTERMINAL",
    "ID_QUIT_P",
    "ID_REFILL",
    "ID_RESIZE",
    "ID_RESTORE_INPUT",
    "ID_ROLL",
    "ID_ROT",
    "ID_RP_FETCH",
    "ID_RP_STORE",
    "ID_RSHIFT",
    "ID_R_DROP",
    "ID_R_FETCH",
    "ID_R_FROM",
    "ID_SAVE_FORTH_P",
    "ID_SAVE_INPUT",
    "ID_SCAN",
    "ID_SEMICOLON",
    "ID_SKIP",
    "ID_SOURCE",
    "ID_SOURCE_ID",
    "ID_SOURCE_ID_POP",
    "ID_SOURCE_ID_PUSH",
    "ID_SOURCE_SET",
    "ID_SP_FETCH",
    "ID_SP_STORE",
    "ID_STORE",
    "ID_SWAP",
    "ID_TEST1",
    "ID_TEST2",
    "ID_TEST3",
    "ID_TICK",
    "ID_TIMES",
    "ID_TO_R",
    "ID_TYPE",
    "ID_TYPE_P",
    "ID_VAR_BASE",
    "ID_VAR_CODE_BASE",
    "ID_VAR_CODE_LIMIT",
    "ID_VAR_CONTEXT",
    "ID_VAR_DP",
    "ID_VAR_ECHO",
    "ID_VAR_HEADERS_BASE",
    "ID_VAR_HEADERS_LIMIT",
    "ID_VAR_HEADERS_PTR",
    "ID_VAR_NUM_TIB",
    "ID_VAR_OUT",
    "ID_VAR_RETURN_CODE",
    "ID_VAR_SOURCE_ID",
    "ID_VAR_STATE",
    "ID_VAR_TO_IN",
    "ID_VAR_TRACE_FLAGS",
    "ID_VAR_TRACE_LEVEL",
    "ID_VAR_TRACE_STACK",
    "ID_VLIST",
    "ID_WORD",
    "ID_WORD_FETCH",
    "ID_WORD_STORE",
    "ID_XOR",
    "ID_ZERO_BRANCH",
    "ID_CATCH",
    "ID_THROW",
    "ID_INTERPRET",
    "ID_FILE_WO",
    "ID_FILE_BIN",
    "ID_CELL",
    "ID_CELLS",
    "ID_FILE_DELETE",
};

size_t mnt_token_list_size = (sizeof(mnt_token_list) / sizeof(char *));
