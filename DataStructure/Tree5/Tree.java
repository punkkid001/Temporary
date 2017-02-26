/**
 * Created by Jiyoon on 2016. 4. 13..
 */
package ex3;

import java.util.ArrayList;
import java.util.List;

public class Tree
{
    private Node root;

    public Tree()
    {
        root=new Node("root",null);
    }

    public Node getRoot()
    {
        return root;
    }

    public Node getParent(Node t)
    {
        return t.getParent();
    }

    public void preOrder(Node t)
    {
        t.printData();
        if(t.isLeft())
            this.preOrder(t.getLeftChild());
        if(t.isRight())
            this.preOrder(t.getRightChild());
    }

    public void postOrder(Node t)
    {
        if(t.isLeft())
            this.postOrder(t.getLeftChild());
        if(t.isRight())
            this.postOrder(t.getRightChild());
        t.printData();
    }

    public boolean isRoot(Node t)
    {
        return t.isRoot();
    }

    public boolean isExternal(Node t)
    {
        return t.isLeaf();
    }

    public boolean isInternal(Node t)
    {
        return !t.isLeaf();
    }

    public List<Node> getChild(Node t)
    {
        List<Node> temp=new ArrayList<Node>();

        temp.addAll(nodes(t.getLeftChild()));
        temp.addAll(nodes(t.getRightChild()));

        return temp;
    }

    public List<Node> nodes()
    {
        return nodes(root);
    }

    public List<Node> nodes(Node t)
    {
        List<Node> temp=new ArrayList<Node>();

        if(t!=null)
        {
            temp.add(t);

            if(t.isLeft())
                temp.addAll(nodes(t.getLeftChild()));
            if(t.isRight())
                temp.addAll(nodes(t.getRightChild()));
        }

        return temp;
    }
}