#include <stdio.h>

#define MAX_LEN 10

int arr_input(int, int[]);
int odd_mltpl(int, int[]);

int main()
{
    int N;
    int res = scanf("%d", &N);
    int a[MAX_LEN];
    if ((res) && (N <= 10) && (N >= 1) && (arr_input(N, a)))
    {
        res = odd_mltpl(N, a);
        if (res)
        {
            printf("%d", res);
            return 0;
        }
    }
    printf("Input error!");
    return 1;
}

int arr_input(int n, int a[])
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = scanf("%d", &a[i]);
        if (res != 1)
        {
            return 0;
        }
    }
    return 1;
}

int odd_mltpl(int n, int a[])
{
    int res = 1;
    int is_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            res *= a[i];
            is_odd = 1;
        }
    }
    if (is_odd)
    {
        return res;
    }
    return 0;
}
