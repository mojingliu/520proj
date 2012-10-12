import java.util.*; 

public class BitMap {
   
    protected TwoDVector map;

    //-----------------------------------------------------------
    //  bitMap constructor
    // 	Initialize a bitmap with "numItems*numItems" bits, so that 
    // 	every bit is clear.
    //	it can be added somewhere on a list.
    //
    //	"numItems*numItems" is the number of bits in the bitmap.
    //-------------------------------------------------------------

    public BitMap(int numItems) { 
	    super();

	    int i;
	    int j;
	    Integer zero;

	    map = new TwoDVector();
	    map.create(numItems,numItems);
	    i=0;
	    j=0;
	
	    while (i<numItems){
	        j=0;
	        while (j<numItems){
		        zero = new Integer(0);
		        map.setElem(i,j,zero);	// initialize map
		        j=j+1;
	        }
	        i=i+1;
	    }
    }


    //---------------------------------------------------------
    //  mark
    // 	Set the "nth" by "mth" bit in a bitmap.
    //
    //	"n by m" is the number of the bit to be set.
    //---------------------------------------------------------

    public void mark(int nth, int mth) { 
	    Integer one;
	    one = new Integer(1);
	    map.setElem(nth,mth,one);
    }
    
    //----------------------------------------------------------
    //  clear
    // 	Clear the "nth" by "mth" bit in a bitmap.
    //
    //	"n by m" is the number of the bit to be cleared.
    //---------------------------------------------------------

    public void clear(int nth, int mth) {
	    Integer zero;
	    zero = new Integer(0);
	    map.setElem(nth,mth,zero);
    }

    //---------------------------------------------------------
    //  check
    // 	Check if the "nth" by "mth" bit in a bitmap is set.
    //
    //	return true if map[nth][mth] = 1
    //---------------------------------------------------------
    //
    public boolean check(int nth, int mth) {
	    Integer one;
	    Integer fromMap;
	    one = new Integer(1);
	    fromMap = (Integer)map.getElem(nth,mth);

        if (fromMap.intValue() == one.intValue()) {
	        return true;
	    }
	    else {
	        return false;
	    }

    }

}

