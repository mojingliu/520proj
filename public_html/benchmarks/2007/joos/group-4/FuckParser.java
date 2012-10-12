import joos.lib.*;

public class FuckParser {
    public FuckParser() {
        super();
    }

    /* returns appropriate node for given bf commannd */
    public FuckNode getNode(char c) {
        FuckIO io;
        FuckNode res;

        io = new FuckIO();

        if(c == '+') { res = new ValueNode(1); } else
        if(c == '-') { res = new ValueNode(-1); } else
        if(c == '<') { res = new PointerNode(-1); } else
        if(c == '>') { res = new PointerNode(1); } else 
        if(c == '[') { res = new LeftBracketNode(); } else
        if(c == ']') { res = new RightBracketNode(); } else 
        if(c == '.') { res = new WriteNode(); } else
        if(c == ',') { res = new ReadNode(); } else
            { res = null; }
        return res;
    }

    /* returns a list of nodes representing the program.  Reason for
       not generating directly from the string is in case we wanted to
       do a pass to consolidate <> and +- nodes, may or may not
       implement it */
    public FuckNode parse(String prog) {
        FuckNode head; // pointer to head of program list
        FuckNode end; // pointer to end of program list, for appending
        int i; // index in program string
        int l; // length of program string
        FuckParser parser;
        parser = new FuckParser();
        head = null;
        end = null;

        /* run through the program, generating the "AST" */
        l = prog.length();
        for( i = 0; i < l; i++) { /* start at 1 to skip the head node */
            FuckNode node;
            node = parser.getNode(prog.charAt(i));


            if(node != null) {
                if(head == null) {
                    head = node;
                }
                if(end != null) { end.setNext(node); }
                end = node;
            }
        }

        return head; // return the program, which starts at head
    }
}