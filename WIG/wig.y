%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern EXP *theexpression;

void yyerror() {
   printf ("syntax error before %s\n", yytext); 
}
%}


%%
service : tSERVICE '{' htmls schemas variables sessions '}'
  {};

htmls : html
    {}
  | htmls html
    {};

html: tCONST tHTML identifier '=' tHTMLTAGOPEN htmlbodies tHTMLTAGCLOSE ';'
  {};

htmlbodies : {}
  | nehtmlbodies
    {};

nehtmlbodies : htmlbody
    {}
  | nehtmlbodies htmlbody
    {};

htmlbody : '<' identifier attributes '>'
    {}
  | '<' '/' identifier '>'
    {}
  | '<' '[' identifier ']' '>'
    {}
  | whatever
    {}
  | meta
    {}
  | '<' tINPUT inputattrs '>'
    {}
  | '<' tSELECT inputattrs '>' htmlbodies '<' '/' tSELECT '>'
    {};

inputattrs : inputattr
    {}
  | inputattrs inputattr
    {};

inputattr : tNAME '=' attr
    {}
  | tTYPE '=' inputtype
    {}
  | attribute
    {};

inputtype : tTEXT | tRADIO
    {};

attributes : {} 
  | neattributes
    {};

neattributes : attribute
    {}
  | neattributes attribute
    {};

attribute : attr
    {}
  | attr '=' attr
    {};

attr : identifier
    {}
  | stringconst
    {};

schemas: 
    {}
  | neschemas
    {};

neschemas: schema
    {}
  | neschemas schema
    {};

schema : tSCHEMA identifier '{' fields '}'
    {};

fields :
    {}
  | nefields
    {};

nefields : field
    {}
  | nefields field
    {};

field : simpletype identifier ';'
    {};

variables : 
    {}
  | nevariables
    {};

nevariables : variable
    {}
  | nevariables variable
    {};

variable : type identifiers ';'
    {};

identifiers : identifier
    {}
  | identifiers ',' identifier
    {};

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
    {$$ makeTYPEtupleid(identifier)};

functions :
    {}
 | nefunctions
    {};

nefunctions : function
    {}
  | nefunctions function
    {};

function : type identifier '(' arguments ')' compoundstm
    {};

arguments : /* empty */
    {$$ = NULL;}
 | nearguments
    {$$ = $1};

nearguments : argument
    {$$ = $1;}
  | nearguments ',' argument
    {$$ = $3; $$->next = $1;};

argument : type identifier
    {$$ = makeARGUMENT($1, $2);};

sessions : session
    {}
  | sessions session
    {};

session : tSESSION identifier '(' ')' compoundstm
    {};

stms : /* empty */
    {$$ = NULL;}
  | nestms
    {$$ = $1;};

nestms : stm
    {$$ = $1;}
  | nestms stm
    {$$ = $2; $$ -> next = $1;};

stm : ';'
    {$$ = makeSTATEMENTsemicolon();}
  | tSHOW document receive ';'
    {$$ = makeSTATEMENTshow($2, $3);}
  | tEXIT document ';'
    {$$ = makeSTATEMENTexit($2);}
  | tRETURN ';'
    {$$ = makeSTATEMENTreturn()}
  | tRETURN exp ';'
    {$$ = makeSTATEMENTreturnexp($2);}
  | tIF '(' exp ')' stm
    {$$ = makeSTATEMENTif($3, $5);}
  | tIF '(' exp ')' stm tELSE stm
    {$$ = makeSTATEMENTifelse($3, $5, $7);}
  | tWHILE '(' exp ')' stm
    {$$ = makeSTATEMENTwhile($3, $5);}
  | compoundstm
    {$$ = $1;}
  | exp ';'
    {};

document : identifier 
    {}
  | tPLUG identifier '[' plugs ']'
    {};

receive : 
    {}
  | tRECEIVE '[' inputs ']'
    {};

compoundstm : '{' variables stms '}'
    {$$ = makeCOMPOUNDSTM($2, $3);};

plugs : plug
    {}
  | plugs ',' plug
    {};

plug : identifier '=' exp
    {};

inputs : 
    {}
  | neinputs
    {};

neinputs : input
    {}
  | neinputs ',' input
    {};

input : lvalue '=' identifier
    {};

exp : lvalue
    {}
  | lvalue '=' exp
    {}
  | exp "==" exp
    {}
  | exp "!=" exp
    {}
  | exp '<' exp
    {}
  | exp '>' exp
    {}
  | exp '<' '=' exp
    {}
  | exp '>' '=' exp
    {}
  | '!' exp
    {}
  | '-' exp
    {}
  | exp '+' exp
    {}
  | exp '-' exp
    {}
  | exp '*' exp
    {}
  | exp '/' exp
    {}
  | exp '%' exp
    {}
  | exp '&' '&' exp
    {}
  | exp '|' '|' exp
    {}
  | exp '<' '<' exp
    {}
  | exp '\' '+' identifiers
    {}
  | exp '\' '-' identifiers
    {}
  | identifier '(' exps ')'
    {}
  | intconst
    {}
  | tTRUE
    {}
  | tFALSE
    {}
  | stringconst
    {}
  | tTUPLE '{' fieldvalues '}'
    {};

exps : /* empty */
    {}
 | neexps
    {};

neexps : exp
    {}
  | neexps ',' exp
    {};

lvalue : identifier 
    {}
  | identifier '.' identifier
    {};

fieldvalues : 
    {}
  | nefieldvalues
    {};

nefieldvalues : fieldvalue
    {}
  | fieldvalues ',' fieldvalue
    {};

fieldvalue : identifier '=' exp
    {};

%%




TOKENS:

identifier : usual identifiers
;
intconst : usual integer constants
;
stringconst : usual string constants
;
meta : any string of the form <!-- ... -->
;
whatever : any string not containing < or >
;