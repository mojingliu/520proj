#include "prettysymbol.h"

FILE* symbolofile;
const int TAB_WIDTHS = 2;

void setsymbolofile(FILE *f){
    symbolofile = f;
}

void newlineS(int indent)
{
    int i=0;
    fprintf(symbolofile, "\n");
    for(; i<indent * TAB_WIDTHS; i++)
        fprintf(symbolofile, " ");
}

void prettySYMBOL(SymbolTable* globalTable)
{
	
	SYMBOL *current; 
	SYMBOL *temp;
	SymbolTable *table;
	table = globalTable; 
	while(table != NULL)
	{
		newlineS(table->indent);
		newlineS(table->indent);
		fprintf(symbolofile, "New Scope");
		current = table->first;
		while(current != NULL)
		{
			newlineS(table->indent);
			fprintf(symbolofile, "Symbol: %s, Type: ", current->id);
			if(current->type->function)
			{
				 temp = (current->val.functionS->fTable->first);
				 fprintf(symbolofile, "(");
				 while(temp != NULL)
				 {
				 	writeType(temp->type);
				 	if(temp->next != NULL)
				 		fprintf(symbolofile, ", ");
				 	temp = temp->next;
				 }
				 fprintf(symbolofile, ")->");
			}
			writeType(current->type); 
			current = current->next;
		}
		table = table->next;
	}
}	

void printArgs(ARGUMENT* arg)
{
	if(arg == NULL)
		return;
	if(arg->next != NULL)
		printArgs(arg->next);
	writeType(arg->type);
}

void writeType(SymbolType* type)
{
	switch(type->kind)
	{
		case failSK:
			fprintf(symbolofile, "someting broke here");
			break;
		case intSK:
			fprintf(symbolofile, "int");
			break;
		case stringSK:
			fprintf(symbolofile, "string");
			break;
		case boolSK:
			fprintf(symbolofile, "bool");
			break;
		case voidSK:
			fprintf(symbolofile, "void");
			break;
		case tupleSK:
			fprintf(symbolofile, "tuple %s", type->tupleName);
			break;
		case schemaSK:
			fprintf(symbolofile, "schema");
			break;
		case htmlSK:
			fprintf(symbolofile, "const html");
			break;
		case gapSK:
			fprintf(symbolofile, "gap");
			break;
		case sessionSK:
			fprintf(symbolofile, "session");
			break;
	}
}
