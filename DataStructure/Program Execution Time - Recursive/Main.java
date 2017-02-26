import java.util.Scanner;

public class Main
{
	static long start;
	static long end;
	
	public static void main(String[] args)
	{
		RecvFactorial ex1=new RecvFactorial();
		Fibonacci ex2=new Fibonacci();
		Scanner input=new Scanner(System.in);
		long result=0;
		long []arr=new long[2];
		
		System.out.print("input 'n' : ");
		int n=input.nextInt();
		
		System.out.println("****Exercise1 - Factorial****");
		start();
		result=ex1.recursiveFactorial(n);
		end();
		System.out.println("result : "+result);
		System.out.println("ExcutionTime : "+(end-start));
		
		System.out.println("****Exercise2 - Fibonacci****");
		System.out.println("1. binaryFib");
		start();
		result=ex2.binaryFib(n);
		end();
		System.out.println("result : "+result);
		System.out.println("ExcutionTime : "+(end-start));
		
		System.out.println("2. linearFib");
		start();
		arr=ex2.linearFib(n);
		end();
		System.out.println("result : "+arr[0]+", "+arr[1]);
		System.out.println("Excution Time : "+(end-start));
		
		System.out.println("3. linearFib2");
		start();
		result=ex2.linearFib2(n);
		end();
		System.out.println("result : "+result);
		System.out.println("ExecutionTime : "+(end-start));
	}
	
	public static void start()
	{
		start=System.nanoTime();
	}
	
	public static void end()
	{
		end=System.nanoTime();
	}
}
