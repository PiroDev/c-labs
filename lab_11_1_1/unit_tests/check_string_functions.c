#include "check_test_suites.h"

#include "../include/string_functions.h"
#include <string.h>

START_TEST(test_write_symbol_to_string_common)
{
    char buf[2] = { 0 };
    char symbol = 'a';
    write_symbol_to_string(symbol, buf, 1, 0);
    ck_assert(symbol == buf[0]);
}
END_TEST

Suite *write_symbol_to_string_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("write_symbol_to_string");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_write_symbol_to_string_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_copy_to_string_common)
{
    char to[10] = { 0 };
    char *from = "abcdef";
    copy_to_string(from, to, 0, 9);

    ck_assert(!strcmp(to, from));
}
END_TEST

Suite *copy_to_string_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    
    equal_class = suite_create("copy_to_string");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_copy_to_string_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_swap_common)
{
    char a = 'a';
    char b = 'b';
    swap(&a, &b);

    ck_assert(a == 'b' && b == 'a');
}
END_TEST

Suite *swap_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    
    equal_class = suite_create("swap");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_swap_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_oct_common)
{
    unsigned long dec = 345847;
    char *expected_result = "1243367";
    char result[100] = { 0 };
    oct(dec, result);

    ck_assert(!strcmp(expected_result, result));
}
END_TEST

Suite *oct_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    
    equal_class = suite_create("oct");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_oct_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}
