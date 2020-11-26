#include "matrix_types.h"

#include <stdlib.h>

matrix_double_t *alloc_matrix_double(int count_rows, int count_columns)
{
    matrix_double_t * matrix = (matrix_double_t *)malloc(sizeof(matrix_double_t));
    if (matrix)
    {
        matrix->count_rows = count_rows;
        matrix->count_columns = count_columns;

        double **rows = (double **)calloc(count_rows, sizeof(double *));
        if (rows)
        {
            matrix->rows = rows;
            double *values = (double *)calloc(count_rows * count_columns, sizeof(double));
            if (values)
                for (int i = 0; i < count_rows; i++)
                    rows[i] = values + i * count_columns;
            else
                free_matrix_double(&matrix);
        }
    }
    return matrix;
}

void free_matrix_double(matrix_double_t **matrix)
{
    if (*matrix != NULL)
    {
        free(*((*matrix)->rows));
        free((*matrix)->rows);
        free(*matrix);
        *matrix = NULL;
    }
}
