import joos.lib.*;

public class Main {

    protected int N;

    public Main() {
        super();
        N = 32;
    }

    public Pair genList(int n) {
        Pair p;
        
        for (p = null; n != 0; n = n - 1) {
            p = new Pair(null, p);        
        }
        
        return p;
    }

    public int add(int a, int b) {
        JoosIO io;

        int i;
        int c;

        Pair alu;
        Pair result;

        io = new JoosIO();
        
        // initialize the full adders
        alu = this.genList(N);
        for (i = 0; i < N; i++) alu.setN(i, new FullAdder());

        // initialize the result register
        result = this.genList(N);
    
        // connect the output register
        for (i = 0; i < N; i++) {
            FullAdder curr;
            curr = (FullAdder)alu.getN(i);
            curr.setSum(new PSNSignal(result, i));
        }

        // connect the carries
        for (i = 1; i < N; i++) {
            FullAdder prev;
            FullAdder curr;
            prev = (FullAdder)alu.getN(i-1);
            curr = (FullAdder)alu.getN(i);
            prev.setCarryOut(new FAISignal(curr));
        }
    
/*    
        // set the input bits
        for (i = 0; i < N; i++) {
            FullAdder curr;
            curr = (FullAdder)alu.getN(i);
            curr.setInput(false, a % 2 == 1); a = a / 2;
            curr.setInput(true,  b % 2 == 1); b = b / 2;
        }
*/
        for (i = 0; i < N; i++) {
            FullAdder curr;
            curr = (FullAdder)alu.getN(i);
            curr.setInput(false, a % 2 == 1); a = a / 2;
        }
        for (i = 0; i < N; i++) {
            FullAdder curr;
            curr = (FullAdder)alu.getN(i);
            curr.setInput(true,  b % 2 == 1); b = b / 2;
        }
    
        // read the result
        c = 0;
        for (i = N-1; i >= 0; i = i-1) {
            c = c * 2;
            if (result.getN(i) != null) c = c + 1;
        }

        return c;
    }

    public static void main(String[] args) {
        Main m;
        JoosIO io;
        int accum;
        int i;
        
        m = new Main();
        io = new JoosIO();

        accum = 0; 
        io.println("" + accum);
        while (true) {
            int x;
            
            x = io.readInt();
            io.println("Adding " + x + "...");
            if (false) {
                // Obvious Way
                accum = accum + x;
            } else {
                // "Optimized" Way
                accum = m.add(accum, x);
            }
            io.println("" + accum);
        }
        
    }

}

