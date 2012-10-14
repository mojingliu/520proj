import joos.lib.*;

/* the node that manages changes to values at pointer */

public class ReadNode extends FuckNode {
    public ReadNode() {
        super();
    }
    public String codeGen(FuckStack stack) {
        return
            ";read: ,\n"+
            "dup2\n"+ 
            "getstatic java/lang/System/in Ljava/io/InputStream;\n"+
            "invokevirtual java/io/InputStream/read()I\n"+
            "; get lower 8 bits\n"+
            "sipush 255\n"+
            "iand\n"+
            "iastore\n"
            ;
    }
}