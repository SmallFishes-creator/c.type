#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcpy(char* destination,const char* source)
{
	//确保两指针均为非空指针 
	assert(destination && source);
	char* tmp = destination;
	while((*destination++ = *source++) != '\0');
	return tmp;
}
int main(void) 
{
	char source[] = "Hello world!\n";
	char destination[50];
	printf("strcpy库函数：%s\n",strcpy(destination,source));
	printf("my_strcpy库函数：%s\n",my_strcpy(destination,source));
	return 0;
}