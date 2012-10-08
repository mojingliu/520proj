/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AExternConstructor extends PExternConstructor
{
    private TIdentifier _identifier_;
    private final LinkedList _formals_ = new TypedLinkedList(new Formals_Cast());

    public AExternConstructor()
    {
    }

    public AExternConstructor(
        TIdentifier _identifier_,
        List _formals_)
    {
        setIdentifier(_identifier_);

        {
            this._formals_.clear();
            this._formals_.addAll(_formals_);
        }

    }
    public Object clone()
    {
        return new AExternConstructor(
            (TIdentifier) cloneNode(_identifier_),
            cloneList(_formals_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAExternConstructor(this);
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

    public LinkedList getFormals()
    {
        return _formals_;
    }

    public void setFormals(List list)
    {
        _formals_.clear();
        _formals_.addAll(list);
    }

    public String toString()
    {
        return ""
            + toString(_identifier_)
            + toString(_formals_);
    }

    void removeChild(Node child)
    {
        if(_identifier_ == child)
        {
            _identifier_ = null;
            return;
        }

        if(_formals_.remove(child))
        {
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_identifier_ == oldChild)
        {
            setIdentifier((TIdentifier) newChild);
            return;
        }

        for(ListIterator i = _formals_.listIterator(); i.hasNext();)
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

    private class Formals_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PFormal node = (PFormal) o;

            if((node.parent() != null) &&
                (node.parent() != AExternConstructor.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AExternConstructor.this))
            {
                node.parent(AExternConstructor.this);
            }

            return node;
        }
    }
}
