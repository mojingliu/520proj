import joos.lib.*;

/* the node that manages changes to values at pointer */

public class LeftBracketNode extends FuckNode {
    public LeftBracketNode() {
        super();
    }
    public String codeGen(FuckStack stack) {
        return 
            ";left bracket, beginning of while loop: [ (jump forward to the command after the corresponding ] if the byte at the pointer is zero.)\n"+
            "dup2\n"+
            "iaload\n"+
            "ifeq label_end_"+stack.push()+"\n"+
            "label_begin_"+stack.peek()+":\n"
            ;
    }
}