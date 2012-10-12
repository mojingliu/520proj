
public class FullAdder {

    protected boolean input_a;
    protected boolean input_b;
    protected boolean input_c; // carry

    protected BooleanSignal sum_output;
    protected BooleanSignal carry_output;

    public FullAdder() {
        super();
        input_a = false;
        input_b = false;
        input_c = false;
        
        sum_output = null;
        carry_output = null;
    }

    public void setSum(BooleanSignal bs) { 
        sum_output = bs;
        this.update();
    }
    public void setCarryOut(BooleanSignal bs) { 
        carry_output = bs;
        this.update();
    }

    public void setInput(boolean i, boolean v) {
        if (!i) input_a = v;
        else input_b = v;
        this.update();
    }
    public void setCarryIn(boolean v) { 
        input_c = v; 
        this.update();
    }

    public void update() {
        if (sum_output != null)
            sum_output.setValue(input_a != input_b != input_c);
        if (carry_output != null)
            carry_output.setValue(input_a && input_b
                               || input_b && input_c 
                               || input_c && input_a);
    }
}

