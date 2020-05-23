#include <stdio.h>

typedef enum
{
    ok = 0,
    args_error = -1,
    file_error = -2,
    input_error = -3
} status_code;

status_code get_file(int, char **, FILE **);
status_code process(FILE *, double *);