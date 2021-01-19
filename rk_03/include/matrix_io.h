#ifndef INCLUDE_MATRIX_IO_H_
#define INCLUDE_MATRIX_IO_H_

#include "matrix_types.h"
#include "status_codes.h"
#include "stdio.h"

status_code get_matrix_size(FILE *f, int *count_rows, int *count_columns);
status_code read_matrix(FILE *f, matrix_t *matrix);
void print_matrix(FILE *f, const matrix_t *matrix);

#endif  // INCLUDE_MATRIX_IO_H_
