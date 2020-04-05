#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1
} status_code;

status_code matrix_input(int, int, int[MAX_LEN][MAX_LEN]);
void matrix_process(int, int, int[MAX_LEN][MAX_LEN], int[]);
void array_output(int, int[]);

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
        int array[MAX_LEN];
        matrix_process(m, n, a, array);
        array_output(n, array);
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

void matrix_process(int m, int n, int a[MAX_LEN][MAX_LEN], int array[])
{
    for (int j = 0; j < n; j++)
    {
        int i = 1;
        while ((i < m) && (a[i][j] < a[i - 1][j]))
        {
            i++;
        }
        if ((i == m) && (i != 0))
            array[j] = 1;
        else
            array[j] = 0;
    }
}

void array_output(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}