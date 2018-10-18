package cn.dbit.demo;

import java.util.Scanner;

public class CalcSalary {
	public static void main(String[] args) {
		int base;     		 //基本工资
        double ga;           //物价津贴
        double hra;          //房屋津贴
        double salary;       //薪水
        
        System.out.println("请输入基本工资：");
        Scanner input = new Scanner(System.in);
        base = input.nextInt();
        
        ga = base * 40 / 100;
        hra = base * 25 /100;
        salary = base + ga + hra; 
        
        /*输出工资细目*/
        System.out.println("该员工的工资细目为： ");
        System.out.println("基本工资为： " + base);
        System.out.println("物价津贴为： " + ga);
        System.out.println("房租津贴为： " + hra);
        System.out.println("员工薪水是： " + salary);
}
}
