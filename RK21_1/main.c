#include <stdio.h>

#define MAX_LEN 20

typedef enum
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code arr_input(int, int[]);
void arr_process(int*, int[], int);
void arr_output(int, int[]);

int main()
{
    int n;
    int num;
    int a[MAX_LEN];
    status_code res = ok;
    if (scanf("%d", &n) != 1)
        res = input_error;
    if ((res == ok) && ((n > MAX_LEN) || (n < 1)))
        res = input_error;
    else if (arr_input(n, a) != ok)
        res = input_error;
    if ((res == ok) && (scanf("%d", &num) != 1))
        res = input_error;
    else if (num == 0)
        res = items_error;
    if (res == ok)
    {
        arr_process(&n, a, num);
        arr_output(n, a);
        return res;
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
            break;
        }
    }
    return res;
}

void arr_process(int *n, int a[], int num)
{
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        if (a[i] % num == 0)
        {
            count++;
            if (count % 2 == 0)
            {
                for (int j = i; j < *n - 1; j++)
                    a[j] = a[j + 1];
                *n -= 1;
            }
        }
    }
}

void arr_output(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}