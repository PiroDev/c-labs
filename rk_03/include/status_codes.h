#ifndef INCLUDE_STATUS_CODES_H_
#define INCLUDE_STATUS_CODES_H_

typedef enum
{
    ok = 0,
    error_wrong_input = 1,
    error_out_of_memory = 2,
    error_wrong_matrix_sizes = 3,
} status_code;

#endif  // INCLUDE_STATUS_CODES_H_
