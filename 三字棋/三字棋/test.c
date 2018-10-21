#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//整体思路：
//1.打印一个菜单使界面更加友好
//2.定义一个二维数组来表示棋盘
//3.对棋盘进行初始化，这里让棋盘全部为空格即初始化
//4.首先打印初始化的棋盘
//5.玩家落子并且检验游戏是否结束
//6.电脑落子并且减压游戏是否结束
//再回到第三步
//此处的宏定义是为了数组的定义使用常量，方便以后的修改改动地方少
#define ROW 3
#define COL 3
//2.先定义棋盘大小
char g_chess_board[ROW][COL];

int IsFull() {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (g_chess_board[row][col] == ' ') {
				return 0;
			}
		}
    }
	return 1;
}

//1.打印菜单
void PrintMenu() {
	printf("####################\n");
	printf("        1.play      \n");
	printf("        0.exit      \n");
	printf("####################\n");
}
//3.对棋盘进行初始化
//在这里我们用x表示玩家，o表示电脑，' '表示空
void InitBoard() {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			g_chess_board[row][col] = ' ';//对3*3棋盘的每一个元素进行初始化为
			                              //空格；
		}
	}
}
//4.打印一个3*3的棋盘
void PrintBoard() {
	for (int row = 0; row < ROW; row++) {
		printf("| %c | %c | %c |\n", g_chess_board[row][0], g_chess_board[row][1],
			                                      g_chess_board[row][2]);
		if (row != ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
//5.玩家落子
//检验是否结束游戏(在检验游戏游戏是否结束的时候一共有三种情况：
              //玩家赢得比赛、电脑赢得比赛、和棋（棋盘满了但是没有分出胜负）)
void PlayerMove() {
	while (1) {
		//先提示玩家输入坐标
		printf("请玩家输入坐标row col:");
		//玩家落子
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//对输入进行校验
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("输入不合理，请重新输入：\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ') {
			printf("当前位置已经有棋子了，请重新输入：\n");
			continue;
		}
		//玩家输入合理，则给该位置赋值为'x'
		g_chess_board[row][col] = 'x';
		break;
	}
}
//5.电脑落子
//本次电脑下棋采用生成随机数的方式
//检验是否结束游戏
void ComputerMove() {
	printf("电脑落子\n");
	int row = 0;
	int col = 0;
	srand((unsigned)time(NULL));
	while (1) {
		//产生随机数
		row = rand() % ROW;//[0,2]
		col = rand() % COL;//[0,2]
		if (g_chess_board[row][col] == ' ') {
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
char CheckWin() {
	//判断胜利的条件：行、列、对角线
	//1.行的判断
	for (int row = 0; row < ROW; row++) {
		if (g_chess_board[row][0]== g_chess_board[row][1]
			&& g_chess_board[row][0]== g_chess_board[row][2]) {
			return g_chess_board[row][0];
		}
	}
	//2.列的判断
	for (int col = 0; col < COL; col++) {
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]) {
			return g_chess_board[0][col];
		}
	}

	//3.主对角线的判断
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[1][1] == g_chess_board[2][2])
	{
		return g_chess_board[0][0];
	}
	//3.次对角线的判断
	if (g_chess_board[0][2] == g_chess_board[1][1]
		&& g_chess_board[1][1] == g_chess_board[2][0])
	{
		return g_chess_board[0][2];
	}
	//4.全盘满，和棋的情况
    if (IsFull()) {
         return 'p';
	}
	//5.未满返回空格，继续进行
	else
		return ' ';
}
int main() {
	int input = 0;
	PrintMenu();
	printf("请输入选择：\n");
	scanf("%d", &input);
	if (input == 1) {
		char winner = ' ';
		InitBoard();
		while (1) {
			PrintBoard();
			PlayerMove();
			winner = CheckWin();
			if (winner != ' ') {
				//游戏结束，玩家获胜
				break;
			}
			PrintBoard();
			printf("\n");
			ComputerMove();
			winner = CheckWin();
			if (winner != ' ') {
				//游戏结束，电脑获胜
				break;
			}
		}
		if (winner == 'x') {
			printf("玩家获胜！\n");
		}
		else if (winner == 'o') {
			printf("电脑获胜！\n");
		}
		else if (winner == 'p') {
			printf("和棋\n");
		}
	}
	else if (input == 0) {
		printf("退出游戏！\n");
	}
	system("pause");
	return 0;
}