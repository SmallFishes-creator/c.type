#include <stdio.h>
int main(void)
{
	for (int i = 0;i < 3;i++)
	{
		int find = 0;
		printf("请输入你要查找的数：");
		scanf("%d", &find);
		int arr[10] = { 0,11,23,37,46,51,62,75,88,95 };
		int left = 0;
		int right = sizeof(arr) / sizeof(arr[0]) - 1;
		printf("%d\n", right);
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (find > arr[mid])
			{
				left = mid + 1;
			}
			else if (find < arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				printf("找到了，这个数的下标是%d\n", mid);
				break;
			}
			if (left > right)
			{
				printf("未找到此数字\n");
			}
		}
	}
	return 0;
}
