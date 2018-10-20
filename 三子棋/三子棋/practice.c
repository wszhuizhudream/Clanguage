#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ROW 3
#define COL 3

//��x��ʾ��ң���o��ʾ�û���" "��ʾδ����
int row = 0;
int col = 0;

//1.��ӡ�˵�
void PrintMenu();
//2.��ӡһ��3*3������
void PrintBoard(char board[ROW][COL], int row, int col);
//3.�����̽��г�ʼ��
void InitBoard(char board[ROW][COL], int row, int col);
//3.�������
void PlayerMove(char board[ROW][COL], int row, int col);
	//4.�����Ƿ������Ϸ
	//�ڼ�����Ϸ��Ϸ�Ƿ������ʱ��һ�������������
	//���Ӯ�ñ���������Ӯ�ñ��������壨�������˵���û�зֳ�ʤ����
	//5.��������
void Computer(char board[ROW][COL], int row, int col);
	
	//6.�����Ƿ������Ϸ
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
//�������
void PlayerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("�����\n");
	while (1){
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		if (board[x - 1][y - 1] == ' '&& x >= 1 && x <= row &&
			y >= 1 && y <= col){
			board[x - 1][y - 1] = 'x';
			break;
		}
		else
			printf("�����������������\n");
	}
}
//���ε��������������������ķ�ʽ
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
	//�ж�ʤ�����������С��С��Խ���
	//1.�е��ж�
	int i = 0;
	for (i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	//2.�е��ж�
	for (i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	//3.���Խ��ߵ��ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	//3.�ζԽ��ߵ��ж�
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];
	//4.ȫ��������������
	else if (IsFull(board, ROW, COL) == 1)
		return 'p';
	//5.δ������������
	else
		return ' ';
}
void game(){
	char win = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	//������������Ϊ��ӡ���̲���ʼ��
	//��Ϸ��ʼ��
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
		printf("���Ӯ\n");
	else if (win == 'o')
		printf("���Ի�ʤ\n");
	else if (win == 'p');
	printf("ƽ��\n");
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
		printf("���Ӯ\n");
	else if (win == 'o')
		printf("���Ի�ʤ\n");
	else if (win == 'p');
	printf("ƽ��\n");
}
void playgame(){
	srand((unsigned)time(NULL));
	int input = 0;
	do{
		PrintMenu();
		printf("���������ѡ��\n");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
}
int main(){
	playgame();
	system("pause");
	return 0;
}