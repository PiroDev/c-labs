#include <string.h>
#include <stdio.h>
#include "my_string.h"

void test_strrchr(void);

int main()
{
    test_strrchr();
    return 0;
}

void test_strrchr(void)
{
    int count_tests = 3;
    int successful_tests = 0;
    const char *str = "qwerty";
    int symbol = 'e';
    if (strrchr(str, symbol) == my_strrchr(str, symbol))
        successful_tests++;
    str = "happa";
    symbol = 'a';
    if (strrchr(str, symbol) == my_strrchr(str, symbol))
        successful_tests++;
    str = "abc";
    symbol = 'r';
    if (strrchr(str, symbol) == my_strrchr(str, symbol))
        successful_tests++;
    printf("Tests success: %d/%d", successful_tests, count_tests);
}