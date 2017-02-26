package Tycoon;

import java.util.Scanner;
import java.io.*;
import java.util.*;

public class Appliance {
	
	char YorN;
	Scanner input=new Scanner(System.in);
	int select;
	int status=0;	//fridge()
	char ent;
	
	public void TV()throws Exception
	{
		int Cnumber;
		
		System.out.print("Do you want to watch TV? (Y/N) : ");
		YorN=(char)System.in.read();
		
		if(YorN=='Y')
		{
			System.out.println("-------JAVA TV------");
			while(true)
			{
				System.out.println("Available Channel is 1~4");
				System.out.print("Input Channel Number that you want to watch (0 is Off) : ");
				Cnumber=input.nextInt();
				
				if(Cnumber==1)
				{
					System.out.println("-----News Channel!-----");
					System.out.println();
					System.out.println("Hello every body! What a nice day!");
					System.out.println("Today's shocking news is ...~~&@(*!~&~");
					ent=(char)System.in.read();
				}
				
				else if(Cnumber==2)
				{
					System.out.println("-----Kids Channel!-----");
					System.out.println();
					System.out.println("Ppolong pplong pplong ppo lo lo!");
					System.out.println("My name is Co Co mong");
					System.out.println("ggo ma bus Tayo ~!@#$*");
					System.out.println();
					ent=(char)System.in.read();
				}
				
				else if(Cnumber==3)
				{
					System.out.println("-----Stock Channel!------");
					System.out.println();
					System.out.println("LG Display's stock is increasing!");
					System.out.println("I want to buy LG Display stock.. hahaha");
					System.out.println();
					ent=(char)System.in.read();
				}
				
				else if(Cnumber==4)
				{
					System.out.println("-----Home Shopping Channel!-----");
					System.out.println();
					System.out.println("Oh my! This Cosmatics Package is so nice!");
					System.out.println("So beautiful! This model's face looks so good!");
					System.out.println("Please call us! 080 - 1234 -5678 ~ $@#$&*");
					System.out.println();
					ent=(char)System.in.read();
				}
				
				else if(Cnumber==0)
				{
					System.out.println("TV Off...");
					System.out.println();
					break;
				}
				else
				{
					System.out.println();
					System.out.println("<ERROR!>");
					System.out.println("This number is not available.");
					ent=(char)System.in.read();
				}
			}
		}
		
		else
			System.out.println("TV Off...");
	}
	
	public void PC()throws Exception
	{
		Calendar calendar=new GregorianCalendar(Locale.KOREA);
		int cyear=calendar.get(Calendar.YEAR);
		int cmonth=calendar.get(Calendar.MONTH)+1;
		int cday=calendar.get(Calendar.DAY_OF_MONTH);
		//I used this code that comes from Internet!
		
		System.out.print("Do you want to turn on PC Power? (Y/N) : ");
		YorN=(char)System.in.read();
		
		if(YorN=='Y')
		{
			System.out.println();
			System.out.println("Power On!");
			
			while(true)
			{
				System.out.println("What do you want to do?");
				System.out.println("------------------------------ ---");
				System.out.println("1.Internet           2. Game");
				System.out.println("3. Power Off");
				System.out.println("----------------------------------");
				
				System.out.print(">> ");
				select=input.nextInt();
				
				if(select==1)
				{
					System.out.println("----Internet----");
					System.out.println("Today is : "+cyear+"-"+cmonth+"-"+cday);
					
					while(true)
					{
						System.out.println("What do you want to do?");
						System.out.println("-------------------------------------------------------");
						System.out.println("1.Read 'Amaziong News      2.View Ads");
						System.out.println("3. View Top search word    4.Out this Internet World");
						System.out.println("-------------------------------------------------------");
						
						System.out.print(">> ");
						select=input.nextInt();

						if(select==1)
						{
							System.out.println("<Amazing News : Human's body wants to dringking Water>");
							System.out.println();
							System.out.println("As you know, Water is needed for healthy.");
							System.out.println("The more drinking water, The more good for you!");
							System.out.println("Let's Drink!");
							System.out.println();
							System.out.println("2014.6.6 Kim Bang gu (bangKim@gmail.com)");
							System.out.println("----------------------------");
							
							ent=(char)System.in.read();
						}
							
						else if(select==2)
						{
							System.out.println();
							System.out.println("<BIG NEWS! YOU CAN GET 100MILION DOLLORS!>");
							System.out.println();
							System.out.println("We're a 'SuperStar K-POP'. If you want to show your talent, Please Call us.");
							System.out.println("The call number is 82-10-3334-2223 !");
							System.out.println("Our show's winner can get 100Milion Dollors!");
							System.out.println("You can be a star! You can do it!");
							
							ent=(char)System.in.read();
						}
						
						else if(select==3)
						{
							System.out.println("Choose a word that you want to search.");
							System.out.println("----------------------------------------");
							System.out.println("1. 1st :           2. 2nd : ");
							System.out.println("3. 3rd : ");
							System.out.println("Another number is 'OUT' this page.");
							System.out.println("----------------------------------------");
							
							System.out.print(">> ");
							select=input.nextInt();
							
							if(select==1)
							{
								System.out.println("Recently, ");
								ent=(char)System.in.read();
							}
							
							else if(select==2)
							{
								System.out.println("This is new.. ");
								ent=(char)System.in.read();
							}
							
							else if(select==3)
							{
								System.out.println("Today, there is ");
								ent=(char)System.in.read();
							}
							
							else
								System.out.println();
						}
						
						else
						{
							System.out.println("Service OFF...");
							System.out.println();
							
							break;
						}
					}
				}
				
			else if(select==2)
			{
				int point=0;
				int answer;
				
				System.out.println("<Welcome to the Quiz Game!>");
				System.out.println("Your Point is .. : "+point);
				System.out.println();
				System.out.println("------Start------");
				System.out.print("1: 2*45+1-30=?");
				answer=input.nextInt();
				
				point=(answer==61)?(point+=1):(point-=1);
					
				System.out.print("2: 11+3*24+1*2=?");
				answer=input.nextInt();
				
				point=(answer==85)?(point+=1):(point-=1);
				
				System.out.print("3: 128>>2 =?");
				answer=input.nextInt();
					
				point=(answer==32)?(point+=1):(point-=1);
				
				System.out.println("Your Point is .. : "+point);
				ent=(char)System.in.read();
			}
			
				else
				{
					System.out.println("Power off .. ");
					break;
				}
			}
		}
	}
	
	public void Fridge()throws Exception
	{
		System.out.println("What do you want to do?");
		
		while(true)
		{
			System.out.println("Your Satiety is .. : "+status);
			
			System.out.println("----------------------------------------------------");
			System.out.println("1.Eat a Three-minute Cury    2.Drinking Water");
			System.out.println("3.Eat a Snack                4.Eat a Ramen");
			System.out.println("5.Close the Fridge's Door");
			System.out.println("----------------------------------------------------");
			
			System.out.print(">> ");
			select=input.nextInt();
			
			if(select==1)
			{
				System.out.println();
				System.out.println("Hmm.. Taste good.. (your satiety is increased.)");
				status+=5;
				ent=(char)System.in.read();
			}
			
			else if(select==2)
			{
				System.out.println();
				System.out.println("Wow! Water is good for my healthy!");
				status++;
				ent=(char)System.in.read();
			}
			
			else if(select==3)
			{
				System.out.println();
				System.out.println("Choco Pie is so Delicious~");
				status+=3;
				ent=(char)System.in.read();
			}
			
			else if(select==4)
			{
				System.out.println();
				System.out.println("Ramen is so nice taste.. but Ramen's Natrium is so bad for my healthy");
				status++;
				ent=(char)System.in.read();
			}
			
			else
			{
				System.out.println("Close the Door ...");
				break;
			}
		}
	}
}
