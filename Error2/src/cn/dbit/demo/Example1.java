package cn.dbit.demo;

public class Example1 {
	public static void main(String[] args){
		int num=8461;
		int gewei=num%10;
		int shiwei=num/10%10;
		int baiwei=num/100%10;
		int qianwei=num/1000;
		System.out.println("数字："+num);
		System.out.println("千位数是："+qianwei);
		System.out.println("百位数是："+baiwei);
		System.out.println("十位数是："+shiwei);
		System.out.println("个位数是："+gewei);
	}
}
