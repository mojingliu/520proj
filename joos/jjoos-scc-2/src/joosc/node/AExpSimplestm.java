/* This file was generated by SableCC (http://www.sablecc.org/). */

package joosc.node;

import java.util.*;
import joosc.analysis.*;

public final class AExpSimplestm extends PSimplestm
{
    private PStmExp _stmExp_;
    private TSemicolon _semicolon_;

    public AExpSimplestm()
    {
    }

    public AExpSimplestm(
        PStmExp _stmExp_,
        TSemicolon _semicolon_)
    {
        setStmExp(_stmExp_);

        setSemicolon(_semicolon_);

    }
    public Object clone()
    {
        return new AExpSimplestm(
            (PStmExp) cloneNode(_stmExp_),
            (TSemicolon) cloneNode(_semicolon_));
    }

    public void apply(Switch sw)
    {
        ((Analysis) sw).caseAExpSimplestm(this);
    }

    public PStmExp getStmExp()
    {
        return _stmExp_;
    }

    public void setStmExp(PStmExp node)
    {
        if(_stmExp_ != null)
        {
            _stmExp_.parent(null);
        }

        if(node != null)
        {
            if(node.parent() != null)
            {
                node.parent().removeChild(node);
            }

            node.parent(this);
        }

        _stmExp_ = node;
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

    public String toString()
    {
        return ""
            + toString(_stmExp_)
            + toString(_semicolon_);
    }

    void removeChild(Node child)
    {
        if(_stmExp_ == child)
        {
            _stmExp_ = null;
            return;
        }

        if(_semicolon_ == child)
        {
            _semicolon_ = null;
            return;
        }

    }

    void replaceChild(Node oldChild, Node newChild)
    {
        if(_stmExp_ == oldChild)
        {
            setStmExp((PStmExp) newChild);
            return;
        }

        if(_semicolon_ == oldChild)
        {
            setSemicolon((TSemicolon) newChild);
            return;
        }

    }
}