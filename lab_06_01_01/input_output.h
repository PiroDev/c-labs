#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <string.h>
#include "structs.h"

typedef enum
{
    ok = 0,
    too_long_input_string = -1,
    wrong_arguments_count = -2,
    wrong_arguments_value = -3,
    file_input_error = -4,
    empty_file_error = -5,
    wrong_year_format = -6,
    too_many_structures = -7
} status_code;

status_code input_check(int, char **);
status_code read_array(char *, film_array, int *);
status_code read_film(FILE *, film_struct *);
status_code read_str(FILE *, char *, int);
status_code str_to_int(char *, int *);

void print_array(film_array, int);
void print_film(film_struct);

#endif