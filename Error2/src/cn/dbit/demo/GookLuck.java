package cn.dbit.demo;

import java.util.Scanner;

public class GookLuck {
	public static void main(String[] args) {
		int custNo; // 客户会员号（说明：customer---客户）
		
		// 输入会员卡号
		System.out.println("请输入4位会员卡号：");
		Scanner input = new Scanner(System.in);
		custNo = input.nextInt();
		
		// 获得每位数字
		int gewei = custNo % 10; // 分解获得个位数
		int shiwei = custNo / 10 % 10; // 分解获得十位数
		int baiwei = custNo / 100 % 10; // 分解获得百位数
		int qianwei = custNo / 1000; // 分解获得千位数
		
		// 计算数字之和
		int sum = gewei + shiwei + baiwei + qianwei;
		System.out.println("会员卡号" + custNo + "各位之和： " + sum);
	}
}
