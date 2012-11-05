#ifndef PRETTYSYMBOL_H
#define PRETTYSYMBOL_H

#include <stdio.h>
#include <string.h>
#include "memory.h"
#include "symbol.h"
#include "tree.h"


FILE* ofile;

void setsymbolofile(FILE *f);
void newline();
void prettySYMBOL(SymbolTable* globalTable);
void writeType(SymbolType* type);

#endif /* !PRETTYSYMBOL_H */