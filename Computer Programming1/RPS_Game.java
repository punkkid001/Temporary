import java.util.*;

public class RPS_Game
{
 static int user_medal=0; //(global variable) save a user's total medal

 public static void main(String[] args)
 {
  Scanner input=new Scanner(System.in);

  String yn; //continue to game or not

  while(true)
  {
   System.out.print("Do you want to play New game? (Yes/No) : ");
   yn=input.next();

   if(yn.equals("Yes"))
   {
    game();
   }

   else if(yn.equals("No"))
   {
    System.out.println("*****End game*****");
    System.out.println("Your total medal is "+user_medal);
    break;
   }

   else
   {
    System.out.println("Please re-type the answer.");
   }
  }
 }

 //Method of game
 public static void game()
 {
  Scanner input=new Scanner(System.in);
  Random rand = new Random();
  int user_choice; //user's choice
  int bot_choice; //computer's choice

  while(true)
  {
   System.out.println("1. Scissor / 2. Rock / 3. Paper");
   System.out.print("What is your choice ? : ");
   user_choice=input.nextInt();

   bot_choice=rand.nextInt(3)+1;

   //draw
   if(bot_choice==user_choice)
   {
    System.out.println("Computer's choice: "+bot_choice);
    System.out.println("Drew!");
   }

   //If user's choice is Scissor..
   else if(user_choice==1)
   {
    if(bot_choice==2) //Rock
    {
     System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Lose");
    }

    //WIN - Paper
    else
    {
     System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Won!");
     System.out.println(total_medal()+" medal is yours! ");
    }
    break;
   }

   //If user's choice is Rock..
   else if(user_choice==2)
   {
    //WIN - Scissor
    if(bot_choice==1)
    {
     System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Won!");
     System.out.println(total_medal()+" medal is yours! ");
    }

    else  //Paper
    {
      System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Lose!");
    }
    break;
   }

   //If user's choice is Paper..
   else if(user_choice==3)
   {
    if(bot_choice==1) //Scissor
    {
     System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Lose!");
    }

    //WIN - Rock
    else
    {
     System.out.println("Computer's choice: "+bot_choice);
     System.out.println("Won!");
     System.out.println(total_medal()+" medal is yours! ");
    }
    break;
   }

   //Wrong input
   else
   {
    System.out.println("Please re-type the value.");
   }
  }
 }

 //method of the return medal amount
 public static int total_medal()
 {
  Random rand = new Random();
  int medal_list[]={20, 10, 5, 0}; //0 is blank
  int bot_medal=medal_list[rand.nextInt(4)];
  user_medal+=bot_medal;
  return bot_medal;
 }
}
