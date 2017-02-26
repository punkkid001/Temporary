public class Node
{
	private Object data;
	private Node left;
	private Node right;
	private Node parent;
	
	public Node(Object data, Node parent)
	{
		this.data=data;
		this.parent=parent;
		left=null;
		right=null;
	}
	
	public void addLeftChild(Object data)
	{
		Node temp=new Node(data, this);
		left=temp;
	}
	
	public void addRightChild(Object data)
	{
		Node temp=new Node(data, this);
		right=temp;
	}
	
	public void printData()
	{
		System.out.println(data);
	}
	
	public Object getData()
	{
		return data;
	}
	
	public Node getLeftChild()
	{
		return left;
	}
	
	public Node getRightChild()
	{
		return right;
	}
}