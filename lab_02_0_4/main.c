#include <stdio.h>

#define MAX_LEN 10

typedef enum
{
    ok = 0,
    input_error = 1
} status_code;

status_code arr_input(int, int[]);
void arr_output(int, const int[]);
void bubble_sort(int, int[]);
void swap(int*, int*);

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
        bubble_sort(n, a);
        arr_output(n, a);
        return res;
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
            break;
        }
    }
    return res;
}

void arr_output(int n, const int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void bubble_sort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] <= a[i])
            {
                swap(&a[j], &a[i]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}
