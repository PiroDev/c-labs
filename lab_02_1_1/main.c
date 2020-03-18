#include <stdio.h>

#define MAX_LEN 10

typedef enum {ok, input_error, items_error} status_code;

status_code arr_input(int, int[]);
status_code odd_mltpl(int, int[], int*);

int main()
{
    int n;
    int a[MAX_LEN];
    int mltpl;
    mltpl = 0;
    status_code res = ok;
    if (scanf("%d", &n) != 1)
        res = input_error;
    if ((n > 10) || (n < 1))
        res = input_error;
    if ((res == ok) && (arr_input(n, a) == ok))
    {
        res = odd_mltpl(n, a, &mltpl);
        if (res == ok)
        {
            printf("%d", mltpl);
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

status_code arr_input(int n, int a[])
{
    int res = ok;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            res = input_error;
            break;
        }
    }
    return res;
}

status_code odd_mltpl(int n, int a[], int *mltpl)
{
    int res = ok;
    *mltpl = 1;
    int is_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            (*mltpl) *= a[i];
            is_odd = 1;
        }
    }
    if (is_odd == 0)
    {
        res = items_error;
    }
    return res;
}