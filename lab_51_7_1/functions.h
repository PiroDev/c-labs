#include <stdio.h>

typedef enum
{
    ok = 0,
    input_error = -1
} status_code;

status_code process(FILE *, int *);