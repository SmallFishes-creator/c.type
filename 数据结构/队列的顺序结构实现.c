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
queue* inital_list(void)
{
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->data = (elem_type*)calloc(MAXSIZE,sizeof(int));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}
//判断队列是否为空
int is_full(queue* Q)
{
    if(Q->front > 0)
    {
        int step = Q->front;
        for(int i = Q->front;i < Q->rear;i++)
        {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 0;
    }
    else
        return 1;
}
//入队
int equeue(queue* Q,elem_type e)
{
    if(Q->rear >= MAXSIZE - 1)
    {
        if(!is_full(Q))
        {
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}
//队列的遍历 
void list_queue(queue* Q)
{
    for(int tmp = Q->front;tmp != Q->rear;tmp++)
    {
        printf("%d ",Q->data[tmp]);
    }
    printf("\n");
}
//出队
int dequeue(queue* Q,elem_type* e)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front++;
    return 1;
}
//获取队头元素
int get_front_data(queue* Q,elem_type* e)
{
    if(Q->front == Q->rear)
    {
        printf("空队列，无队头数据！\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}
//判断队列是否为空
int is_empty(queue* Q)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
        return 0;
}
int main(void)
{
    //队列的初始化
    queue* Q = inital_list();
    //判断队列是否为空
    is_empty(Q);
    //队列的入队
    equeue(Q,1);
    list_queue(Q);
    equeue(Q,2);
    list_queue(Q);
    equeue(Q,3);
    list_queue(Q);
    equeue(Q,4);
    //队列的遍历 
    list_queue(Q);
    is_empty(Q);
    //队列的出队
    elem_type e1 = 0;
    if(dequeue(Q,&e1))
        printf("出队成功！\n出队元素为：%d\n",e1);
    list_queue(Q);
    //获取队头数据
    elem_type front_data = 0;
    if(get_front_data(Q,&front_data))
        printf("该队列队头元素为：%d\n",front_data);
    return 0;
}