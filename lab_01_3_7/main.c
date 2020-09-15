#include <stdio.h>
#include <math.h>

float curr_x(float x, int i, int sign);

int main()
{
	float x, eps;
	int rs = scanf("%f%f", &x, &eps);
	if ((rs == 2) && (fabs(x) < 1) && (eps > 0))
	{
		float s, x1;
		int i, sign;
		s = 0;
		x1 = x;
		i = 1;
		sign = 1;
		while (fabsf(curr_x(x1, i, sign)) > eps)
		{
			s += curr_x(x1, i, sign);
			i += 2;
			sign *= -1;
			x1 = x1 * x * x;
		}
		printf("%f", s);   
	}
	else
	{
		printf("Incorrect input!");
		return 1;
	}
}

float curr_x(float x, int i, int sign)
{
	if (i == 1)
		return x;
	else
		return sign * x / (float)i;
}
