public class Apple
{
    protected int x;
    protected int y;
    //protected PseudoRandom rand;
    public Apple(int boardx, int boardy, String seed)
    {
        super();
        //rand = new PseudoRandom(seed);
        this.randomize(boardx, boardy);
    }
    public int getX()
        {return x;}
    public int getY()
        {return y;}
    public void randomize(int boardx, int boardy)
    {
        x = 3;
        y = 3;
        //x = rand.randint(0, boardx - 1);
        //y = rand.randint(0, boardy - 1);
    }
}