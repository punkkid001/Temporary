public class LinkedList
{
	Node header=new Node();
	Node trailer=new Node();
	
	public LinkedList()
	{
		header.setNext(trailer);
		trailer.setPrev(header);
	}
	
	public void addLast(String value)
	{
		Node nodeNew=new Node(trailer.getPrev(),trailer, value);
		
		trailer.getPrev().setNext(nodeNew);
		trailer.setPrev(nodeNew);
	}
	
	public void printAllNodes()
	{
		Node temp=header.getNext();
		
		while(temp!=trailer)
		{
			System.out.print(temp.getString());
			temp=temp.getNext();
		}
		System.out.println();
	}
	
	public boolean addBefore(int n, String value)
	{
		Node temp=header.getNext();
		int index=0;
		
		while(temp!=trailer)
		{
			if(index==n)
			{
				Node nodeNew=new Node(temp.getPrev(),temp, value);
				temp.getPrev().setNext(nodeNew);
				temp.setPrev(nodeNew);
				
				return true; 
			}
			temp=temp.getNext();
			index++;
		}
		
		return false;
	}
}
