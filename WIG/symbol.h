#ifndef SYMBOL_H
#define SYMBOL_H

#include "tree.h"
#include <stdio.h>
#include <string.h>
#include "memory.h"
/* #include "error.h" */
#include "symbol.h"

extern SymbolTable* globalTable;
extern int symbolError;

int Hash(char *str);
SYMBOL *getSymbol(char *id, SymbolTable *t);
SYMBOL *addSymbol(char *id, SymbolTable *t);
SymbolTable *initSymbolTable();
SymbolTable *addTable(SymbolTable* up);
void symbolSERVICE(SERVICE* s);
/* void symbolGetHTML(HTML* h, SymbolTable* table); */
/* void symbolGetHTMLBODY(HTMLBODY* h, SymbolTable* gapTable, SymbolTable* inputTable); */
/* void symbolGetINPUTATTR(INPUTATTR* i, SymbolTable* table); */
/* void symbolGetATTRname(ATTR* a, SymbolTable* table); */
void symbolGetSCHEMA(SCHEMA* s, SymbolTable* table);
/* void symbolGetFIELD(FIELD* f, SymbolTable* table); */
/* void symbolGetVARIABLE(VARIABLE* v, SymbolTable* table); */
/* void symbolGetTYPEset(TYPE* t, SYMBOL* symbol); */
/* void symbolGetSIMPLETYPEset(SIMPLETYPE* s, SYMBOL* symbol); */
void symbolGetFUNCTION(FUNCTION* f, SymbolTable* table);
/* void symbolGetARGUMENT(ARGUMENT* a, SymbolTable* table); */
void symbolGetSESSION(SESSION* s, SymbolTable* table);
void symbolGetSTM(STM* s, SymbolTable* table);
void symbolGetCOMPOUNDSTM(COMPOUNDSTM* c);
void symbolGetDOCUMENT(DOCUMENT* d, RECEIVE* r, SymbolTable* table);
void symbolGetRECEIVE(RECEIVE* r, SymbolTable* table, SymbolTable* inputTable);
void symbolGetFIELDVALUE(FIELDVALUE* f, SymbolTable* table);
void symbolGetPLUG(PLUG* p, SymbolTable* table, SymbolTable* gapTable);
void symbolGetINPUT(INPUT* i, SymbolTable* table, SymbolTable* inputTable);
void symbolGetLVALUE(LVALUE* l, SymbolTable* table);
void symbolGetEXP(EXP* e, SymbolTable* table);
void symbolGetIDchain(ID* i, SymbolTable* table);

void symbolAddHTML(HTML* h, SymbolTable* table);
void symbolAddHTMLBODY(HTMLBODY* h, SymbolTable* gapTable, SymbolTable* inputTable);
void symbolAddINPUTATTR(INPUTATTR* i, SymbolTable* table);
void symbolAddATTRname(ATTR* a, SymbolTable* table);
void symbolAddSCHEMA(SCHEMA* s, SymbolTable* table);
void symbolAddFIELD(FIELD* f, SymbolTable* table);
void symbolAddVARIABLE(VARIABLE* v, SymbolTable* table);
void symbolAddTYPEset(TYPE* t, SYMBOL* symbol, SymbolTable* table);
void symbolAddSIMPLETYPEset(SIMPLETYPE* s, SYMBOL* symbol);
void symbolAddFUNCTION(FUNCTION* f, SymbolTable* table);
void symbolAddARGUMENT(ARGUMENT* a, SymbolTable* table);
void symbolAddSESSION(SESSION* s, SymbolTable* table);
void symbolAddSTM(STM* s, SymbolTable* table);
void symbolAddCOMPOUNDSTM(COMPOUNDSTM* c, SymbolTable* table);
void symbolAddIDchain(ID* i, SymbolTable* table, TYPE* type);

#endif /* !SYMBOL_H */