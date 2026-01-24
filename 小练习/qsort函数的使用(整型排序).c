#include <stdio.h>
#include <stdlib.h>
//遍历数组
void list_arr(int* arr,int sz)
{
    printf("排序前的数组为：\n>>>");
    for(int i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//比较函数
int cmp_int(const void* e1,const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    list_arr(arr,sz);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    list_arr(arr,sz);
    return 0;
}