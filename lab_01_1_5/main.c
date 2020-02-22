#include <stdio.h>

int div(int a, int b);

int main()
{
	int res, a, d;
	if (((res = scanf("%d %d", &a, &d)) == 2) && (res != EOF) && (a >= 0) && (d > 0))
	{	
		int q, r;
		if (a >= d)
		{
			q = div(a, d);
			r = a - q * d;
		}
		else
		{
			q = 0;
			r = a;
		}
		printf("%d %d", q, r);
		return 0;
	}
	else
	{
		printf("Incorrect input!");
		return 1;
	}
}

int div(int a, int b)
{
	int n = 0;
	while (a >= b)
	{
		a -= b;
		n++;
	}
	return n;
}
