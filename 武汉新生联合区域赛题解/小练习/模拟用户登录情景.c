#include <stdio.h>
#include <string.h>
int main(void)
{
	char password[] = "abcde";
	char arr[10] = { 0 };
	int i;
	for (i = 0;i < 3;i++)
	{
		printf("请输入您的登录密码：\n<<<\n");
		scanf("%s", arr);
		if (strcmp(arr, password) == 0)
		{
			printf("输入正确，登录成功！\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
			if (i == 2)
			{
				printf("连续三次输入错误，已锁定！");
			}
		}
	}
	return 0;
}
