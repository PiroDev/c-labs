#include "films_functions.h"

void sort_films(film_vector_t *films, const char *field)
{
    for (int i = 0; i < films->count - 1; i++)
        for (int j = 0; j < films->count - i - 1; j++)
            if (compare_films_by_field(field, films->data + j, films->data + j + 1) > 0)
                swap(films->data + j, films->data + j + 1);
}

int compare_films_by_field(const char *field, film_t *film_1, film_t *film_2)
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

int binary_search(const film_vector_t *films, const char *field, const char *key, film_t *result)
{
    /* Структура для дальнейшего удобного сравнения со структурами из массива */
    film_t temp_film = init_film(field, key);
    int start = 0;              /* Левая граница отрезка поиска */
    int end = films->count - 1; /* Правая граница отрезка поиска */
    int element_was_found = 0;  /* Результат выполнения поиска */
    int i = 0;
    /* Бинарный поиск по выбранному полю */
    while ((start <= end) && !element_was_found)
    {
        i = (start + end) / 2;
        if (compare_films_by_field(field, films->data + i, &temp_film) > 0)
            end = i - 1;
        else if (compare_films_by_field(field, films->data + i, &temp_film) < 0)
            start = i + 1;
        else
            element_was_found = 1;
    }
    if (element_was_found)
        copy_film(films->data + i, result);

    free_film_string_fields(&temp_film);

    return element_was_found;
}

void swap(film_t *film_1, film_t *film_2)
{
    film_t temp = *film_1;
    *film_1 = *film_2;
    *film_2 = temp;
}
