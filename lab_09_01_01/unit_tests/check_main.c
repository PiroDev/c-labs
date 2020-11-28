#include <stdlib.h>

#include "check_test_suites.h"

int main(void)
{
    int tests_passed = 0;
    Suite *equal_class;
    SRunner *runner;

    equal_class = compare_films_by_field_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = sort_films_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = binary_search_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (!tests_passed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
