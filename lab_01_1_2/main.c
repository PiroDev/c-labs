#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, alpha;
	float h, s;
	scanf("%f%f%f", &a, &b, &alpha);
	h = fabsf(a - b) / 2 * tan(M_PI / 180.0 * alpha);
	s = (a + b) / 2 * h;
	printf("%f", s);
	return 0;
}
