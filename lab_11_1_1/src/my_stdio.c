#include "../include/my_stdio.h"

#include <stdarg.h>

#define MAX_OCT_LEN 100

void write_symbol_to_string(char symbol, char *str, int str_len, int pos)
{
    if (str && str_len > 0 && pos < str_len)
        str[pos] = symbol;
}

int string_len(const char *str)
{
    int len = 0;

    if (str)
    {
        while (*str)
        {
            str++;
            len++;
        }
    }

    return len;
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

int my_snprintf(char *buf, size_t buf_size, const char *format, ...)
{
    int result_len = 0;

    if (!format)
        result_len = -1;

    va_list argptr;
    va_start(argptr, format);

    while (result_len != -1 && *format)
    {
        char curr_symbol = '\0';
        if (*format == '%')
        {
            char temp[MAX_OCT_LEN] = { '\0' };
            format++;
            switch (*format)
            {
                case '%':
                    curr_symbol = '%';
                    break;
                case 'c':
                    curr_symbol = (char) va_arg(argptr, int);
                    break;
                case 'o':
                    oct((unsigned int) va_arg(argptr, unsigned int), temp);
                    result_len += copy_to_string(temp, buf, result_len, buf_size);
                    break;
                case 'l':
                    format++;
                    if (*format == 'o')
                    {
                        oct((long unsigned int) va_arg(argptr, long unsigned int), temp);
                        result_len += copy_to_string(temp, buf, result_len, buf_size);
                    }
                    else
                        result_len = -1;
                    break;
                case 's':
                    result_len += copy_to_string((char *) va_arg(argptr, char *), buf, result_len, buf_size);
                    break;
                default:
                    result_len = -1;
                    break;
            }
        }
        else
            curr_symbol = *format;

        if (curr_symbol)
        {
            write_symbol_to_string(curr_symbol, buf, buf_size, result_len);
            result_len++;
        }
        format++;
    }

    va_end(argptr);

    if (buf)
    {
        if (result_len > buf_size - 1)
            buf[buf_size - 1] = '\0';
        else 
            buf[result_len] = '\0';
    }

    return result_len;
}
