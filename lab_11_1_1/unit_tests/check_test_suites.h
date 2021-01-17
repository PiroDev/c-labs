#ifndef TEST_SUITES_H_
#define TEST_SUITES_H_

#include <check.h>

Suite *write_symbol_to_string_suite(void);
Suite *copy_to_string_suite(void);
Suite *swap_suite(void);
Suite *oct_suite(void);

Suite *my_snprintf_suite(void);

#endif  // TEST_SUITES_H_
