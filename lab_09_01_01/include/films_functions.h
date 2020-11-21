#ifndef INCLUDE_FILMS_FUNCTIONS_H_
#define INCLUDE_FILMS_FUNCTIONS_H_

#include "films_io.h"

void sort_films(film_vector_t *films, const char *field);
int compare_films_by_field(const char *field, film_t *film_1, film_t *film_2);
int binary_search(const film_vector_t *films, const char *field, const char *key, film_t *result);
void swap(film_t *, film_t *);

#endif  // INCLUDE_FILMS_FUNCTIONS_H_
