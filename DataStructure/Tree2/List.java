
public class List
{
	private ListNode header;
	private ListNode trailer;
	private int size;
	
	public List()
	{
		header=new ListNode(null, trailer, null);
		trailer=new ListNode(header, null, null);
		size=-1;
	}
	
	public void initialization()
	{
		header.setNextNode(trailer);
		trailer.setPrevNode(header);
		size=-1;
	}
	
	public void addLast(Object element)
	{
		ListNode temp=new ListNode(trailer.getPrevNode(), trailer, element);
		trailer.getPrevNode().setNextNode(temp);
		trailer.setPrevNode(temp);
		
		size++;
	}
	
	public void addFirst(Object element)
	{
		ListNode temp=new ListNode(header, header.getNextNode(), element);
		header.getNextNode().setPrevNode(temp);
		header.setNextNode(temp);
		
		size++;
	}
	
	public Object getNode(int i)
	{
		ListNode temp=header.getNextNode();
		int index=0;
		
		while(temp!=trailer)
		{
			if(index==i)
				return temp.getElement();
			
			index++;
			temp=temp.getNextNode();
		}
		
		return "Can't find";
	}
	
	public int getSize()
	{
		return this.size;
	}
}
