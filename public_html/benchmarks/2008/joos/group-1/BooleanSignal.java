
public abstract class BooleanSignal {

    protected boolean value;

    public BooleanSignal() {
        super();
        value = false;
    }
    
    public abstract void handleValue();
    
    public /*final*/ void setValue(boolean n) {
        if (value != n) {
            value = n;
            this.handleValue();
        }
    }

}
