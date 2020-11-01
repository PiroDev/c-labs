#ifndef INCLUDE_FILMS_IO_H_
#define INCLUDE_FILMS_IO_H_

#include <stdio.h>
#include <string.h>

#include "films_structs.h"
#include "status_codes.h"

status_code validate_args(int argc, char **argv);
status_code get_validated_year(const char *str, int *number);
status_code read_films_from_file(const char *fname, film_vector_t *films);
status_code read_film_from_file(FILE *f, film_t *film);
void remove_newline_symbol_from_str(char *str);

void print_array(const film_vector_t *films);
void print_film(const film_t *);


#endif  // INCLUDE_FILMS_IO_H_
