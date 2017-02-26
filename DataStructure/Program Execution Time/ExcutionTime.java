/**
 * Created by Jiyoon on 2016. 3. 8..
 */

import java.util.Random;

public class ExcutionTime
{
    public static void main(String[] args)
    {
        run1();     //exercise 1
        run2();     //exercise 2
    }

    public static void setArr(int Arr[], int n)
    {
        Random r = new Random();

        for (int i = 0; i < n; i++)
            Arr[i] = r.nextInt(10) + 1; //input random number
    }

    public static void run1()
    {
        TestCase1 ex1=new TestCase1();
        int n=1;

        System.out.println("*** Exercise 1 ***");
        for(int i=0;i<7;i++)
        {
            int []arr=new int[n];
            setArr(arr, n);
            System.out.print(n+"\t\t\t");   //print number of array
            ex1.test1(arr, n);
            System.out.println(n*3);    //print number of '<-'

            n*=10;
        }
    }

    public static void run2()
    {
        TestCase2 ex2=new TestCase2();
        int n=1;

        System.out.println("*** Exercise 2 ***");
        for(int i=0;i<7;i++)
        {
            int []arr=new int[n];
            setArr(arr, n);
            System.out.print(n+"\t\t\t");   //print number of array
            ex2.test2(arr, n);
            System.out.println(3*n+1);      //print number of '<-'

            n*=10;
        }
    }
}
