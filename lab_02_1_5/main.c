#include <stdio.h>

#define MAX_LEN 10

typedef enum
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code arr_input(int*, int**);
status_code arr_sum_process(int*, int*, int*);

int main()
{
    status_code res = ok;
    int a[MAX_LEN];
    int *end;
    if (arr_input(a, &end) == ok)
    {
        int sum = 0;
        res = arr_sum_process(a, end, &sum);
        if (res == ok)
        {
            printf("%d", sum);
            return res;
        }
    }
    else
    {
        res = input_error;
    }
    printf("Error!");
    return res;
}

status_code arr_input(int *a, int **end)
{
    int len;
    if ((scanf("%d", &len) == 1) && (len > 0) && (len <= 10))
    {
        *end = a + len;
        for (int *i = a; i != *end; i++)
        {
            if (scanf("%d", i) != 1)
            {
                return input_error;
            }
        }
        return ok;
    }
    return input_error;
}

status_code arr_sum_process(int *a, int *end, int *sum)
{
    int *left = a;
    int *right = end - 1;
    while ((left < end) && (right > a))
    {
        while ((left < end) && (*left >= 0))
        {
            left++;
        }
        while ((right > a) && (*right <= 0))
        {
            right--;
        }
        if ((left < end) && (right > a))
        {
            *sum += (*left) * (*right);
        }
        left++;
        right--;
    }
    if (*sum == 0)
    {
        return items_error;
    }
    else
    {
        return ok;
    }
}
