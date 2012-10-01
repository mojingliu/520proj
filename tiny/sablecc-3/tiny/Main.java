package tiny;

import tiny.parser.*;
import tiny.lexer.*;
import tiny.node.*;
import java.io.*;
 
class Main {
  public static void main(String args[]) {
    try {
      System.out.println("Type in a tiny exp folowed by one or two Ctrl-d's:");
      Parser p = 
         new Parser (
           new Lexer (
              new PushbackReader(new InputStreamReader(System.in), 1024)));
      
      Start tree = p.parse();
      NewEval.replaceUminus(tree);
      /* pretty-print */
      System.out.println("\nThe result of evaluating:");
      PrettyPrinter.print(tree);

      /* pre-eval to replace uminus */
      

      /* evaluate */
      System.out.print("\nis: ");
      PrettyPrinter.print(Evaluator.eval(tree));
      System.out.println("\n");

    } 
   catch(Exception e) 
    { System.out.println(e); }
  }
}
