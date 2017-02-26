public class Tree
{
	private Node root;
	
	public Tree()
	{
		root=new Node("root",null);
	}
	
	public Node getRoot()
	{
		return root;
	}
	
	public void preOrder(Node t)
	{
		t.printData();
		if(t.isLeft())
			this.preOrder(t.getLeftChild());
		if(t.isRight())
			this.preOrder(t.getRightChild());
	}
	
	public void postOrder(Node t)
	{
		if(t.isLeft())
			this.postOrder(t.getLeftChild());
		if(t.isRight())
			this.postOrder(t.getRightChild());
		t.printData();
	}
}