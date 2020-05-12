#include "functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    result = process(argc, argv);
    if (result != ok)
        printf("Error!");
    return result;
}