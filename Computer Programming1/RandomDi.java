import java.util.Random;

public class RandomDi
{
  public static void main(String[] args)
  {
    Random g=new Random();
    int i, R_number;

    for(i=1;i<=5;i++)
    {
      R_number=g.nextInt(6)+1;
      System.out.println(i+"Random number is "+R+number);
    }
  }
}
