/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X1PExternClass extends XPExternClass
{
    private XPExternClass _xPExternClass_;
    private PExternClass _pExternClass_;

    public X1PExternClass()
    {
    }

    public X1PExternClass(
        XPExternClass _xPExternClass_,
        PExternClass _pExternClass_)
    {
        setXPExternClass(_xPExternClass_);
        setPExternClass(_pExternClass_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public XPExternClass getXPExternClass()
    {
        return _xPExternClass_;
    }

    public void setXPExternClass(XPExternClass node)
    {
        if(_xPExternClass_ != null)
        {
            _xPExternClass_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _xPExternClass_ = node;
    }

    public PExternClass getPExternClass()
    {
        return _pExternClass_;
    }

    public void setPExternClass(PExternClass node)
    {
        if(_pExternClass_ != null)
        {
            _pExternClass_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _pExternClass_ = node;
    }

    void removeChild(Node child)
    {
        if(_xPExternClass_ == child)
        {
            _xPExternClass_ = null;
        }

        if(_pExternClass_ == child)
        {
            _pExternClass_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_xPExternClass_) +
            toString(_pExternClass_);
    }
}
