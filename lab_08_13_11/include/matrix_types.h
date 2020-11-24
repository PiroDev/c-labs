#ifndef INCLUDE_MATRIX_TYPES_H_
#define INCLUDE_MATRIX_TYPES_H_

typedef struct
{
    int count_rows;
    int count_columns;
    double **rows;
} matrix_double_t;

matrix_double_t *alloc_matrix_double(int count_rows, int count_columns);
void free_matrix_double(matrix_double_t **matrix);

#endif  // INCLUDE_MATRIX_TYPES_H_