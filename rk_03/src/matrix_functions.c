#include "matrix_functions.h"

#include <stdlib.h>
#include <string.h>

int cmp_int(int a, int b) { return a - b; }

matrix_t *alloc_matrix(int count_rows, int count_columns) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    if (matrix) {
        matrix->count_rows = count_rows;
        matrix->count_columns = count_columns;

        int count_values = count_rows * count_columns;
        int **rows = (int **)malloc(count_rows * sizeof(int *) + count_values * sizeof(int));
        if (rows) {
            matrix->rows = rows;
            int *values = (int *)(rows + count_rows);
            for (int i = 0; i < count_rows; i++) {
                matrix->rows[i] = values + i * count_columns;
            }
        }
    }
    return matrix;
}

void free_matrix(matrix_t *matrix) {
    if (matrix) {
        free(matrix->rows);
        free(matrix);
    }
}

void diagonal_snake_sort_matrix(matrix_t *matrix) {
    int count_values = matrix->count_columns * matrix->count_rows;
    int *values = calloc(count_values, sizeof(int));
    values = memcpy(values, matrix->rows + matrix->count_rows, count_values * sizeof(int));

    sort_int_array(values, count_values, cmp_int);

    int ind = 0;
    int i = 0;
    int j = 0;
    while (ind < count_values) {
        matrix->rows[i][j] = values[ind++];  // curr

        if (i < matrix->count_rows - 1) {  // down
            i++;
        } else if (j < matrix->count_columns - 1) {  // right
            j++;
        } else {
            break;
        }
        matrix->rows[i][j] = values[ind++];

        while (i > 0 && j < matrix->count_columns - 1) {  // diag up
            i--;
            j++;
            matrix->rows[i][j] = values[ind++];
        }

        if (j < matrix->count_columns - 1) {  // right
            j++;
        } else if (i < matrix->count_rows - 1) {  // down
            i++;
        } else {
            break;
        }
        matrix->rows[i][j] = values[ind++];

        while (i < matrix->count_rows - 1 && j > 0) {  // diag down
            j--;
            i++;
            matrix->rows[i][j] = values[ind++];
        }
    }

    free(values);
}

void sort_int_array(int *array, int count, int (*cmp)(int, int)) {
    int index_min = 0;
    for (int i = 0; i < count - 1; i++) {
        index_min = i;
        for (int j = i + 1; j < count; j++)
            if (cmp(array[i], array[j]) < 0) {
                index_min = j;
            }
        swap_int(array + i, array + index_min);
    }
}

void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
