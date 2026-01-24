#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int age;
    char name[20];
};
//排序
int cmp_struct_by_name(const void* e1,const void* e2)
{
    return strcmp(((struct student*)e1)->name,((struct student*)e2)->name);
}
//遍历结构体
void list_struct(struct student* stu,int sz)
{
    for(int i = 0;i < sz;i++)
    {
        printf("第%d个学生的姓名为：%s\n",i + 1,stu[i].name);
        printf("第%d个学生的年龄为：%d\n",i + 1,stu[i].age);
        printf("---------\n");
    }
}
int main(void)
{
    struct student stu[] = {{18,"zhangsan"},{20,"lisi"},{15,"wangwu"}};
    int sz = sizeof(stu) / sizeof(stu[0]);
    //遍历结构体
    printf("排序前的结构体为：\n");
    list_struct(stu,sz);
    //排序
    qsort(stu,sz,sizeof(stu[0]),cmp_struct_by_name);
    //遍历结构体
    printf("排序后的结构体为：\n");
    list_struct(stu,sz);
    return 0;
}