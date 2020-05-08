#include "functions.h"

status_code process(FILE *f, int *count)
{
    status_code result = ok;
    *count = 0;
    int n = 0;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    while (fscanf(f, "%d", &a1) == 1)
    {
        n++;
        if (n >= 3)
        {
            if ((a2 > a1) && (a2 > a3))
                *count += 1;
        }
        a3 = a2;
        a2 = a1;
    }
    if (n == 0)
        result = input_error;
    return result;
}