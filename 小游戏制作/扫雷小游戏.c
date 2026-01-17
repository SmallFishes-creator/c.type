#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void menu(void);

void initial(char board[10][10], int row, int col);

void show_board(char board[10][10], int row, int col);

void boost(char board2[10][10], int row, int col);

void print_boost(char board2[10][10], char row, char col);

void num(char board2[10][10], int row, int col);

void player_move(char board[10][10], char board2[10][10], int row, int col,int* x,int* y,int* tool);

int is_win(char board[10][10], char board2[10][10], int row, int col);

void Recursion(char board[10][10], char board2[10][10], int x, int y, int row, int col);

void menu(void)
{
	printf("**********************\n");
	printf("******* 1.play *******\n");
	printf("******* 0.exit *******\n");
	printf("**********************\n");
}

void initial(char board[10][10], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = '*';
		}
	}
}

void show_board(char board[10][10], int row, int col)
{
	//第一行
	printf(" %d ", 0);
	for (int i = 1; i <= row; i++)
	{
		if (i < 10)
		{
			printf(" %d ", i);
		}
		else
		{
			printf("%3d", i);
		}
	}
	printf("\n");
	//接下来几行
	for (int i = 0; i < row; i++)
	{
		printf("%2d ", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}


void boost(char board2[10][10], int row, int col)
{
	srand((unsigned int)time(NULL));
	for (int step = 0; step < 20; step++)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (board2[i][j] == '*')
		{
			board2[i][j] = 'B';
		}
		else
			step--;
	}
}

//打印雷分布版面
void print_boost(char board2[10][10], char row, char col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board2[i][j]);
		}
		printf("\n");
	}
}

//确定非雷处标注数字大小
void num(char board2[10][10], int row, int col)
{
	int dx[] = { -1,-1,-1,0,0,1,1,1 };
	int dy[] = { -1,0,1,-1,1,-1,0,1 };
	for(int i = 0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(board2[i][j]!='B')
			{
				int count = 0;
				for(int k=0;k<8;k++)
				{
					int newx = i + dx[k];
					int newy = j + dy[k];
					if (newx >= 0 && newx < row && newy >= 0 && newy < col)
					{
						if (board2[newx][newy] == 'B')
							count++;
					}
				}
				board2[i][j] = count + '0';
			}
		}
	}
}

//玩家确定坐标及工具
void player_move(char board[10][10], char board2[10][10], int row, int col,int* x,int* y,int* tool )
{
	
	printf("----------------\n");
	printf("请输入你选择的坐标：\n>>>");
	int i = 0;
	int j = 0;
	scanf("%d%d", &j, &i);
	while ((i < 1 || i > 10) || (j < 1 || j > 10))
	{
		printf("输入的坐标超出界限！\n>>>");
		scanf("%d%d", &j, &i);
	}
	*x = i;
	*y = j;
	int k = 0;
	if (board2[i - 1][j - 1] != '0')
	{
		printf("请输入你选择的工具<1.排雷 2.做标记\n>>>");
		scanf("%d", &k);
		while ((k != 1 && k != 2))
		{
			printf("输入无效的工具！\n>>>");

			scanf("%d", &k);
		}
	}
	*tool = k;
}

void Recursion(char board[10][10], char board2[10][10], int x, int y, int row, int col)
{
	if (x < 0 || x >= row || y < 0 || y >= col)
		return;
	if (board[x][y] != '*')
		return;
	board[x][y] = board2[x][y];
	if (board2[x][y] == '0')
	{
		int dx[] = { -1,-1,-1,0,0,1,1,1 };
		int dy[] = { -1,0,1,-1,1,-1,0,1 };
		for(int k = 0; k < 8; k++)
		{
			int newx = x + dx[k];
			int newy = y + dy[k];
			Recursion(board, board2, newx, newy, row, col);
		}
	}
}

//判断玩家是否赢了
//赢了返回0
//没赢返回1
int is_win(char board[10][10], char board2[10][10], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'F' && board2[i][j] != 'B')
				return 1;
			if (board[i][j] != 'F' && board2[i][j] == 'B')
				return 1;
			if (board[i][j] == '*')
				return 1;
		}
	}
	printf("你赢了！\n");
	return 0;
}

void game(void)
{
	char board[10][10] = { 0 };
	//二维数组初始化
	initial(board, 10, 10);
	//扫雷面板展示
	show_board(board, 10, 10);
	//确定雷的位置
	char board2[10][10];
	memcpy(board2, board, sizeof(board));
	boost(board2, 10, 10);
	//确定非雷处标注数字大小
	num(board2, 10, 10);
	int win = 1;
	while (win)
	{
		//玩家确定坐标及使用工具
		int x = 0;
		int y = 0;
		int tool = 0;
		player_move(board, board2, 10, 10, &x, &y, &tool);
		if (tool == 2)
		{
			//做标记
			board[x - 1][y - 1] = 'F';
			show_board(board, 10, 10);
			win = is_win(board, board2, 10, 10);
		}
		else
		{
			//排雷
			if (board2[x - 1][y - 1] == 'B')
			{
				printf("你踩到雷了！\n");
				print_boost(board2, 10, 10);
				break;
			}
			else if (board2[x - 1][y - 1] == '0')
			{
				Recursion(board, board2, x - 1, y - 1, 10, 10);
				show_board(board, 10, 10);
			}
			else
			{
				board[x - 1][y - 1] = board2[x - 1][y - 1];
				show_board(board, 10, 10);
			}
			//判断玩家是否赢了
			win = is_win(board, board2, 10, 10);
		}
	}
}
int main(void)
{
	//游戏选择
	int choose = 0;
	do
	{
		menu();
		printf("请选择（0/1）:>\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("开始游戏！\n");
			game();
		}
		else if (choose == 0)
		{
			printf("退出游戏！\n");
			break;
		}
		else
			printf("输入错误,请重新输入！\n");
	} while (choose);
	return 0;
}