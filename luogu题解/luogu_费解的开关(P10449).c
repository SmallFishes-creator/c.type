#include <stdio.h>
#include <string.h>
void change(int arr2[5][5],int x,int y)
{
	//偏移量的数组形式 
	int dx[5] = {0,-1,0,1,0};
	int dy[5] = {0,0,1,0,-1};
	for(int p = 0;p < 5;p++)
	{
		int X = x + dx[p];
		int Y = y + dy[p];
		if((X >= 0 && X <= 4) && (Y >= 0 && Y <= 4))
		{
			arr2[X][Y] ^= 1;
		}
	}
}
int main(void)
{
	int n = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		//输入数据 
		int arr[5][5] = {0};
		for(int j = 0;j < 5;j++)
		{
			int input = 0;
			scanf("%d",&input);
			for(int k = 0;k < 5;k++)
			{
				arr[j][4 - k] = input % 10;
				input /= 10;	
			}
		}
		//枚举第一行
		int state = 0;
		int min = 7;
		for(int j = 0;state != (1 << 5);j++)
		{
			int count = 0;
			int arr2[5][5] = {0};
			unsigned int num = 5 * 5 * sizeof(int);
			memcpy(arr2,arr,num);
			//确定第一行的灯的状态
			for(int k = 0;k < 5;k++)
			{
				if(state & (1 << k))
				{
					change(arr2,0,4 - k);
					count++;
				}
			}
			//确定其他所有行的灯的状态
			for(int a = 1;a < 5;a++)
			{
				for(int b = 0;b < 5;b++)
				{
					if(arr2[a - 1][b] == 0)
					{
						change(arr2,a,b);
						count++;
					}
				}
			}
			//检查最后一行灯的状态 
			int flag = 1;
			for(int k = 0;k < 5;k++)
			{
				if(arr2[4][k] == 0)
					flag = 0;
			}
			if(flag && min > count)
			{
				min = count;
			}
			state++;
		}
		if(min == 7)
			printf("%d\n",-1);
		else
			printf("%d\n",min);
	}
	return 0;
}