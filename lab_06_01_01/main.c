#include "functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    result = input_check(argc, argv);
    if (result == ok)
    {
        film_array films;
        int count_films = 0;
        // result = read_array(argv[1], films, &count_films);
        // if (result == ok)
        // {
        //     sort_array(films, count_films, argv[2]);
        //     if (argc == 3)
        //         print_array(films, count_films);
        //     else
        //         binary_search(films, count_films, argv[2], argv[3]);
        // }
    }
    return result;
}