#include <stdio.h>
struct Date
{
	int year;
	int month;
	int day;
};
struct BOOK
{
	char ISBN[100];
	char book_name[50];
	char writer[30];
	double price;
	struct Date D;
};
//int main(void)
//{
//	struct BOOK book[5] = { {"978 - 7 - 302 - 12345 - 6","C语言程序设计","谭浩强",39.00,{2010,8,1}},{"978 - 7 - 115 - 23456 - 7","数据结构","严蔚敏",45.00,{2012,6,1}},{"978 - 7 - 121 - 34567 - 8","算法导论","Thomas",128.00,{2013,9,1}},{"978 - 7 - 04 - 45678 - 9","高等数学","同济大学",58.00,{2014,1,1}}, {"978 - 7 - 111 - 56789 - 0","操作系统","汤小丹",42.00,{2011,5,1}} };
//	for (int i = 0; i < 5; i++)
//	{
//		printf("第%d本书的信息\n<<<\n",i + 1);
//		printf("ISBN：%s\n", book[i].ISBN);
//		printf("书名：%s\n", book[i].book_name);
//		printf("作者：%s\n", book[i].writer);
//		printf("价格：%.2f元\n", book[i].price);
//		printf("日期：%d年%d月%d日\n", book[i].D.year, book[i].D.month, book[i].D.day);
//	}
//	printf("-----------------------------");
//	return 0;
//}

void sort_by_price(struct BOOK book[],int n)
{
	int return_size = 0;
	for (int i = 0; i < n; i++)
	{
		if (book[return_size].price < book[i].price)
		{
			return_size = i;
		}
	}
	printf("价格最高的书籍为：《%s》，他的价格为%.2f元\n", book[return_size].book_name, book[return_size].price);
}
void book_output(struct BOOK book[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("第%d本书的信息\n<<<\n", i + 1);
		printf("ISBN：%s\n", book[i].ISBN);
		printf("书名：%s\n", book[i].book_name);
		printf("作者：%s\n", book[i].writer);
		printf("价格：%.2f元\n", book[i].price);
		printf("日期：%d年%d月%d日\n", book[i].D.year, book[i].D.month, book[i].D.day);
	}
	printf("-----------------------------\n");
}

void bubble_book(struct BOOK book[5], int n)
{
	for (int j = 0; j < n - 2; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (book[i].price > book[i + 1].price)
			{
				struct BOOK tmp = book[i];
				book[i] = book[i + 1];
				book[i + 1] = tmp;
			}
		}
	}
}

void find_by_author(struct BOOK book[], int n)
{
	while (1)
	{
		int flag = 1;
		char input[20] = { 0 };
		printf("请输入作者名：\n<<<");
		scanf("%s", &input);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(book[i].writer, input) == 0)
			{
				printf("《%s》\n", book[i].book_name);
				flag = 0;
			}
		}
		if (flag)
			printf("未查找到相关信息……\n");
	}
}



int main(void)
{
	struct BOOK book[5] = 
	{ 
		{"978 - 7 - 302 - 12345 - 6","C语言程序设计","谭浩强",39.00,{2010,8,1}},
		{"978 - 7 - 115 - 23456 - 7","数据结构","严蔚敏",45.00,{2012,6,1}},
		{"978 - 7 - 121 - 34567 - 8","算法导论","Thomas",128.00,{2013,9,1}},
		{"978 - 7 - 04 - 45678 - 9","高等数学","同济大学",58.00,{2014,1,1}},
		{"978 - 7 - 111 - 56789 - 0","操作系统","汤小丹",42.00,{2011,5,1}} 
	};
	//书籍排序
	bubble_book(book, 5);
	//书籍详细页输出
	book_output(book, 5);
	//最高价格查找
	sort_by_price(book, 5);
	//根据作者查找书籍
	find_by_author(book, 5);
	return 0;
}