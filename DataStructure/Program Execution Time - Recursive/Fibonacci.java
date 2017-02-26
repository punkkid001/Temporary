
public class Fibonacci
{
	public long binaryFib(int n)
	{
		if(n<=1)
			return n;
		else
			return binaryFib(n-1)+binaryFib(n-2);
	}
	
	public long[] linearFib(int n)
	{
		long []arr=new long[2];
		if(n<=1)
		{
			arr[0]=1;
			arr[1]=0;
			return arr;
		}
		
		else
		{
			arr=linearFib(n-1);
			long temp=arr[1];
			arr[1]=arr[0];
			arr[0]+=temp;
			
			return arr;
		}
	}
	
	public long linearFib2(int n)
	{		
		if(n<=1)
			return n;
		
		else
		{
			int prev=0, curr=1, next=0;
			for(int i=2;i<=n;i++)
			{
				next=curr+prev;
				prev=curr;
				curr=next;
			}
			
			return next;
		}
	}

}
