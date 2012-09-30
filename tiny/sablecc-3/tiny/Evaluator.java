package tiny;

import tiny.parser.*;
import tiny.lexer.*;
import tiny.node.*;
import tiny.analysis.*;
import java.util.*;

public class Evaluator extends DepthFirstAdapter
{
  /* (static) eval function */
  public static Node eval(Node ast)
  {
    Evaluator e = new Evaluator();
    ast.apply(e);
    return e.getValue(ast);
  }
    
  /* Hashtable, holding intermediate values for AST nodes */
  private Hashtable values = new Hashtable();

  /* Utility methods to set/get values for AST nodes */
  private void setValue(Node node, Node value)
  { values.put(node, value);
  }

  private int getIntValue(Node node)
  {
    return Integer.parseInt(((ANumberExp)node).getNumber().getText());
  }
  
  private void setIntValue(Node node, int value)
  {
    Node derp = new ANumberExp(new TNumber(value + ""));
    setValue(node, derp);
  }

  private Node getValue(Node node)
  { /* gets and removes the associated value.
       This reduces memory pressure, but you should 
       replace "remove" with "get" if you intend to
       lookup the same value more than once (e.g.: in
       an interpreter). */

    return (Node) values.remove(node);
  }

  /* We deal with each grammar alternative, one by one */

  /* AST root (hidden [start = exp;] production) */
  public void outStart(Start node)
  { setValue(node, getValue(node.getPExp())); }

  /* plus */ 
  public void outAPlusExp(APlusExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, getIntValue(left) + getIntValue(right));
    else if((left instanceof ANumberExp) && getIntValue(left) == 0)
      setValue(node, right);
    else if((right instanceof ANumberExp) && getIntValue(right) == 0)
      setValue(node, left);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }
  
  /* minus */
  public void outAMinusExp(AMinusExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, getIntValue(left) - getIntValue(right));
    else if((right instanceof ANumberExp) && getIntValue(right) == 0)
      setValue(node, left);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }

  /* mult */
  public void outAMultExp(AMultExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, getIntValue(left) * getIntValue(right));
    else if((left instanceof ANumberExp) && getIntValue(left) == 1)
      setValue(node, right);
    else if((right instanceof ANumberExp) && getIntValue(right) == 1)
      setValue(node, left);
    else if((left instanceof ANumberExp) && getIntValue(left) == 0)
      setIntValue(node, 0);
    else if((right instanceof ANumberExp) && getIntValue(right) == 0)
      setIntValue(node, 0);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }

  /* div */
  public void outADivdExp(ADivdExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((right instanceof ANumberExp) && getIntValue(right) == 0)
    {
      System.out.println("Division by zero error\n");
      System.exit(0);
    }
    else if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, getIntValue(left) / getIntValue(right));
    else if((right instanceof ANumberExp) && getIntValue(right) == 1)
      setValue(node, left);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }

  /* mod */
  public void outAModExp(AModExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((right instanceof ANumberExp) && getIntValue(right) == 0)
    {
      System.out.println("Modulus by zero error\n");
      System.exit(0);
    }
    else if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, getIntValue(left) % getIntValue(right));
    else if((right instanceof ANumberExp) && getIntValue(right) == 1)
      setIntValue(node, 0);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }

  /* pow */
  public void outAPowExp(APowExp node)
  {
    Node left = getValue(node.getL());
    Node right = getValue(node.getR());
    if((left instanceof ANumberExp) && (right instanceof ANumberExp))
      setIntValue(node, (int)Math.pow(getIntValue(left), getIntValue(right)));
    else if((left instanceof ANumberExp) && getIntValue(left) == 1)
      setIntValue(node, 1);
    else if((right instanceof ANumberExp) && getIntValue(right) == 1)
      setValue(node, left);
    else if((right instanceof ANumberExp) && getIntValue(right) == 0)
      setIntValue(node, 1);
    else
    {
      node.setL((PExp)left);
      node.setR((PExp)right);
      setValue(node, node);
    }
  }

  /* abs */
  public void outAAbsExp(AAbsExp node)
  {
    Node exp = getValue(node.getExp());
    if(exp instanceof ANumberExp)
      setIntValue(node, Math.abs(getIntValue(exp)));
    else
    {
      node.setExp((PExp)exp);
      setValue(node, node);
    }
  }

  /* identifier */
  public void outAIdExp(AIdExp node)
  {
    setValue(node, node);
  }
  
  /* number */
  public void outANumberExp(ANumberExp node)
  {
    setValue(node, node);
  }
}
