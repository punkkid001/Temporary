/**
 * Created by Jiyoon on 2016. 4. 9..
 */
public class Node
{
    private String str;
    private Node prev;
    private Node next;

    //constructor
    public Node()
    {
        this.str="void";
        this.prev=null;
        this.next=null;
    }

    //constructor overloading
    public Node(Node p, Node n, String s)
    {
        this.str=s;
        this.prev=p;
        this.next=n;
    }

    public void setPrev(Node p)
    {
        this.prev=p;
    }

    public void setNext(Node n)
    {
        this.next=n;
    }

    public void setStr(String value)
    {
        this.str=value;
    }

    public Node getPrev()
    {
        return this.prev;
    }

    public Node getNext()
    {
        return this.next;
    }
    
    //added method
    public String getStr()
    {
        return this.str;
    }
}