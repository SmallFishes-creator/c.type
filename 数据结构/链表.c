#include <stdio.h>
#include <stdlib.h>
typedef int elem_type;
typedef struct node{
    elem_type data;
    struct node* next;
}Node;
//初始化链表
Node* init_list()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
//头插法
void insert_head(Node* L,elem_type e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}
//尾结点
Node* list_tail(Node* L)
{
    Node* p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    printf("尾结点的data为：%d\n",p->data);
    printf("尾结点的data为NULL?:");
    if(p->next == NULL)
        printf("YES\n");
    else
        printf("NO\n");
    return p;
}
//尾插法
void insert_tail(Node** tail,elem_type e)
{
    Node* p =(Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    (*tail)->next = p;
    *tail = p;
}
//遍历链表
void list_node(Node* L)
{
    Node* p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
//插入指定位置
int insert_node(Node* L,int pos,elem_type e)
{
    //为了保存插入位置的前驱节点
    Node* p = L;
    for(int i = 0;i < pos - 1;i++)
    {
        p = p->next;
        if(p ==NULL)
            return 0;
    }
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
//删除指定位置
int delete_node(Node* L,int pos)
{
    //要删除的节点的前驱
    Node* p = L;
    //遍历链表，找到要删除的节点的前驱
    for(int i = 0;i < pos - 1;i++)
    {
        p = p->next;
        if(p == NULL)
            return 0;
    }
    //记录要删除的那个节点
    Node* q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
//获取链表的长度
int list_length(Node* L)
{
    Node* p = L;
    int length = 0;
    while(p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}
//释放链表
void free_list(Node* L)
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
//查找倒数第k个节点
Node* find_node_k(Node* L,int k)
{
    Node* slow = L->next;
    Node* fast = L->next;
    for(int i = 0;i < k;i++)
    {
        fast = fast->next;
        if(fast == NULL)
            return NULL;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main(void)
{
    //初始化链表
    Node* list = init_list();
    if(list->data == 0 && list->next == NULL)
        printf("链表初始化成功\n<<<\n");
    else
        printf("链表初始化失败\n<<<\n");
    //头插法
    insert_head(list,10);
    insert_head(list,20);
    insert_head(list,30);
    //遍历链表
    list_node(list);
    //尾节点
    Node* tail = list_tail(list);
    //尾插法
    insert_tail(&tail,5);
    insert_tail(&tail,4);
    insert_tail(&tail,3);
    insert_tail(&tail,2);
    //遍历链表
    list_node(list); 
    //插入指定位置
    insert_node(list,4,520);
    list_node(list);
    //删除指定位置
    delete_node(list,4);
    list_node(list);
    //获取链表的长度
    printf("链表的长度（包含头节点）为：%d\n",list_length(list));
    //查找倒数第k个节点
    Node* k = find_node_k(list,3);
    printf("倒数第3个节点的data为：%d\n",k->data);
    //释放链表
    free_list(list);
}