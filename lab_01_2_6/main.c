#include <stdio.h>
#include <math.h>

float vector(float x2, float x1,
		float y3, float y2,
			float x3, float y1);

int main()
{
	int rs;
	float x1, x2, x3, xA, y1, y2, y3, yA;
	rs = scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &xA, &yA);
	if (rs == 8)
	{
		float a, b, c;
		a = vector(x1, xA, y2, y1, x2, yA);
		b = vector(x2, xA, y3, y2, x3, yA);
		c = vector(x3, xA, y1, y3, x1, yA);
		if (((a > 0) && (b > 0) && (c > 0)) || ((a < 0) && (b < 0) && (c < 0)))
		{
			printf("%d", 0);
		}
		else if ((fabsf(a) < 1e-7) || (fabsf(b) < 1e-7) || (fabsf(c) < 1e-7))
		{
			printf("%d", 1);
		}
		else
			printf("%d", 2);
		return 0;
	}
	else
	{
		printf("Incorrect input!");
		return 1;
	}
}

float vector(float x2, float x1,
		float y3, float y2,
			float x3, float y1)

{
	return (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
}
