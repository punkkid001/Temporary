/**
 * Created by Jiyoon on 2016. 3. 29..
 */
import java.util.EmptyStackException;
import java.util.Stack;

public class Main
{
    private static Stack stack=new Stack();
    private static int count=0;

    public static void main(String[] args)
    {
        count++;
        stack.push(5);
        System.out.print("Output : - Stack : ");
        viewStack();

        count++;
        stack.push(3);
        System.out.print("Output : - Stack : ");
        viewStack();

        System.out.print("Output : "+stack.pop()+" Stack : ");
        count--;
        viewStack();

        count++;
        System.out.print("Output : "+stack.push(7)+" Stack : ");
        viewStack();

        System.out.print("Output : "+stack.pop()+" Stack : ");
        count--;
        viewStack();

        System.out.print("Output : "+stack.pop()+" Stack : ");
        count--;
        viewStack();

        try {
            System.out.print("Output : " + stack.pop() + " Stack : ");
        }
        catch (EmptyStackException e) {
            System.out.print("Output : error Stack : ");
            viewStack();
        }


        System.out.print("Output : "+stack.isEmpty());

    }

    public static void viewStack()
    {
        System.out.print("(");
        for(int i=0;i<count;i++)
            System.out.print(stack.get(i)+" ");
        System.out.print(")");
        System.out.println();
    }
}

