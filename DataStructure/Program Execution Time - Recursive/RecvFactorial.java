
public class RecvFactorial
{
	public long recursiveFactorial(int n)
	{
		if(n==0)
			return 1;
		else
			return n*recursiveFactorial(n-1);
	}
}
