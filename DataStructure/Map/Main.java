public class Main
{
	public static void main(String[] args)
	{
		Entry entry;
		Map map=new Map();
		
		System.out.println(map.isEmpty());
		
		System.out.println("======================");
		entry=new Entry(5, "A");
		map.put(entry);
		map.listPrint();
		entry=new Entry(7, "B");
		map.put(entry);
		map.listPrint();
		
		entry=new Entry(2, "C");
		map.put(entry);
		entry=new Entry(8, "D");
		map.put(entry);
		map.listPrint();
		entry=new Entry(2, "E");
		System.out.println(map.put(entry));
		map.listPrint();
		
		System.out.println("======================");
		System.out.println(map.get(7));
		System.out.println(map.get(4));
		System.out.println(map.get(2));
		
		System.out.println("======================");
		System.out.println(map.size());
		
		
		System.out.println("======================");	//need to check
		System.out.println(map.remove(5));
		map.listPrint();
		System.out.println(map.remove(2));
		map.listPrint();

		System.out.println("======================");
		System.out.println(map.get(2));
		
		System.out.println("======================");
		System.out.println(map.isEmpty());
	}
}
