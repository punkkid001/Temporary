import java.util.Scanner;

public class main
{
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);
        String select;
        int x, y;
        int turn;


        System.out.print("Do you want to play a game? (Yes/No) : ");
        select = input.next();
        while(true)
        {
            if (select.equals("Yes"))
            {
                System.out.print("Please input game board's array size (n) : ");
                x=input.nextInt();
                y=x;

                System.out.print("Who is the first player? (1/2) : ");
                turn=input.nextInt();

                Game game=new Game(x, y, turn);
                game.game_core();

                if(game.quit_game()==2)
                {
                    break;
                }
            }

            else
            {
                break;
            }
        }

        System.out.println("Exit ..");
    }
}
