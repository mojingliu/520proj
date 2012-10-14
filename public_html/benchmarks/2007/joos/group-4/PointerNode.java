import joos.lib.*;

/* the node that manages changes to the pointer */

public class PointerNode extends FuckNode {
    protected int amount; // the amount by which to change the pointer
    public PointerNode(int a) {
        super();
        amount = a;
    }
    public String codeGen(FuckStack stack) {
        return 
            ";move pointer: <>\n"+
            "sipush "+amount+"\n"+
            "iadd";
    }
    public int getAmount() {
        return amount;
    }
    public void setAmount(int a) {
        amount = a;
    }
}