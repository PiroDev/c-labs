#include "../include/my_stdio.h"

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_OCT_LEN ((sizeof(long int) * 8 / 3) + 1)

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

int copy_to_string(char *src, char *dest)
{
    int count = 0;

    if (src && dest)
    {
        while (*src)
        {
            *dest = *src;
            src++;
            dest++;
            count++;
        }
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

    return len;
}

int my_snprintf(char *buf, size_t buf_size, const char *format, ...)
{
    int result = 0;

    if (buf_size > INT_MAX || buf_size < 0 || !format)
        result = -1;

    va_list argptr;
    va_start(argptr, format);

    char *src = buf;

    while (result != -1 && *format)
    {
        if (*format == '%')
        {
            char temp[MAX_OCT_LEN] = { '\0' };
            format++;
            switch (*format)
            {
                case '%':
                    *buf = '%';
                    break;
                case 'c':
                    *buf = (unsigned char) va_arg(argptr, int);
                    break;
                case 'o':
                    oct((unsigned int) va_arg(argptr, unsigned int), temp);
                    buf += (copy_to_string(temp, buf) - 1);
                    break;
                case 'l':
                    format++;
                    if (*format == 'o')
                    {
                        oct((long unsigned int) va_arg(argptr, long unsigned int), temp);
                        buf += (copy_to_string(temp, buf) - 1);
                    }
                    else
                    {
                        result = -1;
                    }
                    break;
                case 's':
                    buf += (copy_to_string((char *) va_arg(argptr, char *), buf) - 1);
                    break;
                default:
                    buf++;
                    break;
            }
        }
        else
        {
            *buf = *format;
        }
        buf++;
        format++;
    }

    va_end(argptr);

    if (result != -1 && src)
    {
        src[buf_size - 1] = '\0';
        result = string_len(src);
    }

    return result;
}
