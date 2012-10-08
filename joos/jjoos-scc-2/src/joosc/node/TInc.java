/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class TInc extends Token
{
    public TInc()
    {
        super.setText("++");
    }

    public TInc(int line, int pos)
    {
        super.setText("++");
        setLine(line);
        setPos(pos);
    }

    public Object clone()
    {
      return new TInc(getLine(), getPos());
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseTInc(this);
    }

    public void setText(String text)
    {
        throw new RuntimeException("Cannot change TInc text.");
    }
}