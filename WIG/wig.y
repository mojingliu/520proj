%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern SERVICE* theservice;

void yyerror() {
   printf ("syntax error before %s\n", yytext); 
}
%}

%start service

%union
{
  struct SERVICE* service;
  struct HTML* html;
  struct HTMLBODY* htmlbody;
  struct INPUTATTR* inputattr;
  struct ATTRIBUTE* attribute;
  struct ATTR* attr;
  struct SCHEMA* schema;
  struct FIELD* field;
  struct SIMPLETYPE* simpletype;
  struct VARIABLE* variable;
  struct TYPE* type;
  struct FUNCTION* function;
  struct ARGUMENT* argument;
  struct STM* statement;
  struct COMPOUNDSTM* compoundstm;
  struct EXP* exp;
  struct ID* id;
  struct FIELDVALUE* fieldvalue;
  struct DOCUMENT* document;
  struct PLUG* plug;
  struct RECEIVE* receive;
  struct INPUT* input;
  struct SESSION* session;
  struct LVALUE* lvalue;
  int intconst;
  char* stringconst;
};

%token tSERVICE tCONST
       tHTML tHTMLTAGOPEN tHTMLTAGCLOSE
       tINPUT tSELECT 
       tNAME tTYPE tTEXT tRADIO
       tSCHEMA 
       tINT tBOOL tSTRING tVOID
       tSESSION tSHOW tEXIT tRETURN 
       tIF tELSE tWHILE tPLUG
       tRECEIVE tTRUE tFALSE
       tTUPLE

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER tSTRINGCONST tWHATEVER tMETA 



%type <service> service
%type <html> htmls html
%type <htmlbody> htmlbodies nehtmlbodies htmlbody 
%type <attribute> attributes neattributes attribute
%type <attr> attr
%type <inputattr> inputattr inputattrs 
%type <schema> schemas neschemas schema
%type <field> fields nefields field
%type <simpletype> simpletype
%type <type> type
%type <id> identifier identifiers
%type <variable> nevariables variable variables
%type <function> functions nefunctions function
%type <session> sessions session
%type <argument> arguments nearguments argument
%type <statement> stms nestms stm
%type <document> document
%type <plug> plugs plug
%type <receive> receive
%type <input> inputs neinputs input
%type <exp> exps neexps exp
%type <fieldvalue> fieldvalues nefieldvalues fieldvalue
%type <compoundstm> compoundstm
%type <lvalue> lvalue




%%

service : tSERVICE '{' htmls schemas variables functions sessions '}'
  {$$ = makeSERVICE($3, $4, $5, $6, $7);};

htmls : html
    {$$ = $1;}
  | htmls html
    {$$ = $2; $$->next = $1;};

html: tCONST tHTML identifier '=' tHTMLTAGOPEN htmlbodies tHTMLTAGCLOSE ';'
  {$$ = makeHTML($3, $6);};

htmlbodies : /* empty */
    {$$ = NULL;}
  | nehtmlbodies
    {$$ = $1;};

nehtmlbodies : htmlbody
    {$$ = $1;}
  | nehtmlbodies htmlbody
    {$$ = $2; $$->next = $1;};

htmlbody : '<' identifier attributes '>'
    {$$ = makeHTMLBODYtag($2, $3);}
  | '<' '/' identifier '>'
    {$$ = makeHTMLBODYtag($3, NULL);}
  | '<' '[' identifier ']' '>'
    {$$ = makeHTMLBODYgap($3);}
  | tWHATEVER
    {$$ = $1;}
  | tMETA
    {$$ = $1;}
  | '<' tINPUT inputattrs '>'
    {$$ = makeHTMLBODYinput($3);}
  | '<' tSELECT inputattrs '>' htmlbodies '<' '/' tSELECT '>'
    {$$ = makeHTMLBODYselect($3, $5);};

inputattrs : inputattr
    {$$ = $1;}
  | inputattrs inputattr
    {$$ = $2; $$->next = $1;};

inputattr : tNAME '=' attr
    {$$ = makeINPUTATTRname($3);}
  | tTYPE '=' tTEXT
    {$$ = makeINPUTATTRtext();}
  | tTYPE '=' tRADIO
    {$$ = makeINPUTATTRradio();}
  | attribute
    {$$ = makeINPUTATTRattribute($1);};


attributes : /* empty */
    {$$ = NULL;} 
  | neattributes
    {$$ = $1;};

neattributes : attribute
    {$$ = $1;}
  | neattributes attribute
    {$$ = $2; $$->next = $1;};

attribute : attr
    {$$ = makeATTRIBUTEattr($1, NULL);}
  | attr '=' attr
    {$$ = makeATTRIBUTE($1, $3);};

attr : identifier
    {$$ = makeATTRid($1);}
  | tSTRINGCONST
    {$$ = makeATTRstringconst($1);};

schemas: /* empty */
    {$$ = NULL;}
  | neschemas
    {$$ = $1;};

neschemas: schema
    {$$ = $1;}
  | neschemas schema
    {$$ = $2; $$->next = $1;};

schema : tSCHEMA identifier '{' fields '}'
    {$$ = makeSCHEMA($2, $4);};

fields :  /* empty */
    {$$ = NULL;}
  | nefields
    {$$ = $1;};

nefields : field
    {$$ = $1;}
  | nefields field
    {$$ = 2; $$->next = $1;};

field : simpletype identifier ';'
    {$$ = makeFIELD($1, $2);};

variables : /* empty */
    {$$ = NULL;}
  | nevariables
    {$$ = $1;};

nevariables : variable
    {$$ = $1;}
  | nevariables variable
    {$$ = $2; $$->next = $1;};

variable : type identifiers ';'
    {$$ = makeVARIABLE($1, $2);};

identifiers : identifier
    {$$ = $1;}
  | identifiers ',' identifier
    {$$ = $3; $$->next = $1;};

identifier : tIDENTIFIER
    {$$ = makeID($1);};

simpletype : tINT
    {$$ = makeSIMPLETYPEint();}
  | tBOOL
    {$$ = makeSIMPLETYPEbool();}
  | tSTRING
    {$$ = makeSIMPLETYPEstring();}
  | tVOID
    {$$ = makeSIMPLETYPEvoid();};

type : simpletype
    {$$ = makeTYPEsimpletype($1);}
  | "tuple" identifier
    {$$ = makeTYPEtupleid($2);};

functions :  /* empty */
    {$$ = NULL;}
 | nefunctions
    {$$ = $1;};

nefunctions : function
    {$$ = 1;}
  | nefunctions function
    {$$ = $2; $$->next = $1;};

function : type identifier '(' arguments ')' compoundstm
    {$$ = makeFUNCTION($1, $2, $4, $6);};

arguments : /* empty */
    {$$ = NULL;}
 | nearguments
    {$$ = $1;};

nearguments : argument
    {$$ = $1;}
  | nearguments ',' argument
    {$$ = $3; $$->next = $1;};

argument : type identifier
    {$$ = makeARGUMENT($1, $2);};

sessions : session
    {$$ = $1;}
  | sessions session
    {$$ = $2; $$->next = $1;};

session : tSESSION identifier '(' ')' compoundstm
    {$$ = makeSESSION($2, $5);};

stms : /* empty */
    {$$ = NULL;}
  | nestms
    {$$ = $1;};

nestms : stm
    {$$ = $1;}
  | nestms stm
    {$$ = $2; $$ -> next = $1;};

stm : ';'
    {$$ = makeSTMsemicolon();}
  | tSHOW document receive ';'
    {$$ = makeSTMshow($2, $3);}
  | tEXIT document ';'
    {$$ = makeSTMexit($2);}
  | tRETURN ';'
    {$$ = makeSTMreturn();}
  | tRETURN exp ';'
    {$$ = makeSTMreturnexp($2);}
  | tIF '(' exp ')' stm
    {$$ = makeSTMif($3, $5);}
  | tIF '(' exp ')' stm tELSE stm
    {$$ = makeSTMifelse($3, $5, $7);}
  | tWHILE '(' exp ')' stm
    {$$ = makeSTMwhile($3, $5);}
  | compoundstm
    {$$ = makeSTMcompound($1);}
  | exp ';'
    {$$ = makeSTMexp($1);};

document : identifier 
    {$$ = makeDOCUMENTid($1);}
  | tPLUG identifier '[' plugs ']'
    {$$ = makeDOCUMENTplug($2, $4);};

receive : /* empty */
    {$$ = makeRECEIVE(NULL);}
  | tRECEIVE '[' inputs ']'
    {$$ = makeRECEIVE($3);};

compoundstm : '{' variables stms '}'
    {$$ = makeCOMPOUNDSTM($2, $3);};

plugs : plug
    {$$ = $1;}
  | plugs ',' plug
    {$$ = $3; $$->next = $1;};

plug : identifier '=' exp
    {$$ = makePLUG($1, $3);};

inputs : /* empty */
    {$$ = NULL;}
  | neinputs
    {$$ = $1;};

neinputs : input
    {$$ = $1;}
  | neinputs ',' input
    {$$ = $3; $$->next = $1;};

input : lvalue '=' identifier
    {$$ = makeINPUT($1, $3);};

exp : lvalue
    {$$ = makeEXPlvalue($1);}
  | lvalue '=' exp
    {$$ = makeEXPassign($1, $3);}
  | exp "==" exp
    {$$ = makeEXPequals($1, $3);}
  | exp "!=" exp
    {$$ = makeEXPnotequals($1, $3);}
  | exp '<' exp
    {$$ = makeEXPlt($1, $3);}
  | exp '>' exp
    {$$ = makeEXPgt($1, $3);}
  | exp '<' '=' exp
    {$$ = makeEXPlte($1, $4);}
  | exp '>' '=' exp
    {$$ = makeEXPgte($1, $4);}
  | '!' exp
    {$$ = makeEXPnot($2);}
  | '-' exp
    {$$ = makeEXPminus(0, $2);}
  | exp '+' exp
    {$$ = makeEXPplus($1, $3);}
  | exp '-' exp
    {$$ = makeEXPminus($1, $3);}
  | exp '*' exp
    {$$ = makeEXPmult($1, $3);}
  | exp '/' exp
    {$$ = makeEXPdiv($1, $3);}
  | exp '%' exp
    {$$ = makeEXPmod($1, $3);}
  | exp '&' '&' exp
    {$$ = makeEXPand($1, $4);}
  | exp '|' '|' exp
    {$$ = makeEXPor($1, $4);}
  | exp '<' '<' exp
    {$$ = makeEXPjoin($1, $4);}
  | exp '\\' '+' identifiers
    {$$ = makeEXPkeep($1, $4);}
  | exp '\\' '-' identifiers
    {$$ = makeEXPremove($1, $4);}
  | identifier '(' exps ')'
    {$$ = makeEXPcall($1, $3);}
  | tINTCONST
    {$$ = makeEXPintconst($1);}
  | tTRUE
    {$$ = makeEXPtrue();}
  | tFALSE
    {$$ = makeEXPfalse();}
  | tSTRINGCONST
    {$$ = makeEXPstringconst($1);}
  | tTUPLE '{' fieldvalues '}'
    {$$ = makeEXPtuple($3);};


exps : /* empty */
    {$$ = NULL;}
 | neexps
    {$$ = $1;};

neexps : exp
    {$$ = $1;}
  | neexps ',' exp
    {$$ = $3; $$->next = $1;};

lvalue : identifier 
    {$$ = makeLVALUE($1, NULL);}
  | identifier '.' identifier
    {$$ = makeLVALUE($1, $3);};

fieldvalues : /* empty */
    {$$ = NULL;}
  | nefieldvalues
    {$$ = $1;};

nefieldvalues : fieldvalue
    {$$ = $1;}
  | fieldvalues ',' fieldvalue
    {$$ = $3; $$->next = $1;};

fieldvalue : identifier '=' exp
    {$$ = makeFIELDVALUE($1, $3);};

%%
