package heap;

public class HeapMain
{
	public static void main(String[] args)
	{
		Heap heap=new Heap();
		
		heap.insert(8, "A");
		heap.preorder();
		
		System.out.println("=============================");
		heap.insert(7, "B");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(6, "C");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(5, "D");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(4, "E");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(3, "F");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(2, "G");
		heap.preorder();
		System.out.println("=============================");
		heap.insert(1, "H");
		heap.preorder();
		
		System.out.println("=========removeMin()============");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
		heap.removeMin();
		heap.preorder();
		System.out.println("=============================");
	}
}
