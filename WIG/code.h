#ifndef CODE_H
#define CODE_H

#include "tree.h"
#include <stdio.h>

void cSetofile(FILE *f);
void codeSERVICE(SERVICE *s);
void codeHTML(HTML* h);
void codeHTMLBODY(HTMLBODY* h);
void codeINPUTATTR(INPUTATTR* i);
void codeATTRIBUTE(ATTRIBUTE* a);
void codeATTR(ATTR* a);
void codeSCHEMA(SCHEMA* s);
void codeFIELD(FIELD* f);
void codeVARIABLE(VARIABLE* v);
void codeID(ID* i);
void codeIDs(ID* i, TYPE* t);
void codeTYPE(TYPE* t);
void codeSIMPLETYPE(SIMPLETYPE* s);
void codeFUNCTION(FUNCTION* f);
void codeARGUMENT(ARGUMENT* a);
void codeARGUMENTpush(ARGUMENT* a);
void codeSESSION(SESSION* s);
void codeSTM(STM* s, int session);
void codeCOMPOUNDSTM(COMPOUNDSTM* c, int session);
void codeDOCUMENT(DOCUMENT* d);
void codeRECEIVE(RECEIVE* r);
void codePLUG(PLUG* p);
void codeINPUT(INPUT* i);
void codeLVALUE(LVALUE* l);
void codeFIELDVALUE(FIELDVALUE* f);
void codeEXP(EXP* e);
void countshowSTM(STM* s, int *small_show, int *big_show);

#endif /* !CODE_H */