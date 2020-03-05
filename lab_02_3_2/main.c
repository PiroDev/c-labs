#include <stdio.h>
#include <math.h>

#define MAX_LEN 10

int arr_input(int, int[]);
void arr_output(int, int[]);
int is_armstr(int);
int cnt_armstr(int, int[], int[]);
int cnt_digits(int);


int main()
{
    int n;
    int res = scanf("%d", &n);
    int a[MAX_LEN];
    if ((res) && (n <= 10) && (n >= 1) && (arr_input(n, a)))
    {
        int armstr[MAX_LEN];
        int cnt = cnt_armstr(n, a, armstr);
        if (cnt)
        {
            arr_output(cnt, armstr);
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

int cnt_armstr(int n, int a[], int new[])
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
