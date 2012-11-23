#include <stdio.h>
#include "code.h"

FILE* cOfile;
int cIndent = 0;
int show_num = 0;
const int cTAB_WIDTH = 2;

void cSetofile(FILE *f){
    cOfile = f;
}

void cNewline()
{
    int i=0;
    fprintf(cOfile, "\n");
    for(; i<cIndent * cTAB_WIDTH; i++)
        fprintf(cOfile, " ");
}

void codeSERVICE(SERVICE* s)
{
    if(s == NULL) return;
    fprintf(cOfile, "import sys"); cNewline();
    fprintf(cOfile, "import os"); cNewline();
    fprintf(cOfile, "import random"); cNewline();
    fprintf(cOfile, "import pickle"); cNewline();
    cNewline();
    fprintf(cOfile, "class VarStack(object):"); cIndent++; cNewline();
        fprintf(cOfile, "def __init__(self, parent, variables):"); cIndent++; cNewline();
            fprintf(cOfile, "self.parent = parent"); cNewline();
            fprintf(cOfile, "self.variables = variables"); cNewline();
        cIndent--; cNewline();
        fprintf(cOfile, "def __getitem__(self, index):"); cIndent++; cNewline();
            fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
                fprintf(cOfile, "if self.parent is None:"); cIndent++; cNewline();
                    fprintf(cOfile, "raise AttributeError"); cIndent--; cNewline();
                fprintf(cOfile, "return self.parent[index]"); cIndent--; cNewline();
            fprintf(cOfile, "return self.variables[index]"); cNewline();
        cIndent--; cNewline();
        fprintf(cOfile, "def __setitem__(self, index, val):"); cIndent++; cNewline();
            fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
                fprintf(cOfile, "if self.parent is None:"); cIndent++; cNewline();
                    fprintf(cOfile, "raise AttributeError"); cIndent--; cNewline();
                fprintf(cOfile, "self.parent[index] = val"); cNewline();
                fprintf(cOfile, "return"); cIndent--; cNewline();
            fprintf(cOfile, "self.variables[index] = val"); cIndent -= 2; cNewline();
    cNewline();
    fprintf(cOfile, "class FnStack(object):"); cIndent++; cNewline();
        fprintf(cOfile, "def __init__(self, parent, variables):"); cIndent++; cNewline();
    fprintf(cOfile, "self.parent = parent"); cNewline();
    fprintf(cOfile, "self.variables = variables"); cNewline();
    cIndent--; cNewline();
    fprintf(cOfile, "def __getitem__(self, index):"); cIndent++; cNewline();
    fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
    fprintf(cOfile, "while self.parent is not None:"); cIndent++; cNewline();
    fprintf(cOfile, "self = self.parent"); cIndent -= 2; cNewline();
    fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
    fprintf(cOfile, "raise AttributeError"); cIndent--; cNewline();
    fprintf(cOfile, "return self.variables[index]"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def __setitem__(self, index, val):"); cIndent++; cNewline();
    fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
    fprintf(cOfile, "while self.parent is not None:"); cIndent++; cNewline();
    fprintf(cOfile, "self = self.parent"); cIndent -= 2; cNewline();
    fprintf(cOfile, "if index not in self.variables:"); cIndent++; cNewline();
    fprintf(cOfile, "raise AttributeError"); cIndent--; cNewline();
    fprintf(cOfile, "self.variables[index] = val"); cIndent -= 2; cNewline();
    cNewline();
    fprintf(cOfile, "counter = 0"); cNewline();
    if(s->variable != NULL)
    {
        fprintf(cOfile, "v = VarStack(None, {");
        codeVARIABLE(s->variable);
        fprintf(cOfile, "})");
        cNewline();
    }

    fprintf(cOfile, "sid = 0"); cNewline();
    fprintf(cOfile, "receives = {}"); cNewline();
    cNewline();
    fprintf(cOfile, "def show(html, num, **kwargs):"); cIndent++; cNewline();
        fprintf(cOfile, "global sid"); cNewline();
        fprintf(cOfile, "global counter"); cNewline();
        fprintf(cOfile, "counter = num"); cNewline();
        fprintf(cOfile, "if sid == 0:"); cIndent++; cNewline();
            fprintf(cOfile, "sid = str(random.randint(1, 200000))"); cIndent--; cNewline();
        fprintf(cOfile, "save_context()"); cNewline();
        fprintf(cOfile, "html(**kwargs)"); cNewline();
        fprintf(cOfile, "print \"(session id: %%s)\"%% sid"); cNewline();
        fprintf(cOfile, "sys.exit()"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def exit(html, **kwargs):"); cIndent++; cNewline();
        fprintf(cOfile, "if sid != 0:"); cIndent++; cNewline();
            fprintf(cOfile, "os.remove(sid + \".ws\")"); cIndent--; cNewline();
        fprintf(cOfile, "html(**kwargs)"); cNewline();
        fprintf(cOfile, "sys.exit()"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def save_context():"); cIndent++; cNewline();
        fprintf(cOfile, "global counter"); cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "with open(sid + \".ws\", \"w\") as f:"); cIndent++; cNewline();
            fprintf(cOfile, "pickle.dump((counter, v), f)"); cIndent -= 2; cNewline();
    cNewline();
    fprintf(cOfile, "def push_context(new_context):"); cIndent++; cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "v = VarStack(v, new_context)"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def function_context(new_context):"); cIndent++; cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "v = FnStack(v, new_context)"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def pop_context():"); cIndent++; cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "v = v.parent"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "###############################################################################"); cNewline();
    if(s->html != NULL)
    {
        cNewline();
        codeHTML(s->html);
    }
    if(s->schema != NULL)
    {
        cNewline();
        codeSCHEMA(s->schema);
    }
    if(s->function != NULL)
    {
        cNewline();
        codeFUNCTION(s->function);
    }
    if(s->session != NULL)
    {
        cNewline();
        codeSESSION(s->session);
    }
}

void codeHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        codeHTML(h->next);
        cNewline();
    }
    fprintf(cOfile, "def html_"); codeID(h->identifier);
    fprintf(cOfile, "(**kwargs):"); cIndent++;
    cNewline();
    fprintf(cOfile, "print (\"\"\"<html>"); codeHTMLBODY(h->body);
    fprintf(cOfile, "</html>\"\"\")"); cIndent--;
    cNewline();
}

void codeHTMLBODY(HTMLBODY* h)
{   /* TODO: consideration for """ */
    if(h == NULL) return;
    codeHTMLBODY(h->next);
    switch (h->kind) {
        case tagK:
            fprintf(cOfile, "<");
            codeID(h->val.tagE.id);
            if(h->val.tagE.attribute != NULL)
            {
                fprintf(cOfile, " ");
                codeATTRIBUTE(h->val.tagE.attribute);
            }
            fprintf(cOfile, ">");
            break;
        case gapK:
            fprintf(cOfile, "\" + kwargs[\"p_");
            codeID(h->val.id);
            fprintf(cOfile, "\"] + \"");
            break;
        case whateverK:
            fprintf(cOfile, "%s", h->val.whatever);
            break;
        case metaK:
            fprintf(cOfile, "%s", h->val.meta);
            break;
        case inputK:
            fprintf(cOfile, "<input ");
            codeINPUTATTR(h->val.inputattr);
            fprintf(cOfile, ">");
            break;
        case selectK:
            fprintf(cOfile, "<select ");
            codeINPUTATTR(h->val.selectE.inputattr);
            fprintf(cOfile, ">");
            codeHTMLBODY(h->val.selectE.body);
            fprintf(cOfile, "</select>");
            break;
    }
}

void codeINPUTATTR(INPUTATTR* i)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        codeINPUTATTR(i->next);
        fprintf(cOfile, " ");
    }
    switch(i->kind) {
        case nameK:
            fprintf(cOfile, "name=");
            codeATTR(i->val.attr);
            break;
        case textK:
            fprintf(cOfile, "type=\\\"text\\\"");
            break;
        case radioK:
            fprintf(cOfile, "type=\\\"radio\\\"");
            break;
        case otherK:
            codeATTRIBUTE(i->val.attribute);
            break;
    }
}

void codeATTRIBUTE(ATTRIBUTE* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        codeATTRIBUTE(a->next);
        fprintf(cOfile, " ");
    }
    codeATTR(a->left);
    if(a->right != NULL)
    {
        fprintf(cOfile, "=");
        codeATTR(a->right);
    }
}

void codeATTR(ATTR* a)
{
    if(a == NULL) return;
    switch(a->kind) {
        case attridK:
            codeID(a->val.id);
            break;
        case attrstringconstK:
            fprintf(cOfile, "\\\"%s\\\"", a->val.stringconst);
            break;
        case attrintconstK:
            fprintf(cOfile, "%d", a->val.intconst);
            break;
    }
}


void codeSCHEMA(SCHEMA* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        codeSCHEMA(s->next);
        cNewline();
        cNewline();
    }
    fprintf(cOfile, "def schema_");
    codeID(s->id);
    fprintf(cOfile, "():"); cIndent++;
    cNewline();
    fprintf(cOfile, "return {");
    codeFIELD(s->field);
    fprintf(cOfile, "}"); cIndent--;
    cNewline();
}

void codeFIELD(FIELD* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        codeFIELD(f->next);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "\"");
    codeID(f->id);
    fprintf(cOfile, "\": ");
    codeSIMPLETYPE(f->simpletype);
}

void codeVARIABLE(VARIABLE* v)
{
    if(v == NULL) return;
    if(v->next != NULL)
    {
        codeVARIABLE(v->next);
        fprintf(cOfile, ", ");
    }
    codeIDs(v->id, v->type);
}

void codeID(ID* i)
{
    if(i == NULL) return;
    fprintf(cOfile, "%s", i->identifier);
}

void codeIDs(ID* i, TYPE* t)
{
    if(i == NULL) return;
    if(i->next != NULL)
    {
        codeIDs(i->next, t);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "\"%s\"", i->identifier);
    if(t != NULL)
    {
        fprintf(cOfile, ": ");
        codeTYPE(t);
    }
}

void codeTYPE(TYPE* t)
{
    if(t == NULL) return;
    switch (t->kind) {
        case simpletypeK:
            codeSIMPLETYPE(t->val.simpletype);
            break;
        case tupleidK:
            fprintf(cOfile, "schema_");
            codeID(t->val.id);
            fprintf(cOfile, "()");
            break;
    }
}

void codeSIMPLETYPE(SIMPLETYPE* s)
{
    if(s == NULL) return;
    switch (s->kind) {
        case intK:
            fprintf(cOfile, "0");
            break;
        case boolK:
            fprintf(cOfile, "False");
            break;
        case stringK:
            fprintf(cOfile, "\"\"");
            break;
        case voidK:
            fprintf(cOfile, "None");
            break;
    }
}

void codeFUNCTION(FUNCTION* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        codeFUNCTION(f->next);
        cNewline();
    }
    /* codeTYPE(f->type); /* Python, you're so cool. */  
    fprintf(cOfile, "def fn_");
    codeID(f->id);
    fprintf(cOfile, "(**kwargs):");
    /* codeARGUMENT(f->argument); /* Python, you're so cool */
    cIndent++;
    cNewline();
    fprintf(cOfile, "function_context(kwargs)");
    cNewline();
    codeCOMPOUNDSTM(f->compoundstm);
    cNewline();
    fprintf(cOfile, "pop_function()");
    cIndent--;
    cNewline();
}

void codeSESSION(SESSION* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        codeSESSION(s->next);
        cNewline();
        cNewline();
    }
    fprintf(cOfile, "def session_");
    codeID(s->id);
    fprintf(cOfile, "():"); cIndent++;
    cNewline();
    fprintf(cOfile, "global counter");
    cNewline();
    fprintf(cOfile, "global v");
    cNewline();
    fprintf(cOfile, "admit_one = False");
    cNewline();
    codeCOMPOUNDSTM(s->compoundstm);
    cIndent--;
}

void codeSTM(STM* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        codeSTM(s->next);
        cNewline();
    }
    
    switch(s->kind) {
        case semicolonK:
            fprintf(cOfile, "pass");
            /* cNewline(); */
            break;
        case showK:
            fprintf(cOfile, "show(html_");
            codeDOCUMENT(s->val.showE.doc);
            fprintf(cOfile, ")");
            if(s->val.showE.rec != NULL)
            {
                cNewline();
                codeRECEIVE(s->val.showE.rec);
            }
            /* cNewline(); */
            break;
        case exitK:
            fprintf(cOfile, "exit(html_");
            codeDOCUMENT(s->val.doc);
            fprintf(cOfile, ")");
            /* cNewline(); */
            break;
        case returnK:
            fprintf(cOfile, "pop_function()");
            cNewline();
            fprintf(cOfile, "return");
            /* cNewline(); */
            break;
        case returnexprK:
            fprintf(cOfile, "toR = ");
            codeEXP(s->val.expr);
            cNewline();
            fprintf(cOfile, "pop_function()");
            cNewline();
            fprintf(cOfile, "return toR");
            /* cNewline(); */
            break;
        case ifK:
            fprintf(cOfile, "if(");
            codeEXP(s->val.ifE.expr);
            fprintf(cOfile, ")");
            cIndent++;
            cNewline();
            codeSTM(s->val.ifE.stm);
            cIndent--;
            break;
        case ifelseK:
            fprintf(cOfile, "if ");
            codeEXP(s->val.ifelseE.expr);
            fprintf(cOfile, ":");
            cIndent++;
            cNewline();
            codeSTM(s->val.ifelseE.stm1);
            cIndent--;
            cNewline();
            fprintf(cOfile, "el");
            if(s->val.ifelseE.stm2 != NULL)
            {
                if(!(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK))
                {   /* else */
                    fprintf(cOfile, "se:");
                    cIndent++;
                    cNewline();
                    codeSTM(s->val.ifelseE.stm2);
                    cIndent--;
                }
                else
                {   /* elif */
                    codeSTM(s->val.ifelseE.stm2);
                }
            }
            break;
        case whileK:
            fprintf(cOfile, "while ");
            codeEXP(s->val.whileE.expr);
            fprintf(cOfile, ":");
            cIndent++;
            cNewline();
            codeSTM(s->val.whileE.stm);
            cIndent--;
            break;
        case compoundK:
            codeCOMPOUNDSTM(s->val.compoundstm);
            break;
        case exprK:
            codeEXP(s->val.expr);
            /* cNewline(); */
            break;
    }
}

void codeCOMPOUNDSTM(COMPOUNDSTM* c)
{   /* TODO: This is the crazy one */
    int declares_vars;
    declares_vars = (c->variable != NULL);
    if(c == NULL) return;
    if(declares_vars)
    {
        printf("push_context({");
        codeVARIABLE(c->variable);
        printf("})");
        cNewline();
    }
    codeSTM(c->stm);
    if(declares_vars)
    {
        cNewline();
        fprintf(cOfile, "pop_context()");
    }
    /* cNewline(); */
    /* fprintf(cOfile, "{"); cIndent++;
    cNewline();
    codeVARIABLE(c->variable);
    codeSTM(c->stm);
    cIndent--;
    cNewline();
    fprintf(cOfile, "}");*/
}

void codeDOCUMENT(DOCUMENT* d)
{
    if(d == NULL) return;
    codeID(d->val.id);
    fprintf(cOfile, ", %d", ++show_num);
    switch(d->kind) {
        case idK:
            break;
        case plugK:
            codePLUG(d->val.plugE.plug);
            break;
    }
}

void codeRECEIVE(RECEIVE* r)
{
    if(r == NULL) return;
    if(r->input != NULL)
    {
        fprintf(cOfile, "if counter == %d:", show_num - 1);
        cIndent++;
        cNewline();
        codeINPUT(r->input);
        fprintf(cOfile, "counter = 0");
        cIndent--;
    }
}


void codePLUG(PLUG* p)
{
    if(p == NULL) return;
    if(p->next != NULL)
    {
        codePLUG(p->next);
    }
    fprintf(cOfile, ", p_");
    codeID(p->id);
    fprintf(cOfile, "=");
    codeEXP(p->expr);
}

void codeINPUT(INPUT* i)
{
    if(i == NULL) return;
    if(i->next)
    {
        codeINPUT(i->next);
    }
    codeLVALUE(i->lvalue);
    fprintf(cOfile, " = receives[\"");
    codeID(i->id);
    fprintf(cOfile, "\"]");
    cNewline();
}

void codeLVALUE(LVALUE* l)
{
    if(l == NULL) return;
    fprintf(cOfile, "v[\"");
    codeID(l->id1);
    fprintf(cOfile, "\"]");
    if(l->id2 != NULL)
    {
        fprintf(cOfile, "[\"");
        codeID(l->id2);
        fprintf(cOfile, "\"]");
    }
}

void codeFIELDVALUE(FIELDVALUE* f)
{
    if(f == NULL) return;
    if(f->next != NULL)
    {
        codeFIELDVALUE(f->next);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "\"");
    codeID(f->id);
    fprintf(cOfile, "\": ");
    codeEXP(f->expr);
}

void codeEXP(EXP* e)
{
    if(e == NULL) return;
    if(e->next != NULL)
    {
        codeEXP(e->next);
        fprintf(cOfile, ", ");
    }
    switch(e->kind)
    {
        case lvalueK:
            codeLVALUE(e->val.lvalueE);
            break;
        case assignK:
            codeLVALUE(e->val.assignE.lvalue);
            fprintf(cOfile, " = ");
            codeEXP(e->val.assignE.expr);
            break;
        case equalsK:
            codeEXP(e->val.equalsE.left);
            fprintf(cOfile, " == ");
            codeEXP(e->val.equalsE.right);
            break;
        case notequalsK:
            codeEXP(e->val.notequalsE.left);
            fprintf(cOfile, " != ");
            codeEXP(e->val.notequalsE.right);
            break;
        case ltK:
            codeEXP(e->val.ltE.left);
            fprintf(cOfile, " < ");
            codeEXP(e->val.ltE.right);
            break;
        case gtK:
            codeEXP(e->val.gtE.left);
            fprintf(cOfile, " > ");
            codeEXP(e->val.gtE.right);
            break;
        case lteK:
            codeEXP(e->val.lteE.left);
            fprintf(cOfile, " <= ");
            codeEXP(e->val.lteE.right);
            break;
        case gteK:
            codeEXP(e->val.gteE.left);
            fprintf(cOfile, " >= ");
            codeEXP(e->val.gteE.right);
            break;
        case notK:
            fprintf(cOfile, "not ");
            codeEXP(e->val.exprE);
            break;
        case plusK:
            codeEXP(e->val.plusE.left);
            fprintf(cOfile, " + ");
            codeEXP(e->val.plusE.right);
            break;
        case minusK:
            codeEXP(e->val.minusE.left);
            fprintf(cOfile, " - ");
            codeEXP(e->val.minusE.right);
            break;
        case multK:
            codeEXP(e->val.multE.left);
            fprintf(cOfile, " * ");
            codeEXP(e->val.multE.right);
            break;
        case divK:
            codeEXP(e->val.divE.left);
            fprintf(cOfile, " // ");
            codeEXP(e->val.divE.right);
            break;
        case modK:
            codeEXP(e->val.modE.left);
            fprintf(cOfile, " %% ");
            codeEXP(e->val.modE.right);
            break;
        case andK:
            codeEXP(e->val.andE.left);
            fprintf(cOfile, " and ");
            codeEXP(e->val.andE.right);
            break;
        case orK:
            codeEXP(e->val.orE.left);
            fprintf(cOfile, " or ");
            codeEXP(e->val.orE.right);
            break;
        case joinK:
            fprintf(cOfile, "wig_join(");
            codeEXP(e->val.joinE.left);
            fprintf(cOfile, ", ");
            codeEXP(e->val.joinE.right);
            fprintf(cOfile, ")");
            break;
        case keepK:
            fprintf(cOfile, "wig_keep(");
            codeEXP(e->val.keepE.left);
            fprintf(cOfile, ", (");
            codeIDs(e->val.keepE.right, NULL);
            fprintf(cOfile, "))");
            break;
        case removeK:
            fprintf(cOfile, "wig_remove(");
            codeEXP(e->val.removeE.left);
            fprintf(cOfile, ", (");
            codeIDs(e->val.removeE.right, NULL);
            fprintf(cOfile, "))");
            break;
        case callK:
            fprintf(cOfile, "fn_");
            codeID(e->val.callE.left);
            fprintf(cOfile, "(");
            codeEXP(e->val.callE.right);
            fprintf(cOfile, ")");
            break;
        case intconstK:
            fprintf(cOfile, "%d", e->val.intconstE);
            break;
        case trueK:
            fprintf(cOfile, "True");
            break;
        case falseK:
            fprintf(cOfile, "False");
            break;
        case stringconstK:
            fprintf(cOfile, "\"%s\"", e->val.stringconstE);
            break;
        case tupleK:
            fprintf(cOfile, "{");
            codeFIELDVALUE(e->val.tupleE);
            fprintf(cOfile, "}");
            break;
        case parenK:
            fprintf(cOfile, "(");
            codeEXP(e->val.exprE);
            fprintf(cOfile, ")");
            break;
    }
}

