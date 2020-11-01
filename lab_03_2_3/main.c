#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1
} status_code;

status_code matrix_input(int, int, int[MAX_LEN][MAX_LEN]);
void matrix_process(int, int, int[MAX_LEN][MAX_LEN]);
void matrix_mult(int, int, int[MAX_LEN][MAX_LEN], int[]);
void matrix_sort(int, int, int[MAX_LEN][MAX_LEN], int[]);
void arrays_swap(int, int[], int[]);
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
        matrix_process(m, n, a);
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

void matrix_process(int m, int n, int a[MAX_LEN][MAX_LEN])
{
    int param[MAX_LEN];
    matrix_mult(m, n, a, param);
    matrix_sort(m, n, a, param);
}

void matrix_mult(int m, int n, int a[MAX_LEN][MAX_LEN], int param[])
{
    for (int i = 0; i < m; i++)
    {
        int mult = 1;
        for (int j = 0; j < n; j++)
            mult *= a[i][j];
        param[i] = mult;
    }
}

void matrix_sort(int m, int n, int a[MAX_LEN][MAX_LEN], int param[])
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (param[j] < param[i])
            {
                arrays_swap(n, a[j], a[i]);
                int buf = param[i];
                param[i] = param[j];
                param[j] = buf;
            }
        }
    }
}

void arrays_swap(int n, int from[], int to[])
{
    for (int i = 0; i < n; i++)
    {
        int buf = to[i];
        to[i] = from[i];
        from[i] = buf;
    }
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