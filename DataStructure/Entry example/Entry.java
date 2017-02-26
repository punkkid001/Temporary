/**
 * Created by Jiyoon on 2016. 5. 24..
 */
public class Entry<T1, T2>
{
    private T1 key;
    private T2 value;

    public Entry(T1 key, T2 value)
    {
        this.key=key;
        this.value=value;
    }

    public T1 getKey()
    {
        return this.key;
    }

    public T2 getValue()
    {
        return this.value;
    }
}
