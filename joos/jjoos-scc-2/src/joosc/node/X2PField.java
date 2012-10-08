/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X2PField extends XPField
{
    private PField _pField_;

    public X2PField()
    {
    }

    public X2PField(
        PField _pField_)
    {
        setPField(_pField_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public PField getPField()
    {
        return _pField_;
    }

    public void setPField(PField node)
    {
        if(_pField_ != null)
        {
            _pField_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _pField_ = node;
    }

    void removeChild(Node child)
    {
        if(_pField_ == child)
        {
            _pField_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_pField_);
    }
}
