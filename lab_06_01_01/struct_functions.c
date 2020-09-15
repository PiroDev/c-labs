/**
 * \file struct_functions.c
 * \brief В этом файле реализованы функции обработки структур и массивов структур
*/
#include "struct_functions.h"

/**
 * \param films - массив структур
 * \param count_films - количество элементов в массиве структур
 * \param field - поле, по которому осуществляется сортировка массива структур
*/
void sort_array(film_array films, int count_films, char *field)
{
    /* Пузырьковая сортировка массива структур */
    for (int i = 0; i < count_films - 1; i++)
        for (int j = 0; j < count_films - i - 1; j++)
            /* Сравнение и обмен элементов */
            if (compare_films_by_field(field, films[j], films[j + 1]) > 0)
            {
                film_struct temp = films[j];
                films[j] = films[j + 1];
                films[j + 1] = temp;
            }
}

/**
 * \param films - поле для сравнения
 * \param film_1 - первая стуктура
 * \param film_2 - вторая структура
 * \return Результат сравнения
*/
int compare_films_by_field(char *field, film_struct film_1, film_struct film_2)
{
    int result = 0;
    if (!strcmp(field, "title"))
        result = strcmp(film_1.title, film_2.title);
    else if (!strcmp(field, "name"))
        result = strcmp(film_1.surname, film_2.surname);
    else
    {
        if (film_1.year > film_2.year)
            result = 1;
        else if (film_1.year < film_2.year)
            result = -1;
        else
            result = 0;
    }
    return result;
}

/**
 * \param films - массив структур
 * \param count_films - количество элементов в массиве структур
 * \param field - поле, по которому осуществляется поиск в массиве структур
 * \param key - ключ, по которому осуществляется бинарный поиск
 * \return Код состояния
*/
status_code binary_search(film_array films, int count_films, char *field, char *key)
{
    status_code result = ok; /* Код состояния */
    /* Структура для дальнейшего удобного сравнения со структурами из массива */
    film_struct temp_film = {
        .title = "",
        .surname = "",
        .year = 0 };
    if (!strcmp(field, "title"))
        strcpy(temp_film.title, key);
    else if (!strcmp(field, "name"))
        strcpy(temp_film.surname, key);
    else
        string_year_to_int(key, &temp_film.year);
    int start = 0; /* Левая граница отрезка поиска */
    int end = count_films - 1; /* Правая граница отрезка поиска */
    int element_was_found = 0;
    int i = 0;
    /* Бинарный поиск по выбранному полю */
    while ((start <= end) && !element_was_found)
    {
        i = (start + end) / 2;
        if (compare_films_by_field(field, films[i], temp_film) > 0)
            end = i - 1;
        else if (compare_films_by_field(field, films[i], temp_film) < 0)
            start = i + 1;
        else
            element_was_found = 1;
    }
    /* Вывод результата поиска на экран */
    if (element_was_found)
        print_film(films[i]);
    else
        fprintf(stdout, "Not found\n");
    return result;
}
