/**
 * Created by Jiyoon on 2016. 3. 22..
 */

public class Stack
{
    private static class StackNode
    {
        int value;
        StackNode prevNode;

        //making stack node! -> value&prev node
        public StackNode(int value, StackNode prevNode)
        {
            this.value = value;
            this.prevNode = prevNode;
        }
    }

    private StackNode topNode=null;
    private int point=0;

    public void push(int value)
    {
        this.topNode = new StackNode(value, this.topNode);
        this.point++;
    }

    public int pop()
    {
        if(this.topNode == null)
            throw new IllegalStateException("Stack is empty.");

        int top_value = this.topNode.value;
        this.topNode = this.topNode.prevNode;
        this.point--;
        return top_value;
    }

    public int top()
    {
        if(this.topNode == null)
            throw new IllegalStateException("Stack is empty.");

        return this.topNode.value;
    }

    public int rtnSize()
    {
        return this.point;
    }

    public boolean checkEmpty()
    {
        return this.topNode == null;
    }
}
