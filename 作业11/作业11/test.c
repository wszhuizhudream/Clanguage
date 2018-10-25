////1.编写函数： 
////unsigned int reverse_bit(unsigned int value);
////这个函数的返回值value的二进制位模式从左到右翻转后的值。
////如：
////在32位机器上25这个值包含下列各位：
////00000000000000000000000000011001
////翻转后：（2550136832）
////10011000000000000000000000000000
////程序结果返回：
////2550136832
////将提出的每一位依次保存在一个字符数组中，此时的问题便是如何将二进制数准换成十进制。
////同时需要将字符型转换为整型。
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//unsigned int reverse_bit(unsigned int value) {
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < 32; i++) {
//		if ((value >> i) & 1) {
//			ret|=(value>>i&1)<<(31-i);
//		}
//	}
//	return ret;
//}
//int main() {
//	int a = 25;
//	int ret = 0;
//	ret = reverse_bit(a);
//	printf("通过转换后为：%u\n", ret);//注意此处一定要用%u表示无符号
//	system("pause");
//	return 0;
//}

////2.不使用（a + b） / 2这种方式，求两个数的平均值。
////思路：右移就相当于除2
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num1 = 0;
//	int num2 = 0;
//	printf("请输入两个数：\n");
//	scanf("%d %d", &num1, &num2);
//	printf("两个数的平均数为：%d\n", (num1 + num2) >> 1);
//	system("pause");
//	return 0;
//}


////3.编程实现：
////一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
////请找出这个数字。（使用位运算）
////思路：在一组数据中不同的那一个数和其他的数异或都是1，在这个数组里面对每个元素进行异或
////的遍历就可以得到只出现一次的那个数。
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = { 1,1,2,2,5,5,7,7,8,8,12,3,3 };
//	int i = 0;
//	for (i = 1; i < sizeof(arr)/sizeof(arr[0]); i++) {
//		arr[0] = arr[0] ^ arr[i];//与不是自己的每一个元素进行异或
//	}
//	printf("the signal number is:%d\n", arr[0]);
//	system("pause");
//	return 0;
//}


////4.
////有一个字符数组的内容为:"student a am i",
////	请你将数组的内容改为"i am a student".
////	要求：
////	不能使用库函数。
////	只能开辟有限个空间（空间个数和字符串的长度无关）。
////
////	student a am i
////	i ma a tneduts
////	i am a student
////思路：先将这个数组整体进行首尾交换，然后再将得到的数组中每一个单词进行首尾交换，这个
////单词通过'\0'进行判断一个单词的长度
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//void swap(char* left, char* right) {
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right) {
//		char temp = 0;
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//void reverse(char* arr) {
//	//整体逆置
//	int len = strlen(arr);
//	swap(arr, arr + len - 1);
//	//每个单词的逆置
//	while (*arr != '\0') {//若不满足则说明还没有到最后一个位置
//		char* start = arr;//单词起始位置
//		char* end = start;//单词结束位置
//		while ((*end != '\0') && (*end != ' ')) {
//			end++;//end指向空格位置的地址
//		}
//		//单词的起始位置为start,结束位置为end前一个
//		swap(start, end - 1);
//		if (*end != '\0') {
//			//当结束一个单词的时候下一个单词的起始为空格的后一个字符
//			arr = end + 1;
//		}
//		else {
//			arr = end;
//		}
//	}
//}
//int main() {
//	char arr[] = "student a am i";
//	reverse(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

////2+22+222+2222+22222
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num = 0;
//	int sum = 0;
//	int sn = 0;
//	printf("请输入一个数：\n");
//	scanf("%d", &num);
//	for (int i = 1; i <= 5; i++){//循环次数表示有几项 
//		sum = num + sum * 10;//每次得到的都是没有各位的项
//	    sn += sum;
//	    printf("每一项=%d\n", sum);
//	}
//	printf("sn=%d\n", sn);
//	system("pause");
//	return 0;
//}
