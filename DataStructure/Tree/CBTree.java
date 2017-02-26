package chapter8;

public class CBTree
{
	private Node root;
	private int n;
	private Node lastNode;
	
	public CBTree(int key, Object data)
	{
		this.root=new Node(new Entry(key, data), null);
		this.n=1;
		this.lastNode=null;
	}
	
	public CBTree()
	{
		this.root=null;
		this.n=0;
		this.lastNode=null;
	}
	
	public void preorder()
	{
		preorder(root);
	}
	
	private void preorder(Node t)
	{
		System.out.println(t.getElement());
		if(t.isLeft())
			preorder(t.getLeftChild());
		if(t.isRight())
			preorder(t.getRightChild());
	}
	
	public void inorder()
	{
		inorder(root);
	}
	
	private void inorder(Node t)
	{
		if(t.isLeft())
			inorder(t.getLeftChild());
		System.out.println(t.getElement());
		if(t.isRight())
			inorder(t.getRightChild());
	}
	
	public void findNode(Node t)
	{
		lastNode=t;
		if(t.isLeft())
			findNode(t.getLeftChild());
		if(t.isRight())
			findNode(t.getRightChild());
	}
	
	public Node add(int key, Object data)
	{
		Node w=new Node(new Entry(key, data), null);
		this.n++;
		
		findNode(root);
		
		if(lastNode.isLeaf())
		{
			lastNode.addLeftChild(w);
			w.setParent(lastNode);
		}
		else if(!lastNode.isLeft())
		{
			lastNode.addLeftChild(w);
			w.setParent(lastNode);
		}
		else if(!lastNode.isRight())
		{
			lastNode.addRightChild(w);
			w.setParent(lastNode);
		}
		else
			return null;
		return w;
	}
	
	public Object remove()
	{
		Object data;
		Node temp;
		findNode(root);
		
		data=lastNode.getElement();
		lastNode.setElement(null);
		temp=lastNode.getParent();
		if(temp.getLeftChild().getElement()==lastNode.getElement())
			temp.setLeftChild(null);
		else
			temp.setRightChild(null);
		lastNode.setParent(null);
		
		this.n--;
		
		return data;
	}
}