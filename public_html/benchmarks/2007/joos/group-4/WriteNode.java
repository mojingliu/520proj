import joos.lib.*;

/* the node that manages changes to values at pointer */

public class WriteNode extends FuckNode {
    public WriteNode() {
        super();
    }
    public String codeGen(FuckStack stack) {
        return 
            ";output value at current position: .\n"+
            "dup2\n"+
            "iaload\n"+
            "getstatic java/lang/System/out Ljava/io/PrintStream;\n"+
            "swap\n"+
            "i2c\n"+
            "invokevirtual java/io/PrintStream/print(C)V\n"
            ;
    }
}