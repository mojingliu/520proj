#include "tree.h"
#include "pretty.h"
#include "stdio.h"
#include "weeder.h"
#include "symbol.h"
#include "prettytype.h"
#include "type.h"
#include "prettysymbol.h"
#include "code.h"
#include <string.h>

void yyparse();

SERVICE *theservice;
int weedError;
int symbolError;
int lineno;
int typeErrors;
FILE* yyin;
FILE* ofile;
SymbolTable* globalTable;


void help()
{
	printf("   Help\n");
	printf("=========\n");
	printf("commands: \n");
	printf("--help: displays this message\n");
	printf("--noweeder: turns off the weeder\n");
	printf("--nosymbol: turns off the symbol table\n");
	printf("--printsymbol: prints the symbol table\n");
	printf("--nopretty: turns off pretty printer\n");
	printf("--notypecheck: turns off the typechecker\n");
	printf("--nocode: turns off the final code generation\n");
	printf("--prettytype: prints the file with expression types\n");
	printf("  Note: typechecker cannot be run with the symbol table turned off.\n");
	printf("format: \n");
	printf("    ./wig inputFile [outputFile] [--noweeder] [--symbol] [--nopretty] [--notypecheck]\n");
	printf("if you don't include an output file, output will be written to stdout.\n");
}

int main(int argc, char *argv[])
{
	int i;
	int weeder = 1;
	int symbol = 1;
	int pretty = 1;
	int typecheck = 1;
	int codegen = 1;
	int printsymbol = 0;
	int prettytype = 0;
	int onSTDOUT = 0;
	lineno = 1;
	if(argc == 1)
	{
		help();
		return(0);
	}
	for(i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "--help"))
		{
			help();
			return(0);
		}
		else if(!strcmp(argv[i], "--noweeder"))
			weeder = 0;
		else if(!strcmp(argv[i], "--nosymbol"))
			symbol = 0;
		else if(!strcmp(argv[i], "--nopretty"))
			pretty = 0;
		else if(!strcmp(argv[i], "--notypecheck"))
			typecheck = 0;
		else if(!strcmp(argv[i], "--printsymbol"))
			printsymbol = 1;
		else if(!strcmp(argv[i], "--prettytype"))
			prettytype = 1;
		else if(!strcmp(argv[i], "--nocode"))
			codegen = 0;
	}

	yyin = fopen(argv[1], "r");
	printf("inputFile = %s\n", argv[1]);
	if(yyin == NULL)
	{
		printf("invalid input file!\n");
		return 0;
	}
	if(argc < 3 || (strlen(argv[2]) > 1 && argv[2][0] == '-' && argv[2][1] == '-'))
		ofile = NULL;
	else
		ofile = fopen(argv[2], "w");
	
	if(ofile == NULL)
	{
		printf("No output file - printing to stdout\n");
		printf("=================================\n");
		onSTDOUT = 1;
		ofile = stdout;
	}
	else
		printf("outputFile = %s\n", argv[2]);

	yyparse();
	setofile(ofile);
	if(weeder)
		weedSERVICE(theservice);
	if(weedError)
	{
		fclose(yyin);
		if(onSTDOUT == 0)
			fclose(ofile);
		printf("\n\n");
		return(0);
	}
	if(pretty == 1)
		prettySERVICE(theservice);
	if(symbol == 1)
	{
		setsymbolofile(stdout);
		symbolSERVICE(theservice);
		if(symbolError) 
		{
			fclose(yyin);
			if(onSTDOUT == 0)
				fclose(ofile);
			printf("\n\n");
			return(0);
		}
		if(printsymbol)
			prettySYMBOL(globalTable);
	}
	if(typecheck)
	{
		settypeofile(stdout);
		typeSERVICE(theservice);
		if(typeErrors)
		{
			printf("%d type errors found.\n", typeErrors);
		fclose(yyin);
		if(onSTDOUT == 0)
			fclose(ofile);
		printf("\n\n");
			return(0);
		}
		if(prettytype)
			prettyTypeSERVICE(theservice);
	}
	if(codegen)
	{
		ofile = fopen("chess.py", "w");
		cSetofile(ofile);
		codeSERVICE(theservice);
	}
	fclose(yyin);
	if(onSTDOUT == 0)
		fclose(ofile);
	printf("\n\n");
	return(0);
}
