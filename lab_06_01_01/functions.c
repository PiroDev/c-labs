#include <stdio.h>
#include <string.h>
#include "functions.h"

status_code input_check(int argc, char **argv)
{
    status_code result = ok;
    if ((argc < 3) || (argc > 4))
        result = wrong_arguments_count;
    else
    {
        if (!strcmp(argv[2], "title"))
        {
            if ((argc == 4) && (strlen(argv[3]) > MAX_TITLE_LENGTH))
                result = too_long_input_string;
        }
        else if (!strcmp(argv[2], "name"))
        {
            if ((argc == 4) && strlen(argv[3]) > MAX_SURNAME_LENGTH)
                result = too_long_input_string;
        }
        else if (!strcmp(argv[2], "year"))
        {
            if (argc == 4)
            {
                int number = 0;
                result = str_to_int(argv[3], &number);
            }
        }
        else
            result = wrong_arguments_value;
    }
    return result;
}

status_code read_array(char *fname, film_array films, int *count_films)
{
    status_code result = ok;
    FILE *f = NULL;
    f = fopen(fname, "r");
    if (f != NULL)
    {
        while (!feof(f) && (*count_films < MAX_STRUCTS_COUNT) && (result == ok))
        {
            film_struct temp = { .year = 0,
                .surname = "",
                .title = "" };
            result = read_film(f, &temp);
            if (result == ok)
            {
                films[*count_films] = temp;
                *count_films += 1;
            }
        }
        if (*count_films == 0)
            result = empty_file_error;
        else if ((*count_films == MAX_STRUCTS_COUNT) && !feof(f))
            result = too_many_structures;
        fclose(f);
    }
    else
        result = file_input_error;
    return result;
}

status_code read_film(FILE *f, film_struct *film)
{
    status_code result = ok;
    if (read_str(f, film->title, MAX_TITLE_LENGTH) || \
            read_str(f, film->surname, MAX_SURNAME_LENGTH))
        result = file_input_error;
    else
    {
        int number = 0;
        char temp[MAX_YEAR_LENGTH + 1] = { '\0' };
        result = read_str(f, temp, MAX_YEAR_LENGTH);
        if (result || str_to_int(temp, &number) || (number <= 0))
            result = wrong_year_format;
        else
            film->year = number;
    }
    return result;
}

status_code read_str(FILE *f, char *str, int max_count)
{
    status_code result = ok;
    int count = 0;
    char c = 0;
    while ((count <= max_count) && ((c = fgetc(f)) != EOF) && (c != '\n'))
        str[count++] = c;
    if (count > max_count)
        result = too_long_input_string;
    return result;
}

void sort_array(film_array films, int count_films, char *field)
{
    for (int i = 0; i < count_films - 1; i++)
        for (int j = 0; j < count_films - i - 1; j++)
            if (compare_films_by_field(field, films[j], films[j + 1]) > 0)
            {
                film_struct temp = films[j];
                films[j] = films[j + 1];
                films[j + 1] = temp;
            }
}

int compare_films_by_field(char *field, film_struct film_1, film_struct film_2)
{
    int result = 0;
    if (!strcmp(field, "title"))
        result = strcmp(film_1.title, film_2.title);
    else if (!strcmp(field, "name"))
        result = strcmp(film_1.surname, film_2.surname);
    else
        result = film_1.year > film_2.year;
    return result;
}

status_code binary_search(film_array films, int count_films, char *field, char *key)
{
    status_code result = ok;
    int start = 0;
    int end = count_films - 1;
    char field_type = ' ';
    int year;
    if (!strcmp(field, "title"))
        field_type = 't';
    else if (!strcmp(field, "name"))
        field_type = 'n';
    else
    {
        field_type = 'y';
        result = str_to_int(key, &year);
    }
    if (result == ok)
    {
        int element_was_found = 0;
        int i = 0;
        while ((start <= end) && !element_was_found)
        {
            i = (start + end) / 2;
            switch (field_type)
            {
                case 't':
                    if (strcmp(films[i].title, key) > 0)
                        end = i - 1;
                    else if (strcmp(films[i].title, key) < 0)
                        start = i + 1;
                    else
                        element_was_found = 1;
                    break;
                case 'n':
                    if (strcmp(films[i].surname, key) > 0)
                        end = i - 1;
                    else if (strcmp(films[i].surname, key) < 0)
                        start = i + 1;
                    else
                        element_was_found = 1;
                    break;
                case 'y':
                    if (films[i].year > year)
                        end = i - 1;
                    else if (films[i].year < year)
                        start = i + 1;
                    else
                        element_was_found = 1;
                    break;
            }
        }
        if (element_was_found)
            print_film(films[i]);
        else
            fprintf(stdout, "Not found\n");
    }
    return result;
}

status_code str_to_int(char *string, int *number)
{
    status_code result = ok;
    *number = 0;
    int i = 0;
    char c = 0;
    while (((c = string[i++]) != '\0') && (c <= '9') && (c >= '0') && (result == ok))
    {
        if ((i == 1) && (c == '0'))
            result = wrong_year_format;
        *number = (*number) * 10 + (c - '0');
    }
    if (c != '\0')
        result = wrong_year_format;
    else if ((*number <= 0) || (*number >= 9999))
        result = wrong_year_format;
    return result;
}

void print_array(film_array films, int count_films)
{
    for (int i = 0; i < count_films; i++)
        print_film(films[i]);
}

void print_film(film_struct film)
{
    fprintf(stdout, "%s\n%s\n%d\n", film.title, film.surname, film.year);
}
