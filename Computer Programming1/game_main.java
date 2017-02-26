import java.util.*;

public class game_main
{
 static int arr[][]=new int[3][3];
 static Scanner input=new Scanner(System.in);

 public static void main(String[] args)
 {
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    arr[i][j]=0;
   }
  }

  game_start();
 }

 public static void game_start()
 {
  int select;

   System.out.print("Do you want to play a game? (1:Yes/2:No) : ");
   select=input.nextInt();

   if(select==1)
   {
    real_game();
   }

   else if(select==2)
   {
    System.out.println("Game End...");
   }

   else
   {
    System.out.println("Wrong input.");
   }
 }

 public static void real_game()
 {
  int select;
  int user_a1, user_a2;
  int user_b1, user_b2;

  while(true)
  {
   System.out.print("User 1's turn : ");
   user_a1=input.nextInt();
   user_a2=input.nextInt();

   arr[user_a1][user_a2]=1;
   printer();

   if(god(1)==2)
   {
    System.out.println("user 1 is win!");
    break;
   }


   if(draw()==0)
   {
    System.out.print("Draw! Do you want to replay a game? (1:Yes/2:No): ");
    select=input.nextInt();

    if(select==1)
     game_start();
    else
     break;
   }

   System.out.print("User 2's turn : ");
   user_b1=input.nextInt();
   user_b2=input.nextInt();

   arr[user_b1][user_b2]=2;
   printer();

   if(god(2)==2)
   {
    System.out.println("user 2 is win!");
    break;
   }

   if(draw()==0)
   {
    System.out.print("Draw! Do you want to replay a game? (1:Yes/2:No): ");
    select=input.nextInt();

    if(select==1)
     game_start();
    else
     break;
   }
  }
 }

 public static int draw()
 {
  int i=0;
  int j=0;

  int num=0;
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
    if(arr[i][j]==0)
     num+=1;
   }
  }

  return num;
 }

 public static int god(int num)
 {
  //1=draw, 2=win? 4=pass?
  int i, j;
  int return_num=4;


  //width
  if((arr[0][0]==num)&&(arr[0][1]==num)&&(arr[0][2]==num))
  {
   return_num=2;
  }
  else if((arr[1][0]==num)&&(arr[1][1]==num)&&(arr[1][2]==num))
  {
   return_num=2;
  }
  else if((arr[2][0]==num)&&(arr[2][1]==num)&&(arr[2][2]==num))
  {
   return_num=2;
  }

  //length
  else if((arr[0][0]==num)&&(arr[1][0]==num)&&(arr[2][0]==num))
  {
   return_num=2;
  }
  else if((arr[0][1]==num)&&(arr[1][1]==num)&&(arr[2][1]==num))
  {
   return_num=2;
  }
  else if((arr[0][2]==num)&&(arr[1][2]==num)&&(arr[2][2]==num))
  {
   return_num=2;
  }

  //대각선
  else if((arr[0][0]==num)&&(arr[1][1]==num)&&(arr[2][2]==num))
  {
   return_num=2;
  }
  else if((arr[0][2]==num)&&(arr[1][1]==num)&&(arr[2][0]==num))
  {
   return_num=2;
  }

  else
   return_num=4;


  return return_num;
 }


 public static void printer()
 {
  int i, j;

  System.out.println("***Status***");
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
    System.out.print(arr[i][j]+" ");
   }
   System.out.println();
  }
 }
}
