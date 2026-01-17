#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int uncertain()
{
	srand(time(NULL));
	int random_number = rand() % 100 + 1;
	return random_number;
}
void game()
{
	int num = uncertain();
	int guess = 0;
	while (1)
	{
		printf("请输入你猜测的数字：\n<<<\n");
		scanf("%d", &guess);
		if (guess < num)
		{
			printf("猜小了\n");

		}
		else if (guess > num)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你答对了\n");
			break;
		}
	}

}
void menu()
{
	printf("********************************\n");
	printf("*********   1. play   **********\n");
	printf("*********   0. exit   **********\n");
	printf("********************************\n");
}
int main(void)
{
	int choose = 0;
	do
	{
		menu();
		printf("请输入您的选择（0/1）：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("开始游戏！\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (choose != 0);
	return 0;
}