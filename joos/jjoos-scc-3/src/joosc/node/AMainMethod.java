/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AMainMethod extends PMethod
{
    private PMainargv _mainargv_;
    private final LinkedList _stmts_ = new TypedLinkedList(new Stmts_Cast());

    public AMainMethod()
    {
    }

    public AMainMethod(
        PMainargv _mainargv_,
        List _stmts_)
    {
        setMainargv(_mainargv_);

        {
            this._stmts_.clear();
            this._stmts_.addAll(_stmts_);
        }

    }
    public Object clone()
    {
        return new AMainMethod(
            (PMainargv) cloneNode(_mainargv_),
            cloneList(_stmts_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAMainMethod(this);
    }

    public PMainargv getMainargv()
    {
        return _mainargv_;
    }

    public void setMainargv(PMainargv node)
    {
        if(_mainargv_ != null)
        {
            _mainargv_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _mainargv_ = node;
    }

    public LinkedList getStmts()
    {
        return _stmts_;
    }

    public void setStmts(List list)
    {
        _stmts_.clear();
        _stmts_.addAll(list);
    }

    public String toString()
    {
        return ""
            + toString(_mainargv_)
            + toString(_stmts_);
    }

    void removeChild(Node child)
    {
        if(_mainargv_ == child)
        {
            _mainargv_ = null;
            return;
        }

        if(_stmts_.remove(child))
        {
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_mainargv_ == oldChild)
        {
            setMainargv((PMainargv) newChild);
            return;
        }

        for(ListIterator i = _stmts_.listIterator(); i.hasNext();)
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

    }

    private class Stmts_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PStm node = (PStm) o;

            if((node.parent() != null) &&
                (node.parent() != AMainMethod.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AMainMethod.this))
            {
                node.parent(AMainMethod.this);
            }

            return node;
        }
    }
}
