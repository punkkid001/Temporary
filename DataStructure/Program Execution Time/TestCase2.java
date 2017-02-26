/**
 * Created by Jiyoon on 2016. 3. 8..
 */
public class TestCase2
{
    public int test2(int A[], int n)
    {
        int s=0;

        long begin=System.currentTimeMillis();  //Start time
        //long begin=System.nanoTime();
        for(int i=0;i<=n-1;i++)
        {
            s+=A[0];
            for(int j=1;j<=i;j++)
                s+=A[j];
        }
        //long end=System.nanoTime();
        long end=System.currentTimeMillis();    //End time

        //System.out.print((end-begin)/10000+"ms \t\t");
        System.out.print((end-begin)+"ms \t\t");    //print execution time

        return s;
    }
}