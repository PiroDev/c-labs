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
int is_armstr(int);
int cnt_armstr(int, const int[], int[]);
int cnt_digits(int);


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
        int armstr[MAX_LEN];
        int cnt = cnt_armstr(n, a, armstr);
        if (cnt != 0)
        {
            arr_output(cnt, armstr);
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

int is_armstr(int a)
{
    if (a < 1)
    {
        return 0;
    }
    int n = cnt_digits(a);
    int sum = 0;
    int buf = a;
    while (a > 0)
    {
        sum += (int) pow((double) (a % 10), (double) n);
        a /= 10;
    }
    if (sum == buf)
    {
        return 1;
    }
    return 0;
}

int cnt_armstr(int n, const int a[], int new[])
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_armstr(a[i]))
        {
            new[j] = a[i];
            j++;
        }
    }
    return j;
}

int cnt_digits(int a)
{
    int n = 0;
    while (a > 0)
    {
        a /= 10;
        n++;
    }
    return n;
}
