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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

FILE * output = NULL;


/* Line 268 of yacc.c  */
#line 80 "y.tab.c"

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
     UNDEFINED = 1,
     TK_IDENTIFIER = 2,
     LIT_INTEGER = 3,
     LIT_FALSE = 4,
     LIT_TRUE = 5,
     LIT_CHAR = 6,
     LIT_STRING = 7,
     KW_INT = 256,
     KW_REAL = 257,
     KW_BOOL = 258,
     KW_CHAR = 259,
     KW_IF = 261,
     KW_ELSE = 263,
     KW_LOOP = 264,
     KW_INPUT = 266,
     KW_RETURN = 267,
     KW_OUTPUT = 268,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TOKEN_ERROR = 290
   };
#endif
/* Tokens.  */
#define UNDEFINED 1
#define TK_IDENTIFIER 2
#define LIT_INTEGER 3
#define LIT_FALSE 4
#define LIT_TRUE 5
#define LIT_CHAR 6
#define LIT_STRING 7
#define KW_INT 256
#define KW_REAL 257
#define KW_BOOL 258
#define KW_CHAR 259
#define KW_IF 261
#define KW_ELSE 263
#define KW_LOOP 264
#define KW_INPUT 266
#define KW_RETURN 267
#define KW_OUTPUT 268
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TOKEN_ERROR 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 69 "parser.y"

	hash_node_t* symbol;
	ast_node_t* node;



/* Line 293 of yacc.c  */
#line 175 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 187 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      38,    39,    32,    30,    42,    31,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    34,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,    10,    11,    12,    13,
       2,    14,     2,    15,    16,     2,    17,    18,    19,     2,
      20,    21,    22,    23,    24,    25,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    12,    16,    20,    21,
      26,    32,    40,    42,    45,    46,    54,    61,    65,    66,
      68,    70,    72,    74,    76,    78,    80,    82,    84,    88,
      91,    92,    95,    96,   101,   106,   114,   122,   125,   128,
     131,   133,   135,   136,   142,   150,   157,   161,   164,   165,
     168,   171,   172,   174,   179,   181,   185,   189,   193,   197,
     201,   205,   209,   213,   217,   221,   225,   229,   233,   238,
     241,   242,   245,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    52,    34,    46,    -1,    47,
      -1,    -1,    48,    34,    47,    -1,    49,    34,    47,    -1,
      -1,    54,    68,    35,    55,    -1,    54,    68,    36,    50,
      37,    -1,    54,    68,    36,    50,    37,    35,    51,    -1,
       5,    -1,    55,    51,    -1,    -1,    54,    68,    38,    61,
      39,    53,    59,    -1,    54,    68,    38,    39,    53,    59,
      -1,    48,    34,    53,    -1,    -1,    10,    -1,    13,    -1,
      11,    -1,    12,    -1,     5,    -1,     8,    -1,     9,    -1,
       7,    -1,     6,    -1,    40,    57,    41,    -1,    59,    58,
      -1,    -1,    34,    57,    -1,    -1,    68,    35,    27,    65,
      -1,    65,    27,    35,    68,    -1,    68,    36,    65,    37,
      35,    27,    65,    -1,    65,    27,    35,    68,    36,    65,
      37,    -1,    17,    68,    -1,    19,    63,    -1,    18,    65,
      -1,    60,    -1,    56,    -1,    -1,    14,    38,    65,    39,
      59,    -1,    14,    38,    65,    39,    59,    15,    59,    -1,
      14,    38,    65,    39,    59,    16,    -1,    54,    68,    62,
      -1,    42,    61,    -1,    -1,    65,    64,    -1,    42,    63,
      -1,    -1,    68,    -1,    68,    36,    65,    37,    -1,    55,
      -1,    65,    30,    65,    -1,    65,    31,    65,    -1,    65,
      32,    65,    -1,    65,    43,    65,    -1,    65,    20,    65,
      -1,    65,    21,    65,    -1,    65,    22,    65,    -1,    65,
      23,    65,    -1,    65,    24,    65,    -1,    65,    25,    65,
      -1,    65,    28,    65,    -1,    65,    29,    65,    -1,    38,
      65,    39,    -1,    68,    38,    66,    39,    -1,    65,    67,
      -1,    -1,    42,    66,    -1,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    80,    81,    82,    84,    85,    86,    88,
      90,    91,    94,    97,    98,   101,   102,   105,   106,   109,
     110,   111,   112,   115,   116,   117,   118,   119,   122,   125,
     126,   129,   130,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   145,   146,   147,   149,   152,   153,   157,
     159,   160,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   182,
     183,   185,   186,   189
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNDEFINED", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_FALSE", "LIT_TRUE", "LIT_CHAR", "LIT_STRING",
  "KW_INT", "KW_REAL", "KW_BOOL", "KW_CHAR", "KW_IF", "KW_ELSE", "KW_LOOP",
  "KW_INPUT", "KW_RETURN", "KW_OUTPUT", "OPERATOR_LE", "OPERATOR_GE",
  "OPERATOR_EQ", "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR",
  "TOKEN_ERROR", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'%'", "';'",
  "':'", "'['", "']'", "'('", "')'", "'{'", "'}'", "','", "'/'", "$accept",
  "start", "program", "declaracao_variaveis_globais",
  "declaracao_variavel", "declaracao_vetor", "tamanho",
  "inicializacao_vetor", "declaracao_funcao", "variaveis_locais", "tipo",
  "literal", "bloco", "lista_comandos", "resto_comandos", "comando",
  "controle_fluxo", "parametros", "resto_parametros", "lista_output",
  "resto_output", "expressao", "parametros_passados",
  "resto_parametros_passados", "id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   291,   292,     1,     2,     3,     4,     5,     6,     7,
     256,   257,   258,   259,   261,   263,   264,   266,   267,   268,
     270,   271,   272,   273,   274,   275,   290,    61,    60,    62,
      43,    45,    42,    37,    59,    58,    91,    93,    40,    41,
     123,   125,    44,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    47,    47,    47,    48,
      49,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    62,    62,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     3,     3,     0,     4,
       5,     7,     1,     2,     0,     7,     6,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       0,     2,     0,     4,     4,     7,     7,     2,     2,     2,
       1,     1,     0,     5,     7,     6,     3,     2,     0,     2,
       2,     0,     1,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       0,     2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    19,    21,    22,    20,     0,     2,     4,     0,     0,
       0,     0,     1,     8,     8,     5,    73,     0,     6,     0,
       7,     3,     0,     0,     0,     0,    23,    27,    26,    24,
      25,     9,    12,     0,    18,     0,     0,    10,     0,    42,
       0,    48,    18,    14,    18,     0,     0,     0,     0,     0,
      30,    54,    41,    16,    40,     0,    52,     0,     0,    46,
      42,    11,    14,    17,     0,    37,    39,    52,    38,    51,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    47,
      15,    13,     0,     0,     0,    49,    67,    28,    30,    29,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    55,
      56,    57,    58,     0,     0,    72,     0,    42,     0,    50,
      31,    34,    33,    53,    70,    69,    68,    43,    53,     0,
       0,    71,    42,    45,     0,     0,    44,    36,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    33,    61,    10,    39,
      40,    51,    52,    71,    99,    72,    54,    36,    59,    68,
      95,    55,   116,   125,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
      -8,   -39,   -39,   -39,   -39,     9,   -39,   -39,   -17,    10,
      13,    19,   -39,    -8,    -8,    -8,   -39,     2,   -39,    19,
     -39,   -39,    75,    31,    57,    41,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,    20,    -8,    19,    39,    50,    59,   128,
      19,    46,    -8,    75,    -8,    63,    19,     7,     7,     7,
     110,   -39,   -39,   -39,   -39,   131,    54,    68,    -8,   -39,
     128,   -39,    75,   -39,     7,   -39,   307,    -4,   -39,   155,
     171,    64,    70,     7,     7,     7,     7,     7,     7,    73,
       7,     7,     7,     7,     7,     7,    83,     7,     7,   -39,
     -39,   -39,   195,     7,     7,   -39,   -39,   -39,   110,   -39,
      43,    43,    43,    43,    43,    43,    19,    43,    43,   -25,
     -25,    66,   307,     7,   219,   243,    72,   128,   259,   -39,
     -39,    76,   307,    85,     7,   -39,   -39,    82,   -39,     7,
      95,   -39,   128,   -39,   283,     7,   -39,   -39,   307
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   108,    86,    -1,   -39,   -39,    69,   -39,     4,
       6,   -12,   -39,    27,   -39,   -38,   -39,    80,   -39,    32,
     -39,   -22,    15,   -39,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int16 yytable[] =
{
      17,    53,     1,     2,     3,     4,    11,    84,    25,    12,
      31,    16,    26,    27,    28,    29,    30,    13,    85,    19,
      19,    11,    90,    16,    41,    66,    69,    70,    56,    57,
      35,    62,    93,    38,    88,    65,    32,    22,    23,    56,
      24,    38,    92,    38,    14,    49,    60,    15,    63,    56,
      62,   100,   101,   102,   103,   104,   105,    37,   107,   108,
     109,   110,   111,   112,    35,   114,   115,     1,     2,     3,
       4,   118,    69,    82,    83,    84,    22,    23,    42,   127,
      26,    27,    28,    29,    30,    43,    85,    56,    58,    86,
      87,   122,    88,    44,   136,   121,    34,   132,   133,    18,
      20,    64,   115,    22,    98,    97,    56,   134,   106,    85,
     113,   126,   129,   138,    16,    26,    27,    28,    29,    30,
     130,    56,   135,    21,    45,   120,   119,    46,    47,    48,
       0,    91,    16,    26,    27,    28,    29,    30,    89,   131,
       0,     0,    45,     0,   -42,    46,    47,    48,    49,     0,
      50,    73,    74,    75,    76,    77,    78,     0,    79,    80,
      81,    82,    83,    84,     0,     0,    49,     0,    50,     0,
       0,     0,     0,     0,    85,    73,    74,    75,    76,    77,
      78,     0,     0,    80,    81,    82,    83,    84,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    94,    85,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,    85,    73,    74,    75,    76,    77,
      78,     0,     0,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,    85,    73,
      74,    75,    76,    77,    78,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,    85,    73,    74,    75,    76,    77,    78,     0,
       0,    80,    81,    82,    83,    84,     0,     0,     0,    73,
      74,    75,    76,    77,    78,   124,    85,    80,    81,    82,
      83,    84,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,    85,    73,    74,    75,    76,    77,    78,     0,
       0,    80,    81,    82,    83,    84,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,    85,    73,    74,    75,
      76,    77,    78,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-39))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      11,    39,    10,    11,    12,    13,     0,    32,    19,     0,
      22,     4,     5,     6,     7,     8,     9,    34,    43,    13,
      14,    15,    60,     4,    35,    47,    48,    49,    39,    40,
      24,    43,    36,    34,    38,    46,     5,    35,    36,    50,
      38,    42,    64,    44,    34,    38,    42,    34,    44,    60,
      62,    73,    74,    75,    76,    77,    78,    37,    80,    81,
      82,    83,    84,    85,    58,    87,    88,    10,    11,    12,
      13,    93,    94,    30,    31,    32,    35,    36,    39,   117,
       5,     6,     7,     8,     9,    35,    43,    98,    42,    35,
      36,   113,    38,    34,   132,   106,    39,    15,    16,    13,
      14,    38,   124,    35,    34,    41,   117,   129,    35,    43,
      27,    39,    36,   135,     4,     5,     6,     7,     8,     9,
      35,   132,    27,    15,    14,    98,    94,    17,    18,    19,
      -1,    62,     4,     5,     6,     7,     8,     9,    58,   124,
      -1,    -1,    14,    -1,    34,    17,    18,    19,    38,    -1,
      40,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    43,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    42,    43,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    42,    43,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    43,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    45,    46,    47,    48,    49,
      52,    54,     0,    34,    34,    34,     4,    68,    47,    54,
      47,    46,    35,    36,    38,    68,     5,     6,     7,     8,
       9,    55,     5,    50,    39,    54,    61,    37,    48,    53,
      54,    68,    39,    35,    34,    14,    17,    18,    19,    38,
      40,    55,    56,    59,    60,    65,    68,    68,    42,    62,
      53,    51,    55,    53,    38,    68,    65,    68,    63,    65,
      65,    57,    59,    20,    21,    22,    23,    24,    25,    27,
      28,    29,    30,    31,    32,    43,    35,    36,    38,    61,
      59,    51,    65,    36,    42,    64,    39,    41,    34,    58,
      65,    65,    65,    65,    65,    65,    35,    65,    65,    65,
      65,    65,    65,    27,    65,    65,    66,    39,    65,    63,
      57,    68,    65,    37,    42,    67,    39,    59,    37,    36,
      35,    66,    15,    16,    65,    27,    59,    37,    65
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
#line 77 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node); ast_print((yyval.node)); if (output) generate_code(output, (yyval.node));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 80 "parser.y"
    {(yyval.node) = ast_node_new(FUNDEC, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 81 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 82 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 84 "parser.y"
    {(yyval.node) = ast_node_new(GLOBAL_VAR, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 85 "parser.y"
    {(yyval.node) = ast_node_new(GLOBAL_VEC, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 86 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    {(yyval.node) = ast_node_new(VARDEC, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (4)].node));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 90 "parser.y"
    {(yyval.node) = ast_node_new(VECDEC_NOINIT, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (5)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (5)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (5)].node));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 91 "parser.y"
    {(yyval.node) = ast_node_new(VECDEC_INIT, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(7) - (7)].node));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 94 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 97 "parser.y"
    {(yyval.node) = ast_node_new(VECINIT, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (2)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 98 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 101 "parser.y"
    {(yyval.node) = ast_node_new(FUNDEC_PARAMS, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(6) - (7)].node)); 																					       ast_node_add_son((yyval.node), (yyvsp[(7) - (7)].node));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 102 "parser.y"
    {(yyval.node) = ast_node_new(FUNDEC_NOPARAMS, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (6)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (6)].node)); ast_node_add_son((yyval.node), (yyvsp[(5) - (6)].node)); ast_node_add_son((yyval.node), (yyvsp[(6) - (6)].node));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 105 "parser.y"
    {(yyval.node) = ast_node_new(LOCAL_VAR,0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 106 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 109 "parser.y"
    {(yyval.node)=ast_node_new(INT, 0);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 110 "parser.y"
    {(yyval.node)=ast_node_new(CHAR, 0);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    {(yyval.node)=ast_node_new(REAL, 0);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 112 "parser.y"
    {(yyval.node)=ast_node_new(BOOL, 0);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 115 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 116 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 117 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 118 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 119 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    {(yyval.node) = ast_node_new(BLOCK, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    {(yyval.node) = ast_node_new(CMDLIST, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (2)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 126 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 130 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 133 "parser.y"
    {(yyval.node) = ast_node_new(ATTR, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (4)].node));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    {(yyval.node) = ast_node_new(ATTR_REV,0); ast_node_add_son((yyval.node), (yyvsp[(1) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (4)].node));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    {(yyval.node) = ast_node_new(VEC_ATTR, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(7) - (7)].node));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    {(yyval.node) = ast_node_new(VEC_ATTR_REV, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(4) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(6) - (7)].node));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    {(yyval.node) = ast_node_new(INPUT, 0); ast_node_add_son((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    {(yyval.node) = ast_node_new(OUTPUT, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    {(yyval.node) = ast_node_new(RETURN, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    {(yyval.node) = ast_node_new(IF, 0); ast_node_add_son((yyval.node), (yyvsp[(3) - (5)].node)); ast_node_add_son((yyval.node), (yyvsp[(5) - (5)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    {(yyval.node) = ast_node_new(IF_ELSE, 0); ast_node_add_son((yyval.node),(yyvsp[(3) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(5) - (7)].node)); ast_node_add_son((yyval.node), (yyvsp[(7) - (7)].node));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    {(yyval.node) = ast_node_new(IF_LOOP, 0); ast_node_add_son((yyval.node), (yyvsp[(3) - (6)].node)); ast_node_add_son((yyval.node),(yyvsp[(5) - (6)].node));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    {(yyval.node) = ast_node_new(FUNC_DEC_PARAMS, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 152 "parser.y"
    {(yyval.node) = ast_node_new(FUNC_DEC_PARAMS_REST, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 157 "parser.y"
    {(yyval.node) = ast_node_new(OUTPUT_LIST, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (2)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    {(yyval.node) = ast_node_new(OUTPUT_LIST_REST, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    {(yyval.node) = ast_node_new(ID_WORD, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (1)].node));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    {(yyval.node) = ast_node_new(VECTOR, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (4)].node));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    {(yyval.node) = ast_node_new(ADD, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 167 "parser.y"
    {(yyval.node) = ast_node_new(SUB, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    {(yyval.node) = ast_node_new(MUL, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    {(yyval.node) = ast_node_new(DIV, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    {(yyval.node) = ast_node_new(LE, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    {(yyval.node) = ast_node_new(GE, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    {(yyval.node) = ast_node_new(EQ, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    {(yyval.node) = ast_node_new(NE, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    {(yyval.node) = ast_node_new(AND, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    {(yyval.node) = ast_node_new(OR, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    {(yyval.node) = ast_node_new(LESS, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    {(yyval.node) = ast_node_new(GREATER, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (3)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    {(yyval.node) = ast_node_new(EXP, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (3)].node));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    {(yyval.node) = ast_node_new(FUNC_CALL, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (4)].node)); ast_node_add_son((yyval.node), (yyvsp[(3) - (4)].node));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    {(yyval.node) = ast_node_new(FUNC_CALL_PARAMS, 0); ast_node_add_son((yyval.node), (yyvsp[(1) - (2)].node)); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 185 "parser.y"
    {(yyval.node) = ast_node_new(FUNC_CALL_PARAMS_REST, 0); ast_node_add_son((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    {(yyval.node) = 0;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    {(yyval.node) = ast_node_new(SYMBOL, (yyvsp[(1) - (1)].symbol));}
    break;



/* Line 1806 of yacc.c  */
#line 2085 "y.tab.c"
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
#line 191 "parser.y"


int setoutput(FILE * new_output) {
	output = new_output;
}

int yyerror(char * str){

	printf("Erro sintatico na linha %d!\n", getLineNumber());
	printf("-----------------\n");
	exit(3);
}



