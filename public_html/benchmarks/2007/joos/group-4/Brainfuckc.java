import joos.lib.*;

/* implements a brainfuck to jasmin assembler compiler */
public class Brainfuckc {
  
    public Brainfuckc() {
        super();
    }

    public static void main (String[] argv) {
        FuckIO io;
        FuckParser parser;
        FuckPrinter printer;
        FuckStack stack;
        FuckNode program;
        FuckNode fnode;
        String input;
        String arraySize;
        String initialIndex;
        String className;
	FuckOptimizer optimizer;


        io = new FuckIO();
        parser = new FuckParser();
        printer = new FuckPrinter();
        arraySize = "30000"; //change if desired
        initialIndex = "0"; //change if desired
        className = "BrainfuckOut"; //change if desired
        /* read input into string */
        input = io.readStdin();
        program = parser.parse(input);
	optimizer = new FuckOptimizer();
	optimizer.simplify(program);
  /* parse input to node list */
        //printer.print(program); /* sanity check: print the list back out */
        
        
        /* outputting class header */
        io.print(".class public "+className+"\n" +
                 ".super java/lang/Object\n" +
                 ".method public <init>()V\n" +
                 ".limit locals 1\n" +
                 ".limit stack 25\n" +
                 "aload_0\n" +
                 "invokenonvirtual java/lang/Object/<init>()V\n" +
                 "return\n" +
                 ".end method\n" +
                 "\n" +
                 ".method public static main([Ljava/lang/String;)V\n" +
                 ".limit locals 3\n" +
                 ".limit stack 25\n" +
                 ".throws java/io/IOException\n" +
                 "; push size of array and create array\n" +
                 "sipush "
                 );
        io.printLine(arraySize);
        io.print(
                 "newarray int\n" +
                 "; push initial index\n" +
                 "sipush "
                 );
        io.printLine(initialIndex);
         
         
        /* outputting code of the main function */
        stack = new FuckStack();
        for(fnode = program;fnode != null; fnode = fnode.getNext()){
           io.printLine(fnode.codeGen(stack));
        }
        /* outputting footer */
        io.printLine("return");
        io.printLine(".end method");
        io.printLine(" ");
    }
}
