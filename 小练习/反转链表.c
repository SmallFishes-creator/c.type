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
node* reversal_list(node* L)
{
    node* first = NULL;
    node* second = L->next;
    node* third;
    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    node* head = inital_list();
    head->next = first;
    return head;
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
    list_node(reversal_list(list));
    return 0;
}