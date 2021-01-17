#ifndef STATUS_CODES_H_
#define STATUS_CODES_H_

typedef enum
{
    ok = 0,
    error_unknown_arg = 1,
    error_wrong_input = 2,
    error_out_of_memory = 3,
    error_empty_result = 4
} status_code_t;

#endif  // STATUS_CODES_H_
