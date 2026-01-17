#include <stdio.h>
#include <math.h>
int main(void)
{
    int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    double x = sqrt(pow(a - e,2) + pow(b - f,2));
    double y = sqrt(pow(a - c,2) + pow(b - d,2));
    double z = sqrt(pow(c - e,2) + pow(d - f,2));
    if(x == y & x == z)
        printf("YES");
    else
        printf("NO");
    return 0;
}