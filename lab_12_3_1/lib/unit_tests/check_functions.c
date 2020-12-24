#include "array_functions.h"
#include "status_codes.h"
#include "check_test_suites.h"

/* is_even tests */
START_TEST(test_is_even_even)
{
    int a = 2;
    ck_assert_int_eq(is_even(a), 1);
}
END_TEST

START_TEST(test_is_even_odd)
{
    int a = 3;
    ck_assert_int_eq(is_even(a), 0);
}
END_TEST

Suite *is_even_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("is_even");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_is_even_even);
    tcase_add_test(tc_pos, test_is_even_odd);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

/* swap tests */
START_TEST(test_swap_usual)
{
    int a = 1;
    int b = 2;
    int new_a = b;
    int new_b = a;

    swap(&a, &b, sizeof(int));
    ck_assert_int_eq(a, new_a);
    ck_assert_int_eq(b, new_b);
}
END_TEST

Suite *swap_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("swap");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_swap_usual);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

/* cmp_int tests */
START_TEST(test_cmp_int_bigger)
{
    int a = 32;
    int b = -12;
    int result;

    result = cmp_int((void *) &a, (void *) &b);
    ck_assert_int_eq(result, 44);
}
END_TEST

START_TEST(test_cmp_int_equal)
{
    int a = 369;
    int b = 369;
    int result;
    
    result = cmp_int((void *) &a, (void *) &b);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_cmp_int_less)
{
    int a = -5;
    int b = 4;
    int result;

    result = cmp_int((void *) &a, (void *) &b);
    ck_assert_int_eq(result, -9);
}
END_TEST

Suite* cmp_int_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("cmp_int");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_cmp_int_bigger);
    tcase_add_test(tc_pos, test_cmp_int_equal);
    tcase_add_test(tc_pos, test_cmp_int_less);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

/* copy_array tests */
START_TEST(test_copy_array_part)
{
    int array_from[7] = {3, 4, -5, -3, 0, 123, 2};
    int count = 3;
    int array_dest[3];
    int result_array[3] = {3, 4, -5};

    copy_array(array_from, array_dest, count);
    ck_assert_mem_eq(result_array, array_dest, count);
}
END_TEST

START_TEST(test_copy_array_full)
{
    int array_from[7] = {3, 4, -5, -3, 0, 123, 2};
    int count = 7;
    int array_dest[7];

    copy_array(array_from, array_dest, count);
    ck_assert_mem_eq(array_from, array_dest, count);
}
END_TEST

Suite* copy_array_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("copy_array");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_copy_array_part);
    tcase_add_test(tc_pos, test_copy_array_full);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

/* key tests */
START_TEST(test_key_empty_result_array)
{
    int array[5] = {-1, 3, 2, 14, 1231};
    int *end_of_array = array + 5;
    int *filtered_array = NULL;
    int *end_of_filtered_array = NULL;
    int result;

    result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);
    ck_assert_int_eq(result, error_empty_filtration_output);
    free_resources(&filtered_array, &end_of_filtered_array);
}
END_TEST

START_TEST(test_key_empty_input_array)
{
    int temp = 0;
    int *array = &temp;
    int *end_of_array = array;
    int *filtered_array = NULL;
    int *end_of_filtered_array = NULL;
    int result;

    result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);
    ck_assert_int_eq(result, error_empty_filtration_output);
}
END_TEST

START_TEST(test_key_full_array)
{
    int array[7] = {12, 23, 0, 35, 25, 10, 22};
    int *result_array = array;
    int *end_of_array = array + 7;
    int *filtered_array = NULL;
    int *end_of_filtered_array = NULL;
    int result;

    result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);
    ck_assert_int_eq(result, ok);
    ck_assert_mem_eq(array, result_array, 7);
    free_resources(&filtered_array, &end_of_filtered_array);
}
END_TEST

START_TEST(test_key_one_neg_number)
{
    int array[7] = {12, 23, 0, -1, 25, 10, 22};
    int result_array[3] = {12, 23, 0};
    int *end_of_array = array + 7;
    int *filtered_array = NULL;
    int *end_of_filtered_array = NULL;
    int result;

    result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);
    ck_assert_int_eq(result, ok);
    ck_assert_mem_eq(array, result_array, 3);
    free_resources(&filtered_array, &end_of_filtered_array);
}
END_TEST

START_TEST(test_key_many_neg_numbers)
{
    int array[7] = {12, -3, 0, -1, 25, -55, 22};
    int result_array[5] = {12, -3, 0, -1, 25};
    int *end_of_array = array + 7;
    int *filtered_array = NULL;
    int *end_of_filtered_array = NULL;
    int result;

    result = key(array, end_of_array, &filtered_array, &end_of_filtered_array);
    ck_assert_int_eq(result, ok);
    ck_assert_mem_eq(array, result_array, 5);
    free_resources(&filtered_array, &end_of_filtered_array);
}
END_TEST

Suite* key_suite(void)
{
    Suite *equal_class;
    TCase *tc_neg;
    TCase *tc_pos;

    equal_class = suite_create("key");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_empty_result_array);
    tcase_add_test(tc_neg, test_key_empty_input_array);
    suite_add_tcase(equal_class, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_neg, test_key_full_array);
    tcase_add_test(tc_neg, test_key_one_neg_number);
    tcase_add_test(tc_neg, test_key_many_neg_numbers);
    suite_add_tcase(equal_class, tc_pos);
    return equal_class;
}

/* mysort tests */
START_TEST(test_mysort_pos_array)
{
    int array[6] = {3, 2, 9, 2, 13, 1};
    int result_array[6] = {1, 2, 2, 3, 9, 13};

    mysort(array, 6, sizeof(int), *cmp_int);
    ck_assert_mem_eq(result_array, array, 6);
}
END_TEST

START_TEST(test_mysort_pos_neg_array)
{
    int array[7] = {-3, 2, 0, 11, -45, 22, 13};
    int result_array[7] = {-45, -3, 0, 2, 11, 13, 22};

    mysort(array, 7, sizeof(int), *cmp_int);
    ck_assert_mem_eq(result_array, array, 7);
}
END_TEST

START_TEST(test_mysort_reversed_arr)
{
    int array[10] = {9, 8, 7, 5, 3, 0, -10, -20, -45, -60};
    int result_array[10] = {-60, -45, -20, -10, 0, 3, 5, 7, 8, 9};

    mysort(array, 10, sizeof(int), *cmp_int);
    ck_assert_mem_eq(result_array, array, 10);
}
END_TEST

START_TEST(test_mysort_sorted_arr)
{
    int array[10] = {1, 5, 10, 20, 45, 47, 322, 666, 6969, 12322};
    int result_array[10] = {1, 5, 10, 20, 45, 47, 322, 666, 6969, 12322};

    mysort(array, 10, sizeof(int), *cmp_int);
    ck_assert_mem_eq(result_array, array, 10);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    equal_class = suite_create("mysort");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_pos_array);
    tcase_add_test(tc_pos, test_mysort_pos_neg_array);
    tcase_add_test(tc_pos, test_mysort_reversed_arr);
    tcase_add_test(tc_pos, test_mysort_sorted_arr);
    suite_add_tcase(equal_class, tc_pos);
    return equal_class;
}
