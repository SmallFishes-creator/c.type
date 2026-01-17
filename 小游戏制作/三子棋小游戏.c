#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);

void show_board(char board[3][3], int row, int col);

void person_move(char board[3][3], int row, int col);

void computer_move(char board[3][3], int row, int col);

char win(char board[3][3], int row, int col);

void result(char x);

void menu(void)
{
	printf("*****************************\n");
	printf("*********  1. play  *********\n");
	printf("*********  2. exit  *********\n");
	printf("*****************************\n");
}
//row表示竖行，col表示横列
void show_board(char board[3][3], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		//打印数据
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//打印分割行
		if(i < 2)
			printf("---|---|---\n");
	}
}

//玩家下棋 *
void person_move(char board[3][3], int row, int col)
{
	int i = 0, j = 0;
	printf("玩家下棋:>\n");
	while (1)
	{
		scanf("%d %d", &i, &j);
		if (i < row + 1 && j < col + 1 && i > 0 && j > 0 && board[i - 1][j - 1] == ' ')
		{
			board[i - 1][j - 1] = '*';
			break;
		}
		else
			printf("输入错误，请重新输入！\n");
	}
	show_board(board, row, col);
}

//电脑下棋
void computer_move(char board[3][3], int row, int col)
{
	printf("电脑下棋:>\n");
	srand(time(NULL));
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
	show_board(board, row, col);
}

//输赢判断
//电脑赢返回‘#’
//玩家赢返回‘*’
//平局返回‘1’
//继续返回‘0’
char win(char board[3][3], int row, int col)
{
	//列
	for (int i = 0;i < 3;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == '*')
		{
			return '*';
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == '#')
		{
			return '#';
		}
	}
	//行
	for (int j = 0;j < 3;j++)
	{
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][2] == '*')
		{
			return '*';
		}
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][2] == '#')
		{
			return '#';
		}
	}
	//左上-右下 斜线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[2][2] == '*')
			return '*';
		if (board[2][2] == '#')
			return '#';
	}
	//左下-右上 斜线
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[2][0] == '*')
			return '*';
		if (board[2][0] == '#')
			return '#';
	}
	return 0;
}

void result(char x)
{
	if (x == '*')
		printf("玩家赢！\n");
	if (x == '#')
		printf("电脑赢！\n");
	if (x == 1)
		printf("平局！\n");
}

void game(void)
{
	char board[3][3] = { 0 };
	//二维数组初始化
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			board[i][j] = ' ';
		}
	}
	//打印棋盘
	show_board(board, 3, 3);
	while (1)
	{
		//玩家下棋
		person_move(board, 3, 3);
		result(win(board, 3, 3));
		if (win(board, 3, 3) != 0)
			break;
		//电脑下棋
		computer_move(board, 3, 3);
		result(win(board, 3, 3));
		if (win(board, 3, 3) != 0)
			break;
	}
}
int main(void)
{
	int choose = 0;
	do
	{
		menu();
		printf("请输入你的选择（1/0):>");
		scanf("%d", &choose);
		if (choose == 1)
		{
			game();
		}
		else if (choose == 0)
		{
			printf("退出游戏！\n");
			break;
		}
		else
			printf("输入错误，请重新输入！\n");
	} while (1);
	return 0;
}