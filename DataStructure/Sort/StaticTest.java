public class StaticTest
{
	static private int test=777;
	static public void testStatic()
	{
		System.out.println("Static test");
	}
	static public void setVariable(int t)
	{
		test=t;
	}
	static public void printStatic()
	{
		System.out.println("print Static : "+test);
	}
	static public void print()
	{
		System.out.println("print : "+test);
	}
	
	public static void main(String[] args)
	{
		StaticTest.testStatic();
		System.out.print("Static variable");
		StaticTest.printStatic();
		StaticTest.setVariable(3333);
		StaticTest.printStatic();
		StaticTest staticTest=new StaticTest();
		staticTest.print();
		staticTest.setVariable(7777);
		StaticTest.printStatic();
		staticTest.print();
	}
}