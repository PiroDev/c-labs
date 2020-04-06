#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code matrix_input(int, int, int[MAX_LEN][MAX_LEN]);
void matrix_process(int*, int*, int[MAX_LEN][MAX_LEN]);
void array_copy(int, int[], int[]);
int digits_sum(int);
void matrix_output(int, int, int[MAX_LEN][MAX_LEN]);

int main()
{
    int m, n;
    int a[MAX_LEN][MAX_LEN];
    status_code res = ok;
    if (scanf("%d%d", &m, &n) != 2)
        res = input_error;
    if ((res == ok) && ((m > 10) || (m < 1) || (n > 10) || (n < 1)))
        res = input_error;
    if ((res == ok) && (matrix_input(m, n, a) == ok))
    {
        matrix_process(&m, &n, a);
        if ((m == 0) || (n == 0))
            res = items_error;
        else
            matrix_output(m, n, a);
        return res;
    }
    else
    {
        res = input_error;
    }
    printf("Error!");
    return res;
}

status_code matrix_input(int m, int n, int a[MAX_LEN][MAX_LEN])
{
    status_code res = ok;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                res = input_error;
                return res;
            }
        }
    }
    return res;
}

int digits_sum(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    if (sum < 0)
        sum *= -1;
    return sum;
}

void matrix_process(int *m, int *n, int a[MAX_LEN][MAX_LEN])
{
    int pos_i = 0;
    int pos_j = 0;
    int min_sum = digits_sum(a[0][0]);
    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            if (digits_sum(a[i][j]) < min_sum)
            {
                pos_i = i;
                pos_j = j;
                min_sum = digits_sum(a[i][j]);
            }
    for (int i = 0; i < *m; i++)
    {
        for (int j = pos_j; j < *n - 1; j++)
            a[i][j] = a[i][j + 1];
        a[i][*n - 1] = 0;
    }
    *n -= 1;
    for (int i = pos_i; i < *m - 1; i++)
    {
        array_copy(*n, a[i + 1], a[i]);
    }
    *m -= 1;
}

void array_copy(int n, int from[], int to[])
{
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

void matrix_output(int m, int n, int a[MAX_LEN][MAX_LEN])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}