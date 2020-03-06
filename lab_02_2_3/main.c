#include <stdio.h>
#include <math.h>

#define MAX_LEN 10

int arr_input(int, int[]);
void arr_output(int, int[]);
int is_square(int);
int deletion(int, int[]);

int main()
{
    int n;
    int res = scanf("%d", &n);
    int a[MAX_LEN];
    if ((res) && (n <= 10) && (n >= 1) && (arr_input(n, a)))
    {
        n -= deletion(n, a);
        if (n != 0)
        {
            arr_output(n, a);
            return 0;
        }
    }
    printf("Incorrect input!");
    return 1;
}

int arr_input(int n, int a[])
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = scanf("%d", &a[i]);
        if (res != 1)
        {
            return 0;
        }
    }
    return 1;
}

void arr_output(int n, int a[])
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
