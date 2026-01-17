#include <stdio.h>
void part(char arr[101], int num, const char* name, int i, int j, int* res)
{
	while (arr[j] != '\n')
	{
		if (arr[j] == name[i])
		{
			if (i == num - 1)
			{
				(*res) += 1;
			}
			else
			{
				int x = i;
				int y = j;
				x++;
				y++;
				part(arr, num, name, x, y, res);
			}
		}
		j++;
	}
}
void find(char arr[101], const char* name, int num, int* res)
{
	int i = 0;
	int j = 0;
	part(arr, num, name, i, j, res);
}
int main(void)
{
	char arr[101] = { 0 };
	int count = 0;
	int i = -1;
	do
	{
		i++;
		scanf("%c", &arr[i]);
		count++;
	} while (arr[i] != '\n');
	const char* name[] = { "HUST","WHU","WHUT","HZAU","CCNU" };
	int num[5] = { 4,3,4,4,4 };
	int res[5] = { 0 };
	for (int j = 0; j < 5; j++)
	{
		find(arr, name[j], num[j], &res[j]);
	}
	int max = 0;
	for (int j = 1; j < 5; j++)
	{
		if (res[j] >= res[max])
		{
			max = j;
		}
	}
	printf("%s %d", name[max], res[max]);
	return 0;
}
