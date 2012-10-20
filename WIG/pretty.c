#include <stdio.h>
#include "pretty.h"

int indent = 0;
const int TAB_WIDTH = 2;

void newline()
{
    int i=0;
    printf("\n");
    for(; i<indent * TAB_WIDTH; i++)
        printf(" ");
}

void prettySERVICE(SERVICE* s)
{
    if(s == NULL) return;
    printf("service {");
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
    printf("}");
}

void prettyHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        prettyHTML(h->next);
        newline();
    }
    printf("const html ");
    prettyID(h->identifier);
    printf(" = <html>");
    prettyHTMLBODY(h->body);
    printf("</html>;");
    newline();
}

void prettyHTMLBODY(HTMLBODY* h)
{
    if(h == NULL) return;
    prettyHTMLBODY(h->next);
    switch (h->kind) {
        case tagK:
            printf("<");
            prettyID(h->val.tagE.id);
            if(h->val.tagE.attribute != NULL)
            {
                printf(" ");
                prettyATTRIBUTE(h->val.tagE.attribute);
            }
            printf(">");
            break;
        case gapK:
            printf("<[");
            prettyID(h->val.id);
            printf("]>");
            break;
        case whateverK:
            printf("%s", h->val.whatever);
            break;
        case metaK:
            printf("%s", h->val.meta);
            break;
        case inputK:
            printf("<input ");
            prettyINPUTATTR(h->val.inputattr);
            printf(">");
            break;
        case selectK:
            printf("<select ");
            prettyINPUTATTR(h->val.selectE.inputattr);
            printf(">");
            prettyHTMLBODY(h->val.selectE.body);
            printf("</select>");
            break;
    }
}

void prettyINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyINPUTATTR(i->next);
        printf(" ");
    }
    switch(i->kind) {
        case nameK:
            printf("name=");
            prettyATTR(i->val.attr);
            break;
        case textK:
            printf("type=\"text\"");
            break;
        case radioK:
            printf("type=\"radio\"");
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
        printf(" ");
    }
    prettyATTR(a->left);
    if(a->right != NULL)
    {
        printf("=");
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
            printf("\"%s\"", a->val.stringconst);
            break;
        case attrintconstK:
            printf("%d", a->val.intconst);
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
    printf("schema ");
    prettyID(s->id);
    printf(" {");
    prettyFIELD(s->field);
    printf("}");
}

void prettyFIELD(FIELD* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyFIELD(f->next);
        printf(" ");
    }
    prettySIMPLETYPE(f->simpletype);
    prettyID(f->id);
    printf(";");
}

void prettyVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    if(v->next != NULL)
    {
        prettyVARIABLE(v->next);
        /*printf("");*/
    }
    prettyTYPE(v->type);
    prettyID(v->id);
    printf(";");
    newline();
}

void prettyID(ID* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyID(i->next);
        printf(", ");
    }
    printf("%s", i->identifier);
}

void prettyTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            prettySIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            printf("tuple ");
            prettyID(t->val.id);
            printf(" ");
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
    if(f->next != NULL)
    {
        prettyFUNCTION(f->next);
        newline();
    }
    prettyTYPE(f->type);
    prettyID(f->id);
    printf("(");
    prettyARGUMENT(f->argument);
    printf(")");
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
        printf(", ");
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
    printf("session ");
    prettyID(s->id);
    printf("()");
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
            printf(";");
            /* newline(); */
            break;
        case showK:
            printf("show ");
            prettyDOCUMENT(s->val.showE.doc);
            if(s->val.showE.rec != NULL)
            {
                prettyRECEIVE(s->val.showE.rec);
            }
            printf(";");
            /* newline(); */
            break;
        case exitK:
            printf("exit ");
            prettyDOCUMENT(s->val.doc);
            printf(";");
            /* newline(); */
            break;
        case returnK:
            printf("return;");
            /* newline(); */
            break;
        case returnexprK:
            printf("return ");
            prettyEXP(s->val.expr);
            printf(";");
            /* newline(); */
            break;
        case ifK:
            printf("if(");
            prettyEXP(s->val.ifE.expr);
            printf(")");
            if(s->val.ifE.stm != NULL && s->val.ifE.stm->kind != compoundK)
                indent++;
            newline();
            prettySTM(s->val.ifE.stm);
            break;
        case ifelseK:
            printf("if(");
            prettyEXP(s->val.ifelseE.expr);
            printf(")");
            if(s->val.ifelseE.stm1 != NULL && s->val.ifelseE.stm1->kind != compoundK)
                indent++;
            newline();
            prettySTM(s->val.ifelseE.stm1);
            indent = myindent;
            newline();
            printf("else");
            if(s->val.ifelseE.stm2 != NULL)
            {
                if(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK)
                    printf(" ");
                else if(s->val.ifelseE.stm2->kind != compoundK)
                {
                    indent++;
                    newline();
                }
            }
            prettySTM(s->val.ifelseE.stm2);
            break;
        case whileK:
            printf("while(");
            prettyEXP(s->val.whileE.expr);
            printf(")");
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
            printf(";");
            /* newline(); */
            break;
    }
    indent = myindent;
}

void prettyCOMPOUNDSTM(COMPOUNDSTM* c)
{
    if(c == NULL) return;
    /* newline(); */
    printf("{");
    indent++;
    newline();
    prettyVARIABLE(c->variable);
    prettySTM(c->stm);
    indent--;
    newline();
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
    if(r->input != NULL)
    {
        printf(" receive [");
        prettyINPUT(r->input);
        printf("]");
    }
}


void prettyPLUG(PLUG* p)
{
    if(p == NULL) return;
    if(p->next != NULL)
    {
        prettyPLUG(p->next);
        printf(", ");
    }
    prettyID(p->id);
    printf(" = ");
    prettyEXP(p->expr);
}

void prettyINPUT(INPUT* i)
{
    if(i == NULL) return;
    if(i->next)
    {
        prettyINPUT(i->next);
        printf(", ");
    }
    prettyLVALUE(i->lvalue);
    printf(" = ");
    prettyID(i->id);
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
    if(f->next != NULL)
    {
        prettyFIELDVALUE(f->next);
        printf(", ");
    }
    prettyID(f->id);
    printf(" = ");
    prettyEXP(f->expr);
}

void prettyEXP(EXP* e)
{
    if(e == NULL) return;
    if(e->next != NULL)
    {
        prettyEXP(e->next);
        printf(", ");
    }
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
            prettyEXP(e->val.exprE);
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
            printf("\"%s\"", e->val.stringconstE);
            break;
        case tupleK:
            printf("tuple {");
            prettyFIELDVALUE(e->val.tupleE);
            printf("}");
            break;
        case parenK:
            printf("(");
            prettyEXP(e->val.exprE);
            printf(")");
            break;
    }
}

