// /*
//  * VectorTest.java
//  *
//  * Created on September 27, 2004, 7:55 AM
//  */

import joos.lib.*;
import java.util.*; 
// /**
//  *
//  * @author  Denis Dube
//  */
public class VectorTest {
    
//     /** Creates a new instance of VectorTest */
    public VectorTest( int vectorSize ) {
        
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
        array = new Vector(vectorSize);
        failureFlag = false;
        
	i = 0;
        while(i<vectorSize){
            // Generate vector data item
            randVar = randGen.nextInt();
            vObj = new VectorObject( randVar );
            array.addElement( vObj  );   
            
            // Check if last element correctly inserted in Vector
            vObj = (VectorObject) array.elementAt(i);
            if( vObj.getValue() != randVar ){           
                failureFlag = true;
            }
            i = i + 1;
        }
        
        if( failureFlag == false ){        
            f.println("Vector Test -------------- PASSED");
        }else{
            f.println("Vector Test -------------- FAILED");
        }
        
        
    }
    
}

