
public class ListNode
{
	private Object element;
	private ListNode nextNode;
	private ListNode prevNode;
	
	public ListNode(ListNode prevNode, ListNode nextNode, Object element)
	{
		this.prevNode=prevNode;
		this.nextNode=nextNode;
		this.element=element;
	}
	
	public void setNextNode(ListNode nextNode)
	{
		this.nextNode=nextNode;
	}
	
	public void setPrevNode(ListNode prevNode)
	{
		this.prevNode=prevNode;
	}
	
	public Object getElement()
	{
		return this.element;
	}
	
	public ListNode getNextNode()
	{
		return this.nextNode;
	}
	
	public ListNode getPrevNode()
	{
		return this.prevNode;
	}
}
