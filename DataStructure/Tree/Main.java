package chapter8;

public class Main
{
	public static void main(String[] args)
	{
		/*
		ListPQ pq=new ListPQ(100);
		pq.insert(3, "Kim");
		pq.insert(2, "Lee");
		pq.insert(1, "Kang");
		pq.insert(6, "Sung");
		pq.insert(4, "Park");
		pq.insert(5, "Son");
		
		pq.printAll();
		
		pq.min();
		pq.printAll();
		
		pq.removeMin();
		pq.printAll();
		
		pq.removeMin();
		pq.printAll();
		*/
		
		CBTree tree=new CBTree(3, "Kim");
		tree.preorder();
		
		System.out.println("==============");
		tree.add(4, "Lee");
		tree.add(5, "Park");
		tree.preorder();
		System.out.println("==============");
		tree.remove();
		tree.preorder();
	}
}