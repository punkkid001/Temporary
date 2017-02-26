import java.util.Scanner;

public class Game
{
    Scanner input=new Scanner(System.in);
    String select;
    int size[][];
    int turn;
    int x_actor, y_actor;
    int p1_x, p1_y, p2_x, p2_y;

    //Constructor
    public Game(int x, int y, int t)
    {
        size=new int[x][y];
        turn=t;

        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                size[i][j]=0;
        }

        x_actor=x;
        y_actor=y;
    }

    public void game_core()
    {
       // AI ai=new AI(x_actor,y_actor);
        while(true)
        {
            if(turn==1)
            {
                while (true) {
                    System.out.print("Player 1's turn : ");
                    p1_x = input.nextInt();
                    p1_y = input.nextInt();

                    if (user_checker(p1_x, p1_y, 1) == 2)
                        break;
                }
                board_printer();
                if (judge(1) == 1) {
                    System.out.println("Player 1 is winner!");
                    break;
                }
                if (draw() == 1) {
                    System.out.println("Draw!");
                    break;
                }
                turn+=1;
            }
            else {
                while (true) {
                    System.out.print("Player 2's turn :");
                    p2_x = input.nextInt();
                    p2_y = input.nextInt();
                    /*
                    p2_x = ai.setNumber();
                    p2_y = ai.setNumber();
                    */

                    if (user_checker(p2_x, p2_y, 2) == 2)
                        break;
                }
                board_printer();
                if (judge(2) == 1) {
                    System.out.println("Player 2 is winner!");
                    break;
                }
                if (draw() == 1) {
                    System.out.println("Draw!");
                    break;
                }
                turn-=1;
            }
        }

    }


    public int draw()
    {
        int i, j;
        int num=0;

        for(i=0;i<x_actor;i++)
        {
            for(j=0;j<y_actor;j++)
            {
                if(size[i][j]!=0)
                {
                    num++;
                }
            }
        }

        if(num==(x_actor*y_actor))
            return 1;   //draw
        else
            return 2;   //pass
    }
    //Judging win
    public int judge(int num)
    {
        int i, j;
        int access_number=0;
        int fi_number=0;    //number '1' is win, but number '0' is pass ..

        for(i=0;i<x_actor;i++)
        {
            //width
            for (j = 0; j < y_actor; j++)
            {
                if (size[i][j] == num)
                    access_number++;
            }
            if (access_number == x_actor)
            {
                fi_number = 1;
                break;
            }
            access_number = 0;

            //height
            for (j =0;j<y_actor;j++)
            {
                if (size[j][i] == num)
                    access_number++;
            }
            if (access_number == x_actor)
            {
                fi_number = 1;
                break;
            }
            access_number = 0;
        }

        if(fi_number!=1)
        {
            i = 0;
            j = 0;
            access_number = 0;

            //left diagonal
            while (i < x_actor && j < y_actor) {
                if (size[i][j] == num)
                    access_number++;
                i++;
                j++;
            }
            if (access_number == x_actor)
                fi_number = 1;
        }

        if(fi_number!=1)
        {
            i = 0;
            j = y_actor - 1;
            access_number = 0;

            //right diagonal
            while (i < x_actor && j >= 0)
            {
                if (size[i][j] == num)
                    access_number++;
                i++;
                j--;
            }
            if (access_number == x_actor)
                fi_number = 1;
        }

        return fi_number;
    }

    //Printing Game Board
    public void board_printer()
    {
        int i, j;

        System.out.println("****Board Status****");

        for(i=0;i<x_actor;i++)
        {
            for(j=0;j<y_actor;j++)
            {
                System.out.print(size[i][j]+" ");
            }
            System.out.println();
        }
    }

    //Checking users choice
    public int user_checker(int x, int y, int user_code)
    {
        int setting_num;
        //return number '1' is error, but '2' is ok.

        if(x>=x_actor||y>=y_actor)
        {
            System.out.println("Your input is wrong!");
            setting_num=1;
        }
        else if(size[x][y]!=0)
        {
            System.out.println("This place can't setting your number.");
            setting_num=1;
        }
        else
        {
            size[x][y] = user_code;
            setting_num=2;
        }

        return setting_num;
    }

    //Asking quit game
    public int quit_game()
    {
        System.out.print("Do yo want to replay this game? (Yes/No) : ");
        select=input.next();

        if(select.equals("Yes"))
            return 1;
        else
            return 2;
    }
}
