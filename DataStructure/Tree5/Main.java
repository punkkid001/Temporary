/**
 * Created by Jiyoon on 2016. 4. 13..
 */
package ex3;

public class Main
{
    public static int depth(Tree t, Node v)
    {
        if(t.isRoot(v))
            return 0;
        else
            return 1+depth(t, t.getParent(v));
    }

    public static int height1(Tree t)
    {
        int h=0;
        for(Node v:t.nodes())
        {
            if(t.isExternal(v))
                h=Math.max(h,  depth(t, v));
        }
        return h;
    }

    public static int height2(Tree t, Node v)
    {
        if(t.isExternal(v))
            return 0;

        int h=0;
        for(Node w:t.getChild(v))	//??
            h=Math.max(h, height2(t,w));	//??
        return 1+h;
    }

    public static void main(String[] args)
    {
        Tree tree=new Tree();

        tree.getRoot().addLeftChild("1.Mammal");
        tree.getRoot().addRightChild("2. Birds");
        tree.getRoot().getLeftChild().addLeftChild("1-1. Dog");
        tree.getRoot().getLeftChild().addRightChild("1-2. Cat");
        tree.getRoot().getRightChild().addLeftChild("2-1. Sparrow");
        tree.getRoot().getRightChild().addRightChild("2-2. Eagle");

        tree.preOrder(tree.getRoot());
        System.out.println();

        System.out.println("Depth : "+depth(tree, tree.getRoot()));
        System.out.println("Height1 : "+height1(tree));
        System.out.println("Height2 : "+height2(tree, tree.getRoot()));
    }
}