/**
 * Created by Jiyoon on 2016. 3. 22..
 */
import java.util.Scanner;

public class HanoiwithStack
{
    private Stack[] stack = new Stack[3];
    private Scanner scanner = new Scanner(System.in);
    private int disk;
    private int count = 0;

    public HanoiwithStack()
    {
        for(int i=0; i<stack.length; i++)
            stack[i] = new Stack();

        System.out.print("Number of disk : ");
        disk = scanner.nextInt();

        for(int i=0; i<disk; i++)
            stack[0].push(disk-i);

        letHanoi(disk, 0, 1, 2);
        System.out.println("Number of movement :"+count);
    }

    private void letHanoi(int n_disk, int start, int middle, int end)
    {
        if(n_disk == 1)
        {
            letMove(start, end);
            return;
        }

        letHanoi(n_disk-1, start, end, middle);
        letMove(start, end);
        letHanoi(n_disk-1, middle, start, end);
    }

    private void letMove(int from, int to)
    {
        int value = stack[from].pop();
        stack[to].push(value);

        count++;

        System.out.println("**************");
        System.out.println("from "+from+" to "+to+" : "+value);

        for(int i=0; i<stack.length; i++)
        {
            try
            {
                System.out.println("stack "+(i+1)+" : "+stack[i].top());
            }
            catch (IllegalStateException e)
            {
                System.out.println("stack "+(i+1)+" : 0");
            }
        }
        System.out.println();
    }
}
