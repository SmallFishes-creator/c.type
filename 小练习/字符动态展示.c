#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main(void)
{
	char arr1[] = "Hello world!!!";
	char arr2[] = "**************";
	int sz = sizeof(arr1) / sizeof(arr1[0]) - 2;
	int left = 0;
	int right = sz;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}
}
