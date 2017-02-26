
public class LinkedList
{
	Node header=new Node();
	Node trailer=new Node();
	
	public LinkedList()
	{
		this.header.setNext(this.trailer);
		this.trailer.setPrev(this.header);
	}
	
	public void set(Node p, Object element)
	{
		/*
		Node node=header.getNext();
		
		while(node!=trailer)
		{
			if(((Entry)node.getElement()).getKey()==((Entry)element).getKey())
			{
				node.setElement(element);
			}
				
		}
		*/
		
		Node node=header.getNext();
		
		while(node!=trailer)
		{
			if(node.equals(p))
			{
				node.setElement(null);
				node.setElement(element);
				return;
			}
			
			node=node.getNext();
		}
	}
	
	public void addLast(Object element)
	{
		Node node=new Node(trailer.getPrev(), trailer, element);
		trailer.getPrev().setNext(node);
		trailer.setPrev(node);
	}
	
	public boolean addBefore(int n, Object element)
	{
		Node temp=header.getNext();
		int index=0;
		
		while(temp!=trailer)
		{
			if(index==n)
			{
				Node node=new Node(temp.getPrev(), temp, element);
				temp.getPrev().setNext(node);
				temp.setPrev(node);
				
				return true;
			}
			
			temp=temp.getNext();
			index++;
		}
		
		return false;
	}
	
	public boolean remove(Node p)
	{
		Node temp=this.header.getNext();
		
		while(temp!=trailer)
		{
			if(temp.equals(p))
			{
				temp.getNext().setPrev(temp.getPrev());
				temp.getPrev().setNext(temp.getNext());
				
				return true;
			}
			
			temp=temp.getNext();
		}
		
		return false;
	}
	
	public void printAll()
	{
		Node temp=header.getNext();
		
		while(temp!=trailer)
		{
			System.out.print(temp.getElement());
			temp=temp.getNext();
		}
		System.out.println();
	}
}
