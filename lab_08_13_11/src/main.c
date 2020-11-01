#include "status_codes.h"
#include "matrix_io.h"
#include "matrix_functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;

    char operation = 0;
    char *fname_matrix_1 = 0;
    char *fname_matrix_2 = 0;
    char *fname_output = 0;
    result = parse_command_line_args(argc, argv, &operation, &fname_matrix_1, &fname_matrix_2, &fname_output);
    if (!result)
    {
        int count_rows = 0;
        int count_columns = 0;
        matrix_double_t* matrix_1 = 0;
        matrix_double_t* matrix_2 = 0;
        result = get_matrix_size_from_file(&count_rows, &count_columns, fname_matrix_1);

        if (!result)
        {
            matrix_1 = alloc_matrix_double(count_rows, count_columns);
            if (!matrix_1)
                result = error_out_of_memory;
            else
                result = read_matrix_double_from_file(matrix_1, fname_matrix_1);
        }
        if (!result && fname_matrix_2)
        {
            result = get_matrix_size_from_file(&count_rows, &count_columns, fname_matrix_2);
            if (!result)
            {
                matrix_2 = alloc_matrix_double(count_rows, count_columns);
                if (!matrix_2)
                    result = error_out_of_memory;
                else
                    result = read_matrix_double_from_file(matrix_2, fname_matrix_2);
            }
        }

        matrix_double_t* matrix_result = 0;
        if (!result)
        {
            double det = 0.0;
            switch (operation)
            {
                case 'a':
                    result = matrix_double_operation_add(matrix_1, matrix_2, matrix_1);
                    matrix_result = matrix_1;
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
                    matrix_result = matrix_1;
                    break;
                default:
                    break;
            }
            if (!result)
            {
                if (operation != 'o')
                    result = write_matrix_double_to_file(matrix_result, fname_output);
                else
                    result = write_double_to_file(det, fname_output);
            }
        }
        free_matrix_double(&matrix_result);
        if (operation == 'm')
            free_matrix_double(&matrix_1);
        free_matrix_double(&matrix_2);
    }

    return result;
}