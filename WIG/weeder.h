#ifndef WEEDER_H
#define WEEDER_H

#include "tree.h"

void weedSERVICE(SERVICE* s);
void weedHTML(HTML* h);
void weedHTMLBODY(HTMLBODY* h);
void weedINPUTATTR(INPUTATTR* i);
void weedATTRIBUTE(ATTRIBUTE* a);
void weedATTR(ATTR* a);
void weedSCHEMA(SCHEMA* s);
void weedFIELD(FIELD* f);
void weedVARIABLE(VARIABLE* v);
void weedID(ID* i);
void weedTYPE(TYPE* t);
void weedSIMPLETYPE(SIMPLETYPE* s);
void weedFUNCTION(FUNCTION* f);
void weedARGUMENT(ARGUMENT* a);
void weedSESSION(SESSION* s);
void weedSTM(STM* s);
void weedCOMPOUNDSTM(COMPOUNDSTM* c);
void weedDOCUMENT(DOCUMENT* d);
void weedRECEIVE(RECEIVE* r);
void weedPLUG(PLUG* p);
void weedINPUT(INPUT* i);
void weedLVALUE(LVALUE* l);
void weedFIELDVALUE(FIELDVALUE* f);
void weedEXP(EXP* e);
int hasShowSTM(STM* s);
int hasExitSTM(STM* s);


#endif /* !WEEDER_H */