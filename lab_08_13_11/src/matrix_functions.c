#include "matrix_functions.h"

status_code matrix_double_operation_add(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
matrix_double_t *matrix_result)
{
    status_code result = ok;

    if (matrix_1->count_rows != matrix_2->count_rows || matrix_1->count_columns != matrix_2->count_columns)
        result = error_wrong_matrix_sizes;
    else if (matrix_result->count_rows != matrix_1->count_rows || matrix_result->count_columns != matrix_1->count_columns)
        result = error_wrong_matrix_sizes;

    if (!result)
    {
        for (int i = 0; i < matrix_1->count_rows; i++)
            for (int j = 0; j < matrix_1->count_columns; j++)
                matrix_result->rows[i][j] = matrix_1->rows[i][j] + matrix_2->rows[i][j];
    }

    return result;
}

status_code matrix_double_operation_mult(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
matrix_double_t *matrix_result)
{
    status_code result = ok;

    if (matrix_1->count_columns != matrix_2->count_rows)
        result = error_wrong_matrix_sizes;
    else if (matrix_result->count_rows != matrix_1->count_rows || matrix_result->count_columns != matrix_2->count_columns)
        result = error_wrong_matrix_sizes;

    if (!result)
    {
        for (int i = 0; i < matrix_1->count_rows; i++)
            for (int j = 0; j < matrix_2->count_columns; j++)
                matrix_result->rows[i][j] = matrix_double_mult_row_and_col(matrix_1, matrix_2, i, j);
    }

    return result;
}

double matrix_double_mult_row_and_col(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2,
int row, int column)
{
    double result = 0.0;
    for (int i = 0; i < matrix_1->count_columns; i++)
        result += matrix_1->rows[row][i] * matrix_2->rows[i][column];
    return result;
}

double matrix_double_get_det(const matrix_double_t *matrix, status_code *error)
{
    double det = 0.0;

    if (matrix->count_columns != matrix->count_rows)
        *error = error_wrong_matrix_sizes;
    else if (matrix->count_columns == 1)
        return matrix->rows[0][0];

    if (!(*error))
    {
        for (int i = 0; i < matrix->count_rows; i++)
        {
            matrix_double_t * minor = alloc_matrix_double(matrix->count_rows - 1, matrix->count_columns - 1);
            int current_row = 0;
            for (int row_index = 0; row_index < matrix->count_rows; row_index++)
            {
                if (row_index != i)
                {
                    for (int column_index = 1; column_index < matrix->count_columns; column_index++)
                        minor->rows[current_row][column_index - 1] = matrix->rows[row_index][column_index];
                    current_row++;
                }
            }
            int mult = (i % 2 == 0 ? 1 : -1);
            det += mult * matrix->rows[i][0] * matrix_double_get_det(minor, error);
            free_matrix_double(&minor);
        }
    }

    return det;
}
