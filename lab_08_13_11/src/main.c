#include "matrix_io.h"
#include "matrix_functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;

    char operation = 0;
    result = parse_and_validate_args(argc, argv, &operation);
    if (!result)
    {
        matrix_double_t * matrix_1 = 0;
        matrix_double_t * matrix_2 = 0;

        result = allocate_and_read_matrixes(operation, argv, matrix_1, matrix_2);

        matrix_double_t * matrix_result = matrix_1;
        if (!result)
        {
            double det = 0.0;
            switch (operation)
            {
                case 'a':
                    result = matrix_double_operation_add(matrix_1, matrix_2, matrix_1);
                    break;
                case 'm':
                    matrix_result = alloc_matrix_double(matrix_1->count_rows, matrix_2->count_columns);
                    if (matrix_result)
                        result = matrix_double_operation_mult(matrix_1, matrix_2, matrix_result);
                    else
                        result = error_out_of_memory;
                    break;
                case 'o':
                    det = matrix_double_get_det(matrix_1, &result);
                    break;
                default:
                    break;
            }
            if (!result)
            {
                if (operation != 'o')
                    result = write_matrix_double_to_file(matrix_result, argv[4]);
                else
                    result = write_double_to_file(det, argv[3]);
            }
        }
        if (matrix_result != matrix_1)
            free_matrix_double(&matrix_result);
        free_matrix_double(&matrix_1);
        free_matrix_double(&matrix_2);
    }

    return result;
}
