#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcat(char* destination,const char* source)
{
	//断言两指针是否为空指针 
	assert(destination && source);
	char* tmp = destination;
	//先调整指针destination的位置
	while(*destination != '\0')
		destination++;
	while((*destination++ = *source++) != '\0');
	return tmp;
}
int main(void)
{
	char destination1[50] = "Hello ";
	char* source1 = "world!\n";
	char destination2[50] = "Hello ";
	char* source2 = "world!\n";
	printf("%s",strcat(destination1,source1));
	printf("%s",my_strcat(destination2,source2));
	return 0;
}