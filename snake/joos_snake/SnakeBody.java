public class SnakeBody
{
    protected SnakeBody rest;
    protected int x;
    protected int y;
    public SnakeBody(int xt, int yt, SnakeBody restt)
    {
        super();
        x = xt;
        y = yt;
        rest = restt;
    }
    public int getLength()
    {
        if(rest == null)
            return 1;
        return 1 + rest.getLength();
    }
    public SnakeBody getRest()
        {return rest;}
    public void setRest(SnakeBody restt)
        {rest = restt;}
    public int getX()
        {return x;}
    public int getY()
        {return y;}
}
