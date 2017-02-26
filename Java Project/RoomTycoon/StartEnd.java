package Tycoon;
import java.util.Scanner;
import java.io.*;

public class StartEnd
{
	Scanner input=new Scanner(System.in);
	public static int pass;		//대문 비밀번호
	char ent;		//엔터
	
	public void Openning()throws Exception		//프로그램 시작시 대문 비밀번호 설정과 함께 프로그램 시작 메시지 보여줌
	{
		System.out.println("-----Welcome to the JAVA's Room Tycoon-----");
		System.out.print("Please input your New 'Gate Passcode' : ");
		pass=input.nextInt();
		
		System.out.println("Nice! Your passcode setting is success!");
		System.out.println("----------------------Have a good time!");
		ent=(char)System.in.read();
	}
	
	public void Ending()		//프로그램 종료시 만족도 점수 입력 받고, 종료 메시지 보여줌
	{
		int satisfy;	//만족도 점수 입력
		
		System.out.println();
		
		System.out.println("Do you like this program?");
		System.out.print("Please input enjoy score : ");
		satisfy=input.nextInt();
		System.out.println("Thank You.");
	}
	
	public void Creator()throws Exception		//제작자 목록
	{
		System.out.println("-----------------CREATORS----------------");
		System.out.println("Coding : Sanghee/Jiyoon");
		System.out.println("Main code : Jiyoon");
		System.out.println("PT : Sanghee");
		System.out.println("-----------------------------------------");
		
		ent=(char)System.in.read();
	}
}
