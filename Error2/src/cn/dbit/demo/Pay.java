package cn.dbit.demo;

public class Pay {
	public static void main(String[] args){
		int shirtPrice=245;
		int shoePrice=570;
		int padPrice=320;
		int shirtNo=1;
		int shoeNo=1;
		int padNo=1;
		double discount=0.8;
		double finalPay=((shirtPrice*shirtNo+shoePrice*shoeNo+padPrice*padNo)*discount);
		System.out.println("消费总金额："+finalPay);
		double returnMoney=1500-finalPay;
		System.out.println("*******消费单*******");
		System.out.println("购物品\t"+"单价\t"+"个数\t"+"金额\t");
		System.out.println("Ｔ恤\t" + "￥"+shirtPrice+ "\t"  + shirtNo+ "\t" + "￥"+(shirtPrice * shirtNo)+"\t");
		System.out.println("网球鞋\t" + "￥"+shoePrice + "\t"+ shoeNo+ "\t" + "￥"+(shoePrice * shoeNo)+ "\t");
		System.out.println("网球拍\t" + "￥"+padPrice + "\t"+ padNo+ "\t" + "￥"+(padPrice * padNo)+ "\t\n");
		System.out.println("折扣：\t8折");
		System.out.println("消费总金额\t" + "￥" + finalPay);
		System.out.println("实际交费\t￥1500");
		System.out.println("找钱\t" + "￥" + returnMoney);


		int score =  (int)finalPay / 100 * 3;
	    System.out.println("本次购物所获的积分是： " + score);
		
		
		
	}
}
