import joos.lib.*;

/* the node that manages changes to values at pointer */

public class ValueNode extends FuckNode {
    protected int amount; // the amount by which to change the value
    public ValueNode(int a) {
        super();
        amount = a;
    }

    /* generates assembler for '+' and '-' */
    public String codeGen(FuckStack stack) {
        return 
            "; increase/decrease value at pointer: +- \n"+
            "dup2\n"+
            "dup2\n"+
            "iaload\n"+
            "sipush "+amount+"\n"+
            "iadd\n"+
            "iastore\n"
            ;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int a) {
        amount = a;
    }
}