#include <stdio.h>
int main(void)
{
	int n = 0;
	printf("请输入一个正整数n：");
	scanf("%d", &n);
	int num = 1;
	int value = 0;
	for (int i = 1;i <= n;i++)
	{
		num *= i;
		value += num;
	}
	printf("%d\n", value);
	return 0;
}
