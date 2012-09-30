package tiny;

import tiny.parser.*;
import tiny.lexer.*;
import tiny.node.*;
import tiny.analysis.*;
import java.util.*;

public class PrettyPrinter extends DepthFirstAdapter {
  public static void print(Node node) {
      node.apply(new PrettyPrinter());
  }

  private void puts(String s) {
      System.out.print(s);
      System.out.flush();
  }

  private static boolean parenMe(Node node, int level)
  {
    if(level >= 1 && (node instanceof APlusExp || node instanceof AMinusExp))
      return true;
    if(level >= 2 && (node instanceof AMultExp || node instanceof ADivdExp || node instanceof AModExp))
      return true;
    if(level >= 3 && (node instanceof APowExp))
      return true;
    return false;
  }

  /* plus */ 
  public void caseAPlusExp(APlusExp node) {
      //puts("(");
      boolean parenit = false;
      Node left = node.getL();
      parenit = parenMe(left, 0);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("+");
      Node right = node.getR();
      parenit = parenMe(right, 1);
      if(parenit)
        puts("(");
      right.apply(this);
      if(parenit)
        puts(")");
  }

  /* minus */
  public void caseAMinusExp(AMinusExp node) { 
      boolean parenit = false;
      Node left = node.getL();
      parenit = parenMe(left, 0);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("-");
      Node right = node.getR();
      parenit = parenMe(right, 1);
      if(parenit)
        puts("(");
      right.apply(this);
      if(parenit)
        puts(")");
  }

  /* mult */
  public void caseAMultExp(AMultExp node) { 
      boolean parenit;
      Node left = node.getL();
      parenit = parenMe(left, 1);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("*");
      Node right = node.getR();
      parenit = parenMe(right, 2);
      if(parenit)
        puts("(");
      node.getR().apply(this);
      if(parenit)
        puts(")");
  }

  /* div */
  public void caseADivdExp(ADivdExp node) {
      boolean parenit;
      Node left = node.getL();
      parenit = parenMe(left, 1);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("/");
      Node right = node.getR();
      parenit = parenMe(right, 2);
      if(parenit)
        puts("(");
      node.getR().apply(this);
      if(parenit)
        puts(")");
  }

  /* mod */
  public void caseAModExp(AModExp node) {
      boolean parenit;
      Node left = node.getL();
      parenit = parenMe(left, 1);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("%");
      Node right = node.getR();
      parenit = parenMe(right, 2);
      if(parenit)
        puts("(");
      node.getR().apply(this);
      if(parenit)
        puts(")");
  }

  /* abs */
  public void caseAAbsExp(AAbsExp node) {
    puts("abs(");
    node.getExp().apply(this);
    puts(")");
  }

  /* pow */
  public void caseAPowExp(APowExp node) {
      boolean parenit;
      Node left = node.getL();
      parenit = parenMe(left, 3);
      if(parenit)
        puts("(");
      left.apply(this);
      if(parenit)
        puts(")");
      puts("**");
      Node right = node.getR();
      parenit = parenMe(right, 2);
      if(parenit)
        puts("(");
      node.getR().apply(this);
      if(parenit)
        puts(")");
  }

  /* identifier */
  public void caseAIdExp(AIdExp node) {
      puts(node.getId().getText());
  }
  
  /* number */
  public void outANumberExp(ANumberExp node) {
      puts(node.getNumber().getText());
  }
}
