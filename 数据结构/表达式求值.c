// 表达式求值：82/2+56*-
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100
typedef enum {
    ADD,SUB,MUL,DIV,MOD,EOS,NUM
}content_type;
typedef int elem_type;
typedef struct Stack{
    elem_type* data;
    int top;
}stack;
stack* inital_stack(void)
{
    stack* p = (stack*)malloc(sizeof(stack));
    p->data = (elem_type*)calloc(MAXSIZE,sizeof(int));
    p->top = -1;
    return p;
}
int push(stack* L,elem_type e)
{
    if(L->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }
    L->top++;
    L->data[L->top] = e;
    return 1;
}
int pop(stack* L,elem_type* e)
{
    if(L->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = L->data[L->top];
    L->top--;
    return 1;
}
content_type get_token(char* symbol,const char* arr,int* index)
{
    *symbol = arr[*index];
    *index = *index + 1;
    switch(*symbol)
    {
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}
void eval(const char* arr,stack* L,elem_type* result)
{
    assert(arr && L);
    elem_type pos1,pos2;
    char symbol;
    int index = 0;
    content_type token = get_token(&symbol,arr,&index);
    while(token != EOS)
    {
        if(token == NUM)
        {
            push(L,symbol - '0');
        }
        else
        {
            pop(L,&pos1);
            pop(L,&pos2);
            switch(token)
            {
            case ADD:
                push(L,pos2 + pos1);
                break;
            case SUB:
                push(L,pos2 - pos1);
                break;
            case MUL:
                push(L,pos2 * pos1);
                break;
            case DIV:
                push(L,pos2 / pos1);
                break;
            case MOD:
                push(L,pos2 % pos1);
                break;
            }
        }
        token = get_token(&symbol,arr,&index);
    }
    pop(L,result);
}
int main(void)
{
    stack* list = inital_stack();
    char* arr = "82/2+56*-";
    elem_type result;
    eval(arr,list,&result);
    printf("%d\n",result);
    return 0;
}