#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int elem_type;
typedef struct Queue{
    elem_type *data;
    int front;
    int rear;
}queue;
//队列的初始化
queue* inital_queue(void)
{
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->front = 0;
    Q->rear = 0;
    Q->data = (elem_type*)calloc(MAXSIZE,sizeof(elem_type));
    return Q;
}
//入队
int equeue(queue* Q,elem_type e)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}
//出队
int dequeue(queue* Q,elem_type* e)
{
    if(Q->front == Q->rear)
    {
        printf("空表\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}
//队列的遍历
void list_queue(queue* Q)
{
    int tmp = Q->front;
    while(tmp % MAXSIZE != Q->rear)
    {
        printf("%d ",Q->data[tmp]);
        tmp = (tmp + 1) % MAXSIZE;
    }
    printf("\n");
}
void free_queue(queue* Q)
{
    if(Q != NULL)
    {
        if(Q->data != NULL)
        {
            free(Q->data);
        }
        free(Q);
    }
}
int main(void)
{
    //队列的初始化
    queue* Q = inital_queue();
    //入队
    equeue(Q,1);
    equeue(Q,2);
    equeue(Q,3);
    equeue(Q,4);
    //队列的遍历
    list_queue(Q);
    //出队
    elem_type e = 0;
    if(dequeue(Q,&e))
        printf("出队成功！\n出队元素为：%d\n",e);
    list_queue(Q);
    //队列销毁函数
    free_queue(Q);
    return 0;
}