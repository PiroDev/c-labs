/**
 * \file functions.c
 * \brief В этом файле находится реализация функций для работы с массивами и других полезные функции
*/
#include "../inc/functions.h"
#include <malloc.h>
#include "../inc/status_codes.h"

void free_resources(int **array, int **end_of_array)
{
    if (*array != NULL)
    {
        free(*array);
        *array = NULL;
    }
    *end_of_array = NULL;
}

void mysort(void *array, int array_size, size_t size, int (*cmp)(const void *, const void *))
{
    char *p_start = (char *) array;
    char *p_end = p_start + array_size * size;
    for (int i = 0; p_start + i * size < p_end; i++)
        for (int j = is_even(i); p_start + (j + 1) * size < p_end; j += 2)
            if (cmp(p_start + j * size, p_start + (j + 1) * size) > 0)
                swap(p_start + j * size, p_start + (j + 1) * size, size);
}

int key(const int *array, const int *end_of_array, int **filtered_array, int **end_of_filtered_array)
{
    status_code result = ok;

    if (array != end_of_array)
    {
        int i;
        /* Поиск первого (с конца) отрицательного элемента массива */
        for (i = 1; (end_of_array - i >= array) && (*(end_of_array - i) >= 0); i++);

        /* Расчет размера отфильтрованного массива */
        int filtered_array_size = (int) (end_of_array - array);
        if (end_of_array - i >= array)
            filtered_array_size -= i;

        if (filtered_array_size > 0)
        {
            /* Выделение памяти под отфильтрованный массив */
            *filtered_array = (int *) malloc(filtered_array_size * sizeof(int));
            if (*filtered_array != NULL)
            {
                *end_of_filtered_array = *filtered_array + filtered_array_size;

                /* Запись подходящих по фильтру элементов массива */
                copy_array(array, *filtered_array, filtered_array_size);
            }
            else
                result = error_out_of_memory;
        }
        else
            result = error_empty_filtration_output;
    }
    else
        result = error_empty_filtration_output;

    return result;
}

int cmp_int(const void *a, const void *b)
{
    return *((const int *) a) - *((const int *) b);
}

void swap(void *a, void *b, size_t size)
{
    char temp;
    for (size_t i = 0; i < size; i++)
    {
        temp = *((char *) a + i);
        *((char *) a + i) = *((char *) b + i);
        *((char *) b + i) = temp;
    }
}

int is_even(int a)
{
    return a % 2 == 0 ? 1 : 0;
}

void copy_array(const int *array_from, int *array_dest, int count)
{
    for (int i = 0; i < count; i++)
        *(array_dest + i) = *(array_from + i);
}