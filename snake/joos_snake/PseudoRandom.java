public class PseudoRandom
{
    protected int counter;
    public PseudoRandom(String seed)
    {
        super();
        seed = seed.toUpperCase();
        int c;
        int i;
        int product;
        product = 1;
        counter = 0;
        for(i = 0; i < seed.length(); i++)
        {   // accepts 32 to 95
            c = seed.charAt(i) - 32;
            if(!(c < 0 || c >= 64))
            {
                counter += product * c;
                product *= 64;
            }
        }
    }

    public int randint(int from, int to)
    {  // inclusive
        int toR;
        toR = (int)((to - from) * Math.abs(this._noise(counter))) + from;
        counter++;
        return toR;
    }

    public double _noise(int x)
    {
        x = (x<<13) ^ x;
        return (1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
    }
}