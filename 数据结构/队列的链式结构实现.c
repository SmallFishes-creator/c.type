#include <stdio.h>
#include <stdlib.h>
typedef int elem_type;
typedef struct queue_node{
    elem_type data;
    struct queue_node* next;

}queue_node;
typedef struct{
    queue_node* front;
    queue_node* rear;
}queue;
//初始化队列
queue* inital_queue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    queue_node* node = (queue_node*)malloc(sizeof(queue_node));
    node->data = 0;
    node->next = node;
    q->front = node;
    q->rear = node;
    return q;
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
//入队
void equeue(queue* q,elem_type e)
{
    queue_node* p = (queue_node*)malloc(sizeof(queue_node));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
//遍历队列
int list_queue(queue* q)
{
    if(q->front == q->rear)
    {
        printf("空表\n");
        return 0;
    }
    queue_node* p = q->front->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}
//出队
int dequeue(queue* q)
{
    if(q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    queue_node* tmp = q->front->next;
    q->front->next = tmp->next;
    if(tmp->next == NULL)
    {
        q->rear = q->front;
    }
    free(tmp);
    return 1;
}
int free_queue(queue* q)
{
    if(q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    queue_node* tmp1 = q->front->next;
    queue_node* tmp2;
    while(tmp1 != q->rear)
    {
        tmp2 = tmp1->next;
        free(tmp1);
        tmp1 = tmp2;
    }
    free(tmp1);
    q->rear = q->front;
    return 1;
}
int main(void)
{
    //初始化队列
    queue* Q = inital_queue();
    //判断队列是否为空
    is_empty(Q);
    //入队
    equeue(Q,1);
    equeue(Q,2);
    equeue(Q,3);
    equeue(Q,4);
    equeue(Q,5);
    //遍历队列
    list_queue(Q);
    //出队
    dequeue(Q);
    list_queue(Q);
    dequeue(Q);
    list_queue(Q);
    //销毁队列
    free_queue(Q);
    return 0;
}