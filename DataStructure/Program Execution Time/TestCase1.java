/**
 * Created by Jiyoon on 2016. 3. 8..
 */
public class TestCase1
{
    public int test1(int A[], int n)
    {
        int s=A[0];

        //long begin=System.nanoTime();
        long begin=System.currentTimeMillis();  //Start time
        for(int i=1;i<=n-1;i++)
            s+=A[i];
        //long end=System.nanoTime();
        long end=System.currentTimeMillis();    //End time

        //System.out.print((end-begin)/10000+"ms \t\t");
        System.out.print((end-begin)+"ms \t\t");    //print execution time

        return s;
    }
}
