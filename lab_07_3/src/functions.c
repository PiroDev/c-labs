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

void mysort(void *array, void *end_of_array, size_t size, int (*cmp)(const void *, const void *))
{
    for (int i = 0; (char *) array + i * size < (char *) end_of_array; i++)
        for (int j = is_even(i); (char *) array + (j + 1) * size < (char *) end_of_array; j += 2)
            if (cmp((char *) array + j * size, (char *) array + (j + 1) * size))
                swap((char *) array + j * size, (char *) array + (j + 1) * size, size);
}

int key(const int *array, const int *end_of_array, int **filtered_array, int **end_of_filtered_array)
{
    status_code result = ok;

    int i;
    /* Поиск первого (с конца) отрицательного элемента массива */
    for (i = 1; (end_of_array - i >= array) && (*(end_of_array - i) >= 0); i++);

    /* Расчет размера отфильтрованного массива */
    size_t filtered_array_size = (int) (end_of_array - array);
    if (end_of_array - i >= array)
        filtered_array_size -= i;

    if (filtered_array_size > 0)
    {
        /* Выделение памяти под отфильтрованный массив */
        *filtered_array = (int *) malloc(filtered_array_size * sizeof(int));
        *end_of_filtered_array = *filtered_array + filtered_array_size;

        /* Запись подходящих по фильтру элементов массива */
        for (i = 0; i < filtered_array_size; i++)
            *(*filtered_array + i) = *(array + i);
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
