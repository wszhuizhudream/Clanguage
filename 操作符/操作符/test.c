//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	//int a = 3;
//	double a = 1.0;
//	double b = 2.1;
//	a = a & b;
//	printf("%d", (a));
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int a = 0;
//	printf("请输入一个数:\n");
//	scanf("%d", &a);
//	a = 45;
//	printf("a的值被修改为：%d\n", a);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
	//int a = 0;
	//printf("请输入一个数:\n");
	//scanf("%d", &a);
	//a += 45;
	//printf("a*=45==>%d\n", a);
	//char x = '3';
	//x <<= 1;
	//printf("%c", x);
	//double x = 1.2;
	//x >>= 1;
	//printf("%lf", x);
	//double a = 2.3;
	//a &= 3;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test1(int arr[]) {
//	printf("%d\n", sizeof(arr));
//}
//void test2(char ch[]) {
//	printf("%d\n", sizeof(ch));
//}
//int main() {
//	int arr[10] = { 0 };
//	char ch[10] = { '0' };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	test1(arr);
//	test2(ch);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	//i=a++ || ++b || d++;
	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
	system("pause");
	return 0;
}