/*
 * We used the Hash, getSymbol, and addSymbol methods from JOOS (with some 
 * modifications) so this notice is included.
 *
 * JOOS is Copyright (C) 1997 Laurie Hendren & Michael I. Schwartzbach
 *
 * Reproduction of all or part of this software is permitted for
 * educational or research use on condition that this copyright notice is
 * included in any copy. This software comes with no warranty of any
 * kind. In no event will the authors be liable for any damages resulting from
 * use of this software.
 *
 * email: hendren@cs.mcgill.ca, mis@brics.dk
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "error.h"
#include "symbol.h"

extern SymbolTable* globalTable;
extern int symbolError;

int Hash(char *str)
{ 
	unsigned int hash = 0;
	while (*str) hash = (hash << 1) + *str++; 
	return hash % HashSize;
}

SYMBOL *getSymbol(char *id, SymbolTable *t)
{ 
	int i = Hash(id);
	SYMBOL *s;
	for (s = t->table[i]; s; s = s->up) 
	{
		if (strcmp(s->id,id)==0) return s;
	}
	if (t->up==NULL) return NULL;
	return getSymbol(id, t->up);
}

SYMBOL *addSymbol(char *id, SymbolTable *t)
{
	SYMBOL* symbol;
	int hashValue = Hash(id);
	SYMBOL* entry = t->table[hashValue];
	/* make sure not already in hashtable */	
	while(entry != NULL)
	{
		if (strcmp(entry->id,id) == 0)
			return NULL;
		
		if(entry->up == NULL)
			break;
		entry = entry->up;
	}
	/* not there, continue as planned */
	
	symbol = NEW(SYMBOL);
	symbol->id = id;
	symbol->up = NULL;
	symbol->type = NEW(SymbolType);
	
	if (entry != NULL)
		entry->up = symbol;
	else
		t->table[hashValue] = symbol;

	if(t->first == NULL)
		t->first = symbol;
	else
	{	
		SYMBOL* temp;
		temp = t->first;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = symbol;
	}
	return symbol;
}

SymbolTable *initSymbolTable()
{ 
	SymbolTable *t;
	int i;
	t = NEW(SymbolTable);
	for (i=0; i < HashSize; i++) t->table[i] = NULL;
	t->up = NULL;
	t->next = NULL;
	t->indent = 0;
	return t;
}

SymbolTable *addTable(SymbolTable* up)
{
	SymbolTable *newTable;
	SymbolTable *lastTable = globalTable;
	newTable = initSymbolTable();
	newTable->up = up;
	newTable->indent = up->indent + 1;
	while(lastTable->next != NULL)
		lastTable = lastTable->next;
	lastTable->next = newTable;
	return newTable;
}

void symbolSERVICE(SERVICE* s)
{
	globalTable = initSymbolTable();
	symbolError = 0;
	symbolAddHTML(s->html, globalTable);
	symbolAddSCHEMA(s->schema, globalTable);
	symbolAddVARIABLE(s->variable, globalTable);	
	symbolAddFUNCTION(s->function, globalTable);
	symbolAddSESSION(s->session, globalTable);

	if(!symbolError)
	{
		/* symbolGetHTML(s->html, globalTable); */
		/* symbolGetSCHEMA(s->schema, globalTable); */
		/* symbolGetVARIABLE(s->variable, globalTable); */
		symbolGetFUNCTION(s->function, globalTable);
		symbolGetSESSION(s->session, globalTable);
	}
}

/* ==============================================
                     GETS
   ============================================== */

void symbolGetFUNCTION(FUNCTION* f, SymbolTable* table)
{
	if(f == NULL) return;
	if(f->next != NULL)
		symbolGetFUNCTION(f->next, table);

	/*symbol = addSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Function symbol '%s' already defined\n", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.functionS = f;
	symbolAddTYPEset(f->type, symbol);
	symbol->type->function = 1;
	fTable = addTable(table);*/
	/* TODO: Miracles */
	/* symbolGetARGUMENT(f->argument, fTable); */
	symbolGetCOMPOUNDSTM(f->compoundstm);
}

void symbolGetSESSION(SESSION* s, SymbolTable* table)
{
	if(s == NULL) return;
	if(s->next != NULL)
		symbolGetSESSION(s->next, table);
	symbolGetCOMPOUNDSTM(s->compoundstm);
}

void symbolGetSTM(STM* s, SymbolTable* table)
{
	if(s == NULL) return;
	if(s->next != NULL)
		symbolGetSTM(s->next, table);
	switch(s->kind) {
		case semicolonK:
			break;
		case showK:
			symbolGetDOCUMENT(s->val.showE.doc, s->val.showE.rec, table);
			break;
		case exitK:
			symbolGetDOCUMENT(s->val.doc, NULL, table);
			break;
		case returnK:
			break;
		case returnexprK:
			symbolGetEXP(s->val.expr, table);
			break;
		case ifK:
			symbolGetEXP(s->val.ifE.expr, table);
			symbolGetSTM(s->val.ifE.stm, table);
			break;
		case ifelseK:
			symbolGetEXP(s->val.ifelseE.expr, table);
			symbolGetSTM(s->val.ifelseE.stm1, table);

			symbolGetSTM(s->val.ifelseE.stm2, table);
			break;
		case whileK:
			symbolGetEXP(s->val.whileE.expr, table);
			symbolGetSTM(s->val.whileE.stm, table);
			break;
		case compoundK:
			symbolGetCOMPOUNDSTM(s->val.compoundstm);
			break;
		case exprK:
			symbolGetEXP(s->val.expr, table);
			break;
	}
}

/* Usually we open a new scope before doing this.
   Usually.
   So we can't do it in here, so do it when you call it. */
void symbolGetCOMPOUNDSTM(COMPOUNDSTM* c)
{
	if(c == NULL) return;
	/* Don't need to do variables: no gets */
	symbolGetSTM(c->stm, c->cTable);
}

void symbolGetDOCUMENT(DOCUMENT* d, RECEIVE* r, SymbolTable* table)
{
	HTML* html;
	SYMBOL* symbol;
	if(d == NULL) return;
	switch(d->kind) {
		case idK:
			symbol = getSymbol(d->val.id->identifier, globalTable);
			if(symbol == NULL)
			{
				printf("%d: HTML symbol '%s' not defined.\n", d->lineno, d->val.id->identifier);
				symbolError = 1;
				return;
			}
			if(symbol->type->kind != htmlSK)
			{
				printf("%d: Symbol '%s' must be of type HTML.\n", d->lineno, d->val.id->identifier);
				symbolError = 1;
				return;
			}
			html = symbol->val.htmlS;
			d->val.id->symbol = symbol;
			break;
		case plugK:
			symbol = getSymbol(d->val.plugE.id->identifier, globalTable);
			if(symbol == NULL)
			{
				printf("%d: Plug symbol '%s' not defined.\n", d->lineno, d->val.plugE.id->identifier);
				symbolError = 1;
				return;
			}
			html = symbol->val.htmlS;
			d->val.plugE.id->symbol = symbol;
			symbolGetPLUG(d->val.plugE.plug, table, html->gapTable);
			break;
	}
	symbolGetRECEIVE(r, table, html->inputTable);
}

void symbolGetRECEIVE(RECEIVE* r, SymbolTable* table, SymbolTable* inputTable)
{
	if(r == NULL) return;
	if(r->input != NULL)
		symbolGetINPUT(r->input, table, inputTable);
}

void symbolGetFIELDVALUE(FIELDVALUE* f, SymbolTable* table)
{
	if(f == NULL) return;
	if(f->next != NULL)
		symbolGetFIELDVALUE(f->next, table);
	/* TODO: Get the right scope */
	symbolGetEXP(f->expr, table);
}


void symbolGetPLUG(PLUG* p, SymbolTable* table, SymbolTable* gapTable)
{
	SYMBOL* symbol;
	if(p == NULL) return;
	if(p->next != NULL)
		symbolGetPLUG(p->next, table, gapTable);
	/* left gaps, right local */
	symbol = getSymbol(p->id->identifier, gapTable);
	if(symbol == NULL)
	{
		printf("%d: Gap symbol '%s' not defined in html.\n", p->id->lineno, p->id->identifier);
		symbolError = 1;
		return;
	}
	symbolGetEXP(p->expr, table);
}

void symbolGetINPUT(INPUT* i, SymbolTable* table, SymbolTable* inputTable)
{
	SYMBOL* symbol;
	if(i == NULL) return;
	if(i->next)
		symbolGetINPUT(i->next, table, inputTable);
	symbolGetLVALUE(i->lvalue, table);
	symbol = getSymbol(i->id->identifier, inputTable);
	if(symbol == NULL)
	{
		printf("%d: Input symbol '%s' not defined in html.\n", i->id->lineno, i->id->identifier);
		symbolError = 1;
		return;
	}
}

void symbolGetLVALUE(LVALUE* l, SymbolTable* table)
{
	SYMBOL* symbol;
	SYMBOL* symbol2;
	SYMBOL* symbol3;
	SymbolTable* tupleTable;
	if(l == NULL) return;
	if(l->id2 == NULL)  /* identifier */
	{
		symbol = getSymbol(l->id1->identifier, table);
		if(symbol == NULL)
		{
			printf("%d: LVALUE symbol '%s' not defined.\n", l->id1->lineno, l->id1->identifier);
			symbolError = 1;
			return;
		}
		l->id1->symbol = symbol;	/* for type checking */ 
		if(symbol->type->kind == tupleSK)
		{
			symbol3 = getSymbol(symbol->type->tupleName, table);
			if(symbol3 != NULL)
			{
				l->id1->symbol->type->schema = symbol3->val.schemaS;
			}
		}
	}
	else  /* identifier.identifier */
	{
		symbol = getSymbol(l->id1->identifier, table);
		if(symbol == NULL)
		{
			printf("%d: Tuple symbol '%s' not defined.\n", l->id1->lineno, l->id1->identifier);
			symbolError = 1;
			return;
		}
		if(symbol->type->kind != tupleSK)
		{
			printf("%d: Symbol '%s' is not a tuple.\n", l->id1->lineno, l->id1->identifier);
			symbolError = 1;
			return;
		}
		symbol3 = getSymbol(symbol->type->tupleName, globalTable);  /* the schema */
		tupleTable = symbol3->val.schemaS->tupleTable;
		symbol2 = getSymbol(l->id2->identifier, tupleTable);
		if(symbol2 == NULL)
		{
			printf("%d: Symbol '%s' not in schema '%s'.\n", l->id2->lineno, l->id2->identifier, symbol->type->tupleName);
			symbolError = 1;
			return;
		}
		l->id2->symbol = symbol2;	/* for type checking */
	}
}

void symbolGetEXP(EXP* e, SymbolTable* table)
{
	SYMBOL* symbol;
	if(e == NULL) return;
	if(e->next != NULL)
		symbolGetEXP(e->next, table);
	switch(e->kind)
	{
		case lvalueK:
			symbolGetLVALUE(e->val.lvalueE, table);
			break;
		case assignK:
			symbolGetLVALUE(e->val.assignE.lvalue, table);
			symbolGetEXP(e->val.assignE.expr, table);
			break;
		case equalsK:
			symbolGetEXP(e->val.equalsE.left, table);
			symbolGetEXP(e->val.equalsE.right, table);
			break;
		case notequalsK:
			symbolGetEXP(e->val.notequalsE.left, table);
			symbolGetEXP(e->val.notequalsE.right, table);
			break;
		case ltK:
			symbolGetEXP(e->val.ltE.left, table);
			symbolGetEXP(e->val.ltE.right, table);
			break;
		case gtK:
			symbolGetEXP(e->val.gtE.left, table);
			symbolGetEXP(e->val.gtE.right, table);
			break;
		case lteK:
			symbolGetEXP(e->val.lteE.left, table);
			symbolGetEXP(e->val.lteE.right, table);
			break;
		case gteK:
			symbolGetEXP(e->val.gteE.left, table);
			symbolGetEXP(e->val.gteE.right, table);
			break;
		case notK:
			symbolGetEXP(e->val.exprE, table);
			break;
		case plusK:
			symbolGetEXP(e->val.plusE.left, table);
			symbolGetEXP(e->val.plusE.right, table);
			break;
		case minusK:
			symbolGetEXP(e->val.minusE.left, table);
			symbolGetEXP(e->val.minusE.right, table);
			break;
		case multK:
			symbolGetEXP(e->val.multE.left, table);
			symbolGetEXP(e->val.multE.right, table);
			break;
		case divK:
			symbolGetEXP(e->val.divE.left, table);
			symbolGetEXP(e->val.divE.right, table);
			break;
		case modK:
			symbolGetEXP(e->val.modE.left, table);
			symbolGetEXP(e->val.modE.right, table);
			break;
		case andK:
			symbolGetEXP(e->val.andE.left, table);
			symbolGetEXP(e->val.andE.right, table);
			break;
		case orK:
			symbolGetEXP(e->val.orE.left, table);
			symbolGetEXP(e->val.orE.right, table);
			break;
		case joinK:
			symbolGetEXP(e->val.joinE.left, table);
			symbolGetEXP(e->val.joinE.right, table);
			break;
		case keepK:
			symbolGetEXP(e->val.keepE.left, table);
			symbolGetIDchain(e->val.keepE.right, table);
			break;
		case removeK:
			symbolGetEXP(e->val.removeE.left, table);
			symbolGetIDchain(e->val.removeE.right, table);
			break;
		case callK:
			symbol = getSymbol(e->val.callE.left->identifier, table);
			if(symbol == NULL)
			{
				printf("%d: Function symbol '%s' not defined.\n", e->val.callE.left->lineno, e->val.callE.left->identifier);
				symbolError = 1;
				return;
			}
			e->val.callE.left->symbol = symbol;
			symbolGetEXP(e->val.callE.right, table);
			break;
		case tupleK:
			symbolGetFIELDVALUE(e->val.tupleE, table);
			break;
		case parenK:
			symbolGetEXP(e->val.exprE, table);
			break;
		case intconstK:
		case trueK:
		case falseK:
		case stringconstK:
			break;
	}

}

void symbolGetIDchain(ID* i, SymbolTable* table)
{
}

/* ==============================================
                     ADDS
   ============================================== */

void symbolAddHTML(HTML* h, SymbolTable* table)
{

	SYMBOL *symbol;
	SymbolTable *gapTable;
	SymbolTable *inputTable;
	if (h == NULL) return;
	if (h->next != NULL)
		symbolAddHTML(h->next, table);
	symbol = addSymbol(h->identifier->identifier, table);

	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined\n", h->identifier->lineno, h->identifier->identifier);
		symbolError = 1;
		return;
	}
	symbol->type->kind = htmlSK;
	symbol->val.htmlS = h;
	gapTable = addTable(table);
	inputTable = addTable(table);
	h->gapTable = gapTable;
	h->inputTable = inputTable;
	symbolAddHTMLBODY(h->body, gapTable, inputTable);
}

void symbolAddHTMLBODY(HTMLBODY* h, SymbolTable* gapTable, SymbolTable* inputTable)
{
	SYMBOL* symbol; 
	if (h == NULL) return;
	if (h->next != NULL)
		symbolAddHTMLBODY(h->next, gapTable, inputTable);
	switch (h->kind) {
		case tagK:
		case whateverK:
		case metaK:
			break;
		case gapK:
			symbol = addSymbol(h->val.id->identifier, gapTable);
			if(symbol == NULL)
			{
				printf("%d: Gap symbol '%s' already defined\n", h->val.id->lineno, h->val.id->identifier);
				symbolError = 1;
				return;
			}
			symbol->type->kind = gapSK;
			symbol->val.gapS = h;
			break;
		case inputK:
			symbolAddINPUTATTR(h->val.inputattr, inputTable);
			break;
		case selectK:
			symbolAddINPUTATTR(h->val.selectE.inputattr, inputTable);
			symbolAddHTMLBODY(h->val.selectE.body, gapTable, inputTable);
			break;
	}

}

void symbolAddINPUTATTR(INPUTATTR* i, SymbolTable* table)
{
	if(i == NULL) return;
	if(i->next != NULL)
		symbolAddINPUTATTR(i->next, table);
	switch(i->kind) {
		case nameK:
			symbolAddATTRname(i->val.attr, table);
			break;
		case textK:
			break;
		case radioK:
			break;
		case otherK:
			break;
	}
}

void symbolAddATTRname(ATTR* a, SymbolTable* table)
{
	char* id;
	int len;
	SYMBOL *symbol;
	if(a == NULL) return;
	switch(a->kind) {
		case attridK:
			id = a->val.id->identifier;
			break;
		case attrstringconstK:
			id = a->val.stringconst;
			break;
		case attrintconstK:
			len = snprintf(NULL, 0, "%d", a->val.intconst) + 1;
  			id = malloc(len * sizeof(char));
  			snprintf(id, len, "%d", a->val.intconst);  /* itoa - c sucks */
			break;
	}
	symbol = addSymbol(id, table);
	if(symbol != NULL)
	{
		symbol->type->kind = stringSK;
		symbol->val.attrnameS = a;
	}
	/* allowed to have duplicates */
}


void symbolAddSCHEMA(SCHEMA* s, SymbolTable* table)
{
	SYMBOL *symbol;
	SymbolTable *sTable;
	if(s == NULL) return;
	if(s->next != NULL)
		symbolAddSCHEMA(s->next, table);

	symbol = addSymbol(s->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Schema Symbol '%s' already defined\n", s->id->lineno, s->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->type->kind = schemaSK;
	symbol->val.schemaS = s;
	sTable = addTable(table);
	s->tupleTable = sTable;
	symbolAddFIELD(s->field, sTable);
}

void symbolAddFIELD(FIELD* f, SymbolTable* table)
{
	SYMBOL *symbol;
	if(f == NULL) return;
	if(f->next != NULL)
		symbolAddFIELD(f->next, table);
	symbol = addSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Field symbol '%s' already defined\n", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.fieldS = f;
	symbolAddSIMPLETYPEset(f->simpletype, symbol);
}

void symbolAddVARIABLE(VARIABLE* v, SymbolTable* table)
{
	if(v == NULL) return;
	if(v->next != NULL)
		symbolAddVARIABLE(v->next, table);	
	symbolAddIDchain(v->id, table, v->type);
}

void symbolAddTYPEset(TYPE* t, SYMBOL* symbol, SymbolTable* table)
{
	SYMBOL* schemaSymbol;
	if(t == NULL) return;
	switch (t->kind) {
		case simpletypeK:
			symbolAddSIMPLETYPEset(t->val.simpletype, symbol);
			break;
		case tupleidK:
			schemaSymbol = getSymbol(t->val.id->identifier, table);  /* This is kinda bad, whatever. */
			if(schemaSymbol == NULL)
			{
				printf("%d: Symbol '%s' does not exist.\n", t->val.id->lineno, t->val.id->identifier);
				symbolError = 1;
				return;
			}
			if(schemaSymbol->type->kind != schemaSK)
			{
				printf("%d: Symbol '%s' must be a schema.\n", t->val.id->lineno, t->val.id->identifier);
				symbolError = 1;
				return;
			}
			t->schema = schemaSymbol->val.schemaS;
			symbol->type->tupleName = t->val.id->identifier;
			symbol->type->kind = tupleSK;
			break;
	}
}

void symbolAddSIMPLETYPEset(SIMPLETYPE* s, SYMBOL* symbol)
{
	if(s == NULL) return;
	switch (s->kind) {
		case intK:
			symbol->type->kind = intSK;
			break;
		case boolK:
			symbol->type->kind = boolSK;
			break;
		case stringK:
			symbol->type->kind = stringSK;
			break;
		case voidK:
			symbol->type->kind = voidSK;
			break;
	}
}

void symbolAddFUNCTION(FUNCTION* f, SymbolTable* table)
{
	SYMBOL *symbol;
	SymbolTable *fTable;
	if(f == NULL) return;
	if(f->next != NULL)
		symbolAddFUNCTION(f->next, table);

	symbol = addSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Function symbol '%s' already defined\n", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.functionS = f;
	symbolAddTYPEset(f->type, symbol, table);
	symbol->type->function = 1;
	fTable = addTable(table);
	f->fTable = fTable;  /* A miracle occurs */
	symbolAddARGUMENT(f->argument, fTable);
	symbolAddCOMPOUNDSTM(f->compoundstm, fTable);
}

void symbolAddARGUMENT(ARGUMENT* a, SymbolTable* table)
{
	SYMBOL *symbol;
	if(a == NULL) return;
	if(a->next != NULL)
		symbolAddARGUMENT(a->next, table);
	symbol = addSymbol(a->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Argument symbol '%s' already defined\n", a->id->lineno, a->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.argumentS = a;
	symbolAddTYPEset(a->type, symbol, table);
}

void symbolAddSESSION(SESSION* s, SymbolTable* table)
{
	SYMBOL *symbol;
	if(s == NULL) return;
	if(s->next != NULL)
		symbolAddSESSION(s->next, table);
	symbol = addSymbol(s->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Session symbol '%s' already defined\n", s->id->lineno, s->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.sessionS = s;
	symbol->type->kind = sessionSK;
	/*cTable = addTable(table);
	s->sTable = cTable;*/
	symbolAddCOMPOUNDSTM(s->compoundstm, table);
}

void symbolAddSTM(STM* s, SymbolTable* table)
{
	if(s == NULL) return;
	if(s->next != NULL)
		symbolAddSTM(s->next, table);
	switch(s->kind) {
		case semicolonK:
			break;
		case showK:
			/* Don't need documents */
			break;
		case exitK:
			/* Don't need documents */
			break;
		case returnK:
			break;
		case returnexprK:
			/* Don't need exp */ 
			break;
		case ifK:
			/* Don't need exp */
			symbolAddSTM(s->val.ifE.stm, table);
			break;
		case ifelseK:
			/* Don't need exp */
			symbolAddSTM(s->val.ifelseE.stm1, table);

			symbolAddSTM(s->val.ifelseE.stm2,table);
			break;
		case whileK:
			/* Don't need exp */
			symbolAddSTM(s->val.whileE.stm, table);
			break;
		case compoundK:
			symbolAddCOMPOUNDSTM(s->val.compoundstm, table);
			break;
		case exprK:
			/* Don't need exp */
			break;
	}
}

/* Usually we open a new scope before doing this.
   Usually.
   So we can't do it in here, so do it when you call it. */
void symbolAddCOMPOUNDSTM(COMPOUNDSTM* c, SymbolTable* table)
{
	SymbolTable* cTable;
	if(c == NULL) return;
	cTable = addTable(table);
	c->cTable = cTable;
	symbolAddVARIABLE(c->variable, cTable);
	symbolAddSTM(c->stm, cTable);
}

void symbolAddIDchain(ID* i, SymbolTable* table, TYPE* type)
{
	SYMBOL* symbol;
	if(i == NULL) return;
	if(i->next != NULL)
		symbolAddIDchain(i->next, table, type);
	symbol = addSymbol(i->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined.\n", i->lineno, i->identifier);
		symbolError = 1;
		return;
	}
	symbolAddTYPEset(type, symbol, table);
}
