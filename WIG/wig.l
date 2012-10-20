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

"html"    {
          printf("\n matching html");
          return tHTML;
          }

"<html>"  {
            printf("\n matching <html>");
            BEGIN(WHATEVER);
            return tHTMLTAGOPEN;
          }


<WHATEVER>"</html>" {
                  printf("\n matching </html>");
                  BEGIN(INITIAL);
                  return tHTMLTAGCLOSE;
                }


"/*"      {
          printf("\n starting comment");
          BEGIN(COMMENT);
          }
<COMMENT>\n   {
                printf("\n matching newline in comment");
                lineno++;
              }
<COMMENT>[^*\n]*  {
                    printf("\n matching not * in comment");
                    /* ignore */;
                  }
<COMMENT>\*[^\/]* {
                    printf("\n matching not */ in comment");
                    /* ignore */;
                  }
<COMMENT>"*/" BEGIN(INITIAL); 


"schema"  {
          printf("\n matching schema");
          return tSCHEMA;
          }
"int"     {
          printf("\n matching int");
          return tINT;
          }
"bool"    return tBOOL;
"string"  return tSTRING;
"void"    return tVOID;
"session" {
          printf("\n matching session");
          return tSESSION;
          }
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
"tuple"   {
          printf("\n matching tuple");
          return tTUPLE;
        }
"{"       return '{';
"}"       return '}';
";"       return ';';
"="     return '=';
"=="      return tEQUALS;
\/\/[^\n]* {printf("\n matching inline comment");}

"*"       return '*';
"/"       return '/';
"%"       return '%';
"+"       return '+';
"-"       return '-';
"("       {
            printf("\n matching (");
            return '(';
          }
")"       {
            printf("\n matching )");
            return ')';
          }
"\\"	  return '\\';

"!"       return '!';
"<"       return '<';
">"       return '>';
"&"       return '&';
"|"		  return '|';
","       return ',';

"["       return '[';
"]"       return ']';

"."		  return '.';


<WHATEVER>"<" { 
            printf("\n matching < in whatever");
            BEGIN(HTMLTAG);
            return '<';
          }
<WHATEVER>"<["  {
              BEGIN(HTMLGAP);
              return tGAPOPEN;
            }

<HTMLGAP>\/?[a-zA-Z_][a-zA-Z0-9_]*  { 
                                    printf("\n matching '%s' in htmltag", yytext);
                                    yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                                    sprintf(yylval.stringconst,"%s",yytext); 
                                    return tIDENTIFIER; 
                                  }
<HTMLGAP>"]>" {
                BEGIN(WHATEVER);
                return tGAPCLOSE;
              }
<HTMLTAG>"="       {
                      printf("\n matching = in htmltag");
                      return '=';
                  }
<HTMLTAG>">"      {
                    printf("\n matching > in htmltag");
                    BEGIN(WHATEVER);
                    return '>';
                  }
<HTMLTAG>"input"   {
                    printf("\n matching input in htmltag");
                    return tINPUT;
                  }
<HTMLTAG>"select"  return tSELECT;
<HTMLTAG>"name"     {
                      printf("\n matching name in htmltag");
                      return tNAME;
                    }
<HTMLTAG>"type"    {
                      printf("\n matching type in htmltag");
                      return tTYPE;
                    }
<HTMLTAG>"\"text\""    return tTEXT;
<HTMLTAG>"radio"   return tRADIO;
<HTMLTAG>"\"radio\""   return tRADIO;
<HTMLTAG>0|([1-9][0-9]*) {
                            yylval.intconst = atoi (yytext);
                            return tINTCONST;
                          }

<HTMLTAG>\/?[a-zA-Z_][a-zA-Z0-9_]*  { 
                                    printf("\n matching '%s' in htmltag", yytext);
                                    yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                                    sprintf(yylval.stringconst,"%s",yytext); 
                                    return tIDENTIFIER; 
                                  }
<HTMLTAG>\"     {
                  printf("\n matching opening quote in htmltag");
                  BEGIN(HTMLQUOTE);
                  printf("\n switching to htmlquote");
                  return '"';
                }

<HTMLQUOTE>("(\\\\)*\\\""|[^\\\"]|"\\\\")* {
                            printf("\n matched '%s' in htmlquote", yytext);
                            yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                            sprintf(yylval.stringconst,"%s",yytext); 
                            return tSTRINGCONST; 
                          }

<HTMLQUOTE>\"             {
                            printf("\n matched end quote of htmlquote");
                            BEGIN(HTMLTAG);
                            return '"';
                          }


<INITIAL>\" {
                BEGIN(STRCONST);
                return '"';
            }
<STRCONST>\" {
                printf("\n ending strconst, back in initial");
                BEGIN(INITIAL);
                return '"';
            }

0|([1-9][0-9]*) {
  printf("\n matching intconst '%s'", yytext);
  yylval.intconst = atoi (yytext);
  return tINTCONST;
}

[a-zA-Z_][a-zA-Z0-9_]* { 
  printf("\n matching identifier '%s'", yytext);
  yylval.stringconst = 
    (char *) malloc (strlen (yytext) + 1);
  sprintf (yylval.stringconst, "%s", yytext); 
  return tIDENTIFIER; 
}

<WHATEVER>[^<]* {
  printf("\n matching '%s' in whatever", yytext);
  yylval.stringconst =
      (char *) malloc (strlen (yytext) + 1);
    sprintf (yylval.stringconst, "%s", yytext); 
    return tWHATEVER;
}



<STRCONST>("(\\\\)*\\\""|[^\\\"]|"\\\\")* {
                            printf("\n matched '%s' in strconst", yytext);
                            yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                            sprintf(yylval.stringconst,"%s",yytext); 
                            return tSTRINGCONST;
                          }

%%
