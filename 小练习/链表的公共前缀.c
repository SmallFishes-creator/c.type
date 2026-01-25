#include <stdio.h>
#include <stdlib.h>
typedef char elem_type;
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
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}
void insert_together_node(node** tail1,node** tail2,elem_type e)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    (*tail1)->next = p;
    (*tail2)->next = p;
    *tail1 = p;
    *tail2 = p;
}
node* find_first_toghther_node(node* p1,node* p2)
{
    int length1 = 0;
    int length2 = 0;
    node* slow = p1->next;
    node* fast = p2->next;
    while(slow != NULL)
    {
        length1++;
        slow = slow->next;
    }
    while(fast !=NULL)
    {
        length2++;
        fast = fast->next;
    }
    int len_sub = length1 - length2;
    if(len_sub >= 0)
    {
        fast = p1->next;
        slow = p2->next;
    }
    else
    {
        fast = p2->next;
        slow = p1->next;
    }
    for(int i = 0;i < abs(len_sub);i++)
    {
        fast = fast->next;
    }
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast == NULL || slow == NULL)
            return NULL;
    }
    return fast;
}
int main(void)
{
    node* p1 = inital_list();
    node* p2 = inital_list();
    node* tail1 = find_tail(p1);
    node* tail2 = find_tail(p2);
    //p1 being
    //p2 studing
    tail1 = insert_tail(tail1,'b');
    tail1 = insert_tail(tail1,'e');
    tail2 = insert_tail(tail2,'s');
    tail2 = insert_tail(tail2,'t');
    tail2 = insert_tail(tail2,'d');
    list_node(p1);
    list_node(p2);
    insert_together_node(&tail1,&tail2,'i');
    insert_together_node(&tail1,&tail2,'n');
    insert_together_node(&tail1,&tail2,'g');
    list_node(p1);
    list_node(p2);
    node* first_together_node = find_first_toghther_node(p1,p2);
    printf("公共前缀为：%c\n",first_together_node->data);
    return 0;
}