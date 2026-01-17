#include <stdio.h>
int main(void)
{
	int way = 0;
	int n = 0;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&arr[i]);
	} 
	for(int j = 0;j < 2;j++)
	{
		int flag = 1;
		int boost1 = j;
		int boost2 = arr[0] - boost1;
		if(boost2 == 0 || boost2 == 1)
		{
			for(int i = 1;i <= n - 2;i++)
			{
				int tmp = arr[i] - boost1 - boost2;
				if(tmp != 0 && tmp != 1)
				{
					flag = 0;
					break;
				}
				boost1 = boost2;
				boost2 = tmp;
			}
			if(flag && boost2 + boost1 == arr[n - 1])
				way++;
		}
	}
	printf("%d",way);
	return 0;
}
