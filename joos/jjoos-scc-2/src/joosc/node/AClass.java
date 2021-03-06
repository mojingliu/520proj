/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AClass extends PClass
{
    private TPublic _public_;
    private PClassmods _classmods_;
    private TClass _tClass_;
    private TIdentifier _identifier_;
    private PExtension _extension_;
    private TLBrace _lBrace_;
    private final LinkedList _field_ = new TypedLinkedList(new Field_Cast());
    private final LinkedList _constructor_ = new TypedLinkedList(new Constructor_Cast());
    private final LinkedList _method_ = new TypedLinkedList(new Method_Cast());
    private TRBrace _rBrace_;

    public AClass()
    {
    }

    public AClass(
        TPublic _public_,
        PClassmods _classmods_,
        TClass _tClass_,
        TIdentifier _identifier_,
        PExtension _extension_,
        TLBrace _lBrace_,
        List _field_,
        List _constructor_,
        List _method_,
        TRBrace _rBrace_)
    {
        setPublic(_public_);

        setClassmods(_classmods_);

        setTClass(_tClass_);

        setIdentifier(_identifier_);

        setExtension(_extension_);

        setLBrace(_lBrace_);

        {
            this._field_.clear();
            this._field_.addAll(_field_);
        }

        {
            this._constructor_.clear();
            this._constructor_.addAll(_constructor_);
        }

        {
            this._method_.clear();
            this._method_.addAll(_method_);
        }

        setRBrace(_rBrace_);

    }

    public AClass(
        TPublic _public_,
        PClassmods _classmods_,
        TClass _tClass_,
        TIdentifier _identifier_,
        PExtension _extension_,
        TLBrace _lBrace_,
        XPField _field_,
        XPConstructor _constructor_,
        XPMethod _method_,
        TRBrace _rBrace_)
    {
        setPublic(_public_);

        setClassmods(_classmods_);

        setTClass(_tClass_);

        setIdentifier(_identifier_);

        setExtension(_extension_);

        setLBrace(_lBrace_);

        if(_field_ != null)
        {
            while(_field_ instanceof X1PField)
            {
                this._field_.addFirst(((X1PField) _field_).getPField());
                _field_ = ((X1PField) _field_).getXPField();
            }
            this._field_.addFirst(((X2PField) _field_).getPField());
        }

        if(_constructor_ != null)
        {
            while(_constructor_ instanceof X1PConstructor)
            {
                this._constructor_.addFirst(((X1PConstructor) _constructor_).getPConstructor());
                _constructor_ = ((X1PConstructor) _constructor_).getXPConstructor();
            }
            this._constructor_.addFirst(((X2PConstructor) _constructor_).getPConstructor());
        }

        if(_method_ != null)
        {
            while(_method_ instanceof X1PMethod)
            {
                this._method_.addFirst(((X1PMethod) _method_).getPMethod());
                _method_ = ((X1PMethod) _method_).getXPMethod();
            }
            this._method_.addFirst(((X2PMethod) _method_).getPMethod());
        }

        setRBrace(_rBrace_);

    }
    public Object clone()
    {
        return new AClass(
            (TPublic) cloneNode(_public_),
            (PClassmods) cloneNode(_classmods_),
            (TClass) cloneNode(_tClass_),
            (TIdentifier) cloneNode(_identifier_),
            (PExtension) cloneNode(_extension_),
            (TLBrace) cloneNode(_lBrace_),
            cloneList(_field_),
            cloneList(_constructor_),
            cloneList(_method_),
            (TRBrace) cloneNode(_rBrace_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAClass(this);
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

    public PClassmods getClassmods()
    {
        return _classmods_;
    }

    public void setClassmods(PClassmods node)
    {
        if(_classmods_ != null)
        {
            _classmods_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _classmods_ = node;
    }

    public TClass getTClass()
    {
        return _tClass_;
    }

    public void setTClass(TClass node)
    {
        if(_tClass_ != null)
        {
            _tClass_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _tClass_ = node;
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

    public PExtension getExtension()
    {
        return _extension_;
    }

    public void setExtension(PExtension node)
    {
        if(_extension_ != null)
        {
            _extension_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _extension_ = node;
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

    public LinkedList getField()
    {
        return _field_;
    }

    public void setField(List list)
    {
        _field_.clear();
        _field_.addAll(list);
    }

    public LinkedList getConstructor()
    {
        return _constructor_;
    }

    public void setConstructor(List list)
    {
        _constructor_.clear();
        _constructor_.addAll(list);
    }

    public LinkedList getMethod()
    {
        return _method_;
    }

    public void setMethod(List list)
    {
        _method_.clear();
        _method_.addAll(list);
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
            + toString(_classmods_)
            + toString(_tClass_)
            + toString(_identifier_)
            + toString(_extension_)
            + toString(_lBrace_)
            + toString(_field_)
            + toString(_constructor_)
            + toString(_method_)
            + toString(_rBrace_);
    }

    void removeChild(Node child)
    {
        if(_public_ == child)
        {
            _public_ = null;
            return;
        }

        if(_classmods_ == child)
        {
            _classmods_ = null;
            return;
        }

        if(_tClass_ == child)
        {
            _tClass_ = null;
            return;
        }

        if(_identifier_ == child)
        {
            _identifier_ = null;
            return;
        }

        if(_extension_ == child)
        {
            _extension_ = null;
            return;
        }

        if(_lBrace_ == child)
        {
            _lBrace_ = null;
            return;
        }

        if(_field_.remove(child))
        {
            return;
        }

        if(_constructor_.remove(child))
        {
            return;
        }

        if(_method_.remove(child))
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

        if(_classmods_ == oldChild)
        {
            setClassmods((PClassmods) newChild);
            return;
        }

        if(_tClass_ == oldChild)
        {
            setTClass((TClass) newChild);
            return;
        }

        if(_identifier_ == oldChild)
        {
            setIdentifier((TIdentifier) newChild);
            return;
        }

        if(_extension_ == oldChild)
        {
            setExtension((PExtension) newChild);
            return;
        }

        if(_lBrace_ == oldChild)
        {
            setLBrace((TLBrace) newChild);
            return;
        }

        for(ListIterator i = _field_.listIterator(); i.hasNext();)
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

        for(ListIterator i = _constructor_.listIterator(); i.hasNext();)
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

        for(ListIterator i = _method_.listIterator(); i.hasNext();)
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

    private class Field_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PField node = (PField) o;

            if((node.parent() != null) &&
                (node.parent() != AClass.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AClass.this))
            {
                node.parent(AClass.this);
            }

            return node;
        }
    }

    private class Constructor_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PConstructor node = (PConstructor) o;

            if((node.parent() != null) &&
                (node.parent() != AClass.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AClass.this))
            {
                node.parent(AClass.this);
            }

            return node;
        }
    }

    private class Method_Cast implements Cast
    {
        public Object cast(Object o)
        {
            PMethod node = (PMethod) o;

            if((node.parent() != null) &&
                (node.parent() != AClass.this))
            {
                node.parent().removeChild(node);
            }

            if((node.parent() == null) ||
                (node.parent() != AClass.this))
            {
                node.parent(AClass.this);
            }

            return node;
        }
    }
}
