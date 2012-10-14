import joos.lib.*;

/* the node that manages changes to values at pointer */

public class RightBracketNode extends FuckNode {
    public RightBracketNode() {
        super();
    }
    public String codeGen(FuckStack stack) {
        return 
            ";right bracket: ] (jump back to the command after the corresponding [ if the byte at the pointer is nonzero.)\n"+
            "dup2\n"+
            "iaload\n"+
            "ifne label_begin_"+stack.peek()+"\n"+
            "label_end_"+stack.pop()+":\n"
            ;
    }
}