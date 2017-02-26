public class Node
{
	private String str;
	private Node prev;
	private Node next;
	
	public Node()
	{
		prev=null;
		next=null;
		str="void";
	}
	
	public Node(Node prev, Node next, String str)
	{
		this.prev=prev;
		this.next=next;
		this.str=str;
	}
	
	public void setPrev(Node p)
	{
		prev=p;
	}
	
	public void setNext(Node n)
	{
		next=n;
	}
	
	public Node getPrev()
	{
		return prev;
	}
	
	public Node getNext()
	{
		return next;
	}
	
	public String getString()
	{
		return str;
	}
	
}
