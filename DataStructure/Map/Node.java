public class Node
{
	private Object element;
	private Node prev;
	private Node next;
	
	public Node(Node prev, Node next, Object element)
	{
		this.prev=prev;
		this.next=next;
		this.element=element;
	}
	
	public Node(Object element)
	{
		this.element = element;
		this.prev = null;
		this.next = null;
	}
	
	public Node()
	{
		this.prev=null;
		this.next=null;
		this.element="void";
	}

	public void setPrev(Node node) {this.prev=node;}
	public void setNext(Node node) {this.next = node;}

	public void printElement() {System.out.println(this.element);}

	public Object getElement() {return this.element;}
	public Node getPrev() {return this.prev;}
	public Node getNext() {return this.next;}
	
	public void setElement(Object obj) {this.element = obj;}
}
