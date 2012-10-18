/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import joosc.analysis.*;

public final class X2TIdentifier extends XTIdentifier
{
    private TIdentifier _tIdentifier_;

    public X2TIdentifier()
    {
    }

    public X2TIdentifier(
        TIdentifier _tIdentifier_)
    {
        setTIdentifier(_tIdentifier_);
    }

    public Object clone()
    {
        throw new RuntimeException("Unsupported Operation");
    }

    public void apply(Switch sw)
    {
        throw new RuntimeException("Switch not supported.");
    }

    public TIdentifier getTIdentifier()
    {
        return _tIdentifier_;
    }

    public void setTIdentifier(TIdentifier node)
    {
        if(_tIdentifier_ != null)
        {
            _tIdentifier_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _tIdentifier_ = node;
    }

    void removeChild(Node child)
    {
        if(_tIdentifier_ == child)
        {
            _tIdentifier_ = null;
        }
    }

    void replaceChild(Node oldChild, Node newChild)
    {
    }

    public String toString()
    {
        return "" +
            toString(_tIdentifier_);
    }
}