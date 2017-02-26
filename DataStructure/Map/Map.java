import java.util.*;

public class Map
{
	private LinkedList list;
	private int n;
	
	public Map()
	{
		this.list=new LinkedList();
		this.n=0;
	}

	public int size(){return n;}
	
	public boolean isEmpty()
	{
		if(this.n==0)
			return true;
		else
			return false;
	}
	
	public Object get(int key)
	{
		Node p=list.header.getNext();
		
		while(p!=list.trailer)
		{
			if(((Entry)p.getElement()).getKey()==key)
				return ((Entry)p.getElement()).getObj();
			
			p=p.getNext();
		}
		
		return null;
	}
	
	public Object put(Entry entry)
	{
		Node p=list.header.getNext();
		Object t=null;
		
		while(p!=list.trailer)
		{
			if(((Entry)p.getElement()).getKey()==entry.getKey())
			{
				t=((Entry)p.getElement()).getObj();
				//list.set(p, entry);	//?
				list.set(p, entry);
				
				return t;
			}
			
			p=p.getNext();
		}
		list.addLast(entry);
		this.n+=1;
		
		return null;
	}
	
	public Object remove(int key)
	{
		Node p=list.header.getNext();
		Object t=null;
		
		while(p!=list.trailer)
		{
			if(((Entry)p.getElement()).getKey()==key)
			{
				t=((Entry)p.getElement()).getObj();
				list.remove(p);
				this.n-=1;
				
				return t;
			}
			
			p=p.getNext();
		}
		
		return null;
	}
	
	public void listPrint()
	{
		Node p=list.header.getNext();
		
		while(p!=list.trailer)
		{
			((Entry)p.getElement()).printDataAndKey();
			
			p=p.getNext();
		}
		System.out.println();
	}
	
	public LinkedList keys()
	{
		Node p=list.header.getNext();
		
		while(p!=list.trailer)
		{
			System.out.print(((Entry)p.getElement()).getKey()+" ");
			p=p.getNext();
		}
		System.out.println();
		
		return list;
	}
	
	public LinkedList values()
	{
		Node p=list.header.getNext();
		
		while(p!=list.trailer)
		{
			System.out.print(((Entry)p.getElement()).getObj()+" ");
			p=p.getNext();
		}
		System.out.println();
		
		return list;
	}
	
	public LinkedList entries()
	{
		Node p=list.header.getNext();
		
		while(p!=list.trailer)
		{
			((Entry)p.getElement()).printDataAndKey();
			
			p=p.getNext();
		}
		System.out.println();
		
		return list;
	}
}
