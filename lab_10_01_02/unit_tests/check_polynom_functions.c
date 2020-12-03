#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "check_test_suites.h"
#include "polynom_functions.h"
#include "list_functions.h"
#include "status_codes.h"

START_TEST(get_polynom_value_common)
{
    int expected = 24;
    node_t *polynom = push_new_ratio(NULL, 3, 3);
    int result = get_polynom_value(polynom, 2);
    delete_polynom(polynom);
    ck_assert_int_eq(expected, result);
}
END_TEST

Suite *get_polynom_value_suite(void) {
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("get_polynom_value_field");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, get_polynom_value_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

int cmp_nodes(node_t *node_1, node_t *node_2)
{
    int power_1 = ((ratio_t *)node_1->data)->power;
    int mult_1 = ((ratio_t *)node_1->data)->mult;
    int power_2 = ((ratio_t *)node_2->data)->power;
    int mult_2 = ((ratio_t *)node_2->data)->mult;

    return (power_1 == power_2 && mult_1 == mult_2);
}

int cmp_polynoms(node_t *polynom_1, node_t *polynom_2)
{
    int result = 1;
    while (result && polynom_1 && polynom_2)
    {
        result = cmp_nodes(polynom_1, polynom_2);
        polynom_1 = polynom_1->next;
        polynom_2 = polynom_2->next;
    }
    return result;
}

START_TEST(get_polynom_dif_by_x_common)
{
    node_t *polynom = push_new_ratio(NULL, 3, 3);
    node_t *expected = push_new_ratio(NULL, 2, 9);
    polynom = get_polynom_dif_by_x(polynom);
    ck_assert(cmp_polynoms(polynom, expected));
    delete_polynom(polynom);
    delete_polynom(expected);
}
END_TEST

Suite *get_polynom_dif_by_x_suite(void) {
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("get_polynom_dif_by_x");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, get_polynom_dif_by_x_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(get_polynom_sum_common)
{
    node_t *polynom_1 = push_new_ratio(NULL, 4, 4);
    polynom_1 = push_new_ratio(polynom_1, 3, 2);
    polynom_1 = push_new_ratio(polynom_1, 1, 4);
    polynom_1 = reverse(polynom_1);

    node_t *polynom_2 = push_new_ratio(NULL, 3, 4);
    polynom_2 = push_new_ratio(polynom_2, 2, 2);
    polynom_2 = push_new_ratio(polynom_2, 0, -3);
    polynom_2 = reverse(polynom_2);

    node_t *expected = push_new_ratio(NULL, 4, 4);
    expected = push_new_ratio(expected, 3, 6);
    expected = push_new_ratio(expected, 2, 2);
    expected = push_new_ratio(expected, 1, 4);
    expected = push_new_ratio(expected, 0, -3);
    expected = reverse(expected);

    node_t *result = NULL;
    get_polynom_sum(polynom_1, polynom_2, &result);
    ck_assert(cmp_polynoms(result, expected));
    delete_polynom(polynom_1);
    delete_polynom(polynom_2);
    delete_polynom(expected);
    delete_polynom(result);
}
END_TEST

Suite *get_polynom_sum_suite(void) {
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("get_polynom_sum");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, get_polynom_sum_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(divide_polynom_common)
{
    node_t *polynom = push_new_ratio(NULL, 4, 4);
    polynom = push_new_ratio(polynom, 3, 2);
    polynom = push_new_ratio(polynom, 1, 4);
    polynom = reverse(polynom);

    node_t *expected_1 = push_new_ratio(NULL, 4, 4);

    node_t *expected_2 = push_new_ratio(NULL, 3, 2);
    expected_2 = push_new_ratio(expected_2, 1, 4);
    expected_2 = reverse(expected_2);

    node_t *result_1 = NULL;
    node_t *result_2 = NULL;
    divide_polynom(polynom, &result_1, &result_2);
    ck_assert(cmp_polynoms(result_1, expected_1) && cmp_polynoms(result_2, expected_2));
    delete_polynom(polynom);
    delete_polynom(expected_1);
    delete_polynom(expected_2);
    delete_polynom(result_1);
    delete_polynom(result_2);
}
END_TEST

Suite *divide_polynom_suite(void) {
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("divide_polynom");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, divide_polynom_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}
