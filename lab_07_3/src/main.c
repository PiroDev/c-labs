/**
 * \file main.c
 * \brief В этом файле находится точка входа в программу
*/
#include "../inc/input_output.h"
#include "../inc/array_functions.h"
#include <string.h>

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
    status_code result = ok; /* код состояния */

    if ((argc == 3) || ((argc == 4) && !strcmp(FILTRATION_MARKER, argv[3])))
    {
        /* Выделяем из аргументов командной строки названия входного и выходного файлов */
        char *input_fname = argv[1];
        char *output_fname = argv[2];

        /* Объявляем и сразу инициализируем NULL необходимые для работы указатели */
        int *array = NULL;
        int *end_of_array = NULL;

        /* Считываем числа из файла в массив */
        result = input_from_text_file(input_fname, &array, &end_of_array);

        if (!result)
        {
            int *result_array = NULL;
            int *end_of_result_array = NULL;

            if (argc == 4)
            {
                int *filtered_array = NULL;
                int *end_of_filtered_array = NULL;

                /* Фильтруем исходный массив, результат копируем в filtered_array */
                result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);

                copy_array_pointers(&filtered_array, &end_of_filtered_array, &result_array, &end_of_result_array);
                free_resources(&array, &end_of_array);
            }
            else
                copy_array_pointers(&array, &end_of_array, &result_array, &end_of_result_array);

            if (!result)
            {
                /* Сортировка массива и вывод результата в файл */
                mysort(result_array, (int) (end_of_result_array - result_array), sizeof(int), cmp_int);
                result = output_in_text_file(output_fname, result_array, end_of_result_array);
            }

            /* Освобождение памяти и обнуление указателей */
            free_resources(&result_array, &end_of_result_array);
        }
        else
            result = error_wrong_command_line_args;
    }
    else
        result = error_wrong_number_of_args;

    return result;
}