#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code arr_input(int, int[]);
status_code odd_mltpl(int, int[], int*);

int main()
{
    int n;
    int a[MAX_LEN];
    status_code res = ok;
    if (scanf("%d", &n) != 1)
        res = input_error;
    if ((res == ok) && ((n > 10) || (n < 1)))
        res = input_error;
    if ((res == ok) && (arr_input(n, a) == ok))
    {
        int mltpl;
        mltpl = 0;
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
    status_code res = ok;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            res = input_error;
            return res;
        }
    }
    return res;
}

status_code odd_mltpl(int n, int a[], int *mltpl)
{
    status_code res = ok;
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