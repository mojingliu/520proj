/* This file was generated by SableCC (http://www.sablecc.org/). */

package tiny.analysis;

import java.util.*;
import tiny.node.*;

public class AnalysisAdapter implements Analysis
{
    private Hashtable<Node,Object> in;
    private Hashtable<Node,Object> out;

    public Object getIn(Node node)
    {
        if(this.in == null)
        {
            return null;
        }

        return this.in.get(node);
    }

    public void setIn(Node node, Object o)
    {
        if(this.in == null)
        {
            this.in = new Hashtable<Node,Object>(1);
        }

        if(o != null)
        {
            this.in.put(node, o);
        }
        else
        {
            this.in.remove(node);
        }
    }

    public Object getOut(Node node)
    {
        if(this.out == null)
        {
            return null;
        }

        return this.out.get(node);
    }

    public void setOut(Node node, Object o)
    {
        if(this.out == null)
        {
            this.out = new Hashtable<Node,Object>(1);
        }

        if(o != null)
        {
            this.out.put(node, o);
        }
        else
        {
            this.out.remove(node);
        }
    }

    public void caseStart(Start node)
    {
        defaultCase(node);
    }

    public void caseAPlusExp(APlusExp node)
    {
        defaultCase(node);
    }

    public void caseAMinusExp(AMinusExp node)
    {
        defaultCase(node);
    }

    public void caseAMultExp(AMultExp node)
    {
        defaultCase(node);
    }

    public void caseADivdExp(ADivdExp node)
    {
        defaultCase(node);
    }

    public void caseAModExp(AModExp node)
    {
        defaultCase(node);
    }

    public void caseAPowExp(APowExp node)
    {
        defaultCase(node);
    }

    public void caseAAbsExp(AAbsExp node)
    {
        defaultCase(node);
    }

    public void caseAIdExp(AIdExp node)
    {
        defaultCase(node);
    }

    public void caseANumberExp(ANumberExp node)
    {
        defaultCase(node);
    }

    public void caseTEol(TEol node)
    {
        defaultCase(node);
    }

    public void caseTBlank(TBlank node)
    {
        defaultCase(node);
    }

    public void caseTStar(TStar node)
    {
        defaultCase(node);
    }

    public void caseTSlash(TSlash node)
    {
        defaultCase(node);
    }

    public void caseTMod(TMod node)
    {
        defaultCase(node);
    }

    public void caseTAbs(TAbs node)
    {
        defaultCase(node);
    }

    public void caseTPow(TPow node)
    {
        defaultCase(node);
    }

    public void caseTPlus(TPlus node)
    {
        defaultCase(node);
    }

    public void caseTMinus(TMinus node)
    {
        defaultCase(node);
    }

    public void caseTLPar(TLPar node)
    {
        defaultCase(node);
    }

    public void caseTRPar(TRPar node)
    {
        defaultCase(node);
    }

    public void caseTNumber(TNumber node)
    {
        defaultCase(node);
    }

    public void caseTId(TId node)
    {
        defaultCase(node);
    }

    public void caseEOF(EOF node)
    {
        defaultCase(node);
    }

    public void defaultCase(@SuppressWarnings("unused") Node node)
    {
        // do nothing
    }
}
