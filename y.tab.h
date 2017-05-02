/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    AND = 259,
    ASSIGN = 260,
    BOOL = 261,
    CLASS = 262,
    CCURV = 263,
    CBRACE = 264,
    CSQUARE = 265,
    DIV = 266,
    DO = 267,
    DOTLENGTH = 268,
    DOUBLE = 269,
    ELSE = 270,
    EQ = 271,
    GEQ = 272,
    GT = 273,
    INT = 274,
    LT = 275,
    LEQ = 276,
    MINUS = 277,
    MOD = 278,
    NEQ = 279,
    NOT = 280,
    OBRACE = 281,
    OCURV = 282,
    OR = 283,
    OSQUARE = 284,
    PARSEINT = 285,
    PLUS = 286,
    PRINT = 287,
    PUBLIC = 288,
    RESERVED = 289,
    RETURN = 290,
    SEMI = 291,
    STAR = 292,
    STATIC = 293,
    WHILE = 294,
    ESCAPESEQUENCE = 295,
    STRING = 296,
    COMMA = 297,
    BOOLLIT = 298,
    REALLIT = 299,
    DECLIT = 300,
    ID = 301,
    STRLIT = 302,
    VOID = 303,
    PRECEDENCE = 304,
    IFX = 305
  };
#endif
/* Tokens.  */
#define IF 258
#define AND 259
#define ASSIGN 260
#define BOOL 261
#define CLASS 262
#define CCURV 263
#define CBRACE 264
#define CSQUARE 265
#define DIV 266
#define DO 267
#define DOTLENGTH 268
#define DOUBLE 269
#define ELSE 270
#define EQ 271
#define GEQ 272
#define GT 273
#define INT 274
#define LT 275
#define LEQ 276
#define MINUS 277
#define MOD 278
#define NEQ 279
#define NOT 280
#define OBRACE 281
#define OCURV 282
#define OR 283
#define OSQUARE 284
#define PARSEINT 285
#define PLUS 286
#define PRINT 287
#define PUBLIC 288
#define RESERVED 289
#define RETURN 290
#define SEMI 291
#define STAR 292
#define STATIC 293
#define WHILE 294
#define ESCAPESEQUENCE 295
#define STRING 296
#define COMMA 297
#define BOOLLIT 298
#define REALLIT 299
#define DECLIT 300
#define ID 301
#define STRLIT 302
#define VOID 303
#define PRECEDENCE 304
#define IFX 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "jac.y" /* yacc.c:1915  */

    char* token;
    struct node* _node;

#line 159 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
