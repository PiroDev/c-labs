#include "../include/string_functions.h"

void write_symbol_to_string(char symbol, char *str, int str_len, int pos)
{
    if (str && str_len > 0 && pos < str_len)
        str[pos] = symbol;
}

int copy_to_string(char *src, char *dest, int start_pos, int dest_len)
{
    int count = 0;

    while (src && *src)
    {
        write_symbol_to_string(*src, dest, dest_len, start_pos + count);
        src++;
        count++;
    }

    return count;
}

void swap(char *first_symbol, char *second_symbol)
{
    char temp = *first_symbol;
    *first_symbol = *second_symbol;
    *second_symbol = temp;
}

int oct(unsigned long int number, char *oct_str)
{
    int len = 0;

    if (oct_str)
    {
        char *src = oct_str;

        do
        {
            *oct_str++ = (number % 8) + '0';
            len++;
        } while (number /= 8);
        oct_str--;

        while (src < oct_str)
        {
            swap(src, oct_str);
            src++;
            oct_str--;
        }
    }

    return len;
}
