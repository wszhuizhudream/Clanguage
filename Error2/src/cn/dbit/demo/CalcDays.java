package cn.dbit.demo;

public class CalcDays {
public static void main(String[] args){
	int days=46;
	int week=days/7;
	int leftDay=days%7;
	System.out.println(days+"天等于"+week+"周零"+leftDay+"天");
}
}
