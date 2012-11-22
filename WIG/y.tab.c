/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "wig.y"

#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern SERVICE* theservice;

void yyerror() {
   printf ("syntax error before %s\n", yytext); 
}


/* Line 189 of yacc.c  */
#line 85 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tSERVICE = 258,
     tCONST = 259,
     tHTML = 260,
     tHTMLTAGOPEN = 261,
     tHTMLTAGCLOSE = 262,
     tINPUT = 263,
     tSELECT = 264,
     tNAME = 265,
     tTYPE = 266,
     tTEXT = 267,
     tRADIO = 268,
     tSCHEMA = 269,
     tINT = 270,
     tBOOL = 271,
     tSTRING = 272,
     tVOID = 273,
     tSESSION = 274,
     tSHOW = 275,
     tEXIT = 276,
     tRETURN = 277,
     tIF = 278,
     tELSE = 279,
     tWHILE = 280,
     tPLUG = 281,
     tRECEIVE = 282,
     tTRUE = 283,
     tFALSE = 284,
     tTUPLE = 285,
     tGAPOPEN = 286,
     tGAPCLOSE = 287,
     tEQUALS = 288,
     tLTE = 289,
     tGTE = 290,
     tNEQ = 291,
     tKEEP = 292,
     tREMOVE = 293,
     tJOIN = 294,
     tOR = 295,
     tAND = 296,
     tINTCONST = 297,
     tIDENTIFIER = 298,
     tSTRINGCONST = 299,
     tWHATEVER = 300,
     tMETA = 301
   };
#endif
/* Tokens.  */
#define tSERVICE 258
#define tCONST 259
#define tHTML 260
#define tHTMLTAGOPEN 261
#define tHTMLTAGCLOSE 262
#define tINPUT 263
#define tSELECT 264
#define tNAME 265
#define tTYPE 266
#define tTEXT 267
#define tRADIO 268
#define tSCHEMA 269
#define tINT 270
#define tBOOL 271
#define tSTRING 272
#define tVOID 273
#define tSESSION 274
#define tSHOW 275
#define tEXIT 276
#define tRETURN 277
#define tIF 278
#define tELSE 279
#define tWHILE 280
#define tPLUG 281
#define tRECEIVE 282
#define tTRUE 283
#define tFALSE 284
#define tTUPLE 285
#define tGAPOPEN 286
#define tGAPCLOSE 287
#define tEQUALS 288
#define tLTE 289
#define tGTE 290
#define tNEQ 291
#define tKEEP 292
#define tREMOVE 293
#define tJOIN 294
#define tOR 295
#define tAND 296
#define tINTCONST 297
#define tIDENTIFIER 298
#define tSTRINGCONST 299
#define tWHATEVER 300
#define tMETA 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 16 "wig.y"

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



/* Line 214 of yacc.c  */
#line 244 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 256 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNRULES -- Number of states.  */
#define YYNSTATES  286

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    54,     2,     2,    63,     2,     2,
      55,    56,    62,    60,    57,    61,    65,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      51,    49,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    20,    22,    25,    34,    42,    44,
      47,    52,    57,    61,    63,    65,    70,    80,    89,    91,
      94,    98,   102,   108,   112,   118,   120,   121,   123,   125,
     128,   130,   134,   136,   140,   143,   145,   147,   149,   151,
     152,   154,   156,   159,   165,   166,   168,   170,   173,   177,
     179,   182,   186,   187,   189,   191,   194,   201,   203,   207,
     209,   211,   213,   215,   217,   219,   222,   223,   225,   227,
     231,   234,   236,   239,   245,   246,   248,   250,   253,   255,
     260,   264,   267,   271,   277,   285,   291,   293,   296,   298,
     304,   305,   310,   315,   319,   321,   325,   329,   330,   332,
     334,   338,   342,   346,   348,   352,   354,   358,   360,   364,
     368,   372,   376,   380,   384,   386,   390,   394,   396,   400,
     404,   408,   410,   414,   416,   420,   426,   430,   436,   438,
     441,   444,   446,   448,   453,   455,   457,   459,   463,   466,
     471,   475,   476,   478,   480,   484,   486,   490,   491,   493,
     495,   499
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,     3,    47,    68,    78,    84,    86,    96,
      48,    -1,     3,    47,    68,    78,    86,    96,    48,    -1,
      69,    -1,    68,    69,    -1,     4,     5,    90,    49,     6,
      70,     7,    50,    -1,     4,     5,    90,    49,     6,     7,
      50,    -1,    71,    -1,    70,    71,    -1,    51,    90,    74,
      52,    -1,    51,    53,    90,    52,    -1,    31,    90,    32,
      -1,    45,    -1,    46,    -1,    51,     8,    72,    52,    -1,
      51,     9,    72,    52,    70,    51,    53,     9,    52,    -1,
      51,     9,    72,    52,    51,    53,     9,    52,    -1,    73,
      -1,    72,    73,    -1,    10,    49,    77,    -1,    11,    49,
      12,    -1,    11,    49,    54,    12,    54,    -1,    11,    49,
      13,    -1,    11,    49,    54,    13,    54,    -1,    76,    -1,
      -1,    75,    -1,    76,    -1,    75,    76,    -1,    77,    -1,
      77,    49,    77,    -1,    90,    -1,    54,    44,    54,    -1,
      54,    54,    -1,    42,    -1,    10,    -1,    11,    -1,    13,
      -1,    -1,    79,    -1,    80,    -1,    79,    80,    -1,    14,
      90,    47,    81,    48,    -1,    -1,    82,    -1,    83,    -1,
      82,    83,    -1,    91,    90,    50,    -1,    85,    -1,    84,
      85,    -1,    92,    89,    50,    -1,    -1,    87,    -1,    88,
      -1,    87,    88,    -1,    92,    90,    55,    93,    56,   103,
      -1,    90,    -1,    89,    57,    90,    -1,    43,    -1,    15,
      -1,    16,    -1,    17,    -1,    18,    -1,    91,    -1,    30,
      90,    -1,    -1,    94,    -1,    95,    -1,    94,    57,    95,
      -1,    92,    90,    -1,    97,    -1,    96,    97,    -1,    19,
      90,    55,    56,   103,    -1,    -1,    99,    -1,   100,    -1,
      99,   100,    -1,    50,    -1,    20,   101,   102,    50,    -1,
      21,   101,    50,    -1,    22,    50,    -1,    22,   109,    50,
      -1,    23,    55,   109,    56,   100,    -1,    23,    55,   109,
      56,   100,    24,   100,    -1,    25,    55,   109,    56,   100,
      -1,   103,    -1,   109,    50,    -1,    90,    -1,    26,    90,
      58,   104,    59,    -1,    -1,    27,    58,   106,    59,    -1,
      47,    84,    98,    48,    -1,    47,    98,    48,    -1,   105,
      -1,   105,    57,   104,    -1,    90,    49,   109,    -1,    -1,
     107,    -1,   108,    -1,   107,    57,   108,    -1,   121,    49,
      90,    -1,   121,    49,   110,    -1,   110,    -1,   110,    40,
     111,    -1,   111,    -1,   111,    41,   112,    -1,   112,    -1,
     113,    33,   113,    -1,   113,    36,   113,    -1,   113,    51,
     113,    -1,   113,    52,   113,    -1,   113,    34,   113,    -1,
     113,    35,   113,    -1,   113,    -1,   113,    60,   114,    -1,
     113,    61,   114,    -1,   114,    -1,   114,    62,   115,    -1,
     114,    53,   115,    -1,   114,    63,   115,    -1,   115,    -1,
     116,    39,   115,    -1,   116,    -1,   116,    37,    90,    -1,
     116,    37,    55,    89,    56,    -1,   116,    38,    90,    -1,
     116,    38,    55,    89,    56,    -1,   117,    -1,    64,   118,
      -1,    61,   118,    -1,   118,    -1,   121,    -1,    90,    55,
     119,    56,    -1,    42,    -1,    28,    -1,    29,    -1,    54,
      44,    54,    -1,    54,    54,    -1,    30,    47,   122,    48,
      -1,    55,   109,    56,    -1,    -1,   120,    -1,   109,    -1,
     120,    57,   109,    -1,    90,    -1,    90,    65,    90,    -1,
      -1,   123,    -1,   124,    -1,   122,    57,   124,    -1,    90,
      49,   109,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    90,    93,    95,    98,   100,   103,   105,
     108,   110,   112,   114,   116,   118,   120,   122,   125,   127,
     130,   132,   134,   136,   138,   140,   145,   146,   149,   151,
     154,   156,   159,   161,   163,   165,   167,   169,   171,   175,
     176,   179,   181,   184,   188,   189,   192,   194,   197,   200,
     202,   205,   209,   210,   213,   215,   218,   224,   226,   229,
     232,   234,   236,   238,   241,   243,   249,   250,   253,   255,
     258,   261,   263,   266,   270,   271,   274,   276,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   300,   302,
     306,   307,   310,   312,   315,   317,   320,   324,   325,   328,
     330,   333,   336,   338,   341,   343,   346,   348,   351,   353,
     355,   357,   359,   361,   363,   366,   368,   370,   373,   375,
     377,   379,   382,   384,   387,   389,   391,   393,   395,   398,
     400,   402,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   425,   426,   429,   431,   434,   436,   440,   441,   444,
     446,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tSERVICE", "tCONST", "tHTML",
  "tHTMLTAGOPEN", "tHTMLTAGCLOSE", "tINPUT", "tSELECT", "tNAME", "tTYPE",
  "tTEXT", "tRADIO", "tSCHEMA", "tINT", "tBOOL", "tSTRING", "tVOID",
  "tSESSION", "tSHOW", "tEXIT", "tRETURN", "tIF", "tELSE", "tWHILE",
  "tPLUG", "tRECEIVE", "tTRUE", "tFALSE", "tTUPLE", "tGAPOPEN",
  "tGAPCLOSE", "tEQUALS", "tLTE", "tGTE", "tNEQ", "tKEEP", "tREMOVE",
  "tJOIN", "tOR", "tAND", "tINTCONST", "tIDENTIFIER", "tSTRINGCONST",
  "tWHATEVER", "tMETA", "'{'", "'}'", "'='", "';'", "'<'", "'>'", "'/'",
  "'\"'", "'('", "')'", "','", "'['", "']'", "'+'", "'-'", "'*'", "'%'",
  "'!'", "'.'", "$accept", "service", "htmls", "html", "nehtmlbodies",
  "htmlbody", "inputattrs", "inputattr", "attributes", "neattributes",
  "attribute", "attr", "schemas", "neschemas", "schema", "fields",
  "nefields", "field", "nevariables", "variable", "functions",
  "nefunctions", "function", "identifiers", "identifier", "simpletype",
  "type", "arguments", "nearguments", "argument", "sessions", "session",
  "stms", "nestms", "stm", "document", "receive", "compoundstm", "plugs",
  "plug", "inputs", "neinputs", "input", "exp", "or_exp", "and_exp",
  "cmp_exp", "add_exp", "mult_exp", "join_exp", "tuple_exp", "unary_exp",
  "base_exp", "exps", "neexps", "lvalue", "fieldvalues", "nefieldvalues",
  "fieldvalue", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   123,   125,    61,
      59,    60,    62,    47,    34,    40,    41,    44,    91,    93,
      43,    45,    42,    37,    33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    81,    81,    82,    82,    83,    84,
      84,    85,    86,    86,    87,    87,    88,    89,    89,    90,
      91,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   106,   106,   107,
     107,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     1,     2,     8,     7,     1,     2,
       4,     4,     3,     1,     1,     4,     9,     8,     1,     2,
       3,     3,     5,     3,     5,     1,     0,     1,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     1,     1,     0,
       1,     1,     2,     5,     0,     1,     1,     2,     3,     1,
       2,     3,     0,     1,     1,     2,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     0,     1,     1,     3,
       2,     1,     2,     5,     0,     1,     1,     2,     1,     4,
       3,     2,     3,     5,     7,     5,     1,     2,     1,     5,
       0,     4,     4,     3,     1,     3,     3,     0,     1,     1,
       3,     3,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     3,     5,     3,     5,     1,     2,
       2,     1,     1,     4,     1,     1,     1,     3,     2,     4,
       3,     0,     1,     1,     3,     1,     3,     0,     1,     1,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    39,     4,     0,     0,
       5,    52,    40,    41,    59,     0,     0,    60,    61,    62,
      63,     0,    52,    49,     0,    53,    54,    64,     0,    42,
       0,    44,    65,    50,     0,     0,     0,    71,    55,     0,
       0,    57,     0,     0,    45,    46,     0,     0,     0,     3,
      72,     0,    51,     0,    66,     0,     0,    13,    14,     0,
       0,     8,    43,    47,     0,     2,     0,    58,     0,     0,
      67,    68,     7,     0,     0,     0,     0,    26,     0,     9,
      48,     0,    70,     0,     0,    12,    36,    37,    38,    35,
       0,     0,    18,    25,    30,    32,     0,     0,    36,    37,
       0,    27,    28,     6,    74,    73,    56,    69,     0,     0,
       0,    34,    15,    19,     0,     0,    11,    10,    29,     0,
       0,     0,     0,     0,   135,   136,     0,   134,    78,     0,
       0,     0,     0,    74,   145,     0,     0,    75,    76,    86,
       0,   103,   105,   107,   114,   117,   121,   123,   128,   131,
     132,    20,    21,    23,     0,    33,    31,     0,     0,     0,
      88,    90,     0,     0,    81,     0,     0,     0,   147,     0,
     138,     0,   130,   132,   129,     0,   141,     0,    57,    93,
      77,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    82,     0,     0,
       0,     0,   148,   149,   137,   140,    92,   143,     0,   142,
     146,   104,   106,   108,   112,   113,   109,   110,   111,   115,
     116,   119,   118,   120,     0,   124,     0,   126,   122,   102,
      22,    24,     0,     0,     0,    97,    79,     0,     0,     0,
     139,     0,   133,     0,     0,     0,    17,     0,     0,     0,
      94,   145,     0,    98,    99,     0,    83,    85,   151,   150,
     144,   125,   127,    16,     0,    89,     0,    91,     0,     0,
       0,    96,    95,   100,   101,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    60,    61,    91,    92,   100,   101,
      93,    94,    11,    12,    13,    43,    44,    45,    22,    23,
      24,    25,    26,    40,   134,    27,    28,    69,    70,    71,
      36,    37,   136,   137,   138,   161,   205,   139,   259,   260,
     262,   263,   264,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   218,   219,   173,   211,   212,   213
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
      91,    50,   102,   133,  -135,   154,    -2,  -135,    99,    99,
    -135,    92,   175,  -135,  -135,   151,   155,  -135,  -135,  -135,
    -135,    99,    92,  -135,   185,    92,  -135,  -135,    99,  -135,
     209,   167,  -135,  -135,   185,    99,   -13,  -135,  -135,    99,
      88,   172,   150,   181,   167,  -135,    99,    -1,   184,  -135,
    -135,   172,  -135,    99,    92,   190,    99,  -135,  -135,     6,
     179,  -135,  -135,  -135,   192,  -135,   188,  -135,    99,   194,
     196,  -135,  -135,   215,   137,   137,    99,   238,   204,  -135,
    -135,   213,  -135,   213,    92,  -135,   214,   218,  -135,  -135,
      80,    74,  -135,  -135,   220,  -135,   110,   221,  -135,  -135,
     222,   238,  -135,  -135,   191,  -135,  -135,  -135,   238,    10,
     230,  -135,  -135,  -135,   238,   -12,  -135,  -135,  -135,   -19,
     -19,   259,   217,   239,  -135,  -135,   111,  -135,  -135,    81,
     275,   101,   101,   191,    17,    99,   227,   236,  -135,  -135,
     235,   253,   254,  -135,    44,    36,  -135,   138,  -135,  -135,
     247,  -135,  -135,  -135,    62,  -135,  -135,    28,   231,    99,
    -135,   271,   249,   260,  -135,   256,   275,   275,    99,   257,
    -135,   252,  -135,  -135,  -135,   262,   275,    99,  -135,  -135,
    -135,  -135,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   -27,    18,   275,   275,   258,
     261,     0,    33,   263,   264,   266,  -135,  -135,   268,   269,
     270,    84,  -135,  -135,  -135,  -135,  -135,  -135,   272,   274,
    -135,   254,  -135,    -4,    -4,    -4,    -4,    -4,    -4,    36,
      36,  -135,  -135,  -135,    99,  -135,    99,  -135,  -135,   253,
    -135,  -135,   280,     1,    99,    99,  -135,   236,   236,   275,
    -135,    99,  -135,   275,   141,   161,  -135,   281,   277,   276,
     289,   273,   278,   290,  -135,   285,   303,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,   275,  -135,    99,  -135,    99,    99,
     236,  -135,  -135,  -135,  -135,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   342,   234,   -55,   279,   -66,  -135,  -135,
     -51,    25,  -135,  -135,   338,  -135,  -135,   307,   248,   -18,
     331,  -135,   330,   -71,    -8,    21,   -14,  -135,  -135,   282,
     322,   -15,   224,  -135,  -134,   240,  -135,   109,    82,  -135,
    -135,  -135,    83,  -113,   164,   177,   180,   156,    32,   -26,
    -135,  -135,   100,  -135,  -135,   -75,  -135,  -135,   113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      15,    16,     5,   180,    33,    79,    35,   159,   165,   242,
     257,    39,     9,    32,    74,    75,    14,   171,    35,    56,
      41,    50,   152,   153,    14,   113,   102,    48,   234,   150,
     113,    51,    50,    57,    58,    49,    74,    75,    64,   157,
      68,    74,    75,    14,    14,    67,   150,    65,    73,    14,
     118,    77,    46,   208,   209,   150,   190,   191,   150,    76,
      82,    14,   150,   217,   154,    46,    95,    95,    97,    95,
      68,    14,   176,   236,   199,   200,    14,   184,   185,   186,
     187,   201,   177,    95,    86,    87,   243,    88,    95,   192,
     135,   150,   150,    95,     1,   188,   189,     3,   193,   194,
      95,   150,     4,    79,   190,   191,    95,    17,    18,    19,
      20,   160,   160,   266,   267,    33,    89,    14,    32,   135,
      86,    87,    21,    88,   110,   169,   112,   178,    90,   124,
     125,   163,   250,   151,   111,   170,   268,     5,    52,   156,
     270,   251,    14,   127,    14,    53,   285,    86,    87,    77,
      88,   203,    89,    14,    14,   129,   130,    55,   168,     8,
     210,   281,   115,   254,    90,   255,   231,   232,   233,   220,
     265,   238,   150,   150,   150,   195,   196,   197,   150,    89,
      14,    56,    17,    18,    19,    20,    78,   235,   237,     9,
     105,    90,   106,    97,    77,    57,    58,   271,    53,   150,
      30,    59,    31,   265,    35,   150,    17,    18,    19,    20,
      56,   119,   120,   121,   122,    42,   123,   272,    53,   124,
     125,   126,   229,   230,    57,    58,   178,    54,   178,    62,
      59,   172,   174,   127,    14,    97,   258,   261,   104,    66,
      72,   128,    80,   210,    81,   129,   130,    85,    98,    99,
      83,    88,   131,    84,   103,   132,   119,   120,   121,   122,
     104,   123,    56,   108,   124,   125,   163,   109,   258,   114,
     261,   284,   166,   116,   117,   179,    57,    58,   127,    14,
      89,    14,   202,   104,   155,   181,   128,   124,   125,   163,
     129,   130,    90,   182,   167,   183,   198,   131,   204,   206,
     132,   127,    14,   124,   125,   163,   207,   168,   215,   164,
     216,   214,   240,   129,   130,   241,   246,   127,    14,   249,
     131,   244,   245,   132,   247,   248,   274,   280,   252,   129,
     130,   253,   256,   273,   279,   275,   131,   277,   177,   132,
     223,   224,   225,   226,   227,   228,   276,   278,    10,   158,
      29,    63,   133,    34,    96,    38,    47,   175,   282,   221,
     162,   283,   239,   222,   269,     0,   107
};

static const yytype_int16 yycheck[] =
{
       8,     9,     4,   137,    22,    60,    19,    26,   121,     9,
       9,    25,    14,    21,     8,     9,    43,   130,    19,    31,
      28,    36,    12,    13,    43,    91,    77,    35,    55,   104,
      96,    39,    47,    45,    46,    48,     8,     9,    46,    51,
      54,     8,     9,    43,    43,    53,   121,    48,    56,    43,
     101,    59,    31,   166,   167,   130,    60,    61,   133,    53,
      68,    43,   137,   176,    54,    44,    74,    75,    76,    77,
      84,    43,    55,    55,    12,    13,    43,    33,    34,    35,
      36,    53,    65,    91,    10,    11,    53,    13,    96,    53,
     104,   166,   167,   101,     3,    51,    52,    47,    62,    63,
     108,   176,     0,   158,    60,    61,   114,    15,    16,    17,
      18,   119,   120,   247,   248,   133,    42,    43,   126,   133,
      10,    11,    30,    13,    44,    44,    52,   135,    54,    28,
      29,    30,    48,   108,    54,    54,   249,     4,    50,   114,
     253,    57,    43,    42,    43,    57,   280,    10,    11,   157,
      13,   159,    42,    43,    43,    54,    55,     7,    47,     5,
     168,   274,    52,   234,    54,   236,   192,   193,   194,   177,
     245,   197,   247,   248,   249,    37,    38,    39,   253,    42,
      43,    31,    15,    16,    17,    18,     7,   195,   196,    14,
      81,    54,    83,   201,   202,    45,    46,    56,    57,   274,
      49,    51,    47,   278,    19,   280,    15,    16,    17,    18,
      31,    20,    21,    22,    23,     6,    25,    56,    57,    28,
      29,    30,   190,   191,    45,    46,   234,    55,   236,    48,
      51,   131,   132,    42,    43,   243,   244,   245,    47,    55,
      50,    50,    50,   251,    56,    54,    55,    32,    10,    11,
      56,    13,    61,    57,    50,    64,    20,    21,    22,    23,
      47,    25,    31,    49,    28,    29,    30,    49,   276,    49,
     278,   279,    55,    52,    52,    48,    45,    46,    42,    43,
      42,    43,    51,    47,    54,    50,    50,    28,    29,    30,
      54,    55,    54,    40,    55,    41,    49,    61,    27,    50,
      64,    42,    43,    28,    29,    30,    50,    47,    56,    50,
      48,    54,    54,    54,    55,    54,    50,    42,    43,    49,
      61,    58,    58,    64,    56,    56,    49,    24,    56,    54,
      55,    57,    52,    52,    49,    59,    61,    59,    65,    64,
     184,   185,   186,   187,   188,   189,    57,    57,     6,   115,
      12,    44,   104,    22,    75,    25,    34,   133,   276,   182,
     120,   278,   198,   183,   251,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    67,    47,     0,     4,    68,    69,     5,    14,
      69,    78,    79,    80,    43,    90,    90,    15,    16,    17,
      18,    30,    84,    85,    86,    87,    88,    91,    92,    80,
      49,    47,    90,    85,    86,    19,    96,    97,    88,    92,
      89,    90,     6,    81,    82,    83,    91,    96,    90,    48,
      97,    90,    50,    57,    55,     7,    31,    45,    46,    51,
      70,    71,    48,    83,    90,    48,    55,    90,    92,    93,
      94,    95,    50,    90,     8,     9,    53,    90,     7,    71,
      50,    56,    90,    56,    57,    32,    10,    11,    13,    42,
      54,    72,    73,    76,    77,    90,    72,    90,    10,    11,
      74,    75,    76,    50,    47,   103,   103,    95,    49,    49,
      44,    54,    52,    73,    49,    52,    52,    52,    76,    20,
      21,    22,    23,    25,    28,    29,    30,    42,    50,    54,
      55,    61,    64,    84,    90,    92,    98,    99,   100,   103,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     121,    77,    12,    13,    54,    54,    77,    51,    70,    26,
      90,   101,   101,    30,    50,   109,    55,    55,    47,    44,
      54,   109,   118,   121,   118,    98,    55,    65,    90,    48,
     100,    50,    40,    41,    33,    34,    35,    36,    51,    52,
      60,    61,    53,    62,    63,    37,    38,    39,    49,    12,
      13,    53,    51,    90,    27,   102,    50,    50,   109,   109,
      90,   122,   123,   124,    54,    56,    48,   109,   119,   120,
      90,   111,   112,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   115,    55,    90,    55,    90,   115,   110,
      54,    54,     9,    53,    58,    58,    50,    56,    56,    49,
      48,    57,    56,    57,    89,    89,    52,     9,    90,   104,
     105,    90,   106,   107,   108,   121,   100,   100,   109,   124,
     109,    56,    56,    52,    49,    59,    57,    59,    57,    49,
      24,   109,   104,   108,    90,   100
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 89 "wig.y"
    {theservice = makeSERVICE((yyvsp[(3) - (8)].html), (yyvsp[(4) - (8)].schema), (yyvsp[(5) - (8)].variable), (yyvsp[(6) - (8)].function), (yyvsp[(7) - (8)].session));}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 91 "wig.y"
    {theservice = makeSERVICE((yyvsp[(3) - (7)].html), (yyvsp[(4) - (7)].schema), NULL, (yyvsp[(5) - (7)].function), (yyvsp[(6) - (7)].session));}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 94 "wig.y"
    {(yyval.html) = (yyvsp[(1) - (1)].html);}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 96 "wig.y"
    {(yyval.html) = (yyvsp[(2) - (2)].html); (yyval.html)->next = (yyvsp[(1) - (2)].html);}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 99 "wig.y"
    {(yyval.html) = makeHTML((yyvsp[(3) - (8)].id), (yyvsp[(6) - (8)].htmlbody));}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 101 "wig.y"
    {(yyval.html) = makeHTML((yyvsp[(3) - (7)].id), NULL);}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 104 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(1) - (1)].htmlbody);}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 106 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(2) - (2)].htmlbody); (yyval.htmlbody)->next = (yyvsp[(1) - (2)].htmlbody);}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 109 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(2) - (4)].id), (yyvsp[(3) - (4)].attribute));}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 111 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(3) - (4)].id), NULL);}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 113 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYgap((yyvsp[(2) - (3)].id));}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 115 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYwhatever((yyvsp[(1) - (1)].stringconst));}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 117 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYmeta((yyvsp[(1) - (1)].stringconst));}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 119 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYinput((yyvsp[(3) - (4)].inputattr));}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 121 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYselect((yyvsp[(3) - (9)].inputattr), (yyvsp[(5) - (9)].htmlbody));}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 123 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYselect((yyvsp[(3) - (8)].inputattr), NULL);}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 126 "wig.y"
    {(yyval.inputattr) = (yyvsp[(1) - (1)].inputattr);}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 128 "wig.y"
    {(yyval.inputattr) = (yyvsp[(2) - (2)].inputattr); (yyval.inputattr)->next = (yyvsp[(1) - (2)].inputattr);}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 131 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRname((yyvsp[(3) - (3)].attr));}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 133 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 135 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 137 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 139 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 141 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRattribute((yyvsp[(1) - (1)].attribute));}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 145 "wig.y"
    {(yyval.attribute) = NULL;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 147 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 150 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 152 "wig.y"
    {(yyval.attribute) = (yyvsp[(2) - (2)].attribute); (yyval.attribute)->next = (yyvsp[(1) - (2)].attribute);}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 155 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (1)].attr), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 157 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 160 "wig.y"
    {(yyval.attr) = makeATTRid((yyvsp[(1) - (1)].id));}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 162 "wig.y"
    {(yyval.attr) = makeATTRstringconst((yyvsp[(2) - (3)].stringconst));}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 164 "wig.y"
    {(yyval.attr) = makeATTRstringconst("");}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 166 "wig.y"
    {(yyval.attr) = makeATTRintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 168 "wig.y"
    {(yyval.attr) = makeATTRstringconst("name");}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 170 "wig.y"
    {(yyval.attr) = makeATTRstringconst("type");}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 172 "wig.y"
    {(yyval.attr) = makeATTRstringconst("radio");}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 175 "wig.y"
    {(yyval.schema) = NULL;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 177 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 180 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 182 "wig.y"
    {(yyval.schema) = (yyvsp[(2) - (2)].schema); (yyval.schema)->next = (yyvsp[(1) - (2)].schema);}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 185 "wig.y"
    {(yyval.schema) = makeSCHEMA((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].field));}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 188 "wig.y"
    {(yyval.field) = NULL;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 190 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 193 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 195 "wig.y"
    {(yyval.field) = (yyvsp[(2) - (2)].field); (yyval.field)->next = (yyvsp[(1) - (2)].field);}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 198 "wig.y"
    {(yyval.field) = makeFIELD((yyvsp[(1) - (3)].simpletype), (yyvsp[(2) - (3)].id));}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 201 "wig.y"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 203 "wig.y"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); (yyval.variable)->next = (yyvsp[(1) - (2)].variable);}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 206 "wig.y"
    {(yyval.variable) = makeVARIABLE((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].id));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 209 "wig.y"
    {(yyval.function) = NULL;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 211 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 214 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 216 "wig.y"
    {(yyval.function) = (yyvsp[(2) - (2)].function); (yyval.function)->next = (yyvsp[(1) - (2)].function);}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 219 "wig.y"
    {(yyval.function) = makeFUNCTION((yyvsp[(1) - (6)].type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].argument), (yyvsp[(6) - (6)].compoundstm));}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 225 "wig.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 227 "wig.y"
    {(yyval.id) = (yyvsp[(3) - (3)].id); (yyval.id)->next = (yyvsp[(1) - (3)].id);}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 230 "wig.y"
    {(yyval.id) = makeID((yyvsp[(1) - (1)].stringconst));}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 233 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEint();}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 235 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEbool();}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 237 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEstring();}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 239 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEvoid();}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 242 "wig.y"
    {(yyval.type) = makeTYPEsimpletype((yyvsp[(1) - (1)].simpletype));}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 244 "wig.y"
    {(yyval.type) = makeTYPEtupleid((yyvsp[(2) - (2)].id));}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 249 "wig.y"
    {(yyval.argument) = NULL;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 251 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 254 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 256 "wig.y"
    {(yyval.argument) = (yyvsp[(3) - (3)].argument); (yyval.argument)->next = (yyvsp[(1) - (3)].argument);}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 259 "wig.y"
    {(yyval.argument) = makeARGUMENT((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].id));}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 262 "wig.y"
    {(yyval.session) = (yyvsp[(1) - (1)].session);}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 264 "wig.y"
    {(yyval.session) = (yyvsp[(2) - (2)].session); (yyval.session)->next = (yyvsp[(1) - (2)].session);}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 267 "wig.y"
    {(yyval.session) = makeSESSION((yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].compoundstm));}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 270 "wig.y"
    {(yyval.statement) = NULL;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 272 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 275 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 277 "wig.y"
    {(yyval.statement) = (yyvsp[(2) - (2)].statement); (yyval.statement)->next = (yyvsp[(1) - (2)].statement);}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 280 "wig.y"
    {(yyval.statement) = makeSTMsemicolon();}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 282 "wig.y"
    {(yyval.statement) = makeSTMshow((yyvsp[(2) - (4)].document), (yyvsp[(3) - (4)].receive));}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 284 "wig.y"
    {(yyval.statement) = makeSTMexit((yyvsp[(2) - (3)].document));}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 286 "wig.y"
    {(yyval.statement) = makeSTMreturn();}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 288 "wig.y"
    {(yyval.statement) = makeSTMreturnexpr((yyvsp[(2) - (3)].exp));}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 290 "wig.y"
    {(yyval.statement) = makeSTMif((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 292 "wig.y"
    {(yyval.statement) = makeSTMifelse((yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 294 "wig.y"
    {(yyval.statement) = makeSTMwhile((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 296 "wig.y"
    {(yyval.statement) = makeSTMcompound((yyvsp[(1) - (1)].compoundstm));}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 298 "wig.y"
    {(yyval.statement) = makeSTMexp((yyvsp[(1) - (2)].exp));}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 301 "wig.y"
    {(yyval.document) = makeDOCUMENTid((yyvsp[(1) - (1)].id));}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 303 "wig.y"
    {(yyval.document) = makeDOCUMENTplug((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].plug));}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 306 "wig.y"
    {(yyval.receive) = makeRECEIVE(NULL);}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 308 "wig.y"
    {(yyval.receive) = makeRECEIVE((yyvsp[(3) - (4)].input));}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 311 "wig.y"
    {(yyval.compoundstm) = makeCOMPOUNDSTM((yyvsp[(2) - (4)].variable), (yyvsp[(3) - (4)].statement));}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 313 "wig.y"
    {(yyval.compoundstm) = makeCOMPOUNDSTM(NULL, (yyvsp[(2) - (3)].statement));}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 316 "wig.y"
    {(yyval.plug) = (yyvsp[(1) - (1)].plug);}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 318 "wig.y"
    {(yyval.plug) = (yyvsp[(1) - (3)].plug); (yyval.plug)->next = (yyvsp[(3) - (3)].plug);}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 321 "wig.y"
    {(yyval.plug) = makePLUG((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 324 "wig.y"
    {(yyval.input) = NULL;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 326 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 329 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 331 "wig.y"
    {(yyval.input) = (yyvsp[(3) - (3)].input); (yyval.input)->next = (yyvsp[(1) - (3)].input);}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 334 "wig.y"
    {(yyval.input) = makeINPUT((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].id));}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 337 "wig.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].exp));}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 339 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 342 "wig.y"
    {(yyval.exp) = makeEXPor((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 344 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 347 "wig.y"
    {(yyval.exp) = makeEXPand((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 349 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 352 "wig.y"
    {(yyval.exp) = makeEXPequals((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 354 "wig.y"
    {(yyval.exp) = makeEXPnotequals((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 356 "wig.y"
    {(yyval.exp) = makeEXPlt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 358 "wig.y"
    {(yyval.exp) = makeEXPgt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 360 "wig.y"
    {(yyval.exp) = makeEXPlte((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 362 "wig.y"
    {(yyval.exp) = makeEXPgte((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 364 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 367 "wig.y"
    {(yyval.exp) = makeEXPplus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 369 "wig.y"
    {(yyval.exp) = makeEXPminus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 371 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 374 "wig.y"
    {(yyval.exp) = makeEXPmult((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 376 "wig.y"
    {(yyval.exp) = makeEXPdiv((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 378 "wig.y"
    {(yyval.exp) = makeEXPmod((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 380 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 383 "wig.y"
    {(yyval.exp) = makeEXPjoin((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 385 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 388 "wig.y"
    {(yyval.exp) = makeEXPkeep((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].id));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 390 "wig.y"
    {(yyval.exp) = makeEXPkeep((yyvsp[(1) - (5)].exp), (yyvsp[(4) - (5)].id));}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 392 "wig.y"
    {(yyval.exp) = makeEXPremove((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].id));}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 394 "wig.y"
    {(yyval.exp) = makeEXPremove((yyvsp[(1) - (5)].exp), (yyvsp[(4) - (5)].id));}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 396 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 399 "wig.y"
    {(yyval.exp) = makeEXPnot((yyvsp[(2) - (2)].exp));}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 401 "wig.y"
    {(yyval.exp) = makeEXPminus(makeEXPintconst(0), (yyvsp[(2) - (2)].exp));}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 403 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 406 "wig.y"
    {(yyval.exp) = makeEXPlvalue((yyvsp[(1) - (1)].lvalue));}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 408 "wig.y"
    {(yyval.exp) = makeEXPcall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].exp));}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 410 "wig.y"
    {(yyval.exp) = makeEXPintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 412 "wig.y"
    {(yyval.exp) = makeEXPtrue();}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 414 "wig.y"
    {(yyval.exp) = makeEXPfalse();}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 416 "wig.y"
    {(yyval.exp) = makeEXPstringconst((yyvsp[(2) - (3)].stringconst));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 418 "wig.y"
    {(yyval.exp) = makeEXPstringconst("");}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 420 "wig.y"
    {(yyval.exp) = makeEXPtuple((yyvsp[(3) - (4)].fieldvalue));}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 422 "wig.y"
    {(yyval.exp) = makeEXPparen((yyvsp[(2) - (3)].exp));}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 425 "wig.y"
    {(yyval.exp) = NULL;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 427 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 430 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 432 "wig.y"
    {(yyval.exp) = (yyvsp[(3) - (3)].exp); (yyval.exp)->next = (yyvsp[(1) - (3)].exp);}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 435 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (1)].id), NULL);}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 437 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 440 "wig.y"
    {(yyval.fieldvalue) = NULL;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 442 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 445 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 447 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(3) - (3)].fieldvalue); (yyval.fieldvalue)->next = (yyvsp[(1) - (3)].fieldvalue);}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 450 "wig.y"
    {(yyval.fieldvalue) = makeFIELDVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;



/* Line 1464 of yacc.c  */
#line 2797 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 452 "wig.y"


