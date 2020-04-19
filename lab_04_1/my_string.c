#include <stddef.h>
#include "my_string.h"

char *my_strrchr(const char *str, int symbol)
{
    char* result = NULL;
    int index = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == symbol)
            index = i;
        i++;
    }
    if (str[index] == symbol)
        result = (char*)(str + index);
    return result;
}