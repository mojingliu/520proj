#ifndef PRETTY_H
#define PRETTY_H

#include "tree.h"
#include <stdio.h>

void prettySERVICE(SERVICE *s);
void prettyHTML(HTML* h);
void prettyHTMLBODY(HTMLBODY* h);
void prettyINPUTATTR(INPUTATTR* i);
void prettyATTRIBUTE(ATTRIBUTE* a);
void prettyATTR(ATTR* a);
void prettySCHEMA(SCHEMA* s);
void prettyFIELD(FIELD* f);
void prettyVARIABLE(VARIABLE* v);
void prettyID(ID* i);
void prettyTYPE(TYPE* t);
void prettySIMPLETYPE(SIMPLETYPE* s);
void prettyFUNCTION(FUNCTION* f);
void prettyARGUMENT(ARGUMENT* a);
void prettySESSION(SESSION* s);
void prettySTM(STM* s);
void prettyCOMPOUNDSTM(COMPOUNDSTM* c);
void prettyDOCUMENT(DOCUMENT* d);
void prettyRECEIVE(RECEIVE* r);
void prettyPLUG(PLUG* p);
void prettyINPUT(INPUT* i);
void prettyLVALUE(LVALUE* l);
void prettyFIELDVALUE(FIELDVALUE* f);
void prettyEXP(EXP* e);

void setofile(FILE* f);

#endif /* !PRETTY_H */