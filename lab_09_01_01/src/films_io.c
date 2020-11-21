#define _GNU_SOURCE

#include "films_io.h"
#include "films_structs.h"
#include "status_codes.h"

status_code validate_args(int argc, char **argv)
{
    status_code result = ok;
    if (argc < 3 || argc > 4)
        result = wrong_arguments_count;
    else
    {
        if (!strcmp(argv[2], "year"))
        {
            if (argc == 4)
            {
                int number = 0;
                result = get_validated_year(argv[3], &number);
            }
        }
        else if (strcmp(argv[2], "title") && strcmp(argv[2], "name"))
            result = wrong_arguments_value;
    }
    return result;
}

status_code read_films_from_file(const char *fname, film_vector_t *films)
{
    status_code result = ok;

    FILE *f = fopen(fname, "r");
    if (f != NULL)
    {
        while (!feof(f) && result == ok)
        {
            film_t temp = {.year = 0, .surname = NULL, .title = NULL};
            result = read_film_from_file(f, &temp);
            if (result == ok)
                result = push_back(films, &temp);

            free_film_string_fields(&temp);
        }
        if (films->count == 0)
            result = empty_file_error;
        fclose(f);
    }
    else
        result = file_input_error;
    return result;
}

status_code read_film_from_file(FILE *f, film_t *film)
{
    status_code result = ok;
    ssize_t count = 0;
    size_t n = 0;
    if ((count = getline(&(film->title), &n, f)) != -1)
    {
        remove_newline_symbol_from_str(film->title);
        fscanf(f, "%*[\n]");
        count = 0;
        n = 0;
        if ((count = getline(&(film->surname), &n, f)) != -1)
        {
            remove_newline_symbol_from_str(film->surname);
            fscanf(f, "%*[\n]");
            if (fscanf(f, "%d\n", &film->year) != 1)
                result = file_input_error;
            else if (film->year <= 0)
                result = wrong_year_format;
        }
        else
        {
            free_film_string_fields(film);
            film->surname = NULL;
            result = out_of_memory;
        }
    }
    else
    {
        free_film_string_fields(film);
        film->title = NULL;
        result = out_of_memory;
    }
    return result;
}

void remove_newline_symbol_from_str(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

status_code get_validated_year(const char *str, int *number)
{
    status_code result = ok;
    *number = 0;
    int i = 0;
    char c = 0;
    while ((c = str[i++]) != '\0' && c <= '9' && c >= '0' && !result)
    {
        if ((i == 1) && (c == '0'))
            result = wrong_year_format;
        *number = (*number) * 10 + (c - '0');
    }
    if (c != '\0')
        result = wrong_year_format;
    else if (*number <= 0)
        result = wrong_year_format;
    return result;
}

void print_array(const film_vector_t *films)
{
    for (int i = 0; i < films->count; i++)
        print_film(films->data + i);
}

void print_film(const film_t *film)
{
    printf("%s\n%s\n%d\n", film->title, film->surname, film->year);
}
