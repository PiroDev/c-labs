#include <stdio.h>

int main()
{
	int s, n; scanf("%d", &s);
	if (s < 45)
		n = 0;
	else
		n = s / 25;
	printf("%d", n);
	return 0;
}
