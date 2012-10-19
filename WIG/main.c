#include "tree.h"
#include "pretty.h"
#include "eval.h"
#include "stdio.h"

void yyparse();

SERVICE *theservice;

int lineno;

int main()
{ lineno = 1;
  printf("Type in a tiny exp folowed by one or two Ctrl-d's:\n");
  yyparse();
  printf("\nThe result of evaluating:\n");
  prettySERVICE(theservice);
  printf("\n");
  return(1);
}
