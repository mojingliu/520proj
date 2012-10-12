import joos.lib.*;

/* implements a "pretty printer" used as a sanity check ensure bf
   code is read/parsed in correctly */
public class FuckPrinter {
    public FuckPrinter() {
        super();
    }

    /* For the nodes with an amount, we want to print out the correct
       io.print(printernumber of commands; lots of instanceof fun */
    public String stringOfNode(FuckNode n) {
        if(n instanceof PointerNode) {
            PointerNode p;
            StringBuffer buf;
            String s;
            int amt;
            int i;
            buf = new StringBuffer();
            p = (PointerNode) n;
            /* deal with +/- amounts */
            if(p.getAmount() >= 0) {
                s = ">";
                amt = p.getAmount();
            } else {
                s = "<";
                amt = -p.getAmount();
            }
            
            /* generate the correct number of commands */
            for( i = 0; i < amt; i++) {
                buf.append(s);
                }
                return buf.toString();
        }
        
        if(n instanceof ValueNode) {
            ValueNode v;
            StringBuffer buf;
            String s;
            int amt;
            int i;
            buf = new StringBuffer();
            v = (ValueNode) n;

            /* deal with +/- amounts */
            if(v.getAmount() >= 0) {
                s = "+";
                amt = v.getAmount();
            } else {
                s = "-";
                amt = -v.getAmount();
            }

            /* generate the correct number of commands */
            for( i = 0; i < amt; i++) {
                buf.append(s);
                }
                return buf.toString();
        }
        // ,        
        if(n instanceof ReadNode) {
            return ",";
        }
        // .
        if(n instanceof WriteNode) {
            return ".";
        }
        // [
        if(n instanceof LeftBracketNode) {
            return "[";
        }
        // ]
        if(n instanceof RightBracketNode) {
            return "]";
        }
        return ""; /* in case we slip through somehow? */
    }

    /* prints the program starting at node n to stdout */    
    public void print(FuckNode n) {
        FuckPrinter printer;
        FuckIO io;
        io = new FuckIO();
        printer = new FuckPrinter();
        /* loop through the list, print out the commands */
        while(n != null){
            io.print(printer.stringOfNode(n));
            n = n.getNext();
        }
    }
}
