
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "2007031.y"

#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
extern FILE *yyout;
int yylex();
int yyerror(char *s);

// Symbol Table Arrays
char var_name[1000][100];
int store_int[1000];
float store_float[1000];
char store_String[1000][100];
int type[1000];
int var_type_pointer = 0; // 0 = int, 1 = float, 2 = string, 3 = function, 4 = char
int store_char[1000];

// Conditional Statement Variables
int if_pointer = 0;
int store_if[1000];

// Switch Handling Variables
int switch_var = 0; 
int switch_case = 0;

// Variable Counter
int var_cnt = 0;

// Variable Declaration Check
int checkDeclared(char *s){
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0)
                return 1;
    }
    return 0;
}

// New Variable Declaration
int varAssign(char *s){
    if(checkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store_int[var_cnt] = 0;
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
    store_char[var_cnt] = '\0';
    type[var_cnt] = var_type_pointer;
    char name[10];
    if(var_type_pointer == 0) {
        strcpy(name, "Int");
    }
    else if(var_type_pointer == 1) {
        strcpy(name, "Float");
    }
    else if(var_type_pointer == 2) {
        strcpy(name, "String");
    }
    else if(var_type_pointer == 4) {
        strcpy(name, "Char");
    }
    printf("\n>> DECLARATION: Variable '%s' of type '%s' has been declared\n", var_name[var_cnt], name);
    var_cnt++;
    return 1;
}

// New Function Declaration
int functionAssign(char *s){
    if(checkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store_int[var_cnt] = 0;
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
    type[var_cnt] = 3;
    printf("\nNew Function Declared With Name: %s\n", var_name[var_cnt]);
    var_cnt++;
    return 1;
}

// Assigning Value to Variable
int setValue(char *s, char* val){
    if(checkDeclared(s) == 0){
        return 0;
    }
    int ok=0, i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            ok = i;
            break;
        }
    }
    if(type[ok] == 0){
        store_int[ok] = atoi(val);
        printf("\n>> ASSIGNMENT: Integer variable '%s' = %d\n", var_name[ok], store_int[ok]);
    }
    else if(type[ok] == 1){
        store_float[ok] = atof(val);
        printf("\n>> ASSIGNMENT: Float variable '%s' = %f\n", var_name[ok], store_float[ok]);
    }
    else if(type[ok] == 2){
        strcpy(store_String[ok], val);
        printf("\n>> ASSIGNMENT: String variable '%s' = %s\n", var_name[ok], store_String[ok]);
    }
    else if(type[ok] == 4){
        store_char[ok] = val[1];  // Skip the quotes and get the character
        printf("\n>> ASSIGNMENT: Character variable '%s' = %c\n", var_name[ok], store_char[ok]);
    }
    else{
        printf("\nCan't Assign Value as Variable is a Function!\n");
    }
    return 1;
}

// Get Variable Value
int getValue(char *s){
    int pos=-1;
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            pos=i;
            break;
        }
    }
    return pos;
}


/* Line 189 of yacc.c  */
#line 206 "2007031.tab.c"

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
     END = 258,
     INT = 259,
     FLOAT = 260,
     STRING = 261,
     MOD = 262,
     CHAR = 263,
     LT = 264,
     GT = 265,
     GEQ = 266,
     LEQ = 267,
     EQ = 268,
     NEQ = 269,
     VARIABLE = 270,
     NUMBER = 271,
     CHAR_LIT = 272,
     STR = 273,
     IMPORT = 274,
     HEADER = 275,
     MAIN = 276,
     INC = 277,
     DEC = 278,
     NOT = 279,
     SIN = 280,
     COS = 281,
     LOG = 282,
     TAN = 283,
     LN = 284,
     ODDEVEN = 285,
     FACTORIAL = 286,
     MAX = 287,
     MIN = 288,
     PRIME = 289,
     DEF = 290,
     DISPLAY = 291,
     IF = 292,
     ELSE_IF = 293,
     ELSE = 294,
     FOR = 295,
     FLINC = 296,
     FLDEC = 297,
     WHILE = 298,
     CASE = 299,
     SWITCH = 300,
     DEFAULT = 301,
     STRCAT = 302,
     STRJOIN = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 134 "2007031.y"

    int num;
    float flt;
    char* string;



/* Line 214 of yacc.c  */
#line 298 "2007031.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 310 "2007031.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   968

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,    51,    49,    60,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      58,    61,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    13,    15,    16,    22,    30,    31,
      34,    39,    42,    44,    47,    48,    50,    52,    55,    60,
      63,    69,    74,    79,    84,    92,   100,   108,   110,   112,
     113,   121,   128,   132,   134,   136,   137,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   169,   174,   179,
     181,   186,   188,   192,   194,   195,   199,   201,   203,   205,
     207,   211,   217,   219,   223,   225,   227,   229,   231,   235,
     239,   243,   247,   251,   255,   259,   263,   267,   271,   275,
     279,   283,   286,   289,   292,   297,   302,   307,   312,   317,
     322,   327,   334,   341,   346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    66,    67,    65,    54,    55,    56,    71,
      57,    -1,    -1,    21,    -1,    -1,    66,    19,    58,    20,
      59,    -1,    68,    54,    69,    55,    56,    71,    57,    -1,
      -1,    35,    15,    -1,    69,    60,    90,    70,    -1,    90,
      70,    -1,    15,    -1,    71,    72,    -1,    -1,     3,    -1,
      89,    -1,    92,     3,    -1,    15,    61,    92,     3,    -1,
      86,     3,    -1,    36,    54,    15,    55,     3,    -1,    83,
      56,    71,    57,    -1,    84,    56,    71,    57,    -1,    85,
      56,    71,    57,    -1,    78,    54,    79,    55,    56,    71,
      57,    -1,    77,    54,    76,    55,    56,    71,    57,    -1,
      73,    54,    74,    55,    56,    75,    57,    -1,    45,    -1,
      92,    -1,    -1,    75,    44,    92,    62,    56,    71,    57,
      -1,    75,    46,    62,    56,    71,    57,    -1,    15,    81,
      80,    -1,    43,    -1,    40,    -1,    -1,    15,    61,    80,
      60,    15,    81,    80,    60,    15,    82,    80,    -1,    16,
      -1,    15,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    41,    -1,    42,    -1,    37,
      54,    92,    55,    -1,    38,    54,    92,    55,    -1,    39,
      -1,    87,    54,    88,    55,    -1,    15,    -1,    88,    60,
      15,    -1,    15,    -1,    -1,    90,    91,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     8,    -1,    91,    60,    15,
      -1,    91,    60,    15,    61,    92,    -1,    15,    -1,    15,
      61,    92,    -1,    16,    -1,    18,    -1,    17,    -1,    15,
      -1,    92,    49,    92,    -1,    92,    50,    92,    -1,    92,
      51,    92,    -1,    92,    52,    92,    -1,    92,    53,    92,
      -1,    92,     7,    92,    -1,    54,    92,    55,    -1,    92,
       9,    92,    -1,    92,    10,    92,    -1,    92,    12,    92,
      -1,    92,    11,    92,    -1,    92,    13,    92,    -1,    92,
      14,    92,    -1,    15,    22,    -1,    15,    23,    -1,    24,
      15,    -1,    25,    54,    92,    55,    -1,    26,    54,    92,
      55,    -1,    28,    54,    92,    55,    -1,    27,    54,    92,
      55,    -1,    29,    54,    92,    55,    -1,    30,    54,    92,
      55,    -1,    31,    54,    92,    55,    -1,    32,    54,    92,
      60,    92,    55,    -1,    33,    54,    92,    60,    92,    55,
      -1,    34,    54,    92,    55,    -1,    48,    54,    92,    60,
      92,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   169,   173,   175,   176,   180,   183,   187,
     197,   198,   202,   213,   214,   218,   219,   220,   221,   232,
     233,   256,   259,   262,   265,   268,   271,   277,   283,   289,
     290,   300,   309,   319,   324,   328,   329,   344,   345,   356,
     357,   358,   359,   360,   361,   365,   368,   374,   387,   399,
     410,   416,   426,   435,   444,   448,   452,   453,   454,   455,
     459,   467,   476,   482,   494,   504,   509,   514,   543,   581,
     589,   621,   657,   689,   721,   725,   733,   741,   749,   757,
     765,   773,   800,   827,   854,   860,   866,   872,   878,   884,
     896,   907,   920,   933,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "INT", "FLOAT", "STRING", "MOD",
  "CHAR", "LT", "GT", "GEQ", "LEQ", "EQ", "NEQ", "VARIABLE", "NUMBER",
  "CHAR_LIT", "STR", "IMPORT", "HEADER", "MAIN", "INC", "DEC", "NOT",
  "SIN", "COS", "LOG", "TAN", "LN", "ODDEVEN", "FACTORIAL", "MAX", "MIN",
  "PRIME", "DEF", "DISPLAY", "IF", "ELSE_IF", "ELSE", "FOR", "FLINC",
  "FLDEC", "WHILE", "CASE", "SWITCH", "DEFAULT", "STRCAT", "STRJOIN",
  "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'", "'{'", "'}'", "'<'",
  "'>'", "','", "'='", "':'", "$accept", "program", "main", "import",
  "func", "func_head", "param", "pid", "statements", "cstatement",
  "switch_start", "switch_exp", "switch_statement", "while_loop",
  "while_start", "for_start", "for_loop", "loop_assign", "loop_exp",
  "f_state", "if_condition", "else_if_condition", "else_condition",
  "function_call", "f_var", "call_param", "declare", "type", "id",
  "expression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    43,
      45,    42,    47,    94,    40,    41,   123,   125,    60,    62,
      44,    61,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    74,    75,
      75,    75,    76,    77,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    84,    85,
      86,    87,    88,    88,    88,    89,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     1,     0,     5,     7,     0,     2,
       4,     2,     1,     2,     0,     1,     1,     2,     4,     2,
       5,     4,     4,     4,     7,     7,     7,     1,     1,     0,
       7,     6,     3,     1,     1,     0,    11,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       4,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       3,     5,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     8,     1,     0,     0,     0,     0,     0,     9,
       4,     0,     0,     0,     0,    56,    57,    58,    59,     0,
       0,     6,     0,     0,     0,    12,    11,    14,    14,     0,
       0,     0,    10,    15,    67,    64,    66,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    34,    33,    27,     0,     0,     2,    13,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     7,    81,    82,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,    35,    14,    14,    14,    19,    54,
      62,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,    28,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,    55,     0,    73,    75,    76,    78,    77,
      79,    80,    68,    69,    70,    71,    72,    18,    84,    85,
      87,    86,    88,    89,    90,     0,     0,    93,     0,    47,
      48,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,    21,    22,    23,    50,     0,    63,    60,
       0,     0,    20,     0,    29,    38,    37,    32,    14,     0,
      14,    52,     0,    91,    92,    94,     0,     0,     0,     0,
      61,     0,     0,    26,    25,     0,    24,     0,     0,     0,
       0,    14,     0,    14,     0,     0,     0,    31,     0,    30,
      45,    46,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    11,     2,     6,     7,    19,    26,    30,    59,
      60,   131,   206,   134,    61,    62,   136,   197,   179,   232,
      63,    64,    65,    66,    67,   141,    68,    69,   101,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
       4,    15,    25,  -148,   -15,    77,    52,    39,    74,  -148,
    -148,    41,    83,    37,    43,  -148,  -148,  -148,  -148,   -43,
      82,  -148,    47,    49,    83,  -148,  -148,  -148,  -148,    82,
      96,   172,  -148,  -148,    84,  -148,  -148,  -148,    93,    62,
      63,    64,    65,    86,    88,    89,    94,    95,    97,    98,
     100,   102,  -148,  -148,  -148,  -148,   103,   914,  -148,  -148,
     104,   105,   106,    75,    81,    91,   158,   108,  -148,   148,
     626,  -148,  -148,  -148,   914,  -148,   914,   914,   914,   914,
     914,   914,   914,   914,   914,   914,   149,   914,   914,   914,
      -9,   646,   914,   150,   151,  -148,  -148,  -148,  -148,   152,
     107,    -1,  -148,   914,   914,   914,   914,   914,   914,   914,
     914,   914,   914,   914,   914,   638,   654,   701,   709,   717,
     725,   733,   780,   550,   562,   788,   114,   796,   804,   574,
    -148,   116,   875,    -3,   118,   113,   124,   219,   266,   313,
    -148,    11,   914,  -148,   166,   129,    12,    12,    12,    12,
      12,    12,    23,    23,   129,   129,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   914,   914,  -148,   180,  -148,
    -148,   914,   128,  -148,  -148,  -148,  -148,  -148,  -148,    30,
     130,    30,   135,  -148,  -148,  -148,  -148,   170,   875,   131,
     812,   859,  -148,   867,  -148,  -148,  -148,  -148,  -148,   134,
    -148,  -148,   914,  -148,  -148,  -148,   -41,   360,   192,   407,
     875,   914,   154,  -148,  -148,    -3,  -148,    28,   157,    30,
     162,  -148,   159,  -148,   454,   199,   501,  -148,    42,  -148,
    -148,  -148,    30,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   201,   -28,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -147,     6,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,    58,  -148,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      31,    91,   143,   211,    -3,   212,   173,   174,   175,   176,
     177,   178,    23,    72,    73,     3,   213,    24,   115,   103,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     103,   127,   128,   129,   199,   103,   132,   104,   105,   106,
     107,   108,   109,     8,     4,   195,   196,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   144,
       5,   110,   111,   112,   113,   114,   186,   137,   138,   139,
      20,   187,   222,    10,   112,   113,   114,   110,   111,   112,
     113,   114,    29,   230,   231,   233,   188,    15,    16,    17,
     220,    18,     9,    12,    13,    14,    21,    25,    22,    33,
      15,    16,    17,    27,    18,    28,    72,    73,    75,   190,
     191,    34,    35,    36,    37,   193,    76,    77,    78,    79,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    95,    49,    50,    51,    52,    53,    96,   -51,    54,
      80,    55,    81,    82,    56,    74,   210,    97,    83,    84,
      57,    85,    86,    58,    87,   217,    88,    89,    92,    93,
      94,    98,    99,   100,   126,   133,   135,   140,   142,   168,
     207,   172,   209,   180,   181,    33,    15,    16,    17,   182,
      18,   189,   114,   192,   194,   201,   198,    34,    35,    36,
      37,   200,   202,   224,   208,   226,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   215,    49,    50,
      51,    52,    53,   221,   228,    54,   218,    55,   223,   225,
      56,   219,    33,    15,    16,    17,    57,    18,     0,    71,
      32,     0,     0,     0,    34,    35,    36,    37,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
       0,     0,    54,     0,    55,     0,     0,    56,     0,    33,
      15,    16,    17,    57,    18,     0,   183,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,    53,     0,     0,    54,
       0,    55,     0,     0,    56,     0,    33,    15,    16,    17,
      57,    18,     0,   184,     0,     0,     0,     0,    34,    35,
      36,    37,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,    53,     0,     0,    54,     0,    55,     0,
       0,    56,     0,    33,    15,    16,    17,    57,    18,     0,
     185,     0,     0,     0,     0,    34,    35,    36,    37,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,    51,    52,
      53,     0,     0,    54,     0,    55,     0,     0,    56,     0,
      33,    15,    16,    17,    57,    18,     0,   214,     0,     0,
       0,     0,    34,    35,    36,    37,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,    53,     0,     0,
      54,     0,    55,     0,     0,    56,     0,    33,    15,    16,
      17,    57,    18,     0,   216,     0,     0,     0,     0,    34,
      35,    36,    37,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,     0,     0,    54,     0,    55,
       0,     0,    56,     0,    33,    15,    16,    17,    57,    18,
       0,   227,     0,     0,     0,     0,    34,    35,    36,    37,
       0,     0,     0,     0,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,    53,     0,     0,    54,     0,    55,     0,     0,    56,
       0,     0,     0,     0,     0,    57,     0,   103,   229,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,   103,
       0,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,   103,     0,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
     165,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,   166,   110,   111,   112,   113,   114,     0,   102,
       0,     0,     0,   103,   171,   104,   105,   106,   107,   108,
     109,   157,     0,     0,     0,   103,     0,   104,   105,   106,
     107,   108,   109,   103,     0,   104,   105,   106,   107,   108,
     109,   103,     0,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,     0,     0,     0,   110,   111,   112,   113,   114,
       0,   130,     0,   110,   111,   112,   113,   114,   103,   158,
     104,   105,   106,   107,   108,   109,   103,     0,   104,   105,
     106,   107,   108,   109,   103,     0,   104,   105,   106,   107,
     108,   109,   103,     0,   104,   105,   106,   107,   108,   109,
     103,     0,   104,   105,   106,   107,   108,   109,     0,     0,
     110,   111,   112,   113,   114,     0,   159,     0,   110,   111,
     112,   113,   114,     0,   160,     0,   110,   111,   112,   113,
     114,     0,   161,     0,   110,   111,   112,   113,   114,     0,
     162,     0,   110,   111,   112,   113,   114,   103,   163,   104,
     105,   106,   107,   108,   109,   103,     0,   104,   105,   106,
     107,   108,   109,   103,     0,   104,   105,   106,   107,   108,
     109,   103,     0,   104,   105,   106,   107,   108,   109,   103,
       0,   104,   105,   106,   107,   108,   109,     0,     0,   110,
     111,   112,   113,   114,     0,   164,     0,   110,   111,   112,
     113,   114,     0,   167,     0,   110,   111,   112,   113,   114,
       0,   169,     0,   110,   111,   112,   113,   114,     0,   170,
       0,   110,   111,   112,   113,   114,   103,   203,   104,   105,
     106,   107,   108,   109,   103,     0,   104,   105,   106,   107,
     108,   109,   103,     0,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,     0,   204,     0,   110,   111,   112,   113,
     114,     0,   205,     0,   110,   111,   112,   113,   114,    90,
      35,    36,    37,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      28,    57,     3,    44,     0,    46,     9,    10,    11,    12,
      13,    14,    55,    22,    23,     0,    57,    60,    74,     7,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       7,    87,    88,    89,   181,     7,    92,     9,    10,    11,
      12,    13,    14,    58,    19,    15,    16,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    60,
      35,    49,    50,    51,    52,    53,    55,    95,    96,    97,
      12,    60,   219,    21,    51,    52,    53,    49,    50,    51,
      52,    53,    24,    41,    42,   232,   142,     4,     5,     6,
      62,     8,    15,    54,    20,    54,    59,    15,    55,     3,
       4,     5,     6,    56,     8,    56,    22,    23,    15,   165,
     166,    15,    16,    17,    18,   171,    54,    54,    54,    54,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    56,    36,    37,    38,    39,    40,    56,    54,    43,
      54,    45,    54,    54,    48,    61,   202,    56,    54,    54,
      54,    54,    54,    57,    54,   211,    54,    54,    54,    54,
      54,     3,    54,    15,    15,    15,    15,    15,    61,    55,
     198,    55,   200,    55,    61,     3,     4,     5,     6,    55,
       8,    15,    53,     3,    56,    15,    56,    15,    16,    17,
      18,    56,    61,   221,    60,   223,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    15,    36,    37,
      38,    39,    40,    56,    15,    43,    62,    45,    56,    60,
      48,   215,     3,     4,     5,     6,    54,     8,    -1,    57,
      29,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    43,    -1,    45,    -1,    -1,    48,    -1,     3,
       4,     5,     6,    54,     8,    -1,    57,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    45,    -1,    -1,    48,    -1,     3,     4,     5,     6,
      54,     8,    -1,    57,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    45,    -1,
      -1,    48,    -1,     3,     4,     5,     6,    54,     8,    -1,
      57,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    -1,    48,    -1,
       3,     4,     5,     6,    54,     8,    -1,    57,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    45,    -1,    -1,    48,    -1,     3,     4,     5,
       6,    54,     8,    -1,    57,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    -1,    48,    -1,     3,     4,     5,     6,    54,     8,
      -1,    57,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    43,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,     7,    57,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    49,    50,    51,    52,    53,    -1,     3,
      -1,    -1,    -1,     7,    60,     9,    10,    11,    12,    13,
      14,     3,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      12,    13,    14,     7,    -1,     9,    10,    11,    12,    13,
      14,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    -1,    49,    50,    51,    52,    53,     7,    55,
       9,    10,    11,    12,    13,    14,     7,    -1,     9,    10,
      11,    12,    13,    14,     7,    -1,     9,    10,    11,    12,
      13,    14,     7,    -1,     9,    10,    11,    12,    13,    14,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    49,    50,
      51,    52,    53,    -1,    55,    -1,    49,    50,    51,    52,
      53,    -1,    55,    -1,    49,    50,    51,    52,    53,    -1,
      55,    -1,    49,    50,    51,    52,    53,     7,    55,     9,
      10,    11,    12,    13,    14,     7,    -1,     9,    10,    11,
      12,    13,    14,     7,    -1,     9,    10,    11,    12,    13,
      14,     7,    -1,     9,    10,    11,    12,    13,    14,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    -1,    49,    50,    51,
      52,    53,    -1,    55,    -1,    49,    50,    51,    52,    53,
      -1,    55,    -1,    49,    50,    51,    52,    53,    -1,    55,
      -1,    49,    50,    51,    52,    53,     7,    55,     9,    10,
      11,    12,    13,    14,     7,    -1,     9,    10,    11,    12,
      13,    14,     7,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    -1,    49,    50,    51,    52,
      53,    -1,    55,    -1,    49,    50,    51,    52,    53,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    66,     0,    19,    35,    67,    68,    58,    15,
      21,    65,    54,    20,    54,     4,     5,     6,     8,    69,
      90,    59,    55,    55,    60,    15,    70,    56,    56,    90,
      71,    71,    70,     3,    15,    16,    17,    18,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    36,
      37,    38,    39,    40,    43,    45,    48,    54,    57,    72,
      73,    77,    78,    83,    84,    85,    86,    87,    89,    90,
      92,    57,    22,    23,    61,    15,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      15,    92,    54,    54,    54,    56,    56,    56,     3,    54,
      15,    91,     3,     7,     9,    10,    11,    12,    13,    14,
      49,    50,    51,    52,    53,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    15,    92,    92,    92,
      55,    74,    92,    15,    76,    15,    79,    71,    71,    71,
      15,    88,    61,     3,    60,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,     3,    55,    55,
      55,    55,    55,    55,    55,    60,    60,    55,    55,    55,
      55,    60,    55,     9,    10,    11,    12,    13,    14,    81,
      55,    61,    55,    57,    57,    57,    55,    60,    92,    15,
      92,    92,     3,    92,    56,    15,    16,    80,    56,    80,
      56,    15,    61,    55,    55,    55,    75,    71,    60,    71,
      92,    44,    46,    57,    57,    15,    57,    92,    62,    81,
      62,    56,    80,    56,    71,    60,    71,    57,    15,    57,
      41,    42,    82,    80
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 168 "2007031.y"
    { printf("\nProgram Successfully Ended!\n"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 173 "2007031.y"
    { printf("\nMain Function Declared!\n"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 176 "2007031.y"
    { printf("\nHeader File Found!\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 180 "2007031.y"
    {
		printf("\nUser Defined Function Ended!\n");
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 187 "2007031.y"
    {
        if(checkDeclared((yyvsp[(2) - (2)].string))==1) {
            printf("\nDuplicate Function Name!\n");
        }
        else {
            functionAssign((yyvsp[(2) - (2)].string));
        }
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 197 "2007031.y"
    { printf("\nValid Function Parameter Declaration!\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 198 "2007031.y"
    { printf("\nValid Function Parameter Declaration!\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 202 "2007031.y"
    {
		if(checkDeclared((yyvsp[(1) - (1)].string))==1) {
      		printf("\nDuplicate Declaration!\n");
        }
   		else {
      	    varAssign((yyvsp[(1) - (1)].string));
		}
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 221 "2007031.y"
    {
		if(checkDeclared((yyvsp[(1) - (4)].string)) == 0) {
			printf("\n%s Not Declared!\n", (yyvsp[(1) - (4)].string));
		}
		else {
			// Only set value if expression didn't result in error (value not "0")
			if(strcmp((yyvsp[(3) - (4)].string), "0") != 0) {
				setValue((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));
			}
		}
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 233 "2007031.y"
    {
		if(checkDeclared((yyvsp[(3) - (5)].string))==0) {
			printf("\nCan't print, Variable is not declared\n");
        }
        else {
            int index = getValue((yyvsp[(3) - (5)].string));
            if(type[index] == 0){
                printf("\nPrinting Value of the variable %s: %d\n", (yyvsp[(3) - (5)].string), store_int[index]);
            }
            else if(type[index] == 1){
                printf("\nPrinting Value of the variable %s: %f\n", (yyvsp[(3) - (5)].string), store_float[index]);
            }
            else if(type[index] == 2){
                printf("\nPrinting Value of the variable %s: %s\n", (yyvsp[(3) - (5)].string), store_String[index]);
            }
            else if(type[index] == 4){
                printf("\nPrinting Value of the variable %s: '%c'\n", (yyvsp[(3) - (5)].string), store_char[index]);
            }
            else{
                printf("\nCan't Display Value as Variable is a Function!\n");
            }
        }
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 256 "2007031.y"
    {
		printf("\nIf Block is Successfully Handled!\n");
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 259 "2007031.y"
    {
		printf("\nElse If Block is Successfully Handled!\n");
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 262 "2007031.y"
    {
		printf("\nElse Block is Successfully Handled!\n");
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 265 "2007031.y"
    {
        printf("\nFor Loop Execution Finshed!\n");
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 268 "2007031.y"
    {
        printf("\nWhile Loop Execution Finshed!\n");
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 271 "2007031.y"
    {
        printf("\nSwitch Execution Finshed!\n");
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 277 "2007031.y"
    {
        printf("\nSwitch Case Started!\n");
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 283 "2007031.y"
    {
        switch_case = 0;
        switch_var = atoi((yyvsp[(1) - (1)].string));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 290 "2007031.y"
    {
        int x = atoi((yyvsp[(3) - (7)].string));
        if(x == switch_var && switch_case == 0 ) {
            printf("\nSwitch Case Executed is %d!\n", x);
            switch_case = 1;
        }
        else {
            printf("\nSwitch Case No: %d is Ignored!\n", x);
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 300 "2007031.y"
    {
        if(switch_case == 0) {
            switch_case = 1;
            printf("\nSwitch Default Case is Executed!\n");
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 309 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (3)].string)) == 0) {
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (3)].string));
        }
        else {
            printf("\nWhile Loop Variable Declaration is Correct!\n");	
        } 
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 319 "2007031.y"
    {
        printf("\nWhile Loop Started!\n");
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 324 "2007031.y"
    {
        printf("\nFor Loop Started!\n");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 329 "2007031.y"
    {			
        if(checkDeclared((yyvsp[(1) - (11)].string)) == 0) {
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (11)].string));
        }
        if(strcmp((yyvsp[(1) - (11)].string), (yyvsp[(5) - (11)].string)) == 0) {
            if(strcmp((yyvsp[(1) - (11)].string), (yyvsp[(9) - (11)].string)) == 0) {
                printf("\nFor Loop Variable Declaration is Correct!\n");
            }
        }
        else {
            printf("\nDifferent Variables Used: %s %s %s\n", (yyvsp[(1) - (11)].string), (yyvsp[(5) - (11)].string), (yyvsp[(9) - (11)].string));	
        } 			    
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 345 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (1)].string)) == 0) {
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (1)].string));
        }
        else {
            printf("\nVariable Correctly Assigned to Loop!\n");	
        }
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 365 "2007031.y"
    {
        printf("\nLoop is of Increasing Manner!\n");
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 368 "2007031.y"
    {
        printf("\nLoop is of Decreasing Manner!\n");
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 374 "2007031.y"
    {
        int x = atoi((yyvsp[(3) - (4)].string));
        if( x >= 1 ) {
			store_if[if_pointer] = 1;
			printf("\nIf Block is Executed!\n");
		}
        else {
            printf("\nIf Block is Not Executed!\n");
        }
        if_pointer++;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 387 "2007031.y"
    {
        int x = atoi((yyvsp[(3) - (4)].string));
        if( x >= 1 && store_if[if_pointer] == 0) {
			store_if[if_pointer] = 1;
			printf("\nElse If Block is Executed!\n");
		}
        else {
            printf("\nElse If Block is Not Executed!\n");
        }
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 399 "2007031.y"
    {
        if( store_if[if_pointer] == 0) {
			store_if[if_pointer] = 1;
			printf("\nElse Block is Executed!\n");
		}
        else {
            printf("\nElse Block is Not Executed!\n");
        }
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 410 "2007031.y"
    { 
        printf("\nValid Function Call!\n");
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 416 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (1)].string)) == 0) {
			printf("\n%s Function is Not Declared!\n", (yyvsp[(1) - (1)].string));
		}
        else {
            printf("\n%s Function is Called!\n", (yyvsp[(1) - (1)].string));
        }
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 426 "2007031.y"
    {
        if(checkDeclared((yyvsp[(3) - (3)].string)) == 0) {
            printf("\n%s Variable is Not Declared\n", (yyvsp[(3) - (3)].string));
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", (yyvsp[(3) - (3)].string)); 
                
        }
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 435 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (1)].string)) == 0) {
            printf("\n%s Variable is Not Declared\n", (yyvsp[(1) - (1)].string));
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", (yyvsp[(1) - (1)].string)); 
                
        }
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 448 "2007031.y"
    { printf("\nValid Syntax For Variable Declaration!\n"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 452 "2007031.y"
    { var_type_pointer = 0; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 453 "2007031.y"
    { var_type_pointer = 1; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 454 "2007031.y"
    { var_type_pointer = 2; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 455 "2007031.y"
    { var_type_pointer = 4; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 459 "2007031.y"
    {
        if(checkDeclared((yyvsp[(3) - (3)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign((yyvsp[(3) - (3)].string));
        }
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 467 "2007031.y"
    {
        if(checkDeclared((yyvsp[(3) - (5)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign((yyvsp[(3) - (5)].string));
            setValue((yyvsp[(3) - (5)].string), (yyvsp[(5) - (5)].string)); 
        }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 476 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (1)].string))==1)
            printf("\nDuplicate Declaration!\n");
        else
            varAssign((yyvsp[(1) - (1)].string));
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 482 "2007031.y"
    {
        if(checkDeclared((yyvsp[(1) - (3)].string))==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign((yyvsp[(1) - (3)].string));
            setValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
        }
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 494 "2007031.y"
    {
        (yyval.string) = malloc(20);
        // Check if it's a float literal
        if(strchr((yyvsp[(1) - (1)].string), '.') != NULL) {
            var_type_pointer = 1; // float
        } else {
            var_type_pointer = 0; // int
        }
        strcpy((yyval.string), (yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 504 "2007031.y"
    {
        (yyval.string) = malloc(20);
        var_type_pointer = 2; // string
        strcpy((yyval.string), (yyvsp[(1) - (1)].string)); 
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 509 "2007031.y"
    {
        (yyval.string) = malloc(20);
        var_type_pointer = 4; // char
        strcpy((yyval.string), (yyvsp[(1) - (1)].string));
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 514 "2007031.y"
    {
        (yyval.string) = malloc(20);
        if(checkDeclared((yyvsp[(1) - (1)].string)) == 0) {
            sprintf((yyval.string), "%d", 0);
            printf("\n%s Not Declared!\n", (yyvsp[(1) - (1)].string));
        }
        else {
            int index = getValue((yyvsp[(1) - (1)].string));
            if(type[index] == 0){
                var_type_pointer = 0;
                sprintf((yyval.string), "%d", store_int[index]);
            }
            else if(type[index] == 1){
                var_type_pointer = 1;
                sprintf((yyval.string), "%f", store_float[index]);
            }
            else if(type[index] == 2){
                var_type_pointer = 2;
                strcpy((yyval.string), store_String[index]);
            }
            else if(type[index] == 4){
                var_type_pointer = 4;
                sprintf((yyval.string), "'%c'", store_char[index]);
            }
            else{
                printf("\nCan't Process Value as Variable is a Function or Invalid!\n");
            }
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 543 "2007031.y"
    { 
        (yyval.string) = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue((yyvsp[(1) - (3)].string));
        int idx2 = getValue((yyvsp[(3) - (3)].string));
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else if(strchr((yyvsp[(1) - (3)].string), '"') != NULL) type1 = 2; // string literal
        else if(strchr((yyvsp[(1) - (3)].string), '\'') != NULL) type1 = 4; // char literal
        else type1 = (strchr((yyvsp[(1) - (3)].string), '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else if(strchr((yyvsp[(3) - (3)].string), '"') != NULL) type2 = 2; // string literal
        else if(strchr((yyvsp[(3) - (3)].string), '\'') != NULL) type2 = 4; // char literal
        else type2 = (strchr((yyvsp[(3) - (3)].string), '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform addition with string type\n");
            sprintf((yyval.string), "0");
        }
        else if(type1 == 4 || type2 == 4) {
            printf("\nType Error: Cannot perform addition with char type\n");
            sprintf((yyval.string), "0");
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot add different types. Please use type conversion\n");
            sprintf((yyval.string), "0");
        }
        else {
            float num1 = atof((yyvsp[(1) - (3)].string));
            float num2 = atof((yyvsp[(3) - (3)].string));
            float num3 = num1 + num2;
            sprintf((yyval.string), "%f", num3);	 
            printf("\nAdd Value: %f\n", num3);
        }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 581 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        float num3 = num1 - num2;
        sprintf((yyval.string), "%f", num3);
        printf("\nSub Value: %f\n", num3);
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 589 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue((yyvsp[(1) - (3)].string));
        int idx2 = getValue((yyvsp[(3) - (3)].string));
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr((yyvsp[(1) - (3)].string), '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr((yyvsp[(3) - (3)].string), '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform multiplication with string type\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot multiply different types. Please use type conversion\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else {
            float num1 = atof((yyvsp[(1) - (3)].string));
            float num2 = atof((yyvsp[(3) - (3)].string));
            float num3 = num1 * num2;
            sprintf((yyval.string), "%f", num3);
            printf("\nMul Value: %f\n", num3);
        }
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 621 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue((yyvsp[(1) - (3)].string));
        int idx2 = getValue((yyvsp[(3) - (3)].string));
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr((yyvsp[(1) - (3)].string), '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr((yyvsp[(3) - (3)].string), '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform division with string type\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot divide different types. Please use type conversion\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else if(num2 == 0.0) {
            printf("\nDiv by Zero is Not Possible!\n");
            sprintf((yyval.string), "0");
        }
        else {
            float num3 = num1 / num2;
            sprintf((yyval.string), "%f", num3);
            printf("\nDiv Value: %f\n", num3);
        }
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 657 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue((yyvsp[(1) - (3)].string));
        int idx2 = getValue((yyvsp[(3) - (3)].string));
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr((yyvsp[(1) - (3)].string), '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr((yyvsp[(3) - (3)].string), '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform power operation with string type\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot use power operation between different types. Please use type conversion\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else {
            float num1 = atof((yyvsp[(1) - (3)].string));
            float num2 = atof((yyvsp[(3) - (3)].string));
            float num3 = pow(num1, num2);
            sprintf((yyval.string), "%f", num3);
            printf("\nPower Value: %f\n", num3);
        }
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 689 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue((yyvsp[(1) - (3)].string));
        int idx2 = getValue((yyvsp[(3) - (3)].string));
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr((yyvsp[(1) - (3)].string), '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr((yyvsp[(3) - (3)].string), '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform modulo with string type\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else if(type1 == 1 || type2 == 1) {
            printf("\nType Error: Modulo operation not allowed with float type\n");
            sprintf((yyval.string), "0");
            // Don't return, continue execution
        }
        else {
            int num1 = atoi((yyvsp[(1) - (3)].string));
            int num2 = atoi((yyvsp[(3) - (3)].string));
            int num3 = num1 % num2;
            sprintf((yyval.string), "%d", num3);	 
            printf("\nRemainder Value: %d\n", num3);
        }
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 721 "2007031.y"
    {
        (yyval.string) = malloc(20);
        strcpy((yyval.string), (yyvsp[(2) - (3)].string)); 
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 725 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 < num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nLess Than Value: %d\n", num3);
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 733 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 > num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nGreater Than Value: %d\n", num3);
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 741 "2007031.y"
    {
        (yyval.string) = malloc(20); 
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 <= num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nLess Than or Equal To Value: %d\n", num3); 
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 749 "2007031.y"
    {
        (yyval.string) = malloc(20); 
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 >= num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nGreater Than or Equal To Value: %d\n", num3);
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 757 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 == num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nEqual To Value: %d\n", num3);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 765 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(1) - (3)].string));
        float num2 = atof((yyvsp[(3) - (3)].string));
        int num3 = num1 != num2;
        sprintf((yyval.string), "%d", num3);
        printf("\nNot Eqaul To Value: %d\n", num3);
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 773 "2007031.y"
    {
        (yyval.string) = malloc(20);
        if( checkDeclared((yyvsp[(1) - (2)].string)) == 0) {
            sprintf((yyval.string), "%d", 0);
            printf("\n%s is Not Declared!\n", (yyvsp[(1) - (2)].string));
        }
        else {
            int index = getValue((yyvsp[(1) - (2)].string));
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = tmp+1;
                store_int[index] = tmp;
                sprintf((yyval.string), "%d", tmp);
                printf("\nValue After Increment: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp+1;
                store_float[index] = tmp;
                sprintf((yyval.string), "%f", tmp);
                printf("\nValue After Increment: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Increament as Variable is a String or a Function!\n");
            }
        }
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 800 "2007031.y"
    {
        (yyval.string) = malloc(20);
  		if( checkDeclared((yyvsp[(1) - (2)].string)) == 0) {
            sprintf((yyval.string), "%d", 0);
     		printf("\n%s Not Declared!\n", (yyvsp[(1) - (2)].string));
   		}
    	else {
            int index = getValue((yyvsp[(1) - (2)].string));
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = tmp-1;
                store_int[index] = tmp;
                sprintf((yyval.string), "%d", tmp);
                printf("\nValue After Decrement: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp-1;
                store_float[index] = tmp;
                sprintf((yyval.string), "%f", tmp);
                printf("\nValue After Decrement: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Decrement as Variable is a String or a Function!\n");
            }
        }
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 827 "2007031.y"
    {
        (yyval.string) = malloc(20);
  		if( checkDeclared((yyvsp[(2) - (2)].string)) == 0) {
            sprintf((yyval.string), "%d", 0);
            printf("\n%s Not Declared!\n", (yyvsp[(2) - (2)].string));
   		}
        else {
            int index = getValue((yyvsp[(2) - (2)].string));
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = !tmp;
                store_int[index] = tmp;
                sprintf((yyval.string), "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else if(type[index] == 1){
                int tmp = store_float[index];
                tmp = !tmp;
                store_float[index] = tmp;
                sprintf((yyval.string), "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else{
                printf("\nCan't Process NOT Operation as Variable is a String or a Function!\n");
            }
        }
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 854 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float x = atof((yyvsp[(3) - (4)].string));
		printf("\nValue of Sin(%f): %lf\n", x, sin(x*3.1416/180));
        sprintf((yyval.string), "%lf", sin(x*3.1416/180));
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 860 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float x = atof((yyvsp[(3) - (4)].string));
		printf("\nValue of Cos(%f): %lf\n", x, cos(x*3.1416/180));
        sprintf((yyval.string), "%lf", cos(x*3.1416/180));
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 866 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float x = atof((yyvsp[(3) - (4)].string));
		printf("\nValue of Tan(%f): %lf\n", x, tan(x*3.1416/180));
        sprintf((yyval.string), "%lf", tan(x*3.1416/180));
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 872 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float x = atof((yyvsp[(3) - (4)].string));
		printf("\nValue of Log(%f): %lf\n", x, (log(x*1.0)/log(10.0)));
        sprintf((yyval.string), "%lf", (log(x*1.0)/log(10.0)));
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 878 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float x = atof((yyvsp[(3) - (4)].string));
		printf("\nValue of Ln(%f): %lf\n", x, (log(x)));
        sprintf((yyval.string), "%lf", (log(x)));
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 884 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int x = atoi((yyvsp[(3) - (4)].string));
        if(x%2==0) {
            sprintf((yyval.string), "%d", 0);
            printf("\n%d is An Even Number\n", x);
        } 
        else {
            sprintf((yyval.string), "%d", 1);
            printf("\n%d is An Odd Number\n", x);
        }        
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 896 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int ans = 1;
        int i;
        int x = atoi((yyvsp[(3) - (4)].string));
        for(i=1; i<=x; i++) {
            ans = ans*i;
        }
        printf("\nFactorial of %d is: %d\n", x, ans);
        sprintf((yyval.string), "%d", ans);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 907 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(3) - (6)].string));
        float num2 = atof((yyvsp[(5) - (6)].string));
        if( num1 < num2 ) {
            sprintf((yyval.string), "%f", num2);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num2);
        }
        else {
            sprintf((yyval.string), "%f", num1);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num1);
        }
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 920 "2007031.y"
    {
        (yyval.string) = malloc(20);
        float num1 = atof((yyvsp[(3) - (6)].string));
        float num2 = atof((yyvsp[(5) - (6)].string));
        if( num1 < num2 ) {
            sprintf((yyval.string), "%f", num1);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num1);
        }
        else {
            sprintf((yyval.string), "%f", num2);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num2);
        }
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 933 "2007031.y"
    {
        (yyval.string) = malloc(20);
        int x = atoi((yyvsp[(3) - (4)].string));
        int ck = 0;
        int i; 
        for(i=2; i*i<=x; i++) {
            if( x%i == 0 ) {
                ck = 1;
                break;
            }
        }
        if(ck || x==1) {
            sprintf((yyval.string), "%d", 0);
            printf("\n%d is Not A Prime Number\n", x);
        }
        else {
            sprintf((yyval.string), "%d", 1);
            printf("\n%d is A Prime Number\n", x);
        }
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 953 "2007031.y"
    {
        (yyval.string) = malloc(1000);
        char temp[1000] = "";
        
        // Handle first string
        if(getValue((yyvsp[(3) - (6)].string)) != -1) {
            int idx1 = getValue((yyvsp[(3) - (6)].string));
            if(type[idx1] == 2) {
                // Remove quotes from stored string
                char *str1 = store_String[idx1];
                str1++; // Skip first quote
                str1[strlen(str1)-1] = '\0'; // Remove last quote
                strcat(temp, str1);
            } else {
                printf("\nError: First operand must be string for concatenation\n");
                strcpy((yyval.string), "");
                return 0;
            }
        } else {
            // Remove quotes from literal string
            char *str1 = strdup((yyvsp[(3) - (6)].string));
            str1++; // Skip first quote
            str1[strlen(str1)-1] = '\0'; // Remove last quote
            strcat(temp, str1);
        }
        
        // Handle second string
        if(getValue((yyvsp[(5) - (6)].string)) != -1) {
            int idx2 = getValue((yyvsp[(5) - (6)].string));
            if(type[idx2] == 2) {
                // Remove quotes from stored string
                char *str2 = store_String[idx2];
                str2++; // Skip first quote
                str2[strlen(str2)-1] = '\0'; // Remove last quote
                strcat(temp, str2);
            } else {
                printf("\nError: Second operand must be string for concatenation\n");
                strcpy((yyval.string), "");
                return 0;
            }
        } else {
            // Remove quotes from literal string
            char *str2 = strdup((yyvsp[(5) - (6)].string));
            str2++; // Skip first quote
            str2[strlen(str2)-1] = '\0'; // Remove last quote
            strcat(temp, str2);
        }
        
        sprintf((yyval.string), "%s", temp);
        printf("\nConcatenated String: %s\n", (yyval.string));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3036 "2007031.tab.c"
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



/* Line 1675 of yacc.c  */
#line 1006 "2007031.y"


int yywrap()
{
	return 1;
}

int main()
{	
	yyin = freopen("input.txt","r",stdin);
	yyout = freopen("output.txt","w",stdout);
    yyparse();
	return 0;	
}


