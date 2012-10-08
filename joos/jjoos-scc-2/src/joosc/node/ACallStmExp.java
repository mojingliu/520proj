/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ACallStmExp extends PStmExp
{
    private PMethodinvocation _methodinvocation_;

    public ACallStmExp()
    {
    }

    public ACallStmExp(
        PMethodinvocation _methodinvocation_)
    {
        setMethodinvocation(_methodinvocation_);

    }
    public Object clone()
    {
        return new ACallStmExp(
            (PMethodinvocation) cloneNode(_methodinvocation_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseACallStmExp(this);
    }

    public PMethodinvocation getMethodinvocation()
    {
        return _methodinvocation_;
    }

    public void setMethodinvocation(PMethodinvocation node)
    {
        if(_methodinvocation_ != null)
        {
            _methodinvocation_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _methodinvocation_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_methodinvocation_);
    }

    void removeChild(Node child)
    {
        if(_methodinvocation_ == child)
        {
            _methodinvocation_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_methodinvocation_ == oldChild)
        {
            setMethodinvocation((PMethodinvocation) newChild);
            return;
        }

    }
}
