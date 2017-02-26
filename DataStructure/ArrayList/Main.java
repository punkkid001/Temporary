public class Main
{
	public static void main(String[] args)
	{
		ArrayList list=new ArrayList();
		
		list.add(0, 5);
		list.add(1, 2);
		list.add(1, 7);
		list.add(0, 1);
		list.printAll();
		System.out.println(list.remove(1)+" ");
		list.printAll();
		list.add(0, 4);
		list.printAll();
		System.out.println(list.remove(10)+" ");
		list.printAll();
		System.out.println(list.remove(3)+" ");
		list.printAll();
	}
}
