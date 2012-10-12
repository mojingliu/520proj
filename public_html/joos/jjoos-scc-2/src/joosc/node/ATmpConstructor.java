/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ATmpConstructor extends PConstructor
{
    private TPublic _public_;
    private TIdentifier _identifier_;
    private TLPar _lPar_;
    private PFormalList _formalList_;
    private TRPar _rPar_;
    private TLBrace _lBrace_;
    private TSuper _super_;
    private TLPar _superLPar_;
    private PArgumentList _argumentList_;
    private TRPar _superRPar_;
    private TSemicolon _semicolon_;
    private final LinkedList _stm_ = new TypedLinkedList(new Stm_Cast());
    private TRBrace _rBrace_;

    public ATmpConstructor()
    {
    }

    public ATmpConstructor(
        TPublic _public_,
        TIdentifier _identifier_,
        TLPar _lPar_,
        PFormalList _formalList_,
        TRPar _rPar_,
        TLBrace _lBrace_,
        TSuper _super_,
        TLPar _superLPar_,
        PArgumentList _argumentList_,
        TRPar _superRPar_,
        TSemicolon _semicolon_,
        List _stm_,
        TRBrace _rBrace_)
    {
        setPublic(_public_);

        setIdentifier(_identifier_);

        setLPar(_lPar_);

        setFormalList(_formalList_);

        setRPar(_rPar_);

        setLBrace(_lBrace_);

        setSuper(_super_);

        setSuperLPar(_superLPar_);

        setArgumentList(_argumentList_);

        setSuperRPar(_superRPar_);

        setSemicolon(_semicolon_);

        {
            this._stm_.clear();
            this._stm_.addAll(_stm_);
        }

        setRBrace(_rBrace_);

    }

    public ATmpConstructor(
        TPublic _public_,
        TIdentifier _identifier_,
        TLPar _lPar_,
        PFormalList _formalList_,
        TRPar _rPar_,
        TLBrace _lBrace_,
        TSuper _super_,
        TLPar _superLPar_,
        PArgumentList _argumentList_,
        TRPar _superRPar_,
        TSemicolon _semicolon_,
        XPStm _stm_,
        TRBrace _rBrace_)
    {
        setPublic(_public_);

        setIdentifier(_identifier_);

        setLPar(_lPar_);

        setFormalList(_formalList_);

        setRPar(_rPar_);

        setLBrace(_lBrace_);

        setSuper(_super_);

        setSuperLPar(_superLPar_);

        setArgumentList(_argumentList_);

        setSuperRPar(_superRPar_);

        setSemicolon(_semicolon_);

        if(_stm_ != null)
        {
            while(_stm_ instanceof X1PStm)
            {
                this._stm_.addFirst(((X1PStm) _stm_).getPStm());
                _stm_ = ((X1PStm) _stm_).getXPStm();
            }
            this._stm_.addFirst(((X2PStm) _stm_).getPStm());
        }

        setRBrace(_rBrace_);

    }
    public Object clone()
    {
        return new ATmpConstructor(
            (TPublic) cloneNode(_public_),
            (TIdentifier) cloneNode(_identifier_),
            (TLPar) cloneNode(_lPar_),
            (PFormalList) cloneNode(_formalList_),
            (TRPar) cloneNode(_rPar_),
            (TLBrace) cloneNode(_lBrace_),
            (TSuper) cloneNode(_super_),
            (TLPar) cloneNode(_superLPar_),
            (PArgumentList) cloneNode(_argumentList_),
            (TRPar) cloneNode(_superRPar_),
            (TSemicolon) cloneNode(_semicolon_),
            cloneList(_stm_),
            (TRBrace) cloneNode(_rBrace_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseATmpConstructor(this);
    }

    public TPublic getPublic()
    {
        return _public_;
    }

    public void setPublic(TPublic node)
    {
        if(_public_ != null)
        {
            _public_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _public_ = node;
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

    public PFormalList getFormalList()
    {
        return _formalList_;
    }

    public void setFormalList(PFormalList node)
    {
        if(_formalList_ != null)
        {
            _formalList_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _formalList_ = node;
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

    public TLBrace getLBrace()
    {
        return _lBrace_;
    }

    public void setLBrace(TLBrace node)
    {
        if(_lBrace_ != null)
        {
            _lBrace_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _lBrace_ = node;
    }

    public TSuper getSuper()
    {
        return _super_;
    }

    public void setSuper(TSuper node)
    {
        if(_super_ != null)
        {
            _super_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _super_ = node;
    }

    public TLPar getSuperLPar()
    {
        return _superLPar_;
    }

    public void setSuperLPar(TLPar node)
    {
        if(_superLPar_ != null)
        {
            _superLPar_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _superLPar_ = node;
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

    public TRPar getSuperRPar()
    {
        return _superRPar_;
    }

    public void setSuperRPar(TRPar node)
    {
        if(_superRPar_ != null)
        {
            _superRPar_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _superRPar_ = node;
    }

    public TSemicolon getSemicolon()
    {
        return _semicolon_;
    }

    public void setSemicolon(TSemicolon node)
    {
        if(_semicolon_ != null)
        {
            _semicolon_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _semicolon_ = node;
    }

    public LinkedList getStm()
    {
        return _stm_;
    }

    public void setStm(List list)
    {
        _stm_.clear();
        _stm_.addAll(list);
    }

    public TRBrace getRBrace()
    {
        return _rBrace_;
    }

    public void setRBrace(TRBrace node)
    {
        if(_rBrace_ != null)
        {
            _rBrace_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _rBrace_ = node;
    }

    public String toString()
    {
        return ""
            + toString(_public_)
            + toString(_identifier_)
            + toString(_lPar_)
            + toString(_formalList_)
            + toString(_rPar_)
            + toString(_lBrace_)
            + toString(_super_)
            + toString(_superLPar_)
            + toString(_argumentList_)
            + toString(_superRPar_)
            + toString(_semicolon_)
            + toString(_stm_)
            + toString(_rBrace_);
    }

    void removeChild(Node child)
    {
        if(_public_ == child)
        {
            _public_ = null;
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

        if(_formalList_ == child)
        {
            _formalList_ = null;
            return;
        }

        if(_rPar_ == child)
        {
            _rPar_ = null;
            return;
        }

        if(_lBrace_ == child)
        {
            _lBrace_ = null;
            return;
        }

        if(_super_ == child)
        {
            _super_ = null;
            return;
        }

        if(_superLPar_ == child)
        {
            _superLPar_ = null;
            return;
        }

        if(_argumentList_ == child)
        {
            _argumentList_ = null;
            return;
        }

        if(_superRPar_ == child)
        {
            _superRPar_ = null;
            return;
        }

        if(_semicolon_ == child)
        {
            _semicolon_ = null;
            return;
        }

        if(_stm_.remove(child))
        {
            return;
        }

        if(_rBrace_ == child)
        {
            _rBrace_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_public_ == oldChild)
        {
            setPublic((TPublic) newChild);
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

        if(_formalList_ == oldChild)
        {
            setFormalList((PFormalList) newChild);
            return;
        }

        if(_rPar_ == oldChild)
        {
            setRPar((TRPar) newChild);
            return;
        }

        if(_lBrace_ == oldChild)
        {
            setLBrace((TLBrace) newChild);
            return;
        }

        if(_super_ == oldChild)
        {
            setSuper((TSuper) newChild);
            return;
        }

        if(_superLPar_ == oldChild)
        {
            setSuperLPar((TLPar) newChild);
            return;
        }

        if(_argumentList_ == oldChild)
        {
            setArgumentList((PArgumentList) newChild);
            return;
        }

        if(_superRPar_ == oldChild)
        {
            setSuperRPar((TRPar) newChild);
            return;
        }

        if(_semicolon_ == oldChild)
        {
            setSemicolon((TSemicolon) newChild);
            return;
        }

        for(ListIterator i = _stm_.listIterator(); i.hasNext();)
        {
            if(i.next() == oldChild)
            {
                if(newChild != null)
                {
                    i.set(newChild);
                    oldChild.parent(null);
                    return;
                }

                i.remove();
                oldChild.parent(null);
                return;
            }
        }

        if(_rBrace_ == oldChild)
        {
            setRBrace((TRBrace) newChild);
            return;
        }

    }

    private class Stm_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PStm node = (PStm) o;

            if((node.parent() != null) &&
                (node.parent() != ATmpConstructor.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != ATmpConstructor.this))
            {
                node.parent(ATmpConstructor.this);
            }

            return node;
        }
    }
}
