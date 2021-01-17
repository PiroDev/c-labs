/**
 * \file input_output.c
 * \brief В этом файле находится реализация функций ввода-вывода
*/
#include "input_output.h"
#include <stdio.h>
#include <malloc.h>

/**
 * \param fname - имя входного файла
 * \param array - указатель на указатель на массив
 * \param end_of_array - указатель на указатель на конец массива
*/
status_code input_from_text_file(char *fname, int **array, int **end_of_array)
{
    if (!fname || !array || !end_of_array || !*array || !*end_of_array)
    {
        return error_null_ptr;
    }

    status_code result = ok;

    FILE *f = NULL;
    f = fopen(fname, "r");

    if (f)
    {
        int count_numbers = 0;
        int current_number = 0;

        while (fscanf(f, "%d", &current_number) == 1)
            count_numbers++;

        if (!feof(f))
            result = error_wrong_value_in_file;
        else if (count_numbers == 0)
            result = error_empty_input_file;
        else
        {
            *end_of_array = *array + count_numbers;

            rewind(f);
            current_number = 0;
            while (current_number < count_numbers)
            {
                fscanf(f, "%d", *array + current_number);
                current_number++;
            }
        }
        fclose(f);
    }
    else
        result = error_cannot_open_input_file;

    return result;
}


status_code output_in_text_file(char *fname, int *array, int *end_of_array)
{
    status_code result = ok;

    FILE *f = NULL;
    f = fopen(fname, "w");

    if (f)
    {
        int i = 0;
        while (array + i < end_of_array)
            fprintf(f, "%d ", *(array + i++));

        fclose(f);
    }
    else
        result = error_cannot_open_output_file;

    return result;
}