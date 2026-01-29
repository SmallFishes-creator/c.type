#include <stdio.h>
enum weekend
{
    Mon = 1,Tes,Wed,Thu,Fri,Sat,Sun
};
int main(void)
{
    enum weekend a;
    a = Mon;
    enum weekend b;
    b = Tes;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    return 0;
}