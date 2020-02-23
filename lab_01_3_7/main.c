#include <stdio.h>
#include <math.h>

float curr_x(float x, int i, int sign);
float abs_inaccuracy(float s, float f);
float rel_inaccuracy(float s, float f);


int main()
{
	float x, eps;
	int rs = scanf("%f%f", &x, &eps);
	if ((rs == 2) && (fabs(x) <= 1) && (eps > 0))
	{
		float s, f, x1;
		int i, sign;
		f = atan(x);
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
		printf("%.6f %.6f %.6f %.6f", s, f, abs_inaccuracy(s, f), rel_inaccuracy(s, f));   
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

float abs_inaccuracy(float s, float f)
{
	return fabsf(f - s);
}

float rel_inaccuracy(float s, float f)
{
	return fabsf((f - s) / f);
}
