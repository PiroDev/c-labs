#include "array_functions.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

void array_shift_left(int *array, size_t array_size, size_t shift)
{
    if (!array || !array_size)
    {
        return;
    }

    shift %= array_size;

    if (shift)
    {
        int *buf = calloc(shift, sizeof(int));
        memcpy(buf, array, shift * sizeof(int));

        memcpy(array, array + shift, (array_size - shift) * sizeof(int));
        memcpy(array + (array_size - shift), buf, shift * sizeof(int));

        free(buf);
    }
}

int is_square(int num)
{
    int sqr = sqrt(num);
    while (sqr * sqr > num)
    {
        sqr--;
    }

    while (sqr * sqr < num)
    {
        sqr++;
    }

    return sqr * sqr == num;
}

int array_fill_full_squares(int *src_array, size_t src_size, int *dest_array)
{
    int result = 0;

    if (!src_array || !src_size)
    {
        result = -1;
    }
    else
    {
        for (size_t i = 0; i < src_size; i++)
        {
            if (is_square(src_array[i]))
            {
                if (dest_array)
                {
                    dest_array[result] = src_array[i];
                }
                result++;
            }
        }
    }

    return result;
}
