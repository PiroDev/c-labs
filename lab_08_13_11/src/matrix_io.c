#include "matrix_io.h"

status_code parse_command_line_args(const int argc, char **argv, char *operation, char **fname_matrix_1,
char **fname_matrix_2, char **fname_output)
{
    status_code result = ok;
    if (argc >= 4 && argc <= 5)
    {
        *operation = argv[1][0];
        *fname_matrix_1 = argv[2];
        switch (*operation)
        {
            case 'o':
                if (argc == 4)
                    *fname_output = argv[3];
                else
                    result = error_wrong_number_of_args;
                break;
            case 'a':
            case 'm':
                if (argc == 5)
                {
                    *fname_matrix_2 = argv[3];
                    *fname_output = argv[4];
                }
                else
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

status_code write_double_to_file(const double value, const char *fname)
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