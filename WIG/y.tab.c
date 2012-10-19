/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "wig.y"

#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern SERVICE* theservice;

void yyerror() {
   printf ("syntax error before %s\n", yytext); 
}


/* Line 268 of yacc.c  */
#line 84 "y.tab.c"

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
     tINTCONST = 288,
     tIDENTIFIER = 289,
     tSTRINGCONST = 290,
     tWHATEVER = 291,
     tMETA = 292
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
#define tINTCONST 288
#define tIDENTIFIER 289
#define tSTRINGCONST 290
#define tWHATEVER 291
#define tMETA 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 225 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 237 "y.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    45,     2,     2,    58,    59,     2,
      48,    49,    57,    56,    46,    55,    62,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      42,    40,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,    61,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    60,    39,     2,     2,     2,     2,
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
      35,    36,    37,    47,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    17,    26,    27,    29,    31,
      34,    39,    44,    48,    50,    52,    57,    67,    69,    72,
      76,    80,    86,    90,    96,    98,    99,   101,   103,   106,
     108,   112,   114,   118,   120,   121,   123,   125,   128,   134,
     135,   137,   139,   142,   146,   147,   149,   151,   154,   158,
     160,   164,   166,   168,   170,   172,   174,   176,   179,   180,
     182,   184,   187,   194,   195,   197,   199,   203,   206,   208,
     211,   217,   218,   220,   222,   225,   227,   232,   236,   239,
     243,   249,   257,   263,   265,   268,   270,   276,   277,   282,
     287,   289,   293,   297,   298,   300,   302,   306,   310,   312,
     316,   320,   324,   328,   332,   337,   342,   345,   348,   352,
     356,   360,   364,   368,   373,   378,   383,   388,   393,   398,
     400,   402,   404,   406,   411,   412,   414,   416,   420,   422,
     426,   427,   429,   431,   435
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,     3,    38,    65,    76,    82,    89,    95,
      39,    -1,    66,    -1,    65,    66,    -1,     4,     5,    86,
      40,     6,    67,     7,    41,    -1,    -1,    68,    -1,    69,
      -1,    68,    69,    -1,    42,    86,    72,    43,    -1,    42,
      44,    86,    43,    -1,    31,    86,    32,    -1,    36,    -1,
      37,    -1,    42,     8,    70,    43,    -1,    42,     9,    70,
      43,    67,    42,    44,     9,    43,    -1,    71,    -1,    70,
      71,    -1,    10,    40,    75,    -1,    11,    40,    12,    -1,
      11,    40,    45,    12,    45,    -1,    11,    40,    13,    -1,
      11,    40,    45,    13,    45,    -1,    74,    -1,    -1,    73,
      -1,    74,    -1,    73,    74,    -1,    75,    -1,    75,    40,
      75,    -1,    86,    -1,    45,    35,    45,    -1,    33,    -1,
      -1,    77,    -1,    78,    -1,    77,    78,    -1,    14,    86,
      38,    79,    39,    -1,    -1,    80,    -1,    81,    -1,    80,
      81,    -1,    87,    86,    41,    -1,    -1,    83,    -1,    84,
      -1,    83,    84,    -1,    88,    85,    41,    -1,    86,    -1,
      85,    46,    86,    -1,    34,    -1,    15,    -1,    16,    -1,
      17,    -1,    18,    -1,    87,    -1,    47,    86,    -1,    -1,
      90,    -1,    91,    -1,    90,    91,    -1,    88,    86,    48,
      92,    49,   102,    -1,    -1,    93,    -1,    94,    -1,    93,
      46,    94,    -1,    88,    86,    -1,    96,    -1,    95,    96,
      -1,    19,    86,    48,    49,   102,    -1,    -1,    98,    -1,
      99,    -1,    98,    99,    -1,    41,    -1,    20,   100,   101,
      41,    -1,    21,   100,    41,    -1,    22,    41,    -1,    22,
     108,    41,    -1,    23,    48,   108,    49,    99,    -1,    23,
      48,   108,    49,    99,    24,    99,    -1,    25,    48,   108,
      49,    99,    -1,   102,    -1,   108,    41,    -1,    86,    -1,
      26,    86,    50,   103,    51,    -1,    -1,    27,    50,   105,
      51,    -1,    38,    82,    97,    39,    -1,   104,    -1,   103,
      46,   104,    -1,    86,    40,   108,    -1,    -1,   106,    -1,
     107,    -1,   106,    46,   107,    -1,   111,    40,    86,    -1,
     111,    -1,   111,    40,   108,    -1,   108,    52,   108,    -1,
     108,    53,   108,    -1,   108,    42,   108,    -1,   108,    43,
     108,    -1,   108,    42,    40,   108,    -1,   108,    43,    40,
     108,    -1,    54,   108,    -1,    55,   108,    -1,   108,    56,
     108,    -1,   108,    55,   108,    -1,   108,    57,   108,    -1,
     108,    44,   108,    -1,   108,    58,   108,    -1,   108,    59,
      59,   108,    -1,   108,    60,    60,   108,    -1,   108,    42,
      42,   108,    -1,   108,    61,    56,    85,    -1,   108,    61,
      55,    85,    -1,    86,    48,   109,    49,    -1,    33,    -1,
      28,    -1,    29,    -1,    35,    -1,    30,    38,   112,    39,
      -1,    -1,   110,    -1,   108,    -1,   110,    46,   108,    -1,
      86,    -1,    86,    62,    86,    -1,    -1,   113,    -1,   114,
      -1,   112,    46,   114,    -1,    86,    40,   108,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    95,    97,   100,   104,   105,   108,   110,
     113,   115,   117,   119,   121,   123,   125,   128,   130,   133,
     135,   137,   139,   141,   143,   148,   149,   152,   154,   157,
     159,   162,   164,   166,   170,   171,   174,   176,   179,   183,
     184,   187,   189,   192,   196,   197,   200,   202,   205,   208,
     210,   213,   216,   218,   220,   222,   225,   227,   231,   232,
     235,   237,   240,   244,   245,   248,   250,   253,   256,   258,
     261,   265,   266,   269,   271,   274,   276,   278,   280,   282,
     284,   286,   288,   290,   292,   295,   297,   301,   302,   305,
     308,   310,   313,   317,   318,   321,   323,   326,   329,   331,
     333,   335,   337,   339,   341,   343,   345,   347,   349,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   384,   385,   388,   390,   393,   395,
     399,   400,   403,   405,   408
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
  "tGAPCLOSE", "tINTCONST", "tIDENTIFIER", "tSTRINGCONST", "tWHATEVER",
  "tMETA", "'{'", "'}'", "'='", "';'", "'<'", "'>'", "'/'", "'\"'", "','",
  "\"tuple\"", "'('", "')'", "'['", "']'", "\"==\"", "\"!=\"", "'!'",
  "'-'", "'+'", "'*'", "'%'", "'&'", "'|'", "'\\\\'", "'.'", "$accept",
  "service", "htmls", "html", "htmlbodies", "nehtmlbodies", "htmlbody",
  "inputattrs", "inputattr", "attributes", "neattributes", "attribute",
  "attr", "schemas", "neschemas", "schema", "fields", "nefields", "field",
  "variables", "nevariables", "variable", "identifiers", "identifier",
  "simpletype", "type", "functions", "nefunctions", "function",
  "arguments", "nearguments", "argument", "sessions", "session", "stms",
  "nestms", "stm", "document", "receive", "compoundstm", "plugs", "plug",
  "inputs", "neinputs", "input", "exp", "exps", "neexps", "lvalue",
  "fieldvalues", "nefieldvalues", "fieldvalue", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   123,   125,
      61,    59,    60,    62,    47,    34,    44,   293,    40,    41,
      91,    93,   294,   295,    33,    45,    43,    42,    37,    38,
     124,    92,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    81,    82,    82,    83,    83,    84,    85,
      85,    86,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    92,    92,    93,    93,    94,    95,    95,
      96,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   101,   101,   102,
     103,   103,   104,   105,   105,   106,   106,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     2,     8,     0,     1,     1,     2,
       4,     4,     3,     1,     1,     4,     9,     1,     2,     3,
       3,     5,     3,     5,     1,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     0,     1,     1,     2,     5,     0,
       1,     1,     2,     3,     0,     1,     1,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     2,     6,     0,     1,     1,     3,     2,     1,     2,
       5,     0,     1,     1,     2,     1,     4,     3,     2,     3,
       5,     7,     5,     1,     2,     1,     5,     0,     4,     4,
       1,     3,     3,     0,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     4,     4,     2,     2,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     4,     0,     1,     1,     3,     1,     3,
       0,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    34,     3,     0,     0,
       4,    44,    35,    36,    51,     0,     0,    52,    53,    54,
      55,     0,    58,    45,    46,    56,     0,    37,     0,    39,
      57,     0,     0,    59,    60,    47,     0,    49,     6,     0,
      40,    41,     0,     0,     0,     0,    68,    61,    48,     0,
       0,    13,    14,     0,     0,     7,     8,    38,    42,     0,
      63,     0,     2,    69,    50,     0,     0,     0,     0,    25,
       0,     9,    43,     0,     0,    64,    65,     0,    12,     0,
       0,    33,     0,     0,    17,    24,    29,    31,     0,     0,
       0,    26,    27,     5,    67,     0,     0,     0,     0,     0,
       0,    15,    18,     0,     0,    11,    10,    28,    44,    62,
      66,    70,    19,    20,    22,     0,    32,    30,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
       0,   119,   122,    75,     0,     0,   128,     0,    72,    73,
      83,     0,    98,    21,    23,     0,     0,    85,    87,     0,
      78,     0,     0,     0,   130,   106,   107,   124,     0,    89,
      74,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      79,     0,     0,     0,     0,   131,   132,   126,     0,   125,
     129,     0,     0,   102,     0,   103,   111,   100,   101,   109,
     108,   110,   112,     0,     0,     0,     0,    99,    16,     0,
      93,    76,     0,     0,     0,   123,     0,   118,     0,   104,
     115,   105,   113,   114,   117,   116,     0,     0,    90,   128,
       0,    94,    95,     0,    80,    82,   134,   133,   127,     0,
       0,    86,    88,     0,     0,     0,    92,    91,    96,    97,
      81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    54,    55,    56,    83,    84,    90,
      91,    85,    86,    11,    12,    13,    39,    40,    41,    22,
      23,    24,    36,   136,    25,    26,    32,    33,    34,    74,
      75,    76,    45,    46,   137,   138,   139,   148,   178,   140,
     227,   228,   230,   231,   232,   141,   188,   189,   142,   184,
     185,   186
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -209
static const yytype_int16 yypact[] =
{
      37,   -14,    94,    93,  -209,    95,    13,  -209,    65,    65,
    -209,     4,   100,  -209,  -209,    77,    80,  -209,  -209,  -209,
    -209,    65,     4,     4,  -209,  -209,    65,  -209,   113,    69,
    -209,    65,   101,     4,  -209,  -209,     7,  -209,    26,    83,
      69,  -209,    65,    76,    65,   -11,  -209,  -209,  -209,    65,
      65,  -209,  -209,     3,   118,    26,  -209,  -209,  -209,    85,
       4,    79,  -209,  -209,  -209,    96,    -1,    -1,    65,    21,
      88,  -209,  -209,    65,    86,    90,  -209,    91,  -209,    92,
      97,  -209,    99,    78,  -209,  -209,   104,  -209,   141,    98,
     102,    21,  -209,  -209,  -209,   109,     4,   109,    21,    -6,
     103,  -209,  -209,    21,    26,  -209,  -209,  -209,     4,  -209,
    -209,  -209,  -209,  -209,  -209,    18,  -209,  -209,   107,   138,
     110,   111,   120,    12,    12,   192,   106,   114,  -209,  -209,
     127,  -209,  -209,  -209,   222,   222,   -33,   130,   138,  -209,
    -209,   226,   137,  -209,  -209,   161,    65,  -209,   112,   139,
    -209,   247,   222,   222,    65,   307,   307,   222,    65,  -209,
    -209,  -209,   176,   209,   222,   222,   222,   222,   222,   222,
     222,   122,   123,    14,   222,   142,   132,   140,   146,  -209,
    -209,   267,   287,   148,    10,  -209,  -209,   307,   145,   143,
    -209,   222,   222,   307,   222,   307,   307,   307,   307,   307,
     307,   307,   307,   222,   222,    65,    65,   307,  -209,    65,
      65,  -209,   138,   138,   222,  -209,    65,  -209,   222,   307,
     307,   307,   307,   307,   149,   149,   151,    25,  -209,   134,
     152,   153,  -209,   160,   183,  -209,   307,  -209,   307,   222,
      65,  -209,  -209,    65,    65,   138,   307,  -209,  -209,  -209,
    -209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,   206,   115,  -209,   158,   147,   -16,  -209,
    -209,   -65,    -5,  -209,  -209,   203,  -209,  -209,   177,   116,
    -209,   200,  -124,    -8,   -15,   -17,  -209,  -209,   195,  -209,
    -209,   133,  -209,   189,  -209,  -209,  -135,   117,  -209,   -45,
    -209,     0,  -209,  -209,     2,   -61,  -209,  -209,  -208,  -209,
    -209,    32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      15,    16,   233,   160,    92,    31,   113,   114,    44,    79,
      80,    66,    67,    30,    42,   157,    31,     5,    37,    17,
      18,    19,    20,    43,     3,    42,   107,     9,    62,   158,
     120,   121,    81,    14,    59,   233,    61,    14,   146,   115,
       1,    64,    65,    73,    82,    69,    14,    68,    48,   215,
     109,    21,   111,    49,    81,    14,   216,    50,    87,    87,
      89,    87,    51,    52,   151,    94,    82,   102,    53,   205,
     206,   240,   102,   155,   156,    87,   241,   234,   235,    73,
      87,   224,   225,    87,    17,    18,    19,    20,    79,    80,
      87,   181,   182,   112,     4,    87,   187,     5,   117,    14,
       8,   193,   195,   196,   197,   198,   199,   200,   201,   202,
     250,    81,    14,   207,     9,   147,   147,    28,    29,    38,
      44,   101,    57,    82,    60,    70,    72,    77,    78,    93,
     219,   220,    98,   221,   100,    95,    96,    99,   176,   177,
      97,   105,   222,   223,   103,   106,   183,   108,   116,   122,
     190,    79,    80,   236,   152,   143,   144,   238,   123,   124,
     125,   126,   153,   127,   145,   154,   128,   129,   130,   159,
     175,   131,    14,   132,    81,    14,   108,   174,   246,   133,
     179,   203,   209,   204,   104,   208,    82,   211,   214,   218,
     210,   239,   134,   135,   217,    49,   158,    37,    37,   243,
     244,   226,   229,   242,   128,   129,   130,   245,   183,   131,
      14,   132,    10,    71,    88,    27,   191,    58,   192,   118,
     128,   129,   130,    35,   119,   131,    14,   132,    47,   110,
     134,   135,   226,   150,    63,   229,   249,   128,   129,   130,
     247,   149,   131,    14,   132,   248,   134,   135,   237,   194,
     128,   129,   130,     0,     0,   131,    14,   132,     0,     0,
       0,     0,     0,   134,   135,     0,     0,   161,   162,   163,
     164,     0,     0,     0,     0,     0,   134,   135,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,   180,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   162,
     163,   164,     0,     0,     0,     0,   212,     0,     0,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   162,
     163,   164,     0,     0,     0,     0,   213,     0,     0,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-209))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       8,     9,   210,   138,    69,    22,    12,    13,    19,    10,
      11,     8,     9,    21,    29,    48,    33,     4,    26,    15,
      16,    17,    18,    31,    38,    40,    91,    14,    39,    62,
      12,    13,    33,    34,    42,   243,    44,    34,    26,    45,
       3,    49,    50,    60,    45,    53,    34,    44,    41,    39,
      95,    47,    97,    46,    33,    34,    46,    31,    66,    67,
      68,    69,    36,    37,   125,    73,    45,    83,    42,    55,
      56,    46,    88,   134,   135,    83,    51,   212,   213,    96,
      88,   205,   206,    91,    15,    16,    17,    18,    10,    11,
      98,   152,   153,    98,     0,   103,   157,     4,   103,    34,
       5,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     245,    33,    34,   174,    14,   123,   124,    40,    38,     6,
      19,    43,    39,    45,    48,     7,    41,    48,    32,    41,
     191,   192,    40,   194,    35,    49,    46,    40,   146,    27,
      49,    43,   203,   204,    40,    43,   154,    38,    45,    42,
     158,    10,    11,   214,    48,    45,    45,   218,    20,    21,
      22,    23,    48,    25,    44,    38,    28,    29,    30,    39,
       9,    33,    34,    35,    33,    34,    38,    40,   239,    41,
      41,    59,    50,    60,    43,    43,    45,    41,    40,    46,
      50,    40,    54,    55,    49,    46,    62,   205,   206,    46,
      40,   209,   210,    51,    28,    29,    30,    24,   216,    33,
      34,    35,     6,    55,    67,    12,    40,    40,    42,   104,
      28,    29,    30,    23,   108,    33,    34,    35,    33,    96,
      54,    55,   240,    41,    45,   243,   244,    28,    29,    30,
     240,   124,    33,    34,    35,   243,    54,    55,   216,    40,
      28,    29,    30,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    54,    55,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    64,    38,     0,     4,    65,    66,     5,    14,
      66,    76,    77,    78,    34,    86,    86,    15,    16,    17,
      18,    47,    82,    83,    84,    87,    88,    78,    40,    38,
      86,    88,    89,    90,    91,    84,    85,    86,     6,    79,
      80,    81,    87,    86,    19,    95,    96,    91,    41,    46,
      31,    36,    37,    42,    67,    68,    69,    39,    81,    86,
      48,    86,    39,    96,    86,    86,     8,     9,    44,    86,
       7,    69,    41,    88,    92,    93,    94,    48,    32,    10,
      11,    33,    45,    70,    71,    74,    75,    86,    70,    86,
      72,    73,    74,    41,    86,    49,    46,    49,    40,    40,
      35,    43,    71,    40,    43,    43,    43,    74,    38,   102,
      94,   102,    75,    12,    13,    45,    45,    75,    67,    82,
      12,    13,    42,    20,    21,    22,    23,    25,    28,    29,
      30,    33,    35,    41,    54,    55,    86,    97,    98,    99,
     102,   108,   111,    45,    45,    44,    26,    86,   100,   100,
      41,   108,    48,    48,    38,   108,   108,    48,    62,    39,
      99,    41,    42,    43,    44,    52,    53,    55,    56,    57,
      58,    59,    60,    61,    40,     9,    86,    27,   101,    41,
      41,   108,   108,    86,   112,   113,   114,   108,   109,   110,
      86,    40,    42,   108,    40,   108,   108,   108,   108,   108,
     108,   108,   108,    59,    60,    55,    56,   108,    43,    50,
      50,    41,    49,    49,    40,    39,    46,    49,    46,   108,
     108,   108,   108,   108,    85,    85,    86,   103,   104,    86,
     105,   106,   107,   111,    99,    99,   108,   114,   108,    40,
      46,    51,    51,    46,    40,    24,   108,   104,   107,    86,
      99
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 93 "wig.y"
    {theservice = makeSERVICE((yyvsp[(3) - (8)].html), (yyvsp[(4) - (8)].schema), (yyvsp[(5) - (8)].variable), (yyvsp[(6) - (8)].function), (yyvsp[(7) - (8)].session));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 96 "wig.y"
    {(yyval.html) = (yyvsp[(1) - (1)].html);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 98 "wig.y"
    {(yyval.html) = (yyvsp[(2) - (2)].html); (yyval.html)->next = (yyvsp[(1) - (2)].html);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 101 "wig.y"
    {(yyval.html) = makeHTML((yyvsp[(3) - (8)].id), (yyvsp[(6) - (8)].htmlbody));}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 104 "wig.y"
    {(yyval.htmlbody) = NULL;}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 106 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(1) - (1)].htmlbody);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 109 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(1) - (1)].htmlbody);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 111 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(2) - (2)].htmlbody); (yyval.htmlbody)->next = (yyvsp[(1) - (2)].htmlbody);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 114 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(2) - (4)].id), (yyvsp[(3) - (4)].attribute));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 116 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(3) - (4)].id), NULL);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 118 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYgap((yyvsp[(2) - (3)].id));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 120 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYwhatever((yyvsp[(1) - (1)].stringconst));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 122 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYmeta((yyvsp[(1) - (1)].stringconst));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 124 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYinput((yyvsp[(3) - (4)].inputattr));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 126 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYselect((yyvsp[(3) - (9)].inputattr), (yyvsp[(5) - (9)].htmlbody));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 129 "wig.y"
    {(yyval.inputattr) = (yyvsp[(1) - (1)].inputattr);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 131 "wig.y"
    {(yyval.inputattr) = (yyvsp[(2) - (2)].inputattr); (yyval.inputattr)->next = (yyvsp[(1) - (2)].inputattr);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 134 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRname((yyvsp[(3) - (3)].attr));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 136 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 138 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 140 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 142 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 144 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRattribute((yyvsp[(1) - (1)].attribute));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 148 "wig.y"
    {(yyval.attribute) = NULL;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 150 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 153 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 155 "wig.y"
    {(yyval.attribute) = (yyvsp[(2) - (2)].attribute); (yyval.attribute)->next = (yyvsp[(1) - (2)].attribute);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 158 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (1)].attr), NULL);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 160 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 163 "wig.y"
    {(yyval.attr) = makeATTRid((yyvsp[(1) - (1)].id));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 165 "wig.y"
    {(yyval.attr) = makeATTRstringconst((yyvsp[(2) - (3)].stringconst));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 167 "wig.y"
    {(yyval.attr) = makeATTRintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 170 "wig.y"
    {(yyval.schema) = NULL;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 172 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 175 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 177 "wig.y"
    {(yyval.schema) = (yyvsp[(2) - (2)].schema); (yyval.schema)->next = (yyvsp[(1) - (2)].schema);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 180 "wig.y"
    {(yyval.schema) = makeSCHEMA((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].field));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 183 "wig.y"
    {(yyval.field) = NULL;}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 185 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 188 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 190 "wig.y"
    {(yyval.field) = (yyvsp[(2) - (2)].field); (yyval.field)->next = (yyvsp[(1) - (2)].field);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 193 "wig.y"
    {(yyval.field) = makeFIELD((yyvsp[(1) - (3)].simpletype), (yyvsp[(2) - (3)].id));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 196 "wig.y"
    {(yyval.variable) = NULL;}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 198 "wig.y"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 201 "wig.y"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 203 "wig.y"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); (yyval.variable)->next = (yyvsp[(1) - (2)].variable);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 206 "wig.y"
    {(yyval.variable) = makeVARIABLE((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].id));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 209 "wig.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 211 "wig.y"
    {(yyval.id) = (yyvsp[(3) - (3)].id); (yyval.id)->next = (yyvsp[(1) - (3)].id);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 214 "wig.y"
    {(yyval.id) = makeID((yyvsp[(1) - (1)].stringconst));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 217 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEint();}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 219 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEbool();}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 221 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEstring();}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 223 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEvoid();}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 226 "wig.y"
    {(yyval.type) = makeTYPEsimpletype((yyvsp[(1) - (1)].simpletype));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 228 "wig.y"
    {(yyval.type) = makeTYPEtupleid((yyvsp[(2) - (2)].id));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 231 "wig.y"
    {(yyval.function) = NULL;}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 233 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 236 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 238 "wig.y"
    {(yyval.function) = (yyvsp[(2) - (2)].function); (yyval.function)->next = (yyvsp[(1) - (2)].function);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 241 "wig.y"
    {(yyval.function) = makeFUNCTION((yyvsp[(1) - (6)].type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].argument), (yyvsp[(6) - (6)].compoundstm));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 244 "wig.y"
    {(yyval.argument) = NULL;}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 246 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 249 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 251 "wig.y"
    {(yyval.argument) = (yyvsp[(3) - (3)].argument); (yyval.argument)->next = (yyvsp[(1) - (3)].argument);}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 254 "wig.y"
    {(yyval.argument) = makeARGUMENT((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].id));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 257 "wig.y"
    {(yyval.session) = (yyvsp[(1) - (1)].session);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 259 "wig.y"
    {(yyval.session) = (yyvsp[(2) - (2)].session); (yyval.session)->next = (yyvsp[(1) - (2)].session);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 262 "wig.y"
    {(yyval.session) = makeSESSION((yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].compoundstm));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 265 "wig.y"
    {(yyval.statement) = NULL;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 267 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 270 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 272 "wig.y"
    {(yyval.statement) = (yyvsp[(2) - (2)].statement); (yyval.statement) -> next = (yyvsp[(1) - (2)].statement);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 275 "wig.y"
    {(yyval.statement) = makeSTMsemicolon();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 277 "wig.y"
    {(yyval.statement) = makeSTMshow((yyvsp[(2) - (4)].document), (yyvsp[(3) - (4)].receive));}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 279 "wig.y"
    {(yyval.statement) = makeSTMexit((yyvsp[(2) - (3)].document));}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 281 "wig.y"
    {(yyval.statement) = makeSTMreturn();}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 283 "wig.y"
    {(yyval.statement) = makeSTMreturnexpr((yyvsp[(2) - (3)].exp));}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 285 "wig.y"
    {(yyval.statement) = makeSTMif((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 287 "wig.y"
    {(yyval.statement) = makeSTMifelse((yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 289 "wig.y"
    {(yyval.statement) = makeSTMwhile((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 291 "wig.y"
    {(yyval.statement) = makeSTMcompound((yyvsp[(1) - (1)].compoundstm));}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 293 "wig.y"
    {(yyval.statement) = makeSTMexp((yyvsp[(1) - (2)].exp));}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 296 "wig.y"
    {(yyval.document) = makeDOCUMENTid((yyvsp[(1) - (1)].id));}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 298 "wig.y"
    {(yyval.document) = makeDOCUMENTplug((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].plug));}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 301 "wig.y"
    {(yyval.receive) = makeRECEIVE(NULL);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 303 "wig.y"
    {(yyval.receive) = makeRECEIVE((yyvsp[(3) - (4)].input));}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 306 "wig.y"
    {(yyval.compoundstm) = makeCOMPOUNDSTM((yyvsp[(2) - (4)].variable), (yyvsp[(3) - (4)].statement));}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 309 "wig.y"
    {(yyval.plug) = (yyvsp[(1) - (1)].plug);}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 311 "wig.y"
    {(yyval.plug) = (yyvsp[(3) - (3)].plug); (yyval.plug)->next = (yyvsp[(1) - (3)].plug);}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 314 "wig.y"
    {(yyval.plug) = makePLUG((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 317 "wig.y"
    {(yyval.input) = NULL;}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 319 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 322 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 324 "wig.y"
    {(yyval.input) = (yyvsp[(3) - (3)].input); (yyval.input)->next = (yyvsp[(1) - (3)].input);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 327 "wig.y"
    {(yyval.input) = makeINPUT((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].id));}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 330 "wig.y"
    {(yyval.exp) = makeEXPlvalue((yyvsp[(1) - (1)].lvalue));}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 332 "wig.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].exp));}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 334 "wig.y"
    {(yyval.exp) = makeEXPequals((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 336 "wig.y"
    {(yyval.exp) = makeEXPnotequals((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 338 "wig.y"
    {(yyval.exp) = makeEXPlt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 340 "wig.y"
    {(yyval.exp) = makeEXPgt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 342 "wig.y"
    {(yyval.exp) = makeEXPlte((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 344 "wig.y"
    {(yyval.exp) = makeEXPgte((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 346 "wig.y"
    {(yyval.exp) = makeEXPnot((yyvsp[(2) - (2)].exp));}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 348 "wig.y"
    {(yyval.exp) = makeEXPminus(0, (yyvsp[(2) - (2)].exp));}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 350 "wig.y"
    {(yyval.exp) = makeEXPplus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 352 "wig.y"
    {(yyval.exp) = makeEXPminus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 354 "wig.y"
    {(yyval.exp) = makeEXPmult((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 356 "wig.y"
    {(yyval.exp) = makeEXPdiv((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 358 "wig.y"
    {(yyval.exp) = makeEXPmod((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 360 "wig.y"
    {(yyval.exp) = makeEXPand((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 362 "wig.y"
    {(yyval.exp) = makeEXPor((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 364 "wig.y"
    {(yyval.exp) = makeEXPjoin((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 366 "wig.y"
    {(yyval.exp) = makeEXPkeep((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].id));}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 368 "wig.y"
    {(yyval.exp) = makeEXPremove((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].id));}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 370 "wig.y"
    {(yyval.exp) = makeEXPcall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].exp));}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 372 "wig.y"
    {(yyval.exp) = makeEXPintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 374 "wig.y"
    {(yyval.exp) = makeEXPtrue();}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 376 "wig.y"
    {(yyval.exp) = makeEXPfalse();}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 378 "wig.y"
    {(yyval.exp) = makeEXPstringconst((yyvsp[(1) - (1)].stringconst));}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 380 "wig.y"
    {(yyval.exp) = makeEXPtuple((yyvsp[(3) - (4)].fieldvalue));}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 384 "wig.y"
    {(yyval.exp) = NULL;}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 386 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 389 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 391 "wig.y"
    {(yyval.exp) = (yyvsp[(3) - (3)].exp); (yyval.exp)->next = (yyvsp[(1) - (3)].exp);}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 394 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (1)].id), NULL);}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 396 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 399 "wig.y"
    {(yyval.fieldvalue) = NULL;}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 401 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 404 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 406 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(3) - (3)].fieldvalue); (yyval.fieldvalue)->next = (yyvsp[(1) - (3)].fieldvalue);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 409 "wig.y"
    {(yyval.fieldvalue) = makeFIELDVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;



/* Line 1806 of yacc.c  */
#line 2655 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 411 "wig.y"


