/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X2PArgumentListTail extends XPArgumentListTail
{
    private PArgumentListTail _pArgumentListTail_;

    public X2PArgumentListTail()
    {
    }

    public X2PArgumentListTail(
        PArgumentListTail _pArgumentListTail_)
    {
        setPArgumentListTail(_pArgumentListTail_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public PArgumentListTail getPArgumentListTail()
    {
        return _pArgumentListTail_;
    }

    public void setPArgumentListTail(PArgumentListTail node)
    {
        if(_pArgumentListTail_ != null)
        {
            _pArgumentListTail_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _pArgumentListTail_ = node;
    }

    void removeChild(Node child)
    {
        if(_pArgumentListTail_ == child)
        {
            _pArgumentListTail_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_pArgumentListTail_);
    }
}
