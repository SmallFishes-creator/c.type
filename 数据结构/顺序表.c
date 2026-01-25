#include <stdio.h>
#define MAXSIZE 100
typedef int elem_type;
//顺序表的定义 
typedef struct{
	elem_type data[MAXSIZE];
	int length;
}seq_list;
//顺序表的初始化 
void init_list(seq_list* L)
{
	L->length = 0;
}
//在顺序表的最后添加元素 
int append_elem(seq_list* L,elem_type e)
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
//顺序表的遍历 
void list_elem(seq_list* L)
{
	for(int i = 0;i < L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
//插入数据 
int insert_elem(seq_list* L,int pos,elem_type e)
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表满了\n");
		return 0;
	}
	if(pos < 1 || pos > L->length)
	{
		printf("插入数据位置有误\n");
		return 0;
	}
	for(int i = L->length - 1;i >= pos - 1;i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[pos - 1] = e;
	L->length++;
}
//删除数据 
int delete_elem(seq_list* L,int pos,elem_type* e)
{
	if(L->length == 0)
	{
		printf("空表\n");
		return 0;
	}
	if(pos < 1 || pos > L->length)
	{
		printf("删除数据位置有误\n");
	}
	*e = L->data[pos - 1];
	for(int i = pos;i < L->length;i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return 1;
}
//查找数据 
int find_elem(seq_list* L,elem_type e)
{
	for(int i = 0;i < L->length;i++)
	{
		if(L->data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}
int main(void)
{
	seq_list list;
	init_list(&list);
	printf("初始化成功，目前长度占用%d\n",list.length);
	printf("目前占用内存%zu字节\n",sizeof(list.data));
	//添加新元素 
	append_elem(&list,18);
	append_elem(&list,45);
	append_elem(&list,63);
	append_elem(&list,17);
	//打印顺序表 
	list_elem(&list);
	//插入新元素 
	insert_elem(&list,2,10);
	list_elem(&list);
	//删除元素 
	elem_type e = 0;
	delete_elem(&list,3,&e);
	printf("删除的元素为：%d\n",e);
	list_elem(&list);
	//查找元素
	printf("%d\n",find_elem(&list,18)); 
	return 0;
} 