#include <stdio.h>
#include <math.h>
int exchange(int* arr,int n)
{
    int flag = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            double tmp = sqrt(arr[i] * arr[j]);
            if(tmp - (int)tmp == 0 && arr[i] > arr[j] )
            {
                int x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
                flag = 1;
            }
        }
    }
    return flag;
}
int main(void)
{
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(exchange(arr,n))
    {
        ;
    }
    int flag = 1;
    for(int i = 1;i < n;i++)
    {
        if(arr[i - 1] > arr[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
