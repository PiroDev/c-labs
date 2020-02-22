#include <stdio.h>

int div(long a, long b);

int main()
{
	long a, d;
	int rs;
	rs = scanf("%ld%ld", &a, &d);
	if ((rs == 2) && (a > 0) && (d > 0))
	{	
		long q, r;
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
		printf("%ld %ld", q, r);
		return 0;
	}
	else
	{
		printf("Incorrect input!");
		return 1;
	}
}

int div(long a, long b)
{
	long n = 0;
	while (a >= b)
	{
		a -= b;
		n++;
	}
	return n;
}
