#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int elem_type;
typedef enum content{
    EOS,LEFT_PAR,RIGHT_PAR,ADD,SUB,MUL,DIV,MOD,NUM
}content_type;
typedef struct Stack{
    elem_type* data;
    int top;
}stack;
stack* inital_stack()
{
    stack* p = (stack*)malloc(sizeof(stack));
    p->data = (elem_type*)calloc(MAXSIZE,sizeof(elem_type));
    p->top = -1;
    return p;
}
int push(stack* s,elem_type e)
{
    if(s->top >= MAXSIZE)
    {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}
int pop(stack* s,elem_type* e)
{
    if(s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}
content_type get_token(const char* arr,char* symbol,int* index)
{
    *symbol = arr[*index];
    if(*symbol != '\0')
        *index = *index + 1;
    switch(*symbol)
    {
    case '(':
        return LEFT_PAR;
    case ')':
        return RIGHT_PAR;
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
void print_stack(content_type tmp)
{
    switch(tmp)
    {
    case ADD:
        printf("+");
        break;
    case SUB:
        printf("-");
        break;
    case MUL:
        printf("*");
        break;
    case DIV:
        printf("/");
        break;
    case MOD:
        printf("%%");
        break;
    }
}
void eval(const char* arr,stack* s)
{
    int in_stack[] = {0,0,19,12,12,13,13,13,0};
    int out_stack[] = {0,20,19,12,12,13,13,13,0};
    char symbol;
    int index = 0;
    content_type token = get_token(arr,&symbol,&index);
    while(token != EOS)
    { 
        if(token == NUM)
        {
            printf("%c",symbol);
        }
        else if(token == RIGHT_PAR)
        {
            elem_type tmp = RIGHT_PAR;
            while(s->data[s->top] != LEFT_PAR)
            {
                pop(s,&tmp);
                print_stack(tmp);
            }
            pop(s,&tmp);
        }
        else
        {
            if(in_stack[s->data[s->top]] < out_stack[token])
            {
                push(s,token);
            }
            else
            {
                elem_type tmp;
                pop(s,&tmp);
                print_stack(tmp);
                push(s,token);
            }
        }
        token = get_token(arr,&symbol,&index);
    }
    while(s->top != 0)
    {
        elem_type tmp;
        pop(s,&tmp);
        print_stack(tmp);
    }
}
int main(void)
{
    //xij-/y*
    char* arr = "x/(i-j)*y";
    printf("原表达式为：%s\n",arr);
    stack* s = inital_stack();
    push(s,0);
    printf("现表达式为：");
    eval(arr,s);
    return 0;
}