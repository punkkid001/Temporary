public class Tree
{
	private TreeNode root;
	private TreeNode findNode;
	
	//add
	private List list=new List();
	private List subList=new List();
	
	//add - 2
	private int height;
	private Object treeArray[];
	private int depth;
	
	private int edge=0;
	private int nodeCounter=0;
	
	public Tree()
	{
		root=new TreeNode("root", null);
	}
	public Tree(Object element)
	{
		root=new TreeNode(element, null);
	}
	
	private void findRecursive(TreeNode t, String str)
	{
		if(t.getData().equals(str))
		{
			findNode=t;
		}
		
		if(t.isLeft())
		{
			findRecursive(t.getLeftChild(), str);
		}
		
		if(t.isRight())
		{
			findRecursive(t.getRightChild(), str);
		}
	}
	
	public TreeNode findNode(String data)
	{
		findRecursive(root, data);
		
		return findNode;
	}
	
	public TreeNode getRoot()
	{
		return root;
	}
	
	public boolean isRoot(TreeNode v)
	{
		return v.isRoot();
	}
	
	public TreeNode parent(TreeNode v)
	{
		return v.getParent();
	}
	
	public void preorder(TreeNode v)
	{
		v.printData();
		if(v.isLeft())
			this.preorder(v.getLeftChild());
		if(v.isRight())
			this.preorder(v.getRightChild());
	}
	
	public void nodeCounting(TreeNode v)
	{
		this.nodeCounter++;
		if(v.isLeft())
			this.nodeCounting(v.getLeftChild());
		if(v.isRight())
			this.nodeCounting(v.getRightChild());
	}
	
	public void printNodeList()
	{
		list.initialization();
		addToList(root, this.list);
		for(int i=0;i<=list.getSize();i++)
			System.out.println(list.getNode(i));
	}
	
	public void addToList(TreeNode v, List list)
	{
		list.addLast(v.getData());
		if(v.isLeft())
			addToList(v.getLeftChild(), list);
		if(v.isRight())
			addToList(v.getRightChild(), list);
	}
	
	public void getAncestors(TreeNode node)
	{
		int index=0;
		list.addLast(node.getParent().getData());
		node=node.getParent();
		
		while(list.getNode(index)!=root.getData())
		{
			System.out.println(list.getNode(index));
			list.addLast(node.getParent().getData());
			node=node.getParent();
			index++;
		}
		System.out.println(root.getData());
	}
	
	public void getAncestors(TreeNode node, List list)
	{
		int index=0;
		list.addLast(node.getParent().getData());
		node=node.getParent();
		
		while(list.getNode(index)!=root.getData())
		{
			//System.out.println(list.getNode(index));
			list.addLast(node.getParent().getData());
			node=node.getParent();
			index++;
		}
		list.addLast(root.getData());
	}
	
	public void getCommonNode(TreeNode node, TreeNode node2)
	{
		int index=0, index2=0;
		this.list.initialization();
		this.subList.initialization();
		
		getAncestors(node, this.list);
		getAncestors(node2, this.subList);
		
		/*
		System.out.println("test ---------");
		for(int i=0;i<list.getSize();i++)
			System.out.println(list.getNode(i));
		System.out.println();
		System.out.println("test2---------------");
		for(int i=0;i<subList.getSize();i++)
			System.out.println(subList.getNode(i));
		System.out.println();
		System.out.println("00000000000000000000000000");
		*/
		
		for(;index<list.getSize();index++)
		{
			for(index2=0;index2<subList.getSize();index2++)
			{
				if(list.getNode(index).equals(subList.getNode(index2)))
				{
					System.out.println(list.getNode(index));
					edge++;
				}
			}
			edge++;
		}
		
		/*
		while((list.getNode(index)!=root.getData()&&(subList.getNode(index2)!=root.getData())))
		{
			if(list.getNode(index)==subList.getNode(index2))
			{
				edge++;
				System.out.print(list.getNode(index)+" ");
			}
			
			list.addLast(node.getParent().getData());
			subList.addLast(node2.getParent().getData());
			node=node.getParent();
			node2=node2.getParent();
			index++;
			index2++;
		}
		*/
		System.out.println("°Å¸® : "+edge);
	}
	
	void printSameLevelNodes(int level)
	{
		this.list.initialization();
		printSameLevelNodes(this.root, level, 0);
		
		for(int i=0;i<=this.list.getSize();i++)
			System.out.println(this.list.getNode(i));
	}
	
	void printSameLevelNodes(TreeNode t, int level, int depth)
	{
		if(level==depth)
			list.addLast(t.getData());
		if(t.isLeft())
			printSameLevelNodes(t.getLeftChild(), level, depth+1);
		if(t.isRight())
			printSameLevelNodes(t.getRightChild(), level, depth+1);
	}
	
	public void treeNumbering(TreeNode t, String str)
	{
		//t.setData(str+" : "+t.getData());
		System.out.println(str+" : "+t.getData());
		
		if(t.isLeft())
			treeNumbering(t.getLeftChild(), str+".1");
		if(t.isRight())
			treeNumbering(t.getRightChild(), str+".2");
	}
	
	public void treeToArray()
	{
		this.nodeCounter=0;
		this.nodeCounting(this.root);
		//System.out.println(nodeCounter);
		treeArray=new Object[nodeCounter*2];
		treeArray[0]="null";
		this.addTreeToArray(root, 1);
	}
	
	public void addTreeToArray(TreeNode v, int index)
	{
		this.treeArray[index]=(Object)v.getData();
		if(v.isLeft())
			this.addTreeToArray(v.getLeftChild(), index*2);
		if(v.isRight())
			this.addTreeToArray(v.getRightChild(), 2*index+1);
	}
	
	public void getTreeArray()
	{
		for(int i=0;i<nodeCounter*2;i++)
			System.out.println(i+" : "+this.treeArray[i]);
	}
	
	public void printHeight()
	{
		this.height=0;
		getHeight(root, getDepth(this, root));
		System.out.println("Height of Tree : "+this.height);	//??
	}
	
	public int getDepth(Tree t, TreeNode v)
	{
		if(t.isRoot(v))
			return 0;
		else
			return 1+getDepth(t, t.parent(v));
	}
	
	public int getDepth(TreeNode v)
	{
		if(v.getParent()==null)
			return 0;
		else
			return 1+getDepth(v.getParent());
	}
	
	public void getHeight(TreeNode t, int depth)
	{
		this.height=Math.max(this.height, depth);
		if(t.isLeft())
			getHeight(t.getLeftChild(), depth+1);
		if(t.isRight())
			getHeight(t.getRightChild(), depth+1);
	}
}
