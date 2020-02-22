#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265

int main()
{
	float a, b, alpha;
	float h, s;
	scanf("%f%f%f", &a, &b, &alpha);
	h = fabsf(a - b)/2*tan(M_PI/180.0*alpha);
	s = (a + b)/2*h;
	printf("%f", s);
	return 0;
}
