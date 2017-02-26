/**
 * Created by Jiyoon on 2016. 4. 9..
 */
public class Main
{
    public static void main(String[] args)
    {
        LinkedList list=new LinkedList();

        //input my name ("pk-yoon")
        list.addLast("p");
        list.addLast("k");
        list.addLast("-");
        list.addLast("y");
        list.addLast("o");
        list.addLast("o");
        list.addLast("n");

        list.printAllNodes();
        
        //add.. pk-yoon -> pk-y-oon
        list.addAfter("y", "-");
        list.printAllNodes();
        list.printRev();
        
        //add pk-y-oon -> pPk-y-oon
        list.addBefore("k","P");
        list.printAllNodes();

        //change pPk-y-oon -> pPk-g-oon
        list.setCharacter("y", "g");
        list.printAllNodes();
        
        //delete pPk-g-oon -> pPk--oon
        list.remove("g");
        list.printAllNodes();
        
        list.searchNode("n");	//search 'n' -> find!
        list.searchNode("b");	//search 'b' -> can't find!
    }
}