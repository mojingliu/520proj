#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "symbol.h"


/* 
	In symbol.c, give each LVALUE its symbol
	this is in typeLVALUE,
	we do this so we don't have to pass the SymbolTable tree
	because that doesn't even work, come to think of it.

	Then we can quickly look up exactly what the symbol is, based on the lvalue

	Tuples need to actually keep track of what they have
	Need anonymous tuples for /+ etc

	Functions need to check number of arguments and argument type
*/

void initTypes();
void typeSERVICE(SERVICE* s);
void typeFUNCTION(FUNCTION* f);
void typeSESSION(SESSION* s);
void typeSTM(STM* s);
void typeCOMPOUNDSTM(COMPOUNDSTM* c);
void typeDOCUMENT(DOCUMENT* d);
void typeRECEIVE(RECEIVE* r);
void typeFIELDVALUE(FIELDVALUE* f);
void typePLUG(PLUG* p);
void typeINPUT(INPUT* i);
void typeLVALUE(LVALUE* l);
void typeEXP(EXP* e);
void makeAnonymousTuple(SCHEMA* schema, FIELDVALUE* fieldvalue);
FIELD* dupField(FIELD* f);
SCHEMA* joinTuples(SCHEMA* s1, SCHEMA* s2);
SCHEMA* keepIDs(SCHEMA* schema, ID* id);
SCHEMA* removeIDs(SCHEMA* schema, ID* id);
void typeIDchain(ID* i);
TYPE* getRealType(SymbolType* stype);
int compareTypes(TYPE* t1, TYPE* t2);
int compareSchemas(SCHEMA* s1, SCHEMA* s2);
int subsetFields(FIELD* f1, FIELD* f2);
void typeARGUMENT(ARGUMENT* arg, EXP* expr);
TYPE* makeBool();
TYPE* makeInt();
TYPE* makeVoid();
TYPE* makeString();