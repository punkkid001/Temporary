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
	
	public Node getParent()
	{
		return parent;
	}
	
	public boolean isLeft()
	{
		if(left==null)
			return false;
		else
			return true;
	}
	
	public boolean isRight()
	{
		if(right==null)
			return false;
		else
			return true;
	}
	
	public boolean isLeaf()
	{
		if(!(isLeft()&&isRight()))
			return true;
		else
			return false;
	}
	
	public boolean isRoot()
	{
		if(parent==null)
			return true;
		else
			return false;
	}
}