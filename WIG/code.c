#include <stdio.h>
#include "code.h"

FILE* cOfile;
int cIndent = 0;
int show_num = 0;
const int cTAB_WIDTH = 4;

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

void allSessionNames(SESSION* s)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        allSessionNames(s->next);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "'");
    codeID(s->id);
    fprintf(cOfile, "': session_");
    codeID(s->id);
}

void codeSERVICE(SERVICE* s)
{
    if(s == NULL) return;
    fprintf(cOfile, "#!/usr/bin/python"); cNewline();
    cNewline();
    fprintf(cOfile, "import sys"); cNewline();
    fprintf(cOfile, "import os"); cNewline();
    fprintf(cOfile, "import random"); cNewline();
    fprintf(cOfile, "import pickle"); cNewline();
    fprintf(cOfile, "import cgi"); cNewline();
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
    if(s->schema != NULL)
    {
        cNewline();
        codeSCHEMA(s->schema);
        cNewline();
    }
    fprintf(cOfile, "counter = 0"); cNewline();
    if(s->variable != NULL)
    {
        fprintf(cOfile, "v = VarStack(None, {");
        codeVARIABLE(s->variable);
        fprintf(cOfile, "})");
        cNewline();
    }
    fprintf(cOfile, "session=''"); cNewline();
    fprintf(cOfile, "sid = ''"); cNewline();
    fprintf(cOfile, "receives = {}"); cNewline();
    cNewline();
    fprintf(cOfile, "def show(html, num, **kwargs):"); cIndent++; cNewline();
        fprintf(cOfile, "global sid"); cNewline();
        fprintf(cOfile, "global counter"); cNewline();
        fprintf(cOfile, "counter = num"); cNewline();
        fprintf(cOfile, "if sid == '':"); cIndent++; cNewline();
            fprintf(cOfile, "sid = str('%%030x' %% random.randrange(256**15))"); cIndent--; cNewline();
        fprintf(cOfile, "save_context()"); cNewline();
        fprintf(cOfile, "print ('<html><form method=\"POST\" action=\"?' + str(session) + '$' + str(sid) + '\">')"); cNewline();
        fprintf(cOfile, "html(**kwargs)"); cNewline();
        fprintf(cOfile, "print ('<input type=\"submit\" value=\"go\" /></form></body></body></html>')"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def exit(html, **kwargs):"); cIndent++; cNewline();
        fprintf(cOfile, "if sid != 0:"); cIndent++; cNewline();
            fprintf(cOfile, "os.remove(sid + \".ws\")"); cIndent--; cNewline();
        fprintf(cOfile, "print ('<html><form method=\"POST\" action=\"?' + str(session) + '$' + str(sid) + '\">')"); cNewline();
        fprintf(cOfile, "html(**kwargs)"); cNewline();
        fprintf(cOfile, "print ('</form></body></body></html>')"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "def save_context():"); cIndent++; cNewline();
        fprintf(cOfile, "global counter"); cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "f = open(sid + \".ws\", \"w\")"); cNewline();
        fprintf(cOfile, "pickle.dump((counter, v), f)"); cNewline();
        fprintf(cOfile, "f.close()"); cIndent--; cNewline();
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
    fprintf(cOfile, "def pop_function():"); cIndent++; cNewline();
        fprintf(cOfile, "global v"); cNewline();
        fprintf(cOfile, "while isinstance(v, VarStack):"); cIndent++; cNewline();
            fprintf(cOfile, "v = v.parent"); cIndent--; cNewline();
        fprintf(cOfile, "v = v.parent"); cIndent--; cNewline();
    cNewline();
    fprintf(cOfile, "###############################################################################"); cNewline();
    if(s->html != NULL)
    {
        cNewline();
        codeHTML(s->html);
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
    cNewline();
    cNewline();
    fprintf(cOfile, "if __name__ == '__main__':"); cIndent++; cNewline();
        fprintf(cOfile, "print \"Content-Type: text/html\\n\"");cNewline();
        fprintf(cOfile, "sessions = {");
        allSessionNames(s->session);
        fprintf(cOfile, "}"); cNewline();
        fprintf(cOfile, "storage = cgi.FieldStorage()"); cNewline();
            /* fprintf(cOfile, "session, sep, sid = storage.getfirst('a').partition('$')"); cIndent--; cNewline(); */
        fprintf(cOfile, "s = os.environ['QUERY_STRING']"); cNewline();
        fprintf(cOfile, "if '$' in s:"); cIndent++; cNewline();
            fprintf(cOfile, "i = s.index('$')"); cNewline();
            fprintf(cOfile, "session, sep, sid = s[0:i], s[i], s[i+1:]"); cIndent--; cNewline();
        fprintf(cOfile, "else:"); cIndent++; cNewline();
            fprintf(cOfile, "session, sep, sid = s, '', ''"); cIndent--; cNewline();
        fprintf(cOfile, "if session not in sessions:"); cIndent++; cNewline();
            fprintf(cOfile, "print '<html>You did not enter a valid session name.<br>Try one of these:<br>'"); cNewline();
            fprintf(cOfile, "for s in sessions:"); cIndent++; cNewline();
                fprintf(cOfile, "print \" -<a href='?\" + s + \"'>\", s, \"</a><br>\""); cIndent--; cNewline();
            fprintf(cOfile, "print \"</html>\""); cIndent--; cNewline();
        fprintf(cOfile, "elif sep == '$':"); cIndent++; cNewline();
            fprintf(cOfile, "try:"); cIndent++; cNewline();
                fprintf(cOfile, "f = open(sid + \".ws\", \"r\")"); cNewline();
                fprintf(cOfile, "counter, v = pickle.load(f)"); cNewline();
                fprintf(cOfile, "f.close()"); cIndent--; cNewline();
            fprintf(cOfile, "except IOError:"); cIndent++; cNewline();
                fprintf(cOfile, "print \"Your session key is not valid.<br>Try one of the sessions below for a new key<br>\""); cNewline();
                fprintf(cOfile, "for s in sessions:"); cIndent++; cNewline();
                    fprintf(cOfile, "print \" -<a href='?\" + s + \"'>\", s, \"</a><br>\""); cIndent--; cNewline();
                fprintf(cOfile, "print \"</html>\""); cIndent--; cNewline();
            fprintf(cOfile, "else:"); cIndent++; cNewline();
                fprintf(cOfile, "for i in storage:"); cIndent++; cNewline();
                    fprintf(cOfile, "receives[i] = str(storage[i].value)"); cIndent--; cNewline();
                fprintf(cOfile, "sessions[session]()"); cIndent -= 2; cNewline();
        fprintf(cOfile, "else:"); cIndent++; cNewline();
            fprintf(cOfile, "sessions[session]()"); cIndent -= 2; cNewline();
}

void codeHTML(HTML* h)
{
    if(h == NULL) return;
    if(h->next != NULL)
    {
        codeHTML(h->next);
        cNewline();
    }
    fprintf(cOfile, "def html_");
    codeID(h->identifier);
    fprintf(cOfile, "(**kwargs):");
    cIndent++;
    cNewline();
    fprintf(cOfile, "print (\"\"\"");
    codeHTMLBODY(h->body);
    fprintf(cOfile, "\"\"\")");
    cIndent--;
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
            fprintf(cOfile, "\"\"\" + str(kwargs[\"p_");
            codeID(h->val.id);
            fprintf(cOfile, "\"]) + \"\"\"");
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
    fprintf(cOfile, "def fn_");
    codeID(f->id);
    fprintf(cOfile, "(");
    codeARGUMENT(f->argument);
    fprintf(cOfile, "):");
    cIndent++;
    cNewline();
    fprintf(cOfile, "function_context({");
    codeARGUMENTpush(f->argument);
    fprintf(cOfile, "})");
    cNewline();
    codeCOMPOUNDSTM(f->compoundstm, 0);
    cNewline();
    fprintf(cOfile, "pop_function()");
    cIndent--;
    cNewline();
}

void codeARGUMENTpush(ARGUMENT* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        codeARGUMENTpush(a->next);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "\"");
    codeID(a->id);
    fprintf(cOfile, "\": p_");
    codeID(a->id);
}

void codeARGUMENT(ARGUMENT* a)
{
    if(a == NULL) return;
    if(a->next != NULL)
    {
        codeARGUMENT(a->next);
        fprintf(cOfile, ", ");
    }
    fprintf(cOfile, "p_");
    codeID(a->id);
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
    fprintf(cOfile, "():");
    cIndent++;
    cNewline();
    fprintf(cOfile, "global counter");
    cNewline();
    fprintf(cOfile, "global v");
    cNewline();
    codeCOMPOUNDSTM(s->compoundstm, 1);
    cIndent--;
}

void codeSTM(STM* s, int session)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        codeSTM(s->next, session);
        cNewline();
    }
    
    switch(s->kind) {
        case semicolonK:
            fprintf(cOfile, "pass");
            /* cNewline(); */
            break;
        case showK:
            fprintf(cOfile, "return show(html_");
            codeDOCUMENT(s->val.showE.doc);
            fprintf(cOfile, ")");
            cIndent--;
            cNewline();
            fprintf(cOfile, "if counter == %d:", show_num);
            cIndent++;
            cNewline();
            fprintf(cOfile, "counter = 0");
            cNewline();
            if(s->val.showE.rec != NULL)
            {
                codeRECEIVE(s->val.showE.rec);
            }
            cIndent--;
            cNewline();
            fprintf(cOfile, "if counter <= %d:", show_num);
            cIndent++;
            break;
        case exitK:
            fprintf(cOfile, "return exit(html_");
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
            {
                int small_show=0, big_show=0;
                if (session)
                {
                    countshowSTM(s->val.ifE.stm, &small_show, &big_show);
                    if (small_show)
                    {
                        cIndent--;
                        cNewline();
                        fprintf(cOfile, "if counter <= %d:", big_show);
                        cIndent++;
                        cNewline();
                        fprintf(cOfile, "if (%d <= counter <= %d) or ", small_show, big_show);
                    }
                    else
                        fprintf(cOfile, "if ");
                }
                else
                {
                    fprintf(cOfile, "if ");
                }
                codeEXP(s->val.ifE.expr);
                fprintf(cOfile, ":");
                cIndent++;
                cNewline();
                codeSTM(s->val.ifE.stm, session);
                cIndent--;
            }
            break;
        case ifelseK:
            if (session)
            {
                int small_show=0, big_show=0;
                countshowSTM(s, &small_show, &big_show);
                if (small_show)
                {
                    small_show = 0;
                    big_show = 0;
                    countshowSTM(s->val.ifelseE.stm1, &small_show, &big_show);
                    if (small_show)
                    {
                        cIndent--;
                        cNewline();
                        fprintf(cOfile, "if counter <= %d:", big_show);
                        cIndent++;
                        cNewline();
                        fprintf(cOfile, "if (%d <= counter <= %d) or ", small_show, big_show);
                    }
                    else
                    {   /* there were no shows, can skip the crazy logic */
                        fprintf(cOfile, "if ");
                    }

                    codeEXP(s->val.ifelseE.expr);
                    fprintf(cOfile, ":");
                    cIndent++;
                    cNewline();
                    codeSTM(s->val.ifelseE.stm1, session);
                    cIndent--;
                    cNewline();
                    fprintf(cOfile, "el");

                    if(!(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK))
                    {   /* else */
                        int small_show=0, big_show=0;
                        countshowSTM(s->val.ifelseE.stm2, &small_show, &big_show);

                        if (small_show)
                            fprintf(cOfile, "if %d <= counter <= %d:", small_show, big_show);
                        else
                            fprintf(cOfile, "se:");
                        cIndent++;
                        cNewline();
                        codeSTM(s->val.ifelseE.stm2, session);
                        cIndent--;
                    }
                    else
                    {   /* elif */
                        codeSTM(s->val.ifelseE.stm2, session);
                    }
                    break;
                }
            }
            fprintf(cOfile, "if ");
            codeEXP(s->val.ifelseE.expr);
            fprintf(cOfile, ":");
            cIndent++;
            cNewline();
            codeSTM(s->val.ifelseE.stm1, session);
            cIndent--;
            cNewline();
            fprintf(cOfile, "el");
            if(!(s->val.ifelseE.stm2->kind == ifK || s->val.ifelseE.stm2->kind == ifelseK))
            {   /* else */
                fprintf(cOfile, "se:");
                cIndent++;
                cNewline();
                codeSTM(s->val.ifelseE.stm2, session);
                cIndent--;
            }
            else
            {   /* elif */
                codeSTM(s->val.ifelseE.stm2, session);
            }
            break;
        case whileK:
            {
                int small_show=0, big_show=0;
                if (session)
                {
                    countshowSTM(s->val.whileE.stm, &small_show, &big_show);
                    if (small_show)
                    {
                        cIndent--;
                        cNewline();
                        fprintf(cOfile, "if counter <= %d:", big_show);
                        cIndent++;
                        cNewline();
                        fprintf(cOfile, "while (%d <= counter <= %d) or ", small_show, big_show);
                    }
                    else
                    {   /* there were no shows, can skip the crazy logic */
                        fprintf(cOfile, "while ");
                    }
                }
                else
                {
                    fprintf(cOfile, "while ");
                }
                codeEXP(s->val.whileE.expr);
                fprintf(cOfile, ":");
                cIndent++;
                cNewline();
                codeSTM(s->val.whileE.stm, session);
                cIndent--;
            }
            break;
        case compoundK:
            codeCOMPOUNDSTM(s->val.compoundstm, session);
            break;
        case exprK:
            codeEXP(s->val.expr);
            /* cNewline(); */
            break;
    }
}

void countshowSTM(STM* s, int *small_show, int *big_show)
{
    if(s == NULL) return;
    if(s->next != NULL)
    {
        countshowSTM(s->next, small_show, big_show);
    }
    switch(s->kind) {
        case whileK:
            countshowSTM(s->val.whileE.stm, small_show, big_show);
            break;
        case showK:
            if(*small_show)
            {
                (*big_show)++;
            }
            else
            {
                *small_show = show_num + 1;
                *big_show = show_num + 1;
            }
            break;
        case ifK:
            countshowSTM(s->val.ifE.stm, small_show, big_show);
            break;
        case ifelseK:
            countshowSTM(s->val.ifelseE.stm1, small_show, big_show);
            countshowSTM(s->val.ifelseE.stm2, small_show, big_show);
            break;
        case compoundK:
            countshowSTM(s->val.compoundstm->stm, small_show, big_show);
            break;
        default:
            break;
    }
}

void codeCOMPOUNDSTM(COMPOUNDSTM* c, int session)
{
    int declares_vars;
    if(c == NULL) return;
    declares_vars = (c->variable != NULL);
    if (session)
    {
        fprintf(cOfile, "if counter <= %d:", show_num);
        cIndent++;
        cNewline();
    }
    if(declares_vars)
    {
        fprintf(cOfile, "push_context({");
        codeVARIABLE(c->variable);
        fprintf(cOfile, "})");
        cNewline();
    }
    codeSTM(c->stm, session);
    if(declares_vars)
    {
        cNewline();
        fprintf(cOfile, "pop_context()");
    }
    if (session)
        cIndent--;
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
        codeINPUT(r->input);
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
        cNewline();
    }
    codeLVALUE(i->lvalue);
    switch(i->lvalue->type->val.simpletype->kind)
    {
        case stringK:
            fprintf(cOfile, " = str(");
            break;
        case intK:
            fprintf(cOfile, " = int(");
            break;
        case boolK:
            fprintf(cOfile, " = ('true' == ");
            break;
        default:
            break;
    }
    fprintf(cOfile, "receives[\"");
    codeID(i->id);
    fprintf(cOfile, "\"])");
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

int isString(TYPE* t)
{
    return ((t->kind == simpletypeK) && (t->val.simpletype->kind == stringK));
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
            {
                int strme = 0;
                strme =  (isString(e->val.plusE.left->type) +
                        isString(e->val.plusE.right->type) * 2);
                if ((strme % 3) && (strme & 2))
                    fprintf(cOfile, "str(");
                codeEXP(e->val.plusE.left);
                if ((strme % 3) && (strme & 2))
                    fprintf(cOfile, ")");
                fprintf(cOfile, " + ");
                if ((strme % 3) && (strme & 1))
                    fprintf(cOfile, "str(");
                codeEXP(e->val.plusE.right);
                if ((strme % 3) && (strme & 1))
                    fprintf(cOfile, ")");
            }
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

