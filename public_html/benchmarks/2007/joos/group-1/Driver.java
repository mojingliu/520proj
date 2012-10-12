import java.util.StringTokenizer;
import java.util.Vector;

import joos.lib.JoosIO;

/**
 * A program for finding strongly connected components of a directed graph.
 * Reads the list of edges from stdin in node-node pairs.
 * Writes the list of components to stdout.
 */
public class Driver {

	public Driver() {
		super();
	}

    //find and return the smallest int in Vector v
    /** NOTE: this is an unused method, i.e. dead code */
    public Integer vectorMin(Vector v) {
        Integer current, min;
        int i;
        min = (Integer)v.firstElement();
        i = 0;
        while (i < v.size()) {
            current = (Integer)v.elementAt(i);
            if (current.intValue() < min.intValue())
                min = current;
            i = i + 1;
        }
        return min;
    }
    
    
	public static void main(String[] args) {
		Graph g;
		JoosIO io, io2; //note: io2 is not used
		String line;
		int x; //note: x is never read
        int Y; //declared but never used
		
		;{;} //note: pointless
		
		io = null; //note: pointless (immediately overwritten)
		io = new JoosIO();
		io = io; //note: pointless (no effect)
		
		g = new GraphImpl();
		/* cannot change to for loop, neither accepted by a+ */
		line = io.readLine();
		while(line != null && line.length() > 0) {
			StringTokenizer tok;
			tok = new StringTokenizer(line);
			g.addEdge(tok.nextElement(), tok.nextElement());
			line = io.readLine();
			
			x = 2; //note: pointless (never read)
		}
		
		{
			int i;
			Vector allComponents;
            Vector p;
			
			allComponents = g.getStronglyConnectedComponents();
            
            p = (Vector) (Object) ((Vector) allComponents); //pointless casting
            p.size();
            
			i = 0;
			while(i < allComponents.size()) {
				int j;
				Vector component;
				String componentString;

				componentString = "";
				component = (Vector) allComponents.elementAt(i);
				j = 0;
				
				while(j < component.size()) {
					componentString = componentString + component.elementAt(j);
					componentString = componentString + " ";
					
					j = -(-j) - (-1); //note: folding opportunity
					
					x = i * j + (2 * 3) - (j * i) - 6; //note: pointless (never read)
				}
				
				io.println(componentString);
				
				i = (-(-1)) - (-i); //note: folding opportunity
			}
		}
	}

}
