/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AIntType extends PType
{
    private TInt _int_;

    public AIntType()
    {
    }

    public AIntType(
        TInt _int_)
    {
        setInt(_int_);

    }
    public Object clone()
    {
        return new AIntType(
            (TInt) cloneNode(_int_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAIntType(this);
    }

    public TInt getInt()
    {
        return _int_;
    }

    public void setInt(TInt node)
    {
        if(_int_ != null)
        {
            _int_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _int_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_int_);
    }

    void removeChild(Node child)
    {
        if(_int_ == child)
        {
            _int_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_int_ == oldChild)
        {
            setInt((TInt) newChild);
            return;
        }

    }
}
