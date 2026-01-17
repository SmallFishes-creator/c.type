#include <stdio.h>
int main(void)
{
    int n = 0;
    scanf("%d",&n);
    getchar();
    int arr[n][4];
    int record[n];
    //初始化
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            arr[i][j] = 0;
        }
        record[i] = 0;
    }
    //获取数字
    for(int i = 0;i < n;i++)
    {
        int s1 = getchar() - 1;
        getchar();
        int s2 = getchar() -'A';
        getchar();
        if(arr[s1][s2] == 0)
            arr[s1][s2] = i + 1;
    }
    //数对数
    //记录
    int count = 0;
    for(int i = 0;i < n;i++)
    {
        int total = 0;
        for(int j = 0;j < 4;j++)
        {
            if(arr[i][j] != 0)
            {
                total++;
            }
        }
        if(total > 1 && total < 4)
        {
            count++;
            record[i] = 2;
        }
        else if(total == 4)
        {
            count += 2;
            record[i] = 4;
        }
    }
    //打印结果
    printf("%d\n",count);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;record[i] && j < 4;j++)
        {
            if(arr[i][j] != 0)
            {
                printf("%d",arr[i][j]);
                record[i]--;
                if(record[i] == 3 || record[i] == 1)
                    printf(" ");
                if(record[i] == 2 || record[i] == 0)
                    printf("\n");
            }
        }
    }
    return 0;
}
