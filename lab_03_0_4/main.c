#include <stdio.h>

#define MAX_LEN 10

typedef enum 
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code matrix_input(int, int, int[MAX_LEN][MAX_LEN]);
status_code matrix_process(int, int[MAX_LEN][MAX_LEN], int*);

int main()
{
    int m, n;
    int a[MAX_LEN][MAX_LEN];
    status_code res = ok;
    if (scanf("%d%d", &m, &n) != 2)
        res = input_error;
    if ((res == ok) && ((m != n) || (m > 10) || (m < 1) || (n > 10) || (n < 1)))
        res = input_error;
    if ((res == ok) && (matrix_input(m, n, a) == ok))
    {
        int min;
        res = matrix_process(m, a, &min);
        if (res == ok)
            printf("%d", min);
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

status_code matrix_process(int m, int a[MAX_LEN][MAX_LEN], int *min)
{
    status_code res = ok;
    *min = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if ((i > j) && (a[i][j] % 2 != 0))
            {
                if (*min != 0)
                {
                    if (a[i][j] < *min)
                        *min = a[i][j];
                }
                else
                    *min = a[i][j];
            }
    if (*min == 0)
        res = items_error;
    return res;
}