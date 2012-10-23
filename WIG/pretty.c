#include <stdio.h>
#include "pretty.h"

FILE* ofile;
int indent = 0;
const int TAB_WIDTH = 2;

void setofile(FILE *f){
    ofile = f;
}

void newline()
{
    int i=0;
    fprintf(ofile, "\n");
    for(; i<indent * TAB_WIDTH; i++)
        fprintf(ofile, " ");
}

void prettySERVICE(SERVICE* s)
{
    if(s == NULL) return;
    fprintf(ofile, "service {");
    indent++;
    if(s->html != NULL)
    {
        newline();
        prettyHTML(s->html);
    }
    if(s->schema != NULL)
    {
        newline();
        prettySCHEMA(s->schema);
    }
    if(s->variable != NULL)
    {
        newline();
        prettyVARIABLE(s->variable);
    }
    if(s->function != NULL)
    {
        newline();
        prettyFUNCTION(s->function);
    }
    if(s->session != NULL)
    {
        newline();
        prettySESSION(s->session);
    }
    indent--;
    newline();
    fprintf(ofile, "}");
}

void prettyHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        prettyHTML(h->next);
        newline();
    }
    fprintf(ofile, "const html ");
    prettyID(h->identifier);
    fprintf(ofile, " = <html>");
    prettyHTMLBODY(h->body);
    fprintf(ofile, "</html>;");
    newline();
}

void prettyHTMLBODY(HTMLBODY* h)
{
    if(h == NULL) return;
    prettyHTMLBODY(h->next);
    switch (h->kind) {
        case tagK:
            fprintf(ofile, "<");
            prettyID(h->val.tagE.id);
            if(h->val.tagE.attribute != NULL)
            {
                fprintf(ofile, " ");
                prettyATTRIBUTE(h->val.tagE.attribute);
            }
            fprintf(ofile, ">");
            break;
        case gapK:
            fprintf(ofile, "<[");
            prettyID(h->val.id);
            fprintf(ofile, "]>");
            break;
        case whateverK:
            fprintf(ofile, "%s", h->val.whatever);
            break;
        case metaK:
            fprintf(ofile, "%s", h->val.meta);
            break;
        case inputK:
            fprintf(ofile, "<input ");
            prettyINPUTATTR(h->val.inputattr);
            fprintf(ofile, ">");
            break;
        case selectK:
            fprintf(ofile, "<select ");
            prettyINPUTATTR(h->val.selectE.inputattr);
            fprintf(ofile, ">");
            prettyHTMLBODY(h->val.selectE.body);
            fprintf(ofile, "</select>");
            break;
    }
}

void prettyINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyINPUTATTR(i->next);
        fprintf(ofile, " ");
    }
    switch(i->kind) {
        case nameK:
            fprintf(ofile, "name=");
            prettyATTR(i->val.attr);
            break;
        case textK:
            fprintf(ofile, "type=\"text\"");
            break;
        case radioK:
            fprintf(ofile, "type=\"radio\"");
            break;
        case otherK:
            prettyATTRIBUTE(i->val.attribute);
            break;
    }
}

void prettyATTRIBUTE(ATTRIBUTE* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        prettyATTRIBUTE(a->next);
        fprintf(ofile, " ");
    }
    prettyATTR(a->left);
    if(a->right != NULL)
    {
        fprintf(ofile, "=");
        prettyATTR(a->right);
    }
}

void prettyATTR(ATTR* a)
{
    if(a == NULL) return;
    switch(a->kind) {
        case attridK:
            prettyID(a->val.id);
            break;
        case attrstringconstK:
            fprintf(ofile, "\"%s\"", a->val.stringconst);
            break;
        case attrintconstK:
            fprintf(ofile, "%d", a->val.intconst);
            break;
    }
}


void prettySCHEMA(SCHEMA* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        prettySCHEMA(s->next);
        newline();
        newline();
    }
    fprintf(ofile, "schema ");
    prettyID(s->id);
    fprintf(ofile, " {");
    prettyFIELD(s->field);
    fprintf(ofile, "}");
}

void prettyFIELD(FIELD* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyFIELD(f->next);
        fprintf(ofile, " ");
    }
    prettySIMPLETYPE(f->simpletype);
    prettyID(f->id);
    fprintf(ofile, ";");
}

void prettyVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    if(v->next != NULL)
    {
        prettyVARIABLE(v->next);
        /*fprintf(ofile, "");*/
    }
    prettyTYPE(v->type);
    prettyID(v->id);
    fprintf(ofile, ";");
    newline();
}

void prettyID(ID* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyID(i->next);
        fprintf(ofile, ", ");
    }
    fprintf(ofile, "%s", i->identifier);
}

void prettyTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            prettySIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            fprintf(ofile, "tuple ");
            prettyID(t->val.id);
            fprintf(ofile, " ");
            break;
    }
}

void prettySIMPLETYPE(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind) {
        case intK:
            fprintf(ofile, "int ");
            break;
        case boolK:
            fprintf(ofile, "bool ");
            break;
        case stringK:
            fprintf(ofile, "string ");
            break;
        case voidK:
            fprintf(ofile, "void ");
            break;
    }
}

void prettyFUNCTION(FUNCTION* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyFUNCTION(f->next);
        newline();
    }
    prettyTYPE(f->type);
    prettyID(f->id);
    fprintf(ofile, "(");
    prettyARGUMENT(f->argument);
    fprintf(ofile, ")");
    newline();
    prettyCOMPOUNDSTM(f->compoundstm);
    newline();
}

void prettyARGUMENT(ARGUMENT* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        prettyARGUMENT(a->next);
        fprintf(ofile, ", ");
    }
    prettyTYPE(a->type);
    prettyID(a->id);
}

void prettySESSION(SESSION* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        prettySESSION(s->next);
        newline();
        newline();
    }
    fprintf(ofile, "session ");
    prettyID(s->id);
    fprintf(ofile, "()");
    newline();
    prettyCOMPOUNDSTM(s->compoundstm);
}

void prettySTM(STM* s)
{
    int myindent;
    if(s->next != NULL)
    {
        prettySTM(s->next);
        newline();
    }
    myindent = indent;
    if(s == NULL) return;
    switch(s->kind) {
        case semicolonK:
            fprintf(ofile, ";");
            /* newline(); */
            break;
        case showK:
            fprintf(ofile, "show ");
            prettyDOCUMENT(s->val.showE.doc);
            if(s->val.showE.rec != NULL)
            {
                prettyRECEIVE(s->val.showE.rec);
            }
            fprintf(ofile, ";");
            /* newline(); */
            break;
        case exitK:
            fprintf(ofile, "exit ");
            prettyDOCUMENT(s->val.doc);
            fprintf(ofile, ";");
            /* newline(); */
            break;
        case returnK:
            fprintf(ofile, "return;");
            /* newline(); */
            break;
        case returnexprK:
            fprintf(ofile, "return ");
            prettyEXP(s->val.expr);
            fprintf(ofile, ";");
            /* newline(); */
            break;
        case ifK:
            fprintf(ofile, "if(");
            prettyEXP(s->val.ifE.expr);
            fprintf(ofile, ")");
            if(s->val.ifE.stm != NULL && s->val.ifE.stm->kind != compoundK)
                indent++;
            newline();
            prettySTM(s->val.ifE.stm);
            break;
        case ifelseK:
            fprintf(ofile, "if(");
            prettyEXP(s->val.ifelseE.expr);
            fprintf(ofile, ")");
            if(s->val.ifelseE.stm1 != NULL && s->val.ifelseE.stm1->kind != compoundK)
                indent++;
            newline();
            prettySTM(s->val.ifelseE.stm1);
            indent = myindent;
            newline();
            fprintf(ofile, "else");
            if(s->val.ifelseE.stm2 != NULL)
            {
                if(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK)
                    fprintf(ofile, " ");
                else if(s->val.ifelseE.stm2->kind != compoundK)
                {
                    indent++;
                    newline();
                }
            }
            prettySTM(s->val.ifelseE.stm2);
            break;
        case whileK:
            fprintf(ofile, "while(");
            prettyEXP(s->val.whileE.expr);
            fprintf(ofile, ")");
            if(s->val.whileE.stm != NULL && s->val.whileE.stm->kind != compoundK)
                indent++;
            newline();
            prettySTM(s->val.whileE.stm);
            break;
        case compoundK:
            prettyCOMPOUNDSTM(s->val.compoundstm);
            break;
        case exprK:
            prettyEXP(s->val.expr);
            fprintf(ofile, ";");
            /* newline(); */
            break;
    }
    indent = myindent;
}

void prettyCOMPOUNDSTM(COMPOUNDSTM* c)
{
    if(c == NULL) return;
    /* newline(); */
    fprintf(ofile, "{");
    indent++;
    newline();
    prettyVARIABLE(c->variable);
    prettySTM(c->stm);
    indent--;
    newline();
    fprintf(ofile, "}");
}

void prettyDOCUMENT(DOCUMENT* d)
{
    if(d == NULL) return;
    switch(d->kind) {
        case idK:
            prettyID(d->val.id);
            break;
        case plugK:
            fprintf(ofile, "plug ");
            prettyID(d->val.plugE.id);
            fprintf(ofile, "[");
            prettyPLUG(d->val.plugE.plug);
            fprintf(ofile, "]");
            break;
    }
}

void prettyRECEIVE(RECEIVE* r)
{
    if(r == NULL) return;
    if(r->input != NULL)
    {
        fprintf(ofile, " receive [");
        prettyINPUT(r->input);
        fprintf(ofile, "]");
    }
}


void prettyPLUG(PLUG* p)
{
    if(p == NULL) return;
    if(p->next != NULL)
    {
        prettyPLUG(p->next);
        fprintf(ofile, ", ");
    }
    prettyID(p->id);
    fprintf(ofile, " = ");
    prettyEXP(p->expr);
}

void prettyINPUT(INPUT* i)
{
    if(i == NULL) return;
    if(i->next)
    {
        prettyINPUT(i->next);
        fprintf(ofile, ", ");
    }
    prettyLVALUE(i->lvalue);
    fprintf(ofile, " = ");
    prettyID(i->id);
}

void prettyLVALUE(LVALUE* l)
{
    if(l == NULL) return;
    prettyID(l->id1);
    if(l->id2 != NULL)
    {
        fprintf(ofile, ".");
        prettyID(l->id2);
    }
}

void prettyFIELDVALUE(FIELDVALUE* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyFIELDVALUE(f->next);
        fprintf(ofile, ", ");
    }
    prettyID(f->id);
    fprintf(ofile, " = ");
    prettyEXP(f->expr);
}

void prettyEXP(EXP* e)
{
    if(e == NULL) return;
    if(e->next != NULL)
    {
        prettyEXP(e->next);
        fprintf(ofile, ", ");
    }
    switch(e->kind)
    {
        case lvalueK:
            prettyLVALUE(e->val.lvalueE);
            break;
        case assignK:
            prettyLVALUE(e->val.assignE.lvalue);
            fprintf(ofile, " = ");
            prettyEXP(e->val.assignE.expr);
            break;
        case equalsK:
            prettyEXP(e->val.equalsE.left);
            fprintf(ofile, " == ");
            prettyEXP(e->val.equalsE.right);
            break;
        case notequalsK:
            prettyEXP(e->val.notequalsE.left);
            fprintf(ofile, " != ");
            prettyEXP(e->val.notequalsE.right);
            break;
        case ltK:
            prettyEXP(e->val.ltE.left);
            fprintf(ofile, " < ");
            prettyEXP(e->val.ltE.right);
            break;
        case gtK:
            prettyEXP(e->val.gtE.left);
            fprintf(ofile, " > ");
            prettyEXP(e->val.gtE.right);
            break;
        case lteK:
            prettyEXP(e->val.lteE.left);
            fprintf(ofile, " <= ");
            prettyEXP(e->val.lteE.right);
            break;
        case gteK:
            prettyEXP(e->val.gteE.left);
            fprintf(ofile, " >= ");
            prettyEXP(e->val.gteE.right);
            break;
        case notK:
            fprintf(ofile, "!");
            prettyEXP(e->val.exprE);
            break;
        case plusK:
            prettyEXP(e->val.plusE.left);
            fprintf(ofile, " + ");
            prettyEXP(e->val.plusE.right);
            break;
        case minusK:
            prettyEXP(e->val.minusE.left);
            fprintf(ofile, " - ");
            prettyEXP(e->val.minusE.right);
            break;
        case multK:
            prettyEXP(e->val.multE.left);
            fprintf(ofile, " * ");
            prettyEXP(e->val.multE.right);
            break;
        case divK:
            prettyEXP(e->val.divE.left);
            fprintf(ofile, " / ");
            prettyEXP(e->val.divE.right);
            break;
        case modK:
            prettyEXP(e->val.modE.left);
            fprintf(ofile, " %% ");
            prettyEXP(e->val.modE.right);
            break;
        case andK:
            prettyEXP(e->val.andE.left);
            fprintf(ofile, " && ");
            prettyEXP(e->val.andE.right);
            break;
        case orK:
            prettyEXP(e->val.orE.left);
            fprintf(ofile, " || ");
            prettyEXP(e->val.orE.right);
            break;
        case joinK:
            prettyEXP(e->val.joinE.left);
            fprintf(ofile, " << ");
            prettyEXP(e->val.joinE.right);
            break;
        case keepK:
            prettyEXP(e->val.keepE.left);
            fprintf(ofile, " \\+ ");
            prettyID(e->val.keepE.right);
            break;
        case removeK:
            prettyEXP(e->val.removeE.left);
            fprintf(ofile, " \\- ");
            prettyID(e->val.removeE.right);
            break;
        case callK:
            prettyID(e->val.removeE.right);
            fprintf(ofile, "(");
            prettyEXP(e->val.removeE.left);
            fprintf(ofile, ")");
            break;
        case intconstK:
            fprintf(ofile, "%d", e->val.intconstE);
            break;
        case trueK:
            fprintf(ofile, "true");
            break;
        case falseK:
            fprintf(ofile, "false");
            break;
        case stringconstK:
            fprintf(ofile, "\"%s\"", e->val.stringconstE);
            break;
        case tupleK:
            fprintf(ofile, "tuple {");
            prettyFIELDVALUE(e->val.tupleE);
            fprintf(ofile, "}");
            break;
        case parenK:
            fprintf(ofile, "(");
            prettyEXP(e->val.exprE);
            fprintf(ofile, ")");
            break;
    }
}

