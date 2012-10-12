/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AAssignExp extends PExp
{
    private PAssignment _assignment_;

    public AAssignExp()
    {
    }

    public AAssignExp(
        PAssignment _assignment_)
    {
        setAssignment(_assignment_);

    }
    public Object clone()
    {
        return new AAssignExp(
            (PAssignment) cloneNode(_assignment_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAAssignExp(this);
    }

    public PAssignment getAssignment()
    {
        return _assignment_;
    }

    public void setAssignment(PAssignment node)
    {
        if(_assignment_ != null)
        {
            _assignment_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _assignment_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_assignment_);
    }

    void removeChild(Node child)
    {
        if(_assignment_ == child)
        {
            _assignment_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_assignment_ == oldChild)
        {
            setAssignment((PAssignment) newChild);
            return;
        }

    }
}
