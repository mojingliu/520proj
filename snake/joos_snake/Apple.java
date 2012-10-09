import joos.lib.*;

public class Apple
{
    protected int x;
    protected int y;
    protected JoosRandom rand;
    public Apple(int boardx, int boardy, int seed)
    {
        super();
        rand = new JoosRandom(seed);
        this.randomize(boardx, boardy);
    }
    public int getX()
        {return x;}
    public int getY()
        {return y;}
    public void randomize(int boardx, int boardy)
    {
        x = rand.nextInt() % boardx;
        if(x < 0)
            x *= -1;
        y = rand.nextInt() % boardy;
        if(y < 0)
            y *= -1;
    }
}