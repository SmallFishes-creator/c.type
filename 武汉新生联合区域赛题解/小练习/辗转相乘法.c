#include <stdio.h>
int gcd(int max, int min)
{
	int r = max % min;
	if (r == 0)
		return min;
	else
	{
		max = min;
		min = r;
		return gcd(max, min);
	}
}
int main(void)
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	if(m != 0 && n != 0)
	{
		int max = m > n ? m : n;
		int min = m > n ? n : m;
		printf("%d\n", gcd(max, min));
	}
	else
	{
		printf("error!\n");
	}
	return 0;
}