public class Main
{
	public static void main(String[] args0)
	{
		/*
		List list=new List();
		
		list.addLast("A");
		list.addLast("B");
		list.addLast("C");
		
		System.out.println(list.getNode(2));
		System.out.println(list.getNode(0));
		System.out.println(list.getNode(1));
		 */
		
		/*
		Tree tree=new Tree();
		
		tree.getRoot().addLeftChild("mammal");
		tree.getRoot().addRightChild("bird");
		tree.findNode("mammal").addLeftChild("cat");
		tree.findNode("mammal").addRightChild("dog");
		tree.findNode("bird").addLeftChild("eagle");
		tree.findNode("bird").addRightChild("sparrow");
		
		tree.preorder(tree.getRoot());
		 */
		
		Tree tree=new Tree("Data Structure");
		
		tree.findNode("Data Structure").addLeftChild("Primitive Data Structure");
		
		tree.findNode("Primitive Data Structure").addRightChild("String");
		tree.findNode("Primitive Data Structure").addLeftChild("Number");
		tree.findNode("Data Structure").addRightChild("Non-Primitive Data Structure");
		
		tree.findNode("Non-Primitive Data Structure").addLeftChild("Linear");
		tree.findNode("Non-Primitive Data Structure").addRightChild("Non-Linear");
		
		tree.findNode("Linear").addLeftChild("Static");
		tree.findNode("Static").addLeftChild("Array");
		tree.findNode("Linear").addRightChild("Dynamic");
		
		tree.findNode("Dynamic").addLeftChild("Linked List");
		tree.findNode("Dynamic").addRightChild("Stack/Queue");
		
		tree.findNode("Non-Linear").addLeftChild("Trees");
		tree.findNode("Non-Linead").addRightChild("Graph");
		
		tree.preorder(tree.getRoot());
		
		//System.out.println();
		//tree.printNodeList();
		
		/*
		System.out.println("================");
		tree.getAncestors(tree.findNode("Dynamic"));
		System.out.println("================");
		tree.getCommonNode(tree.findNode("Trees"), tree.findNode("Array"));
		*/
		System.out.println("samelevel========");
		tree.printSameLevelNodes(2);
		System.out.println("================");
		tree.treeNumbering(tree.getRoot(), "1");
		//tree.printNodeList();
		System.out.println("================");
		tree.printHeight();
		System.out.println("================");
		tree.treeToArray();
		tree.getTreeArray();
	}
}
