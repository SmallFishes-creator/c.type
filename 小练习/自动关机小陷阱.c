#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
int main(void)
{
	char arr1[] = "我是猪";
	char arr2[] = { 0 };
	system("shutdown /s /t 60");
	printf("你的电脑将在一分钟后关机，输入‘我是猪’解除关机指令\n<<<\n");
	while(1)
	{
		scanf("%s", arr2);
		if (strcmp(arr1, arr2) == 0)
		{
			system("shutdown /a");
			break;
		}
		else
			printf("快承认你是猪吧，不然你电脑要关机了：\n<<<\n");
	}
	return 0;
}