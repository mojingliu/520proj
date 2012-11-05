%{
#include "y.tab.h"
#include "tree.h"
#include <string.h>
#include <stdlib.h>

extern int lineno;
%}

%x WHATEVER HTML HTMLTAG HTMLGAP HTMLQUOTE STRCONST COMMENT

%%
[ \t]+    /* ignore */;
\n        lineno++;
<HTMLTAG>[ \t]+   /* ignore */
<HTMLTAG>\n     lineno++;
<WHATEVER>\<!--.*?--> {
  yylval.stringconst = 
      (char *) malloc (strlen (yytext) + 1);
    sprintf (yylval.stringconst, "%s", yytext); 
    return tMETA;
}

"service" return tSERVICE;
"const"   return tCONST;

"html"    return tHTML;


"<html>"  {
            BEGIN(WHATEVER);
            return tHTMLTAGOPEN;
          }


<WHATEVER>"</html>" {
                  BEGIN(INITIAL);
                  return tHTMLTAGCLOSE;
                }


"/*"     BEGIN(COMMENT);

<COMMENT>\n    lineno++;
<COMMENT>[^*\n]*   /* ignore */;
<COMMENT>\*[^\/]*  /* ignore */;
<COMMENT>"*/" BEGIN(INITIAL); 


"schema"  return tSCHEMA;
"int"     return tINT;
"bool"    return tBOOL;
"string"  return tSTRING;
"void"    return tVOID;
"session" return tSESSION;
"show"    return tSHOW;
"exit"    return tEXIT;
"return"  return tRETURN;
"if"      return tIF;
"else"    return tELSE;
"while"   return tWHILE;
"plug"    return tPLUG;
"receive" return tRECEIVE;
"true"    return tTRUE;
"false"   return tFALSE;
"tuple"   return tTUPLE;
"{"       return '{';
"}"       return '}';
";"       return ';';
"="     return '=';
"=="      return tEQUALS;
">="      return tGTE;
"<="      return tLTE;
"!="      return tNEQ;
"\\+"     return tKEEP;
"\\-"     return tREMOVE;
"<<"      return tJOIN;
"||"      return tOR;
"&&"      return tAND;
\/\/[^\n]* /* ignore */;

"*"       return '*';
"/"       return '/';
"%"       return '%';
"+"       return '+';
"-"       return '-';
"("       return '(';
")"       return ')';
"\\"	    return '\\';
"!"       return '!';
"<"       return '<';
">"       return '>';
"&"       return '&';
"|"		    return '|';
","       return ',';

"["       return '[';
"]"       return ']';

"."		  return '.';


<WHATEVER>"<" { 
            BEGIN(HTMLTAG);
            return '<';
          }
<WHATEVER>"<["  {
              BEGIN(HTMLGAP);
              return tGAPOPEN;
            }

<HTMLGAP>\/?[a-zA-Z_][a-zA-Z0-9_]*  { 
                                    yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                                    sprintf(yylval.stringconst,"%s",yytext); 
                                    return tIDENTIFIER; 
                                  }
<HTMLGAP>"]>" {
                BEGIN(WHATEVER);
                return tGAPCLOSE;
              }
<HTMLTAG>"="    return '=';
<HTMLTAG>">"      {
                    BEGIN(WHATEVER);
                    return '>';
                  }
<HTMLTAG>"input"   return tINPUT;
<HTMLTAG>"select"  return tSELECT;
<HTMLTAG>"name"    return tNAME;
<HTMLTAG>"type"    return tTYPE;
<HTMLTAG>"\"text\""    return tTEXT;
<HTMLTAG>"radio"   return tRADIO;
<HTMLTAG>"\"radio\""   return tRADIO;
<HTMLTAG>0|([1-9][0-9]*) {
                            yylval.intconst = atoi (yytext);
                            return tINTCONST;
                          }

<HTMLTAG>\/?[a-zA-Z_][a-zA-Z0-9_]*  { 
                                    yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                                    sprintf(yylval.stringconst,"%s",yytext); 
                                    return tIDENTIFIER; 
                                  }
<HTMLTAG>\"     {
                  BEGIN(HTMLQUOTE);
                  return '"';
                }

<HTMLQUOTE>("(\\\\)*\\\""|[^\\\"]|"\\\\")* {
                            yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                            sprintf(yylval.stringconst,"%s",yytext); 
                            return tSTRINGCONST; 
                          }

<HTMLQUOTE>\"             {
                            BEGIN(HTMLTAG);
                            return '"';
                          }


<INITIAL>\" {
                BEGIN(STRCONST);
                return '"';
            }
<STRCONST>\" {
                BEGIN(INITIAL);
                return '"';
            }

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

<WHATEVER>[^<\n]* {
    yylval.stringconst =
      (char *) malloc (strlen (yytext) + 1);
    sprintf (yylval.stringconst, "%s", yytext); 
    return tWHATEVER;
}

<WHATEVER>\n {
    lineno++;
    yylval.stringconst =
      (char *) malloc (strlen (yytext) + 1);
    sprintf (yylval.stringconst, "%s", yytext);
    return tWHATEVER;
}



<STRCONST>("(\\\\)*\\\""|[^\\\"]|"\\\\")* {
                            yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                            sprintf(yylval.stringconst,"%s",yytext); 
                            return tSTRINGCONST;
                          }

%%
