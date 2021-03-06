/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ASecondMainargv extends PMainargv
{
    private TIdentifier _type_;
    private TLBracket _lBracket_;
    private TRBracket _rBracket_;
    private TIdentifier _name_;

    public ASecondMainargv()
    {
    }

    public ASecondMainargv(
        TIdentifier _type_,
        TLBracket _lBracket_,
        TRBracket _rBracket_,
        TIdentifier _name_)
    {
        setType(_type_);

        setLBracket(_lBracket_);

        setRBracket(_rBracket_);

        setName(_name_);

    }
    public Object clone()
    {
        return new ASecondMainargv(
            (TIdentifier) cloneNode(_type_),
            (TLBracket) cloneNode(_lBracket_),
            (TRBracket) cloneNode(_rBracket_),
            (TIdentifier) cloneNode(_name_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseASecondMainargv(this);
    }

    public TIdentifier getType()
    {
        return _type_;
    }

    public void setType(TIdentifier node)
    {
        if(_type_ != null)
        {
            _type_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _type_ = node;
    }

    public TLBracket getLBracket()
    {
        return _lBracket_;
    }

    public void setLBracket(TLBracket node)
    {
        if(_lBracket_ != null)
        {
            _lBracket_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _lBracket_ = node;
    }

    public TRBracket getRBracket()
    {
        return _rBracket_;
    }

    public void setRBracket(TRBracket node)
    {
        if(_rBracket_ != null)
        {
            _rBracket_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _rBracket_ = node;
    }

    public TIdentifier getName()
    {
        return _name_;
    }

    public void setName(TIdentifier node)
    {
        if(_name_ != null)
        {
            _name_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _name_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_type_)
            + toString(_lBracket_)
            + toString(_rBracket_)
            + toString(_name_);
    }

    void removeChild(Node child)
    {
        if(_type_ == child)
        {
            _type_ = null;
            return;
        }

        if(_lBracket_ == child)
        {
            _lBracket_ = null;
            return;
        }

        if(_rBracket_ == child)
        {
            _rBracket_ = null;
            return;
        }

        if(_name_ == child)
        {
            _name_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_type_ == oldChild)
        {
            setType((TIdentifier) newChild);
            return;
        }

        if(_lBracket_ == oldChild)
        {
            setLBracket((TLBracket) newChild);
            return;
        }

        if(_rBracket_ == oldChild)
        {
            setRBracket((TRBracket) newChild);
            return;
        }

        if(_name_ == oldChild)
        {
            setName((TIdentifier) newChild);
            return;
        }

    }
}
