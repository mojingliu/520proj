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
	if(globalTable == NULL)
		return;
	current = globalTable->first;
	while(current != NULL)
	{
		newlineS(globalTable->indent);
		fprintf(symbolofile, "Symbol: %s, Type: ", current->id);
		writeType(current->type); 
		current = current->next;
	}
	fprintf(symbolofile, "\n\n New Scope \n");
	prettySYMBOL(globalTable->next);
}	

void writeType(SymbolType* type)
{
	/* printf("\n\nin writeType\n\n"); */
	char* fun = "function ";
	if(!type->function)
		fun = "";
	switch(type->kind)
	{
		case failSK:
			fprintf(symbolofile, "someting broke here");
			break;
		case intSK:
			fprintf(symbolofile, "%sint", fun);
			break;
		case stringSK:
			fprintf(symbolofile, "%sstring", fun);
			break;
		case boolSK:
			fprintf(symbolofile, "%sbool", fun);
			break;
		case voidSK:
			fprintf(symbolofile, "%svoid", fun);
			break;
		case tupleSK:
			fprintf(symbolofile, "%stuple %s", fun, type->tupleName);
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
