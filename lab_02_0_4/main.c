#include <stdio.h>

#define MAX_LEN 10

int arr_input(int, int[]);
void arr_output(int, int[]);
void bubble_sort(int, int[]);
void swap(int*, int*);

int main()
{
    int n;
    int res = scanf("%d", &n);
    int a[MAX_LEN];
    if ((res) && (n <= 10) && (n >= 1) && (arr_input(n, a)))
    {
        bubble_sort(n, a);
        arr_output(n, a);
        return 0;
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

void bubble_sort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(&a[j], &a[i]);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}
