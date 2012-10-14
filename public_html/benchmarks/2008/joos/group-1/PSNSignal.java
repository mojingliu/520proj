
// BooleanSignal Implementation to set the i-th element in
//  a pair-list to null or non-null
public class PSNSignal extends BooleanSignal {

    protected Pair p;
    protected int i;

    public PSNSignal(Pair p_, int i_) {
        super();
        p = p_;
        i = i_;
    }
    
    public void handleValue() {
        if (value) 
            p.setN(i, this);
        else 
            p.setN(i, null);
    }

    public /*final*/ void setValue(boolean n) {
        if (value != n) {
            value = n;
            this.handleValue();
        }
    }

}

