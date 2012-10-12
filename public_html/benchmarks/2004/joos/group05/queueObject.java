// /*
//  * queueObject.java
//  *
//  * Created on September 27, 2004, 8:39 AM
//  */

// /**
//  *
//  * @author  Denis Dube
//  */
public class queueObject {
    
    protected int value;
    protected queueObject next;
    
//     /** Creates a new instance of queueObject */
    public queueObject( int integer ) {
        super();
        value = integer;
        next = null;
    }
    
    public int getValue(){
        return value;
    }
    

    public void setValue( int integer ){
        value = integer;
    }
    
    public queueObject getNextObject(){
        return next;
    }
    
    public void setNextObject( queueObject nextObj ){
        next = nextObj;
    }
    
}

