#include "matrix_io.h"

status_code get_matrix_size(FILE *f, int *count_rows, int *count_columns) {
    status_code result = ok;

    if (fscanf(f, "%d%d", count_rows, count_columns) != 2) {
        result = error_wrong_input;
    } else if (*count_rows <= 0 || *count_columns <= 0) {
        result = error_wrong_matrix_sizes;
    }

    return result;
}

status_code read_matrix(FILE *f, matrix_t *matrix) {
    status_code result = ok;

    for (int i = 0; i < matrix->count_rows && !result; i++) {
        for (int j = 0; j < matrix->count_columns && !result; j++) {
            if (fscanf(f, "%d", matrix->rows[i] + j) != 1) {
                result = error_wrong_input;
            }
        }
    }

    return result;
}

void print_matrix(FILE *f, const matrix_t *matrix) {
    for (int i = 0; i < matrix->count_rows; i++) {
        for (int j = 0; j < matrix->count_columns; j++) {
            fprintf(f, "%d ", matrix->rows[i][j]);
        }
        fprintf(f, "\n");
    }
}
