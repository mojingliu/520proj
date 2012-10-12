
// pair, for use as a lisp-style cons, to get really slow sequences
public class Pair {

    protected Object first;
    protected Object second;
    
    public Pair(Object f, Object s) {
        super();
        first = f;
        second = s;
    }
    
    public Object getFirst() { return first; }
    public void setFirst(Object value) { first = value; }

    public Object getSecond() { return second; }
    public void setSecond(Object value) { second = value; }

    public Object getN(int n) { 
        if (n == 0) return this.getFirst(); 
        else return ((Pair)this.getSecond()).getN(n-1);
    }
    public void setN(int n, Object value) { 
        if (n == 0) this.setFirst(value); 
        else ((Pair)this.getSecond()).setN(n-1, value);
    }
}

