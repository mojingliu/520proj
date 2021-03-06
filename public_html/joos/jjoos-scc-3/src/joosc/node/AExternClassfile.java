/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AExternClassfile extends PClassfile
{
    private final LinkedList _classes_ = new TypedLinkedList(new Classes_Cast());

    public AExternClassfile()
    {
    }

    public AExternClassfile(
        List _classes_)
    {
        {
            this._classes_.clear();
            this._classes_.addAll(_classes_);
        }

    }
    public Object clone()
    {
        return new AExternClassfile(
            cloneList(_classes_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAExternClassfile(this);
    }

    public LinkedList getClasses()
    {
        return _classes_;
    }

    public void setClasses(List list)
    {
        _classes_.clear();
        _classes_.addAll(list);
    }

    public String toString()
    {
        return ""
            + toString(_classes_);
    }

    void removeChild(Node child)
    {
        if(_classes_.remove(child))
        {
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        for(ListIterator i = _classes_.listIterator(); i.hasNext();)
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

    private class Classes_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PExternClass node = (PExternClass) o;

            if((node.parent() != null) &&
                (node.parent() != AExternClassfile.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AExternClassfile.this))
            {
                node.parent(AExternClassfile.this);
            }

            return node;
        }
    }
}
