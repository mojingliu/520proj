/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AWhileStm extends PStm
{
    private PExp _exp_;
    private PStm _stm_;

    public AWhileStm()
    {
    }

    public AWhileStm(
        PExp _exp_,
        PStm _stm_)
    {
        setExp(_exp_);

        setStm(_stm_);

    }
    public Object clone()
    {
        return new AWhileStm(
            (PExp) cloneNode(_exp_),
            (PStm) cloneNode(_stm_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAWhileStm(this);
    }

    public PExp getExp()
    {
        return _exp_;
    }

    public void setExp(PExp node)
    {
        if(_exp_ != null)
        {
            _exp_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _exp_ = node;
    }

    public PStm getStm()
    {
        return _stm_;
    }

    public void setStm(PStm node)
    {
        if(_stm_ != null)
        {
            _stm_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _stm_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_exp_)
            + toString(_stm_);
    }

    void removeChild(Node child)
    {
        if(_exp_ == child)
        {
            _exp_ = null;
            return;
        }

        if(_stm_ == child)
        {
            _stm_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_exp_ == oldChild)
        {
            setExp((PExp) newChild);
            return;
        }

        if(_stm_ == oldChild)
        {
            setStm((PStm) newChild);
            return;
        }

    }
}
