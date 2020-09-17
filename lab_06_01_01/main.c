/**
 * \file main.c
 * \brief В этом файле находится точка входа в программу
*/
#include "struct_functions.h"

/**
 * \brief Точка входа в программу
 * 
 * Считывает аргументы командной строки и передает управление другим функциям в зависимости от кода состояния
 * \return Код состояния
 */
int main(int argc, char **argv)
{
    status_code result = ok; /* код состояния */
    result = input_check(argc, argv); /* проверка введенных аргументов на корректность*/
    if (result == ok)
    {
        film_array films; /* массив для хранения структур */
        int count_films = 0; /* переменная для хранения количества структур в массиве */
        result = read_array(argv[1], films, &count_films); /* считывание структур в массив */
        if (result == ok)
        {
            sort_array(films, count_films, argv[2]); /* сортировка массива по выбранному полю */
            if (argc == 3)
                print_array(films, count_films); /* вывод отсортированного массива на экран */
            else
            {
                film_struct temp_film = film_constructor("year", "0");
                if (binary_search(films, count_films, argv[2], argv[3], &temp_film)) /* бинарный поиск по ключу */
                    print_film(&temp_film);
                else
                    fprintf(stdout, "Not found\n");
            }
        }
    }
    return result;
}