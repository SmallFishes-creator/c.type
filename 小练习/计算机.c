#include <stdio.h>
void menu(void)
{
	printf("***************************\n");
	printf("********** 1.Add **********\n");
	printf("********** 2.Sub **********\n");
	printf("********** 3.Mul **********\n");
	printf("********** 4.Div **********\n");
	printf("********** 0.Esc **********\n");
	printf("***************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main(void)
{
	int flag = 0;
	int x = 0;
	int y = 0;
	while (1)
	{
		menu();
		printf("请输入将使用的功能：\n>>>");
		scanf("%d", &flag);
		if (!flag)
			break;
		printf("请输入两个整数：\n>>>");
		scanf("%d%d", &x, &y);
		int (*p[4])(int, int) = { Add,Sub,Mul,Div };
		int tmp = (*p[flag - 1])(x, y);
		printf("结果为：%d\n", tmp);
	}
	printf("退出计算机！\n");
	return 0;
}