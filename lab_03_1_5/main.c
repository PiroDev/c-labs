#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code matrix_input(int, int, int[MAX_LEN][MAX_LEN]);
status_code matrix_process(int, int, int[MAX_LEN][MAX_LEN]);
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
        res = matrix_process(m, n, a);
        if (res == ok) 
            matrix_output(m, n, a);
        else
            printf("Error!");
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

status_code matrix_process(int m, int n, int a[MAX_LEN][MAX_LEN])
{
    int array[2][MAX_LEN * MAX_LEN];
    int ind = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int sum = digits_sum(a[i][j]);
            if (sum > 10)
            {
                array[0][ind] = a[i][j];
                array[1][ind] = i * n + j;
                ind++;
            }
        }
    if (ind == 0)
        return items_error;
    for (int times = 0; times < 3; times++)
    {
        int buf = array[0][0];
        for (int i = 0; i < ind - 1; i++)
        {
            array[0][i] = array[0][i + 1];
        }
        array[0][ind - 1] = buf;
    }
    for (int i = 0; i < ind; i++)
    {
        int pos_i = array[1][i] / n;
        int pos_j = array[1][i] % n;
        a[pos_i][pos_j] = array[0][i];
    }
    return ok;
}

int digits_sum(int a)
{
    int sum = 0;
    while (a * a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    if (sum < 0)
        sum *= -1;
    return sum;
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