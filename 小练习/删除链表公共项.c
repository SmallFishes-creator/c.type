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
    node* p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
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
int delete_abs_common_node(node* L)
{
    if(L->next == NULL)
        return 0;
    node* p = L->next;
    int max = abs(p->data);
    while(p != NULL)
    {
        int tmp = abs(p->data);
        if(max <= tmp)
            max = tmp;
        p = p->next;
    }
    int* arr = (int*)calloc(max + 1,sizeof(int));
    for(p = L;p->next != NULL;)
    {
        int index = abs(p->next->data);
        if(arr[index] == 0)
        {
            arr[index] = 1;
            p = p->next;
            continue;
        }
        node* q = p->next;
        p->next = q->next;
        free(q);
    }
    free(arr);
    return 1;
}
int main(void)
{
    node* list = inital_list();
    node* tail = find_tail(list);
    tail = insert_tail(tail,21);
    tail = insert_tail(tail,-15);
    tail = insert_tail(tail,-15);
    tail = insert_tail(tail,7);
    tail = insert_tail(tail,15);
    list_node(list);
    delete_abs_common_node(list);
    list_node(list);
    return 0;
}