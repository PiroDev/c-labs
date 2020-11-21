#define _GNU_SOURCE

#include "films_structs.h"

#include <stdlib.h>
#include <string.h>

film_t init_film(const char *field, const char *value)
{
    film_t film = { .title = NULL, .surname = NULL, .year = 0 };
    if (!strcmp(field, "title"))
        film.title = strdup(value);
    else if (!strcmp(field, "name"))
        film.surname = strdup(value);
    else
        film.year = atoi(value);
    return film;
}

void free_film_string_fields(film_t *film)
{
    free(film->title);
    film->title = NULL;
    free(film->surname);
    film->surname = NULL;
}

status_code copy_film(const film_t *from, film_t *to)
{
    status_code result = ok;

    to->title = strdup(from->title);
    if (to->title)
    {
        to->surname = strdup(from->surname);
        if (to->surname)
            to->year = from->year;
        else
            result = out_of_memory;
    }
    else
        result = out_of_memory;

    return result;
}

status_code push_back(film_vector_t *films, const film_t *film)
{
    status_code result = ok;

    if (films->size == 0)
    {
        films->data = calloc(VECTOR_INIT_SIZE, sizeof(film_t));
        if (!films->data)
            result = out_of_memory;
        else
            films->size = VECTOR_INIT_SIZE;
    }

    if (films->count == films->size)
    {
        film_t * new_data = calloc(films->size * VECTOR_SIZE_MULTIPLIER, sizeof(film_t));
        if (new_data)
        {
            memcpy(new_data, films->data, sizeof(film_t) * films->count);
            free(films->data);
            films->data = new_data;
        }
    }

    result = copy_film(film, films->data + films->count);
    if (!result)
        films->count++;

    return result;
}

void free_vector(film_vector_t *films)
{
    for (int i = 0; i < films->count; i++)
        free_film_string_fields(films->data + i);

    free(films->data);
    films->data = NULL;
    films->count = 0;
}
