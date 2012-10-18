/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ASimpleStmNoShortIf extends PStmNoShortIf
{
    private PSimplestm _simplestm_;

    public ASimpleStmNoShortIf()
    {
    }

    public ASimpleStmNoShortIf(
        PSimplestm _simplestm_)
    {
        setSimplestm(_simplestm_);

    }
    public Object clone()
    {
        return new ASimpleStmNoShortIf(
            (PSimplestm) cloneNode(_simplestm_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseASimpleStmNoShortIf(this);
    }

    public PSimplestm getSimplestm()
    {
        return _simplestm_;
    }

    public void setSimplestm(PSimplestm node)
    {
        if(_simplestm_ != null)
        {
            _simplestm_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _simplestm_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_simplestm_);
    }

    void removeChild(Node child)
    {
        if(_simplestm_ == child)
        {
            _simplestm_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_simplestm_ == oldChild)
        {
            setSimplestm((PSimplestm) newChild);
            return;
        }

    }
}