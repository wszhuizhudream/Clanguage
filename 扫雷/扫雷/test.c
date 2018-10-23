#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//1.打印一个菜单，提示用户是否开始游戏
int  Menu() {
	printf("##########################\n");
	printf("           1.play         \n");
	printf("           0.exit         \n");
	printf("##########################\n");
	int choice = 0;
	printf("请输入您的选择：\n");
	scanf("%d", &choice);
	return choice;
}
#define Mine_number 10
#define ROW 9
#define COL 9
//需要定义两个数组：（加一个边框）
//一个表示雷阵
//用字符'0'表示不是地雷，字符'1'表示是地雷
char mine_map[ROW + 2][COL + 2];

//一个表示给玩家展示的扫雷图
//*表示未打开的格子，打开的格子用具体的数字来表示周围8个格子地雷的数量
char show_map[ROW + 2][COL + 2];
//没有地雷的格子数
int no_mine_number = 0;
void Init(char mine_map[ROW+2][COL+2],char show_map[ROW+2][COL+2]) {
	//1.把数组进行初始化
	//把表示雷阵的数组全部初始化为'0'
	//(1)方法1：通过一个函数(对应参数的含义)：需要进行赋值的数组名、需要赋值
	           //成什么、赋值区域的大小。
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	//（2）方法2：通过循环进行赋值
	//int row = 0;
	//int col = 0;
	//for (row = 1; row <= ROW; row++) {
	//	for (col = 1; col <= COL; col++) {
	//		mine_map[row][col] = '0';
	//	}
	//}
	//把表示未打开的格子全部初始化为*
   memset(show_map, '*', (ROW + 2)*(COL + 2));
	//2.通过随机的方法把雷阵布置好
   srand((unsigned)time(NULL));
   int mine_count = Mine_number;
   //每次随机产生一个横坐标、一个纵坐标，表示有地雷的位置，每次布置布置一个地雷
   //范围为:[1,ROW]
   while (mine_count > 0) {
	   int row = 0;
	   int col = 0;
	   row = rand() % 9 + 1;
	   col = rand() % 9 + 1;
	   if(mine_map[row][col] =='0'){
	   mine_map[row][col] = '1';
	   mine_count--;
	   }
   }
}
void PrintMap(char map[ROW + 2][COL + 2]) {
	int row = 0;
	int col = 0;
	//打印第一行之前先打印5个空格，为了让键盘更加好看
	printf("   ");
	//打印列号
	for (col = 1; col <= COL; col++) {
		printf("%d   ", col);
	}
	printf("\n");
	//打印第二行，边框
	for (col = 1; col <= COL; col++) {
		printf("----");
	}
	printf("\n");
	//打印具体内容
	for (row = 1; row <= ROW; row++) {
		//%02d的意思是把一位数也变为两位数输出
		//1==>01  2==>02
	//打印行号之前先打印一个空格，为了对其坐标与每个格子
	printf(" ");
		printf("%d|", row);
		for (col = 1; col <= COL; col++) {
			printf("%c   ", map[row][col]);
		}
		printf("\n");
		printf("\n");
	}
}
//需要统计当前位置周围8个位置的地雷数，并将结果更新到show_map中
void UpdateMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW+2][COL+2],
	int row,int col ) {
	int mine_count = 0;
	//row, col;当前位置
	//1.row - 1, col - 1;
	//由于mine_map中只有两种情况，要么是1表示有地雷，要么是0表示没有地雷，
	//所以可以通过这种方式进行统计地雷的数量
	mine_count = (mine_map[row - 1][col - 1]-'0')+
	//2.row - 1, col;
	(mine_map[row - 1][col]-'0')+
	//3.row - 1, col + 1;
	(mine_map[row - 1][col + 1]-'0')+
	//4.row, col - 1;
	(mine_map[row][col - 1]-'0')+
	//5.row, col + 1;
	(mine_map[row][col + 1]-'0')+
	//6.row + 1, col - 1;
	(mine_map[row + 1][col - 1]-'0')+
	//7.row + 1, col;
	(mine_map[row + 1][col]-'0')+
	//8.row + 1, col + 1;
	(mine_map[row + 1][col + 1]-'0');
	show_map[row][col] = '0' + mine_count;//直接把地雷的数量转化为字符形式
	//表示出来。因为show_map[row][col]是字符类型的，字符'0'的ASCII码为60，'1'
	//的ASCII码为61，所以加几就转化为字符几的ASCII码。
}
void Game() {
	//1.初始化地图（mine_map,show_map）
	Init(mine_map, show_map);
	//2.先打印show_map.
	PrintMap(show_map);
	//因为涉及到后面的步骤需要判断是或否，有终止条件，所以此处需要循环
	while (1) {
	//3.提示用户输入坐标
		int row = 0;
		int col = 0;
	printf("请输入需要翻开方块的坐标：row col\n");
	scanf("%d %d", &row, &col);
	//4.对用户输入的合法性进行判断，如果不合理，提示用户重新输入
	if (row <= 0 || row > ROW || col <= 0 || col > COL) {
		printf("您的输入不合理请重新输入：\n");
		continue;
	}
	//5.判定玩家当前是否踩雷，如果踩雷，游戏结束并且打印雷阵
	if (mine_map[row][col] == '1') {
		printf("游戏结束！\n");
		PrintMap(mine_map);
		break;
	}
	//6.如果没踩雷，判定玩家是否胜利（胜利的条件是：已经翻开的方块数=总数-雷数）
	if (no_mine_number == ROW * COL - Mine_number) {
		printf("恭喜您获胜了！\n");
		PrintMap(mine_map);
		break;
	}
	//7.接下来就需要统计当前位置周围有几个雷，然后回到第3步
	UpdateMap(show_map,mine_map,row,col);
	PrintMap(show_map);
	}
}
//2.通过返回值判断是否进行游戏
void statr() {
	while (1) {
		int choice = Menu();
		if(choice==0){
			printf("退出游戏\n");
			break;
		}
	Game();//为1就调用该函数开始游戏
	break;//加这个break是为了让程序只进行一次，不管最后结果是赢还是输都退出
	      //游戏。
	}
}
int main() {
	statr();
	system("pause");
	return 0;
}