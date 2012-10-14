// /*
//  * Main.java
//  *
//  * Created on September 26, 2004, 4:52 PM
//  */
import joos.lib.*;
// /**
//  *
//  * @author  Denis Dube
//  */
public class Main {
    
//     /** Creates a new instance of Main */
    public Main( int vectorSize, int queueSize ) {
        super();
        
//         /* Run Benchmark 1 
//          * Uses a double for loop to run +-/* operations
//          * Tests final result against known value
//          * NOTE: Test size is fixed (otherwise can't test 
//          * if the result is correct with a constant).
//          */
        new Arithmetic();
        
//         /* Run Benchmark 2
//          * Fills a vector with random integers and checks
//          * that the last entered number is correctly stored.
//          * Parameter = size of vector
//          * NOTE: Random integers are deterministic (seeded @ 0)
//          */
        new VectorTest( vectorSize );
        
//         /* Run Benchmark 3
//          * Fills a vector with random integers and an object
//          * oriented queue simultaneously. When done, runs
//          * an element by element comparison between the vector
//          * and the queue.
//          * Parameter = size of vector & queue
//          * NOTE: Random integers are deterministic (seeded @ 0)
//          */
        new QueueTest( queueSize );
    }
    
//     /**
//      * @param args the command line arguments
//      */
    public static void main(String[] args) {
//          /*
//         int numberOfArgs;
//         numberOfArgs = args.length;
        
//         if( numberOfArgs == 3 ){
//             new Main( Integer.parseInt( args[1] ),
//                       Integer.parseInt( args[2] ) );
//         }else{
//             new Main( 10000, 10000 );
//         }
//         */
        JoosIO f;
        int v;
        int q;
        
        f = new JoosIO();
        
        f.print("\nPlease enter an integer size for the vector test"); 
        v = f.readInt(); 
                
        f.print("\nPlease enter an integer size for the queue test"); 
        q = f.readInt(); 
        
        f.println("\n\n-------------------------------------------"); 
        f.print("\nStarting Benchmark Suite:"); 
        
        f.println("\n1) Arithemetic test with 1000*1000 repetitions");
        
        f.print("\n2) Vector storage of random elements with vector size: ");
        f.println((new Integer(v)).toString());
        
        f.print("\n3) Object oriented queue of random elements of size: ");
        f.println((new Integer(q)).toString());
        
        f.println("\n-------------------------------------------\n"); 
        
        new Main( v, q);
        
        f.println("\n-------------------------------------------"); 
        
    }
    
}

