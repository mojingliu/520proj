/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AMethodinvocation extends PMethodinvocation
{
    private PReceiver _receiver_;
    private TDot _dot_;
    private TIdentifier _identifier_;
    private TLPar _lPar_;
    private PArgumentList _argumentList_;
    private TRPar _rPar_;

    public AMethodinvocation()
    {
    }

    public AMethodinvocation(
        PReceiver _receiver_,
        TDot _dot_,
        TIdentifier _identifier_,
        TLPar _lPar_,
        PArgumentList _argumentList_,
        TRPar _rPar_)
    {
        setReceiver(_receiver_);

        setDot(_dot_);

        setIdentifier(_identifier_);

        setLPar(_lPar_);

        setArgumentList(_argumentList_);

        setRPar(_rPar_);

    }
    public Object clone()
    {
        return new AMethodinvocation(
            (PReceiver) cloneNode(_receiver_),
            (TDot) cloneNode(_dot_),
            (TIdentifier) cloneNode(_identifier_),
            (TLPar) cloneNode(_lPar_),
            (PArgumentList) cloneNode(_argumentList_),
            (TRPar) cloneNode(_rPar_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAMethodinvocation(this);
    }

    public PReceiver getReceiver()
    {
        return _receiver_;
    }

    public void setReceiver(PReceiver node)
    {
        if(_receiver_ != null)
        {
            _receiver_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _receiver_ = node;
    }

    public TDot getDot()
    {
        return _dot_;
    }

    public void setDot(TDot node)
    {
        if(_dot_ != null)
        {
            _dot_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _dot_ = node;
    }

    public TIdentifier getIdentifier()
    {
        return _identifier_;
    }

    public void setIdentifier(TIdentifier node)
    {
        if(_identifier_ != null)
        {
            _identifier_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _identifier_ = node;
    }

    public TLPar getLPar()
    {
        return _lPar_;
    }

    public void setLPar(TLPar node)
    {
        if(_lPar_ != null)
        {
            _lPar_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _lPar_ = node;
    }

    public PArgumentList getArgumentList()
    {
        return _argumentList_;
    }

    public void setArgumentList(PArgumentList node)
    {
        if(_argumentList_ != null)
        {
            _argumentList_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _argumentList_ = node;
    }

    public TRPar getRPar()
    {
        return _rPar_;
    }

    public void setRPar(TRPar node)
    {
        if(_rPar_ != null)
        {
            _rPar_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _rPar_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_receiver_)
            + toString(_dot_)
            + toString(_identifier_)
            + toString(_lPar_)
            + toString(_argumentList_)
            + toString(_rPar_);
    }

    void removeChild(Node child)
    {
        if(_receiver_ == child)
        {
            _receiver_ = null;
            return;
        }

        if(_dot_ == child)
        {
            _dot_ = null;
            return;
        }

        if(_identifier_ == child)
        {
            _identifier_ = null;
            return;
        }

        if(_lPar_ == child)
        {
            _lPar_ = null;
            return;
        }

        if(_argumentList_ == child)
        {
            _argumentList_ = null;
            return;
        }

        if(_rPar_ == child)
        {
            _rPar_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_receiver_ == oldChild)
        {
            setReceiver((PReceiver) newChild);
            return;
        }

        if(_dot_ == oldChild)
        {
            setDot((TDot) newChild);
            return;
        }

        if(_identifier_ == oldChild)
        {
            setIdentifier((TIdentifier) newChild);
            return;
        }

        if(_lPar_ == oldChild)
        {
            setLPar((TLPar) newChild);
            return;
        }

        if(_argumentList_ == oldChild)
        {
            setArgumentList((PArgumentList) newChild);
            return;
        }

        if(_rPar_ == oldChild)
        {
            setRPar((TRPar) newChild);
            return;
        }

    }
}
