
import joos.lib.*;

 // @author  Denis Dube

public class Arithmetic {
    
    // Creates a new instance of Arithmetic
    public Arithmetic() {
        super();
        
        JoosIO f;
        int intSum;
        int i;
        int j;
                    
        f = new JoosIO();
        
        intSum = 0;
	i = 1;
	while (i < 1000) {

	    j = 1;
	    while (j < 1000) {
		
                intSum = -123 + intSum + i / j + 2 * i + 2 * j - 2 * ( i + j ) + 123;
		j = j + 1;
            }
	    i = i + 1;
        }
        
        if( intSum == 3281346 ){        
            f.println("Arithmetic Test ---------- PASSED");
        }else{
            f.println("Arithmetic Test ---------- FAILED");
        }
    }
    
}

