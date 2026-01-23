#include <stdio.h>
int main(void)
{
    //输入
    int n = 0,k = 0;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //寻找
    //找到原来质心的位置
    double inner = 0;
    double son = 0;
    double mother = 0;
    for(int i = 0;i < n;i++)
    {
        son += arr[i] * i;
        mother += arr[i];
    }
    inner = son / mother;
    //二进制枚举
    unsigned int choose = 1;
    for(int i = 0;i < n;i++)
    {
        choose *= 2;
    }
    choose -= 1;
    int flag = 0;
    for(int i = choose;i >= 0;i--)
    {
        int count = 0;
        flag = 0;
        int b = i;
        while(b != 0)
        {
            if(b & 1 == 1)
            {
                count++;
            }
            b = b >> 1;
        }
        if(count == k)
        {
            //计算质心位置
            double up = 0;
            double down = 0; 
            int tmp = i;
            for(int t = 0;t < n;t++)
            {
                if(tmp & 1 == 1)
                {
                    up += arr[t] * t;
                    down += arr[t];
                }
                tmp = tmp >> 1;
            }
            if(inner == up / down)
            {
                printf("Yes");
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    if(flag == 0)
        printf("No");
    return 0;
}