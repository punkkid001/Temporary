public class QuickSort
{
	public static void main(String[] args)
	{
		int k=0;
		int[] arr=new int[50000];
		long time=0;
		
		for(int i=arr.length-1;i>=0;i--)
		{
			arr[k]=(int)(Math.random()*100000);
			k++;
		}
		
		time=System.currentTimeMillis();
		quickSort(arr, 0, arr.length-1);
		time=System.currentTimeMillis()-time;
		
		k=0;
		System.out.println("Result : ");
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
			//k++;
		}
		System.out.println();
		
		//System.out.println("Time : "+time+"ms");
	}
	
	static void swap(int[] arr, int i, int j)
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	
	public static void quickSort(int[] arr, int first, int last)
	{
		int left, right;
		int pivot;
		
		if(last>first)
		{
			pivot=arr[last];
			left=first-1;
			right=last;
			
			while(left<right)
			{
				do
				{
					if(left==last)
						break;
					left++;
				}while(arr[left]<pivot);
				
				do
				{
					if(right==first)
						break;
					right--;
				}while(arr[right]>pivot);
				
				if(left<right)
					swap(arr, left, right);
			}
			
			swap(arr, left, last);
			quickSort(arr, first, left-1);
			quickSort(arr, left+1, last);
		}
	}
}