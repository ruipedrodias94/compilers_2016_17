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
    COMMA = 265,
    CSQUARE = 266,
    DIV = 267,
    DO = 268,
    DOTLENGTH = 269,
    DOUBLE = 270,
    ELSE = 271,
    EQ = 272,
    GEQ = 273,
    GT = 274,
    INT = 275,
    LT = 276,
    LEQ = 277,
    MINUS = 278,
    MOD = 279,
    NEQ = 280,
    NOT = 281,
    OBRACE = 282,
    OCURV = 283,
    OR = 284,
    OSQUARE = 285,
    PARSEINT = 286,
    PLUS = 287,
    PRINT = 288,
    PUBLIC = 289,
    RESERVED = 290,
    RETURN = 291,
    SEMI = 292,
    STAR = 293,
    STATIC = 294,
    STRING = 295,
    VOID = 296,
    WHILE = 297,
    ESCAPESEQUENCE = 298,
    BOOLLIT = 299,
    REALLIT = 300,
    DECLIT = 301,
    ID = 302,
    STRLIT = 303,
    SIGN = 304
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
#define COMMA 265
#define CSQUARE 266
#define DIV 267
#define DO 268
#define DOTLENGTH 269
#define DOUBLE 270
#define ELSE 271
#define EQ 272
#define GEQ 273
#define GT 274
#define INT 275
#define LT 276
#define LEQ 277
#define MINUS 278
#define MOD 279
#define NEQ 280
#define NOT 281
#define OBRACE 282
#define OCURV 283
#define OR 284
#define OSQUARE 285
#define PARSEINT 286
#define PLUS 287
#define PRINT 288
#define PUBLIC 289
#define RESERVED 290
#define RETURN 291
#define SEMI 292
#define STAR 293
#define STATIC 294
#define STRING 295
#define VOID 296
#define WHILE 297
#define ESCAPESEQUENCE 298
#define BOOLLIT 299
#define REALLIT 300
#define DECLIT 301
#define ID 302
#define STRLIT 303
#define SIGN 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "jac.y" /* yacc.c:1909  */

    char* token;
    struct node* _node;

#line 157 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
