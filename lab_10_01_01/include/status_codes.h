#ifndef STATUS_CODES_H_
#define STATUS_CODES_H_

typedef enum
{
    ok = 0,
    error_wrong_args_count = 1,
    error_unknown_args = 2,
    error_while_open_input_file = 3,
    error_while_open_output_file = 4,
    error_wrong_value_in_file = 5
} status_code_t;

#endif  // STATUS_CODES_H_
