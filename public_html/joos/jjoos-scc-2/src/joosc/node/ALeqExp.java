/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ALeqExp extends PExp
{
    private PExp _left_;
    private TLeq _leq_;
    private PExp _right_;

    public ALeqExp()
    {
    }

    public ALeqExp(
        PExp _left_,
        TLeq _leq_,
        PExp _right_)
    {
        setLeft(_left_);

        setLeq(_leq_);

        setRight(_right_);

    }
    public Object clone()
    {
        return new ALeqExp(
            (PExp) cloneNode(_left_),
            (TLeq) cloneNode(_leq_),
            (PExp) cloneNode(_right_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseALeqExp(this);
    }

    public PExp getLeft()
    {
        return _left_;
    }

    public void setLeft(PExp node)
    {
        if(_left_ != null)
        {
            _left_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _left_ = node;
    }

    public TLeq getLeq()
    {
        return _leq_;
    }

    public void setLeq(TLeq node)
    {
        if(_leq_ != null)
        {
            _leq_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _leq_ = node;
    }

    public PExp getRight()
    {
        return _right_;
    }

    public void setRight(PExp node)
    {
        if(_right_ != null)
        {
            _right_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _right_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_left_)
            + toString(_leq_)
            + toString(_right_);
    }

    void removeChild(Node child)
    {
        if(_left_ == child)
        {
            _left_ = null;
            return;
        }

        if(_leq_ == child)
        {
            _leq_ = null;
            return;
        }

        if(_right_ == child)
        {
            _right_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_left_ == oldChild)
        {
            setLeft((PExp) newChild);
            return;
        }

        if(_leq_ == oldChild)
        {
            setLeq((TLeq) newChild);
            return;
        }

        if(_right_ == oldChild)
        {
            setRight((PExp) newChild);
            return;
        }

    }
}
