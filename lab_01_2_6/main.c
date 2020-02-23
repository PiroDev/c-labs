#include <stdio.h>
#include <math.h>

float vector(float x2, float x1,
float y3, float y2, float x3, float y1);

int is_line(float x1, float y1,
float x2, float y2, float x3, float y3);

int main()
{
	int rs;
	float x1, x2, x3, xa, y1, y2, y3, ya;
	rs = scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xa, &ya);
	if ((rs == 8) && !(is_line(x1, y1, x2, y2, x3, y3)))
	{
		
		float a, b, c;
		a = vector(x1, xa, y2, y1, x2, ya);
		b = vector(x2, xa, y3, y2, x3, ya);
		c = vector(x3, xa, y1, y3, x1, ya);
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
float y3, float y2, float x3, float y1)
{
	return (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
}

int is_line(float x1, float y1,
float x2, float y2, float x3, float y3)
{
	return (fabsf((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) < 1e-7);
}
