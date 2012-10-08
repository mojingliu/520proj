/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class TChar extends Token
{
    public TChar()
    {
        super.setText("char");
    }

    public TChar(int line, int pos)
    {
        super.setText("char");
        setLine(line);
        setPos(pos);
    }

    public Object clone()
    {
      return new TChar(getLine(), getPos());
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseTChar(this);
    }

    public void setText(String text)
    {
        throw new RuntimeException("Cannot change TChar text.");
    }
}
