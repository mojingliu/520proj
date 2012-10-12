// /*
//  * simpleQueue.java
//  *
//  * Created on September 27, 2004, 8:37 AM
//  */

// /**
//  *
//  * @author  Denis Dube
//  */
public class simpleQueue {
    
    protected queueObject queueHead;
    protected queueObject queueCurrent;
    protected queueObject tempQueue;
    
//     /** Creates a new instance of simpleQueue */
    public simpleQueue() {
        super();
        queueHead = null;
        queueCurrent = null;
    }
    
    public void addToQueue( int integer ){
        if( queueHead == null ){
            queueHead = new queueObject( integer );
            queueCurrent = queueHead;
        }else{
            tempQueue = new queueObject( integer );
            queueCurrent.setNextObject( tempQueue );
            queueCurrent = tempQueue;
        }
    }
    
    public void moveToQueueHead(){
        queueCurrent = queueHead;
    }
    
    public int getNextQueuedObject(){
        int value;
        if(queueCurrent == null ){
            return -1234567;
        }else{
            value = queueCurrent.getValue();
            queueCurrent = queueCurrent.getNextObject();
            return value;
        }
    }
    
    
}

