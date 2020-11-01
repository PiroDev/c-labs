#ifndef INCLUDE_MATRIX_TYPES_H_
#define INCLUDE_MATRIX_TYPES_H_

typedef struct
{
    int count_rows;
    int count_columns;
    double **rows;
} matrix_double_t;

#endif  // INCLUDE_MATRIX_TYPES_H_