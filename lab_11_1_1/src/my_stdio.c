#include "../include/my_stdio.h"

#include <limits.h>
#include <stdarg.h>

#define MAX_OCT_LEN 100

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

    if (buf_size > INT_MAX || buf_size < 0 || !format)
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
                    if (buf)
                        copy_to_string(temp, buf + result_len);
                    result_len += string_len(temp);
                    break;
                case 'l':
                    format++;
                    if (*format == 'o')
                    {
                        oct((long unsigned int) va_arg(argptr, long unsigned int), temp);
                        if (buf)
                            copy_to_string(temp, buf + result_len);
                        result_len += string_len(temp);
                    }
                    else
                        result_len = -1;
                    break;
                case 's':
                    if (buf)
                        result_len += copy_to_string((char *) va_arg(argptr, char *), buf + result_len);
                    else
                        result_len += string_len((char *) va_arg(argptr, char *));
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
            if (buf)
                buf[result_len] = curr_symbol;
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
