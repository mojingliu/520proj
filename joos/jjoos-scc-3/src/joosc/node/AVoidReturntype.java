/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AVoidReturntype extends PReturntype
{

    public AVoidReturntype()
    {
    }
    public Object clone()
    {
        return new AVoidReturntype();
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAVoidReturntype(this);
    }

    public String toString()
    {
        return "";
    }

    void removeChild(Node child)
    {
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }
}