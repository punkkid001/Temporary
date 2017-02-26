import java.util.ArrayList;
import java.util.Iterator;

public class Vertex<T>
{
	private T element;
	private ArrayList<T> edgeList=new ArrayList<T>();
	
	public Vertex(T element)
	{
		this.element=element;
	}
	
	public T getElement()
	{
		return this.element;
	}
	
	public void addEdge(T edge)
	{
		edgeList.add(edge);
	}
	
	public ArrayList<T> getEdgeList()
	{
		return edgeList;
	}
	
	public void printEdgeList()
	{
		Iterator<T> iterator=edgeList.iterator();
		System.out.print(this.element);
		
		while(iterator.hasNext())
		{
			T e=iterator.next();
			System.out.print("--->"+e);
		}
		System.out.println();
	}
}