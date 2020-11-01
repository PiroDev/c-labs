#ifndef INCLUDE_MATRIX_IO_H_
#define INCLUDE_MATRIX_IO_H_

#include "matrix_types.h"
#include "status_codes.h"
#include "stdio.h"

status_code parse_command_line_args(int argc, char **argv, char *operation, char **fname_matrix_1,
                                    char **fname_matrix_2, char **fname_output);

status_code get_matrix_size_from_file(int *count_rows, int *count_columns, const char *fname);
status_code read_matrix_double_from_file(matrix_double_t *matrix, const char *fname);
status_code write_matrix_double_to_file(const matrix_double_t *matrix, const char *fname);
status_code write_double_to_file(const double value, const char *fname);

#endif  // INCLUDE_MATRIX_IO_H_