/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cbu2.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG	0

#define	 MAXSYM	100
#define	 MAXSYMLEN	20
#define	 MAXTSYMLEN	15
#define	 MAXTSYMBOL	MAXSYM/2

#define STMTLIST 500

typedef struct nodeType {
	int token;
	int tokenval;
	struct nodeType *son;
	struct nodeType *brother;
	} Node;

#define YYSTYPE Node*
	
int tsymbolcnt=0;
int errorcnt=0;
int iflabel=0;
int Rlabel=0;
int modlabel=0;
int arrsize=0;
char ch;

FILE *yyin;
FILE *fp;

extern char symtbl[MAXSYM][MAXSYMLEN];
extern int maxsym;
extern int lineno;

void DFSTree(Node*);
Node * MakeOPTree(int, Node*, Node*);
Node * MakeNode(int, int);
Node * MakeListTree(Node*, Node*);
Node * MakeIFTree(int, int, Node*, Node*);
Node * MakeIFELSETree(int, int, int, Node*, Node*, Node*);
Node * MakeWHILETree(int, int, Node*, Node*);
Node * MakeAATree(int, int, Node*, Node*);
Node * MakeINPUTTree(int,int, Node*);
void codegen(Node* );
void prtcode(int, int, Node * n);

void	dwgen(Node*);
void 	finish();
int	gentemp();
void	assgnstmt(int, int);
void	numassgn(int, int);
void	addstmt(int, int, int);
void	substmt(int, int, int);
void	ifstmt(Node*, Node*);;
int		insertsym(char *);

/* Line 371 of yacc.c  */
#line 129 "cbu2.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "cbu2.h".  */
#ifndef YY_YY_CBU2_H_INCLUDED
# define YY_YY_CBU2_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     IF = 259,
     IF2 = 260,
     THEN = 261,
     ELSE = 262,
     WHILE = 263,
     LOOP = 264,
     CONTINUE = 265,
     BREAK = 266,
     LT = 267,
     GT = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NE = 272,
     AND = 273,
     OR = 274,
     ADD = 275,
     SUB = 276,
     MUL = 277,
     DIV = 278,
     MOD = 279,
     MOD2 = 280,
     ADDASSGN = 281,
     SUBASSGN = 282,
     MULASSGN = 283,
     DIVASSGN = 284,
     ARRASSGN = 285,
     ASSGN = 286,
     ID = 287,
     NUM = 288,
     CHAR = 289,
     STMTEND = 290,
     START = 291,
     END = 292,
     ID2 = 293,
     ID3 = 294,
     VAR = 295,
     INPUT = 296,
     PRINTNUM = 297,
     PRINTCH = 298,
     IFX = 299
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_CBU2_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 239 "cbu2.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNRULES -- Number of states.  */
#define YYNSTATES  91

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    20,    25,    30,
      35,    40,    44,    48,    52,    56,    62,    65,    68,    73,
      80,    85,    89,    93,    97,   101,   105,   109,   113,   117,
     121,   125,   129,   133,   137,   141,   145,   147,   149,   151
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    36,    51,    37,    -1,    51,    52,    -1,
      52,    -1,     1,    35,    -1,    32,    31,    53,    35,    -1,
      32,    26,    53,    35,    -1,    32,    27,    53,    35,    -1,
      32,    28,    53,    35,    -1,    32,    29,    53,    35,    -1,
      41,    32,    35,    -1,    42,    53,    35,    -1,    43,    53,
      35,    -1,    40,    32,    35,    -1,    40,    32,    31,    53,
      35,    -1,    11,    35,    -1,    10,    35,    -1,     4,    53,
       6,    52,    -1,     4,    53,     6,    52,     7,    52,    -1,
       8,    53,     6,    52,    -1,    45,    51,    46,    -1,    53,
      20,    53,    -1,    53,    21,    53,    -1,    53,    22,    53,
      -1,    53,    23,    53,    -1,    53,    24,    53,    -1,    53,
      12,    53,    -1,    53,    13,    53,    -1,    53,    14,    53,
      -1,    53,    15,    53,    -1,    53,    16,    53,    -1,    53,
      17,    53,    -1,    53,    18,    53,    -1,    53,    19,    53,
      -1,    47,    53,    48,    -1,    54,    -1,    32,    -1,    33,
      -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    77,    78,    79,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   117,   118,   119
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "IF", "IF2", "THEN", "ELSE",
  "WHILE", "LOOP", "CONTINUE", "BREAK", "LT", "GT", "LE", "GE", "EQ", "NE",
  "AND", "OR", "ADD", "SUB", "MUL", "DIV", "MOD", "MOD2", "ADDASSGN",
  "SUBASSGN", "MULASSGN", "DIVASSGN", "ARRASSGN", "ASSGN", "ID", "NUM",
  "CHAR", "STMTEND", "START", "END", "ID2", "ID3", "VAR", "INPUT",
  "PRINTNUM", "PRINTCH", "IFX", "'{'", "'}'", "'('", "')'", "$accept",
  "program", "stmt_list", "stmt", "expr", "term", YY_NULL
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
     295,   296,   297,   298,   299,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     5,     2,     2,     4,     6,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     1,     5,    37,    38,
      39,     0,     0,    36,     0,    17,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    11,    12,    13,    21,    35,    18,    27,    28,
      29,    30,    31,    32,    33,    34,    22,    23,    24,    25,
      26,    20,     7,     8,     9,    10,     6,     0,     0,    15,
      19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    14,    15,    22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int16 yypact[] =
{
     -30,    53,     7,   -26,   -31,   -31,   -25,   -18,     6,   -13,
     -12,   -31,   -31,    53,    80,   -32,   -32,   -32,   -32,   -32,
     -32,   -31,   345,   -32,   364,   -32,   -32,   -31,   -31,   -31,
     -31,   -31,   -27,   -17,   153,   177,    65,   -32,   -32,   139,
     105,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   105,   201,   225,   249,   273,   297,
     -31,   -32,   -32,   -32,   -32,   -32,   -32,    16,    57,    57,
      57,    57,    57,    57,   118,   118,    -9,    -9,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   321,   105,   -32,
     -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    11,   -14,     0,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    18,    19,    20,    60,    24,     1,    16,    61,    17,
      25,    34,    35,    51,    52,    53,    21,    26,    62,    32,
      33,    39,    38,    88,    36,     0,    67,    55,    56,    57,
      58,    59,    27,    28,    29,    30,     0,    31,     0,     0,
      81,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     3,     0,     0,     4,     0,     0,
      87,     5,     0,     6,     7,     0,     0,     0,     0,     4,
       0,     0,     0,     5,    90,     6,     7,    49,    50,    51,
      52,    53,     0,     0,     4,     8,     0,     0,     5,     0,
       6,     7,     0,     9,    10,    11,    12,     8,    13,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,     4,
      13,    65,     8,     5,     0,     6,     7,    37,     0,     0,
       9,    10,    11,    12,     0,    13,     0,     0,     0,     0,
      41,    42,    43,    44,    45,    46,     0,     8,    49,    50,
      51,    52,    53,     0,     0,     9,    10,    11,    12,     0,
      13,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    63,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,    89,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      14,    32,    33,    34,    31,     5,    36,     0,    35,    35,
      35,    11,    12,    22,    23,    24,    47,    35,    35,    32,
      32,    21,    36,     7,    13,    -1,    40,    27,    28,    29,
      30,    31,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      54,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     1,    -1,    -1,     4,    -1,    -1,
      60,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,     8,    88,    10,    11,    20,    21,    22,
      23,    24,    -1,    -1,     4,    32,    -1,    -1,     8,    -1,
      10,    11,    -1,    40,    41,    42,    43,    32,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,     4,
      45,    46,    32,     8,    -1,    10,    11,    37,    -1,    -1,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    -1,    32,    20,    21,
      22,    23,    24,    -1,    -1,    40,    41,    42,    43,    -1,
      45,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    35,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    35,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    50,     1,     4,     8,    10,    11,    32,    40,
      41,    42,    43,    45,    51,    52,     0,    35,    32,    33,
      34,    47,    53,    54,    53,    35,    35,    26,    27,    28,
      29,    31,    32,    32,    53,    53,    51,    37,    52,    53,
       6,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     6,    53,    53,    53,    53,    53,
      31,    35,    35,    35,    35,    46,    48,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    52,    35,    35,    35,    35,    35,    53,     7,    35,
      52
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
/* Line 1792 of yacc.c  */
#line 74 "cbu2.y"
    { if (errorcnt==0) {codegen((yyvsp[(2) - (3)])); finish();} }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 77 "cbu2.y"
    {(yyval)=MakeListTree((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 78 "cbu2.y"
    {(yyval)=MakeListTree(NULL, (yyvsp[(1) - (1)]));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 79 "cbu2.y"
    { errorcnt++; yyerrok;}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 82 "cbu2.y"
    { (yyvsp[(1) - (4)])->token = ID2; (yyval)=MakeOPTree(ASSGN, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 83 "cbu2.y"
    { (yyvsp[(1) - (4)])->token = ID3; (yyval)=MakeAATree(ASSGN, ADD, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 84 "cbu2.y"
    { (yyvsp[(1) - (4)])->token = ID3; (yyval)=MakeAATree(ASSGN, SUB, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 85 "cbu2.y"
    { (yyvsp[(1) - (4)])->token = ID3; (yyval)=MakeAATree(ASSGN, MUL, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 86 "cbu2.y"
    { (yyvsp[(1) - (4)])->token = ID3; (yyval)=MakeAATree(ASSGN, DIV, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 87 "cbu2.y"
    { (yyvsp[(2) - (3)])->token = ID2; (yyval) = MakeINPUTTree(ASSGN,INPUT, (yyvsp[(2) - (3)])); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 88 "cbu2.y"
    { (yyval)=MakeNode(PRINTNUM,PRINTNUM); (yyval)->son = (yyvsp[(2) - (3)]);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 89 "cbu2.y"
    { (yyval)=MakeNode(PRINTCH,PRINTCH); (yyval)->son = (yyvsp[(2) - (3)]);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 90 "cbu2.y"
    {dwgen((yyvsp[(2) - (3)])); (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 91 "cbu2.y"
    { dwgen((yyvsp[(2) - (5)])); (yyvsp[(2) - (5)])->token = ID2; (yyval)=MakeOPTree(ASSGN, (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 92 "cbu2.y"
    { (yyval)=MakeNode(BREAK, BREAK); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 93 "cbu2.y"
    { (yyval)=MakeNode(CONTINUE, CONTINUE); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 94 "cbu2.y"
    { (yyval)=MakeIFTree(IF, THEN, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 95 "cbu2.y"
    { (yyval)=MakeIFELSETree(IF, THEN, ELSE, (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 96 "cbu2.y"
    { (yyval)=MakeWHILETree(WHILE, THEN, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 97 "cbu2.y"
    { (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 100 "cbu2.y"
    { (yyval)=MakeOPTree(ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 101 "cbu2.y"
    { (yyval)=MakeOPTree(SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 102 "cbu2.y"
    { (yyval)=MakeOPTree(MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 103 "cbu2.y"
    { (yyval)=MakeOPTree(DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 104 "cbu2.y"
    { (yyval)=MakeOPTree(MOD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 105 "cbu2.y"
    { (yyval)=MakeOPTree(LT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 106 "cbu2.y"
    { (yyval)=MakeOPTree(GT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 107 "cbu2.y"
    { (yyval)=MakeOPTree(LE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 108 "cbu2.y"
    { (yyval)=MakeOPTree(GE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 109 "cbu2.y"
    { (yyval)=MakeOPTree(EQ, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 110 "cbu2.y"
    { (yyval)=MakeOPTree(NE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 111 "cbu2.y"
    { (yyval)=MakeOPTree(AND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 112 "cbu2.y"
    { (yyval)=MakeOPTree(OR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 113 "cbu2.y"
    { (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 114 "cbu2.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 117 "cbu2.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 118 "cbu2.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 119 "cbu2.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;


/* Line 1792 of yacc.c  */
#line 1785 "cbu2.c"
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


/* Line 2055 of yacc.c  */
#line 123 "cbu2.y"

int main(int argc, char *argv[]) 
{
	printf("\nsample CBU compiler v2.0\n");
	printf("(C) Copyright by Jae Sung Lee (jasonlee@cbnu.ac.kr), 2022.\n");
	
	if (argc == 2)
		yyin = fopen(argv[1], "r");
	else {
		printf("Usage: cbu2 inputfile\noutput file is 'a.asm'\n");
		return(0);
		}
		
	fp=fopen("a.asm", "w");
	
	yyparse();
	
	fclose(yyin);
	fclose(fp);

	if (errorcnt==0) 
		{ printf("Successfully compiled. Assembly code is in 'a.asm'.\n");}
}

yyerror(s)
char *s;
{
	printf("%s (line %d)\n", s, lineno);
}

Node * MakeOPTree(int op, Node* operand1, Node* operand2)
{
Node * newnode;
Node * mod2;

	newnode = (Node *)malloc(sizeof (Node));
	newnode->token = op;
	newnode->tokenval = op;
	newnode->son = operand1;
	newnode->brother = NULL;
	operand1->brother = operand2;
	if(op==MOD){
		mod2 = (Node *)malloc(sizeof (Node));
		mod2->token=MOD2;
		mod2->tokenval=MOD2;
		mod2->son = NULL;
		mod2->brother = operand1;
		newnode->son = mod2;
	}
	return newnode;
}

Node * MakeNode(int token, int operand)
{
Node * newnode;

	newnode = (Node *) malloc(sizeof (Node));
	newnode->token = token;
	newnode->tokenval = operand; 
	newnode->son = newnode->brother = NULL;
	return newnode;
}

Node * MakeListTree(Node* operand1, Node* operand2)
{
Node * newnode;
Node * node;

	if (operand1 == NULL){
		newnode = (Node *)malloc(sizeof (Node));
		newnode->token = newnode-> tokenval = STMTLIST;
		newnode->son = operand2;
		newnode->brother = NULL;
		return newnode;
		}
	else {
		node = operand1->son;
		while (node->brother != NULL) node = node->brother;
		node->brother = operand2;
		return operand1;
		}
}

Node * MakeIFTree(int op1, int op2, Node* operand1, Node* operand2)
{
Node * newnode;
Node * condition;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	newnode->brother = NULL;
	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	operand1->brother = condition;
	condition->brother = operand2;
	return newnode;
}

Node * MakeIFELSETree(int op1, int op2, int op3, Node* operand1, Node* operand2, Node* operand3)
{
Node * newnode;
Node * condition;
Node * newnode2;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	newnode2 = (Node *)malloc(sizeof(Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	newnode->brother = NULL;
	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	condition->brother = operand2;
	newnode2->token=op3;
	newnode2->token=op3;
	newnode2->son = NULL;
	newnode2->brother = operand3;
	operand1->brother = condition;
	operand2->brother = newnode2;
	
	return newnode;
}

Node * MakeWHILETree(int op1, int op2, Node* operand1, Node* operand2)
{
Node * newnode;
Node * condition;
Node * back;
	newnode = (Node *)malloc(sizeof (Node));
	condition = (Node *)malloc(sizeof (Node));
	back = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = back;
	newnode->brother = NULL;
	
	back->token = LOOP;
	back->tokenval = LOOP;
	back->son = NULL;
	back->brother = operand1;

	condition->token = op2;
	condition->tokenval = op2;
	condition->son = NULL;
	condition->brother = operand2;
	operand1->brother = condition;
	return newnode;
}

Node * MakeAATree(int op1, int op2, Node* operand1, Node* operand2){
Node * newnode;
Node * assgn;
Node * add;
	newnode = (Node *)malloc(sizeof (Node));
	assgn = (Node *)malloc(sizeof (Node));
	add = (Node *)malloc(sizeof (Node));
	assgn->token = ASSGN;
	assgn->tokenval = ASSGN;
	add->token = op2;
	add->tokenval = op2;
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->son = operand1;
	operand1->brother = operand2;
	newnode->brother = NULL;
	operand2->brother = add;
	add->brother = NULL;
	add->son = NULL;
	return newnode;
}

Node * MakeINPUTTree(int op1,int op2, Node * id){
Node * newnode;
Node * newnode2;
	newnode = (Node *)malloc(sizeof (Node));
	newnode->token = op1;
	newnode->tokenval = op1;
	newnode->brother = NULL;
	newnode2 = (Node *)malloc(sizeof (Node));
	newnode2->token = op2;
	newnode2->tokenval = op2;
	newnode2->son = NULL;
	newnode2->brother = NULL;
	newnode->son = id;
	id->brother=newnode2;
	return newnode;
}

void codegen(Node * root)
{
	DFSTree(root);
}

void DFSTree(Node * n)
{
	if (n==NULL) return;
	if (n->token == MOD) DFSTree(n->son);
	DFSTree(n->son);
	prtcode(n->token, n->tokenval, n);
	DFSTree(n->brother);
}

void prtcode(int token, int val, Node* n)
{
	switch (token) {
	case ID:
		fprintf(fp,"RVALUE %s\n", symtbl[val]);
		break;
	case ID2:
		fprintf(fp, "LVALUE %s\n", symtbl[val]);
		break;
	case ID3:
		fprintf(fp, "LVALUE %s\n", symtbl[val]);
		fprintf(fp, "RVALUE %s\n", symtbl[val]);
		break;
	case PRINTNUM:
		fprintf(fp, "OUTNUM\n");
		break;
	case PRINTCH:
		fprintf(fp, "OUTCH\n");
		break;
	case INPUT:
		fprintf(fp, "INNUM\n");
		break;
	case NUM:
		fprintf(fp, "PUSH %d\n", val);
		break;
	case CHAR:
		fprintf(fp, "PUSH %d\n" , symtbl[val][1]);
		break;
	case IF:
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case THEN:
		fprintf(fp, "GOFALSE iflabel%d\n",iflabel);
		break;
	case ELSE:
		fprintf(fp, "GOTO iflabel%d\n", iflabel);
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case WHILE:
		iflabel = iflabel - 1;
		fprintf(fp, "GOTO iflabel%d\n", iflabel);
		iflabel++;
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case LOOP:
		fprintf(fp, "LABEL iflabel%d\n",iflabel);
		iflabel++;
		break;
	case CONTINUE:
		iflabel--;
		fprintf(fp, "GOTO iflabel%d\n",iflabel);
		iflabel++;
		break;
	case BREAK:
		fprintf(fp, "GOTO iflabel%d\n",iflabel);
		break;
	case ADD:
		fprintf(fp, "+\n");
		break;
	case SUB:
		fprintf(fp, "-\n");
		break;
	case MUL:
		fprintf(fp, "*\n");
		break;
	case DIV:
		fprintf(fp, "/\n");
		break;
	case MOD:
		fprintf(fp, "/\n");
		fprintf(fp, "*\n");
		fprintf(fp, "-\n");
		break;
	case AND:
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case OR:
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case LT:
		fprintf(fp, "-\n");
		fprintf(fp, "GOMINUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case GT:
		fprintf(fp, "-\n");
		fprintf(fp, "GOPLUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
        Rlabel++;
		break;
	case LE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOPLUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
        Rlabel++;
		break;
	case GE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOMINUS Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case EQ:
		fprintf(fp, "-\n");
		fprintf(fp, "GOTRUE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case NE:
		fprintf(fp, "-\n");
		fprintf(fp, "GOFALSE Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 1\n");
		fprintf(fp, "GOTO Routlabel%d\n",Rlabel);
		fprintf(fp, "LABEL Rlabel%d\n",Rlabel);
		fprintf(fp, "PUSH 0\n");
		fprintf(fp, "LABEL Routlabel%d\n",Rlabel);
		Rlabel++;
		break;
	case ASSGN:
		fprintf(fp, ":=\n");
        break;
	case ARRASSGN:
		fprintf(fp, ":=\n");
		break;
	case STMTLIST:
	default:
		break;
	};
}


/*
int gentemp()
{
char buffer[MAXTSYMLEN];
char tempsym[MAXSYMLEN]="TTCBU";

	tsymbolcnt++;
	if (tsymbolcnt > MAXTSYMBOL) printf("temp symbol overflow\n");
	itoa(tsymbolcnt, buffer, 10);
	strcat(tempsym, buffer);
	return( insertsym(tempsym) ); // Warning: duplicated symbol is not checked for lazy implementation
}
*/
void dwgen(Node * i)
{
// Warning: this code should be different if variable declaration is supported in the language 
	fprintf(fp, "DW %s\n", symtbl[i->tokenval]);
	
}

void finish()
{
	fprintf(fp, "HALT\n");
	fprintf(fp, "$ -- END OF EXECUTION CODE AND START OF VAR DEFINITIONS --\n");
	fprintf(fp, "END\n");
}
