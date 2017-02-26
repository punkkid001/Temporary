package Tycoon;

import java.util.Scanner;

public class maintest 
{
	public static void main(String[] args)throws Exception
	{
		Scanner iput=new Scanner(System.in);
		Appliance test=new Appliance();
		Door ntest=new Door();
		StartEnd mtest=new StartEnd();
		int number=0;		//실행할 행동 결정
		
		char enter;		//엔터
		
		mtest.Openning();		//프로그램 시작 메시지, 대문 비밀번호 설정
		
		while(true)
		{
			System.out.println("What do you want to do?");
			System.out.println("--------------------------------------------------------");
			System.out.println("1.Open the Fride's Door       2.Get into the Bathroom");
			System.out.println("3.Get into the Room           4.Manage the Window/Gate");
			System.out.println("5.View Stat                   6.View Creator's Note");
			System.out.println("0. Quit");
			System.out.println("--------------------------------------------------------");
			
			System.out.print(">> ");
			number=iput.nextInt();
			
			if(number==1)
				test.Fridge();		//냉장고 문 열기
			else if(number==2)
				ntest.BathroomDoor();		//화장실 들어가기
			else if(number==3)
				ntest.RoomDoor();		//방에 들어가기
			else if(number==4)			//창문, 대문 관리
			{
				while(true)
				{
					System.out.println("Which door you want to manage?");
					System.out.println("1. Window");
					System.out.println("2. Gate");
					System.out.println("3. Out this menu");
					
					System.out.print(">> ");
					number=iput.nextInt();
					
					if(number==1)
						ntest.Window();		//창문 관리
					else if(number==2)
						ntest.Gate();		//대문 관리
					else if(number==3)
						break;
				}
			}
			else if(number==5)		//사용자 상태, 집의 상태 보여줌
			{
				System.out.println();
				System.out.println("------------------------------------------");
				
				System.out.println("Your cleanliness point is "+ntest.clean);
				
				if(ntest.winstat==0)
					System.out.println("Now Window is closed");
				else
					System.out.println("Now Window is opened");
				System.out.println("Your Healthy point is "+(ntest.healstat+test.status));
				
				
				if(ntest.gatestat==0)
					System.out.println("Now Gate is closed");
				else
					System.out.println("Now Gate is opened");
				
				System.out.println("------------------------------------------");
				enter=(char)System.in.read();
			}
			
			else if(number==6)
				mtest.Creator();		//제작자 목록 보여줌
			
			else if(number==0)
				break;
		}
		
		mtest.Ending();		//프로그램 종료 메시지, 만족도 점수 입력받음
	}
}
