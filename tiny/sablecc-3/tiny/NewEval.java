package tiny;

import tiny.parser.*;
import tiny.lexer.*;
import tiny.node.*;
import tiny.analysis.*;
import java.util.*;

public class NewEval extends DepthFirstAdapter
{
  /* (static) eval function */
  public static void replaceUminus(Node ast)
  {
    NewEval e = new NewEval();
    ast.apply(e);
  }

  public void outAUminusExp(AUminusExp node)
  {
    AMinusExp newExp = new AMinusExp();
    newExp.setL(new ANumberExp(new TNumber("0")));
    newExp.setR(node.getExp());
    node.replaceBy(newExp);
    newExp.apply(this);
  }
  
}
