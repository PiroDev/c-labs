#include <stdio.h>

#define MAX_LEN 10

int arr_input(int*, int**);
int min_cnt_pos_neg(int*, int*);
int arr_sum_process(int*, int*, int);

int main()
{
    int a[MAX_LEN];
    int *end = a;
    if (arr_input(a, &end))
    {
        int k = min_cnt_pos_neg(a, end);
        if (k)
        {
            int sum = arr_sum_process(a, end, k);
            printf("%d", sum);
            return 0;
        }
    }
    return 1;
}

int arr_input(int *a, int **end)
{
    int len;
    if ((scanf("%d", &len) == 1) && (len > 0) && (len <= 10))
    {
        *end += len;
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

int min_cnt_pos_neg(int *a, int *end)
{
    int cnt_pos = 0;
    int cnt_neg = 0;
    for (int *i = a; i != end; i++)
    {
        if (*i > 0)
        {
            cnt_pos++;
        }
        else if (*i <0)
        {
            cnt_neg++;
        }
    }
    if ((cnt_neg != 0) && (cnt_pos != 0))
    {
        if (cnt_neg < cnt_pos)
        {
            return cnt_neg;
        }
        else
        {
            return cnt_pos;
        }
    }
    printf("Input error!");
    return 0;
}

int arr_sum_process(int *a, int *end, int k)
{
    int sum = 0;
    int i = 0;
    int *left = a;
    int *right = end;
    while(i < k)
    {
        while (*left >= 0)
        {
            left++;
        }
        while (*right <= 0)
        {
            right--;
        }
        sum += *left * *right;
        left++;
        right--;
        i++;
    }
    return sum;
}
