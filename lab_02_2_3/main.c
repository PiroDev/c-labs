#include <stdio.h>
#include <math.h>

#define MAX_LEN 10

typedef enum
{
    ok = 0,
    input_error = 1,
    items_error = 2
} status_code;

status_code arr_input(int, int[]);
void arr_output(int, const int[]);
int is_square(int);
int deletion(int, int[]);

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
        n -= deletion(n, a);
        if (n != 0)
        {
            arr_output(n, a);
            return res;
        }
        res = items_error;
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

int is_sqare(int a)
{
    if (a < 0)
    {
        return 0;
    }
    int sq = (int) sqrt((double) a);
    if ((sq * sq == a) || ((sq + 1) * (sq + 1) == a))
    {
        return 1;
    }
    return 0;
}

int deletion(int n, int a[])
{
    int cnt_all = 0; // количество полных квадратов (всего)
    int cnt = 0; // количество полных квадратов текущее
    int pos = 0; // счетчик элементов, которые находятся на своих местах
    while (pos < n - cnt_all)
    {
        if (is_sqare(a[pos + cnt]))
        {
            cnt_all++;
            cnt++;
        }
        else if (cnt > 0)
        {
            for (int j = pos; j < n - cnt; j++)
            {
                a[j] = a[j + cnt];
            }
            pos++;
            cnt = 0;
        }
        else
        {
            pos++;
        }
    }
    return cnt_all;
}
