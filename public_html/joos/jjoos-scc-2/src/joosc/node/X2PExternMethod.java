/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X2PExternMethod extends XPExternMethod
{
    private PExternMethod _pExternMethod_;

    public X2PExternMethod()
    {
    }

    public X2PExternMethod(
        PExternMethod _pExternMethod_)
    {
        setPExternMethod(_pExternMethod_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public PExternMethod getPExternMethod()
    {
        return _pExternMethod_;
    }

    public void setPExternMethod(PExternMethod node)
    {
        if(_pExternMethod_ != null)
        {
            _pExternMethod_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _pExternMethod_ = node;
    }

    void removeChild(Node child)
    {
        if(_pExternMethod_ == child)
        {
            _pExternMethod_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_pExternMethod_);
    }
}