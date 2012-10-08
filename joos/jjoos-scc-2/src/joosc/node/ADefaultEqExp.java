/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ADefaultEqExp extends PEqExp
{
    private PRelExp _relExp_;

    public ADefaultEqExp()
    {
    }

    public ADefaultEqExp(
        PRelExp _relExp_)
    {
        setRelExp(_relExp_);

    }
    public Object clone()
    {
        return new ADefaultEqExp(
            (PRelExp) cloneNode(_relExp_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseADefaultEqExp(this);
    }

    public PRelExp getRelExp()
    {
        return _relExp_;
    }

    public void setRelExp(PRelExp node)
    {
        if(_relExp_ != null)
        {
            _relExp_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _relExp_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_relExp_);
    }

    void removeChild(Node child)
    {
        if(_relExp_ == child)
        {
            _relExp_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_relExp_ == oldChild)
        {
            setRelExp((PRelExp) newChild);
            return;
        }

    }
}
