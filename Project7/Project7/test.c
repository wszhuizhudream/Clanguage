//1. дһ���������ز����������� 1 �ĸ������磺 15 0000 1111 4 �� 1����ԭ�ͣ�
////����1��
////˼·��ͨ��ģ2�ж�1�ĸ���(��ȱ�ݣ�ֻ�ܶ����������ж�)
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int num = 0;
//	printf("������һ�������õ�������������1�ĸ���:\n");
//	scanf("%d", &num);
//	int count = 0;
//	while (num) {
//		if (num % 2 == 1) {
//			count++;
//		}
//		num = num / 2;
//	}
//	printf("1�ĸ���Ϊ��%d\n", count);
//	system("pause");
//	return 0;
//}

////����2��
////˼·�����������������4���ֽڣ��ܹ�32λ�������32λһ�ν����жϣ�
////Ϊ1���1�����Զ��������жϣ�
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
//		printf("1�ĸ���Ϊ��%d\n", count);
//		system("pause");
//		return 0;
//	}
//}

////2.��ȡһ�������������������е�ż��λ������λ�� �ֱ�������������С�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr1[16] = { 0 };//��Ŷ�����ż������
//	int arr2[16] = { 0 };//��Ŷ�������������
//	printf("������һ�����֣�\n");
//	scanf("%d", &num);
//	for (i = 0, j = 0; j < 32; ++i, j += 2) {
//		arr1[15 - j / 2] = (num >> j) & 1;//ͨ����λ��õ�ż��λԭ����
                                         //���֣����������С�
//		arr2[15 - i] = (num >> (2 * i + 1)) & 1;//ͨ����λ��õ�����λ
                                               //ԭ�������֣����������С�
//	}
//	printf("%d��Ӧ�Ķ���������ż��λ�ֱ��ǣ�\n", num);
//	for (i = 0; i < 16; i++) {
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	printf("%d��Ӧ�Ķ�������������λ�ֱ��ǣ�\n", num);
//	for (i = 0; i < 16; i++) {
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////3. ���һ��������ÿһλ�� 
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int i = 0;
//	int num = 0;
//	int arr[32] = { 0 };
//	printf("������һ������\n");
//	scanf("%d", &num);
//	for (i = 0; i < 32; i++) {
//		arr[31 - i] = (num >> i) & 1;
//	}
//	printf("%d��Ӧ�Ķ�������Ϊ:\n",num);
//	for (i = 0; i < 32; i++) {
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

////4.���ʵ�֣� 
////����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
////�������� :
////1999 2299
////������� :7
////˼·���Ƚ�m��n�İ�λ�����һ����ʱ�����Ȼ���ٶ������ʱ������
////���ٸ�1���м��������õ�1�ĸ�����Ϊ��ͬ��bitλ
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int m = 0;
//	int n = 0;
//	int temp = 0;
//	int count = 0;
//	printf("��������������\n");
//	scanf("%d %d", &m, &n);
//	temp = m ^ n;
//	for (int i = 0; i < 32; i++) {
//		if (((temp >> i) & 1))
//			count++;
//	}
//	printf("�ܹ��в�ͬ��bitλ:%d\n", count);
//	system("pause");
//	return 0;
//}