/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AThisExp extends PExp
{
    private TThis _this_;

    public AThisExp()
    {
    }

    public AThisExp(
        TThis _this_)
    {
        setThis(_this_);

    }
    public Object clone()
    {
        return new AThisExp(
            (TThis) cloneNode(_this_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAThisExp(this);
    }

    public TThis getThis()
    {
        return _this_;
    }

    public void setThis(TThis node)
    {
        if(_this_ != null)
        {
            _this_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _this_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_this_);
    }

    void removeChild(Node child)
    {
        if(_this_ == child)
        {
            _this_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_this_ == oldChild)
        {
            setThis((TThis) newChild);
            return;
        }

    }
}
