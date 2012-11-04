#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"


/* 
	In symbol.c, give each LVALUE its symbol
	this is in typeLVALUE,
	we do this so we don't have to pass the SymbolTable tree
	because that doesn't even work, come to think of it.

	Then we can quickly look up exactly what the symbol is, based on the lvalue

	Tuples need to actually keep track of what they have
	Need anonymous tuples for /+ etc

	Functions need to check number of arguments and argument type




	TODO FOR TOMORROW

	receive
	+tuple ops
	all returns in function must have type of function
		- all returns must be of correct type
		- must be a return in every case
	pretty printing
*/
extern int typeErrors;
TYPE* intType;
TYPE* boolType;
TYPE* stringType;
TYPE* voidType;

void initTypes()
{
	typeErrors = 0;
	intType = makeInt();
	boolType = makeBool();
	stringType = makeString();
	voidType = makeVoid();
}

void typeSERVICE(SERVICE* s)
{
	initTypes();
	printf("  before function\n");
	typeFUNCTION(s->function);
	printf("  after function\n");
	typeSESSION(s->session);
	printf("  after session\n");
}


void typeFUNCTION(FUNCTION* f)
{
	if(f == NULL) return;
	if(f->next != NULL)
		typeFUNCTION(f->next);
	typeCOMPOUNDSTM(f->compoundstm);
}

void typeSESSION(SESSION* s)
{
	if(s == NULL) return;
	if(s->next != NULL)
		typeSESSION(s->next);
	printf("  before compound\n");
	typeCOMPOUNDSTM(s->compoundstm);
	printf("  after compoundstm\n");
}

void typeSTM(STM* s)
{
	printf("  top of stm\n");
	if(s == NULL) return;
	if(s->next != NULL)
		typeSTM(s->next);
	switch(s->kind) {
		case semicolonK:
			break;
		case showK:
			printf("  before document\n");
			typeDOCUMENT(s->val.showE.doc);
			typeRECEIVE(s->val.showE.rec);
			printf("  after document\n");
			break;
		case exitK:
			printf("  before document\n");
			typeDOCUMENT(s->val.doc);
			printf("  after document\n");
			break;
		case returnK:
			break;
		case returnexprK:
			printf("  top of exprk\n");
			typeEXP(s->val.expr);
			break;
		case ifK:
			typeEXP(s->val.ifE.expr);
			typeSTM(s->val.ifE.stm);
			break;
		case ifelseK:
			typeEXP(s->val.ifelseE.expr);
			typeSTM(s->val.ifelseE.stm1);

			typeSTM(s->val.ifelseE.stm2);
			break;
		case whileK:
			typeEXP(s->val.whileE.expr);
			typeSTM(s->val.whileE.stm);
			break;
		case compoundK:
			typeCOMPOUNDSTM(s->val.compoundstm);
			break;
		case exprK:
			printf("  before exp\n");
			typeEXP(s->val.expr);
			printf("  after exp\n");
			break;
	}
}

/* Usually we open a new scope before doing this.
   Usually.
   So we can't do it in here, so do it when you call it. */
void typeCOMPOUNDSTM(COMPOUNDSTM* c)
{
	printf("  top of compoundstm\n");
	if(c == NULL) return;
	/* Don't need to do variables: no gets */
	typeSTM(c->stm);
}

void typeDOCUMENT(DOCUMENT* d)
{
	if(d == NULL) return;
	switch(d->kind) {
		case idK:	
			if(d->val.id->symbol->type->kind != htmlSK)	
			{
				typeErrors++;
				printf("%d: Type Error: Document type needs to be const html.\n", d->lineno);
			}
			break;
		case plugK:
			if(d->val.plugE.id->symbol->type->kind != htmlSK)	
			{
				typeErrors++;
				printf("%d: Type Error: Document type needs to be const html.\n", d->lineno);
			}
			typePLUG(d->val.plugE.plug);
			break;
	}
}

void typeRECEIVE(RECEIVE* r)
{
	if(r == NULL) return;
	if(r->input != NULL)
		typeINPUT(r->input);
}

void typeFIELDVALUE(FIELDVALUE* f)
{
	printf("  top of fieldvalue\n");
	if(f == NULL) return;
	if(f->next != NULL)
		typeFIELDVALUE(f->next);
	/* TODO: Get the right scope */
	typeEXP(f->expr);
}


void typePLUG(PLUG* p)
{
	if(p == NULL) return;
	if(p->next != NULL)
		typePLUG(p->next);
	/* left gaps, right local */

	typeEXP(p->expr);
}

void typeINPUT(INPUT* i)
{
	if(i == NULL) return;
	if(i->next)
		typeINPUT(i->next);
	typeLVALUE(i->lvalue);

}

void typeLVALUE(LVALUE* l)
{
	printf("  top of lvalue\n");
	if(l == NULL) return;
	if(l->id2 == NULL)  /* identifier */
	{
		l->type = getRealType(l->id1->symbol->type);
	}
	else  /* identifier.identifier */
	{
		l->type = getRealType(l->id2->symbol->type);
	}
}

void typeEXP(EXP* e)
{
	int counter;
	if(e == NULL) return;
	if(e->next != NULL)
		typeEXP(e->next);
	switch(e->kind)
	{
		case lvalueK:
			printf("  before lvalue\n");
			typeLVALUE(e->val.lvalueE);
			printf("  after lvalue\n");
			e->type = e->val.lvalueE->type;
			printf("  after setting type of expr in lvalue\n");
			break;
		case assignK:
			printf("  top of assignk\n");
			typeLVALUE(e->val.assignE.lvalue);
			typeEXP(e->val.assignE.expr);
			printf("  after exp in assign\n");
			if(compareTypes(e->val.assignE.lvalue->type, e->val.assignE.expr->type))
			{
				printf("  after if in assignK\n");
				e->type = e->val.assignE.lvalue->type;
				printf("  after setting type in assignk if statement\n");
			}
			else
			{
				printf("%d: Type Error: Assignment of incompatible types.\n", e->lineno);
				typeErrors++;
			}
			break;
		case equalsK:
			printf("  top of equalsK\n");
			typeEXP(e->val.equalsE.left);
			typeEXP(e->val.equalsE.right);
			if(compareTypes(e->val.equalsE.left->type, e->val.equalsE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}
			break;
		case notequalsK:
			printf("  top of notequalsK\n");
			typeEXP(e->val.notequalsE.left);
			typeEXP(e->val.notequalsE.right);
			if(compareTypes(e->val.notequalsE.left->type, e->val.notequalsE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}
			break;
		case ltK:
			printf("  top of ltk\n");
			typeEXP(e->val.ltE.left);
			typeEXP(e->val.ltE.right);
			if(compareTypes(e->val.ltE.left->type, e->val.ltE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}

			if(!compareTypes(stringType, e->val.ltE.left->type) && !compareTypes(intType, e->val.ltE.left->type))
			{
				printf("%d: Type Error: Comparisons can only be between ints or strings.\n", e->lineno);
				typeErrors++;
			}
			break;
		case gtK:
			printf("  top of gtk\n");
			typeEXP(e->val.gtE.left);
			typeEXP(e->val.gtE.right);
			if(compareTypes(e->val.gtE.left->type, e->val.gtE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}

			if(!compareTypes(stringType, e->val.gtE.left->type) && !compareTypes(intType, e->val.gtE.left->type))
			{
				printf("%d: Type Error: Comparisons can only be between ints or strings.\n", e->lineno);
				typeErrors++;
			}
			break;
		case lteK:
			printf("  top of lteK\n");
			typeEXP(e->val.lteE.left);
			typeEXP(e->val.lteE.right);
			if(compareTypes(e->val.lteE.left->type, e->val.lteE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}

			if(!compareTypes(stringType, e->val.lteE.left->type) && !compareTypes(intType, e->val.lteE.left->type))
			{
				printf("%d: Type Error: Comparisons can only be between ints or strings.\n", e->lineno);
				typeErrors++;
			}

			break;
		case gteK:
			printf("  top of gteK\n");
			typeEXP(e->val.gteE.left);
			typeEXP(e->val.gteE.right);
			if(compareTypes(e->val.gteE.left->type, e->val.gteE.right->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Comparing incompatible types.\n", e->lineno);
				typeErrors++;
			}

			if(!compareTypes(stringType, e->val.gteE.left->type) && !compareTypes(intType, e->val.gteE.left->type))
			{
				printf("%d: Type Error: Comparisons can only be between ints or strings.\n", e->lineno);
				typeErrors++;
			}
			break;			
		case notK:
			printf("  top of notk\n");
			typeEXP(e->val.exprE);
			if(compareTypes(boolType, e->val.exprE->type))
				e->type = makeBool();
			else
			{
				printf("%d: Type Error: bool type expected.\n", e->lineno);
				typeErrors++;
			}
			break;
		case plusK:
			printf("  top of plusK\n");
			typeEXP(e->val.plusE.left);
			typeEXP(e->val.plusE.right);
			counter = 0;
			if(compareTypes(stringType, e->val.plusE.left->type))
				counter++;
			else if(!compareTypes(intType, e->val.plusE.left->type))
			{	
				printf("%d: Type Error: incorrect types for operator '+'.\n", e->lineno);
				typeErrors++;
			}
			if(compareTypes(stringType, e->val.plusE.left->type))
				counter++;
			else if(!compareTypes(intType, e->val.plusE.left->type))
			{	
				printf("%d: Type Error: incorrect types for operator '+'.\n", e->lineno);
				typeErrors++;
			}
			if(counter > 0)
				e->type = makeString();
			else
				e->type = makeInt();
			break;
		case minusK:
			printf("  top of minusK\n");
			typeEXP(e->val.minusE.left);
			typeEXP(e->val.minusE.right);
			if(compareTypes(e->val.minusE.left->type, e->val.minusE.right->type) && compareTypes(intType, e->val.minusE.left->type))
			{
				e->type = makeInt();
			}
			else
			{
				printf("%d: Type Error: Expected type int for subtraction.\n", e->lineno);
				typeErrors++;
			}
			break;
		case multK:
			printf("  top of multK\n");
			typeEXP(e->val.multE.left);
			typeEXP(e->val.multE.right);
			if(compareTypes(e->val.multE.left->type, e->val.multE.right->type) && compareTypes(intType, e->val.multE.left->type))
			{
				e->type = makeInt();
			}
			else
			{
				printf("%d: Type Error: Expected type int for multiplication.\n", e->lineno);
				typeErrors++;
			}
			break;
		case divK:
			printf("  top of divK\n");
			typeEXP(e->val.divE.left);
			typeEXP(e->val.divE.right);
			if(compareTypes(e->val.divE.left->type, e->val.divE.right->type) && compareTypes(intType, e->val.divE.left->type))
			{
				e->type = makeInt();
			}
			else
			{
				printf("%d: Type Error: Expected type int for division.\n", e->lineno);
				typeErrors++;
			}
			break;
		case modK:
			printf("  top of modK\n");
			typeEXP(e->val.modE.left);
			typeEXP(e->val.modE.right);
			if(compareTypes(e->val.modE.left->type, e->val.modE.right->type) && compareTypes(intType, e->val.modE.left->type))
			{
				e->type = makeInt();
			}
			else
			{
				printf("%d: Type Error: Expected type int for mod.\n", e->lineno);
				typeErrors++;
			}
			break;
		case andK:
			printf("  top of andK\n");
			typeEXP(e->val.andE.left);
			typeEXP(e->val.andE.right);
			if(compareTypes(e->val.andE.left->type, e->val.andE.right->type) && compareTypes(boolType, e->val.andE.left->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Expected type bool for &&.\n", e->lineno);
				typeErrors++;
			}
			break;
		case orK:
			printf("  top of orK\n");
			typeEXP(e->val.orE.left);
			typeEXP(e->val.orE.right);
			if(compareTypes(e->val.orE.left->type, e->val.orE.right->type) && compareTypes(intType, e->val.orE.left->type))
			{
				e->type = makeBool();
			}
			else
			{
				printf("%d: Type Error: Expected type bool for ||.\n", e->lineno);
				typeErrors++;
			}
			break;
		case joinK:
			printf("  top of joinK\n");
			typeEXP(e->val.joinE.left);
			typeEXP(e->val.joinE.right);
			if(e->val.joinE.left->type->schema == NULL || e->val.joinE.right->type->schema == NULL)
			{
				printf("  error in joinK\n");
				return;
			}			
			e->type = NEW(TYPE);
			e->type->kind = tupleidK;
			e->type->schema = joinTuples(e->val.joinE.left->type->schema, e->val.joinE.right->type->schema);
			break;
		case keepK:
			printf("  top of keepK\n");
			typeEXP(e->val.keepE.left);
			e->type = NEW(TYPE);
			e->type->kind = tupleidK;
			e->type->schema = keepIDs(e->val.keepE.left->type->schema, e->val.keepE.right);
			if(e->type->schema == NULL)
			{
				printf("%d: Type Error: Identifiers are not a subset of schema fields.\n", e->lineno);
				typeErrors++;
			}
			break;
		case removeK:
			printf("  top of removeK\n");
			typeEXP(e->val.removeE.left);
			e->type = NEW(TYPE);
			e->type->kind = tupleidK;
			e->type->schema = removeIDs(e->val.keepE.left->type->schema, e->val.keepE.right);
			if(e->type->schema == NULL)
			{
				printf("%d: Type Error: Identifiers are not a subset of schema fields.\n", e->lineno);
				typeErrors++;
			}
			break;
		case callK:
			printf("  top of callK\n");
			typeARGUMENT(e->val.callE.left->symbol->val.functionS->argument, e->val.callE.right);
			e->type = e->val.callE.left->symbol->val.functionS->type;
			break;
		case tupleK:
			printf("  top of tupleK\n");
			typeFIELDVALUE(e->val.tupleE);
			printf("  after fieldvalue\n");
			e->type = NEW(TYPE);
			e->type->kind = tupleidK;	/* SEGFAULT WARNING TODO HELP */
			e->type->schema = NEW(SCHEMA);
			printf("  after setting type shit\n");
			makeAnonymousTuple(e->type->schema, e->val.tupleE);
			printf("  after make anonymous tuple\n");
			break;
		case parenK:
			printf("  top of parenK\n");
			typeEXP(e->val.exprE);
			e->type = e->val.exprE->type;
			break;
		case intconstK:
			printf("  top of intconstK\n");
			e->type = makeInt();
			break;
		case trueK:
			e->type = makeBool();
			break;
		case falseK:
			e->type = makeBool();
			break;
		case stringconstK:
			e->type = makeString();
			break;
	}
}

FIELD* dupField(FIELD* f)
{
	FIELD* toR;
	if(f == NULL)
		return NULL;
	
	toR = NEW(FIELD);
	toR->id = f->id;
	toR->simpletype = f->simpletype;
	toR->next = dupField(f->next);
	return toR;
}

SCHEMA* joinTuples(SCHEMA* s1, SCHEMA* s2)
{
	printf("  top of joinTuples\n");
	FIELD* s1Loop;
	FIELD* s2Loop;
	FIELD* s2Start;
	SCHEMA* toR;
	int matches;
	FIELD* toRfield;
	toRfield = NULL;
	toR = NEW(SCHEMA);
	
	s1Loop = dupField(s1->field);
	/* s1Loop has same fields as s1 */
	s2Start = dupField(s2->field);
	/* s2Loop has same fields as s2 */
	printf("  above first while loop\n");
	while(s1Loop != NULL)
	{
		matches = 0;
		s2Loop = s2Start;
		printf("  above second while\n");
		while(s2Loop != NULL)
		{
			if(!strcmp(s2Loop->id->identifier, s1Loop->id->identifier))
			{	/* don't add s1 */
				printf("  after strcmp\n");
				matches++;
				break;
			}
			s2Loop = s2Loop->next;
		}
		printf("  above matches == 0\n");
		if(matches == 0)
		{	/* in s1, not s2: keep */
			if(toRfield == NULL)
			{
				printf("  toRfield == NULL\n");
				toRfield = s1Loop;
				toR->field = toRfield;
				printf("  after setting\n");
			}
			else
			{
				printf("  toRfield == NULL\n");	
				toRfield->next = s1Loop;
				toRfield = toRfield->next;
			}
		}
		printf("  after matches == 0\n");
		s1Loop = s1Loop->next;
	}
	toRfield->next = s2Start;
	/* appending all of s2 onto toR */
	return toR;
}

SCHEMA* keepIDs(SCHEMA* schema, ID* id)
{
	printf("  top of keep ids\n");
	int matched;
	SCHEMA* toR;
	toR = NEW(SCHEMA);
	FIELD* temp;
	FIELD* toAdd;
	while(id != NULL)
	{	/* iterate over each id in the right side list */
		matched = 0;
		temp = schema->field;
		while(temp != NULL)
		{	/* iterate over all values in the tuple to see if the ID is in the tuple */
			if(!strcmp(id->identifier, temp->id->identifier))
			{	/* id is in the tuple, keep this one in toAdd */
				matched++;
				if(toAdd == NULL)
				{	/* if this is the first match, set it to toAdd */
					toAdd = temp;
					toR->field = toAdd;
				}
				else
				{	/* otherwise, make it toAdd's next, and make toAdd = toAdd->next */
					toAdd->next = temp;
					toAdd = temp;
				}
				break;
			}
			temp = temp->next;	
		}
		if(!matched)
		{	/* this ID isn't in the tuple, so return */
			return NULL;
		}
		id = id->next;
	}
	return toR;
}

SCHEMA* removeIDs(SCHEMA* schema, ID* id)
{
	printf("  top of remove ids\n");
	int matched;
	SCHEMA* toR;
	toR = NEW(SCHEMA);
	FIELD* tempField;
	FIELD* toAdd;
	ID* tempID;
	tempID = id;
	
	/* Make sure all ids are in the tuple */
	while(tempID != NULL)
	{
		matched = 0;
		tempField = schema->field;
		while(tempField != NULL)
		{	
			if(!strcmp(tempID->identifier, tempField->id->identifier))
			{ 	/* id is in the tuple */
				matched++;
				break;
			}
			tempField = tempField->next;	
		}
		if(!matched)
		{	/* id is not in the tuple, return */
			return NULL;
		}
		tempID = tempID->next;
	}
	/* all ids in the tuple, now do removes */
	tempID = id;
	while(tempField != NULL)
	{
		matched = 0;
		tempField = schema->field;
		while(tempID != NULL)
		{	
			if(!strcmp(id->identifier, tempField->id->identifier))
			{ 	/* id is in the tuple, don't add this one  */
				matched++;
				break;
			}
			tempID = tempID->next;	
		}
		if(!matched)
		{	/* id is not in the tuple, add the tuple value to the schema */
			if(toAdd == NULL)
			{
				toAdd = tempField;
				toR->field = toAdd;
			}
			else
			{
				toAdd->next = tempField;
				toAdd = tempField;
			}
		}
		tempField = tempField->next;
	}
	return toR;
}


void makeAnonymousTuple(SCHEMA* schema, FIELDVALUE* fieldvalue)
{
	printf("  top of make anonymous tuple\n");
	FIELD* field;
	field = NEW(FIELD);
	schema->field = field;
	while(fieldvalue != NULL)
	{
		field->id = fieldvalue->id;
		if(fieldvalue->expr->type->kind != simpletypeK)
		{
			printf("%d: Type Error: Tuple elements must be of type simpletype.\n", fieldvalue->lineno);
			typeErrors++;
			return;
		}
		field->simpletype = fieldvalue->expr->type->val.simpletype;
		fieldvalue = fieldvalue->next;
		if(fieldvalue != NULL)
		{
			field->next = NEW(FIELD);
			field = field->next;
		}
	}
}

void typeIDchain(ID* i)
{
	if(i == NULL) return;
	if(i->next != NULL)
		typeIDchain(i->next);

}

TYPE* getRealType(SymbolType* stype)
{
	TYPE* toR = NEW(TYPE);
	switch(stype->kind)
	{
		case failSK:
			printf("\n\nSOMETHING WENT WRONG\n\n");
			break;
		case intSK:
			toR->kind = simpletypeK;
			toR->val.simpletype = NEW(SIMPLETYPE);
			toR->val.simpletype->kind = intK;
			break;
		case boolSK:
			toR->kind = simpletypeK;
			toR->val.simpletype = NEW(SIMPLETYPE);
			toR->val.simpletype->kind = boolK;
			break;
		case stringSK:
			toR->kind = simpletypeK;
			toR->val.simpletype = NEW(SIMPLETYPE);
			toR->val.simpletype->kind = stringK;
			break;
		case voidSK:
			toR->kind = simpletypeK;
			toR->val.simpletype = NEW(SIMPLETYPE);
			toR->val.simpletype->kind = voidK;
			break; 
		case tupleSK:
			toR->kind = tupleidK;
			toR->val.id = NEW(ID);
			toR->val.id->identifier = stype->tupleName;
			toR->schema = stype->schema;
			break; 
		case htmlSK:
		case schemaSK:
		case gapSK:
		case sessionSK:
			return NULL;
	}
	return toR;
}

int compareTypes(TYPE* t1, TYPE* t2)
{
	printf("  top of compare types\n");
	if(t1->kind == t2->kind)
	{
		printf("  inside first if\n");
		if(t1->kind == simpletypeK)
		{
			printf("  inside second if\n");
			if(t1->val.simpletype->kind == t2->val.simpletype->kind)
			{
				printf("  inside third if\n");
				return 1;
			}
		}
		else
		{
			printf("  inside else\n");
			if(compareSchemas(t1->schema, t2->schema))
			{
				printf("  inside fourth if\n");
				return 1;
			}
		}
	}
	return 0;
}

int compareSchemas(SCHEMA* s1, SCHEMA* s2)
{
	printf("  top of compare schemas\n");
	printf("  %x, %x\n", s1, s2);
	return subsetFields(s1->field, s2->field) && subsetFields(s2->field, s1->field);
}

int subsetFields(FIELD* f1, FIELD* f2) 	/* f1 is a subset of f2 */
{
	printf("  top of subset fields\n");
	int matched;
	FIELD* temp;
	while(f1 != NULL)
	{
		temp = f2;
		matched = 0;
		while(temp != NULL)
		{
			if(!strcmp(f1->id->identifier, temp->id->identifier) && (f1->simpletype->kind == temp->simpletype->kind))
			{
				matched++;
				break;
			}
			temp = temp->next;	
		}
		if(!matched)
		{
			return 0;
		}
		f1 = f1->next;
	}
	return 1;
}

void typeARGUMENT(ARGUMENT* arg, EXP* expr)
{
	if((arg == NULL) != (expr == NULL)) /* one is null, so wrong number of arguments */
	{
		typeErrors++;
		printf("%d: Type Error: Wrong number of arguments for function call.\n", expr->lineno);
	}
	if(arg == NULL && expr == NULL)
		return;

	typeARGUMENT(arg->next, expr->next);

	typeEXP(expr);

	if(!compareTypes(arg->type, expr->type))
	{
		typeErrors++;
		printf("%d: Type Error: Wrong type of argument for function call.\n", expr->lineno);
	}
}




TYPE* makeBool()
{
	TYPE* toR;
	toR = NEW(TYPE);
	toR->kind = simpletypeK;
	toR->val.simpletype = NEW(SIMPLETYPE);
	toR->val.simpletype->kind = boolK;
	return toR;
}

TYPE* makeInt()
{
	TYPE* toR;
	toR = NEW(TYPE);
	toR->kind = simpletypeK;
	toR->val.simpletype = NEW(SIMPLETYPE);
	toR->val.simpletype->kind = intK;
	return toR;
}

TYPE* makeVoid()
{
	TYPE* toR;
	toR = NEW(TYPE);
	toR->kind = simpletypeK;
	toR->val.simpletype = NEW(SIMPLETYPE);
	toR->val.simpletype->kind = voidK;
	return toR;
}

TYPE* makeString()
{
	TYPE* toR;
	toR = NEW(TYPE);
	toR->kind = simpletypeK;
	toR->val.simpletype = NEW(SIMPLETYPE);
	toR->val.simpletype->kind = stringK;
	return toR;
}