#include <stdio.h>
#include <string.h>
int main(void)
{
	int T = 0;
	scanf("%d",&T);
	for(int i = 0;i < T;i++)
	{
		int n = 0,m = 0,k = 0;
		scanf("%d%d%d",&n,&m,&k);
		if(k == 0)
		{
			int arr[n][m];
			memset(arr,0,sizeof(arr));
			printf("Yes\n");
			int num = n * m;
			for(int x = 0;x < n;x++)
			{
				for(int y = 0;y < m;y++)
				{
					arr[x][y] = num;
					num--;
				}
			}
			for(int x = 0;x < n;x++)
			{
				for(int y = 0;y < m;y++)
				{
					printf("%d ",arr[x][y]);
					
				}
				printf("\n");
			}
		}
		else if(n < 3 || m < 3 || (k > ((n - 1) / 2) * ((m - 1) / 2)))
			printf("No\n");
		else
		{
			printf("Yes\n");
			int arr[n][m];
			int num = m * n;
			int point = 0;
			memset(arr,0,sizeof(arr));
			for(int x = 1;x < n - 1;x += 2)
			{
				int flag = 0;
				for(int y = 1;y < m - 1;y += 2)
				{
					arr[x][y] = num;
					num--;
					point++;
					if(point == k)
					{
						flag = 1;
						break;
					}
				}
				if(flag)
					break;
			}
			for(int x = 0;x < n;x++)
			{
				for(int y = 0;y < m;y++)
				{
					if(arr[x][y] == 0)
					{
						arr[x][y] = num;
						num--;
					}
				}
			}
			for(int x = 0;x < n;x++)
			{
				for(int y = 0;y < m;y++)
				{
					printf("%d ",arr[x][y]);
					
				}
				printf("\n");
			}
		}
	}
	return 0;
}
