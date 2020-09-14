#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define MAX_TITLE_LENGTH 25
#define MAX_SURNAME_LENGTH 25
#define MAX_STRUCTS_COUNT 15
#define MAX_YEAR_LENGTH 4

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

typedef struct
{
    char title[MAX_TITLE_LENGTH + 1];
    char surname[MAX_SURNAME_LENGTH + 1];
    int year;
} film_struct;

typedef film_struct film_array[MAX_STRUCTS_COUNT];

status_code input_check(int, char **);
status_code read_array(char *, film_array, int *);
status_code read_film(FILE *, film_struct *);
status_code read_str(FILE *, char *, int);
void sort_array(film_array, int, char *);
int compare_films_by_field(char *, film_struct, film_struct);
void print_array(film_array, int);
void print_film(film_struct);
status_code binary_search(film_array, int, char *, char *);
status_code str_to_int(char *, int *);

#endif