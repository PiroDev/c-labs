#include "matrix_io.h"
#include <stdio.h>

status_code parse_and_validate_args(const int argc, char **argv, char *operation)
{
    status_code result = ok;
    if (argc >= 4 && argc <= 5)
    {
        *operation = argv[1][0];
        switch (*operation)
        {
            case 'o':
                if (argc != 4)
                    result = error_wrong_number_of_args;
                break;
            case 'a':
            case 'm':
                if (argc != 5)
                    result = error_wrong_number_of_args;
                break;
            default:
                result = error_wrong_command_line_args;
                break;
        }
    }
    else
        result = error_wrong_number_of_args;

    return result;
}

status_code get_matrix_size_from_file(int *count_rows, int *count_columns, const char *fname)
{
    status_code result = ok;
    FILE *f = fopen(fname, "r");

    if (f)
    {
        if (fscanf(f, "%d%d", count_rows, count_columns) == 2)
        {
            if (*count_rows <= 0 || *count_columns <= 0)
                result = error_wrong_value_in_file;
        }
        else
            result = error_wrong_value_in_file;
        fclose(f);
    }
    else
        result = error_cannot_open_input_file;

    return result;
}

status_code read_matrix_double_from_file(matrix_double_t *matrix, const char *fname)
{
    status_code result = ok;
    FILE *f = fopen(fname, "r");

    if (f)
    {
        int n, m;
        fscanf(f, "%d%d", &n, &m);

        for (int i = 0; i < matrix->count_rows && !result; i++)
            for (int j = 0; j < matrix->count_columns && !result; j++)
                if (fscanf(f, "%lf", matrix->rows[i] + j) != 1)
                    result = error_wrong_value_in_file;
        fclose(f);
    }
    else
        result = error_cannot_open_input_file;

    return result;
}

status_code allocate_and_read_matrixes(char operation, char **fnames, matrix_double_t *matrix_1, matrix_double_t *matrix_2)
{
    status_code result = ok;

    int count_rows_1 = 0;
    int count_columns_1 = 0;
    int count_rows_2 = 0;
    int count_columns_2 = 0;

    result = get_matrix_size_from_file(&count_rows_1, &count_columns_1, fnames[2]);
    if (!result && operation != 'o')
        result = get_matrix_size_from_file(&count_rows_2, &count_columns_2, fnames[3]);

    if (!result)
        result = validate_matrix_sizes(count_rows_1, count_columns_1, count_rows_2, count_columns_2, operation);

    if (!result)
    {
        matrix_1 = alloc_matrix_double(count_rows_1, count_columns_1);
        if (!matrix_1)
            result = error_out_of_memory;
        else
            result = read_matrix_double_from_file(matrix_1, fnames[2]);
    }
    if (!result && operation != 'o')
    {
        matrix_2 = alloc_matrix_double(count_rows_2, count_columns_2);
        if (!matrix_2)
            result = error_out_of_memory;
        else
            result = read_matrix_double_from_file(matrix_2, fnames[3]);
    }

    return result;
}

status_code write_matrix_double_to_file(const matrix_double_t *matrix, const char *fname)
{
    status_code result = ok;
    FILE *f = fopen(fname, "w");

    if (f)
    {
        fprintf(f, "%d %d\n", matrix->count_rows, matrix->count_columns);
        for (int i = 0; i < matrix->count_rows; i++)
        {
            for (int j = 0; j < matrix->count_columns; j++)
            {
                fprintf(f, "%lf", matrix->rows[i][j]);
                if (j != matrix->count_columns - 1)
                    fprintf(f, " ");
            }
            fprintf(f, "\n");
        }
        fclose(f);
    }
    else
        result = error_cannot_open_output_file;

    return result;
}

status_code write_double_to_file(double value, const char *fname)
{
    status_code result = ok;
    FILE *f = fopen(fname, "w");

    if (f)
    {
        fprintf(f, "%lf", value);
        fclose(f);
    }
    else
        result = error_cannot_open_output_file;

    return result;
}

status_code validate_matrix_sizes(int rows_1, int cols_1, int rows_2, int cols_2, char operation)
{
    status_code result = ok;
    switch (operation)
    {
        case 'a':
            if (rows_1 != rows_2 || cols_1 != cols_2)
                result = error_wrong_matrix_sizes;
            break;
        case 'm':
            if (cols_1 != rows_2)
                result = error_wrong_matrix_sizes;
            break;
        case 'o':
            if (rows_1 != cols_1)
                result = error_wrong_matrix_sizes;
            break;
        default:
            break;
    }
    return result;
}
