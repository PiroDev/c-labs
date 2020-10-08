#include "functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    double average = 0.0;
    FILE *f = NULL;
    result = get_file(argc, argv, &f);
    if (result == ok)
        result = process(f, &average);
    if (result != ok)
        printf("Error!");
    else
        printf("%f", average);
    return result;
}