/**
 * \file input_output.c
 * \brief В этом файле реализованы функции ввода-вывода структур и массивов структур
*/
#include "input_output.h"

/**
 * \param argc - количество переданных аргументов
 * \param argv - массив с аргументами командной строки
 * \return Код состояния
*/
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
                result = string_year_to_int(argv[3], &number);
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
    if (!(result = read_str(f, film->title, MAX_TITLE_LENGTH)))
    {
        fscanf(f, "%*[\n]");
        if (!(result = read_str(f, film->surname, MAX_SURNAME_LENGTH)))
        {
           fscanf(f, "%*[\n]");
            if (fscanf(f, "%d\n", &film->year) != 1)
                result = file_input_error;
            else if (film->year <= 0)
                result = wrong_year_format;
        }
    }
    return result;
}

status_code read_str(FILE *f, char *str, int max_count)
{
    status_code result = ok;
    if (fgets(str, MAX_TITLE_LENGTH, f) == NULL)
        result = file_input_error;
    else
    {
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = '\0';
    }
    return result;
}


status_code string_year_to_int(char *string, int *number)
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