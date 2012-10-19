%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>

extern int lineno;
%}

%%
[ \t]+    /* ignore */;
\n        lineno++;

"*"       return '*';
"/"       return '/';
"%"       return '%';
"+"       return '+';
"-"       return '-';
"("       return '(';
")"       return ')';
"\\"	  return '\\';
"="		  return '=';
"!"       return '!';
"<"       return '<';
">"       return '>';
"&"       return '&';
"|"		  return '|';
","       return ',';
";"       return ';';
"["       return '[';
"]"       return ']';
"{"	      return '{';
"}"       return '}';
"."		  return '.';


"service" return tSERVICE;
"const"	  return tCONST;
"html"	  return tHTML;
"<html>"  return tHTMLTAGOPEN;
"</html>" return tHTMLTAGCLOSE;
"input"   return tINPUT;
"select"  return tSELECT;
"name"    return tNAME;
"type"    return tTYPE;
"text"    return tTEXT;
"radio"   return tRADIO;
"schema"  return tSCHEMA;
"int"     return tINT;
"bool"    return tBOOL;
"string"  return tSTRING;
"void"	  return tVOID;
"session" return tSESSION;
"show"	  return tSHOW;
"exit"	  return tEXIT;
"return"  return tRETURN;
"if"      return tIF;
"else"	  return tELSE;
"while"   return tWHILE;
"plug"    return tPLUG;
"receive" return tRECEIVE;
"true"    return tTRUE;
"false"   return tFALSE;
"tuple"   return tTUPLE;



0|([1-9][0-9]*) {
  yylval.intconst = atoi (yytext);
  return tINTCONST;
}

[a-zA-Z_][a-zA-Z0-9_]* { 
  yylval.stringconst = 
    (char *) malloc (strlen (yytext) + 1);
  sprintf (yylval.stringconst, "%s", yytext); 
  return tIDENTIFIER; 
}

\<!--.*?--> {
	yylval.stringconst = 
    	(char *) malloc (strlen (yytext) + 1);
  	sprintf (yylval.stringconst, "%s", yytext); 
  	return tMETA;
}

%%
