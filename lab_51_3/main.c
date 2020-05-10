/*
Integer type: int;
Sort algorithm: bubble sort;
Sort type: increasing sort;
*/

#include "functions.h"

int main(int argc, char **argv)
{
    int result = OK;
    result = process(argc, argv);
    if (result != OK)
        printf("Error!");
    return result;
}