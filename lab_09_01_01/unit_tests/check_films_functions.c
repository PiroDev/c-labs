#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "check_test_suites.h"
#include "films_functions.h"
#include "status_codes.h"

#define EPS 1e-5

START_TEST(test_compare_films_by_field_title_less)
{
    film_t film_1 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    film_t film_2 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    int result = compare_films_by_field("title", &film_1, &film_2);
    ck_assert_int_lt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_title_greater)
{
    film_t film_1 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    film_t film_2 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    int result = compare_films_by_field("title", &film_1, &film_2);
    ck_assert_int_gt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_title_equal)
{
    film_t film_1 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    film_t film_2 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    int result = compare_films_by_field("title", &film_1, &film_2);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_surname_less)
{
    film_t film_1 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    film_t film_2 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    int result = compare_films_by_field("name", &film_1, &film_2);
    ck_assert_int_lt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_surname_greater)
{
    film_t film_1 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    film_t film_2 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    int result = compare_films_by_field("name", &film_1, &film_2);
    ck_assert_int_gt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_surname_equal)
{
    film_t film_1 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    film_t film_2 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    int result = compare_films_by_field("name", &film_1, &film_2);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_year_less)
{
    film_t film_1 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    film_t film_2 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    int result = compare_films_by_field("year", &film_1, &film_2);
    ck_assert_int_lt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_year_greater)
{
    film_t film_1 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    film_t film_2 = { .title = "Fight Club", .surname = "David Fincher", .year = 1999 };
    int result = compare_films_by_field("year", &film_1, &film_2);
    ck_assert_int_gt(result, 0);
}
END_TEST

START_TEST(test_compare_films_by_field_year_equal)
{
    film_t film_1 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    film_t film_2 = { .title = "Inception", .surname = "Christopher Nolan", .year = 2010 };
    int result = compare_films_by_field("year", &film_1, &film_2);
    ck_assert_int_eq(result, 0);
}
END_TEST

Suite *compare_films_by_field_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("compare_films_by_field");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_films_by_field_title_less);
    tcase_add_test(tc_pos, test_compare_films_by_field_title_greater);
    tcase_add_test(tc_pos, test_compare_films_by_field_title_equal);
    tcase_add_test(tc_pos, test_compare_films_by_field_surname_less);
    tcase_add_test(tc_pos, test_compare_films_by_field_surname_greater);
    tcase_add_test(tc_pos, test_compare_films_by_field_surname_equal);
    tcase_add_test(tc_pos, test_compare_films_by_field_year_less);
    tcase_add_test(tc_pos, test_compare_films_by_field_year_greater);
    tcase_add_test(tc_pos, test_compare_films_by_field_year_equal);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

void film_set_fields(film_t *film, const char *title, const char *surname, int year)
{
    film->title = strdup(title);
    film->surname = strdup(surname);
    film->year = year;
}

int films_is_equal(const film_t *film_1, const film_t *film_2)
{
    int result = 1;
    if (strcmp(film_1->title, film_2->title) || strcmp(film_1->title, film_2->title) ||
        film_1->year != film_2->year)
        result = 0;
    return result;
}

int film_vectors_is_equal(const film_vector_t *films_1, const film_vector_t *films_2)
{
    int result = 1;
    for (int i = 0; i < films_1->count && result; i++)
        result &= films_is_equal(films_1->data + i, films_2->data + i);
    return result;
}

START_TEST(test_sort_films_common)
{
    film_vector_t films = { .count = 0, .size = 0, .data = NULL };
    film_t film;
    film_set_fields(&film, "The Shawshank Redemption", "Frank Darabont", 1994);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Godfather", "Francis Ford Coppola", 1972);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Dark Knight", "Christopher Nolan", 2008);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Schindler's List", "Steven Spielberg", 1993);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Fight Club", "David Fincher", 1999);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Inception", "Christopher Nolan", 2010);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_vector_t films_expected = { .count = 0, .size = 0, .data = NULL };
    film_set_fields(&film, "Fight Club", "David Fincher", 1999);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Inception", "Christopher Nolan", 2010);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Schindler's List", "Steven Spielberg", 1993);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Dark Knight", "Christopher Nolan", 2008);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Godfather", "Francis Ford Coppola", 1972);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Shawshank Redemption", "Frank Darabont", 1994);
    push_back(&films_expected, &film);
    free_film_string_fields(&film);

    sort_films(&films, "title");

    ck_assert(film_vectors_is_equal(&films, &films_expected));
    free_vector(&films);
    free_vector(&films_expected);
}
END_TEST

Suite *sort_films_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("sort_films");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_films_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_binary_search_common)
{
    film_vector_t films = { .count = 0, .size = 0, .data = NULL };
    film_t film;
    film_set_fields(&film, "Fight Club", "David Fincher", 1999);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Inception", "Christopher Nolan", 2010);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "Schindler's List", "Steven Spielberg", 1993);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Dark Knight", "Christopher Nolan", 2008);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Godfather", "Francis Ford Coppola", 1972);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_set_fields(&film, "The Shawshank Redemption", "Frank Darabont", 1994);
    push_back(&films, &film);
    free_film_string_fields(&film);

    film_t film_expected = { .title = "The Dark Knight", .surname = "Christopher Nolan", .year = 2008 };

    film_t film_result = { .title = NULL, .surname = NULL, .year = 0 };
    const char *search_title = "The Dark Knight";
    binary_search(&films, "title", search_title, &film_result);

    ck_assert(films_is_equal(&film_expected, &film_result));
    free_film_string_fields(&film_result);
    free_vector(&films);
}
END_TEST

Suite *binary_search_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("binary_search");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_binary_search_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}
