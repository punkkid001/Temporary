package chapter8;

public class Node
{
	private Object element;
	private Node left;
	private Node right;
	private Node parent;
	
	public Node(Object element, Node parent)
	{
		this.element=element;
		this.parent=parent;
		this.left=null;
		this.right=null;
	}
	
	public void addLeftChild(Object element)
	{
		Node temp=new Node(element, this);
		this.left=temp;
	}
	
	public void addLeftChild(Node t)
	{
		this.left=t;
	}
	
	public void addRightChild(Object element)
	{
		Node temp=new Node(element, this);
		this.right=temp;
	}
	
	public void addRightChild(Node t)
	{
		this.right=t;
	}
	
	public void printElement()
	{
		System.out.println(this.element);
	}
	
	public Object getElement()
	{
		return this.element;
	}
	
	public Node getParent()
	{
		return this.parent;
	}
	
	public Node getLeftChild()
	{
		return this.left;
	}
	
	public Node getRightChild()
	{
		return this.right;
	}
	
	public boolean isLeft()
	{
		if(this.left!=null)
			return true;
		else
			return false;
	}
	
	public boolean isRight()
	{
		if(this.right!=null)
			return true;
		else
			return false;
	}
	
	public boolean isLeaf()
	{
		if(isLeft()&&isRight())
			return false;
		else
			return true;
	}
	
	public void setElement(Object data)
	{
		this.element=data;
	}
	
	public void setParent(Node parent)
	{
		this.parent=parent;
	}
	
	public void setLeftChild(Node left)
	{
		this.left=left;
	}
	
	public void setRightChild(Node right)
	{
		this.right=right;
	}
}
