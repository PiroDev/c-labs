#ifndef INCLUDE_FILMS_STRUCTS_H_
#define INCLUDE_FILMS_STRUCTS_H_

#include "status_codes.h"

#define VECTOR_INIT_SIZE 10
#define VECTOR_SIZE_MULTIPLIER 2

typedef struct
{
    char *title;
    char *surname;
    int year;
} film_t;

typedef struct
{
    film_t *data;
    int count;
    int size;
} film_vector_t;

film_t init_film(const char *field, const char *value);
void free_film_string_fields(film_t *film);
status_code copy_film(const film_t *from, film_t *to);
status_code push_back(film_vector_t *films, const film_t *film);
void free_vector(film_vector_t *films);

#endif  // INCLUDE_FILMS_STRUCTS_H_
