#ifndef INCLUDE_MATRIX_IO_H_
#define INCLUDE_MATRIX_IO_H_

#include "matrix_types.h"
#include "status_codes.h"

status_code parse_and_validate_args(const int argc, char **argv, char *operation);

status_code get_matrix_size_from_file(int *count_rows, int *count_columns, const char *fname);
status_code read_matrix_double_from_file(matrix_double_t *matrix, const char *fname);
status_code allocate_and_read_matrixes(char operation, char **fnames, matrix_double_t **matrix_1, matrix_double_t **matrix_2);
status_code write_matrix_double_to_file(const matrix_double_t *matrix, const char *fname);
status_code write_double_to_file(double value, const char *fname);
status_code validate_matrix_sizes(int rows_1, int cols_1, int rows_2, int cols_2, char operation);

#endif  // INCLUDE_MATRIX_IO_H_