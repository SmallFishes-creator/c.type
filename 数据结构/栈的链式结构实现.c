#include <stdio.h>
#include <stdlib.h>
typedef int elem_type;
typedef struct Stack{
    elem_type data;
    struct Stack* next;
}stack;
//栈的初始化
stack* inital_stack(void)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->data = 0;
    s->next = NULL;
    return s;
}
//判断栈是否为空
int is_empty(stack* s)
{
    if(s->next == NULL)
    {
        printf("空的\n");
        return 1;
    }
    return 0;
}
//进栈
void push(stack* s,elem_type e)
{
    stack* p = (stack*)malloc(sizeof(stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
}
//遍历栈
void list_stack(stack* s)
{
    stack* p = s->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
//出栈
int pop(stack* s)
{
    if(s->next == NULL)
    {
        printf("空的\n");
        return 0;
    }
    stack* p = s->next;
    s->next = p->next;
    free(p);
    return 1;
}
//确定栈顶元素
int get_top(stack* s,elem_type* e)
{
    if(s->next ==NULL)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}
int main(void)
{
    //栈的初始化
    stack* s = inital_stack();
    //判断栈是否为空
    is_empty(s);
    //进栈(头插法)
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    //遍历栈
    list_stack(s);
    //出栈
    pop(s);
    list_stack(s);
    //确定栈顶元素
    elem_type top_elem = 0;
    get_top(s,&top_elem);
    printf("栈顶元素为：%d\n",top_elem);
    return 0;
}