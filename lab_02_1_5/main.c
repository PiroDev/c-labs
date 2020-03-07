#include <stdio.h>

#define MAX_LEN 10

int arr_input(int*, int**);
int min_cnt_pos_neg(int*, int*);
int arr_sum_process(int*, int*, int*);

int main()
{
    int a[MAX_LEN];
    int *end;
    if (arr_input(a, &end))
    {
        int sum = 0;
        if (arr_sum_process(a, end, &sum))
        {
            printf("%d", sum);
            return 0;
        }
    }
    printf("Input error!");
    return 1;
}

int arr_input(int *a, int **end)
{
    int len;
    if ((scanf("%d", &len) == 1) && (len > 0) && (len <= 10))
    {
        *end = a + len;
        for (int *i = a; i != *end; i++)
        {
            if (scanf("%d", i) != 1)
            {
                printf("Input error!");
                return 0;
            }
        }
        return 1;
    }
    printf("Input error!");
    return 0;
}

int arr_sum_process(int *a, int *end, int *sum)
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
        return 0;
    }
    else
    {
        return 1;
    }
}
