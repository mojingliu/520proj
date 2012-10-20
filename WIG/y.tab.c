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
     tEQUALS = 288,
     tINTCONST = 289,
     tIDENTIFIER = 290,
     tSTRINGCONST = 291,
     tWHATEVER = 292,
     tMETA = 293
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
#define tINTCONST 289
#define tIDENTIFIER 290
#define tSTRINGCONST 291
#define tWHATEVER 292
#define tMETA 293




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
#line 227 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 239 "y.tab.c"

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
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNRULES -- Number of states.  */
#define YYNSTATES  277

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    46,     2,     2,    56,    57,     2,
      47,    48,    55,    54,    49,    53,    60,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      43,    41,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,    59,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    58,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    20,    22,    25,    34,    42,    44,
      47,    52,    57,    61,    63,    65,    70,    80,    89,    91,
      94,    98,   102,   108,   112,   118,   120,   121,   123,   125,
     128,   130,   134,   136,   140,   143,   145,   146,   148,   150,
     153,   159,   160,   162,   164,   167,   171,   173,   176,   180,
     181,   183,   185,   188,   195,   197,   201,   203,   205,   207,
     209,   211,   213,   216,   217,   219,   221,   225,   228,   230,
     233,   239,   240,   242,   244,   247,   249,   254,   258,   261,
     265,   271,   279,   285,   287,   290,   292,   298,   299,   304,
     309,   313,   315,   319,   323,   324,   326,   328,   332,   336,
     338,   342,   346,   351,   355,   359,   364,   369,   372,   375,
     379,   383,   387,   391,   395,   400,   405,   410,   415,   422,
     427,   434,   439,   441,   443,   445,   449,   452,   457,   461,
     462,   464,   466,   470,   472,   476,   477,   479,   481,   485
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,     3,    39,    63,    73,    79,    81,    91,
      40,    -1,     3,    39,    63,    73,    81,    91,    40,    -1,
      64,    -1,    63,    64,    -1,     4,     5,    85,    41,     6,
      65,     7,    42,    -1,     4,     5,    85,    41,     6,     7,
      42,    -1,    66,    -1,    65,    66,    -1,    43,    85,    69,
      44,    -1,    43,    45,    85,    44,    -1,    31,    85,    32,
      -1,    37,    -1,    38,    -1,    43,     8,    67,    44,    -1,
      43,     9,    67,    44,    65,    43,    45,     9,    44,    -1,
      43,     9,    67,    44,    43,    45,     9,    44,    -1,    68,
      -1,    67,    68,    -1,    10,    41,    72,    -1,    11,    41,
      12,    -1,    11,    41,    46,    12,    46,    -1,    11,    41,
      13,    -1,    11,    41,    46,    13,    46,    -1,    71,    -1,
      -1,    70,    -1,    71,    -1,    70,    71,    -1,    72,    -1,
      72,    41,    72,    -1,    85,    -1,    46,    36,    46,    -1,
      46,    46,    -1,    34,    -1,    -1,    74,    -1,    75,    -1,
      74,    75,    -1,    14,    85,    39,    76,    40,    -1,    -1,
      77,    -1,    78,    -1,    77,    78,    -1,    86,    85,    42,
      -1,    80,    -1,    79,    80,    -1,    87,    84,    42,    -1,
      -1,    82,    -1,    83,    -1,    82,    83,    -1,    87,    85,
      47,    88,    48,    98,    -1,    85,    -1,    84,    49,    85,
      -1,    35,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    86,    -1,    30,    85,    -1,    -1,    89,    -1,    90,
      -1,    89,    49,    90,    -1,    87,    85,    -1,    92,    -1,
      91,    92,    -1,    19,    85,    47,    48,    98,    -1,    -1,
      94,    -1,    95,    -1,    94,    95,    -1,    42,    -1,    20,
      96,    97,    42,    -1,    21,    96,    42,    -1,    22,    42,
      -1,    22,   104,    42,    -1,    23,    47,   104,    48,    95,
      -1,    23,    47,   104,    48,    95,    24,    95,    -1,    25,
      47,   104,    48,    95,    -1,    98,    -1,   104,    42,    -1,
      85,    -1,    26,    85,    50,    99,    51,    -1,    -1,    27,
      50,   101,    51,    -1,    39,    79,    93,    40,    -1,    39,
      93,    40,    -1,   100,    -1,   100,    49,    99,    -1,    85,
      41,   104,    -1,    -1,   102,    -1,   103,    -1,   102,    49,
     103,    -1,   107,    41,    85,    -1,   107,    -1,   107,    41,
     104,    -1,   104,    33,   104,    -1,   104,    52,    41,   104,
      -1,   104,    43,   104,    -1,   104,    44,   104,    -1,   104,
      43,    41,   104,    -1,   104,    44,    41,   104,    -1,    52,
     104,    -1,    53,   104,    -1,   104,    54,   104,    -1,   104,
      53,   104,    -1,   104,    55,   104,    -1,   104,    45,   104,
      -1,   104,    56,   104,    -1,   104,    57,    57,   104,    -1,
     104,    58,    58,   104,    -1,   104,    43,    43,   104,    -1,
     104,    59,    54,    85,    -1,   104,    59,    54,    47,    84,
      48,    -1,   104,    59,    53,    85,    -1,   104,    59,    53,
      47,    84,    48,    -1,    85,    47,   105,    48,    -1,    34,
      -1,    28,    -1,    29,    -1,    46,    36,    46,    -1,    46,
      46,    -1,    30,    39,   108,    40,    -1,    47,   104,    48,
      -1,    -1,   106,    -1,   104,    -1,   106,    49,   104,    -1,
      85,    -1,    85,    60,    85,    -1,    -1,   109,    -1,   110,
      -1,   108,    49,   110,    -1,    85,    41,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    90,    93,    95,    98,   100,   103,   105,
     108,   110,   112,   114,   116,   118,   120,   122,   125,   127,
     130,   132,   134,   136,   138,   140,   145,   146,   149,   151,
     154,   156,   159,   161,   163,   165,   169,   170,   173,   175,
     178,   182,   183,   186,   188,   191,   194,   196,   199,   203,
     204,   207,   209,   212,   218,   220,   223,   226,   228,   230,
     232,   235,   237,   243,   244,   247,   249,   252,   255,   257,
     260,   264,   265,   268,   270,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   294,   296,   300,   301,   304,
     306,   309,   311,   314,   318,   319,   322,   324,   327,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   354,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   392,
     393,   396,   398,   401,   403,   407,   408,   411,   413,   416
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
  "tGAPCLOSE", "tEQUALS", "tINTCONST", "tIDENTIFIER", "tSTRINGCONST",
  "tWHATEVER", "tMETA", "'{'", "'}'", "'='", "';'", "'<'", "'>'", "'/'",
  "'\"'", "'('", "')'", "','", "'['", "']'", "'!'", "'-'", "'+'", "'*'",
  "'%'", "'&'", "'|'", "'\\\\'", "'.'", "$accept", "service", "htmls",
  "html", "nehtmlbodies", "htmlbody", "inputattrs", "inputattr",
  "attributes", "neattributes", "attribute", "attr", "schemas",
  "neschemas", "schema", "fields", "nefields", "field", "nevariables",
  "variable", "functions", "nefunctions", "function", "identifiers",
  "identifier", "simpletype", "type", "arguments", "nearguments",
  "argument", "sessions", "session", "stms", "nestms", "stm", "document",
  "receive", "compoundstm", "plugs", "plug", "inputs", "neinputs", "input",
  "exp", "exps", "neexps", "lvalue", "fieldvalues", "nefieldvalues",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
     125,    61,    59,    60,    62,    47,    34,    40,    41,    44,
      91,    93,    33,    45,    43,    42,    37,    38,   124,    92,
      46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    84,    84,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    91,    91,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   102,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     1,     2,     8,     7,     1,     2,
       4,     4,     3,     1,     1,     4,     9,     8,     1,     2,
       3,     3,     5,     3,     5,     1,     0,     1,     1,     2,
       1,     3,     1,     3,     2,     1,     0,     1,     1,     2,
       5,     0,     1,     1,     2,     3,     1,     2,     3,     0,
       1,     1,     2,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     0,     1,     1,     3,     2,     1,     2,
       5,     0,     1,     1,     2,     1,     4,     3,     2,     3,
       5,     7,     5,     1,     2,     1,     5,     0,     4,     4,
       3,     1,     3,     3,     0,     1,     1,     3,     3,     1,
       3,     3,     4,     3,     3,     4,     4,     2,     2,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     6,     4,
       6,     4,     1,     1,     1,     3,     2,     4,     3,     0,
       1,     1,     3,     1,     3,     0,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    36,     4,     0,     0,
       5,    49,    37,    38,    56,     0,     0,    57,    58,    59,
      60,     0,    49,    46,     0,    50,    51,    61,     0,    39,
       0,    41,    62,    47,     0,     0,     0,    68,    52,     0,
       0,    54,     0,     0,    42,    43,     0,     0,     0,     3,
      69,     0,    48,     0,    63,     0,     0,    13,    14,     0,
       0,     8,    40,    44,     0,     2,     0,    55,     0,     0,
      64,    65,     7,     0,     0,     0,     0,    26,     0,     9,
      45,     0,    67,     0,     0,    12,     0,     0,    35,     0,
       0,    18,    25,    30,    32,     0,     0,     0,    27,    28,
       6,    71,    70,    53,    66,     0,     0,     0,    34,    15,
      19,     0,     0,    11,    10,    29,     0,     0,     0,     0,
       0,   123,   124,     0,   122,    75,     0,     0,     0,     0,
      71,   133,     0,     0,    72,    73,    83,     0,    99,    20,
      21,    23,     0,    33,    31,     0,     0,     0,    85,    87,
       0,     0,    78,     0,     0,     0,   135,     0,   126,     0,
     107,   108,     0,   129,     0,    54,    90,    74,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      79,     0,     0,     0,     0,   136,   137,   125,   128,    89,
     131,     0,   130,   134,   101,     0,     0,   103,     0,   104,
     112,     0,   110,   109,   111,   113,     0,     0,     0,     0,
     100,    22,    24,     0,     0,     0,    94,    76,     0,     0,
       0,   127,     0,   121,     0,   105,   116,   106,   102,   114,
     115,     0,   119,     0,   117,    17,     0,     0,     0,    91,
     133,     0,    95,    96,     0,    80,    82,   139,   138,   132,
       0,     0,    16,     0,    86,     0,    88,     0,     0,     0,
     120,   118,    93,    92,    97,    98,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    60,    61,    90,    91,    97,    98,
      92,    93,    11,    12,    13,    43,    44,    45,    22,    23,
      24,    25,    26,    40,   131,    27,    28,    69,    70,    71,
      36,    37,   133,   134,   135,   149,   188,   136,   248,   249,
     251,   252,   253,   137,   201,   202,   138,   194,   195,   196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
      25,    -4,   101,   132,  -221,   113,    88,  -221,    87,    87,
    -221,   154,   139,  -221,  -221,   123,   127,  -221,  -221,  -221,
    -221,    87,   154,  -221,   156,   154,  -221,  -221,    87,  -221,
     180,   266,  -221,  -221,   156,    87,     3,  -221,  -221,    87,
      81,   153,    76,   161,   266,  -221,    87,    53,   157,  -221,
    -221,   153,  -221,    87,   154,   163,    87,  -221,  -221,    -1,
     114,  -221,  -221,  -221,   166,  -221,   155,  -221,    87,   167,
     147,  -221,  -221,   177,    45,    45,    87,    60,   172,  -221,
    -221,   182,  -221,   182,   154,  -221,   181,   184,  -221,    28,
      15,  -221,  -221,   185,  -221,    19,   179,   183,    60,  -221,
    -221,   233,  -221,  -221,  -221,    60,    11,   188,  -221,  -221,
    -221,    60,   104,  -221,  -221,  -221,    70,    70,   348,   189,
     190,  -221,  -221,    42,  -221,  -221,    80,   377,   377,   377,
     233,   -28,    87,   192,   160,  -221,  -221,   186,   205,  -221,
    -221,  -221,   148,  -221,  -221,     1,   112,    87,  -221,   220,
     210,   225,  -221,   245,   377,   377,    87,   219,  -221,   262,
     313,   313,   226,   377,    87,  -221,  -221,  -221,   377,  -221,
     345,   374,   377,   228,   377,   377,   377,   377,   213,   215,
     125,   377,   230,   231,     2,     7,   221,   224,   249,  -221,
    -221,   279,   296,   251,   118,  -221,  -221,  -221,  -221,  -221,
     313,   246,   244,  -221,   313,   377,   377,   313,   377,   313,
     313,   377,   313,   313,   313,   313,   377,   377,   -14,    23,
     313,  -221,  -221,   252,     5,    87,    87,  -221,   160,   160,
     377,  -221,    87,  -221,   377,   313,   313,   313,   313,   313,
     313,    87,  -221,    87,  -221,  -221,   264,   268,   260,   276,
     253,   275,   281,  -221,   287,   318,  -221,   313,  -221,   313,
     144,   149,  -221,   377,  -221,    87,  -221,    87,    87,   160,
    -221,  -221,   313,  -221,  -221,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,   337,   235,   -57,   270,    64,  -221,  -221,
     -59,    -7,  -221,  -221,   347,  -221,  -221,   316,   261,   -20,
     339,  -221,   338,  -165,    -8,   -27,   -13,  -221,  -221,   280,
     350,    26,   255,  -221,  -129,   272,  -221,    63,   116,  -221,
    -221,  -221,   120,   -43,  -221,  -221,  -220,  -221,  -221,   164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      15,    16,    33,    79,    46,   167,   254,    74,    75,    74,
      75,   223,    39,    32,   246,    74,    75,    46,    99,   163,
      41,    14,    35,   140,   141,    86,    87,    48,     1,    86,
      87,    51,   164,   241,    14,     3,    14,    14,    64,   115,
      14,    68,    14,    49,    76,    67,   184,   254,    73,    88,
      14,    77,   224,    88,    14,    86,    87,   142,    14,   109,
      82,    89,    50,   112,   107,    89,    94,    94,    96,    94,
     243,    68,    35,    50,   108,   153,   260,    14,   261,    88,
      14,   156,    94,    55,   159,   160,   161,    94,   132,    79,
      94,    89,     5,    65,    88,    14,   147,    94,   139,   255,
     256,     4,     9,    94,   144,    14,    89,    56,   148,   148,
      33,   191,   192,    57,    58,    32,   157,   132,     8,    59,
     200,    78,    14,    52,   165,   204,   158,   207,   209,   210,
      53,   212,   213,   214,   215,    56,     5,    77,   220,   186,
     276,    57,    58,    56,   102,    56,   103,   145,   193,    57,
      58,    57,    58,     9,   110,   185,   203,    59,   231,   110,
     182,   183,   235,   236,    30,   237,    31,   232,   238,    17,
      18,    19,    20,   239,   240,    35,    96,    77,   218,   219,
     116,   117,   118,   119,    21,   120,    42,   257,   121,   122,
     151,   259,   270,    53,   124,    14,    84,   271,    53,   101,
      54,    62,   125,    81,    66,    72,   126,   127,    80,    85,
     242,   244,   128,   129,   100,    83,    96,   247,   250,   168,
     272,   101,   105,   113,   193,   106,   111,   114,   169,   170,
     171,   172,   166,   165,   143,   165,   154,   155,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   187,    17,    18,
      19,    20,   189,   116,   117,   118,   119,   247,   120,   250,
     275,   121,   122,   123,   156,   197,   199,   124,    14,   211,
     216,   225,   101,   217,   226,   125,   221,   222,   168,   126,
     127,    17,    18,    19,    20,   128,   129,   190,   170,   171,
     172,   227,   230,   234,   233,   168,   245,   173,   174,   175,
     176,   177,   178,   179,   180,   170,   171,   172,   262,   263,
     198,   264,   168,   164,   173,   174,   175,   176,   177,   178,
     179,   180,   170,   171,   172,   265,   266,   228,   268,   168,
     267,   173,   174,   175,   176,   177,   178,   179,   180,   170,
     171,   172,   269,    10,   229,    95,   168,   146,   173,   174,
     175,   176,   177,   178,   179,   180,   170,   171,   172,    29,
      63,    34,   130,    38,   104,   173,   174,   175,   176,   177,
     178,   179,   180,   121,   122,   151,   121,   122,   151,   124,
      14,   273,   124,    14,    47,   162,   205,   274,   206,   150,
     152,   126,   127,     0,   126,   127,   258,   128,   129,     0,
     128,   129,   121,   122,   151,   121,   122,   151,   124,    14,
       0,   124,    14,     0,     0,   208,     0,     0,     0,     0,
     126,   127,     0,   126,   127,     0,   128,   129,     0,   128,
     129
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-221))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       8,     9,    22,    60,    31,   134,   226,     8,     9,     8,
       9,     9,    25,    21,     9,     8,     9,    44,    77,    47,
      28,    35,    19,    12,    13,    10,    11,    35,     3,    10,
      11,    39,    60,    47,    35,    39,    35,    35,    46,    98,
      35,    54,    35,    40,    45,    53,    45,   267,    56,    34,
      35,    59,    45,    34,    35,    10,    11,    46,    35,    44,
      68,    46,    36,    44,    36,    46,    74,    75,    76,    77,
      47,    84,    19,    47,    46,   118,   241,    35,   243,    34,
      35,    39,    90,     7,   127,   128,   129,    95,   101,   146,
      98,    46,     4,    40,    34,    35,    26,   105,   105,   228,
     229,     0,    14,   111,   111,    35,    46,    31,   116,   117,
     130,   154,   155,    37,    38,   123,    36,   130,     5,    43,
     163,     7,    35,    42,   132,   168,    46,   170,   171,   172,
      49,   174,   175,   176,   177,    31,     4,   145,   181,   147,
     269,    37,    38,    31,    81,    31,    83,    43,   156,    37,
      38,    37,    38,    14,    90,    43,   164,    43,    40,    95,
      12,    13,   205,   206,    41,   208,    39,    49,   211,    15,
      16,    17,    18,   216,   217,    19,   184,   185,    53,    54,
      20,    21,    22,    23,    30,    25,     6,   230,    28,    29,
      30,   234,    48,    49,    34,    35,    49,    48,    49,    39,
      47,    40,    42,    48,    47,    42,    46,    47,    42,    32,
     218,   219,    52,    53,    42,    48,   224,   225,   226,    33,
     263,    39,    41,    44,   232,    41,    41,    44,    42,    43,
      44,    45,    40,   241,    46,   243,    47,    47,    52,    53,
      54,    55,    56,    57,    58,    59,    41,    27,    15,    16,
      17,    18,    42,    20,    21,    22,    23,   265,    25,   267,
     268,    28,    29,    30,    39,    46,    40,    34,    35,    41,
      57,    50,    39,    58,    50,    42,    46,    46,    33,    46,
      47,    15,    16,    17,    18,    52,    53,    42,    43,    44,
      45,    42,    41,    49,    48,    33,    44,    52,    53,    54,
      55,    56,    57,    58,    59,    43,    44,    45,    44,    41,
      48,    51,    33,    60,    52,    53,    54,    55,    56,    57,
      58,    59,    43,    44,    45,    49,    51,    48,    41,    33,
      49,    52,    53,    54,    55,    56,    57,    58,    59,    43,
      44,    45,    24,     6,    48,    75,    33,   112,    52,    53,
      54,    55,    56,    57,    58,    59,    43,    44,    45,    12,
      44,    22,   101,    25,    84,    52,    53,    54,    55,    56,
      57,    58,    59,    28,    29,    30,    28,    29,    30,    34,
      35,   265,    34,    35,    34,   130,    41,   267,    43,   117,
      42,    46,    47,    -1,    46,    47,   232,    52,    53,    -1,
      52,    53,    28,    29,    30,    28,    29,    30,    34,    35,
      -1,    34,    35,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    -1,    46,    47,    -1,    52,    53,    -1,    52,
      53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    39,     0,     4,    63,    64,     5,    14,
      64,    73,    74,    75,    35,    85,    85,    15,    16,    17,
      18,    30,    79,    80,    81,    82,    83,    86,    87,    75,
      41,    39,    85,    80,    81,    19,    91,    92,    83,    87,
      84,    85,     6,    76,    77,    78,    86,    91,    85,    40,
      92,    85,    42,    49,    47,     7,    31,    37,    38,    43,
      65,    66,    40,    78,    85,    40,    47,    85,    87,    88,
      89,    90,    42,    85,     8,     9,    45,    85,     7,    66,
      42,    48,    85,    48,    49,    32,    10,    11,    34,    46,
      67,    68,    71,    72,    85,    67,    85,    69,    70,    71,
      42,    39,    98,    98,    90,    41,    41,    36,    46,    44,
      68,    41,    44,    44,    44,    71,    20,    21,    22,    23,
      25,    28,    29,    30,    34,    42,    46,    47,    52,    53,
      79,    85,    87,    93,    94,    95,    98,   104,   107,    72,
      12,    13,    46,    46,    72,    43,    65,    26,    85,    96,
      96,    30,    42,   104,    47,    47,    39,    36,    46,   104,
     104,   104,    93,    47,    60,    85,    40,    95,    33,    42,
      43,    44,    45,    52,    53,    54,    55,    56,    57,    58,
      59,    41,    12,    13,    45,    43,    85,    27,    97,    42,
      42,   104,   104,    85,   108,   109,   110,    46,    48,    40,
     104,   105,   106,    85,   104,    41,    43,   104,    41,   104,
     104,    41,   104,   104,   104,   104,    57,    58,    53,    54,
     104,    46,    46,     9,    45,    50,    50,    42,    48,    48,
      41,    40,    49,    48,    49,   104,   104,   104,   104,   104,
     104,    47,    85,    47,    85,    44,     9,    85,    99,   100,
      85,   101,   102,   103,   107,    95,    95,   104,   110,   104,
      84,    84,    44,    41,    51,    49,    51,    49,    41,    24,
      48,    48,   104,    99,   103,    85,    95
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
#line 89 "wig.y"
    {theservice = makeSERVICE((yyvsp[(3) - (8)].html), (yyvsp[(4) - (8)].schema), (yyvsp[(5) - (8)].variable), (yyvsp[(6) - (8)].function), (yyvsp[(7) - (8)].session));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 91 "wig.y"
    {theservice = makeSERVICE((yyvsp[(3) - (7)].html), (yyvsp[(4) - (7)].schema), NULL, (yyvsp[(5) - (7)].function), (yyvsp[(6) - (7)].session));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 94 "wig.y"
    {(yyval.html) = (yyvsp[(1) - (1)].html);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 96 "wig.y"
    {(yyval.html) = (yyvsp[(2) - (2)].html); (yyval.html)->next = (yyvsp[(1) - (2)].html);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 99 "wig.y"
    {(yyval.html) = makeHTML((yyvsp[(3) - (8)].id), (yyvsp[(6) - (8)].htmlbody));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 101 "wig.y"
    {(yyval.html) = makeHTML((yyvsp[(3) - (7)].id), NULL);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 104 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(1) - (1)].htmlbody);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 106 "wig.y"
    {(yyval.htmlbody) = (yyvsp[(2) - (2)].htmlbody); (yyval.htmlbody)->next = (yyvsp[(1) - (2)].htmlbody);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 109 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(2) - (4)].id), (yyvsp[(3) - (4)].attribute));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 111 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYtag((yyvsp[(3) - (4)].id), NULL);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 113 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYgap((yyvsp[(2) - (3)].id));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 115 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYwhatever((yyvsp[(1) - (1)].stringconst));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 117 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYmeta((yyvsp[(1) - (1)].stringconst));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 119 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYinput((yyvsp[(3) - (4)].inputattr));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 121 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYselect((yyvsp[(3) - (9)].inputattr), (yyvsp[(5) - (9)].htmlbody));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 123 "wig.y"
    {(yyval.htmlbody) = makeHTMLBODYselect((yyvsp[(3) - (8)].inputattr), NULL);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 126 "wig.y"
    {(yyval.inputattr) = (yyvsp[(1) - (1)].inputattr);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 128 "wig.y"
    {(yyval.inputattr) = (yyvsp[(2) - (2)].inputattr); (yyval.inputattr)->next = (yyvsp[(1) - (2)].inputattr);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 131 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRname((yyvsp[(3) - (3)].attr));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 133 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 135 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRtext();}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 137 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 139 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRradio();}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 141 "wig.y"
    {(yyval.inputattr) = makeINPUTATTRattribute((yyvsp[(1) - (1)].attribute));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 145 "wig.y"
    {(yyval.attribute) = NULL;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 147 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 150 "wig.y"
    {(yyval.attribute) = (yyvsp[(1) - (1)].attribute);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 152 "wig.y"
    {(yyval.attribute) = (yyvsp[(2) - (2)].attribute); (yyval.attribute)->next = (yyvsp[(1) - (2)].attribute);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 155 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (1)].attr), NULL);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 157 "wig.y"
    {(yyval.attribute) = makeATTRIBUTEattr((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 160 "wig.y"
    {(yyval.attr) = makeATTRid((yyvsp[(1) - (1)].id));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 162 "wig.y"
    {(yyval.attr) = makeATTRstringconst((yyvsp[(2) - (3)].stringconst));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 164 "wig.y"
    {(yyval.attr) = makeATTRstringconst("");}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 166 "wig.y"
    {(yyval.attr) = makeATTRintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 169 "wig.y"
    {(yyval.schema) = NULL;}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 171 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 174 "wig.y"
    {(yyval.schema) = (yyvsp[(1) - (1)].schema);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 176 "wig.y"
    {(yyval.schema) = (yyvsp[(2) - (2)].schema); (yyval.schema)->next = (yyvsp[(1) - (2)].schema);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 179 "wig.y"
    {(yyval.schema) = makeSCHEMA((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].field));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 182 "wig.y"
    {(yyval.field) = NULL;}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 184 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 187 "wig.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 189 "wig.y"
    {(yyval.field) = (yyvsp[(2) - (2)].field); (yyval.field)->next = (yyvsp[(1) - (2)].field);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 192 "wig.y"
    {(yyval.field) = makeFIELD((yyvsp[(1) - (3)].simpletype), (yyvsp[(2) - (3)].id));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 195 "wig.y"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 197 "wig.y"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); (yyval.variable)->next = (yyvsp[(1) - (2)].variable);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 200 "wig.y"
    {(yyval.variable) = makeVARIABLE((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].id));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 203 "wig.y"
    {(yyval.function) = NULL;}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 205 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 208 "wig.y"
    {(yyval.function) = (yyvsp[(1) - (1)].function);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 210 "wig.y"
    {(yyval.function) = (yyvsp[(2) - (2)].function); (yyval.function)->next = (yyvsp[(1) - (2)].function);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 213 "wig.y"
    {(yyval.function) = makeFUNCTION((yyvsp[(1) - (6)].type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].argument), (yyvsp[(6) - (6)].compoundstm));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 219 "wig.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 221 "wig.y"
    {(yyval.id) = (yyvsp[(3) - (3)].id); (yyval.id)->next = (yyvsp[(1) - (3)].id);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 224 "wig.y"
    {(yyval.id) = makeID((yyvsp[(1) - (1)].stringconst));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 227 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEint();}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 229 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEbool();}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 231 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEstring();}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 233 "wig.y"
    {(yyval.simpletype) = makeSIMPLETYPEvoid();}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 236 "wig.y"
    {(yyval.type) = makeTYPEsimpletype((yyvsp[(1) - (1)].simpletype));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 238 "wig.y"
    {(yyval.type) = makeTYPEtupleid((yyvsp[(2) - (2)].id));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 243 "wig.y"
    {(yyval.argument) = NULL;}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 245 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 248 "wig.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 250 "wig.y"
    {(yyval.argument) = (yyvsp[(3) - (3)].argument); (yyval.argument)->next = (yyvsp[(1) - (3)].argument);}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 253 "wig.y"
    {(yyval.argument) = makeARGUMENT((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].id));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 256 "wig.y"
    {(yyval.session) = (yyvsp[(1) - (1)].session);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 258 "wig.y"
    {(yyval.session) = (yyvsp[(2) - (2)].session); (yyval.session)->next = (yyvsp[(1) - (2)].session);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 261 "wig.y"
    {(yyval.session) = makeSESSION((yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].compoundstm));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 264 "wig.y"
    {(yyval.statement) = NULL;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 266 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 269 "wig.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 271 "wig.y"
    {(yyval.statement) = (yyvsp[(2) - (2)].statement); (yyval.statement)->next = (yyvsp[(1) - (2)].statement);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 274 "wig.y"
    {(yyval.statement) = makeSTMsemicolon();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 276 "wig.y"
    {(yyval.statement) = makeSTMshow((yyvsp[(2) - (4)].document), (yyvsp[(3) - (4)].receive));}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 278 "wig.y"
    {(yyval.statement) = makeSTMexit((yyvsp[(2) - (3)].document));}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 280 "wig.y"
    {(yyval.statement) = makeSTMreturn();}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 282 "wig.y"
    {(yyval.statement) = makeSTMreturnexpr((yyvsp[(2) - (3)].exp));}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 284 "wig.y"
    {(yyval.statement) = makeSTMif((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 286 "wig.y"
    {(yyval.statement) = makeSTMifelse((yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 288 "wig.y"
    {(yyval.statement) = makeSTMwhile((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 290 "wig.y"
    {(yyval.statement) = makeSTMcompound((yyvsp[(1) - (1)].compoundstm));}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 292 "wig.y"
    {(yyval.statement) = makeSTMexp((yyvsp[(1) - (2)].exp));}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 295 "wig.y"
    {(yyval.document) = makeDOCUMENTid((yyvsp[(1) - (1)].id));}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 297 "wig.y"
    {(yyval.document) = makeDOCUMENTplug((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].plug));}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 300 "wig.y"
    {(yyval.receive) = makeRECEIVE(NULL);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 302 "wig.y"
    {(yyval.receive) = makeRECEIVE((yyvsp[(3) - (4)].input));}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 305 "wig.y"
    {(yyval.compoundstm) = makeCOMPOUNDSTM((yyvsp[(2) - (4)].variable), (yyvsp[(3) - (4)].statement));}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 307 "wig.y"
    {(yyval.compoundstm) = makeCOMPOUNDSTM(NULL, (yyvsp[(2) - (3)].statement));}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 310 "wig.y"
    {(yyval.plug) = (yyvsp[(1) - (1)].plug);}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 312 "wig.y"
    {(yyval.plug) = (yyvsp[(1) - (3)].plug); (yyval.plug)->next = (yyvsp[(3) - (3)].plug);}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 315 "wig.y"
    {(yyval.plug) = makePLUG((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 318 "wig.y"
    {(yyval.input) = NULL;}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 320 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 323 "wig.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 325 "wig.y"
    {(yyval.input) = (yyvsp[(3) - (3)].input); (yyval.input)->next = (yyvsp[(1) - (3)].input);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 328 "wig.y"
    {(yyval.input) = makeINPUT((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].id));}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 331 "wig.y"
    {(yyval.exp) = makeEXPlvalue((yyvsp[(1) - (1)].lvalue));}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 333 "wig.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].lvalue), (yyvsp[(3) - (3)].exp));}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 335 "wig.y"
    {(yyval.exp) = makeEXPequals((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 337 "wig.y"
    {(yyval.exp) = makeEXPnotequals((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 339 "wig.y"
    {(yyval.exp) = makeEXPlt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 341 "wig.y"
    {(yyval.exp) = makeEXPgt((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 343 "wig.y"
    {(yyval.exp) = makeEXPlte((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 345 "wig.y"
    {(yyval.exp) = makeEXPgte((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 347 "wig.y"
    {(yyval.exp) = makeEXPnot((yyvsp[(2) - (2)].exp));}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 349 "wig.y"
    {(yyval.exp) = makeEXPminus(0, (yyvsp[(2) - (2)].exp));}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 351 "wig.y"
    {(yyval.exp) = makeEXPplus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 353 "wig.y"
    {(yyval.exp) = makeEXPminus((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 355 "wig.y"
    {(yyval.exp) = makeEXPmult((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 357 "wig.y"
    {(yyval.exp) = makeEXPdiv((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 359 "wig.y"
    {(yyval.exp) = makeEXPmod((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 361 "wig.y"
    {(yyval.exp) = makeEXPand((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 363 "wig.y"
    {(yyval.exp) = makeEXPor((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 365 "wig.y"
    {(yyval.exp) = makeEXPjoin((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 367 "wig.y"
    {(yyval.exp) = makeEXPkeep((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].id));}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 369 "wig.y"
    {(yyval.exp) = makeEXPkeep((yyvsp[(1) - (6)].exp), (yyvsp[(5) - (6)].id));}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 371 "wig.y"
    {(yyval.exp) = makeEXPremove((yyvsp[(1) - (4)].exp), (yyvsp[(4) - (4)].id));}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 373 "wig.y"
    {(yyval.exp) = makeEXPremove((yyvsp[(1) - (6)].exp), (yyvsp[(5) - (6)].id));}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 375 "wig.y"
    {(yyval.exp) = makeEXPcall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].exp));}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 377 "wig.y"
    {(yyval.exp) = makeEXPintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 379 "wig.y"
    {(yyval.exp) = makeEXPtrue();}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 381 "wig.y"
    {(yyval.exp) = makeEXPfalse();}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 383 "wig.y"
    {(yyval.exp) = makeEXPstringconst((yyvsp[(2) - (3)].stringconst));}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 385 "wig.y"
    {(yyval.exp) = makeEXPstringconst("");}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 387 "wig.y"
    {(yyval.exp) = makeEXPtuple((yyvsp[(3) - (4)].fieldvalue));}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 389 "wig.y"
    {(yyval.exp) = makeEXPparen((yyvsp[(2) - (3)].exp));}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 392 "wig.y"
    {(yyval.exp) = NULL;}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 394 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 397 "wig.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 399 "wig.y"
    {(yyval.exp) = (yyvsp[(3) - (3)].exp); (yyval.exp)->next = (yyvsp[(1) - (3)].exp);}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 402 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (1)].id), NULL);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 404 "wig.y"
    {(yyval.lvalue) = makeLVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 407 "wig.y"
    {(yyval.fieldvalue) = NULL;}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 409 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 412 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(1) - (1)].fieldvalue);}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 414 "wig.y"
    {(yyval.fieldvalue) = (yyvsp[(3) - (3)].fieldvalue); (yyval.fieldvalue)->next = (yyvsp[(1) - (3)].fieldvalue);}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 417 "wig.y"
    {(yyval.fieldvalue) = makeFIELDVALUE((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp));}
    break;



/* Line 1806 of yacc.c  */
#line 2715 "y.tab.c"
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
#line 419 "wig.y"


