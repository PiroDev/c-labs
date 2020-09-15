#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "input_output.h"

void sort_array(film_array, int, char *);
int compare_films_by_field(char *, film_struct, film_struct);
status_code binary_search(film_array, int, char *, char *);

#endif