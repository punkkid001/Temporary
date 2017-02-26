/**
 * Created by Jiyoon on 2016. 3. 29..
 */
import java.util.Queue;
import java.util.LinkedList;

public class Main
{
    private static Queue q=new LinkedList();

    public static void main(String[] args)
    {
        q.offer(5);
        System.out.println("Output : - Front : "+q.peek());
        q.offer(3);
        System.out.println("Output : - Front : "+q.peek());
        System.out.println("Output : "+q.poll()+" Front : "+q.peek());
        q.offer(7);
        System.out.println("Output : - Front : "+q.peek());
        System.out.println("Output : "+q.poll()+" Front : "+q.peek());

        if(q.poll()==null)
            System.out.println("Output : error");

        System.out.println("Output : "+q.isEmpty());
    }
}
