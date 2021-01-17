#ifndef UNIT_TESTS_CHECK_TEST_SUITES_H_
#define UNIT_TESTS_CHECK_TEST_SUITES_H_

#include <check.h>

Suite *push_front_suite(void);
Suite *insert_suite(void);
Suite *pop_front_suite(void);
Suite *reverse_suite(void);

Suite *get_polynom_value_suite(void);
Suite *get_polynom_dif_by_x_suite(void);
Suite *get_polynom_sum_suite(void);
Suite *divide_polynom_suite(void);

#endif  // UNIT_TESTS_CHECK_TEST_SUITES_H_
