#include <stdio.h>
#include "weeder.h"

extern int weedError;

void weedSERVICE(SERVICE* s)
{
    if(s == NULL) return;
    weedError = 0;
    if(s->html != NULL)
    {
        weedHTML(s->html);
    }
    if(s->schema != NULL)
    {
        weedSCHEMA(s->schema);
    }
    if(s->variable != NULL)
    {
        weedVARIABLE(s->variable);
    }
    if(s->function != NULL)
    {
        weedFUNCTION(s->function);
    }
    if(s->session != NULL)
    {
        weedSESSION(s->session);
    }
}

void weedHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        weedHTML(h->next);
    }
    weedID(h->identifier);
    weedHTMLBODY(h->body);
}

void weedHTMLBODY(HTMLBODY* h)
{
    if(h == NULL) return;
    weedHTMLBODY(h->next);
    switch (h->kind) {
        case tagK:
            weedID(h->val.tagE.id);
            if(h->val.tagE.attribute != NULL)
            {
                weedATTRIBUTE(h->val.tagE.attribute);
            }
            break;
        case gapK:
            weedID(h->val.id);
            break;
        case whateverK:
            break;
        case metaK:
            break;
        case inputK:
            weedINPUTATTR(h->val.inputattr);
            break;
        case selectK:
            weedINPUTATTR(h->val.selectE.inputattr);
            weedHTMLBODY(h->val.selectE.body);
            break;
    }
}

void weedINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        weedINPUTATTR(i->next);
    }
    switch(i->kind) {
        case nameK:
            weedATTR(i->val.attr);
            break;
        case textK:
            break;
        case radioK:
            break;
        case otherK:
            weedATTRIBUTE(i->val.attribute);
            break;
    }
}

void weedATTRIBUTE(ATTRIBUTE* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        weedATTRIBUTE(a->next);
    }
    weedATTR(a->left);
    if(a->right != NULL)
    {
        weedATTR(a->right);
    }
}

void weedATTR(ATTR* a)
{
    if(a == NULL) return;
    switch(a->kind) {
        case attridK:
            weedID(a->val.id);
            break;
        case attrstringconstK:
            break;
        case attrintconstK:
            break;
    }
}


void weedSCHEMA(SCHEMA* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        weedSCHEMA(s->next);
    }
    weedID(s->id);
    weedFIELD(s->field);
}

void weedFIELD(FIELD* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        weedFIELD(f->next);
    }
    weedSIMPLETYPE(f->simpletype);
    weedID(f->id);
}

void weedVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    if(v->next != NULL)
    {
        weedVARIABLE(v->next);
    }
    weedTYPE(v->type);
    weedID(v->id);
}

void weedID(ID* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        weedID(i->next);
    }
}

void weedTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            weedSIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            weedID(t->val.id);
            break;
    }
}

void weedSIMPLETYPE(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind) {
        case intK:
            break;
        case boolK:
            break;
        case stringK:
            break;
        case voidK:
            break;
    }
}

void weedFUNCTION(FUNCTION* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        weedFUNCTION(f->next);
    }
    weedTYPE(f->type);
    weedID(f->id);
    weedARGUMENT(f->argument);
    weedCOMPOUNDSTM(f->compoundstm);
}

void weedARGUMENT(ARGUMENT* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        weedARGUMENT(a->next);
    }
    weedTYPE(a->type);
    weedID(a->id);
}

void weedSESSION(SESSION* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        weedSESSION(s->next);
    }
    weedID(s->id);
    weedCOMPOUNDSTM(s->compoundstm);
}

void weedSTM(STM* s)
{
    if(s->next != NULL)
    {
        weedSTM(s->next);
    }
    if(s == NULL) return;
    switch(s->kind) {
        case semicolonK:
            break;
        case showK:
            weedDOCUMENT(s->val.showE.doc);
            if(s->val.showE.rec != NULL)
            {
                weedRECEIVE(s->val.showE.rec);
            }
            break;
        case exitK:
            weedDOCUMENT(s->val.doc);
            break;
        case returnK:
            break;
        case returnexprK:
            weedEXP(s->val.expr);
            break;
        case ifK:
            weedEXP(s->val.ifE.expr);
            weedSTM(s->val.ifE.stm);
            break;
        case ifelseK:
            weedEXP(s->val.ifelseE.expr);
            weedSTM(s->val.ifelseE.stm1);

            weedSTM(s->val.ifelseE.stm2);
            break;
        case whileK:
            weedEXP(s->val.whileE.expr);
            weedSTM(s->val.whileE.stm);
            break;
        case compoundK:
            weedCOMPOUNDSTM(s->val.compoundstm);
            break;
        case exprK:
            weedEXP(s->val.expr);
            break;
    }
}

void weedCOMPOUNDSTM(COMPOUNDSTM* c)
{
    if(c == NULL) return;
    weedVARIABLE(c->variable);
    weedSTM(c->stm);
}

void weedDOCUMENT(DOCUMENT* d)
{
    if(d == NULL) return;
    switch(d->kind) {
        case idK:
            weedID(d->val.id);
            break;
        case plugK:
            weedID(d->val.plugE.id);
            weedPLUG(d->val.plugE.plug);
            break;
    }
}

void weedRECEIVE(RECEIVE* r)
{
    if(r == NULL) return;
    if(r->input != NULL)
    {
        weedINPUT(r->input);
    }
}


void weedPLUG(PLUG* p)
{
    if(p == NULL) return;
    if(p->next != NULL)
    {
        weedPLUG(p->next);
    }
    weedID(p->id);
    weedEXP(p->expr);
}

void weedINPUT(INPUT* i)
{
    if(i == NULL) return;
    if(i->next)
    {
        weedINPUT(i->next);
    }
    weedLVALUE(i->lvalue);
    weedID(i->id);
}

void weedLVALUE(LVALUE* l)
{
    if(l == NULL) return;
    weedID(l->id1);
    if(l->id2 != NULL)
    {
        weedID(l->id2);
    }
}

void weedFIELDVALUE(FIELDVALUE* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        weedFIELDVALUE(f->next);
    }
    weedID(f->id);
    weedEXP(f->expr);
}

void weedEXP(EXP* e)
{
    if(e == NULL) return;
    if(e->next != NULL)
    {
        weedEXP(e->next);
    }
    switch(e->kind)
    {
        case lvalueK:
            weedLVALUE(e->val.lvalueE);
            break;
        case assignK:
            weedLVALUE(e->val.assignE.lvalue);
            weedEXP(e->val.assignE.expr);
            break;
        case equalsK:
            weedEXP(e->val.equalsE.left);
            weedEXP(e->val.equalsE.right);
            break;
        case notequalsK:
            weedEXP(e->val.notequalsE.left);
            weedEXP(e->val.notequalsE.right);
            break;
        case ltK:
            weedEXP(e->val.ltE.left);
            weedEXP(e->val.ltE.right);
            break;
        case gtK:
            weedEXP(e->val.gtE.left);
            weedEXP(e->val.gtE.right);
            break;
        case lteK:
            weedEXP(e->val.lteE.left);
            weedEXP(e->val.lteE.right);
            break;
        case gteK:
            weedEXP(e->val.gteE.left);
            weedEXP(e->val.gteE.right);
            break;
        case notK:
            weedEXP(e->val.exprE);
            break;
        case plusK:
            weedEXP(e->val.plusE.left);
            weedEXP(e->val.plusE.right);
            break;
        case minusK:
            weedEXP(e->val.minusE.left);
            weedEXP(e->val.minusE.right);
            break;
        case multK:
            weedEXP(e->val.multE.left);
            weedEXP(e->val.multE.right);
            break;
        case divK:
            if(e->val.divE.right->val.intconstE == 0)
            {
                printf("\nLine %d: Weeder Error - division by zero\n", e->lineno);
                weedError = 1;
                return;
            } 
            weedEXP(e->val.divE.left);
            weedEXP(e->val.divE.right);
            break;
        case modK:
            weedEXP(e->val.modE.left);
            weedEXP(e->val.modE.right);
            break;
        case andK:
            weedEXP(e->val.andE.left);
            weedEXP(e->val.andE.right);
            break;
        case orK:
            weedEXP(e->val.orE.left);
            weedEXP(e->val.orE.right);
            break;
        case joinK:
            weedEXP(e->val.joinE.left);
            weedEXP(e->val.joinE.right);
            break;
        case keepK:
            weedEXP(e->val.keepE.left);
            weedID(e->val.keepE.right);
            break;
        case removeK:
            weedEXP(e->val.removeE.left);
            weedID(e->val.removeE.right);
            break;
        case callK:
            weedID(e->val.removeE.right);
            weedEXP(e->val.removeE.left);
            break;
        case intconstK:
            break;
        case trueK:
            break;
        case falseK:
            break;
        case stringconstK:
            break;
        case tupleK:
            weedFIELDVALUE(e->val.tupleE);
            break;
        case parenK:
            weedEXP(e->val.exprE);
            break;
    }
}

