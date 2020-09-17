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
            if (compare_films_by_field(field, &films[j], &films[j + 1]) > 0)
                swap(&films[j], &films[j + 1]);
}

/**
 * \param films - поле для сравнения
 * \param film_1 - первая стуктура
 * \param film_2 - вторая структура
 * \return Результат сравнения
*/
int compare_films_by_field(char *field, film_struct *film_1, film_struct *film_2)
{
    int result = 0;
    if (!strcmp(field, "title"))
        result = strcmp(film_1->title, film_2->title);
    else if (!strcmp(field, "name"))
        result = strcmp(film_1->surname, film_2->surname);
    else
        result = film_1->year - film_2->year;
    return result;
}

/**
 * \param films - массив структур
 * \param count_films - количество элементов в массиве структур
 * \param field - поле, по которому осуществляется поиск в массиве структур
 * \param key - ключ, по которому осуществляется бинарный поиск
 * \param result - структура, в которую записывается результат
 * \return Код состояния
*/
int binary_search(film_array films, int count_films, char *field, char *key, film_struct *result)
{
    /* Структура для дальнейшего удобного сравнения со структурами из массива */
    film_struct temp_film = film_constructor(field, key);
    int start = 0; /* Левая граница отрезка поиска */
    int end = count_films - 1; /* Правая граница отрезка поиска */
    int element_was_found = 0; /* Результат выполнения поиска */
    int i = 0;
    /* Бинарный поиск по выбранному полю */
    while ((start <= end) && !element_was_found)
    {
        i = (start + end) / 2;
        if (compare_films_by_field(field, &films[i], &temp_film) > 0)
            end = i - 1;
        else if (compare_films_by_field(field, &films[i], &temp_film) < 0)
            start = i + 1;
        else
            element_was_found = 1;
    }
    if (element_was_found)
        *result = films[i];
    return element_was_found;
}

/**
 * \param field - поле, которое нужно проинициализировать
 * \param key - значение для инициализации
 * \return Структура
*/
film_struct film_constructor(char *field, char *value)
{
    film_struct film = {
        .title = "",
        .surname = "",
        .year = 0 };
    if (!strcmp(field, "title"))
        strcpy(film.title, value);
    else if (!strcmp(field, "name"))
        strcpy(film.surname, value);
    else
        string_year_to_int(value, &film.year);
    return film;
}

/**
 * \param film_1 - указатель на первую структуру
 * \param film_2 - указатель на вторую структуру
*/
void swap(film_struct *film_1, film_struct *film_2)
{
    film_struct temp = *film_1;
    *film_1 = *film_2;
    *film_2 = temp;
}
