/**
 * Created by Jiyoon on 2016. 4. 9..
 */
public class LinkedList
{
    Node header=new Node();
    Node trailer=new Node();

    public LinkedList()
    {
        this.header.setNext(trailer);
        this.trailer.setPrev(header);
    }

    public void addLast(String value)
    {
        Node newNode=new Node(trailer.getPrev(), trailer, value);
        trailer.getPrev().setNext(newNode);
        trailer.setPrev(newNode);
    }

    public boolean addBefore(int n, String value)
    {
        Node temp=header.getNext();
        int index=0;

        while(temp!=trailer)
        {
            if(index==n)
            {
                Node newNode=new Node(temp.getPrev(), temp, value);
                temp.getPrev().setNext(newNode);
                temp.setPrev(newNode);

                return true;
            }

            temp=temp.getNext();
            index++;
        }
        return false;
    }
    
    //addBefore method overloading
    public boolean addBefore(String pt, String value)
    {
        Node temp=header.getNext();

        while(temp!=trailer)
        {
            if(pt.equals(temp.getStr()))
            {
                Node newNode=new Node(temp.getPrev(), temp, value);
                temp.getPrev().setNext(newNode);
                temp.setPrev(newNode);

                return true;
            }

            temp=temp.getNext();
        }

        return false;
    }

    public boolean addAfter(String pt, String value)
    {
        Node temp=header.getNext();
        String p=temp.getStr();

        while(temp!=trailer)
        {
            if(p.equals(pt))
            {
                Node newNode=new Node(temp, temp.getNext(), value);
                temp.getNext().setPrev(newNode);
                temp.setNext(newNode);

                return true;
            }

            temp=temp.getNext();
            p=temp.getStr();
        }
        return false;
    }
 
    public boolean setCharacter(String pt, String value)
    {
        Node temp=header.getNext();

        while(temp!=trailer)
        {
            if(pt.equals(temp.getStr()))
            {
                temp.setStr(value);
                return true;
            }
            temp=temp.getNext();
        }
        return false;
    }

    //prev - temp - next => prev - next : delete temp node
    public boolean remove(String value)
    {
        Node temp=header.getNext();

        while(temp!=trailer)
        {
            if(value.equals(temp.getStr()))
            {
                temp.getPrev().setNext(temp.getNext());
                temp.getNext().setPrev(temp.getPrev());

                return true;
            }

            temp=temp.getNext();
        }
        return false;
    }

    public void printAllNodes()
    {
        Node temp=header.getNext();

        while(temp!=trailer)
        {
            System.out.print(temp.getStr());
            temp=temp.getNext();
        }
        System.out.println();
    }

    //trailer to header : print reverse
    public void printRev()
    {
        Node temp=trailer.getPrev();

        while(temp!=header)
        {
            System.out.print(temp.getStr());
            temp=temp.getPrev();
        }
        System.out.println();
    }
    
    //find : return index,  can't find : return -1
    public int searchNode(String value)
    {
        Node temp=header.getNext();
        int index=0;

        while(temp!=trailer)
        {
            if(value.equals(temp.getStr()))
            {
                System.out.println("Find!");
                return index;
            }

            temp=temp.getNext();
            index++;
        }

        System.out.println("Can't Find!");
        return -1;
    }
}