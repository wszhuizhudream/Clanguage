////1.��д������ 
////unsigned int reverse_bit(unsigned int value);
////��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
////�磺
////��32λ������25���ֵ�������и�λ��
////00000000000000000000000000011001
////��ת�󣺣�2550136832��
////10011000000000000000000000000000
////���������أ�
////2550136832
////�������ÿһλ���α�����һ���ַ������У���ʱ�����������ν���������׼����ʮ���ơ�
////ͬʱ��Ҫ���ַ���ת��Ϊ���͡�
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
//	printf("ͨ��ת����Ϊ��%u\n", ret);//ע��˴�һ��Ҫ��%u��ʾ�޷���
//	system("pause");
//	return 0;
//}

////2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
////˼·�����ƾ��൱�ڳ�2
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num1 = 0;
//	int num2 = 0;
//	printf("��������������\n");
//	scanf("%d %d", &num1, &num2);
//	printf("��������ƽ����Ϊ��%d\n", (num1 + num2) >> 1);
//	system("pause");
//	return 0;
//}


////3.���ʵ�֣�
////һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
////���ҳ�������֡���ʹ��λ���㣩
////˼·����һ�������в�ͬ����һ�������������������1����������������ÿ��Ԫ�ؽ������
////�ı����Ϳ��Եõ�ֻ����һ�ε��Ǹ�����
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = { 1,1,2,2,5,5,7,7,8,8,12,3,3 };
//	int i = 0;
//	for (i = 1; i < sizeof(arr)/sizeof(arr[0]); i++) {
//		arr[0] = arr[0] ^ arr[i];//�벻���Լ���ÿһ��Ԫ�ؽ������
//	}
//	printf("the signal number is:%d\n", arr[0]);
//	system("pause");
//	return 0;
//}


////4.
////��һ���ַ����������Ϊ:"student a am i",
////	���㽫��������ݸ�Ϊ"i am a student".
////	Ҫ��
////	����ʹ�ÿ⺯����
////	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
////
////	student a am i
////	i ma a tneduts
////	i am a student
////˼·���Ƚ�����������������β������Ȼ���ٽ��õ���������ÿһ�����ʽ�����β���������
////����ͨ��'\0'�����ж�һ�����ʵĳ���
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
//	//��������
//	int len = strlen(arr);
//	swap(arr, arr + len - 1);
//	//ÿ�����ʵ�����
//	while (*arr != '\0') {//����������˵����û�е����һ��λ��
//		char* start = arr;//������ʼλ��
//		char* end = start;//���ʽ���λ��
//		while ((*end != '\0') && (*end != ' ')) {
//			end++;//endָ��ո�λ�õĵ�ַ
//		}
//		//���ʵ���ʼλ��Ϊstart,����λ��Ϊendǰһ��
//		swap(start, end - 1);
//		if (*end != '\0') {
//			//������һ�����ʵ�ʱ����һ�����ʵ���ʼΪ�ո�ĺ�һ���ַ�
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
//	printf("������һ������\n");
//	scanf("%d", &num);
//	for (int i = 1; i <= 5; i++){//ѭ��������ʾ�м��� 
//		sum = num + sum * 10;//ÿ�εõ��Ķ���û�и�λ����
//	    sn += sum;
//	    printf("ÿһ��=%d\n", sum);
//	}
//	printf("sn=%d\n", sn);
//	system("pause");
//	return 0;
//}
