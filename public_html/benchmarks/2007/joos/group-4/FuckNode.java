import joos.lib.*;

/* abstract class for the syntax nodes for brainfuck */

public abstract class FuckNode {
    protected FuckNode next;
    public FuckNode() {
        super();
        next = null;
    }

    public void setNext(FuckNode n) {
        next = n;
    }

    public FuckNode getNext() {
        return next;
    }

    public abstract String codeGen(FuckStack stack);
}