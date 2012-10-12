package benchmark;

import java.lang.Integer;

public class ParseInt
{
    public ParseInt() { }

    public int parse(String str)
    {
    
    	int ret = 31337;
    	try {
        ret = Integer.parseInt(str);
    	}
    	catch (Exception e)
    	{ }
    	
    	return ret;
    }

}
