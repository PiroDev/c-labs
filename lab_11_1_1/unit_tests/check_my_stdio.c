#include "check_test_suites.h"

#include "../include/my_stdio.h"

START_TEST(test_my_snprintf_null_format)
{
    char buf[10] = { 0 };
    int result = my_snprintf(buf, 10, NULL, 123, 'a');
    ck_assert(result == -1);
}
END_TEST

START_TEST(test_my_snprintf_wrong_format)
{
    char buf[10] = { 0 };
    int result = my_snprintf(buf, 10, "%q", 123);
    ck_assert(result == -1);
}
END_TEST

START_TEST(test_my_snprintf_wrong_lformat)
{
    char buf[10] = { 0 };
    int result = my_snprintf(buf, 10, "%lq", 123);
    ck_assert(result == -1);
}
END_TEST

START_TEST(test_my_snprintf_without_vargs)
{
    char buf[30] = { 0 };
    char *format = "%% 123 hello there";
    char *expected_result = "% 123 hello there";

    int result = my_snprintf(buf, 30, format);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_o_common)
{
    char buf[30] = { 0 };
    unsigned dec = 337;
    char *format = "%o";
    char *expected_result = "521";

    int result = my_snprintf(buf, 30, format, dec);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_lo_common)
{
    char buf[30] = { 0 };
    unsigned long dec = 2543532000000533453;
    char *format = "%lo";
    char *expected_result = "215143416026667561715";

    int result = my_snprintf(buf, 30, format, dec);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_c_common)
{
    char buf[30] = { 0 };
    char c = 'f';
    char *format = "%c";
    char *expected_result = "f";

    int result = my_snprintf(buf, 30, format, c);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_s_common)
{
    char buf[30] = { 0 };
    char *expected_result = "fast & furious";
    char *format = "%s";

    int result = my_snprintf(buf, 30, format, expected_result);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_all)
{
    char buf[100] = { '\0' };
    char a = 'Y';
    unsigned b = 4565;
    unsigned long c = 2543532000000533453;
    char *expected_result = "HI __ Y % ?10725 9()() 215143416026667561715";
    char *format = "%s __ %c %% ?%o 9()() %lo";

    int result = my_snprintf(buf, 100, format, "HI", a, b, c);
    ck_assert((unsigned)result == strlen(expected_result) && !strcmp(buf, expected_result));
}
END_TEST

START_TEST(test_my_snprintf_small_buf)
{
    char buf[3] = { 0 };
    char *str = "abc";
    char *expected_result = "ab";
    int expected_len = 3;
    int result = my_snprintf(buf, 3, "%s", str);
    ck_assert(expected_len == result && !strcmp(expected_result, buf));
}
END_TEST

Suite *my_snprintf_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    TCase *tc_neg;

    equal_class = suite_create("my_snprintf");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_my_snprintf_without_vargs);
    tcase_add_test(tc_pos, test_my_snprintf_o_common);
    tcase_add_test(tc_pos, test_my_snprintf_lo_common);
    tcase_add_test(tc_pos, test_my_snprintf_c_common);
    tcase_add_test(tc_pos, test_my_snprintf_s_common);
    tcase_add_test(tc_pos, test_my_snprintf_all);
    tcase_add_test(tc_pos, test_my_snprintf_small_buf);


    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_my_snprintf_null_format);
    tcase_add_test(tc_neg, test_my_snprintf_wrong_format);
    tcase_add_test(tc_neg, test_my_snprintf_wrong_lformat);

    suite_add_tcase(equal_class, tc_pos);
    suite_add_tcase(equal_class, tc_neg);

    return equal_class;
}
