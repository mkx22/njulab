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
#line 3 "./syntax.y" /* yacc.c:339  */

 #include "lex.yy.c"
 #include <stdio.h>
 #include "string.h"
 void yyerror(const char* s);
 enum NodeType {Variable, Terminal, Number, Type, Id};
 struct Node{
	char* name;
	enum NodeType nodeType;
	int lineNum;
	char stringValue[300];
	int numValue;
	float numValueF;
	int childNum;
	struct Node* child[8];
 };
 struct Node* root;
 char IdString[300];
 struct Node* CreateTerminal(char* nameF, enum NodeType typeF,
		char* content, int numContent, int lineF, float fn);
 struct Node* CreateVariable(char* nameF, int numOfChild, 
		struct Node** childNode,int lineF);	

#line 90 "./syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    DOUBLE = 260,
    PLUS = 261,
    MINUS = 262,
    STAR = 263,
    DIV = 264,
    AND = 265,
    OR = 266,
    DOT = 267,
    NOT = 268,
    LP = 269,
    RP = 270,
    LB = 271,
    RB = 272,
    LC = 273,
    RC = 274,
    STRUCT = 275,
    RETURN = 276,
    IF = 277,
    ELSE = 278,
    WHILE = 279,
    BLANK = 280,
    SEMI = 281,
    COMMA = 282,
    RELOP = 283,
    ASSIGNOP = 284,
    ID = 285,
    TYPE = 286,
    CM = 287,
    LCM = 288,
    RCM = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "./syntax.y" /* yacc.c:355  */

 int type_int;
 float type_float;
 double type_double;
 struct Node* type_node;
 char* type_char;

#line 173 "./syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "./syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    66,    73,    75,    84,    92,   100,   104,
     108,   112,   116,   129,   136,   141,   155,   164,   168,   175,
     177,   187,   194,   207,   211,   224,   236,   240,   250,   255,
     266,   278,   282,   290,   292,   301,   306,   317,   331,   348,
     362,   366,   370,   376,   384,   386,   396,   400,   404,   408,
     412,   423,   427,   437,   444,   455,   465,   475,   485,   495,
     505,   515,   525,   535,   546,   555,   564,   577,   589,   601,
     612,   620,   629,   639,   649
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "DOUBLE", "PLUS",
  "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "LP", "RP", "LB",
  "RB", "LC", "RC", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "BLANK",
  "SEMI", "COMMA", "RELOP", "ASSIGNOP", "ID", "TYPE", "CM", "LCM", "RCM",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Com1", "Com2", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    80,   -27,   -64,   -64,   -19,    19,   -64,    22,    43,
     -64,   -64,   -64,   -64,   -64,    33,    39,   -64,   -64,   -64,
     -64,   132,   -64,    53,    42,    -3,    48,   109,   -64,   -64,
      28,   -64,    69,    55,    72,    57,   -64,    94,    55,    75,
      57,   -64,   -64,    77,   -64,    55,    59,    91,    90,   104,
     -64,   -64,   -64,    79,   -64,   -15,   106,   108,   -64,   -64,
     127,   -64,    64,   -64,     6,   -64,   -64,   141,   141,   141,
     141,   125,   136,   137,   -64,   133,    79,   -64,   -64,   150,
     141,   -64,    55,   -64,   -64,   262,   262,   174,   185,   141,
     141,   123,   -64,   -64,   141,   141,   141,   141,   141,   141,
     116,   141,   -64,   141,   141,   262,   -64,   -64,   -64,   209,
     220,   -64,   234,   148,   262,   262,   262,   262,   262,   262,
     -64,   248,   262,   262,   101,   101,   141,   -64,   -64,   142,
     -64,   -64,   101,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    19,    13,    53,     0,     0,     2,     0,     0,
      14,     8,     9,    17,    10,    20,     0,    16,    54,     1,
       3,     0,     6,    21,     0,    11,     0,     0,    26,    23,
       0,     5,     0,     0,     0,     0,     7,     0,     0,     0,
       0,    46,    47,     0,    25,     0,     0,    28,     0,     0,
      21,    12,    31,     0,    48,    51,     0,    49,    15,    43,
      29,    24,     0,    22,     0,    71,    72,     0,     0,     0,
       0,     0,     0,    70,    35,     0,     0,    40,    41,     0,
       0,    45,     0,    27,    42,    64,    65,     0,     0,     0,
       0,     0,    30,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,    52,    50,    63,    36,     0,
       0,    67,    74,     0,    59,    60,    61,    62,    56,    57,
      69,     0,    58,    55,     0,     0,     0,    66,    68,    37,
      39,    73,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   156,   -64,   134,     0,   -64,   -64,   -64,   -36,
     -64,   107,   -64,   144,    92,    -8,   -24,   -64,    93,   -64,
      10,    12,   -63,    46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    24,    38,    10,    16,    17,    25,
      26,    46,    47,    74,    75,    76,    39,    40,    56,    57,
      77,    78,    79,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    32,    55,    15,    85,    86,    87,    88,     9,    60,
      11,    53,    12,    32,    80,    18,    59,   105,    11,    19,
      12,    84,    -4,     1,    33,    52,   109,   110,   112,    43,
      45,   114,   115,   116,   117,   118,   119,    41,   121,    42,
     122,   123,     2,    44,    21,    41,    55,    42,     2,    34,
      41,   -18,    42,     3,     4,     5,    49,    27,    37,     3,
     -44,   -44,    45,   112,   -44,    43,    35,    30,    31,    22,
     -44,   -44,    48,    23,    61,   -44,   -44,     2,   -44,   -44,
      64,   -44,    65,    66,     2,    50,    67,   -44,     3,     4,
       5,    52,    68,    69,    58,     3,    13,    35,   -33,    13,
      70,    71,    64,    72,    65,    66,    14,    63,    67,    73,
      37,     4,     5,    13,    68,    69,   129,   130,    62,    35,
      54,    29,    70,    71,   133,    72,    65,    66,   -44,     2,
      67,    73,    81,     4,     5,    82,    68,    69,   111,    89,
       3,     4,     5,    32,    65,    66,   120,    28,    67,    29,
      90,    91,    92,    73,    68,    69,    94,    95,    96,    97,
      98,    99,   100,   127,    20,   132,   101,    51,    93,    83,
      36,    73,   131,     0,     0,   106,   102,     0,   103,   104,
      94,    95,    96,    97,    98,    99,   100,     0,     0,   107,
     101,    94,    95,    96,    97,    98,    99,   100,     0,     0,
       0,   101,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   108,     0,   103,   104,    94,    95,    96,    97,    98,
      99,   100,     0,     0,   124,   101,    94,    95,    96,    97,
      98,    99,   100,     0,     0,   125,   101,   103,   104,     0,
      94,    95,    96,    97,    98,    99,   100,     0,   103,   104,
     101,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   126,   103,   104,   101,   128,     0,     0,    94,    95,
      96,    97,    98,    99,   100,     0,   103,   104,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    16,    38,    30,    67,    68,    69,    70,     8,    45,
       0,    35,     0,    16,    29,    34,    40,    80,     8,     0,
       8,    15,     0,     1,    27,    19,    89,    90,    91,     1,
      30,    94,    95,    96,    97,    98,    99,    27,   101,    27,
     103,   104,    20,    15,     1,    35,    82,    35,    20,     1,
      40,    18,    40,    31,    32,    33,     1,    18,     1,    31,
       3,     4,    62,   126,     7,     1,    18,    14,    26,    26,
      13,    14,     3,    30,    15,    18,    19,    20,    21,    22,
       1,    24,     3,     4,    20,    30,     7,    30,    31,    32,
      33,    19,    13,    14,    19,    31,    19,    18,    19,    19,
      21,    22,     1,    24,     3,     4,    26,    17,     7,    30,
       1,    32,    33,    19,    13,    14,   124,   125,    27,    18,
      26,    17,    21,    22,   132,    24,     3,     4,    19,    20,
       7,    30,    26,    32,    33,    27,    13,    14,    15,    14,
      31,    32,    33,    16,     3,     4,    30,    15,     7,    17,
      14,    14,    19,    30,    13,    14,     6,     7,     8,     9,
      10,    11,    12,    15,     8,    23,    16,    33,    76,    62,
      26,    30,   126,    -1,    -1,    82,    26,    -1,    28,    29,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    16,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,    28,    29,    -1,
       6,     7,     8,     9,    10,    11,    12,    -1,    28,    29,
      16,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    27,    28,    29,    16,    17,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    -1,    28,    29,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    20,    31,    32,    33,    36,    37,    38,    40,
      41,    55,    56,    19,    26,    30,    42,    43,    34,     0,
      37,     1,    26,    30,    39,    44,    45,    18,    15,    17,
      14,    26,    16,    27,     1,    18,    48,     1,    40,    51,
      52,    55,    56,     1,    15,    40,    46,    47,     3,     1,
      30,    39,    19,    51,    26,    44,    53,    54,    19,    51,
      44,    15,    27,    17,     1,     3,     4,     7,    13,    14,
      21,    22,    24,    30,    48,    49,    50,    55,    56,    57,
      29,    26,    27,    46,    15,    57,    57,    57,    57,    14,
      14,    14,    19,    49,     6,     7,     8,     9,    10,    11,
      12,    16,    26,    28,    29,    57,    53,    15,    26,    57,
      57,    15,    57,    58,    57,    57,    57,    57,    57,    57,
      30,    57,    57,    57,    15,    15,    27,    15,    17,    50,
      50,    58,    23,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    39,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    44,    44,    45,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     1,
       2,     1,     3,     1,     1,     5,     2,     2,     1,     0,
       1,     1,     4,     2,     4,     3,     2,     3,     1,     2,
       4,     2,     2,     0,     2,     1,     3,     5,     7,     5,
       1,     1,     2,     2,     0,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 61 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Program", 1, &(yyvsp[0].type_node), (yyloc).first_line);
		root = (yyval.type_node);
	}
#line 1501 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("ExtDefList", 2, child, (yyloc).first_line);
	   }
#line 1512 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_node) = NULL; }
#line 1518 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = (yyvsp[-1].type_node);
		child[2] = CreateTerminal("SEMI", Terminal, yytext, 0,
				(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("ExtDef", 3, child, (yyloc).first_line);
	}
#line 1531 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = CreateTerminal("SEMI", Terminal, yytext, 0,
			(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("ExtDef", 2, child, (yyloc).first_line);
	}
#line 1543 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = (yyvsp[-1].type_node);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("ExtDef", 3, child, (yyloc).first_line);
	}
#line 1555 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com1", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1563 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com2", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1571 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 1578 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("ExtDecList", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	   }
#line 1586 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("COMMA", Terminal, ",", 0,
				(yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("ExtDecList", 3, child, 
				(yyloc).first_line);
	   }
#line 1600 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node*p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("TYPE", Type, (yyvsp[0].type_char), 0,
				(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Specifier", 1, &p, (yyloc).first_line);
	  }
#line 1611 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Specifier", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	  }
#line 1619 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "./syntax.y" /* yacc.c:1646  */
    {
			struct Node* child[5];
			child[0] = CreateTerminal("STRUCT", Terminal,
					"STRUCT", 0, (yylsp[-4]).first_line, 0);
			child[1] = (yyvsp[-3].type_node);
			child[2] = CreateTerminal("LC", Terminal,
					"{", 0, (yylsp[-2]).first_line, 0);
			child[3] = (yyvsp[-1].type_node);
			child[4] = CreateTerminal("RC", Terminal,
					"}", 0, (yylsp[0]).first_line, 0);
			(yyval.type_node) = CreateVariable("StructSpecifier", 5, child,
					(yyloc).first_line);
		}
#line 1637 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "./syntax.y" /* yacc.c:1646  */
    {
			struct Node* child[2];
			child[0] = CreateTerminal("STRUCT", Terminal,
					"STRUCT", 0, (yylsp[-1]).first_line, 0);
			child[1] = (yyvsp[0].type_node);
			(yyval.type_node) = CreateVariable("StructSpecifier", 2, child,
					(yyloc).first_line);
		}
#line 1650 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 165 "./syntax.y" /* yacc.c:1646  */
    {
		}
#line 1657 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("OptTag", 1, &p, (yyloc).first_line);
	}
#line 1668 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 175 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_node) = NULL; }
#line 1674 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Tag", 1, &p, (yyloc).first_line);
	}
#line 1685 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 188 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id, IdString, 0,
				(yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("VarDec", 1, &p, (yyloc).first_line);
	}
#line 1696 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 195 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[4];
		child[0] = (yyvsp[-3].type_node);
		child[1] = CreateTerminal("LB", Terminal,
				"[", 0, (yylsp[-2]).first_line, 0);
		child[2] = CreateTerminal("INT", Number,
				"INT", (yyvsp[-1].type_int), (yylsp[-1]).first_line, 0);
		child[3] = CreateTerminal("RB", Terminal,
				"]", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("VarDec", 4, child,
				(yyloc).first_line);
	}
#line 1713 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 1720 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 212 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[4];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[-3]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-2]).first_line, 0);
		child[2] = (yyvsp[-1].type_node);
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("FunDec", 4, child,
				(yyloc).first_line);
	}
#line 1737 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 225 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[-2]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-1]).first_line, 0);
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("FunDec", 3, child,
				(yyloc).first_line);
	}
#line 1753 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 1760 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 241 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("VarList", 3, child,
				(yyloc).first_line);
	}
#line 1774 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 251 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("VarList", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1782 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 256 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("ParamDec", 2, child,
				(yyloc).first_line);
	}
#line 1794 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 267 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[4];
		child[0] = CreateTerminal("LC", Terminal,
				"{", 0, (yylsp[-3]).first_line, 0);
		child[1] = (yyvsp[-2].type_node);
		child[2] = (yyvsp[-1].type_node);
		child[3] = CreateTerminal("RC", Terminal,
				"}", 0, (yylsp[-2]).first_line, 0);
		(yyval.type_node) = CreateVariable("CompSt", 4, child,
				(yyloc).first_line);
	}
#line 1810 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 279 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 1817 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 283 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("StmtList", 2, child,
				(yyloc).first_line);
	}
#line 1829 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 290 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_node) = NULL; }
#line 1835 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = CreateTerminal("SEMI", Terminal,
				";", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Stmt", 2, child,
				(yyloc).first_line);
	}
#line 1848 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 302 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Stmt", 1, &(yyvsp[0].type_node),
				(yyloc).first_line);
	}
#line 1857 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 307 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = CreateTerminal("RETURN", Terminal,
				"RETURN", 0, (yylsp[-2]).first_line, 0);
		child[1] = (yyvsp[-2].type_node);
		child[2] = CreateTerminal("SEMI", Terminal,
				";", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Stmt", 3, child,
				(yyloc).first_line);
	}
#line 1872 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 318 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[5];
		child[0] = CreateTerminal("IF", Terminal,
				"IF", 0, (yylsp[-4]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-3]).first_line, 0);
		child[2] = (yyvsp[-2].type_node);
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[-1]).first_line, 0);
		child[4] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Stmt", 5, child,
				(yyloc).first_line);
	}
#line 1890 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 332 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[7];
		child[0] = CreateTerminal("IF", Terminal,
				"IF", 0, (yylsp[-6]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-5]).first_line, 0);
		child[2] = (yyvsp[-4].type_node);
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[-3]).first_line, 0);
		child[4] = (yyvsp[-2].type_node);
		child[5] = CreateTerminal("ELSE", Terminal,
				"ELSE", 0, (yylsp[-2]).first_line, 0);
		child[6] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Stmt", 7, child,
				(yyloc).first_line);
	}
#line 1911 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 349 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[5];
		child[0] = CreateTerminal("WHILE", Terminal,
				"WHILE", 0, (yylsp[-4]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-3]).first_line, 0);
		child[2] = (yyvsp[-2].type_node);
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[-1]).first_line, 0);
		child[4] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Stmt", 5, child,
				(yyloc).first_line);
	}
#line 1929 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 363 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com1", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1937 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com2", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1945 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 371 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 1952 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 377 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = (yyvsp[-1].type_node);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("DefList", 2, child,
				(yyloc).first_line);
	}
#line 1964 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 384 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_node) = NULL; }
#line 1970 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 387 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = (yyvsp[-1].type_node);
		child[2] = CreateTerminal("SEMI", Terminal,
				yytext, 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Def", 3, child,
				(yyloc).first_line);
	}
#line 1984 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 397 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com1", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 1992 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 401 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Com2", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 2000 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 405 "./syntax.y" /* yacc.c:1646  */
    {
	}
#line 2007 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 409 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("DecList", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 2015 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 413 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("DecList", 3, child,
				(yyloc).first_line);
	}
#line 2029 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 424 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Dec", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 2037 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 428 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("ASSIGNOP", Terminal,
				"=", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Dec", 3, child,
				(yyloc).first_line);
	}
#line 2051 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "./syntax.y" /* yacc.c:1646  */
    {
	/*	struct Node* child[1];
		child[0] = CreateTerminal("CM", Terminal, "//", 0, @1.first_line, 0);
		$$ = CreateVariable("Com1", 1, child, @$.first_line);
	*/
	}
#line 2062 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 445 "./syntax.y" /* yacc.c:1646  */
    {
	/*	struct Node* child[2];
		child[0] = CreateTerminal("LCM", Terminal, "", 0, @1.first_line, 0);
		child[1] = CreateTerminal("RCM", Terminal, "", 0, @2.first_line, 0);
		$$ = CreateVariable("Com2", 2, child, @$.first_line);
	*/
	}
#line 2074 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 456 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("ASSIGNOP", Terminal,
				"=", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2088 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 466 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("AND", Terminal,
				"&&", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2102 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 476 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("OR", Terminal,
				"||", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2116 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 486 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("RELOP", Terminal,
				yytext, 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2130 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 496 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("PLUS", Terminal,
				"+", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2144 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 506 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("MINUS", Terminal,
				"-", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2158 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 516 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("STAR", Terminal,
				"*", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2172 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 526 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("DIV", Terminal,
				"/", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2186 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 536 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-2]).first_line, 0);
		child[1] = (yyvsp[-1].type_node);
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2201 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 547 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = CreateTerminal("MINUS", Terminal,
				"-", 0, (yylsp[-1]).first_line, 0);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 2, child,
				(yyloc).first_line);
	}
#line 2214 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 556 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[2];
		child[0] = CreateTerminal("NOT", Terminal,
				"~", 0, (yylsp[-1]).first_line, 0);
		child[1] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Exp", 2, child,
				(yyloc).first_line);
	}
#line 2227 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 565 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[4];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[-3]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-2]).first_line, 0);
		child[2] = (yyvsp[-1].type_node);
		child[3] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 4, child,
				(yyloc).first_line);
	}
#line 2244 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 578 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[-2]).first_line, 0);
		child[1] = CreateTerminal("LP", Terminal,
				"(", 0, (yylsp[-1]).first_line, 0);
		child[2] = CreateTerminal("RP", Terminal,
				")", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2260 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 590 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[4];
		child[0] = (yyvsp[-3].type_node);
		child[1] = CreateTerminal("LB", Terminal,
				"[", 0, (yylsp[-2]).first_line, 0);
		child[2] = (yyvsp[-1].type_node);
		child[3] = CreateTerminal("RB", Terminal,
				"]", 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 4, child,
				(yyloc).first_line);
	}
#line 2276 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 602 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("DOT", Terminal,
				".", 0, (yylsp[-1]).first_line, 0);
		child[2] = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 3, child,
				(yyloc).first_line);
	}
#line 2291 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 613 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p = CreateTerminal("ID", Id,
				IdString, 0, (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 1, &p,
				(yyloc).first_line);
	}
#line 2303 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 621 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* tempNode = (struct Node*)malloc(
				sizeof(struct Node));
		tempNode = CreateTerminal("INT", Number,
				"INT", (yyvsp[0].type_int), (yylsp[0]).first_line, 0);
		(yyval.type_node) = CreateVariable("Exp", 1, &tempNode,
				(yyloc).first_line);
	}
#line 2316 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 630 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* tempNode = (struct Node*)malloc(
				sizeof(struct Node));
		tempNode = CreateTerminal("FLOAT", Number,
				"FLOAT", 0, (yylsp[0]).first_line, (yyvsp[0].type_float));
		(yyval.type_node) = CreateVariable("Exp", 1, &tempNode,
				(yyloc).first_line);
	}
#line 2329 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 640 "./syntax.y" /* yacc.c:1646  */
    {
		struct Node* child[3];
		child[0] = (yyvsp[-2].type_node);
		child[1] = CreateTerminal("COMMA", Terminal,
				",", 0, (yylsp[-1]).first_line, 0);
		child[2] = (yyvsp[0].type_node);
		(yyval.type_node) = CreateVariable("Args", 3, child,
				(yyloc).first_line);
	}
#line 2343 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 650 "./syntax.y" /* yacc.c:1646  */
    {
		(yyval.type_node) = CreateVariable("Args", 1, &(yyvsp[0].type_node), (yyloc).first_line);
	}
#line 2351 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2355 "./syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 654 "./syntax.y" /* yacc.c:1906  */

struct Node* CreateTerminal(char* nameF, enum NodeType typeF,
		char* content, int numContent, int lineF, float fn) {
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->name = nameF;
	p->nodeType = typeF;
	p->lineNum = lineF;
	p->childNum = 0;
	if(typeF == Type | typeF == Id)
		strcpy(p->stringValue, content);
	else if(typeF == Number) {
		if(p->name == "INT")
			p->numValue = numContent;
		else
			p->numValueF = fn;
	}
	return p;
}
struct Node* CreateVariable(char* nameF, int numOfChild, 
		struct Node** childNode,int lineF) {
	int i;
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->name = nameF;
	p->nodeType = Variable;
	p->lineNum = lineF;
	p->childNum = numOfChild;
	for(i = 0;i < numOfChild;i++) {
		p->child[i] = childNode[i];
	}
	return p;
}
void preTraverse(struct Node* root, int blankNum) {
	int i;
	for(i = 0;i < blankNum;i++)
		printf(" ");
	if(root->nodeType == Variable)
		printf("%s (%d)\n", root->name, root->lineNum);
	else if(root->nodeType == Id || root->nodeType == Type) {
		printf("%s: %s\n", root->name, root->stringValue);
	}
	else if(root->nodeType == Number) {
		if(root->name == "INT")
			printf("%s: %d\n", root->name, root->numValue);
		else
			printf("%s: %f\n", root->name, root->numValueF);
	}
	else
		printf("%s\n", root->name);
	for(i = 0;i < root->childNum;i++) {
		if(root->child[i] != NULL) {
			preTraverse(root->child[i], blankNum + 2);
		}
	}
}
void printSytaxTree() {
	if(root == NULL) {
		printf("This is an empty syntax tree, but acceptable\n");
		return;
	}
	preTraverse(root, 0);	
}
