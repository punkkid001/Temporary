/**
 * Created by Jiyoon on 2016. 3. 22..
 */
public class Main
{
    public static void main(String[] args)
    {
        Queue q=new Queue();
        q.deQueue();
        q.enQueue(10);
        q.enQueue(20);
        q.enQueue(30);
        q.deQueue();
        q.viewQueue();
    }
}
