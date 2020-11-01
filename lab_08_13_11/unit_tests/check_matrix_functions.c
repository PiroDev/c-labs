#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "check_test_suites.h"
#include "matrix_functions.h"
#include "status_codes.h"

#define EPS 1e-5

int is_matrix_equal(const matrix_double_t *matrix_1, const matrix_double_t *matrix_2)
{
    int result = 1;
    if (matrix_1->count_rows != matrix_2->count_rows || matrix_1->count_columns != matrix_2->count_columns)
        result = 0;
    for (int i = 0; i < matrix_1->count_rows && result; i++)
        for (int j = 0; j < matrix_1->count_columns && result; j++)
            result &= fabs(matrix_1->rows[i][j] - matrix_2->rows[i][j]) < EPS;
    return result;
}

void fill_matrix_with_values(matrix_double_t *matrix, double *values)
{
    for (int i = 0; i < matrix->count_rows; i++)
        for (int j = 0; j < matrix->count_columns; j++)
            matrix->rows[i][j] = values[i * matrix->count_columns + j];
}

START_TEST(test_matrix_double_operation_add_common)
{
    double values_1[] = { 1, 2, 3,
                          4, 5, 6,
                          7, 8, 9 };
    matrix_double_t *matrix_1 = alloc_matrix_double(3, 3);
    fill_matrix_with_values(matrix_1, values_1);

    double values_2[] = { 9, 8, 7,
                          6, 5, 4,
                          3, 2, 1 };
    matrix_double_t *matrix_2 = alloc_matrix_double(3, 3);
    fill_matrix_with_values(matrix_2, values_2);

    double expected_values[] = { 10, 10, 10,
                                 10, 10, 10,
                                 10, 10, 10 };
    matrix_double_t *expected_matrix = alloc_matrix_double(3, 3);
    fill_matrix_with_values(expected_matrix, expected_values);

    matrix_double_t *result = alloc_matrix_double(3, 3);
    matrix_double_operation_add(matrix_1, matrix_2, result);

    ck_assert(is_matrix_equal(result, expected_matrix));

    free_matrix_double(&matrix_1);
    free_matrix_double(&matrix_2);
    free_matrix_double(&expected_matrix);
    free_matrix_double(&result);
}
END_TEST

Suite *matrix_double_operation_add_suite(void) {
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("matrix_double_operation_add");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_double_operation_add_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_matrix_double_operation_mult_square_matrix)
{
    double values_1[] = { 3, 2, 7, 5,
                          4, 6, 3, 1,
                          9, 7, 9, 9,
                          1, 3, 3, 1 };
    matrix_double_t *matrix_1 = alloc_matrix_double(4, 4);
    fill_matrix_with_values(matrix_1, values_1);

    double values_2[] = { 5, 3, 5, 1,
                          7, 6, 3, 2,
                          6, 5, 4, 1,
                          3, 9, 8, 2 };
    matrix_double_t *matrix_2 = alloc_matrix_double(4, 4);
    fill_matrix_with_values(matrix_2, values_2);

    double expected_values[] = { 86, 101, 89, 24,
                                 83, 72, 58, 21,
                                 175, 195, 174, 50,
                                 47, 45, 34, 12 };
    matrix_double_t *expected_matrix = alloc_matrix_double(4, 4);
    fill_matrix_with_values(expected_matrix, expected_values);

    matrix_double_t *result = alloc_matrix_double(4, 4);
    matrix_double_operation_mult(matrix_1, matrix_2, result);

    ck_assert(is_matrix_equal(result, expected_matrix));

    free_matrix_double(&matrix_1);
    free_matrix_double(&matrix_2);
    free_matrix_double(&expected_matrix);
    free_matrix_double(&result);
}
END_TEST

START_TEST(test_matrix_double_operation_mult_not_square_matrix)
{
    double values_1[] = { 7, 6,
                          3, 9,
                          5, 4 };
    matrix_double_t *matrix_1 = alloc_matrix_double(3, 2);
    fill_matrix_with_values(matrix_1, values_1);

    double values_2[] = { 3, 5, 7, 9,
                          1, 7, 7, 4 };
    matrix_double_t *matrix_2 = alloc_matrix_double(2, 4);
    fill_matrix_with_values(matrix_2, values_2);

    double expected_values[] = { 27, 77, 91, 87,
                                 18, 78, 84, 63,
                                 19, 53, 63, 61 };
    matrix_double_t *expected_matrix = alloc_matrix_double(3, 4);
    fill_matrix_with_values(expected_matrix, expected_values);

    matrix_double_t *result = alloc_matrix_double(3, 4);
    matrix_double_operation_mult(matrix_1, matrix_2, result);

    ck_assert(is_matrix_equal(result, expected_matrix));

    free_matrix_double(&matrix_1);
    free_matrix_double(&matrix_2);
    free_matrix_double(&expected_matrix);
    free_matrix_double(&result);
}
END_TEST

START_TEST(test_matrix_double_operation_mult_row_and_column)
{
    double values_1[] = { 5, 4, 7, 8, 1 };
    matrix_double_t *matrix_1 = alloc_matrix_double(1, 5);
    fill_matrix_with_values(matrix_1, values_1);

    double values_2[] = { 1,
                          8,
                          3,
                          5,
                          2 };
    matrix_double_t *matrix_2 = alloc_matrix_double(5, 1);
    fill_matrix_with_values(matrix_2, values_2);

    double expected_values[] = { 100 };
    matrix_double_t *expected_matrix = alloc_matrix_double(1, 1);
    fill_matrix_with_values(expected_matrix, expected_values);

    matrix_double_t *result = alloc_matrix_double(1, 1);
    matrix_double_operation_mult(matrix_1, matrix_2, result);

    ck_assert(is_matrix_equal(result, expected_matrix));

    free_matrix_double(&matrix_1);
    free_matrix_double(&matrix_2);
    free_matrix_double(&expected_matrix);
    free_matrix_double(&result);
}
END_TEST

Suite *matrix_double_operation_mult_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("matrix_double_operation_mult");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_double_operation_mult_square_matrix);
    tcase_add_test(tc_pos, test_matrix_double_operation_mult_not_square_matrix);
    tcase_add_test(tc_pos, test_matrix_double_operation_mult_row_and_column);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_matrix_double_get_det_3x3)
{
    double values[] = { 5, 4, 3,
                        7, 8, 9,
                        10, 13, 6 };
    matrix_double_t *matrix = alloc_matrix_double(3, 3);
    fill_matrix_with_values(matrix, values);

    double expected_det = -120.0;

    status_code err = ok;
    double det = matrix_double_get_det(matrix, &err);

    ck_assert_float_eq(expected_det, det);

    free_matrix_double(&matrix);
}
END_TEST

START_TEST(test_matrix_double_get_det_5x5)
{
    double values[] = { 7, 8, 3, 21, 2,
                        7, 5, -19, 23, 2,
                        -8, 13, 2, 5, 8,
                        8, -1, -7, -9, 1,
                        22, 3, 0, 1, 0 };
    matrix_double_t *matrix = alloc_matrix_double(5, 5);
    fill_matrix_with_values(matrix, values);

    double expected_det = 85232.0;

    status_code err = ok;
    double det = matrix_double_get_det(matrix, &err);

    ck_assert_float_eq(expected_det, det);

    free_matrix_double(&matrix);
}
END_TEST

Suite *matrix_double_get_det_suite(void) 
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("matrix_double_get_det_suite");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_double_get_det_3x3);
    tcase_add_test(tc_pos, test_matrix_double_get_det_5x5);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}
