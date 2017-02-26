/**
 * Created by Jiyoon on 2016. 3. 22..
 */
public class Stack
{
    private int number[];
    private int index;

    public Stack()
    {
        number=new int[100];
        index=-1;
        System.out.println("Stack initialization.");
    }

    public void push(int data)
    {
        if(index>=100)
            System.out.println("Stack is Full");
        else
        {
            this.number[++index] = data;
            System.out.println("(" + index + ", " + data + ")");
        }
    }

    public int pop()
    {
        if(index<0)
        {
            System.out.println("Stack is Empty.");
            return 0;
        }

        else
        {
            System.out.println("("+this.number[index]+")");
            return this.number[index--];
        }
    }

    public void top()
    {
        System.out.println("Stack Top : "+this.number[index]);
    }
}