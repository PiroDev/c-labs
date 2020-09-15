#include "struct_functions.h"

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

