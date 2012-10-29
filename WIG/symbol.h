#ifndef SYMBOL_H
#define SYMBOL_H

#define HashSize 250

#include "tree.h"
#include <stdio.h>
#include <string.h>
#include "memory.h"
#include "error.h"
#include "symbol.h"

extern SymbolTable* globalTable;
extern int symbolError;




int Hash(char *str);
SYMBOL *getSymbol(char *id, SymbolTable *t);
SYMBOL *addSymbol(char *id, SymbolTable *t);
SymbolTable *initSymbolTable();
SymbolTable *addTable(SymbolTable* up);
void symbolSERVICE(SERVICE* s);
void symbolHTML(HTML* h, SymbolTable* table);
void symbolHTMLBODY(HTMLBODY* h, SymbolTable* gapTable, SymbolTable* inputTable);
void symbolINPUTATTR(INPUTATTR* i, SymbolTable* table);
void symbolATTRname(ATTR* a, SymbolTable* table);
void symbolSCHEMA(SCHEMA* s, SymbolTable* table);
void symbolFIELD(FIELD* f, SymbolTable* table);
void symbolVARIABLE(VARIABLE* v, SymbolTable* table);
void symbolTYPEset(TYPE* t, SYMBOL* symbol);
void symbolSIMPLETYPEset(SIMPLETYPE* s, SYMBOL* symbol);
void symbolFUNCTION(FUNCTION* f, SymbolTable* table);
void symbolARGUMENT(ARGUMENT* a, SymbolTable* table);
void symbolSESSION(SESSION* s, SymbolTable* table);
void symbolSTM(STM* s, SymbolTable* table);
void symbolCOMPOUNDSTM(COMPOUNDSTM* c, SymbolTable* table);
void symbolDOCUMENT(DOCUMENT* d, SymbolTable* table);
void symbolRECEIVE(RECEIVE* r, SymbolTable* table, SymbolTable* inputTable);
void symbolPLUG(PLUG* p, SymbolTable* table, SymbolTable* gapTable);
void symbolINPUT(INPUT* i, SymbolTable* table, SymbolTable* inputTable);
void symbolLVALUE(LVALUE* l, SymbolTable* table);
void symbolFIELDVALUE(FIELDVALUE* f, SymbolTable* table);
void symbolEXP(EXP* e, SymbolTable* table);
void symbolIDchainget(ID* i, SymbolTable* table);
void symbolIDchainadd(ID* i, SymbolTable* table, TYPE* type);

#endif /* !SYMBOL_H */