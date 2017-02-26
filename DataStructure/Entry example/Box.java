/**
 * Created by Jiyoon on 2016. 5. 24..
 */
public class Box<T>
{
    private T t;

    public void add(T t)
    {
        this.t=t;
    }

    public T get()
    {
        return this.t;
    }

}