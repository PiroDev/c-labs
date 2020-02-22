#include <stdio.h>

int main()
{
	float r1, r2, r3, r;
	scanf("%f %f %f", &r1, &r2, &r3);
	r = (r3 * (r2 + r1) + r1 + r2) / (r1 * r2 * r3);
	printf("%f", r);
	return 0;
}
