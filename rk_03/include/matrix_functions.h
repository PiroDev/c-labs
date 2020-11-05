#ifndef INCLUDE_MATRIX_FUNCTIONS_H_
#define INCLUDE_MATRIX_FUNCTIONS_H_

#include "matrix_types.h"
#include "status_codes.h"

matrix_t *alloc_matrix(int count_rows, int count_columns);
void free_matrix(matrix_t *matrix);

void diagonal_snake_sort_matrix(matrix_t *matrix);
void sort_int_array(int *array, int count, int (*cmp)(int, int));
int cmp_int(int a, int b);
void swap_int(int *a, int *b);


#endif  // INCLUDE_MATRIX_FUNCTIONS_H_
