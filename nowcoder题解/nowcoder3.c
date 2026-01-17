#include <stdio.h>
#include <string.h>
int main(void)
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0; i < T;i++)
    {
        int n = 0;
        int m = 0;
        scanf("%d%d",&n,&m);
        if(n >= m - 1)
        {
            int arr[10000];
            memset(arr,0,sizeof(arr));
            for(int j = 0;j < n;j++)
            {
                int place = 0;
                scanf("%d",&place);
                arr[place - 1] = 1;
            }
            int flag = 0;
            for(int j = 0;j < n;j++)
            {
                int count = 0;
                if(arr[j] == 1)
                {
                    count++;
                }
                else
                {
                    count = 0;
                    continue;
                }
                if(count == m)
                {
                    flag = 1;
                    printf("YES\n");
                    break;
                }
            }
            if(flag == 0)
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
