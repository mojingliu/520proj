// /*
//  * QueueTest.java
//  *
//  * Created on September 27, 2004, 9:01 AM
//  */

import joos.lib.*;
import java.util.*;
// /**
//  *
//  * @author  Denis Dube
//  */
public class QueueTest {
    
//     /** Creates a new instance of QueueTest */
    public QueueTest( int size ) {
        
        super();
        
        JoosIO f;
        
        Vector array;
        VectorObject vObj;
        simpleQueue queue; 
             
        JoosRandom randGen;
        
        int randVar;
        int i;
	boolean failureFlag;
                
        f = new JoosIO();
        
        randGen = new JoosRandom(0);
        array = new Vector(size);
        queue = new simpleQueue();
        failureFlag = false;
        
//         /* Generate random data (deterministically seeded)
//          * and store it in a Vector and a Queue
//          * Then compare the Vector and Queue to see if they
//          * agree!
//          */
	i = 0;
        while(i<size){
            randVar = randGen.nextInt();
            vObj = new VectorObject( randVar );
            array.addElement( vObj  );   
            queue.addToQueue( randVar );     
	    i = i + 1;
        }
        
//         /* Validity check */
        queue.moveToQueueHead();
	i = 0;
        while(i<size){
            vObj = (VectorObject) array.elementAt(i);  
            randVar = queue.getNextQueuedObject();    
            if( vObj.getValue() != randVar ){   
                failureFlag = true;
            }
	    i = i + 1;
        }
        
        
        if( failureFlag == false ){        
            f.println("Queue Test --------------- PASSED");
        }else{
            f.println("Queue Test --------------- FAILED");
        }
        
    }
    
}

