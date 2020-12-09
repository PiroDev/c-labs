#include <stdlib.h>

#include "check_test_suites.h"

int main(void)
{
    int tests_passed = 0;
    Suite *equal_class;
    SRunner *runner;

    equal_class = write_symbol_to_string_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = copy_to_string_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = swap_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = oct_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    equal_class = my_snprintf_suite();
    runner = srunner_create(equal_class);
    srunner_run_all(runner, CK_VERBOSE);
    tests_passed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (!tests_passed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
