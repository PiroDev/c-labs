/**
 * \file main.c
 * \brief В этом файле находится точка входа в программу
*/

#include "status_codes.h"
#ifdef DYN_LINK
    #include <dlfcn.h>
#else
    #include "array_functions.h"
    #include "input_output.h"
#endif
#include <string.h>
#include <stdlib.h>

#define FILTRATION_MARKER "f"
#define MAX_ARRAY_SIZE 128

/**
 * \brief Точка входа в программу
 * 
 * Считывает аргументы командной строки и передает управление другим функциям в зависимости от кода состояния
 * \param argc - количество переданных аргументов командной строки
 * \param argv - массив строк - переданных аргументов командной строки
 * \return Код состояния
 */
int main(int argc, char **argv)
{
#ifdef DYN_LINK
    void *library_ptr = dlopen("lib/libarray.so", RTLD_LAZY);
    if (!library_ptr)
        return error_open_lib; 

    status_code (*input_from_text_file)(char *, int **, int **) =
        (status_code (*)(char *, int **, int **))dlsym(library_ptr, "input_from_text_file");

    status_code (*output_in_text_file)(char *, int *, int *) =
        (status_code (*)(char *, int *, int *))dlsym(library_ptr, "output_in_text_file");

    void (*copy_array_pointers)(int **, int **, int **, int **) =
        (void (*)(int **, int **, int **, int **))dlsym(library_ptr, "copy_array_pointers");

    int (*key)(const int *, const int *, int **, int **) =
        (int (*)(const int *, const int *, int **, int **))dlsym(library_ptr, "key");

    void (*mysort)(void *, int, size_t, int (*)(const void *, const void *)) =
        (void (*)(void *, int, size_t, int (*)(const void *, const void *)))dlsym(library_ptr, "mysort");

    int (*cmp_int)(const void *, const void *) =
        (int (*)(const void *, const void *))dlsym(library_ptr, "cmp_int");
#endif

    status_code result = ok; /* код состояния */

    if ((argc == 3) || ((argc == 4) && !strcmp(FILTRATION_MARKER, argv[3])))
    {
        /* Выделяем из аргументов командной строки названия входного и выходного файлов */
        char *input_fname = argv[1];
        char *output_fname = argv[2];

        /* Объявляем и сразу инициализируем NULL необходимые для работы указатели */
        int *array = calloc(MAX_ARRAY_SIZE, sizeof(int));
        int *end_of_array = NULL;
        if (!array)
        {
            result = error_out_of_memory;
        }
        else 
        {
            end_of_array = array + MAX_ARRAY_SIZE;
            /* Считываем числа из файла в массив */
            result = input_from_text_file(input_fname, &array, &end_of_array);
        }

        if (!result)
        {
            int *result_array = calloc(MAX_ARRAY_SIZE, sizeof(int));
            if (!result_array)
            {
                result = error_out_of_memory;
            }
            else
            {
                int *end_of_result_array = result_array + MAX_ARRAY_SIZE;

                if (argc == 4)
                {
                    int *filtered_array = calloc(MAX_ARRAY_SIZE, sizeof(int));
                    if (!filtered_array)
                    {
                        result = error_out_of_memory;
                    }
                    else
                    {
                        int *end_of_filtered_array = filtered_array + MAX_ARRAY_SIZE;

                        /* Фильтруем исходный массив, результат копируем в filtered_array */
                        result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);

                        copy_array_pointers(&filtered_array, &end_of_filtered_array, &result_array, &end_of_result_array);
                    }

                    free(filtered_array);
                }
                else
                    copy_array_pointers(&array, &end_of_array, &result_array, &end_of_result_array);

                if (!result)
                {
                    /* Сортировка массива и вывод результата в файл */
                    mysort(result_array, (int) (end_of_result_array - result_array), sizeof(int), cmp_int);
                    result = output_in_text_file(output_fname, result_array, end_of_result_array);
                }
            }

            free(result_array);
        }
        else
            result = error_wrong_command_line_args;

        free(array);
    }
    else
        result = error_wrong_number_of_args;
    

#ifdef DYN_LINK
    dlclose(library_ptr);
#endif

    return result;
}