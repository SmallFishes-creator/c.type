#include <stdio.h>
int my_strlen(char* value)
{
	if (*value != '\0')
	{
		value++;
		int len = 1 + my_strlen(value);
		return len;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	char num[100] = {0};
	printf("请输入字符串�?");
	scanf("%s", num);
	printf("%d\n", my_strlen(num));
	return 0;
}
