#ifndef INCLUDE_STATUS_CODES_H_
#define INCLUDE_STATUS_CODES_H_

typedef enum
{
    ok = 0,
    error_wrong_number_of_args = 1,
    error_wrong_command_line_args = 2,
    error_cannot_open_input_file = 3,
    error_wrong_value_in_file = 4,
    error_cannot_open_output_file = 5,
    error_out_of_memory = 6,
    error_operation_wrong_matrix_sizes = 7
} status_code;

#endif  // INCLUDE_STATUS_CODES_H_