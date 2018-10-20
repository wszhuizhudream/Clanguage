//1. 写一个函数返回参数二进制中 1 的个数比如： 15 0000 1111 4 个 1程序原型：
////方法1：
////思路：通过模2判断1的个数(有缺陷，只能对正数进行判断)
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num = 0;
//	printf("请输入一个数，得到它二进制数中1的个数:\n");
//	scanf("%d", &num);
//	int count = 0;
//	while (num) {
//		if (num % 2 == 1) {
//			count++;
//		}
//		num = num / 2;
//	}
//	printf("1的个数为：%d\n", count);
//	system("pause");
//	return 0;
//}

////方法2：
////思路：对于输入的整型是4个字节，总共32位，则对这32位一次进行判断，
////为1则加1（可以对正负数判断）
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num = -1;
//	int count = 0;
//	for (int i = 0; i < 32; i++) {
//		//num=7  ===>0111
//		if (((num >> i)&1) == 1) {
//			count++;
//		}
//		printf("1的个数为：%d\n", count);
//		system("pause");
//		return 0;
//	}
//}

////2.获取一个数二进制序列中所有的偶数位和奇数位， 分别输出二进制序列。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr1[16] = { 0 };//存放二进制偶数序列
//	int arr2[16] = { 0 };//存放二进制奇数序列
//	printf("请输入一个数字：\n");
//	scanf("%d", &num);
//	for (i = 0, j = 0; j < 32; ++i, j += 2) {
//		arr1[15 - j / 2] = (num >> j) & 1;//通过按位与得到偶数位原本的
                                         //数字，放在数组中。
//		arr2[15 - i] = (num >> (2 * i + 1)) & 1;//通过按位与得到奇数位
                                               //原本的数字，放在数组中。
//	}
//	printf("%d对应的二进制数的偶数位分别是：\n", num);
//	for (i = 0; i < 16; i++) {
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	printf("%d对应的二进制数的奇数位分别是：\n", num);
//	for (i = 0; i < 16; i++) {
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////3. 输出一个整数的每一位。 
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int i = 0;
//	int num = 0;
//	int arr[32] = { 0 };
//	printf("请输入一个数：\n");
//	scanf("%d", &num);
//	for (i = 0; i < 32; i++) {
//		arr[31 - i] = (num >> i) & 1;
//	}
//	printf("%d对应的二进制数为:\n",num);
//	for (i = 0; i < 32; i++) {
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

////4.编程实现： 
////两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
////输入例子 :
////1999 2299
////输出例子 :7
////思路：先将m与n的按位与存在一个临时变量里。然后再对这个临时变量有
////多少个1进行计数，最后得到1的个数即为不同的bit位
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int m = 0;
//	int n = 0;
//	int temp = 0;
//	int count = 0;
//	printf("请输入两个数：\n");
//	scanf("%d %d", &m, &n);
//	temp = m ^ n;
//	for (int i = 0; i < 32; i++) {
//		if (((temp >> i) & 1))
//			count++;
//	}
//	printf("总共有不同的bit位:%d\n", count);
//	system("pause");
//	return 0;
//}