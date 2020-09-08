#include <stdio.h>
#include <string.h>
#include "main.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    result = main_process(argc, argv);
    return result;
}

status_code main_process(int argc, char **argv)
{
    status_code result = ok;
    if ((argc < 3) || (argc > 4))
        result = wrong_arguments_count;
    else
    {
        if (!strcmp(argv[2], "title") || !strcmp(argv[2], "name") || !strcmp(argv[2], "year"))
        {
            film_array films;
            int count_films = 0;
            result = read_array(argv[1], films, &count_films);
            if (result == ok)
            {
                sort_array(films, count_films, argv[2]);
                if (argc == 3)
                    print_array(films, count_films);
                else
                    binary_search(films, count_films, argv[2], argv[3]);
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
    f = fopen((const char *) fname, "r");
    if (f != NULL)
    {
        while (result == ok)
        {
            film_struct temp = { .year = 0 };
            result = read_film(f, &temp);
            films[*count_films] = temp;
            *count_films += 1;
        }
        *count_films -= 1;
        if (!feof(f))
            result = file_input_error;
        else if (*count_films == 0)
            result = empty_file_error;
        else
            result = ok;
        fclose(f);
    }
    else
        result = file_input_error;
    return result;
}

status_code read_film(FILE *f, film_struct *film)
{
    status_code result;
    if (read_str(f, film->title, MAX_TITLE_LENGTH) \
        || read_str(f, film->surname, MAX_SURNAME_LENGTH) || (fscanf(f, "%d", &film->year) != 1))
        result = file_input_error;
    else
        fgetc(f); // считывает \n после fscanf
    return result;
}

status_code read_str(FILE *f, char *str, int max_count)
{
    status_code result = ok;
    int count = 0;
    char c = 0;
    while ((count < max_count) && ((c = fgetc(f)) != EOF) && (c != '\n'))
    {
        str[count] = c;
        count++;
    }
    if ((c != '\n') && (c != EOF))
        result = file_input_error;
    if (count < max_count)
        str[count + 1] = '\0';
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
        if (year <= 0)
            result = wrong_year_format;
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
            printf("Not found\n");
    }
    return result;
}

status_code str_to_int(char *string, int *number)
{
    status_code result = ok;
    *number = 0;
    int i = 0;
    char c = 0;
    while (((c = string[i++]) != '\0') && (c <= '9') && (c >= '0'))
        *number = (*number) * 10 + (c - '0');
    if (c != '\0')
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
    printf("%s\n%s\n%d\n", film.title, film.surname, film.year);
}
