#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "error.h"
#include "symbol.h"

extern SymbolTable* globalTable;
extern int symbolError;

int Hash(char *str)
{ unsigned int hash = 0;
  while (*str) hash = (hash << 1) + *str++; 
  return hash % HashSize;
}

SYMBOL *getSymbol(char *id, SymbolTable *t)
{ int i = Hash(id);
  SYMBOL *s;
  for (s = t->table[i]; s; s = s->up) {
	  if (strcmp(s->id,id)==0) return s;
  }
  if (t->up==NULL) return NULL;
  return getSymbol(id, t->up);
}

SYMBOL *addSymbol(char *id, SymbolTable *t)
{
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
	SYMBOL* symbol;
	symbol = NEW(SYMBOL);
	symbol->id = id;
	symbol->up = NULL;
	
	if (entry != NULL)
		entry->up = symbol;
	else
		t->table[hashValue] = symbol;
	return symbol;
}

SymbolTable *initSymbolTable()
{ SymbolTable *t;
  int i;
  t = NEW(SymbolTable);
  for (i=0; i < HashSize; i++) t->table[i] = NULL;
  t->up = NULL;
  return t;
}

SymbolTable *addTable(SymbolTable* up)
{
	SymbolTable *newTable;
	newTable = initSymbolTable();
	newTable->up = up;
	return newTable;
}

void symbolSERVICE(SERVICE* s)
{
	globalTable = initSymbolTable();
	symbolError = 0;
	symbolHTML(s->html, globalTable);
	symbolSCHEMA(s->schema, globalTable);
	symbolFUNCTION(s->function, globalTable);
	symbolSESSION(s->session, globalTable);
	/* do something with errors maybe */
}

void symbolHTML(HTML* h, SymbolTable* table)
{
	if (h == NULL) return;
	if (h->next != NULL)
		symbolHTML(h->next, table);
	SYMBOL *symbol = addSymbol(h->identifier->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", h->identifier->lineno, h->identifier->identifier);
		symbolError = 1;
		return;
	}
	/* could be error here */
	symbol->type->kind = htmlK;
	symbol->val.htmlS = h;
	SymbolTable *gapTable = addTable(table);
	SymbolTable *inputTable = addTable(table);
	h->gapTable = gapTable;
	h->inputTable = inputTable;
	symbolHTMLBODY(h->body, gapTable, inputTable);
}

void symbolHTMLBODY(HTMLBODY* h, SymbolTable* gapTable, SymbolTable* inputTable)
{
	SYMBOL* symbol; 
	if (h == NULL) return;
	if (h->next != NULL)
		symbolHTMLBODY(h->next, gapTable, inputTable);
	switch (h->kind) {
		case tagK:
		case whateverK:
		case metaK:
			break;
		case gapK:
			symbol = addSymbol(h->val.id->identifier, gapTable);
			if(symbol == NULL)
			{
				printf("%d: Gap symbol '%s' already defined", h->val.id->lineno, h->val.id->identifier);
				symbolError = 1;
				return;
			}
			symbol->type->kind = gapK;
			symbol->val.gapS = h;
			break;
		case inputK:
			symbolINPUTATTR(h->val.inputattr, inputTable);
			break;
		case selectK:
			symbolINPUTATTR(h->val.selectE.inputattr, inputTable);
			symbolHTMLBODY(h->val.selectE.body, gapTable, inputTable);
			break;
	}

}

void symbolINPUTATTR(INPUTATTR* i, SymbolTable* table)
{
	if(i == NULL) return;
	if(i->next != NULL)
		symbolINPUTATTR(i->next, table);
	switch(i->kind) {
		case nameK:
			symbolATTRname(i->val.attr, table);
			break;
		case textK:
			break;
		case radioK:
			break;
		case otherK:
			break;
	}
}

void symbolATTRname(ATTR* a, SymbolTable* table)
{
	char* id;
	int len;
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
	SYMBOL *symbol = addSymbol(id, table);
	symbol->type->kind = stringK;
	symbol->val.attrnameS = a;
	/* allowed to have duplicates */
}


void symbolSCHEMA(SCHEMA* s, SymbolTable* table)
{
	if(s == NULL) return;
	if(s->next != NULL)
		symbolSCHEMA(s->next, table);

	SYMBOL *symbol = addSymbol(s->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", s->id->lineno, s->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->type->kind = schemaK;
	symbol->val.schemaS = s;
	SymbolTable *sTable = addTable(table);
	s->tupleTable = sTable;
	symbolFIELD(s->field, sTable);
}

void symbolFIELD(FIELD* f, SymbolTable* table)
{
	if(f == NULL) return;
	if(f->next != NULL)
		symbolFIELD(f->next, table);
	SYMBOL *symbol = addSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.fieldS = f;
	symbolSIMPLETYPEset(f->simpletype, symbol);
}

void symbolVARIABLE(VARIABLE* v, SymbolTable* table)
{
	if(v == NULL) return;
	if(v->next != NULL)
		symbolVARIABLE(v->next, table);	
	symbolIDchainadd(v->id, table, v->type);
}

void symbolTYPEset(TYPE* t, SYMBOL* symbol)
{
	if(t == NULL) return;
	switch (t->kind) {
		case simpletypeK:
			symbolSIMPLETYPEset(t->val.simpletype, symbol);
			break;
		case tupleidK:
			symbol->type->tupleName = t->val.id->identifier;
			break;
	}
}

void symbolSIMPLETYPEset(SIMPLETYPE* s, SYMBOL* symbol)
{
	if(s == NULL) return;
	switch (s->kind) {
		case intK:
			symbol->type->kind = intK;
			break;
		case boolK:
			symbol->type->kind = boolK;
			break;
		case stringK:
			symbol->type->kind = stringK;
			break;
		case voidK:
			symbol->type->kind = voidK;
			break;
	}
}

void symbolFUNCTION(FUNCTION* f, SymbolTable* table)
{
	if(f == NULL) return;
	if(f->next != NULL)
		symbolFUNCTION(f->next, table);

	SYMBOL *symbol = addSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.functionS = f;
	symbolTYPEset(f->type, symbol);
	symbol->type->function = 1;
	SymbolTable *fTable = addTable(table);
	symbolARGUMENT(f->argument, fTable);
	symbolCOMPOUNDSTM(f->compoundstm, fTable);
}

void symbolARGUMENT(ARGUMENT* a, SymbolTable* table)
{
	if(a == NULL) return;
	if(a->next != NULL)
		symbolARGUMENT(a->next, table);
	SYMBOL *symbol = addSymbol(a->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", a->id->lineno, a->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.argumentS = a;
	symbolTYPEset(a->type, symbol);
}

void symbolSESSION(SESSION* s, SymbolTable* table)
{
	if(s == NULL) return;
	if(s->next != NULL)
		symbolSESSION(s->next, table);
	SYMBOL *symbol = addSymbol(s->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined", s->id->lineno, s->id->identifier);
		symbolError = 1;
		return;
	}
	symbol->val.sessionS = s;
	SymbolTable *cTable = addTable(table);
	symbolCOMPOUNDSTM(s->compoundstm, cTable);
}

void symbolSTM(STM* s, SymbolTable* table)
{
	SymbolTable* cTable;
	if(s == NULL) return;
	if(s->next != NULL)
		symbolSTM(s->next, table);
	switch(s->kind) {
		case semicolonK:
			break;
		case showK:
			symbolDOCUMENT(s->val.showE.doc, s->val.showE.rec, table);
			break;
		case exitK:
			symbolDOCUMENT(s->val.doc, NULL, table);
			break;
		case returnK:
			break;
		case returnexprK:
			symbolEXP(s->val.expr, table);
			break;
		case ifK:
			symbolEXP(s->val.ifE.expr, table);
			symbolSTM(s->val.ifE.stm, table);
			break;
		case ifelseK:
			symbolEXP(s->val.ifelseE.expr, table);
			symbolSTM(s->val.ifelseE.stm1, table);

			symbolSTM(s->val.ifelseE.stm2,table);
			break;
		case whileK:
			symbolEXP(s->val.whileE.expr, table);
			symbolSTM(s->val.whileE.stm, table);
			break;
		case compoundK:
			cTable = addTable(table);
			symbolCOMPOUNDSTM(s->val.compoundstm, cTable);
			break;
		case exprK:
			symbolEXP(s->val.expr, table);
			break;
	}
}

/* Usually we open a new scope before doing this.
   Usually.
   So we can't do it in here, so do it when you call it. */
void symbolCOMPOUNDSTM(COMPOUNDSTM* c, SymbolTable* table)
{
	if(c == NULL) return;
	symbolVARIABLE(c->variable, table);
	symbolSTM(c->stm, table);
}

void symbolDOCUMENT(DOCUMENT* d, RECEIVE* r, SymbolTable* table)
{
	HTML* html;
	SYMBOL* symbol;
	if(d == NULL) return;
	switch(d->kind) {
		case idK:
			symbol = getSymbol(d->val.id->identifier, globalTable);
			if(symbol == NULL)
			{
				printf("%d: Symbol '%s' not defined.\n", d->lineno, d->val.id->identifier);
				symbolError = 1;
				return;
			}
			html = symbol->val.htmlS;
			break;
		case plugK:
			symbol = getSymbol(d->val.plugE.id->identifier, globalTable);
			if(symbol == NULL)
			{
				printf("%d: Symbol '%s' not defined.\n", d->lineno, d->val.plugE.id->identifier);
				symbolError = 1;
				return;
			}
			html = symbol->val.htmlS;
			symbolPLUG(d->val.plugE.plug, table, html->gapTable);
			break;
	}
	symbolRECEIVE(r, table, html->inputTable);
}

void symbolRECEIVE(RECEIVE* r, SymbolTable* table, SymbolTable* inputTable)
{
	if(r == NULL) return;
	if(r->input != NULL)
		symbolINPUT(r->input, table, inputTable);
}


void symbolPLUG(PLUG* p, SymbolTable* table, SymbolTable* gapTable)
{
	if(p == NULL) return;
	if(p->next != NULL)
		symbolPLUG(p->next, table, gapTable);
	/* left gaps, right local */
	SYMBOL* symbol = getSymbol(p->id->identifier, gapTable);
	if(symbol == NULL)
	{
		printf("%d: Gap symbol '%s' not defined in html.\n", p->id->lineno, p->id->identifier);
		symbolError = 1;
		return;
	}
	symbolEXP(p->expr, table);
}

void symbolINPUT(INPUT* i, SymbolTable* table, SymbolTable* inputTable)
{
	if(i == NULL) return;
	if(i->next)
		symbolINPUT(i->next, table, inputTable);
	symbolLVALUE(i->lvalue, table);
	SYMBOL* symbol = getSymbol(i->id->identifier, inputTable);
	if(symbol == NULL)
	{
		printf("%d: Input symbol '%s' not defined in html.\n", i->id->lineno, i->id->identifier);
		symbolError = 1;
		return;
	}
}

void symbolLVALUE(LVALUE* l, SymbolTable* table)
{
	if(l == NULL) return;
	if(l->id2 == NULL)  /* identifier */
	{
		SYMBOL* symbol = getSymbol(l->id1->identifier, table);
		if(symbol == NULL)
		{
			printf("%d: Symbol '%s' not defined.\n", l->id1->lineno, l->id1->identifier);
			symbolError = 1;
			return;
		}
	}
	else  /* identifier.identifier */
	{
		SYMBOL* symbol = getSymbol(l->id1->identifier, table);
		if(symbol == NULL)
		{
			printf("%d: Tuple symbol '%s' not defined.\n", l->id1->lineno, l->id1->identifier);
			symbolError = 1;
			return;
		}
		SymbolTable* tupleTable = symbol->val.schemaS->tupleTable;
		symbol = getSymbol(l->id2->identifier, tupleTable);
		if(symbol == NULL)
		{
			printf("%d: Tuple symbol '%s' not defined.\n", l->id2->lineno, l->id2->identifier);
			symbolError = 1;
			return;
		}
	}
}

void symbolFIELDVALUE(FIELDVALUE* f, SymbolTable* table)
{
	if(f == NULL) return;
	if(f->next != NULL)
		symbolFIELDVALUE(f->next, table);
	/* SYMBOL* symbol = getSymbol(f->id->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' not defined.\n", f->id->lineno, f->id->identifier);
		symbolError = 1;
		return;
	} */
	/* TODO: Get the right scope */
	symbolEXP(f->expr, table);
}

void symbolEXP(EXP* e, SymbolTable* table)
{
	SYMBOL* symbol;
	if(e == NULL) return;
	if(e->next != NULL)
		symbolEXP(e->next, table);
	switch(e->kind)
	{
		case lvalueK:
			symbolLVALUE(e->val.lvalueE, table);
			break;
		case assignK:
			symbolLVALUE(e->val.assignE.lvalue, table);
			symbolEXP(e->val.assignE.expr, table);
			break;
		case equalsK:
			symbolEXP(e->val.equalsE.left, table);
			symbolEXP(e->val.equalsE.right, table);
			break;
		case notequalsK:
			symbolEXP(e->val.notequalsE.left, table);
			symbolEXP(e->val.notequalsE.right, table);
			break;
		case ltK:
			symbolEXP(e->val.ltE.left, table);
			symbolEXP(e->val.ltE.right, table);
			break;
		case gtK:
			symbolEXP(e->val.gtE.left, table);
			symbolEXP(e->val.gtE.right, table);
			break;
		case lteK:
			symbolEXP(e->val.lteE.left, table);
			symbolEXP(e->val.lteE.right, table);
			break;
		case gteK:
			symbolEXP(e->val.gteE.left, table);
			symbolEXP(e->val.gteE.right, table);
			break;
		case notK:
			symbolEXP(e->val.exprE, table);
			break;
		case plusK:
			symbolEXP(e->val.plusE.left, table);
			symbolEXP(e->val.plusE.right, table);
			break;
		case minusK:
			symbolEXP(e->val.minusE.left, table);
			symbolEXP(e->val.minusE.right, table);
			break;
		case multK:
			symbolEXP(e->val.multE.left, table);
			symbolEXP(e->val.multE.right, table);
			break;
		case divK:
			symbolEXP(e->val.divE.left, table);
			symbolEXP(e->val.divE.right, table);
			break;
		case modK:
			symbolEXP(e->val.modE.left, table);
			symbolEXP(e->val.modE.right, table);
			break;
		case andK:
			symbolEXP(e->val.andE.left, table);
			symbolEXP(e->val.andE.right, table);
			break;
		case orK:
			symbolEXP(e->val.orE.left, table);
			symbolEXP(e->val.orE.right, table);
			break;
		case joinK:
			symbolEXP(e->val.joinE.left, table);
			symbolEXP(e->val.joinE.right, table);
			break;
		case keepK:
			symbolEXP(e->val.keepE.left, table);
			symbolIDchainget(e->val.keepE.right, table);
			break;
		case removeK:
			symbolEXP(e->val.removeE.left, table);
			symbolIDchainget(e->val.removeE.right, table);
			break;
		case callK:
			symbol = getSymbol(e->val.callE.left->identifier, table);
			if(symbol == NULL)
			{
				printf("%d: Symbol '%s' not defined.\n", e->val.callE.left->lineno, e->val.callE.left->identifier);
				symbolError = 1;
				return;
			}
			symbolEXP(e->val.callE.right, table);
			break;
		case tupleK:
			symbolFIELDVALUE(e->val.tupleE, table);
			break;
		case parenK:
			symbolEXP(e->val.exprE, table);
			break;
		case intconstK:
		case trueK:
		case falseK:
		case stringconstK:
			break;
	}

}

void symbolIDchainget(ID* i, SymbolTable* table)
{
	if(i == NULL) return;
	if(i->next != NULL)
		symbolIDchainget(i->next, table);
	SYMBOL* symbol = getSymbol(i->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' not defined.\n", i->lineno, i->identifier);
		symbolError = 1;
		return;
	}	

}

void symbolIDchainadd(ID* i, SymbolTable* table, TYPE* type)
{
	if(i == NULL) return;
	if(i->next != NULL)
		symbolIDchainadd(i->next, table, type);
	SYMBOL* symbol = addSymbol(i->identifier, table);
	if(symbol == NULL)
	{
		printf("%d: Symbol '%s' already defined.\n", i->lineno, i->identifier);
		symbolError = 1;
		return;
	}	
	symbolTYPEset(type, symbol);
}
