#include <stdio.h>
#include <stdlib.h>
typedef int elem_type;
typedef struct Node{
    elem_type data;
    struct Node* next;
}node;
node* inital_list(void)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = 0;
    p->next = NULL;
    return p;
}
node* find_tail(node* L)
{
    node* tail = L;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}
node* insert_tail(node* tail,elem_type e)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}
void list_node(node* L)
{
    node* p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
node* find_mid_node(node* L)
{
    if(L->next == NULL)
    {
        printf("空的\n");
        return NULL;
    }
    node* slow = L;
    node* fast = L->next;
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
int main(void)
{
    node* list = inital_list();
    node* tail = find_tail(list);
    tail = insert_tail(tail,1);
    tail = insert_tail(tail,2);
    tail = insert_tail(tail,3);
    tail = insert_tail(tail,4);
    tail = insert_tail(tail,5);
    tail = insert_tail(tail,6);
    tail = insert_tail(tail,7);
    list_node(list);
    node* mid = find_mid_node(list);
    printf("中间节点的data为：%d\n",mid->data);
    return 0;
}