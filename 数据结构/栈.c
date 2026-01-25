#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int elem_type;
typedef struct {
    elem_type *data;
    int top;
}stack;
//初始化栈
int inital_stack(stack* s)
{
    if(s == NULL)
        return 0;
    s->top = -1;
    return 1;
}
//初始化栈（动态内存分配）
stack* inital_stack_dynamic()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->data = (elem_type*)malloc(sizeof(elem_type) * MAXSIZE);
    s->top = -1;
    return s;
}
//判断栈是否为空
int is_empty(stack* s)
{
    if(s->top == -1)
    {
        printf("空的\n");
        return 1;
    }
    else
        return 0;
}
//进栈
int push(stack* s,elem_type e)
{
    if(s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}
//遍历栈
void list_stack(stack* s)
{
    for(int i = 0;i <= s->top;i++)
    {
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
//出栈
int pop(stack* s)
{
    if(s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    else
    {
        s->top--;
        return 1;
    }
}
int get_top(stack* s,elem_type* e)
{
    if(s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}
int main(void)
{
    //初始化栈
    stack* s = inital_stack_dynamic();
    // inital_stack(s);
    //判断栈是否为空
    is_empty(s);
    //进栈
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    //遍历栈
    list_stack(s);
    is_empty(s);
    //获取栈顶元素
    elem_type e;
    get_top(s,&e);
    printf("栈顶元素为:%d\n",e);
    //出栈
    for(int i = 0;i < 5;i++)
        pop(s);
    return 0;
}