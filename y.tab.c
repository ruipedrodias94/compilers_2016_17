/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jac.y" /* yacc.c:339  */

   #include <stdio.h>
   #include <string.h>
   #include "estruturas.h"
   #include "semantics.h"
   #include "sym_tab.h"


  int yylex(void);
  void yyerror(char *s);
  int erro=0;
  int syntax_flag = 0;
  extern int flag_error;

  Node* root = NULL ;
  Node* aux_node = NULL;
  Node* aux_node2 = NULL;
  Node* aux_node3 = NULL;
  Node* aux_node4 = NULL;




#line 90 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 25 "jac.y" /* yacc.c:355  */

    char* token;
    struct node* _node;

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   101,   102,   103,   104,   108,   109,   111,
     112,   115,   118,   119,   120,   121,   124,   126,   127,   128,
     131,   132,   134,   135,   138,   141,   142,   145,   146,   147,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   165,   166,   169,   172,   173,   174,
     177,   178,   181,   182,   185,   186,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "AND", "ASSIGN", "BOOL", "CLASS",
  "CCURV", "CBRACE", "CSQUARE", "DIV", "DO", "DOTLENGTH", "DOUBLE", "ELSE",
  "EQ", "GEQ", "GT", "INT", "LT", "LEQ", "MINUS", "MOD", "NEQ", "NOT",
  "OBRACE", "OCURV", "OR", "OSQUARE", "PARSEINT", "PLUS", "PRINT",
  "PUBLIC", "RESERVED", "RETURN", "SEMI", "STAR", "STATIC", "WHILE",
  "ESCAPESEQUENCE", "STRING", "COMMA", "BOOLLIT", "REALLIT", "DECLIT",
  "ID", "STRLIT", "VOID", "PRECEDENCE", "IFX", "$accept", "Program",
  "ProgramCycle", "FieldDecl", "FieldDeclCycle", "MethodDecl",
  "MethodHeader", "MethodBody", "MethodBodyCycle", "FormalParams",
  "FormalParamsCycle", "VarDecl", "VarDeclCycle", "Type", "Statement",
  "StatementCycle", "Assignment", "MethodInvocation",
  "MethodInvocationCycle", "ParseArgs", "Expr", "ExprAux", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -39,    31,    18,   -53,   -53,    13,    19,   -53,    35,
     -53,   -53,   -53,   -53,    24,   -53,   -53,   -53,    10,   -18,
      59,    40,    62,   -53,    41,   -53,   -53,    63,    33,   -53,
     134,    34,   -53,    65,    88,    56,    67,    77,   -53,   156,
     -53,    80,    83,   299,   -53,    85,    49,   -53,    42,    70,
     -53,    86,    91,    92,   -53,   115,   114,   -53,   -53,   -53,
     306,    90,    79,     4,   273,   331,   331,   182,   331,   -53,
     -53,   -53,   -53,     8,   -53,   -53,   -53,    94,   213,   306,
     306,   154,   -53,    93,   -53,   -53,   -53,   -53,   -53,    95,
      89,   128,   111,   -53,   -53,   136,   113,   137,   139,    68,
     -53,   -53,   141,   142,   -53,   -53,   -53,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     143,   -53,   144,   -53,   -53,   -53,   -53,    87,   156,   306,
     -53,   306,   118,   120,   -53,   -53,   253,   -53,   271,    14,
      14,    14,    14,    60,   -53,   271,   235,    60,   -53,   156,
     -53,    15,   112,   146,   155,   157,   -53,   -53,   -53,   -53,
     306,   -53,   156,   129,   163,   -53,   -53,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     0,     0,     2,     0,
       5,     3,     4,     8,     0,    27,    29,    28,     0,     0,
       0,     0,     0,     7,     0,    19,    11,    10,     0,     9,
       0,     0,    15,     0,     0,     0,     0,     0,    16,     0,
      45,     0,     0,     0,    37,     0,     0,    17,     0,     0,
      18,     0,     0,     0,    13,     0,     0,    14,    23,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      77,    79,    78,    74,    54,    56,    57,     0,    55,     0,
       0,     0,    24,     0,    26,    38,    39,    40,    12,     0,
      20,     0,     0,    30,    44,     0,     0,     0,     0,    74,
      72,    73,     0,     0,    71,    75,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,    51,    25,    21,     0,     0,     0,
      53,     0,     0,     0,    80,    76,    58,    69,    60,    61,
      62,    64,    63,    67,    70,    65,    59,    66,    68,     0,
      49,     0,     0,    31,     0,     0,    36,    35,    33,    48,
       0,    22,     0,     0,     0,    50,    32,    34,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   147,
     -53,   -53,   -53,   -10,   -36,   -53,   -30,   -29,   -53,   -28,
     -52,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    11,    19,    12,    20,    26,    30,    34,
      90,    47,    48,    35,    50,    62,    74,    75,   151,    76,
      77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    53,    61,    21,    95,     1,     3,    91,    51,
      52,    53,    98,    80,     7,   103,   100,   101,    23,   104,
      49,   105,     8,   159,    24,   108,    94,   120,   121,   124,
      15,     4,    51,    52,    53,    81,   114,   115,    16,    15,
      15,    32,    54,    17,     5,   118,     9,    16,    16,    10,
      96,   119,    17,    17,    80,    13,    22,   160,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   108,    18,    14,    33,    33,    81,   154,    82,   155,
      36,   105,    37,   115,    83,    25,    27,    29,    93,    28,
      31,    39,   153,    15,    56,    81,    57,   119,    51,    52,
      53,    16,    58,    59,    60,    40,    17,    63,   165,    41,
      64,    42,    79,   158,    43,    44,    84,   152,    45,    51,
      52,    53,    85,    88,    89,    46,   166,    86,    87,    92,
     106,   127,    51,    52,    53,    36,   128,    37,   129,   125,
      15,   126,   131,    38,   130,   132,    39,   133,    16,   134,
     135,   149,   150,    17,   156,   122,   157,    36,   161,    37,
      40,   162,   123,   163,    41,   167,    42,   164,    39,    43,
      44,   168,     0,    45,     0,     0,    65,     0,    55,    66,
      46,    67,    40,   102,    41,    68,    41,     0,    42,     0,
       0,    43,    44,     0,     0,    45,     0,    70,    71,    72,
      73,     0,    46,     0,    65,     0,     0,    66,     0,    67,
       0,     0,    41,    68,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,   108,    70,    71,    72,    73,   109,
     110,   111,     0,   112,   113,   114,   115,   116,     0,   107,
       0,   117,     0,     0,   118,     0,   108,     0,     0,     0,
     119,   109,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   108,     0,   118,     0,     0,   109,
     110,   111,   119,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   108,     0,   118,     0,     0,     0,   110,   111,
     119,   112,   113,   114,   115,    65,     0,     0,    66,     0,
      67,     0,   118,    41,    68,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      97,    65,     0,     0,    66,     0,    67,     0,    65,    41,
      68,    66,     0,    67,     0,    69,    41,    68,     0,     0,
       0,     0,    70,    71,    72,    73,     0,     0,     0,    70,
      71,    72,    73,    65,     0,     0,    66,     0,    67,     0,
       0,    41,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    99
};

static const yytype_int16 yycheck[] =
{
      30,    30,    30,    39,    14,     1,     7,    46,    60,    39,
      39,    39,    64,     5,     1,    67,    65,    66,    36,    68,
      30,    13,     9,     8,    42,    11,    62,    79,    80,    81,
       6,     0,    62,    62,    62,    27,    22,    23,    14,     6,
       6,     8,     8,    19,    26,    31,    33,    14,    14,    36,
      46,    37,    19,    19,     5,    36,    46,    42,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    11,    48,    38,    41,    41,    27,   129,    36,   131,
       1,    13,     3,    23,    42,    26,    46,    46,     9,    27,
      27,    12,   128,     6,    29,    27,     8,    37,   128,   128,
     128,    14,    46,    36,    27,    26,    19,    27,   160,    30,
      27,    32,    27,   149,    35,    36,    46,   127,    39,   149,
     149,   149,    36,     8,    10,    46,   162,    36,    36,    39,
      36,    42,   162,   162,   162,     1,     8,     3,    27,    46,
       6,    46,    29,     9,     8,     8,    12,     8,    14,     8,
       8,     8,     8,    19,    36,     1,    36,     1,    46,     3,
      26,    15,     8,     8,    30,    36,    32,    10,    12,    35,
      36,     8,    -1,    39,    -1,    -1,    22,    -1,    31,    25,
      46,    27,    26,     1,    30,    31,    30,    -1,    32,    -1,
      -1,    35,    36,    -1,    -1,    39,    -1,    43,    44,    45,
      46,    -1,    46,    -1,    22,    -1,    -1,    25,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    43,    44,    45,    46,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,     4,
      -1,    28,    -1,    -1,    31,    -1,    11,    -1,    -1,    -1,
      37,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    11,    -1,    31,    -1,    -1,    16,
      17,    18,    37,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    11,    -1,    31,    -1,    -1,    -1,    17,    18,
      37,    20,    21,    22,    23,    22,    -1,    -1,    25,    -1,
      27,    -1,    31,    30,    31,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    22,    -1,    -1,    25,    -1,    27,    -1,    22,    30,
      31,    25,    -1,    27,    -1,    36,    30,    31,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    -1,    43,
      44,    45,    46,    22,    -1,    -1,    25,    -1,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    52,    46,     0,    26,    53,     1,     9,    33,
      36,    54,    56,    36,    38,     6,    14,    19,    48,    55,
      57,    64,    46,    36,    42,    26,    58,    46,    27,    46,
      59,    27,     8,    41,    60,    64,     1,     3,     9,    12,
      26,    30,    32,    35,    36,    39,    46,    62,    63,    64,
      65,    67,    68,    70,     8,    60,    29,     8,    46,    36,
      27,    65,    66,    27,    27,    22,    25,    27,    31,    36,
      43,    44,    45,    46,    67,    68,    70,    71,    72,    27,
       5,    27,    36,    42,    46,    36,    36,    36,     8,    10,
      61,    71,    39,     9,    65,     1,    46,    47,    71,    46,
      72,    72,     1,    71,    72,    13,    36,     4,    11,    16,
      17,    18,    20,    21,    22,    23,    24,    28,    31,    37,
      71,    71,     1,     8,    71,    46,    46,    42,     8,    27,
       8,    29,     8,     8,     8,     8,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,     8,
       8,    69,    64,    65,    71,    71,    36,    36,    65,     8,
      42,    46,    15,     8,    10,    71,    65,    36,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    57,    57,    58,    59,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     2,     3,
       2,     4,     5,     4,     5,     4,     3,     2,     2,     0,
       3,     4,     4,     0,     2,     3,     2,     1,     1,     1,
       3,     5,     7,     5,     7,     5,     5,     1,     2,     2,
       2,     2,     3,     2,     2,     0,     3,     3,     5,     4,
       3,     0,     7,     4,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     1,     2,     3,     1,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 99 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-3].token),NULL,(yyvsp[-1]._node));free((yyvsp[-3].token));root = createNode(type_Program,NULL,aux_node,NULL);}}
#line 1487 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 101 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-1]._node),(yyvsp[0]._node));(yyval._node)=(yyvsp[-1]._node);}}
#line 1493 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 102 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-1]._node),(yyvsp[0]._node));(yyval._node)=(yyvsp[-1]._node);}}
#line 1499 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 103 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1505 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 104 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1511 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 108 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node)=(yyvsp[-1]._node);}}
#line 1517 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 109 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Error,NULL,NULL,NULL);(yyval._node) = aux_node;}}
#line 1523 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 111 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,(yyvsp[0].token),NULL,NULL));free((yyvsp[0].token));insertBrother((yyvsp[-2]._node),createNode(type_FieldDecl,NULL,aux_node,NULL)); (yyval._node) = (yyvsp[-2]._node);}}
#line 1529 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 112 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node2 = (yyvsp[-1]._node);aux_node = createNode(type_Id,(yyvsp[0].token),NULL,NULL);insertBrother((yyvsp[-1]._node),aux_node);free((yyvsp[0].token));(yyval._node) = createNode(type_FieldDecl,NULL,(yyvsp[-1]._node),NULL);}}
#line 1535 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 115 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-1]._node),(yyvsp[0]._node)); (yyval._node) = createNode(type_MethodDecl,NULL,(yyvsp[-1]._node),NULL);}}
#line 1541 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 118 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-3].token),NULL,NULL);free((yyvsp[-3].token));insertBrother((yyvsp[-4]._node),aux_node);insertBrother((yyvsp[-4]._node),createNode(type_MethodParams,NULL,(yyvsp[-1]._node),NULL));(yyval._node) = createNode(type_MethodHeader,NULL,(yyvsp[-4]._node),NULL);}}
#line 1547 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 119 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-2].token),NULL,NULL);free((yyvsp[-2].token));insertBrother((yyvsp[-3]._node),aux_node);insertBrother((yyvsp[-3]._node),createNode(type_MethodParams,NULL,NULL,NULL));(yyval._node) = createNode(type_MethodHeader,NULL,(yyvsp[-3]._node),NULL);}}
#line 1553 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 120 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Void,NULL,NULL,createNode(type_Id,(yyvsp[-3].token),NULL,createNode(type_MethodParams,NULL,(yyvsp[-1]._node),NULL)));free((yyvsp[-3].token));(yyval._node) = createNode(type_MethodHeader,NULL,aux_node,NULL);}}
#line 1559 "y.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 121 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Void,NULL,NULL,createNode(type_Id,(yyvsp[-2].token),NULL,NULL));insertBrother(aux_node,createNode(type_MethodParams,NULL,NULL,NULL));free((yyvsp[-2].token));(yyval._node) = createNode(type_MethodHeader,NULL,aux_node,NULL);}}
#line 1565 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 124 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_MethodBody,NULL,(yyvsp[-1]._node),NULL);(yyval._node) = aux_node;}}
#line 1571 "y.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 126 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-1]._node),(yyvsp[0]._node));(yyval._node) = (yyvsp[-1]._node);}}
#line 1577 "y.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 127 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) { if(checkBlock((yyvsp[0]._node))>=2){aux_node = createNode(type_Block,NULL,(yyvsp[0]._node),NULL);}else{aux_node = (yyvsp[0]._node);}insertBrother((yyvsp[-1]._node),aux_node);(yyval._node) = (yyvsp[-1]._node);}}
#line 1583 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 128 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1589 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 131 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-1].token),NULL,NULL);free((yyvsp[-1].token));insertBrother((yyvsp[-2]._node),aux_node); (yyval._node) = createNode(type_ParamDecl,NULL,(yyvsp[-2]._node),(yyvsp[0]._node));}}
#line 1595 "y.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 132 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_StringArray,NULL,NULL,createNode(type_Id,(yyvsp[0].token),NULL,NULL));free((yyvsp[0].token)); (yyval._node) = createNode(type_ParamDecl,NULL,aux_node,NULL);}}
#line 1601 "y.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 134 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_ParamDecl,NULL,(yyvsp[-1]._node),NULL);insertBrother((yyvsp[-1]._node),createNode(type_Id,(yyvsp[0].token),NULL,NULL));free((yyvsp[0].token));insertBrother((yyvsp[-3]._node),aux_node);(yyval._node) = (yyvsp[-3]._node);}}
#line 1607 "y.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 135 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1613 "y.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 138 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1619 "y.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 141 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(aux_node2->node_type,NULL,NULL,createNode(type_Id,(yyvsp[0].token),NULL,NULL));free((yyvsp[0].token));insertBrother((yyvsp[-2]._node),createNode(type_VarDecl,NULL,aux_node,NULL)); (yyval._node) = (yyvsp[-2]._node);}}
#line 1625 "y.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 142 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node2 = (yyvsp[-1]._node);aux_node = createNode(type_Id,(yyvsp[0].token),NULL,NULL);free((yyvsp[0].token));insertBrother((yyvsp[-1]._node),aux_node); (yyval._node) = createNode(type_VarDecl,NULL,(yyvsp[-1]._node),NULL);}}
#line 1631 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 145 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Bool,NULL,NULL,NULL);}}
#line 1637 "y.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 146 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Int,NULL,NULL,NULL);}}
#line 1643 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 147 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Double,NULL,NULL,NULL);}}
#line 1649 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 150 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1655 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 151 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Block,NULL,NULL,NULL);if(checkBlock((yyvsp[0]._node))>=2){aux_node3 = createNode(type_Block,NULL,(yyvsp[0]._node),NULL);}else if(checkBlock((yyvsp[0]._node))==0){aux_node3 = createNode(type_Block,NULL,NULL,NULL);}else{aux_node3 = (yyvsp[0]._node);};insertBrother(aux_node3,aux_node);insertBrother((yyvsp[-2]._node),aux_node3);(yyval._node) = createNode(type_If,NULL,(yyvsp[-2]._node),NULL);}}
#line 1661 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 152 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {if(checkBlock((yyvsp[0]._node))>=2){aux_node3 = createNode(type_Block,NULL,(yyvsp[0]._node),NULL);}else if(checkBlock((yyvsp[0]._node))==0){aux_node3 = createNode(type_Block,NULL,NULL,NULL);}else{aux_node3 = (yyvsp[0]._node);}if(checkBlock((yyvsp[-2]._node))>=2){aux_node = createNode(type_Block,NULL,(yyvsp[-2]._node),NULL);}else if(checkBlock((yyvsp[-2]._node))==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node = (yyvsp[-2]._node);} insertBrother(aux_node,aux_node3);insertBrother((yyvsp[-4]._node),aux_node);(yyval._node) = createNode(type_If,NULL,(yyvsp[-4]._node),NULL);}}
#line 1667 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 153 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {if(checkBlock((yyvsp[0]._node))>=2){aux_node = createNode(type_Block,NULL,(yyvsp[0]._node),NULL);}else if(checkBlock((yyvsp[0]._node))==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node = (yyvsp[0]._node);};insertBrother((yyvsp[-2]._node),aux_node);(yyval._node) = createNode(type_While,NULL,(yyvsp[-2]._node),NULL);}}
#line 1673 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 154 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {if(checkBlock((yyvsp[-5]._node))>=2){aux_node = createNode(type_Block,NULL,(yyvsp[-5]._node),NULL);}else if(checkBlock((yyvsp[-5]._node))==0){aux_node = createNode(type_Block,NULL,NULL,NULL);}else{aux_node=(yyvsp[-5]._node);};insertBrother(aux_node,(yyvsp[-2]._node));(yyval._node) = createNode(type_DoWhile,NULL,aux_node,NULL);}}
#line 1679 "y.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 155 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Print,NULL,(yyvsp[-2]._node),NULL);}}
#line 1685 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 156 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_StrLit,(yyvsp[-2].token),NULL,NULL);(yyval._node) = createNode(type_Print,NULL,aux_node,NULL);}}
#line 1691 "y.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 157 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1697 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 158 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1703 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 159 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1709 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 160 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1715 "y.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 161 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Return,NULL,NULL,NULL);}}
#line 1721 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 162 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Return,NULL,(yyvsp[-1]._node),NULL);}}
#line 1727 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 163 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Error,NULL,NULL,NULL);}}
#line 1733 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 165 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-1]._node),(yyvsp[0]._node));(yyval._node) = (yyvsp[-1]._node);}}
#line 1739 "y.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 166 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1745 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 169 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-2].token),NULL,NULL);free((yyvsp[-2].token));insertBrother(aux_node,(yyvsp[0]._node));(yyval._node) = createNode(type_Assign,NULL,aux_node,NULL);}}
#line 1751 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 172 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-2].token),NULL,NULL);free((yyvsp[-2].token));(yyval._node) = createNode(type_Call,NULL,aux_node,NULL);}}
#line 1757 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 173 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-4].token),NULL,NULL);free((yyvsp[-4].token));insertBrother(aux_node, (yyvsp[-2]._node)); insertBrother((yyvsp[-2]._node), (yyvsp[-1]._node)); (yyval._node) = createNode(type_Call, NULL, aux_node, NULL);}}
#line 1763 "y.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 174 "jac.y" /* yacc.c:1661  */
    {free((yyvsp[-3].token));if(flag_error == 0) {(yyval._node) = createNode(type_Error,NULL,NULL,NULL);}}
#line 1769 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 177 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node),(yyvsp[0]._node)); (yyval._node) = (yyvsp[-2]._node);}}
#line 1775 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 178 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Null,NULL,NULL,NULL);}}
#line 1781 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 181 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id,(yyvsp[-4].token),NULL,NULL);free((yyvsp[-4].token));insertBrother(aux_node,(yyvsp[-2]._node));(yyval._node) = createNode(type_ParseArgs,NULL,aux_node,NULL);}}
#line 1787 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 182 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = createNode(type_Error,NULL,NULL,NULL);}}
#line 1793 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 185 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[0]._node);}}
#line 1799 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 186 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[0]._node);}}
#line 1805 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 189 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[0]._node);}}
#line 1811 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 190 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[0]._node);}}
#line 1817 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 191 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_And, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1823 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 192 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Or, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1829 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 193 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Eq, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1835 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 194 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Geq, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1841 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 195 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Gt, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1847 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 196 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Leq, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1853 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 197 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Lt, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1859 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 198 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Neq, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1865 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 199 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Add, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1871 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 200 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Sub, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1877 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 201 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Mul, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1883 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 202 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Div, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1889 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 203 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {insertBrother((yyvsp[-2]._node), (yyvsp[0]._node)); aux_node = createNode(type_Mod, NULL, (yyvsp[-2]._node), NULL);  (yyval._node) = aux_node;}}
#line 1895 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 204 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Plus, NULL, (yyvsp[0]._node), NULL); (yyval._node) = aux_node;}}
#line 1901 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 205 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Minus, NULL, (yyvsp[0]._node), NULL); (yyval._node) = aux_node;}}
#line 1907 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 206 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Not, NULL, (yyvsp[0]._node), NULL); (yyval._node) = aux_node;}}
#line 1913 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 207 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id, (yyvsp[0].token), NULL, NULL);free((yyvsp[0].token));(yyval._node) = aux_node;}}
#line 1919 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 208 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Id, (yyvsp[-1].token), NULL, NULL);free((yyvsp[-1].token)); (yyval._node) = createNode(type_Length, NULL, aux_node, NULL);}}
#line 1925 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 209 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {(yyval._node) = (yyvsp[-1]._node);}}
#line 1931 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 210 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_BoolLit, (yyvsp[0].token), NULL, NULL); (yyval._node) = aux_node;}}
#line 1937 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 211 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_DecLit, (yyvsp[0].token), NULL, NULL); (yyval._node) = aux_node;}}
#line 1943 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 212 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_RealLit, (yyvsp[0].token), NULL, NULL); (yyval._node) = aux_node;}}
#line 1949 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 213 "jac.y" /* yacc.c:1661  */
    {if(flag_error == 0) {aux_node = createNode(type_Error, NULL, NULL, NULL); (yyval._node) = aux_node;}}
#line 1955 "y.tab.c" /* yacc.c:1661  */
    break;


#line 1959 "y.tab.c" /* yacc.c:1661  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 216 "jac.y" /* yacc.c:1906  */


int main(int argc, char** argv){
	if(argc>1){
		if(strcmp(argv[1],"-l")==0){
			erro = 1;
      syntax_flag = 0;
			yylex();
		}
    else if(strcmp(argv[1],"-t")==0){
      syntax_flag = 1;
      yyparse();
      if(flag_error == 0){
        printList(root,0);
      }

    free_tree(root);

  }else if(strcmp(argv[1],"-s")==0){
      syntax_flag = 1;
      yyparse();

      check_ast_to_table(root);

      if(flag_error == 0){
        //printList(root,0);
      }

    free_tree(root);

    } else if(strcmp(argv[1],"-2")==0){
      syntax_flag = 1;
      yyparse();
      free_tree(root);
   	}
		else
		{
      syntax_flag = 0;
			yylex();
		}
	}
	else{
   syntax_flag = 1;
      yyparse();
      free_tree(root);
	}
	return 0;
}
