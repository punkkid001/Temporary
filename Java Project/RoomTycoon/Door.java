package Tycoon;

import java.util.Scanner;
import java.io.*;

public class Door {
	int choose=0;
	char YorN;
	Scanner input=new Scanner(System.in);
	StartEnd passC=new StartEnd();
	
	int clean=0;	//bathroomdoor()
	int winstat=0;	//window()
	int healstat=0;	//roomdoor()
	int gatestat=0;	//gate()
	
	char ent;		//엔터
	
	public void BathroomDoor()throws Exception
	{
		System.out.println("Bathroom Door is now open");
		System.out.println("=======================================");
	
	
		while(true)
		{
			System.out.println("What do you want to do?");
			System.out.println("---------------------------------------------");
			System.out.println("1.Use a Toilet bowl     2.Start Shower");
			System.out.println("3.Wash your Face/Hand   4.Brush your teeth");
			System.out.println("5.Exit");
			System.out.println("---------------------------------------------");
			
			System.out.print(">> ");
			choose=input.nextInt();
		
			switch(choose)
			{
				case 1:
					System.out.println("Your intestine health is good (point +5)");		//장건강 좋아짐
					clean+=5;
					ent=(char)System.in.read();
					break;
				case 2:
					System.out.println("Your cleanliness point is increased (point +10)");	//청결도 상승
					clean+=10;
					ent=(char)System.in.read();
					break;
				case 3:
					System.out.println("Your lever of immunity is increased (point +3)");	//면역력 상승
					clean+=3;
					ent=(char)System.in.read();
					break;
				case 4:
					System.out.println("Now Your teeth is so clean! (point +6)");	//양치질해서 이 깨끗해짐
					clean+=6;
					ent=(char)System.in.read();
					break;
			}
		
			if(choose==5)
				break;
				
			System.out.println("-----------------------------------");
		}
	}
	
	public void Window()throws Exception
	{
		if(winstat==0)
		{
			System.out.print("Do you want to open the Window? (Y/N) :");
			YorN=(char)System.in.read();
		
			if(YorN=='Y')
				winstat=1;
		}
		
		else if(winstat==1)
		{
			System.out.println("Do you want to close the Window? (Y/N) :");
			YorN=(char)System.in.read();
			
			if(YorN=='Y')
				winstat=0;
		}
	}
	
	public void RoomDoor()throws Exception
	{
		Appliance appliance=new Appliance();
		
		System.out.println("-----You are now in your Room! (Home sweet home :D )-----");
		System.out.println();
		
		while(true)
		{
			System.out.println("What do you want to do?");
			System.out.println("-----------------------------------------");
			System.out.println("1.Play the Computer   2.Sleeping now");
			System.out.println("3.Watching TV         4.Exit");
			System.out.println("-----------------------------------------");
			
			System.out.print(">> ");
			choose=input.nextInt();
			
			if(choose==1)
			{
				appliance.PC();		//컴퓨터 사용
				healstat-=5;
			}
			
			else if(choose==2)
			{
				System.out.println("Your healthy level is increased!");
				healstat+=6;
				ent=(char)System.in.read();
			}
			
			else if(choose==3)
			{
				appliance.TV();		//tv실행
				healstat-=3;
			}
			
			else if(choose==4)
				break;
		}
	}
	
	public void Gate()throws Exception		//대문
	{
		int passcode;
		
		System.out.print("Please input your 'Gate Passcode' : ");
		passcode=input.nextInt();
		
		if(passcode==passC.pass)
		{
			if(gatestat==0)
			{
				System.out.print("Are you really open the Gate? (Y/N) :");
				YorN=(char)System.in.read();
				
				if(YorN=='Y')
					gatestat=1;
			}
			
			else if(gatestat==1)
			{
				System.out.print("Are you really close the Gate? (Y/N) :");
				YorN=(char)System.in.read();
				
				if(YorN=='Y')
					gatestat=0;
			}
		}
		
		else
			System.out.println("Error! Your 'Gate Passcode' is wrong!");
	}
}
