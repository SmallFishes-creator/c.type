#include <stdio.h>
#include <string.h>
int my_strcmp(const char* str1,const char* str2)
{
	while(*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main(void)
{
	char* str1 = "abcde";
	char* str2 = "abcdf";
	int x = strcmp(str1,str2);
	int y = my_strcmp(str1,str2);
	//库函数 
	if(x > 0)
		printf(">");
	else if(x == 0)
		printf("==");
	else
		printf("<");
	//模拟函数 
	if(y > 0)
		printf(">");
	else if(y == 0)
		printf("==");
	else
		printf("<");
	return 0;
}