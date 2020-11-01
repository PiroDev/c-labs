#ifndef INCLUDE_MATRIX_FUNCTIONS_H_
#define INCLUDE_MATRIX_FUNCTIONS_H_

#include "matrix_types.h"
#include "status_codes.h"

matrix_double_t *alloc_matrix_double(int count_rows, int count_columns);
void free_matrix_double(matrix_double_t **matrix);

status_code matrix_double_operation_add(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
                                        matrix_double_t *matrix_result);
status_code matrix_double_operation_mult(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
                                             matrix_double_t *matrix_result);
double matrix_double_mult_row_and_col(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
                                             int row, int column);

double matrix_double_get_det(const matrix_double_t *matrix, status_code *error);

#endif  // INCLUDE_MATRIX_FUNCTIONS_H_