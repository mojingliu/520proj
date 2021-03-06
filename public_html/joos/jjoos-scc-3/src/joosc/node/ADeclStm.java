/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class ADeclStm extends PStm
{
    private final LinkedList _locals_ = new TypedLinkedList(new Locals_Cast());

    public ADeclStm()
    {
    }

    public ADeclStm(
        List _locals_)
    {
        {
            this._locals_.clear();
            this._locals_.addAll(_locals_);
        }

    }
    public Object clone()
    {
        return new ADeclStm(
            cloneList(_locals_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseADeclStm(this);
    }

    public LinkedList getLocals()
    {
        return _locals_;
    }

    public void setLocals(List list)
    {
        _locals_.clear();
        _locals_.addAll(list);
    }

    public String toString()
    {
        return ""
            + toString(_locals_);
    }

    void removeChild(Node child)
    {
        if(_locals_.remove(child))
        {
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        for(ListIterator i = _locals_.listIterator(); i.hasNext();)
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

    private class Locals_Cast implements Cast
    {
        public Object cast(Object o)
        {
            POnelocal node = (POnelocal) o;

            if((node.parent() != null) &&
                (node.parent() != ADeclStm.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != ADeclStm.this))
            {
                node.parent(ADeclStm.this);
            }

            return node;
        }
    }
}
