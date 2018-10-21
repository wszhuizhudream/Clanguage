#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//����˼·��
//1.��ӡһ���˵�ʹ��������Ѻ�
//2.����һ����ά��������ʾ����
//3.�����̽��г�ʼ��������������ȫ��Ϊ�ո񼴳�ʼ��
//4.���ȴ�ӡ��ʼ��������
//5.������Ӳ��Ҽ�����Ϸ�Ƿ����
//6.�������Ӳ��Ҽ�ѹ��Ϸ�Ƿ����
//�ٻص�������
//�˴��ĺ궨����Ϊ������Ķ���ʹ�ó����������Ժ���޸ĸĶ��ط���
#define ROW 3
#define COL 3
//2.�ȶ������̴�С
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

//1.��ӡ�˵�
void PrintMenu() {
	printf("####################\n");
	printf("        1.play      \n");
	printf("        0.exit      \n");
	printf("####################\n");
}
//3.�����̽��г�ʼ��
//������������x��ʾ��ң�o��ʾ���ԣ�' '��ʾ��
void InitBoard() {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			g_chess_board[row][col] = ' ';//��3*3���̵�ÿһ��Ԫ�ؽ��г�ʼ��Ϊ
			                              //�ո�
		}
	}
}
//4.��ӡһ��3*3������
void PrintBoard() {
	for (int row = 0; row < ROW; row++) {
		printf("| %c | %c | %c |\n", g_chess_board[row][0], g_chess_board[row][1],
			                                      g_chess_board[row][2]);
		if (row != ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
//5.�������
//�����Ƿ������Ϸ(�ڼ�����Ϸ��Ϸ�Ƿ������ʱ��һ�������������
              //���Ӯ�ñ���������Ӯ�ñ��������壨�������˵���û�зֳ�ʤ����)
void PlayerMove() {
	while (1) {
		//����ʾ�����������
		printf("�������������row col:");
		//�������
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//���������У��
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("���벻�������������룺\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ') {
			printf("��ǰλ���Ѿ��������ˣ����������룺\n");
			continue;
		}
		//���������������λ�ø�ֵΪ'x'
		g_chess_board[row][col] = 'x';
		break;
	}
}
//5.��������
//���ε��������������������ķ�ʽ
//�����Ƿ������Ϸ
void ComputerMove() {
	printf("��������\n");
	int row = 0;
	int col = 0;
	srand((unsigned)time(NULL));
	while (1) {
		//���������
		row = rand() % ROW;//[0,2]
		col = rand() % COL;//[0,2]
		if (g_chess_board[row][col] == ' ') {
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
char CheckWin() {
	//�ж�ʤ�����������С��С��Խ���
	//1.�е��ж�
	for (int row = 0; row < ROW; row++) {
		if (g_chess_board[row][0]== g_chess_board[row][1]
			&& g_chess_board[row][0]== g_chess_board[row][2]) {
			return g_chess_board[row][0];
		}
	}
	//2.�е��ж�
	for (int col = 0; col < COL; col++) {
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]) {
			return g_chess_board[0][col];
		}
	}

	//3.���Խ��ߵ��ж�
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[1][1] == g_chess_board[2][2])
	{
		return g_chess_board[0][0];
	}
	//3.�ζԽ��ߵ��ж�
	if (g_chess_board[0][2] == g_chess_board[1][1]
		&& g_chess_board[1][1] == g_chess_board[2][0])
	{
		return g_chess_board[0][2];
	}
	//4.ȫ��������������
    if (IsFull()) {
         return 'p';
	}
	//5.δ�����ؿո񣬼�������
	else
		return ' ';
}
int main() {
	int input = 0;
	PrintMenu();
	printf("������ѡ��\n");
	scanf("%d", &input);
	if (input == 1) {
		char winner = ' ';
		InitBoard();
		while (1) {
			PrintBoard();
			PlayerMove();
			winner = CheckWin();
			if (winner != ' ') {
				//��Ϸ��������һ�ʤ
				break;
			}
			PrintBoard();
			printf("\n");
			ComputerMove();
			winner = CheckWin();
			if (winner != ' ') {
				//��Ϸ���������Ի�ʤ
				break;
			}
		}
		if (winner == 'x') {
			printf("��һ�ʤ��\n");
		}
		else if (winner == 'o') {
			printf("���Ի�ʤ��\n");
		}
		else if (winner == 'p') {
			printf("����\n");
		}
	}
	else if (input == 0) {
		printf("�˳���Ϸ��\n");
	}
	system("pause");
	return 0;
}