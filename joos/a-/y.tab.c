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
#line 13 "joos.y"

 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

extern CLASSFILE *theclassfile;
 


/* Line 189 of yacc.c  */
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
     tABSTRACT = 258,
     tBOOLEAN = 259,
     tBREAK = 260,
     tBYTE = 261,
     tCASE = 262,
     tCATCH = 263,
     tCHAR = 264,
     tCLASS = 265,
     tCONST = 266,
     tCONTINUE = 267,
     tDEFAULT = 268,
     tDO = 269,
     tDOUBLE = 270,
     tELSE = 271,
     tEXTENDS = 272,
     tEXTERN = 273,
     tFINAL = 274,
     tFINALLY = 275,
     tFLOAT = 276,
     tFOR = 277,
     tGOTO = 278,
     tIF = 279,
     tIMPLEMENTS = 280,
     tIMPORT = 281,
     tIN = 282,
     tINSTANCEOF = 283,
     tINT = 284,
     tINTERFACE = 285,
     tLONG = 286,
     tMAIN = 287,
     tMAINARGV = 288,
     tNATIVE = 289,
     tNEW = 290,
     tNULL = 291,
     tPACKAGE = 292,
     tPRIVATE = 293,
     tPROTECTED = 294,
     tPUBLIC = 295,
     tRETURN = 296,
     tSHORT = 297,
     tSTATIC = 298,
     tSUPER = 299,
     tSWITCH = 300,
     tSYNCHRONIZED = 301,
     tTHIS = 302,
     tTHROW = 303,
     tTHROWS = 304,
     tTRANSIENT = 305,
     tTRY = 306,
     tVOID = 307,
     tVOLATILE = 308,
     tWHILE = 309,
     tEQ = 310,
     tLEQ = 311,
     tGEQ = 312,
     tNEQ = 313,
     tAND = 314,
     tOR = 315,
     tINC = 316,
     tPATH = 317,
     tERROR = 318,
     tDEC = 319,
     tPLUSEQ = 320,
     tMINUSEQ = 321,
     tANDEQ = 322,
     tDIVEQ = 323,
     tMODEQ = 324,
     tOREQ = 325,
     tTIMESEQ = 326,
     tINTCONST = 327,
     tBOOLCONST = 328,
     tCHARCONST = 329,
     tSTRINGCONST = 330,
     tIDENTIFIER = 331
   };
#endif
/* Tokens.  */
#define tABSTRACT 258
#define tBOOLEAN 259
#define tBREAK 260
#define tBYTE 261
#define tCASE 262
#define tCATCH 263
#define tCHAR 264
#define tCLASS 265
#define tCONST 266
#define tCONTINUE 267
#define tDEFAULT 268
#define tDO 269
#define tDOUBLE 270
#define tELSE 271
#define tEXTENDS 272
#define tEXTERN 273
#define tFINAL 274
#define tFINALLY 275
#define tFLOAT 276
#define tFOR 277
#define tGOTO 278
#define tIF 279
#define tIMPLEMENTS 280
#define tIMPORT 281
#define tIN 282
#define tINSTANCEOF 283
#define tINT 284
#define tINTERFACE 285
#define tLONG 286
#define tMAIN 287
#define tMAINARGV 288
#define tNATIVE 289
#define tNEW 290
#define tNULL 291
#define tPACKAGE 292
#define tPRIVATE 293
#define tPROTECTED 294
#define tPUBLIC 295
#define tRETURN 296
#define tSHORT 297
#define tSTATIC 298
#define tSUPER 299
#define tSWITCH 300
#define tSYNCHRONIZED 301
#define tTHIS 302
#define tTHROW 303
#define tTHROWS 304
#define tTRANSIENT 305
#define tTRY 306
#define tVOID 307
#define tVOLATILE 308
#define tWHILE 309
#define tEQ 310
#define tLEQ 311
#define tGEQ 312
#define tNEQ 313
#define tAND 314
#define tOR 315
#define tINC 316
#define tPATH 317
#define tERROR 318
#define tDEC 319
#define tPLUSEQ 320
#define tMINUSEQ 321
#define tANDEQ 322
#define tDIVEQ 323
#define tMODEQ 324
#define tOREQ 325
#define tTIMESEQ 326
#define tINTCONST 327
#define tBOOLCONST 328
#define tCHARCONST 329
#define tSTRINGCONST 330
#define tIDENTIFIER 331




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "joos.y"

   struct CLASSFILE *classfile;
   struct CLASS *class;
   struct FIELD *field;
   struct TYPE *type;
   struct ID *id;
   struct CONSTRUCTOR *constructor;
   struct METHOD *method;
   struct FORMAL *formal;
   struct STATEMENT *statement;
   struct EXP *exp;
   struct RECEIVER *receiver;
   struct ARGUMENT *argument;
   int modifier;
   int intconst;
   int boolconst;
   char charconst;
   char *stringconst;



/* Line 214 of yacc.c  */
#line 294 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 306 "y.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1055

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  374

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,     2,     2,     2,    92,     2,     2,
      81,    82,    90,    88,    80,    89,    94,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    79,
      86,    85,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    83,     2,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,    78,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,     9,    12,    23,    24,    26,
      28,    30,    33,    46,    47,    50,    52,    54,    56,    58,
      59,    61,    63,    66,    71,    73,    77,    79,    82,    96,
      98,   101,   108,   109,   111,   113,   117,   120,   121,   123,
     125,   128,   139,   149,   158,   169,   171,   173,   178,   183,
     184,   186,   188,   191,   200,   208,   210,   212,   214,   216,
     218,   219,   221,   223,   226,   228,   230,   232,   234,   236,
     238,   242,   244,   248,   250,   252,   258,   266,   268,   270,
     272,   274,   282,   288,   294,   304,   313,   322,   330,   339,
     347,   355,   362,   372,   381,   390,   398,   407,   415,   423,
     430,   433,   435,   437,   439,   443,   444,   446,   450,   453,
     456,   459,   462,   466,   470,   474,   478,   482,   486,   490,
     492,   494,   496,   500,   502,   506,   508,   512,   516,   518,
     522,   526,   530,   534,   538,   540,   544,   548,   550,   554,
     558,   562,   564,   567,   569,   572,   574,   579,   584,   586,
     588,   590,   592,   596,   598,   600,   606,   613,   615,   617,
     619,   620,   622,   624,   628,   630,   632,   634,   636
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      96,     0,    -1,    97,    98,    -1,   100,    -1,    -1,    97,
      62,    -1,    40,    99,    10,    76,   102,    77,   104,   108,
     115,    78,    -1,    -1,    19,    -1,     3,    -1,   101,    -1,
     100,   101,    -1,    18,    40,    99,    10,    76,   102,    27,
      75,    77,   110,   120,    78,    -1,    -1,    17,    76,    -1,
      76,    -1,     9,    -1,     4,    -1,    29,    -1,    -1,   105,
      -1,   106,    -1,   105,   106,    -1,    39,   103,   107,    79,
      -1,    76,    -1,   107,    80,    76,    -1,   109,    -1,   108,
     109,    -1,    40,    76,    81,   112,    82,    77,    44,    81,
     158,    82,    79,   125,    78,    -1,   111,    -1,   110,   111,
      -1,    40,    76,    81,   112,    82,    79,    -1,    -1,   113,
      -1,   114,    -1,   113,    80,   114,    -1,   103,    76,    -1,
      -1,   116,    -1,   117,    -1,   116,   117,    -1,    40,   118,
     124,    76,    81,   112,    82,    77,   125,    78,    -1,    40,
     124,    76,    81,   112,    82,    77,   125,    78,    -1,    40,
       3,   124,    76,    81,   112,    82,    79,    -1,    40,    43,
      52,    32,    81,   119,    82,    77,   125,    78,    -1,    19,
      -1,    46,    -1,    76,    76,    83,    84,    -1,    76,    83,
      84,    76,    -1,    -1,   121,    -1,   122,    -1,   121,   122,
      -1,    40,   123,   124,    76,    81,   112,    82,    79,    -1,
      40,   124,    76,    81,   112,    82,    79,    -1,    19,    -1,
       3,    -1,    46,    -1,    52,    -1,   103,    -1,    -1,   126,
      -1,   127,    -1,   126,   127,    -1,   129,    -1,   128,    -1,
     130,    -1,   131,    -1,   134,    -1,   136,    -1,   103,   107,
      79,    -1,    79,    -1,    77,   125,    78,    -1,   138,    -1,
     140,    -1,    24,    81,   143,    82,   127,    -1,    24,    81,
     143,    82,   132,    16,   127,    -1,   129,    -1,   133,    -1,
     135,    -1,   137,    -1,    24,    81,   143,    82,   132,    16,
     132,    -1,    54,    81,   143,    82,   127,    -1,    54,    81,
     143,    82,   132,    -1,    22,    81,   139,    79,   143,    79,
     139,    82,   127,    -1,    22,    81,   139,    79,   143,    79,
      82,   127,    -1,    22,    81,   139,    79,    79,   139,    82,
     127,    -1,    22,    81,   139,    79,    79,    82,   127,    -1,
      22,    81,    79,   143,    79,   139,    82,   127,    -1,    22,
      81,    79,   143,    79,    82,   127,    -1,    22,    81,    79,
      79,   139,    82,   127,    -1,    22,    81,    79,    79,    82,
     127,    -1,    22,    81,   139,    79,   143,    79,   139,    82,
     132,    -1,    22,    81,   139,    79,   143,    79,    82,   132,
      -1,    22,    81,   139,    79,    79,   139,    82,   132,    -1,
      22,    81,   139,    79,    79,    82,   132,    -1,    22,    81,
      79,   143,    79,   139,    82,   132,    -1,    22,    81,    79,
     143,    79,    82,   132,    -1,    22,    81,    79,    79,   139,
      82,   132,    -1,    22,    81,    79,    79,    82,   132,    -1,
     139,    79,    -1,   142,    -1,   156,    -1,   155,    -1,    41,
     141,    79,    -1,    -1,   143,    -1,    76,    85,   143,    -1,
      76,    61,    -1,    76,    64,    -1,    61,    76,    -1,    64,
      76,    -1,    76,    65,   143,    -1,    76,    66,   143,    -1,
      76,    68,   143,    -1,    76,    71,   143,    -1,    76,    69,
     143,    -1,    76,    67,   143,    -1,    76,    70,   143,    -1,
     144,    -1,   142,    -1,   145,    -1,   144,    60,   145,    -1,
     146,    -1,   145,    59,   146,    -1,   147,    -1,   146,    55,
     147,    -1,   146,    58,   147,    -1,   148,    -1,   147,    86,
     148,    -1,   147,    87,   148,    -1,   147,    56,   148,    -1,
     147,    57,   148,    -1,   147,    28,    76,    -1,   149,    -1,
     148,    88,   149,    -1,   148,    89,   149,    -1,   150,    -1,
     149,    90,   150,    -1,   149,    91,   150,    -1,   149,    92,
     150,    -1,   151,    -1,    89,   150,    -1,   153,    -1,    93,
     150,    -1,   152,    -1,    81,   143,    82,   151,    -1,    81,
       9,    82,   150,    -1,    76,    -1,   154,    -1,   160,    -1,
      47,    -1,    81,   143,    82,    -1,   155,    -1,   156,    -1,
      35,    76,    81,   158,    82,    -1,   157,    94,    76,    81,
     158,    82,    -1,    76,    -1,   154,    -1,    44,    -1,    -1,
     159,    -1,   143,    -1,   159,    80,   143,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    88,    92,    93,    96,   102,   103,   105,
     109,   111,   115,   121,   122,   126,   128,   130,   132,   137,
     138,   142,   144,   148,   152,   154,   158,   160,   164,   175,
     177,   181,   186,   187,   191,   193,   197,   202,   203,   207,
     209,   213,   215,   217,   219,   223,   225,   229,   231,   236,
     237,   241,   243,   247,   249,   253,   255,   257,   262,   264,
     269,   270,   274,   276,   280,   282,   284,   286,   288,   290,
     294,   298,   300,   302,   304,   308,   312,   316,   318,   320,
     322,   326,   331,   335,   339,   343,   347,   351,   355,   357,
     359,   362,   367,   371,   375,   379,   383,   385,   387,   390,
     395,   399,   401,   403,   407,   412,   413,   417,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   439,   443,
     445,   449,   451,   455,   457,   461,   463,   465,   469,   471,
     473,   475,   477,   479,   483,   485,   487,   491,   493,   495,
     497,   501,   503,   508,   510,   512,   515,   518,   522,   524,
     528,   530,   532,   534,   536,   540,   544,   548,   550,   552,
     557,   558,   562,   564,   568,   570,   572,   574,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tABSTRACT", "tBOOLEAN", "tBREAK",
  "tBYTE", "tCASE", "tCATCH", "tCHAR", "tCLASS", "tCONST", "tCONTINUE",
  "tDEFAULT", "tDO", "tDOUBLE", "tELSE", "tEXTENDS", "tEXTERN", "tFINAL",
  "tFINALLY", "tFLOAT", "tFOR", "tGOTO", "tIF", "tIMPLEMENTS", "tIMPORT",
  "tIN", "tINSTANCEOF", "tINT", "tINTERFACE", "tLONG", "tMAIN",
  "tMAINARGV", "tNATIVE", "tNEW", "tNULL", "tPACKAGE", "tPRIVATE",
  "tPROTECTED", "tPUBLIC", "tRETURN", "tSHORT", "tSTATIC", "tSUPER",
  "tSWITCH", "tSYNCHRONIZED", "tTHIS", "tTHROW", "tTHROWS", "tTRANSIENT",
  "tTRY", "tVOID", "tVOLATILE", "tWHILE", "tEQ", "tLEQ", "tGEQ", "tNEQ",
  "tAND", "tOR", "tINC", "tPATH", "tERROR", "tDEC", "tPLUSEQ", "tMINUSEQ",
  "tANDEQ", "tDIVEQ", "tMODEQ", "tOREQ", "tTIMESEQ", "tINTCONST",
  "tBOOLCONST", "tCHARCONST", "tSTRINGCONST", "tIDENTIFIER", "'{'", "'}'",
  "';'", "','", "'('", "')'", "'['", "']'", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'.'", "$accept", "classfile",
  "imports", "class", "classmods", "externclasses", "externclass",
  "extension", "type", "fields", "nefields", "field", "idlist",
  "constructors", "constructor", "externconstructors", "externconstructor",
  "formals", "neformals", "formal", "methods", "nemethods", "method",
  "methodmods", "mainargv", "externmethods", "externnemethods",
  "externmethod", "externmods", "returntype", "statements", "nestatements",
  "statement", "declaration", "simplestatement", "ifthenstatement",
  "ifthenelsestatement", "statementnoshortif",
  "ifthenelsestatementnoshortif", "whilestatement",
  "whilestatementnoshortif", "forstatement", "forstatementnoshortif",
  "expressionstatement", "statementexpression", "returnstatement",
  "returnexpression", "assignment", "expression", "orexpression",
  "andexpression", "eqexpression", "relexpression", "addexpression",
  "multexpression", "unaryexpression", "unaryexpressionnotminus",
  "castexpression", "postfixexpression", "primaryexpression",
  "classinstancecreation", "methodinvocation", "receiver", "arguments",
  "nearguments", "literal", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   123,   125,    59,
      44,    40,    41,    91,    93,    61,    60,    62,    43,    45,
      42,    47,    37,    33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    97,    97,    98,    99,    99,    99,
     100,   100,   101,   102,   102,   103,   103,   103,   103,   104,
     104,   105,   105,   106,   107,   107,   108,   108,   109,   110,
     110,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     128,   129,   129,   129,   129,   130,   131,   132,   132,   132,
     132,   133,   134,   135,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     138,   139,   139,   139,   140,   141,   141,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   148,   148,   148,   149,   149,   149,
     149,   150,   150,   151,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   154,   154,   155,   156,   157,   157,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,    10,     0,     1,     1,
       1,     2,    12,     0,     2,     1,     1,     1,     1,     0,
       1,     1,     2,     4,     1,     3,     1,     2,    13,     1,
       2,     6,     0,     1,     1,     3,     2,     0,     1,     1,
       2,    10,     9,     8,    10,     1,     1,     4,     4,     0,
       1,     1,     2,     8,     7,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     5,     7,     1,     1,     1,
       1,     7,     5,     5,     9,     8,     8,     7,     8,     7,
       7,     6,     9,     8,     8,     7,     8,     7,     7,     6,
       2,     1,     1,     1,     3,     0,     1,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     1,     2,     1,     4,     4,     1,     1,
       1,     1,     3,     1,     1,     5,     6,     1,     1,     1,
       0,     1,     1,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     3,    10,     7,     1,     7,     5,
       2,    11,     9,     8,     0,     0,     0,     0,    13,    13,
       0,     0,     0,    14,     0,    19,     0,     0,     0,    20,
      21,     0,    17,    16,    18,    15,     0,     0,    37,    26,
      22,     0,    49,    29,    24,     0,     0,     0,    27,     0,
      38,    39,     0,     0,    30,     0,    50,    51,    23,     0,
      32,     0,    45,     0,    46,    58,    15,    59,     0,     0,
       6,     0,    40,    32,    56,    55,    57,    15,     0,     0,
      12,     0,    52,    25,     0,     0,    33,    34,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,    32,     0,     0,    32,     0,    35,    32,     0,    32,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,     0,     0,     0,    60,     0,
      54,     0,   168,   159,   151,     0,     0,   164,   165,   166,
     167,   148,     0,     0,     0,   120,   162,   119,   121,   123,
     125,   128,   134,   137,   141,   145,   143,   149,   153,   154,
       0,     0,   161,   150,    43,     0,     0,    60,    60,     0,
       0,   105,     0,    15,    60,    71,     0,     0,     0,    61,
      62,    65,    64,    66,    67,    68,    69,    73,     0,    74,
     101,   158,   103,   102,    53,     0,   110,   111,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   142,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,    42,    63,   100,   160,   112,   113,   117,   114,
     116,   118,   115,   107,     0,   152,   122,   124,   126,   127,
     133,   131,   132,   129,   130,   135,   136,   138,   139,   140,
       0,    60,   163,    44,    41,   157,     0,     0,     0,   104,
       0,    72,   152,    70,     0,   147,   146,   160,     0,     0,
       0,     0,     0,     0,   155,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    64,     0,    78,    79,
      80,    82,   156,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    89,     0,    87,     0,     0,
       0,     0,     0,     0,     0,    76,    88,    86,    85,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    83,    99,     0,     0,     0,     0,     0,     0,
       0,    98,    97,     0,    95,     0,     0,     0,    81,    96,
      94,    93,     0,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,     4,     5,    21,   177,    28,
      29,    30,    45,    38,    39,    42,    43,    85,    86,    87,
      49,    50,    51,    68,   117,    55,    56,    57,    78,    69,
     178,   179,   180,   181,   182,   183,   184,   307,   308,   185,
     309,   186,   310,   187,   188,   189,   236,   190,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -243
static const yytype_int16 yypact[] =
{
      -9,   -12,    44,   -21,    -9,  -243,     2,  -243,     2,  -243,
    -243,  -243,  -243,  -243,    46,    48,    -6,     5,    67,    67,
      10,    65,    16,  -243,    19,    59,    22,    14,    62,    59,
    -243,    63,  -243,  -243,  -243,  -243,    31,    42,    79,  -243,
    -243,    47,    80,  -243,  -243,   -67,    49,     7,  -243,    51,
      91,  -243,    54,   105,  -243,    64,    92,  -243,  -243,    61,
      14,    25,  -243,    88,  -243,  -243,    49,  -243,    25,    70,
    -243,    28,  -243,    14,  -243,  -243,  -243,    54,    25,    71,
    -243,   272,  -243,  -243,    72,    68,    69,  -243,    76,   109,
      78,    75,    77,    82,    85,  -243,    83,    14,    87,    93,
      95,    14,    84,    96,    14,   118,  -243,    14,   103,    14,
      98,  -243,    14,   100,   104,   108,   -61,   112,   114,   120,
     117,   123,   444,   124,   122,   126,   129,   130,   608,   134,
    -243,   132,  -243,  -243,  -243,   138,   141,  -243,  -243,  -243,
    -243,   402,   517,   749,   749,  -243,  -243,   159,   163,   -41,
      -8,   -64,    35,  -243,  -243,  -243,  -243,   136,  -243,  -243,
     139,   142,   143,  -243,  -243,   144,   158,   608,   608,   155,
     160,   444,   161,   402,   608,  -243,   444,    31,   162,   608,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   166,  -243,
    -243,  -243,   145,   156,  -243,   171,  -243,  -243,  -243,  -243,
     444,   444,   444,   444,   444,   444,   444,   444,   174,   175,
     164,  -243,  -243,   749,   749,   749,   749,   183,   749,   749,
     749,   749,   749,   749,   749,   749,   749,   185,   186,   444,
    -243,  -243,   188,   189,   941,   444,   191,  -243,   444,   194,
     180,   -19,  -243,  -243,  -243,   444,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,   749,   260,   163,   -41,    -8,    -8,
    -243,   -64,   -64,   -64,   -64,    35,    35,  -243,  -243,  -243,
     182,   608,  -243,  -243,  -243,   347,   655,   199,   197,  -243,
     202,  -243,  -243,  -243,   203,  -243,  -243,   444,   208,   773,
     209,   679,   632,   608,  -243,   205,  -243,   608,   207,   792,
     815,   211,   218,   225,   229,  -243,   248,   276,  -243,  -243,
    -243,  -243,  -243,  -243,   608,   608,   230,   608,   234,   834,
     960,   444,   444,   608,  -243,  -243,   608,  -243,   608,   608,
     239,   702,   243,   241,   245,  -243,  -243,  -243,  -243,   608,
     857,   249,   726,   632,   632,  -243,   632,   247,   876,   899,
     251,   321,  -243,  -243,   632,   632,   258,   632,   261,   918,
     632,  -243,  -243,   632,  -243,   632,   632,   262,  -243,  -243,
    -243,  -243,   632,  -243
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,  -243,   334,  -243,   341,   328,   278,  -243,
    -243,   325,   173,  -243,   317,  -243,   315,    66,  -243,   263,
    -243,  -243,   308,  -243,  -243,  -243,  -243,   305,  -243,   -26,
    -166,  -243,   184,  -243,   259,  -243,  -243,   683,  -243,  -243,
    -243,  -243,  -243,  -243,  -204,  -243,  -243,   255,  -138,  -243,
     149,   150,  -143,  -108,  -147,  -137,   110,  -243,  -243,  -128,
     -46,    81,  -243,  -242,  -243,  -243
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -159
static const yytype_int16 yytable[] =
{
     191,   232,   233,   284,   209,    12,   211,   212,   239,     1,
      61,    32,    58,    59,   215,   124,    33,   216,    32,     8,
     217,    13,   125,    33,   222,   223,    62,    79,     6,    32,
     277,    61,    32,   237,    33,    88,    34,    33,   240,   191,
     191,     9,    90,    34,     7,   295,   191,    62,   218,   219,
      63,   191,    93,    64,    34,    79,    16,    34,    17,    65,
     283,    59,   246,   247,   248,   249,   250,   251,   252,   253,
      18,    63,   258,   259,    64,   265,   266,    65,   220,   221,
      65,    19,   192,    66,    20,   298,    23,   267,   268,   269,
      35,   272,    24,    25,    26,   316,   318,   278,    27,    31,
     280,    35,    37,    41,    35,   288,   191,    44,    74,    32,
     261,   262,   263,   264,    33,   330,   332,   285,    46,    47,
      53,   192,   192,    52,    75,   224,   225,   226,   192,    70,
      60,    71,    81,   192,    34,    73,   347,    83,   290,    92,
      89,    99,    80,   191,   356,   358,    91,    94,    95,    97,
      96,    76,    98,   301,   100,   367,   101,    65,   103,   102,
     105,   191,   114,   111,   191,   191,   104,   110,   107,   191,
     113,   191,   191,   115,   108,   118,   109,   112,   120,   116,
     119,    77,   121,   333,   334,   122,   191,   191,   192,   191,
     123,   191,   191,   341,   126,   191,   127,   128,   191,   129,
     191,   191,   130,   164,   350,   165,   167,   168,   195,   193,
     166,   191,   191,   194,   196,   191,   191,   197,   191,   213,
     191,   191,   214,   229,   228,   192,   191,   191,   230,   191,
    -158,   191,   191,   227,   231,   191,   234,   191,   191,  -153,
     242,   235,   238,   192,   191,   244,   192,   192,   193,   193,
    -154,   192,   245,   192,   192,   193,   254,   255,  -157,   260,
     193,   270,   282,   287,   -77,   271,   273,   274,   192,   192,
     279,   192,   281,   192,   192,    74,    32,   192,   291,   292,
     192,    33,   192,   192,   293,   294,   296,   312,   299,   314,
     319,    75,   323,   192,   192,   131,   132,   192,   192,   320,
     192,    34,   192,   192,   133,    36,   321,   134,   192,   192,
     322,   192,   326,   192,   192,   193,   328,   192,    76,   192,
     192,   339,   342,   343,    65,    67,   192,   344,   348,   354,
     359,    67,   137,   138,   139,   140,   210,   360,    84,    67,
     363,   142,    15,   365,   372,    11,    67,    22,    35,    67,
     241,    84,   193,   144,    40,    48,    67,    54,    72,    67,
     106,    82,   256,   243,   257,   286,     0,     0,     0,     0,
     193,     0,     0,   193,   193,    84,     0,   145,   193,    84,
     193,   193,    84,     0,     0,    84,     0,    84,     0,     0,
      84,     0,     0,     0,     0,   193,   193,   145,   193,     0,
     193,   193,     0,     0,   193,     0,     0,   193,   198,   193,
     193,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     193,   193,     0,     0,   193,   193,   145,   193,     0,   193,
     193,   145,   207,     0,     0,   193,   193,     0,   193,     0,
     193,   193,     0,     0,   193,     0,   193,   193,     0,     0,
       0,     0,     0,   193,     0,   145,   145,   145,   145,   145,
     145,   145,   145,   198,     0,     0,   199,   200,   201,   202,
     203,   204,   205,   206,     0,     0,   305,   311,     0,   131,
     132,   313,     0,     0,   145,     0,     0,   207,   133,     0,
     145,   134,     0,   145,     0,     0,  -157,     0,   324,   325,
     145,   327,     0,     0,     0,   135,     0,   335,   136,     0,
     336,     0,   337,   338,     0,     0,   137,   138,   139,   140,
     141,     0,     0,   345,     0,   142,   208,   305,   311,     0,
     313,   145,     0,   143,     0,     0,     0,   144,   324,   325,
       0,   327,   145,     0,   335,     0,   145,   336,     0,   337,
     338,   306,   131,   132,     0,     0,   345,     0,     0,     0,
       0,   133,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   145,   135,     0,
       0,   136,     0,     0,     0,     0,   145,     0,     0,   137,
     138,   139,   140,   141,     0,     0,     0,   145,   142,     0,
       0,     0,   306,   306,     0,   306,   143,     0,     0,     0,
     144,     0,    32,   306,   306,     0,   306,    33,     0,   306,
       0,     0,   306,     0,   306,   306,     0,     0,     0,     0,
     169,   306,   170,     0,     0,     0,    32,    34,     0,     0,
       0,    33,     0,   131,   132,     0,     0,     0,     0,   171,
       0,     0,   133,     0,   302,   134,   303,     0,     0,     0,
       0,    34,   172,     0,     0,     0,     0,   131,   132,   135,
       0,     0,   136,   171,     0,     0,   133,     0,     0,   134,
     137,   138,   139,   140,   173,   174,   304,   175,     0,   176,
     131,   132,     0,   135,     0,     0,   136,     0,     0,   133,
       0,     0,   134,     0,   137,   138,   139,   140,   173,   174,
       0,   175,     0,   176,   131,   132,   135,     0,     0,   136,
       0,     0,     0,   133,     0,     0,   134,   137,   138,   139,
     140,   141,     0,     0,   289,     0,   142,   131,   132,     0,
     135,     0,     0,   136,   143,     0,   133,     0,   144,   134,
       0,   137,   138,   139,   140,   141,     0,     0,   300,     0,
     142,   131,   132,   135,     0,     0,   136,     0,   143,     0,
     133,     0,   144,   134,   137,   138,   139,   140,   141,     0,
       0,   340,     0,   142,   131,   132,     0,   135,     0,     0,
     136,   143,     0,   133,     0,   144,   134,     0,   137,   138,
     139,   140,   141,     0,     0,   349,     0,   142,   131,   132,
       0,     0,     0,     0,     0,   143,     0,   133,     0,   144,
     134,   137,   138,   139,   140,   210,     0,   131,   132,     0,
     142,     0,     0,     0,   135,     0,   133,   136,   143,   134,
       0,     0,   144,     0,     0,   137,   138,   139,   140,   275,
     131,   132,     0,   135,   176,   297,   136,     0,     0,   133,
       0,     0,   134,     0,   137,   138,   139,   140,   275,   131,
     132,     0,     0,   176,   315,     0,   135,     0,   133,   136,
       0,   134,     0,     0,     0,     0,     0,   137,   138,   139,
     140,   275,   131,   132,     0,   135,   176,   317,   136,     0,
       0,   133,     0,     0,   134,     0,   137,   138,   139,   140,
     275,   131,   132,     0,     0,   176,   329,     0,   135,     0,
     133,   136,     0,   134,     0,     0,     0,     0,     0,   137,
     138,   139,   140,   275,   131,   132,     0,   135,   176,   346,
     136,     0,     0,   133,     0,     0,   134,     0,   137,   138,
     139,   140,   275,   131,   132,     0,     0,   176,   355,     0,
     135,     0,   133,   136,     0,   134,     0,     0,     0,     0,
       0,   137,   138,   139,   140,   275,   131,   132,     0,   135,
     176,   357,   136,     0,     0,   133,     0,     0,   134,     0,
     137,   138,   139,   140,   275,   131,   132,     0,     0,   176,
     366,     0,   135,     0,   133,   136,     0,   134,     0,     0,
       0,     0,     0,   137,   138,   139,   140,   275,     0,     0,
     276,   135,   176,     0,   136,     0,   351,   352,     0,   353,
       0,     0,   137,   138,   139,   140,   275,   361,   362,   331,
     364,   176,     0,   368,     0,     0,   369,     0,   370,   371,
       0,     0,     0,     0,     0,   373
};

static const yytype_int16 yycheck[] =
{
     128,   167,   168,   245,   142,     3,   143,   144,   174,    18,
       3,     4,    79,    80,    55,    76,     9,    58,     4,    40,
      28,    19,    83,     9,    88,    89,    19,    53,    40,     4,
     234,     3,     4,   171,     9,    61,    29,     9,   176,   167,
     168,    62,    68,    29,     0,   287,   174,    19,    56,    57,
      43,   179,    78,    46,    29,    81,    10,    29,    10,    52,
      79,    80,   200,   201,   202,   203,   204,   205,   206,   207,
      76,    43,   215,   216,    46,   222,   223,    52,    86,    87,
      52,    76,   128,    76,    17,   289,    76,   224,   225,   226,
      76,   229,    27,    77,    75,   299,   300,   235,    39,    77,
     238,    76,    40,    40,    76,   271,   234,    76,     3,     4,
     218,   219,   220,   221,     9,   319,   320,   254,    76,    40,
      40,   167,   168,    76,    19,    90,    91,    92,   174,    78,
      81,    40,    40,   179,    29,    81,   340,    76,   276,    73,
      52,    32,    78,   271,   348,   349,    76,    76,    76,    80,
      82,    46,    76,   291,    76,   359,    81,    52,    76,    82,
      77,   289,    44,    79,   292,   293,    81,   101,    81,   297,
     104,   299,   300,   107,    81,   109,    81,    81,   112,    76,
      82,    76,    82,   321,   322,    81,   314,   315,   234,   317,
      82,   319,   320,   331,    82,   323,    82,    77,   326,    82,
     328,   329,    79,    79,   342,    83,    77,    77,    76,   128,
      84,   339,   340,    79,    76,   343,   344,    76,   346,    60,
     348,   349,    59,    80,    82,   271,   354,   355,    84,   357,
      94,   359,   360,    94,    76,   363,    81,   365,   366,    94,
      78,    81,    81,   289,   372,    79,   292,   293,   167,   168,
      94,   297,    81,   299,   300,   174,    82,    82,    94,    76,
     179,    76,    82,    81,    16,    79,    78,    78,   314,   315,
      79,   317,    78,   319,   320,     3,     4,   323,    79,    82,
     326,     9,   328,   329,    82,    82,    78,    82,    79,    82,
      79,    19,    16,   339,   340,    35,    36,   343,   344,    81,
     346,    29,   348,   349,    44,    27,    81,    47,   354,   355,
      81,   357,    82,   359,   360,   234,    82,   363,    46,   365,
     366,    82,    79,    82,    52,    47,   372,    82,    79,    82,
      79,    53,    72,    73,    74,    75,    76,    16,    60,    61,
      82,    81,     8,    82,    82,     4,    68,    19,    76,    71,
     177,    73,   271,    93,    29,    38,    78,    42,    50,    81,
      97,    56,   213,   179,   214,   255,    -1,    -1,    -1,    -1,
     289,    -1,    -1,   292,   293,    97,    -1,   122,   297,   101,
     299,   300,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,   314,   315,   142,   317,    -1,
     319,   320,    -1,    -1,   323,    -1,    -1,   326,    61,   328,
     329,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
     339,   340,    -1,    -1,   343,   344,   171,   346,    -1,   348,
     349,   176,    85,    -1,    -1,   354,   355,    -1,   357,    -1,
     359,   360,    -1,    -1,   363,    -1,   365,   366,    -1,    -1,
      -1,    -1,    -1,   372,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,   292,   293,    -1,    35,
      36,   297,    -1,    -1,   229,    -1,    -1,    85,    44,    -1,
     235,    47,    -1,   238,    -1,    -1,    94,    -1,   314,   315,
     245,   317,    -1,    -1,    -1,    61,    -1,   323,    64,    -1,
     326,    -1,   328,   329,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    -1,   339,    -1,    81,     9,   343,   344,    -1,
     346,   276,    -1,    89,    -1,    -1,    -1,    93,   354,   355,
      -1,   357,   287,    -1,   360,    -1,   291,   363,    -1,   365,
     366,   292,    35,    36,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   321,   322,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,   331,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    -1,    -1,   342,    81,    -1,
      -1,    -1,   343,   344,    -1,   346,    89,    -1,    -1,    -1,
      93,    -1,     4,   354,   355,    -1,   357,     9,    -1,   360,
      -1,    -1,   363,    -1,   365,   366,    -1,    -1,    -1,    -1,
      22,   372,    24,    -1,    -1,    -1,     4,    29,    -1,    -1,
      -1,     9,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    22,    47,    24,    -1,    -1,    -1,
      -1,    29,    54,    -1,    -1,    -1,    -1,    35,    36,    61,
      -1,    -1,    64,    41,    -1,    -1,    44,    -1,    -1,    47,
      72,    73,    74,    75,    76,    77,    54,    79,    -1,    81,
      35,    36,    -1,    61,    -1,    -1,    64,    -1,    -1,    44,
      -1,    -1,    47,    -1,    72,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    35,    36,    61,    -1,    -1,    64,
      -1,    -1,    -1,    44,    -1,    -1,    47,    72,    73,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    35,    36,    -1,
      61,    -1,    -1,    64,    89,    -1,    44,    -1,    93,    47,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    35,    36,    61,    -1,    -1,    64,    -1,    89,    -1,
      44,    -1,    93,    47,    72,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    35,    36,    -1,    61,    -1,    -1,
      64,    89,    -1,    44,    -1,    93,    47,    -1,    72,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    35,    36,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    44,    -1,    93,
      47,    72,    73,    74,    75,    76,    -1,    35,    36,    -1,
      81,    -1,    -1,    -1,    61,    -1,    44,    64,    89,    47,
      -1,    -1,    93,    -1,    -1,    72,    73,    74,    75,    76,
      35,    36,    -1,    61,    81,    82,    64,    -1,    -1,    44,
      -1,    -1,    47,    -1,    72,    73,    74,    75,    76,    35,
      36,    -1,    -1,    81,    82,    -1,    61,    -1,    44,    64,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    35,    36,    -1,    61,    81,    82,    64,    -1,
      -1,    44,    -1,    -1,    47,    -1,    72,    73,    74,    75,
      76,    35,    36,    -1,    -1,    81,    82,    -1,    61,    -1,
      44,    64,    -1,    47,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    35,    36,    -1,    61,    81,    82,
      64,    -1,    -1,    44,    -1,    -1,    47,    -1,    72,    73,
      74,    75,    76,    35,    36,    -1,    -1,    81,    82,    -1,
      61,    -1,    44,    64,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    35,    36,    -1,    61,
      81,    82,    64,    -1,    -1,    44,    -1,    -1,    47,    -1,
      72,    73,    74,    75,    76,    35,    36,    -1,    -1,    81,
      82,    -1,    61,    -1,    44,    64,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    -1,
      79,    61,    81,    -1,    64,    -1,   343,   344,    -1,   346,
      -1,    -1,    72,    73,    74,    75,    76,   354,   355,    79,
     357,    81,    -1,   360,    -1,    -1,   363,    -1,   365,   366,
      -1,    -1,    -1,    -1,    -1,   372
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    96,    97,   100,   101,    40,     0,    40,    62,
      98,   101,     3,    19,    99,    99,    10,    10,    76,    76,
      17,   102,   102,    76,    27,    77,    75,    39,   104,   105,
     106,    77,     4,     9,    29,    76,   103,    40,   108,   109,
     106,    40,   110,   111,    76,   107,    76,    40,   109,   115,
     116,   117,    76,    40,   111,   120,   121,   122,    79,    80,
      81,     3,    19,    43,    46,    52,    76,   103,   118,   124,
      78,    40,   117,    81,     3,    19,    46,    76,   123,   124,
      78,    40,   122,    76,   103,   112,   113,   114,   124,    52,
     124,    76,   112,   124,    76,    76,    82,    80,    76,    32,
      76,    81,    82,    76,    81,    77,   114,    81,    81,    81,
     112,    79,    81,   112,    44,   112,    76,   119,   112,    82,
     112,    82,    81,    82,    76,    83,    82,    82,    77,    82,
      79,    35,    36,    44,    47,    61,    64,    72,    73,    74,
      75,    76,    81,    89,    93,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    79,    83,    84,    77,    77,    22,
      24,    41,    54,    76,    77,    79,    81,   103,   125,   126,
     127,   128,   129,   130,   131,   134,   136,   138,   139,   140,
     142,   154,   155,   156,    79,    76,    76,    76,    61,    64,
      65,    66,    67,    68,    69,    70,    71,    85,     9,   143,
      76,   150,   150,    60,    59,    55,    58,    28,    56,    57,
      86,    87,    88,    89,    90,    91,    92,    94,    82,    80,
      84,    76,   125,   125,    81,    81,   141,   143,    81,   125,
     143,   107,    78,   127,    79,    81,   143,   143,   143,   143,
     143,   143,   143,   143,    82,    82,   145,   146,   147,   147,
      76,   148,   148,   148,   148,   149,   149,   150,   150,   150,
      76,    79,   143,    78,    78,    76,    79,   139,   143,    79,
     143,    78,    82,    79,   158,   150,   151,    81,   125,    79,
     143,    79,    82,    82,    82,   158,    78,    82,   139,    79,
      79,   143,    22,    24,    54,   127,   129,   132,   133,   135,
     137,   127,    82,   127,    82,    82,   139,    82,   139,    79,
      81,    81,    81,    16,   127,   127,    82,   127,    82,    82,
     139,    79,   139,   143,   143,   127,   127,   127,   127,    82,
      79,   143,    79,    82,    82,   127,    82,   139,    79,    79,
     143,   132,   132,   132,    82,    82,   139,    82,   139,    79,
      16,   132,   132,    82,   132,    82,    82,   139,   132,   132,
     132,   132,    82,   132
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
#line 87 "joos.y"
    {theclassfile = makeCLASSFILE((yyvsp[(2) - (2)].class),NULL);}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 89 "joos.y"
    {theclassfile = (yyvsp[(1) - (1)].classfile);}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 98 "joos.y"
    {(yyval.class) = makeCLASS((yyvsp[(4) - (10)].stringconst),(yyvsp[(5) - (10)].stringconst),0,NULL,(yyvsp[(2) - (10)].modifier),(yyvsp[(7) - (10)].field),(yyvsp[(8) - (10)].constructor),(yyvsp[(9) - (10)].method));}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 102 "joos.y"
    {(yyval.modifier) = noneMod;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 104 "joos.y"
    {(yyval.modifier) = finalMod;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 106 "joos.y"
    {(yyval.modifier) = abstractMod;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 110 "joos.y"
    {(yyval.classfile) = makeCLASSFILE((yyvsp[(1) - (1)].class),NULL);}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 112 "joos.y"
    {(yyval.classfile) = makeCLASSFILE((yyvsp[(2) - (2)].class),(yyvsp[(1) - (2)].classfile));}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 117 "joos.y"
    {(yyval.class) = makeCLASS((yyvsp[(5) - (12)].stringconst),(yyvsp[(6) - (12)].stringconst),1,(yyvsp[(8) - (12)].stringconst),(yyvsp[(3) - (12)].modifier),NULL,(yyvsp[(10) - (12)].constructor),(yyvsp[(11) - (12)].method));}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 121 "joos.y"
    {(yyval.stringconst) = NULL;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 123 "joos.y"
    {(yyval.stringconst) = (yyvsp[(2) - (2)].stringconst);}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 127 "joos.y"
    {(yyval.type) = makeTYPEref((yyvsp[(1) - (1)].stringconst));}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 129 "joos.y"
    {(yyval.type) = makeTYPEchar();}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 131 "joos.y"
    {(yyval.type) = makeTYPEbool();}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 133 "joos.y"
    {(yyval.type) = makeTYPEint();}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 137 "joos.y"
    {(yyval.field) = NULL;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 139 "joos.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 143 "joos.y"
    {(yyval.field) = (yyvsp[(1) - (1)].field);}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 145 "joos.y"
    {(yyval.field) = appendFIELD((yyvsp[(2) - (2)].field),(yyvsp[(1) - (2)].field));}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 149 "joos.y"
    {(yyval.field) = makeFIELDlist((yyvsp[(3) - (4)].id),(yyvsp[(2) - (4)].type));}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 153 "joos.y"
    {(yyval.id) = makeID((yyvsp[(1) - (1)].stringconst),NULL);}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 155 "joos.y"
    {(yyval.id) = makeID((yyvsp[(3) - (3)].stringconst),(yyvsp[(1) - (3)].id));}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 159 "joos.y"
    {(yyval.constructor) = (yyvsp[(1) - (1)].constructor);}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 161 "joos.y"
    {(yyval.constructor) = (yyvsp[(2) - (2)].constructor); (yyval.constructor)->next = (yyvsp[(1) - (2)].constructor);}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 166 "joos.y"
    {(yyval.constructor) = makeCONSTRUCTOR((yyvsp[(2) - (13)].stringconst),(yyvsp[(4) - (13)].formal),
                                    makeSTATEMENTsequence(
                                        makeSTATEMENTsupercons((yyvsp[(9) - (13)].argument)),
                                        (yyvsp[(12) - (13)].statement)
                                    ),
                                    NULL
                    );}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 176 "joos.y"
    {(yyval.constructor) = (yyvsp[(1) - (1)].constructor);}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 178 "joos.y"
    {(yyval.constructor) = (yyvsp[(2) - (2)].constructor); (yyval.constructor)->next = (yyvsp[(1) - (2)].constructor);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 182 "joos.y"
    {(yyval.constructor) = makeCONSTRUCTOR((yyvsp[(2) - (6)].stringconst),(yyvsp[(4) - (6)].formal),NULL,NULL);}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 186 "joos.y"
    {(yyval.formal) = NULL;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 188 "joos.y"
    {(yyval.formal) = (yyvsp[(1) - (1)].formal);}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 192 "joos.y"
    {(yyval.formal) = (yyvsp[(1) - (1)].formal);}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 194 "joos.y"
    {(yyval.formal) = (yyvsp[(3) - (3)].formal); (yyval.formal)->next = (yyvsp[(1) - (3)].formal);}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 198 "joos.y"
    {(yyval.formal) = makeFORMAL((yyvsp[(2) - (2)].stringconst),(yyvsp[(1) - (2)].type),NULL);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 202 "joos.y"
    {(yyval.method) = NULL;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 204 "joos.y"
    {(yyval.method) = (yyvsp[(1) - (1)].method);}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 208 "joos.y"
    {(yyval.method) = (yyvsp[(1) - (1)].method);}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 210 "joos.y"
    {(yyval.method) = (yyvsp[(2) - (2)].method); (yyval.method)->next = (yyvsp[(1) - (2)].method);}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 214 "joos.y"
    {(yyval.method) = makeMETHOD((yyvsp[(4) - (10)].stringconst),(yyvsp[(2) - (10)].modifier),(yyvsp[(3) - (10)].type),(yyvsp[(6) - (10)].formal),(yyvsp[(9) - (10)].statement),NULL);}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 216 "joos.y"
    {(yyval.method) = makeMETHOD((yyvsp[(3) - (9)].stringconst),noneMod,(yyvsp[(2) - (9)].type),(yyvsp[(5) - (9)].formal),(yyvsp[(8) - (9)].statement),NULL);}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 218 "joos.y"
    {(yyval.method) = makeMETHOD((yyvsp[(4) - (8)].stringconst),abstractMod,(yyvsp[(3) - (8)].type),(yyvsp[(6) - (8)].formal),NULL,NULL);}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 220 "joos.y"
    {(yyval.method) = makeMETHOD("main",staticMod,makeTYPEvoid(),NULL,(yyvsp[(9) - (10)].statement),NULL);}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 224 "joos.y"
    {(yyval.modifier) = finalMod;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 226 "joos.y"
    {(yyval.modifier) = synchronizedMod;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 230 "joos.y"
    {if (strcmp((yyvsp[(1) - (4)].stringconst),"String")!=0) yyerror("type String expected");}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 232 "joos.y"
    {if (strcmp((yyvsp[(1) - (4)].stringconst),"String")!=0) yyerror("type String expected");}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 236 "joos.y"
    {(yyval.method) = NULL;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 238 "joos.y"
    {(yyval.method) = (yyvsp[(1) - (1)].method);}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 242 "joos.y"
    {(yyval.method) = (yyvsp[(1) - (1)].method);}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 244 "joos.y"
    {(yyval.method) = (yyvsp[(2) - (2)].method); (yyval.method)->next = (yyvsp[(1) - (2)].method);}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 248 "joos.y"
    {(yyval.method) = makeMETHOD((yyvsp[(4) - (8)].stringconst),(yyvsp[(2) - (8)].modifier),(yyvsp[(3) - (8)].type),(yyvsp[(6) - (8)].formal),NULL,NULL);}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 250 "joos.y"
    {(yyval.method) = makeMETHOD((yyvsp[(3) - (7)].stringconst),noneMod,(yyvsp[(2) - (7)].type),(yyvsp[(5) - (7)].formal),NULL,NULL);}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 254 "joos.y"
    {(yyval.modifier) = finalMod;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 256 "joos.y"
    {(yyval.modifier) = abstractMod;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 258 "joos.y"
    {(yyval.modifier) = synchronizedMod;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 263 "joos.y"
    {(yyval.type) = makeTYPEvoid();}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 265 "joos.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 269 "joos.y"
    {(yyval.statement) = NULL;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 271 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 275 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 277 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence((yyvsp[(1) - (2)].statement),(yyvsp[(2) - (2)].statement));}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 281 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 283 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 285 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 287 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 289 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 291 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 295 "joos.y"
    {(yyval.statement) = makeSTATEMENTlocal(makeLOCALlist((yyvsp[(2) - (3)].id),(yyvsp[(1) - (3)].type)));}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 299 "joos.y"
    {(yyval.statement) = makeSTATEMENTskip();}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 301 "joos.y"
    {(yyval.statement) = makeSTATEMENTblock((yyvsp[(2) - (3)].statement));}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 303 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 305 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 309 "joos.y"
    {(yyval.statement) = makeSTATEMENTif((yyvsp[(3) - (5)].exp),(yyvsp[(5) - (5)].statement));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 313 "joos.y"
    {(yyval.statement) = makeSTATEMENTifelse((yyvsp[(3) - (7)].exp),(yyvsp[(5) - (7)].statement),(yyvsp[(7) - (7)].statement));}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 317 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 319 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 321 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 323 "joos.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 328 "joos.y"
    {(yyval.statement) = makeSTATEMENTifelse((yyvsp[(3) - (7)].exp),(yyvsp[(5) - (7)].statement),(yyvsp[(7) - (7)].statement));}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 332 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(3) - (5)].exp),(yyvsp[(5) - (5)].statement));}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 336 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(3) - (5)].exp),(yyvsp[(5) - (5)].statement));}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 340 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (9)].exp)),
                makeSTATEMENTwhile((yyvsp[(5) - (9)].exp),makeSTATEMENTsequence((yyvsp[(9) - (9)].statement),makeSTATEMENTexp((yyvsp[(7) - (9)].exp)))));
                }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 344 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (8)].exp)),
                makeSTATEMENTwhile((yyvsp[(5) - (8)].exp),(yyvsp[(8) - (8)].statement)));
                }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 348 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (8)].exp)),
                makeSTATEMENTwhile(makeEXPboolconst(1),makeSTATEMENTsequence((yyvsp[(8) - (8)].statement),makeSTATEMENTexp((yyvsp[(6) - (8)].exp)))));
                }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 352 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (7)].exp)),
                makeSTATEMENTwhile(makeEXPboolconst(1),(yyvsp[(7) - (7)].statement)));
                }
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 356 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(4) - (8)].exp),makeSTATEMENTsequence((yyvsp[(8) - (8)].statement),makeSTATEMENTexp((yyvsp[(6) - (8)].exp))));}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 358 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(4) - (7)].exp),(yyvsp[(7) - (7)].statement));}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 360 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile(makeEXPboolconst(1),makeSTATEMENTsequence((yyvsp[(7) - (7)].statement),makeSTATEMENTexp((yyvsp[(5) - (7)].exp))));
                }
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 363 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile(makeEXPboolconst(1), (yyvsp[(6) - (6)].statement));
                }
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 368 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (9)].exp)),
                makeSTATEMENTwhile((yyvsp[(5) - (9)].exp),makeSTATEMENTsequence((yyvsp[(9) - (9)].statement),makeSTATEMENTexp((yyvsp[(7) - (9)].exp)))));
                }
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 372 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (8)].exp)),
                makeSTATEMENTwhile((yyvsp[(5) - (8)].exp),(yyvsp[(8) - (8)].statement)));
                }
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 376 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (8)].exp)),
                makeSTATEMENTwhile(makeEXPboolconst(1),makeSTATEMENTsequence((yyvsp[(8) - (8)].statement),makeSTATEMENTexp((yyvsp[(6) - (8)].exp)))));
                }
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 380 "joos.y"
    {(yyval.statement) = makeSTATEMENTsequence(makeSTATEMENTexp((yyvsp[(3) - (7)].exp)),
                makeSTATEMENTwhile(makeEXPboolconst(1),(yyvsp[(7) - (7)].statement)));
                }
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 384 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(4) - (8)].exp),makeSTATEMENTsequence((yyvsp[(8) - (8)].statement),makeSTATEMENTexp((yyvsp[(6) - (8)].exp))));}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 386 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile((yyvsp[(4) - (7)].exp),(yyvsp[(7) - (7)].statement));}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 388 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile(makeEXPboolconst(1),makeSTATEMENTsequence((yyvsp[(7) - (7)].statement),makeSTATEMENTexp((yyvsp[(5) - (7)].exp))));
                }
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 391 "joos.y"
    {(yyval.statement) = makeSTATEMENTwhile(makeEXPboolconst(1), (yyvsp[(6) - (6)].statement));
                }
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 396 "joos.y"
    {(yyval.statement) = makeSTATEMENTexp((yyvsp[(1) - (2)].exp));}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 400 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 402 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 404 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 408 "joos.y"
    {(yyval.statement) = makeSTATEMENTreturn((yyvsp[(2) - (3)].exp));}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 412 "joos.y"
    {(yyval.exp) = NULL;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 414 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 418 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst),(yyvsp[(3) - (3)].exp));}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 420 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (2)].stringconst), makeEXPplus(makeEXPid((yyvsp[(1) - (2)].stringconst)), makeEXPintconst(1)));}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 422 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (2)].stringconst), makeEXPminus(makeEXPid((yyvsp[(1) - (2)].stringconst)), makeEXPintconst(1)));}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 424 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(2) - (2)].stringconst), makeEXPplus(makeEXPid((yyvsp[(2) - (2)].stringconst)), makeEXPintconst(1)));}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 426 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(2) - (2)].stringconst), makeEXPminus(makeEXPid((yyvsp[(2) - (2)].stringconst)), makeEXPintconst(1)));}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 428 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPplus(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 430 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPminus(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 432 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPdiv(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 434 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPtimes(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 436 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPmod(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 438 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPand(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 440 "joos.y"
    {(yyval.exp) = makeEXPassign((yyvsp[(1) - (3)].stringconst), makeEXPor(makeEXPid((yyvsp[(1) - (3)].stringconst)), (yyvsp[(3) - (3)].exp)));}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 444 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 446 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 450 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 452 "joos.y"
    {(yyval.exp) = makeEXPor((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 456 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 458 "joos.y"
    {(yyval.exp) = makeEXPand((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 462 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 464 "joos.y"
    {(yyval.exp) = makeEXPeq((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 466 "joos.y"
    {(yyval.exp) = makeEXPneq((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 470 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 472 "joos.y"
    {(yyval.exp) = makeEXPlt((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 474 "joos.y"
    {(yyval.exp) = makeEXPgt((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 476 "joos.y"
    {(yyval.exp) = makeEXPleq((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 478 "joos.y"
    {(yyval.exp) = makeEXPgeq((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 480 "joos.y"
    {(yyval.exp) = makeEXPinstanceof((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].stringconst));}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 484 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 486 "joos.y"
    {(yyval.exp) = makeEXPplus((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 488 "joos.y"
    {(yyval.exp) = makeEXPminus((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 492 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 494 "joos.y"
    {(yyval.exp) = makeEXPtimes((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 496 "joos.y"
    {(yyval.exp) = makeEXPdiv((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 498 "joos.y"
    {(yyval.exp) = makeEXPmod((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 502 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 504 "joos.y"
    {(yyval.exp) = makeEXPuminus((yyvsp[(2) - (2)].exp));}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 509 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 511 "joos.y"
    {(yyval.exp) = makeEXPnot((yyvsp[(2) - (2)].exp));}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 513 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 516 "joos.y"
    {if ((yyvsp[(2) - (4)].exp)->kind!=idK) yyerror("identifier expected");
                  (yyval.exp) = makeEXPcast((yyvsp[(2) - (4)].exp)->val.idE.name,(yyvsp[(4) - (4)].exp));}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 519 "joos.y"
    {(yyval.exp) = makeEXPcharcast((yyvsp[(4) - (4)].exp));}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 523 "joos.y"
    {(yyval.exp) = makeEXPid((yyvsp[(1) - (1)].stringconst));}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 525 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 529 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 531 "joos.y"
    {(yyval.exp) = makeEXPthis();}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 533 "joos.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp);}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 535 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 537 "joos.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 541 "joos.y"
    {(yyval.exp) = makeEXPnew((yyvsp[(2) - (5)].stringconst),(yyvsp[(4) - (5)].argument));}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 545 "joos.y"
    {(yyval.exp) = makeEXPinvoke((yyvsp[(1) - (6)].receiver),(yyvsp[(3) - (6)].stringconst),(yyvsp[(5) - (6)].argument));}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 549 "joos.y"
    {(yyval.receiver) = makeRECEIVERobject(makeEXPid((yyvsp[(1) - (1)].stringconst)));}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 551 "joos.y"
    {(yyval.receiver) = makeRECEIVERobject((yyvsp[(1) - (1)].exp));}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 553 "joos.y"
    {(yyval.receiver) = makeRECEIVERsuper();}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 557 "joos.y"
    {(yyval.argument) = NULL;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 559 "joos.y"
    {(yyval.argument) = (yyvsp[(1) - (1)].argument);}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 563 "joos.y"
    {(yyval.argument) = makeARGUMENT((yyvsp[(1) - (1)].exp),NULL);}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 565 "joos.y"
    {(yyval.argument) = makeARGUMENT((yyvsp[(3) - (3)].exp),(yyvsp[(1) - (3)].argument));}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 569 "joos.y"
    {(yyval.exp) = makeEXPintconst((yyvsp[(1) - (1)].intconst));}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 571 "joos.y"
    {(yyval.exp) = makeEXPboolconst((yyvsp[(1) - (1)].boolconst));}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 573 "joos.y"
    {(yyval.exp) = makeEXPcharconst((yyvsp[(1) - (1)].charconst));}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 575 "joos.y"
    {(yyval.exp) = makeEXPstringconst((yyvsp[(1) - (1)].stringconst));}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 577 "joos.y"
    {(yyval.exp) = makeEXPnull();}
    break;



/* Line 1464 of yacc.c  */
#line 3180 "y.tab.c"
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



