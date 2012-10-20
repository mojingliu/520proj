#include "tree.h"
#include "pretty.h"
#include "eval.h"
#include "stdio.h"
#include "weeder.h"

void yyparse();

SERVICE *theservice;
int weedError;
int lineno;


int main()
{ lineno = 1;
  printf("Type in a tiny exp folowed by one or two Ctrl-d's:\n");
  yyparse();
  weedSERVICE(theservice);
  if(weedError == 1)
  	printf("\n yo that shit broke\n");
  else
  {
	  printf("\nThe result of evaluating:\n");
	  prettySERVICE(theservice);
	  printf("\n");
  }
  return(1);
}
