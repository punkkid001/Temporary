public class Main
{
	public static void main(String[] args)
	{
		Tree tree=new Tree();
		
		tree.getRoot().addLeftChild("1.Mammal");
		tree.getRoot().addRightChild("2. Birds");
		tree.getRoot().getLeftChild().addLeftChild("1-1. Dog");
		tree.getRoot().getLeftChild().addRightChild("1-2. Cat");
		tree.getRoot().getRightChild().addLeftChild("2-1. Sparrow");
		tree.getRoot().getRightChild().addRightChild("2-2. Eagle");
		
		tree.getRoot().printData();
		tree.getRoot().getRightChild().printData();
		tree.getRoot().getRightChild().getRightChild().printData();
		tree.getRoot().getLeftChild().getRightChild().printData();
	}
}
