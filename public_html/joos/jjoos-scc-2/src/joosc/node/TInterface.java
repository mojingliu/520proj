/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class TInterface extends Token
{
    public TInterface()
    {
        super.setText("interface");
    }

    public TInterface(int line, int pos)
    {
        super.setText("interface");
        setLine(line);
        setPos(pos);
    }

    public Object clone()
    {
      return new TInterface(getLine(), getPos());
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseTInterface(this);
    }

    public void setText(String text)
    {
        throw new RuntimeException("Cannot change TInterface text.");
    }
}
