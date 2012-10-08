/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class TTry extends Token
{
    public TTry()
    {
        super.setText("try");
    }

    public TTry(int line, int pos)
    {
        super.setText("try");
        setLine(line);
        setPos(pos);
    }

    public Object clone()
    {
      return new TTry(getLine(), getPos());
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseTTry(this);
    }

    public void setText(String text)
    {
        throw new RuntimeException("Cannot change TTry text.");
    }
}