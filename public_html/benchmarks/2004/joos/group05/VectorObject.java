// /*
//  * VectorObject.java
//  *
//  * Created on September 27, 2004, 8:20 AM
//  */

// /**
//  *
//  * @author  Denis Dube
//  */
public class VectorObject {
    
    protected int value;
    
//     /** Creates a new instance of VectorObject */
    public VectorObject( int integer ) {
        super();
        
        value = integer;
    }
    
    public int getValue(){
        return value;
    }
    
    public void setValue( int integer ){
        value = integer;
    }
    
}

