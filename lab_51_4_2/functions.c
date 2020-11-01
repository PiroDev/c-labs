#include "functions.h"

status_code get_file(int argc, char **argv, FILE **f)
{
    status_code result = ok;
    if (argc != 2)
        result = args_error;
    else
    {
        *f = fopen((const char *) argv[1], "r");
        if (*f == NULL)
            result = file_error;
    }
    return result;
}

status_code process(FILE *f, double *average)
{
    status_code result = ok;
    double max, min, num;
    int max_pos = 0;
    int min_pos = 0;
    int n = 0;
    if (fscanf(f, "%lf", &max) == 1)
    {
        n = 1;
        min = max;
        min_pos = 1;
        max_pos = 1;
        while (fscanf(f, "%lf", &num) == 1)
        {
            n++;
            if (num > max)
            {
                max = num;
                max_pos = n;
            }
            if (num < min)
            {
                min = num;
                min_pos = n;
            }
        }
        if (!feof(f) || (n < 3) || (min == max))
            result = input_error;
    }
    else
        result = input_error;
    if (result == ok)
    {
        int i = 0;
        n = 0;
        rewind(f);
        int from, to;
        if (min_pos < max_pos)
        {
            from = min_pos;
            to = max_pos;
        }
        else
        {
            from = max_pos;
            to = min_pos;
        }
        while (i < from)
        {
            fscanf(f, "%lf", &num);
            i++;
        }
        while (i < to - 1)
        {
            fscanf(f, "%lf", &num);
            *average += num;
            i++;
            n++;
        }
        *average /= n;
    }
    fclose(f);
    return result;
}