/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
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



/* Line 1685 of yacc.c  */
#line 225 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


