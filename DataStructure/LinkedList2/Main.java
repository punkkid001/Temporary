public class Main
{
	public static void main(String[] args)
	{
		LinkedList linkedList=new LinkedList();
		
		linkedList.addLast("A");
		linkedList.addLast("B");
		linkedList.addLast("C");
		linkedList.addLast("D");
		linkedList.addLast("E");
		linkedList.addLast("F");
		linkedList.addLast("G");
		linkedList.addLast("H");
		linkedList.addLast("I");
		
		linkedList.printAllNodes();
		
		linkedList.addBefore(2, "a");
		linkedList.addBefore(2, "b");
		
		linkedList.printAllNodes();
		
		linkedList.addBefore(10, "c");
		
		linkedList.printAllNodes();
	}
}
