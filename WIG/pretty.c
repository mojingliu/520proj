#include <stdio.h>
#include "pretty.h"


void prettySERVICE(SERVICE* s)
{
    if(s == NULL) return;
    printf("service {");
    prettyHTML(s->html);
    prettySCHEMA(s->schema);
    prettyVARIABLE(s->variable);
    prettyFUNCTION(s->function);
    prettySESSION(s->session);
    printf("}");
}

void prettyHTML(HTML* h)
{
    if(h == NULL) return;
    printf("const html ");
    prettyID(h->identifier);
    printf(" = <html>");
    prettyHTMLBODY(h->body);
    prettyHTML(h->next); 
}

void prettyHTMLBODY(HTMLBODY* h)
{
    if(h == NULL) return;
    switch (h->kind) {
        case tagK:
            prettyID(h->val.tagE.id);
            prettyATTRIBUTE(h->val.tagE.attribute);
            break;
        case gapK:
            prettyID(h->val.id);
            break;
        case whateverK:
            printf("%s", h->val.whatever);
            break;
        case metaK:
            printf("%s", h->val.meta);
            break;
        case inputK:
            prettyINPUTATTR(h->val.inputattr);
            break;
        case selectK:
            prettyINPUTATTR(h->val.selectE.inputattr);
            prettyHTMLBODY(h->val.selectE.body);
            break;
    }
    prettyHTMLBODY(h->next);
}

void prettyINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    switch(i->kind) {
        case nameK:
            prettyATTR(i->val.attr);
            break;
        case textK:
            printf("text");
            break;
        case radioK:
            printf("radio");
            break;
        case otherK:
            prettyATTRIBUTE(i->val.attribute);
            break;
    }
    prettyINPUTATTR(i->next);
}

void prettyATTRIBUTE(ATTRIBUTE* a)
{
    if(a == NULL) return;
    prettyATTR(a->left);
    prettyATTR(a->right);
    prettyATTRIBUTE(a->next);
}

void prettyATTR(ATTR* a)
{
    if(a == NULL) return;
    switch(a->kind) {
        case attridK:
            prettyID(a->val.id);
            break;
        case attrstringconstK:
            printf("%s", a->val.stringconst);
            break;
        case attrintconstK:
            printf("%d", a->val.intconst);
            break;
    }
}


void prettySCHEMA(SCHEMA* s)
{
    if(s == NULL) return;
    prettyID(s->id);
    prettyFIELD(s->field);
    prettySCHEMA(s->next);
}

void prettyFIELD(FIELD* f)
{
    if(f == NULL) return;
    prettySIMPLETYPE(f->simpletype);
    prettyID(f->id);
    prettyFIELD(f->next);
}

void prettyVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    prettyTYPE(v->type);
    prettyID(v->id);
    prettyVARIABLE(v->next);
}

void prettyID(ID* i)
{
    if(i == NULL) return;
    printf("%s", i->identifier);
    prettyID(i->next);
}

void prettyTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            prettySIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            prettyID(t->val.id);
            break;
    }

}

void prettySIMPLETYPE(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind) {
        case intK:
            printf("int ");
            break;
        case boolK:
            printf("bool ");
            break;
        case stringK:
            printf("string ");
            break;
        case voidK:
            printf("void ");
            break;
    }
}

void prettyFUNCTION(FUNCTION* f)
{
    if(f == NULL) return;
    prettyTYPE(f->type);
    prettyID(f->id);
    prettyARGUMENT(f->argument);
    prettyCOMPOUNDSTM(f->compoundstm);
    prettyFUNCTION(f->next);
}

void prettyARGUMENT(ARGUMENT* a)
{
    if(a == NULL) return;
    prettyTYPE(a->type);
    prettyID(a->id);
    prettyARGUMENT(a->next);
}

void prettySESSION(SESSION* s)
{
    if(s == NULL) return;
    prettyID(s->id);
    prettyCOMPOUNDSTM(s->compoundstm);
    prettySESSION(s->next);
}

void prettySTM(STM* s)
{
    if(s == NULL) return;
    switch(s->kind) {
        case semicolonK:
            printf(";");
            break;
        case showK:
            printf("show ");
            prettyDOCUMENT(s->val.showE.doc);
            prettyRECEIVE(s->val.showE.rec);
            printf(";");
            break;
        case exitK:
            printf("exit ");
            prettyDOCUMENT(s->val.doc);
            printf(";");
            break;
        case returnK:
            printf("return;");
            break;
        case returnexprK:
            printf("return ");
            prettyEXP(s->val.expr);
            printf(";");
            break;
        case ifK:
            printf("if (");
            prettyEXP(s->val.ifE.expr);
            printf(")");
            prettySTM(s->val.ifE.stm);
            break;
        case ifelseK:
            printf("if (");
            prettyEXP(s->val.ifelseE.expr);
            printf(")");
            prettySTM(s->val.ifelseE.stm1);
            printf("\n else");
            prettySTM(s->val.ifelseE.stm2);
            break;
        case whileK:
            printf("while (");
            prettyEXP(s->val.whileE.expr);
            printf(")");
            prettySTM(s->val.whileE.stm);
            break;
        case compoundK:
            prettyCOMPOUNDSTM(s->val.compoundstm);
            break;
        case exprK:
            prettyEXP(s->val.expr);
            printf(";");
            break;
    }
}

void prettyCOMPOUNDSTM(COMPOUNDSTM* c)
{
    if(c == NULL) return;
    printf("{");
    prettyVARIABLE(c->variable);
    prettySTM(c->stm);
    printf("}");
}

void prettyDOCUMENT(DOCUMENT* d)
{
    if(d == NULL) return;
    switch(d->kind) {
        case idK:
            prettyID(d->val.id);
            break;
        case plugK:
            printf("plug ");
            prettyID(d->val.plugE.id);
            printf("[");
            prettyPLUG(d->val.plugE.plug);
            printf("]");
            break;
    }
}

void prettyRECEIVE(RECEIVE* r)
{
    if(r == NULL) return;
    printf("receive [");
    prettyINPUT(r->input);
    printf("]");
}


void prettyPLUG(PLUG* p)
{
    if(p == NULL) return;
    prettyID(p->id);
    printf(" = ");
    prettyEXP(p->expr);
    prettyPLUG(p->next);

}

void prettyINPUT(INPUT* i)
{
    if(i == NULL) return;
    prettyLVALUE(i->lvalue);
    printf(" = ");
    prettyID(i->id);
    prettyINPUT(i->next);
}

void prettyLVALUE(LVALUE* l)
{
    if(l == NULL) return;
    prettyID(l->id1);
    if(l->id2 != NULL)
    {
        printf(".");
        prettyID(l->id2);
    }
}

void prettyFIELDVALUE(FIELDVALUE* f)
{
    if(f == NULL) return;
    prettyID(f->id);
    printf(" = ");
    prettyEXP(f->expr);
}

void prettyEXP(EXP* e)
{
    if(e == NULL) return;
    switch(e->kind)
    {
        case lvalueK:
            prettyLVALUE(e->val.lvalueE);
            break;
        case assignK:
            prettyLVALUE(e->val.assignE.lvalue);
            printf(" = ");
            prettyEXP(e->val.assignE.expr);
            break;
        case equalsK:
            prettyEXP(e->val.equalsE.left);
            printf(" == ");
            prettyEXP(e->val.equalsE.right);
            break;
        case notequalsK:
            prettyEXP(e->val.notequalsE.left);
            printf(" != ");
            prettyEXP(e->val.notequalsE.right);
            break;
        case ltK:
            prettyEXP(e->val.ltE.left);
            printf(" < ");
            prettyEXP(e->val.ltE.right);
            break;
        case gtK:
            prettyEXP(e->val.gtE.left);
            printf(" > ");
            prettyEXP(e->val.gtE.right);
            break;
        case lteK:
            prettyEXP(e->val.lteE.left);
            printf(" <= ");
            prettyEXP(e->val.lteE.right);
            break;
        case gteK:
            prettyEXP(e->val.gteE.left);
            printf(" >= ");
            prettyEXP(e->val.gteE.right);
            break;
        case notK:
            printf("!");
            prettyEXP(e->val.expr);
            break;
        case plusK:
            prettyEXP(e->val.plusE.left);
            printf(" + ");
            prettyEXP(e->val.plusE.right);
            break;
        case minusK:
            prettyEXP(e->val.minusE.left);
            printf(" - ");
            prettyEXP(e->val.minusE.right);
            break;
        case multK:
            prettyEXP(e->val.multE.left);
            printf(" * ");
            prettyEXP(e->val.multE.right);
            break;
        case divK:
            prettyEXP(e->val.divE.left);
            printf(" / ");
            prettyEXP(e->val.divE.right);
            break;
        case modK:
            prettyEXP(e->val.modE.left);
            printf(" %% ");
            prettyEXP(e->val.modE.right);
            break;
        case andK:
            prettyEXP(e->val.andE.left);
            printf(" && ");
            prettyEXP(e->val.andE.right);
            break;
        case orK:
            prettyEXP(e->val.orE.left);
            printf(" || ");
            prettyEXP(e->val.orE.right);
            break;
        case joinK:
            prettyEXP(e->val.joinE.left);
            printf(" << ");
            prettyEXP(e->val.joinE.right);
            break;
        case keepK:
            prettyEXP(e->val.keepE.left);
            printf(" \\+ ");
            prettyID(e->val.keepE.right);
            break;
        case removeK:
            prettyEXP(e->val.removeE.left);
            printf(" \\- ");
            prettyID(e->val.removeE.right);
            break;
        case callK:
            prettyID(e->val.removeE.right);
            printf("(");
            prettyEXP(e->val.removeE.left);
            printf(")");
            break;
        case intconstK:
            printf("%d", e->val.intconstE);
            break;
        case trueK:
            printf("true");
            break;
        case falseK:
            printf("false");
            break;
        case stringconstK:
            printf("%s", e->val.stringconstE);
            break;
        case tupleK:
            printf("tuple {");
            prettyFIELDVALUE(e->val.tupleE);
            printf("}");
            break;
        prettyEXP(e->next);
    }
}
