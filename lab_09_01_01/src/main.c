#include "films_functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    result = validate_args(argc, argv);
    if (!result)
    {
        film_vector_t films = { .count = 0, .size = 0, .data = NULL };

        result = read_films_from_file(argv[1], &films); /* считывание структур в массив */
        if (!result)
        {
            sort_films(&films, argv[2]); /* сортировка массива по выбранному полю */

            if (argc == 3)
                print_array(&films); /* вывод отсортированного массива на экран */
            else
            {
                film_t temp_film = { .title = NULL, .surname = NULL, .year = 0 };
                /* бинарный поиск по ключу */
                if (binary_search(&films, argv[2], argv[3], &temp_film))
                {
                    print_film(&temp_film);
                    free_film_string_fields(&temp_film);
                }
                else
                    fprintf(stdout, "Not found\n");
            }
        }
        free_vector(&films);
    }
    return result;
}
