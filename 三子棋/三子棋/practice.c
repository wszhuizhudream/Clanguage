#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ROW 3
#define COL 3

//用x表示玩家，用o表示用户，" "表示未落子
int row = 0;
int col = 0;

//1.打印菜单
void PrintMenu();
//2.打印一个3*3的棋盘
void PrintBoard(char board[ROW][COL], int row, int col);
//3.对棋盘进行初始化
void InitBoard(char board[ROW][COL], int row, int col);
//3.玩家落子
void PlayerMove(char board[ROW][COL], int row, int col);
	//4.检验是否结束游戏
	//在检验游戏游戏是否结束的时候一共有三种情况：
	//玩家赢得比赛、电脑赢得比赛、和棋（棋盘满了但是没有分出胜负）
	//5.电脑落子
void Computer(char board[ROW][COL], int row, int col);
	
	//6.检验是否结束游戏
char CheckWin(char board[ROW][COL], int row, int col);
void PrintMenu(){
	printf("####################\n");
	printf("        1.play      \n");
	printf("        0.exit      \n");
	printf("####################\n");
}
void PrintBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			printf("---|---|---\n");
	}
	printf("\n");
}
void InitBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
//玩家落子
void PlayerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	while (1){
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (board[x - 1][y - 1] == ' '&& x >= 1 && x <= row &&
			y >= 1 && y <= col){
			board[x - 1][y - 1] = 'x';
			break;
		}
		else
			printf("坐标错误，请重新输入\n");
	}
}
//本次电脑下棋采用生成随机数的方式
void ComputerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	while (1){
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' '){
			board[x][y] = 'o';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == 0)
				return 0;
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row, int col){
	//判断胜利的条件：行、列、对角线
	//1.行的判断
	int i = 0;
	for (i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	//2.列的判断
	for (i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	//3.主对角线的判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	//3.次对角线的判断
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];
	//4.全盘满，和棋的情况
	else if (IsFull(board, ROW, COL) == 1)
		return 'p';
	//5.未满，继续进行
	else
		return ' ';
}
void game(){
	char win = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	//以上三个步骤为打印棋盘并初始化
	//游戏开始：
	while (1){
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		win = CheckWin(board, ROW, COL);
		if (win != ' '){
			break;
		}
		//system("cls");
		PrintBoard(board, ROW, COL);
	}
	if (win == 'x')
		printf("玩家赢\n");
	else if (win == 'o')
		printf("电脑获胜\n");
	else if (win == 'p');
	printf("平局\n");
	while (1){
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		win = CheckWin(board, ROW, COL);
		if (win != ' '){
			break;
		}
		//system("cls");
		PrintBoard(board, ROW, COL);
	}
	if (win == 'x')
		printf("玩家赢\n");
	else if (win == 'o')
		printf("电脑获胜\n");
	else if (win == 'p');
	printf("平局\n");
}
void playgame(){
	srand((unsigned)time(NULL));
	int input = 0;
	do{
		PrintMenu();
		printf("请输入你的选择\n");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main(){
	playgame();
	system("pause");
	return 0;
}