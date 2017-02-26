public class TreeNode
{
	private Object element;
	private TreeNode left;
	private TreeNode right;
	private TreeNode parent;
	
	public TreeNode(Object element, TreeNode parent)
	{
		this.element=element;
		this.parent=parent;
		
		left=null;
		right=null;
	}
	
	public void addLeftChild(Object element)
	{
		TreeNode temp=new TreeNode(element, this);
		left=temp;
	}
	
	public void addRightChild(Object element)
	{
		TreeNode temp=new TreeNode(element, this);
		right=temp;
	}
	
	void printData()
	{
		System.out.println(this.element);
	}
	
	public void setData(Object data)
	{
		this.element=data;
	}
	
	public Object getData()
	{
		return this.element;
	}
	
	public TreeNode getLeftChild()
	{
		return this.left;
	}
	
	public TreeNode getRightChild()
	{
		return this.right;
	}
	
	public boolean isLeft()
	{
		if(left!=null)
			return true;
		else
			return false;
	}
	
	public boolean isRight()
	{
		if(right!=null)
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
	
	public TreeNode getParent()
	{
		return this.parent;
	}
	
	/*
	public TreeNode getRoot()
	{
		if(isRoot())
			return this;
		else
			return false;
	}
	*/
}
