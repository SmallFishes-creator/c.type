#include <stdio.h>
int main(void)
{
    int n = 0;
    scanf("%d",&n);
    int inital[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&inital[i]);
    }
    int index[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&index[i]);
    }
    int change[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&change[i]);
    }
    for(int i = 0;i < n;i++)
    {
        int now_index = index[i] - 1;
        int need = inital[now_index];
        int now_change = 0;
        int count = 0;
        while(need != now_change)
        {
            now_change = change[now_index];
            for(int j = 0;j < n;j++)
            {
                if(inital[j] == now_change)
                {
                    now_change = change[j];
                    count++;
                }
            }
        }
        printf("%d ",count);
    }
    return 0;
}