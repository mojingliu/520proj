/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ATrueLiteral extends PLiteral
{
    private TTrue _true_;

    public ATrueLiteral()
    {
    }

    public ATrueLiteral(
        TTrue _true_)
    {
        setTrue(_true_);

    }
    public Object clone()
    {
        return new ATrueLiteral(
            (TTrue) cloneNode(_true_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseATrueLiteral(this);
    }

    public TTrue getTrue()
    {
        return _true_;
    }

    public void setTrue(TTrue node)
    {
        if(_true_ != null)
        {
            _true_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _true_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_true_);
    }

    void removeChild(Node child)
    {
        if(_true_ == child)
        {
            _true_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_true_ == oldChild)
        {
            setTrue((TTrue) newChild);
            return;
        }

    }
}
