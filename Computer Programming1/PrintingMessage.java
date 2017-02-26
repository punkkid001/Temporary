/*How to use this code ..
  >>(using cmd) java PrintingMessage (value[0]) (value[1]) (value[2])
  Ex. java PrintingMessage Kim Lee Homework
*/

public class PrintingMessage
{
  public static void main(String[] args)
  {
    System.out.println("From : "+args[0]);
    System.out.println("To : "+args[1]);
    System.out.println("Contents "+args[2]);
  }
}
