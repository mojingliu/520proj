/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X1PStm extends XPStm
{
    private XPStm _xPStm_;
    private PStm _pStm_;

    public X1PStm()
    {
    }

    public X1PStm(
        XPStm _xPStm_,
        PStm _pStm_)
    {
        setXPStm(_xPStm_);
        setPStm(_pStm_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public XPStm getXPStm()
    {
        return _xPStm_;
    }

    public void setXPStm(XPStm node)
    {
        if(_xPStm_ != null)
        {
            _xPStm_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _xPStm_ = node;
    }

    public PStm getPStm()
    {
        return _pStm_;
    }

    public void setPStm(PStm node)
    {
        if(_pStm_ != null)
        {
            _pStm_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _pStm_ = node;
    }

    void removeChild(Node child)
    {
        if(_xPStm_ == child)
        {
            _xPStm_ = null;
        }

        if(_pStm_ == child)
        {
            _pStm_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_xPStm_) +
            toString(_pStm_);
    }
}
