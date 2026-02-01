#include <stdio.h>
#include <stdlib.h>
typedef char elem_type;
typedef struct Tree_node
{
    elem_type data;
    struct Tree_node* left_child;
    struct Tree_node* right_child;
}tree_node;
typedef tree_node* bi_tree;
void creat_tree(const char* arr,bi_tree* T)
{
    static int index = 0;
    elem_type symbol = arr[index];
    index++;
    if(symbol == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (bi_tree)malloc(sizeof(tree_node));
        (*T)->data = symbol;
        creat_tree(arr,&((*T)->left_child));
        creat_tree(arr,&((*T)->right_child));
    }
}
void pre_order(bi_tree T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        printf("%c ",T->data);
        pre_order(T->left_child);
        pre_order(T->right_child);
    }
}
void in_order(bi_tree T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        in_order(T->left_child);
        printf("%c ",T->data);
        in_order(T->right_child);
    }
}
int main(void)
{
    char* arr = "ABDH#K###E##CFI###G#J##";
    bi_tree tree;
    creat_tree(arr,&tree);
    pre_order(tree); 
    printf("\n");
    in_order(tree);
    printf("\n");
    return 0;
}