/**
 * Created by Jiyoon on 2016. 3. 22..
 */
public class Queue
{
    private int number[];
    private int front;
    private int rear;

    public Queue()
    {
        number=new int[100];
        front=0;
        rear=-1;

        System.out.println("Queue initialization.");
    }

    public void enQueue(int data)
    {
        if(rear>=100)
            System.out.println("Queue is full.");
        else
        {
            number[++rear] = data;
            System.out.println("("+rear+", "+this.number[rear]+")");
        }
    }

    public int deQueue()
    {
        if(front>rear)
        {
            System.out.println("Queue is Empty.");
            return 0;
        }

        else
        {
            System.out.println("("+this.number[front]+")");
            return this.number[front++];
        }
    }

    public void viewQueue()
    {
        System.out.println("Queue Front : "+this.number[front]);
        System.out.println("Queue Rear : "+this.number[rear]);
    }
}