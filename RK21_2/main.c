#include <stdio.h>

#define MAX_LEN 20

typedef enum 
{
    ok = 0,
    input_error = 1
} status_code;

status_code matrix_input(int, int[MAX_LEN][MAX_LEN]);
int matrix_process(int, int[MAX_LEN][MAX_LEN]);

int main()
{
    int n;
    int a[MAX_LEN][MAX_LEN];
    status_code res = ok;
    if (scanf("%d", &n) != 1)
        res = input_error;
    if ((res == ok) && ((n > MAX_LEN) || (n < 1)))
        res = input_error;
    if ((res == ok) && (matrix_input(n, a) == ok))
    {
        int index = matrix_process(n, a);
        printf("%d", index);
        return res;
    }
    else
    {
        res = input_error;
    }
    printf("Error!");
    return res;
}


status_code matrix_input(int n, int a[MAX_LEN][MAX_LEN])
{
    status_code res = ok;
    for (int i = 0; i < n; i++)
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

int matrix_process(int n, int a[MAX_LEN][MAX_LEN])
{
    int res = -1;
    for (int index = 1 - n; index <= n - 1; index++)
    {
        int sum_top = 0;
        int sum_bottom = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i < j + index)
                    sum_top += a[i][j];
                if (i > j + index)
                    sum_bottom += a[i][j];
            }
        if (sum_top == sum_bottom)
        {
            res = index + n - 1;
            break;
        }
    }
    return res;
}