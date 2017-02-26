import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class Graph<T>
{
	private int numVertex=0;
	private int numEdge=0;
	private ArrayList<Vertex<T>> vertexList=new ArrayList<>();
	private ArrayList<T> visited = new ArrayList<T>();
	
	public void addVertex(T element)
	{
		vertexList.add(new Vertex<T>(element));
		this.numVertex++;
	}
	
	public void addEdge(T t1, T t2)
	{
		findVertex(t1, false).addEdge(t2);
		findVertex(t2, false).addEdge(t1);
	}
	
	public Vertex<T> findVertex(T element, Boolean print)
	{
		for(Vertex<T> vertex:vertexList)
		{
			if(vertex.getElement().equals(element))
			{
				if(print)
					System.out.println("Vertex found "+element);
				return vertex;
			}
		}
		return null;
	}
	
	public void depthFirstSearch(T element)
	{
		Vertex<T> find=this.findVertex(element, false);
		System.out.println(find.getElement());
		
		visited.add(find.getElement());
		Iterator<T> iterator=find.getEdgeList().iterator();
		while(iterator.hasNext())
		{
			T e=iterator.next();
			if(!visited.contains(e))
				depthFirstSearch(e);
		}
	}
	
	public void depthFirstSearch()
	{
		visited.clear();
		System.out.println("-----DFS-----");
		this.depthFirstSearch((T)"0");
	}
	
	public void breadthFirstSearch(T element)
	{
		Queue<T> queue=new <T>LinkedList();
		queue.offer(element);
		visited.clear();
		visited.add(element);
		
		System.out.println("-----BFS-----");
		while(!queue.isEmpty())
		{
			T temp=queue.poll();
			Vertex<T> find=this.findVertex(temp, false);
			System.out.println(find.getElement());
			
			Iterator<T> iterator=find.getEdgeList().iterator();
			while(iterator.hasNext())
			{
				T e=iterator.next();
				if(!visited.contains(e))
				{
					queue.offer(e);
					visited.add(e);
				}
			}
		}
	}
	
	public void printGraph()
	{
		System.out.println("-----printGraph-----");
		for(Vertex<T> vertex:vertexList)
			vertex.printEdgeList();
	}
	
	public void printVertices()
	{
		System.out.println("-----printVertices-----");
		
		for(Vertex<T> vertex:vertexList)
			System.out.print(vertex.getElement()+" ");
		System.out.println();
	}
}