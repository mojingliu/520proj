
// BooleanSignal implementation to set the carry_in of a FullAdder
public class FAISignal extends BooleanSignal {

    protected FullAdder fa;
    
    public FAISignal(FullAdder fa_) {
        super();
        fa = fa_;
    }

    public void handleValue() {
        fa.setCarryIn(value);
    }

    public /*final*/ void setValue(boolean n) {
        if (value != n) {
            value = n;
            this.handleValue();
        }
    }

}

