#include "prettytype.h"

FILE* typeofile;
int typeindent = 0;
const int TYPE_TAB_WIDTH = 2; 

void settypeofile(FILE *f){
    typeofile = f;
}

void typenewline()
{
    int i=0;
    fprintf(typeofile, "\n");
    for(; i<typeindent * TYPE_TAB_WIDTH; i++)
        fprintf(typeofile, " ");
}

void prettyTypeSERVICE(SERVICE* s)
{
    if(s == NULL) return;
    fprintf(typeofile, "service {");
    typeindent++;
    if(s->html != NULL)
    {
        typenewline();
        prettyTypeHTML(s->html);
    }
    if(s->schema != NULL)
    {
        typenewline();
        prettyTypeSCHEMA(s->schema);
    }
    if(s->variable != NULL)
    {
        typenewline();
        prettyTypeVARIABLE(s->variable);
    }
    if(s->function != NULL)
    {
        typenewline();
        prettyTypeFUNCTION(s->function);
    }
    if(s->session != NULL)
    {
        typenewline();
        prettyTypeSESSION(s->session);
    }
    typeindent--;
    typenewline();
    fprintf(typeofile, "}");
}

void prettyTypeHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        prettyTypeHTML(h->next);
        typenewline();
    }
    fprintf(typeofile, "const html ");
    prettyTypeID(h->identifier);
    fprintf(typeofile, " = <html>");
    prettyTypeHTMLBODY(h->body);
    fprintf(typeofile, "</html>;");
    typenewline();
}

void prettyTypeHTMLBODY(HTMLBODY* h)
{
    if(h == NULL) return;
    prettyTypeHTMLBODY(h->next);
    switch (h->kind) {
        case tagK:
            fprintf(typeofile, "<");
            prettyTypeID(h->val.tagE.id);
            if(h->val.tagE.attribute != NULL)
            {
                fprintf(typeofile, " ");
                prettyTypeATTRIBUTE(h->val.tagE.attribute);
            }
            fprintf(typeofile, ">");
            break;
        case gapK:
            fprintf(typeofile, "<[");
            prettyTypeID(h->val.id);
            fprintf(typeofile, "]>");
            break;
        case whateverK:
            fprintf(typeofile, "%s", h->val.whatever);
            break;
        case metaK:
            fprintf(typeofile, "%s", h->val.meta);
            break;
        case inputK:
            fprintf(typeofile, "<input ");
            prettyTypeINPUTATTR(h->val.inputattr);
            fprintf(typeofile, ">");
            break;
        case selectK:
            fprintf(typeofile, "<select ");
            prettyTypeINPUTATTR(h->val.selectE.inputattr);
            fprintf(typeofile, ">");
            prettyTypeHTMLBODY(h->val.selectE.body);
            fprintf(typeofile, "</select>");
            break;
    }
}

void prettyTypeINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyTypeINPUTATTR(i->next);
        fprintf(typeofile, " ");
    }
    switch(i->kind) {
        case nameK:
            fprintf(typeofile, "name=");
            prettyTypeATTR(i->val.attr);
            break;
        case textK:
            fprintf(typeofile, "type=\"text\"");
            break;
        case radioK:
            fprintf(typeofile, "type=\"radio\"");
            break;
        case otherK:
            prettyTypeATTRIBUTE(i->val.attribute);
            break;
    }
}

void prettyTypeATTRIBUTE(ATTRIBUTE* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        prettyTypeATTRIBUTE(a->next);
        fprintf(typeofile, " ");
    }
    prettyTypeATTR(a->left);
    if(a->right != NULL)
    {
        fprintf(typeofile, "=");
        prettyTypeATTR(a->right);
    }
}

void prettyTypeATTR(ATTR* a)
{
    if(a == NULL) return;
    switch(a->kind) {
        case attridK:
            prettyTypeID(a->val.id);
            break;
        case attrstringconstK:
            fprintf(typeofile, "\"%s\"", a->val.stringconst);
            break;
        case attrintconstK:
            fprintf(typeofile, "%d", a->val.intconst);
            break;
    }
}


void prettyTypeSCHEMA(SCHEMA* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        prettyTypeSCHEMA(s->next);
        typenewline();
        typenewline();
    }
    fprintf(typeofile, "schema ");
    prettyTypeID(s->id);
    fprintf(typeofile, " {");
    prettyTypeFIELD(s->field);
    fprintf(typeofile, "}");
}

void prettyTypeFIELD(FIELD* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyTypeFIELD(f->next);
        fprintf(typeofile, " ");
    }
    prettyTypeSIMPLETYPE(f->simpletype);
    prettyTypeID(f->id);
    fprintf(typeofile, ";");
}

void prettyTypeVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    if(v->next != NULL)
    {
        prettyTypeVARIABLE(v->next);
        /*fprintf(typeofile, "");*/
    }
    prettyTypeTYPE(v->type);
    prettyTypeID(v->id);
    fprintf(typeofile, ";");
    typenewline();
}

void prettyTypeID(ID* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        prettyTypeID(i->next);
        fprintf(typeofile, ", ");
    }
    fprintf(typeofile, "%s", i->identifier);
}

void prettyTypeTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            prettyTypeSIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            fprintf(typeofile, "tuple ");
            prettyTypeID(t->val.id);
            fprintf(typeofile, " ");
            break;
    }
}

void prettyTypeSIMPLETYPE(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind) {
        case intK:
            fprintf(typeofile, "int ");
            break;
        case boolK:
            fprintf(typeofile, "bool ");
            break;
        case stringK:
            fprintf(typeofile, "string ");
            break;
        case voidK:
            fprintf(typeofile, "void ");
            break;
    }
}

void prettyTypeFUNCTION(FUNCTION* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyTypeFUNCTION(f->next);
        typenewline();
    }
    prettyTypeTYPE(f->type);
    prettyTypeID(f->id);
    fprintf(typeofile, "(");
    prettyTypeARGUMENT(f->argument);
    fprintf(typeofile, ")");
    typenewline();
    prettyTypeCOMPOUNDSTM(f->compoundstm);
    typenewline();
}

void prettyTypeARGUMENT(ARGUMENT* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        prettyTypeARGUMENT(a->next);
        fprintf(typeofile, ", ");
    }
    prettyTypeTYPE(a->type);
    prettyTypeID(a->id);
}

void prettyTypeSESSION(SESSION* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        prettyTypeSESSION(s->next);
        typenewline();
        typenewline();
    }
    fprintf(typeofile, "session ");
    prettyTypeID(s->id);
    fprintf(typeofile, "()");
    typenewline();
    prettyTypeCOMPOUNDSTM(s->compoundstm);
}

void prettyTypeSTM(STM* s)
{
    int mytypeindent;
    if(s == NULL) return;
    if(s->next != NULL)
    {
        prettyTypeSTM(s->next);
        typenewline();
    }
    mytypeindent = typeindent;
    
    switch(s->kind) {
        case semicolonK:
            fprintf(typeofile, ";");
            /* typenewline(); */
            break;
        case showK:
            fprintf(typeofile, "show ");
            prettyTypeDOCUMENT(s->val.showE.doc);
            if(s->val.showE.rec != NULL)
            {
                prettyTypeRECEIVE(s->val.showE.rec);
            }
            fprintf(typeofile, ";");
            /* typenewline(); */
            break;
        case exitK:
            fprintf(typeofile, "exit ");
            prettyTypeDOCUMENT(s->val.doc);
            fprintf(typeofile, ";");
            /* typenewline(); */
            break;
        case returnK:
            fprintf(typeofile, "return;");
            /* typenewline(); */
            break;
        case returnexprK:
            fprintf(typeofile, "return ");
            prettyTypeEXP(s->val.expr);
            fprintf(typeofile, ";");
            /* typenewline(); */
            break;
        case ifK:
            fprintf(typeofile, "if(");
            prettyTypeEXP(s->val.ifE.expr);
            fprintf(typeofile, ")");
            if(s->val.ifE.stm != NULL && s->val.ifE.stm->kind != compoundK)
                typeindent++;
            typenewline();
            prettyTypeSTM(s->val.ifE.stm);
            break;
        case ifelseK:
            fprintf(typeofile, "if(");
            prettyTypeEXP(s->val.ifelseE.expr);
            fprintf(typeofile, ")");
            if(s->val.ifelseE.stm1 != NULL && s->val.ifelseE.stm1->kind != compoundK)
                typeindent++;
            typenewline();
            prettyTypeSTM(s->val.ifelseE.stm1);
            typeindent = mytypeindent;
            typenewline();
            fprintf(typeofile, "else");
            if(s->val.ifelseE.stm2 != NULL)
            {
                if(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK)
                    fprintf(typeofile, " ");
                else if(s->val.ifelseE.stm2->kind != compoundK)
                {
                    typeindent++;
                    typenewline();
                }
            }
            prettyTypeSTM(s->val.ifelseE.stm2);
            break;
        case whileK:
            fprintf(typeofile, "while(");
            prettyTypeEXP(s->val.whileE.expr);
            fprintf(typeofile, ")");
            if(s->val.whileE.stm != NULL && s->val.whileE.stm->kind != compoundK)
                typeindent++;
            typenewline();
            prettyTypeSTM(s->val.whileE.stm);
            break;
        case compoundK:
            prettyTypeCOMPOUNDSTM(s->val.compoundstm);
            break;
        case exprK:
            prettyTypeEXP(s->val.expr);
            fprintf(typeofile, ";");
            /* typenewline(); */
            break;
    }
    typeindent = mytypeindent;
}

void prettyTypeCOMPOUNDSTM(COMPOUNDSTM* c)
{
    if(c == NULL) return;
    /* typenewline(); */
    fprintf(typeofile, "{");
    typeindent++;
    typenewline();
    prettyTypeVARIABLE(c->variable);
    prettyTypeSTM(c->stm);
    typeindent--;
    typenewline();
    fprintf(typeofile, "}");
}

void prettyTypeDOCUMENT(DOCUMENT* d)
{
    if(d == NULL) return;
    switch(d->kind) {
        case idK:
            prettyTypeID(d->val.id);
            break;
        case plugK:
            fprintf(typeofile, "plug ");
            prettyTypeID(d->val.plugE.id);
            fprintf(typeofile, "[");
            prettyTypePLUG(d->val.plugE.plug);
            fprintf(typeofile, "]");
            break;
    }
}

void prettyTypeRECEIVE(RECEIVE* r)
{
    if(r == NULL) return;
    if(r->input != NULL)
    {
        fprintf(typeofile, " receive [");
        prettyTypeINPUT(r->input);
        fprintf(typeofile, "]");
    }
}


void prettyTypePLUG(PLUG* p)
{
    if(p == NULL) return;
    if(p->next != NULL)
    {
        prettyTypePLUG(p->next);
        fprintf(typeofile, ", ");
    }
    prettyTypeID(p->id);
    fprintf(typeofile, " = ");
    prettyTypeEXP(p->expr);
}

void prettyTypeINPUT(INPUT* i)
{
    if(i == NULL) return;
    if(i->next)
    {
        prettyTypeINPUT(i->next);
        fprintf(typeofile, ", ");
    }
    prettyTypeLVALUE(i->lvalue);
    fprintf(typeofile, " = ");
    prettyTypeID(i->id);
}

void prettyTypeLVALUE(LVALUE* l)
{
    if(l == NULL) return;
    prettyTypeID(l->id1);
    if(l->id2 != NULL)
    {
        fprintf(typeofile, ".");
        prettyTypeID(l->id2);
    }
}

void prettyTypeFIELDVALUE(FIELDVALUE* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        prettyTypeFIELDVALUE(f->next);
        fprintf(typeofile, ", ");
    }
    prettyTypeID(f->id);
    fprintf(typeofile, " = ");
    prettyTypeEXP(f->expr);
}

void prettyTypeEXP(EXP* e)
{
    if(e == NULL) return;
    if(e->next != NULL)
    {
        prettyTypeEXP(e->next);
        fprintf(typeofile, ", ");
    }
    switch(e->kind)
    {
        case lvalueK:
            prettyTypeLVALUE(e->val.lvalueE);
            break;
        case assignK:
            prettyTypeLVALUE(e->val.assignE.lvalue);
            fprintf(typeofile, " = ");
            prettyTypeEXP(e->val.assignE.expr);
            break;
        case equalsK:
            prettyTypeEXP(e->val.equalsE.left);
            fprintf(typeofile, " == ");
            prettyTypeEXP(e->val.equalsE.right);
            break;
        case notequalsK:
            prettyTypeEXP(e->val.notequalsE.left);
            fprintf(typeofile, " != ");
            prettyTypeEXP(e->val.notequalsE.right);
            break;
        case ltK:
            prettyTypeEXP(e->val.ltE.left);
            fprintf(typeofile, " < ");
            prettyTypeEXP(e->val.ltE.right);
            break;
        case gtK:
            prettyTypeEXP(e->val.gtE.left);
            fprintf(typeofile, " > ");
            prettyTypeEXP(e->val.gtE.right);
            break;
        case lteK:
            prettyTypeEXP(e->val.lteE.left);
            fprintf(typeofile, " <= ");
            prettyTypeEXP(e->val.lteE.right);
            break;
        case gteK:
            prettyTypeEXP(e->val.gteE.left);
            fprintf(typeofile, " >= ");
            prettyTypeEXP(e->val.gteE.right);
            break;
        case notK:
            fprintf(typeofile, "!");
            prettyTypeEXP(e->val.exprE);
            break;
        case plusK:
            prettyTypeEXP(e->val.plusE.left);
            fprintf(typeofile, " + ");
            prettyTypeEXP(e->val.plusE.right);
            break;
        case minusK:
            prettyTypeEXP(e->val.minusE.left);
            fprintf(typeofile, " - ");
            prettyTypeEXP(e->val.minusE.right);
            break;
        case multK:
            prettyTypeEXP(e->val.multE.left);
            fprintf(typeofile, " * ");
            prettyTypeEXP(e->val.multE.right);
            break;
        case divK:
            prettyTypeEXP(e->val.divE.left);
            fprintf(typeofile, " / ");
            prettyTypeEXP(e->val.divE.right);
            break;
        case modK:
            prettyTypeEXP(e->val.modE.left);
            fprintf(typeofile, " %% ");
            prettyTypeEXP(e->val.modE.right);
            break;
        case andK:
            prettyTypeEXP(e->val.andE.left);
            fprintf(typeofile, " && ");
            prettyTypeEXP(e->val.andE.right);
            break;
        case orK:
            prettyTypeEXP(e->val.orE.left);
            fprintf(typeofile, " || ");
            prettyTypeEXP(e->val.orE.right);
            break;
        case joinK:
            prettyTypeEXP(e->val.joinE.left);
            fprintf(typeofile, " << ");
            prettyTypeEXP(e->val.joinE.right);
            break;
        case keepK:
            prettyTypeEXP(e->val.keepE.left);
            fprintf(typeofile, " \\+ ");
            prettyTypeID(e->val.keepE.right);
            break;
        case removeK:
            prettyTypeEXP(e->val.removeE.left);
            fprintf(typeofile, " \\- ");
            prettyTypeID(e->val.removeE.right);
            break;
        case callK:
            prettyTypeID(e->val.callE.left);
            fprintf(typeofile, "(");
            prettyTypeEXP(e->val.callE.right);
            fprintf(typeofile, ")");
            break;
        case intconstK:
            fprintf(typeofile, "%d", e->val.intconstE);
            break;
        case trueK:
            fprintf(typeofile, "true");
            break;
        case falseK:
            fprintf(typeofile, "false");
            break;
        case stringconstK:
            fprintf(typeofile, "\"%s\"", e->val.stringconstE);
            break;
        case tupleK:
            fprintf(typeofile, "tuple {");
            prettyTypeFIELDVALUE(e->val.tupleE);
            fprintf(typeofile, "}");
            break;
        case parenK:
            fprintf(typeofile, "(");
            prettyTypeEXP(e->val.exprE);
            fprintf(typeofile, ")");
            break;
    }
    printJustType(e->type);
}

void printJustType(TYPE* t)
{
    if(t == NULL) return;
    switch(t->kind){
        case tupleidK:
            if(t->schema->id == NULL)
                fprintf(typeofile, " (:tuple -anon-)");
            else
                fprintf(typeofile, " (:tuple %s)", t->schema->id->identifier);
        case simpletypeK:
            printJustSimpleType(t->val.simpletype);
            break;
    }

}

void printJustSimpleType(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind){
        case intK:
            fprintf(typeofile, " (:int)");
            break;
        case boolK:
            fprintf(typeofile, " (:bool)");
            break;
        case stringK:
            fprintf(typeofile, " (:string)");
            break;
        case voidK:
            fprintf(typeofile, " (:void)");
            break;
    }
}

