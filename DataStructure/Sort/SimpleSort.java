import java.util.ArrayList;
import java.util.Collections;

public class SimpleSort
{
	public static void main(String[] args)throws Exception
	{
		ArrayList<Integer> listInt=new ArrayList<Integer>();

		listInt.add(2);
		listInt.add(1);
		listInt.add(3);
		listInt.add(5);
		listInt.add(4);

		System.out.print("Before : ");
		for(Integer item:listInt)
			System.out.print(item+" ");
		System.out.println();

		Collections.sort(listInt);

		System.out.print("After : ");
		for(Integer item:listInt)
			System.out.print(item+" ");
		System.out.println();
	}
}
