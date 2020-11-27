#include <stdlib.h>

#include "check_test_suites.h"

int main(void)
{
    int tests_passed = 0;
    Suite *equal_class;
    SRunner *runner;

    equal_class = push_front_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = insert_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = pop_front_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = reverse_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = sorted_insert_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = sort_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (!tests_passed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
