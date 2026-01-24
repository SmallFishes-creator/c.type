#include <stdio.h>
#include <stdlib.h>
typedef int elem_type;
typedef struct node{
    elem_type data;
    struct node* next;
    struct node* prev;
}Node;
//双向链表初始化
Node* inital_list(void)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    printf("双向链表初始化成功!\n");
    return head;
}
//头插法
void insert_head(Node* L,elem_type e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next != NULL)
        L->next->prev = p;
    L->next = p;
}
//查找尾节点
Node* find_tail(Node* L)
{
    Node* p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
//尾插法
Node* insert_tail(Node* tail,elem_type e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    p->prev = tail;
    tail->next = p;
    return p;
}
//遍历双向链表
void list_node(Node* L)
{
    printf("双向链表的数据为：\n>>>");
    Node* p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
//在指定位置插入数据
int insert_node(Node* L,int pop,elem_type e)
{
    if(pop < 1)
        return 0;
    //找到指定位置的前驱节点
    Node* q = L;
    for(int i = 0;i < pop - 1;i++)
    {
        q = q->next;
        if(q == NULL)
            return 0;
    }
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = q;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prev = p;
    q->next = p;
    return 1;
}
//在指定位置删除数据
int delete_node(Node* L,int pop)
{
    Node* p = L;
    for(int i = 0;i < pop - 1;i++)
    {
        p = p->next;
        if(p->next == NULL)
            return 0;
    }
    Node* q = p->next;
    if(q->next != NULL)
        q->next->prev = p;
    p->next = q->next;
    free(q);
    return 1;
}
//释放双向链表
void free_node(Node* L)
{
    Node* p = L->next;
    Node* q;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}
int main(void)
{
    //双向链表初始化
    Node* list = inital_list();
    //头插法插入数据
    insert_head(list,10);
    insert_head(list,20);
    insert_head(list,30);
    insert_head(list,40);
    //遍历双向链表
    list_node(list);
    //查找尾节点
    Node* tail = find_tail(list);
    printf("尾节点的data为: %d\n",tail->data);
    //尾插法插入数据
    tail = insert_tail(tail,2);
    tail = insert_tail(tail,3);
    tail = insert_tail(tail,4);
    tail = insert_tail(tail,5);
    list_node(list);
    //在指定位置插入数据
    insert_node(list,5,520);
    list_node(list);
    //在指定位置删除数据
    delete_node(list,5);
    list_node(list);
    //释放双向链表
    free_node(list);
    list_node(list);
    return 0;
}