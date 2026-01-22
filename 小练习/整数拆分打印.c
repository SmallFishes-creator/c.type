#include <stdio.h>
//利用函数的打印一个整数的每位数
void print(unsigned int num)
{
	if (num > 9)
	{
		print(num / 10);
	}
	printf("%d\n", num % 10);
}
int main()
{
	unsigned int num = 0;
	scanf("%u", &num);
	print(num);
	return 0;
}