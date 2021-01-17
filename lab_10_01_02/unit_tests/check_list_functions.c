#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#include "check_test_suites.h"
#include "list_functions.h"

#define EPS 1e-5

int is_list_equal(const node_t *head_first, const node_t *head_second, int size)
{
    int result = 0;
    while (head_first && head_second && !memcmp(head_first->data, head_second->data, size))
    {
        head_first = head_first->next;
        head_second = head_second->next;
    }
    if (!head_first && !head_second)
        result = 1;
    return result;
}

START_TEST(test_push_front_common)
{
    char *data = "data";
    node_t *expected = new_node(data);
    node_t *result = NULL;
    result = push_front(result, data);
    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    free(expected);
    free(result);
}
END_TEST

Suite *push_front_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("push_front");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_push_front_common);

    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}

START_TEST(test_insert_before_head)
{
    char *data = "data";
    char *ins_data = "ins_data";
    node_t *expected = new_node(data);
    expected = push_front(expected, ins_data);
    node_t *result = new_node(data);
    insert(&result, new_node(ins_data), result);

    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    while (expected)
        pop_front(&expected);

    while (result)
        pop_front(&result);
}
END_TEST

START_TEST(test_insert_before_common)
{
    char *data = "data";
    char *ins_data = "ins_data";
    node_t *expected = new_node(ins_data);
    expected = push_front(expected, data);
    node_t *result = new_node(data);
    insert(&result, new_node(ins_data), NULL);

    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    while (expected)
        pop_front(&expected);

    while (result)
        pop_front(&result);
}
END_TEST

START_TEST(test_insert_null_head)
{
    char *data = "data";
    char *ins_data = "ins_data";
    node_t *expected = new_node(data);
    node_t *result = new_node(data);
    node_t *element = new_node(ins_data);
    insert(NULL, element, result);

    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    pop_front(&expected);
    pop_front(&result);
    pop_front(&element);
}
END_TEST

START_TEST(test_insert_null_element)
{
    char *data = "data";
    node_t *expected = new_node(data);
    node_t *result = new_node(data);
    insert(&result, NULL, result);

    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    pop_front(&expected);
    pop_front(&result);
}
END_TEST

Suite *insert_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    TCase *tc_neg;
    equal_class = suite_create("insert");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_insert_before_head);
    tcase_add_test(tc_pos, test_insert_before_common);
    suite_add_tcase(equal_class, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_insert_null_head);
    tcase_add_test(tc_neg, test_insert_null_element);
    suite_add_tcase(equal_class, tc_neg);

    return equal_class;
}

START_TEST(test_pop_front_common)
{
    char *expected_data = "data";
    node_t *head = new_node(expected_data);
    void *result_data = pop_front(&head);

    ck_assert_mem_eq((void *)expected_data, result_data, sizeof(expected_data));
}
END_TEST

START_TEST(test_pop_front_null_head_ptr)
{
    void *result_data = pop_front(NULL);
    ck_assert(!result_data);
}
END_TEST

START_TEST(test_pop_front_null_head)
{
    void *head = NULL;
    void **head_ptr = &head;
    void *result_data = pop_front((void *)head_ptr);
    ck_assert(!result_data);
}
END_TEST

Suite *pop_front_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;
    TCase *tc_neg;

    equal_class = suite_create("pop_front");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pop_front_common);
    suite_add_tcase(equal_class, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_pop_front_null_head_ptr);
    tcase_add_test(tc_neg, test_pop_front_null_head);
    suite_add_tcase(equal_class, tc_neg);

    return equal_class;
}

START_TEST(test_reverse_common)
{
    char *data_first = "1";
    char *data_second = "2";
    node_t *expected = NULL;
    expected =  push_front(expected, data_first);
    expected =  push_front(expected, data_second);
    node_t *buf = NULL;
    buf = push_front(buf, data_second);
    buf = push_front(buf, data_first);

    node_t *result = reverse(buf);

    ck_assert(is_list_equal(expected, result, sizeof(char *)));
    while (expected)
        pop_front(&expected);

    while (result)
        pop_front(&result);
}
END_TEST

Suite *reverse_suite(void)
{
    Suite *equal_class;
    TCase *tc_pos;

    equal_class = suite_create("reverse");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_reverse_common);
    suite_add_tcase(equal_class, tc_pos);

    return equal_class;
}
