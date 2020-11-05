#include "matrix_functions.h"
#include "matrix_io.h"

int main(void) {
    int count_columns = 0;
    int count_rows = 0;
    get_matrix_size(stdin, &count_columns, &count_rows);

    matrix_t *matrix = alloc_matrix(count_rows, count_columns);
    if (matrix) {
        read_matrix(stdin, matrix);
        diagonal_snake_sort_matrix(matrix);
        printf("Matrix result:\n");
        print_matrix(stdout, matrix);
        free_matrix(matrix);
    }

    return 0;
}