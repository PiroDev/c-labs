#include "functions.h"

int main()
{
    int count = 0;
    status_code result = process(stdin, &count);
    if (result == ok)
    {
        printf("%d", count);
    }
    else
        printf("Error!");
    return result;
}