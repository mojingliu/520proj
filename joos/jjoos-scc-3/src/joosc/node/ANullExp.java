/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ANullExp extends PExp
{

    public ANullExp()
    {
    }
    public Object clone()
    {
        return new ANullExp();
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseANullExp(this);
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
