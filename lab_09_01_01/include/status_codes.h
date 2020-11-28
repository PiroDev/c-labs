#ifndef INCLUDE_STATUS_CODES_H_
#define INCLUDE_STATUS_CODES_H_

typedef enum
{
    ok = 0,
    wrong_arguments_count = 1,
    wrong_arguments_value = 2,
    file_input_error = 3,
    empty_file_error = 4,
    wrong_year_format = 5,
    out_of_memory = 6
} status_code;

#endif  // INCLUDE_STATUS_CODES_H_