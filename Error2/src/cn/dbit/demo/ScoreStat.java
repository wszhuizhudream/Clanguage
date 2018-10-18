package cn.dbit.demo;

import java.util.Scanner;

public class ScoreStat {
public static void main(String[] args){
	Scanner input=new Scanner(System.in);
	System.out.print("STB的成绩是：");
	int stb=input.nextInt();
	System.out.print("Java的成绩是：");
	int java=input.nextInt();
	System.out.print("SQL的成绩是：");
	int sql=input.nextInt();
	int diffen;
	double avg;
	System.out.println("--------------");
	System.out.println("STB\tJava\tSQL");
	System.out.println(stb+"\t"+java+"\t"+sql);
	System.out.println("--------------");
	diffen=java-sql;
	System.out.println("Java和SQL的成绩差："+diffen);
	avg=(stb+java+sql)/3;
	System.out.println("3门课的平均分是："+avg);	
    }
}
