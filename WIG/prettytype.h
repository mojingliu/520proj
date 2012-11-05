#ifndef PRETTYTYPE_H
#define PRETTYTYPE_H

#include <stdio.h>
#include <string.h>
#include "memory.h"
#include "symbol.h"
#include "tree.h"

void settypeofile(FILE *f);
void newline();
void prettyTypeSERVICE(SERVICE* s);
void prettyTypeHTML(HTML* h);
void prettyTypeHTMLBODY(HTMLBODY* h);
void prettyTypeINPUTATTR(INPUTATTR* i);
void prettyTypeATTRIBUTE(ATTRIBUTE* a);
void prettyTypeATTR(ATTR* a);
void prettyTypeSCHEMA(SCHEMA* s);
void prettyTypeFIELD(FIELD* f);
void prettyTypeVARIABLE(VARIABLE* v);
void prettyTypeID(ID* i);
void prettyTypeTYPE(TYPE* t);
void prettyTypeSIMPLETYPE(SIMPLETYPE* s);
void prettyTypeFUNCTION(FUNCTION* f);
void prettyTypeARGUMENT(ARGUMENT* a);
void prettyTypeSESSION(SESSION* s);
void prettyTypeSTM(STM* s);
void prettyTypeCOMPOUNDSTM(COMPOUNDSTM* c);
void prettyTypeDOCUMENT(DOCUMENT* d);
void prettyTypeRECEIVE(RECEIVE* r);
void prettyTypePLUG(PLUG* p);
void prettyTypeINPUT(INPUT* i);
void prettyTypeLVALUE(LVALUE* l);
void prettyTypeFIELDVALUE(FIELDVALUE* f);
void prettyTypeEXP(EXP* e);
void printJustType(TYPE* t);
void printJustSimpleType(SIMPLETYPE* s);

#endif /* !PRETTYTYPE_H */