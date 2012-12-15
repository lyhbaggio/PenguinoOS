/* A Bison parser, made by GNU Bison 2.6.5.977-6d58-dirty.  */

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
#define YYBISON_VERSION "2.6.5.977-6d58-dirty"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         GRAM_STYPE
#define YYLTYPE         GRAM_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         gram_parse
#define yylex           gram_lex
#define yyerror         gram_error
#define yylval          gram_lval
#define yychar          gram_char
#define yydebug         gram_debug
#define yynerrs         gram_nerrs
#define yylloc          gram_lloc

/* Copy the first part of user declarations.  */
/* Line 355 of yacc.c  */
#line 1 "src/parse-gram.y"
/* Bison Grammar Parser                             -*- C -*-

   Copyright (C) 2002-2012 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

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

#include <config.h>
#include "system.h"

#include "c-ctype.h"
#include "complain.h"
#include "conflicts.h"
#include "files.h"
#include "getargs.h"
#include "gram.h"
#include "muscle-tab.h"
#include "named-ref.h"
#include "quotearg.h"
#include "reader.h"
#include "symlist.h"
#include "symtab.h"
#include "scan-gram.h"
#include "scan-code.h"
#include "xmemdup0.h"

#define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
static YYLTYPE lloc_default (YYLTYPE const *, int);

#define YY_LOCATION_PRINT(File, Loc) \
          location_print (File, Loc)

static void version_check (location const *loc, char const *version);

/* Request detailed syntax error messages, and pass them to GRAM_ERROR.
   FIXME: depends on the undocumented availability of YYLLOC.  */
#undef  yyerror
#define yyerror(Msg) \
        gram_error (&yylloc, Msg)
static void gram_error (location const *, char const *);

static char const *char_name (char);

/* Line 355 of yacc.c  */
#line 134 "src/parse-gram.c"

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "src/parse-gram.h".  */
#ifndef YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
# define YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
/* Enabling traces.  */
#ifndef GRAM_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define GRAM_DEBUG 1
#  else
#   define GRAM_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define GRAM_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined GRAM_DEBUG */
#if GRAM_DEBUG
extern int gram_debug;
#endif
/* "%code requires" blocks.  */
/* Line 371 of yacc.c  */
#line 223 "src/parse-gram.y"

# ifndef PARAM_TYPE
#  define PARAM_TYPE
  typedef enum
  {
    param_none   = 0,
    param_lex    = 1 << 0,
    param_parse  = 1 << 1,
    param_both   = param_lex | param_parse
  } param_type;
# endif


/* Line 371 of yacc.c  */
#line 188 "src/parse-gram.c"

/* Tokens.  */
#ifndef GRAM_TOKENTYPE
# define GRAM_TOKENTYPE
  /* Put the tokens into the symbol table, so that GDB and other debuggers
     know about them.  */
  enum gram_tokentype
  {
    GRAM_EOF = 0,
    STRING = 258,
    INT = 259,
    PERCENT_TOKEN = 260,
    PERCENT_NTERM = 261,
    PERCENT_TYPE = 262,
    PERCENT_DESTRUCTOR = 263,
    PERCENT_PRINTER = 264,
    PERCENT_LEFT = 265,
    PERCENT_RIGHT = 266,
    PERCENT_NONASSOC = 267,
    PERCENT_PRECEDENCE = 268,
    PERCENT_PREC = 269,
    PERCENT_DPREC = 270,
    PERCENT_MERGE = 271,
    PERCENT_CODE = 272,
    PERCENT_DEFAULT_PREC = 273,
    PERCENT_DEFINE = 274,
    PERCENT_DEFINES = 275,
    PERCENT_ERROR_VERBOSE = 276,
    PERCENT_EXPECT = 277,
    PERCENT_EXPECT_RR = 278,
    PERCENT_FLAG = 279,
    PERCENT_FILE_PREFIX = 280,
    PERCENT_GLR_PARSER = 281,
    PERCENT_INITIAL_ACTION = 282,
    PERCENT_LANGUAGE = 283,
    PERCENT_NAME_PREFIX = 284,
    PERCENT_NO_DEFAULT_PREC = 285,
    PERCENT_NO_LINES = 286,
    PERCENT_NONDETERMINISTIC_PARSER = 287,
    PERCENT_OUTPUT = 288,
    PERCENT_REQUIRE = 289,
    PERCENT_SKELETON = 290,
    PERCENT_START = 291,
    PERCENT_TOKEN_TABLE = 292,
    PERCENT_VERBOSE = 293,
    PERCENT_YACC = 294,
    BRACED_CODE = 295,
    BRACED_PREDICATE = 296,
    BRACKETED_ID = 297,
    CHAR = 298,
    EPILOGUE = 299,
    EQUAL = 300,
    ID = 301,
    ID_COLON = 302,
    PERCENT_PERCENT = 303,
    PIPE = 304,
    PROLOGUE = 305,
    SEMICOLON = 306,
    TAG = 307,
    TAG_ANY = 308,
    TAG_NONE = 309,
    PERCENT_PARAM = 310,
    PERCENT_UNION = 311
  };
#endif
/* Tokens.  */
#define GRAM_EOF 0
#define STRING 258
#define INT 259
#define PERCENT_TOKEN 260
#define PERCENT_NTERM 261
#define PERCENT_TYPE 262
#define PERCENT_DESTRUCTOR 263
#define PERCENT_PRINTER 264
#define PERCENT_LEFT 265
#define PERCENT_RIGHT 266
#define PERCENT_NONASSOC 267
#define PERCENT_PRECEDENCE 268
#define PERCENT_PREC 269
#define PERCENT_DPREC 270
#define PERCENT_MERGE 271
#define PERCENT_CODE 272
#define PERCENT_DEFAULT_PREC 273
#define PERCENT_DEFINE 274
#define PERCENT_DEFINES 275
#define PERCENT_ERROR_VERBOSE 276
#define PERCENT_EXPECT 277
#define PERCENT_EXPECT_RR 278
#define PERCENT_FLAG 279
#define PERCENT_FILE_PREFIX 280
#define PERCENT_GLR_PARSER 281
#define PERCENT_INITIAL_ACTION 282
#define PERCENT_LANGUAGE 283
#define PERCENT_NAME_PREFIX 284
#define PERCENT_NO_DEFAULT_PREC 285
#define PERCENT_NO_LINES 286
#define PERCENT_NONDETERMINISTIC_PARSER 287
#define PERCENT_OUTPUT 288
#define PERCENT_REQUIRE 289
#define PERCENT_SKELETON 290
#define PERCENT_START 291
#define PERCENT_TOKEN_TABLE 292
#define PERCENT_VERBOSE 293
#define PERCENT_YACC 294
#define BRACED_CODE 295
#define BRACED_PREDICATE 296
#define BRACKETED_ID 297
#define CHAR 298
#define EPILOGUE 299
#define EQUAL 300
#define ID 301
#define ID_COLON 302
#define PERCENT_PERCENT 303
#define PIPE 304
#define PROLOGUE 305
#define SEMICOLON 306
#define TAG 307
#define TAG_ANY 308
#define TAG_NONE 309
#define PERCENT_PARAM 310
#define PERCENT_UNION 311

#if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
typedef union GRAM_STYPE
{
/* Line 371 of yacc.c  */
#line 109 "src/parse-gram.y"

  assoc assoc;
  char *code;
  char const *chars;
  int integer;
  named_ref *named_ref;
  symbol *symbol;
  symbol_list *list;
  uniqstr uniqstr;
  unsigned char character;

/* Line 371 of yacc.c  */
#line 247 "src/parse-gram.y"

  param_type param;

/* Line 371 of yacc.c  */
#line 423 "src/parse-gram.y"
code_props_type code_type;

/* Line 371 of yacc.c  */
#line 337 "src/parse-gram.c"
} GRAM_STYPE;
# define GRAM_STYPE_IS_TRIVIAL 1
# define GRAM_STYPE_IS_DECLARED 1
#endif

#if ! defined GRAM_LTYPE && ! defined GRAM_LTYPE_IS_DECLARED
typedef struct GRAM_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} GRAM_LTYPE;
# define GRAM_LTYPE_IS_DECLARED 1
# define GRAM_LTYPE_IS_TRIVIAL 1
#endif


int gram_parse (void);

#endif /* !YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 374 of yacc.c  */
#line 363 "src/parse-gram.c"
/* Unqualified %code blocks.  */
/* Line 375 of yacc.c  */
#line 58 "src/parse-gram.y"

  static int current_prec = 0;
  static location current_lhs_location;
  static named_ref *current_lhs_named_ref;
  static symbol *current_lhs_symbol;
  static symbol_class current_class = unknown_sym;
  static uniqstr current_type = NULL;

  /** Set the new current left-hand side symbol, possibly common
   * to several right-hand side parts of rule.
   */
  static
  void
  current_lhs(symbol *sym, location loc, named_ref *ref)
  {
    current_lhs_symbol = sym;
    current_lhs_location = loc;
    /* In order to simplify memory management, named references for lhs
       are always assigned by deep copy into the current symbol_list
       node.  This is because a single named-ref in the grammar may
       result in several uses when the user factors lhs between several
       rules using "|".  Therefore free the parser's original copy.  */
    free (current_lhs_named_ref);
    current_lhs_named_ref = ref;
  }

  #define YYTYPE_INT16 int_fast16_t
  #define YYTYPE_INT8 int_fast8_t
  #define YYTYPE_UINT16 uint_fast16_t
  #define YYTYPE_UINT8 uint_fast8_t

/* Line 375 of yacc.c  */
#line 236 "src/parse-gram.y"

  /** Add a lex-param and/or a parse-param.
   *
   * \param type  where to push this formal argument.
   * \param decl  the formal argument.  Destroyed.
   * \param loc   the location in the source.
   */
  static void add_param (param_type type, char *decl, location loc);
  static param_type current_param = param_none;


/* Line 375 of yacc.c  */
#line 412 "src/parse-gram.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#ifdef __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
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
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL \
             && defined GRAM_STYPE_IS_TRIVIAL && GRAM_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if GRAM_DEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
static const yytype_uint16 yyrline[] =
{
       0,   272,   272,   280,   282,   286,   287,   297,   301,   306,
     307,   312,   317,   318,   319,   320,   325,   334,   335,   336,
     337,   338,   339,   339,   340,   341,   365,   366,   367,   368,
     372,   373,   382,   383,   384,   388,   400,   404,   408,   415,
     426,   427,   437,   438,   442,   454,   454,   459,   459,   464,
     475,   490,   491,   492,   493,   497,   498,   503,   505,   510,
     511,   516,   518,   523,   524,   528,   529,   533,   534,   535,
     540,   545,   550,   556,   562,   573,   574,   583,   584,   590,
     591,   592,   599,   599,   607,   608,   609,   614,   616,   618,
     620,   622,   624,   626,   631,   633,   643,   644,   649,   650,
     651,   660,   680,   682,   691,   696,   697,   702,   709,   711
};
#endif

#if GRAM_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
  "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
  "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
  "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
  "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
  "prologue_declaration", "$@1", "params", "grammar_declaration",
  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
  "precedence_declaration", "precedence_declarator", "tag.opt",
  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
  "generic_symlist_item", "tag", "symbol_def", "symbol_defs.1", "grammar",
  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
  "named_ref.opt", "variable", "content.opt", "braceless", "id",
  "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -109

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.    */
static const yytype_int16 yypact[] =
{
     -74,    40,   101,   -74,   -74,   -74,   -48,   -74,   -74,   -74,
     -74,   -74,   -74,    19,   -74,     0,    52,   -74,    56,    79,
     -74,    81,   -74,    45,    83,    84,   -74,   -74,   -74,    85,
      86,    87,    31,   -74,   -74,   -74,    15,   -74,   -74,   -74,
      46,   -74,   -74,    51,   -74,   -74,    42,     4,     4,    31,
     -74,    57,   -74,   -74,   -74,    36,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,    47,   -74,    49,     1,   -74,   -74,    59,    62,
     -74,    57,    26,   -74,    31,   -74,   -74,     4,    72,     4,
      31,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    60,   -74,
     -74,   -74,   -74,   -74,    63,   -74,   -74,   -74,   -74,    26,
     -74,   -74,   -74,    31,   -74,   111,   -74,   113,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -13,    27,   -74,
     -74,    31,   137,    65,    59,   -74,    59,    27,   -74,   -74,
     -74,   -74,   -74
};

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE does not specify something else to do.  Zero means the default
     is an error.    */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    47,    45,     0,    40,    41,    51,
      52,    53,    54,     0,    36,     0,     9,    11,     0,     0,
       7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
       0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
      42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
     101,     0,    38,    97,    96,    98,    10,    12,    13,    14,
      16,    17,    18,    21,    24,    25,   107,   103,   102,   105,
      34,   106,     0,   104,     0,     0,    77,    79,    94,     0,
      43,     0,     0,    56,     0,    70,    75,    48,    71,    46,
      49,    61,    39,   100,    99,     8,    81,    80,     0,    78,
       2,    95,    82,    31,    23,    44,    67,    68,    69,    35,
      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
     109,    87,    30,    64,    58,    60,    74,    83,    84,    87,
      86,     0,     0,     0,    94,    90,    94,    85,    91,    92,
      93,    89,    88
};

  /* YYPGOTO[NTERM-NUM].    */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,   140,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    30,   -74,   -74,    35,
     -74,   -26,    97,   -74,    71,   -74,   -74,   -74,    18,   -70,
     -74,   -74,   -46,     6,   -74,   -32,   -73,   -74
};

  /* YYDEFGOTO[NTERM-NUM].    */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,    79,   104,    74,    43,    81,    44,
      48,    47,    45,    46,    84,   113,   114,    90,   109,   110,
     111,    86,    87,    75,    76,    77,   121,   127,   128,   102,
      55,    95,    52,    69,    78,   112,    71,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF, syntax error.    */
static const yytype_int16 yytable[] =
{
      70,  -108,    72,    53,    49,    92,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   118,    72,    91,    13,    14,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    66,
      66,    26,    13,    14,    66,   105,   129,    32,   130,    93,
       3,   131,   132,   133,   126,    26,    54,    67,    73,    98,
      68,    32,   115,    88,    88,    56,    85,    40,   119,    50,
      57,   116,    73,   116,   141,    51,   142,   134,   135,    67,
      67,    40,    68,    68,    67,    66,   117,    68,   106,   107,
     108,   115,    94,    58,    59,    60,    61,    62,    63,    64,
      65,    82,    80,    88,    83,    88,   136,    50,    96,   138,
      97,   101,   103,   122,   120,   136,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   125,    66,   140,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,   139,    42,   124,   123,    89,    99,   137,     0,    36,
       0,    37,    38,     0,     0,     0,    39,    40
};

static const yytype_int16 yycheck[] =
{
      32,     0,     1,     3,    52,    51,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    88,     1,    49,    17,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       3,    30,    17,    18,     3,    81,    49,    36,    51,     3,
       0,    14,    15,    16,   117,    30,    46,    43,    47,    48,
      46,    36,    84,    47,    48,     3,    52,    56,    90,    40,
       4,    87,    47,    89,   134,    46,   136,    40,    41,    43,
      43,    56,    46,    46,    43,     3,     4,    46,    52,    53,
      54,   113,    46,     4,     3,    40,     3,     3,     3,     3,
       3,    40,    46,    87,    52,    89,   128,    40,    51,   131,
      51,    42,    40,    40,    44,   137,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     4,     3,    52,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     4,     2,   113,   109,    48,    75,   129,    -1,    48,
      -1,    50,    51,    -1,    -1,    -1,    55,    56
};

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.    */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
      56,    60,    63,    64,    66,    69,    70,    68,    67,    52,
      40,    46,    89,     3,    46,    87,     3,     4,     4,     3,
      40,     3,     3,     3,     3,     3,     3,    43,    46,    90,
      92,    93,     1,    47,    63,    80,    81,    82,    91,    61,
      46,    65,    40,    52,    71,    52,    78,    79,    90,    79,
      74,    92,    89,     3,    46,    88,    51,    51,    48,    81,
      94,    42,    86,    40,    62,    89,    52,    53,    54,    75,
      76,    77,    92,    72,    73,    92,    78,     4,    93,    92,
      44,    83,    40,    76,    73,     4,    93,    84,    85,    49,
      51,    14,    15,    16,    40,    41,    92,    85,    92,     4,
      52,    86,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    60,    60,    60,    60,    60,    60,    60,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    83,    82,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    89,    90,    90,    91,    92,    92,    93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
       2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
       1,     2,     0,     3,     2,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
       2,     3,     3,     3,     0,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
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
      YY_LAC_DISCARD ("YYBACKUP");                              \
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)                                   \
  do {                                                                   \
    fprintf (File, "%d.%d", (Loc).first_line, (Loc).first_column);       \
    if ((Loc).first_line < (Loc).last_line)                              \
      fprintf (File, "-%d.%d", (Loc).last_line,  (Loc).last_column - 1); \
    else if ((Loc).first_column < (Loc).last_column - 1)                 \
      fprintf (File, "-%d", (Loc).last_column - 1);                      \
  } while (0)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if GRAM_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

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


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE(yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
            case 3: // "string"
/* Line 711 of yacc.c  */
#line 196 "src/parse-gram.y"
        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
/* Line 711 of yacc.c  */
#line 1011 "src/parse-gram.c"
        break;

            case 4: // "integer"
/* Line 711 of yacc.c  */
#line 209 "src/parse-gram.y"
        { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
/* Line 711 of yacc.c  */
#line 1019 "src/parse-gram.c"
        break;

            case 24: // "%<flag>"
/* Line 711 of yacc.c  */
#line 205 "src/parse-gram.y"
        { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
/* Line 711 of yacc.c  */
#line 1027 "src/parse-gram.c"
        break;

            case 40: // "{...}"
/* Line 711 of yacc.c  */
#line 198 "src/parse-gram.y"
        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
/* Line 711 of yacc.c  */
#line 1035 "src/parse-gram.c"
        break;

            case 42: // "[identifier]"
/* Line 711 of yacc.c  */
#line 203 "src/parse-gram.y"
        { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
/* Line 711 of yacc.c  */
#line 1043 "src/parse-gram.c"
        break;

            case 43: // "char"
/* Line 711 of yacc.c  */
#line 190 "src/parse-gram.y"
        { fputs (char_name (((*yyvaluep).character)), yyo); }
/* Line 711 of yacc.c  */
#line 1051 "src/parse-gram.c"
        break;

            case 44: // "epilogue"
/* Line 711 of yacc.c  */
#line 198 "src/parse-gram.y"
        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
/* Line 711 of yacc.c  */
#line 1059 "src/parse-gram.c"
        break;

            case 46: // "identifier"
/* Line 711 of yacc.c  */
#line 202 "src/parse-gram.y"
        { fputs (((*yyvaluep).uniqstr), yyo); }
/* Line 711 of yacc.c  */
#line 1067 "src/parse-gram.c"
        break;

            case 47: // "identifier:"
/* Line 711 of yacc.c  */
#line 204 "src/parse-gram.y"
        { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
/* Line 711 of yacc.c  */
#line 1075 "src/parse-gram.c"
        break;

            case 50: // "%{...%}"
/* Line 711 of yacc.c  */
#line 198 "src/parse-gram.y"
        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
/* Line 711 of yacc.c  */
#line 1083 "src/parse-gram.c"
        break;

            case 52: // "<tag>"
/* Line 711 of yacc.c  */
#line 206 "src/parse-gram.y"
        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
/* Line 711 of yacc.c  */
#line 1091 "src/parse-gram.c"
        break;

            case 55: // "%param"
/* Line 711 of yacc.c  */
#line 252 "src/parse-gram.y"
        {
  switch (((*yyvaluep).param))
    {
#define CASE(In, Out)                                           \
      case param_ ## In: fputs ("%" #Out, stderr); break
      CASE(lex,   lex-param);
      CASE(parse, parse-param);
      CASE(both,  param);
#undef CASE
      case param_none: aver (false); break;
    }
}
/* Line 711 of yacc.c  */
#line 1110 "src/parse-gram.c"
        break;

            case 64: // code_props_type
/* Line 711 of yacc.c  */
#line 424 "src/parse-gram.y"
        { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
/* Line 711 of yacc.c  */
#line 1118 "src/parse-gram.c"
        break;

            case 73: // symbol.prec
/* Line 711 of yacc.c  */
#line 212 "src/parse-gram.y"
        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
/* Line 711 of yacc.c  */
#line 1126 "src/parse-gram.c"
        break;

            case 77: // tag
/* Line 711 of yacc.c  */
#line 206 "src/parse-gram.y"
        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
/* Line 711 of yacc.c  */
#line 1134 "src/parse-gram.c"
        break;

            case 87: // variable
/* Line 711 of yacc.c  */
#line 202 "src/parse-gram.y"
        { fputs (((*yyvaluep).uniqstr), yyo); }
/* Line 711 of yacc.c  */
#line 1142 "src/parse-gram.c"
        break;

            case 88: // content.opt
/* Line 711 of yacc.c  */
#line 198 "src/parse-gram.y"
        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
/* Line 711 of yacc.c  */
#line 1150 "src/parse-gram.c"
        break;

            case 89: // braceless
/* Line 711 of yacc.c  */
#line 198 "src/parse-gram.y"
        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
/* Line 711 of yacc.c  */
#line 1158 "src/parse-gram.c"
        break;

            case 90: // id
/* Line 711 of yacc.c  */
#line 212 "src/parse-gram.y"
        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
/* Line 711 of yacc.c  */
#line 1166 "src/parse-gram.c"
        break;

            case 91: // id_colon
/* Line 711 of yacc.c  */
#line 213 "src/parse-gram.y"
        { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
/* Line 711 of yacc.c  */
#line 1174 "src/parse-gram.c"
        break;

            case 92: // symbol
/* Line 711 of yacc.c  */
#line 212 "src/parse-gram.y"
        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
/* Line 711 of yacc.c  */
#line 1182 "src/parse-gram.c"
        break;

            case 93: // string_as_id
/* Line 711 of yacc.c  */
#line 212 "src/parse-gram.y"
        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
/* Line 711 of yacc.c  */
#line 1190 "src/parse-gram.c"
        break;

      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

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
#else /* !GRAM_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !GRAM_DEBUG */


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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if GRAM_DEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if GRAM_DEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if GRAM_DEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
# if GRAM_DEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE(yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
/* Line 1452 of yacc.c  */
#line 101 "src/parse-gram.y"
{
  /* Bison's grammar can initial empty locations, hence a default
     location is needed. */
  boundary_set (&yylloc.start, current_file, 1, 1);
  boundary_set (&yylloc.end, current_file, 1, 1);
}
/* Line 1452 of yacc.c  */
#line 1912 "src/parse-gram.c"
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 6:
/* Line 1670 of yacc.c  */
#line 288 "src/parse-gram.y"
    {
      code_props plain_code;
      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
      code_props_translate_code (&plain_code);
      gram_scanner_last_string_free ();
      muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                        plain_code.code, (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2118 "src/parse-gram.c"
    break;

  case 7:
/* Line 1670 of yacc.c  */
#line 298 "src/parse-gram.y"
    {
      muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
    }
/* Line 1670 of yacc.c  */
#line 2128 "src/parse-gram.c"
    break;

  case 8:
/* Line 1670 of yacc.c  */
#line 302 "src/parse-gram.y"
    {
      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
    }
/* Line 1670 of yacc.c  */
#line 2139 "src/parse-gram.c"
    break;

  case 9:
/* Line 1670 of yacc.c  */
#line 306 "src/parse-gram.y"
    { defines_flag = true; }
/* Line 1670 of yacc.c  */
#line 2147 "src/parse-gram.c"
    break;

  case 10:
/* Line 1670 of yacc.c  */
#line 308 "src/parse-gram.y"
    {
      defines_flag = true;
      spec_defines_file = xstrdup ((yyvsp[0].chars));
    }
/* Line 1670 of yacc.c  */
#line 2158 "src/parse-gram.c"
    break;

  case 11:
/* Line 1670 of yacc.c  */
#line 313 "src/parse-gram.y"
    {
      muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
    }
/* Line 1670 of yacc.c  */
#line 2169 "src/parse-gram.c"
    break;

  case 12:
/* Line 1670 of yacc.c  */
#line 317 "src/parse-gram.y"
    { expected_sr_conflicts = (yyvsp[0].integer); }
/* Line 1670 of yacc.c  */
#line 2177 "src/parse-gram.c"
    break;

  case 13:
/* Line 1670 of yacc.c  */
#line 318 "src/parse-gram.y"
    { expected_rr_conflicts = (yyvsp[0].integer); }
/* Line 1670 of yacc.c  */
#line 2185 "src/parse-gram.c"
    break;

  case 14:
/* Line 1670 of yacc.c  */
#line 319 "src/parse-gram.y"
    { spec_file_prefix = (yyvsp[0].chars); }
/* Line 1670 of yacc.c  */
#line 2193 "src/parse-gram.c"
    break;

  case 15:
/* Line 1670 of yacc.c  */
#line 321 "src/parse-gram.y"
    {
      nondeterministic_parser = true;
      glr_parser = true;
    }
/* Line 1670 of yacc.c  */
#line 2204 "src/parse-gram.c"
    break;

  case 16:
/* Line 1670 of yacc.c  */
#line 326 "src/parse-gram.y"
    {
      code_props action;
      code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
      code_props_translate_code (&action);
      gram_scanner_last_string_free ();
      muscle_code_grow ("initial_action", action.code, (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2219 "src/parse-gram.c"
    break;

  case 17:
/* Line 1670 of yacc.c  */
#line 334 "src/parse-gram.y"
    { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
/* Line 1670 of yacc.c  */
#line 2227 "src/parse-gram.c"
    break;

  case 18:
/* Line 1670 of yacc.c  */
#line 335 "src/parse-gram.y"
    { spec_name_prefix = (yyvsp[0].chars); }
/* Line 1670 of yacc.c  */
#line 2235 "src/parse-gram.c"
    break;

  case 19:
/* Line 1670 of yacc.c  */
#line 336 "src/parse-gram.y"
    { no_lines_flag = true; }
/* Line 1670 of yacc.c  */
#line 2243 "src/parse-gram.c"
    break;

  case 20:
/* Line 1670 of yacc.c  */
#line 337 "src/parse-gram.y"
    { nondeterministic_parser = true; }
/* Line 1670 of yacc.c  */
#line 2251 "src/parse-gram.c"
    break;

  case 21:
/* Line 1670 of yacc.c  */
#line 338 "src/parse-gram.y"
    { spec_outfile = (yyvsp[0].chars); }
/* Line 1670 of yacc.c  */
#line 2259 "src/parse-gram.c"
    break;

  case 22:
/* Line 1670 of yacc.c  */
#line 339 "src/parse-gram.y"
    { current_param = (yyvsp[0].param); }
/* Line 1670 of yacc.c  */
#line 2267 "src/parse-gram.c"
    break;

  case 23:
/* Line 1670 of yacc.c  */
#line 339 "src/parse-gram.y"
    { current_param = param_none; }
/* Line 1670 of yacc.c  */
#line 2275 "src/parse-gram.c"
    break;

  case 24:
/* Line 1670 of yacc.c  */
#line 340 "src/parse-gram.y"
    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
/* Line 1670 of yacc.c  */
#line 2283 "src/parse-gram.c"
    break;

  case 25:
/* Line 1670 of yacc.c  */
#line 342 "src/parse-gram.y"
    {
      char const *skeleton_user = (yyvsp[0].chars);
      if (strchr (skeleton_user, '/'))
        {
          size_t dir_length = strlen (current_file);
          char *skeleton_build;
          while (dir_length && current_file[dir_length - 1] != '/')
            --dir_length;
          while (dir_length && current_file[dir_length - 1] == '/')
            --dir_length;
          skeleton_build =
            xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
          if (dir_length > 0)
            {
              memcpy (skeleton_build, current_file, dir_length);
              skeleton_build[dir_length++] = '/';
            }
          strcpy (skeleton_build + dir_length, skeleton_user);
          skeleton_user = uniqstr_new (skeleton_build);
          free (skeleton_build);
        }
      skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
    }
/* Line 1670 of yacc.c  */
#line 2313 "src/parse-gram.c"
    break;

  case 26:
/* Line 1670 of yacc.c  */
#line 365 "src/parse-gram.y"
    { token_table_flag = true; }
/* Line 1670 of yacc.c  */
#line 2321 "src/parse-gram.c"
    break;

  case 27:
/* Line 1670 of yacc.c  */
#line 366 "src/parse-gram.y"
    { report_flag |= report_states; }
/* Line 1670 of yacc.c  */
#line 2329 "src/parse-gram.c"
    break;

  case 28:
/* Line 1670 of yacc.c  */
#line 367 "src/parse-gram.y"
    { yacc_flag = true; }
/* Line 1670 of yacc.c  */
#line 2337 "src/parse-gram.c"
    break;

  case 30:
/* Line 1670 of yacc.c  */
#line 372 "src/parse-gram.y"
    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2345 "src/parse-gram.c"
    break;

  case 31:
/* Line 1670 of yacc.c  */
#line 373 "src/parse-gram.y"
    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2353 "src/parse-gram.c"
    break;

  case 34:
/* Line 1670 of yacc.c  */
#line 385 "src/parse-gram.y"
    {
      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
    }
/* Line 1670 of yacc.c  */
#line 2363 "src/parse-gram.c"
    break;

  case 35:
/* Line 1670 of yacc.c  */
#line 389 "src/parse-gram.y"
    {
      code_props code;
      code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
      code_props_translate_code (&code);
      {
        symbol_list *list;
        for (list = (yyvsp[0].list); list; list = list->next)
          symbol_list_code_props_set (list, (yyvsp[-2].code_type), &code);
        symbol_list_free ((yyvsp[0].list));
      }
    }
/* Line 1670 of yacc.c  */
#line 2381 "src/parse-gram.c"
    break;

  case 36:
/* Line 1670 of yacc.c  */
#line 401 "src/parse-gram.y"
    {
      default_prec = true;
    }
/* Line 1670 of yacc.c  */
#line 2391 "src/parse-gram.c"
    break;

  case 37:
/* Line 1670 of yacc.c  */
#line 405 "src/parse-gram.y"
    {
      default_prec = false;
    }
/* Line 1670 of yacc.c  */
#line 2401 "src/parse-gram.c"
    break;

  case 38:
/* Line 1670 of yacc.c  */
#line 409 "src/parse-gram.y"
    {
      /* Do not invoke muscle_percent_code_grow here since it invokes
         muscle_user_name_list_grow.  */
      muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2414 "src/parse-gram.c"
    break;

  case 39:
/* Line 1670 of yacc.c  */
#line 416 "src/parse-gram.y"
    {
      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2425 "src/parse-gram.c"
    break;

  case 40:
/* Line 1670 of yacc.c  */
#line 426 "src/parse-gram.y"
    { (yyval.code_type) = destructor; }
/* Line 1670 of yacc.c  */
#line 2433 "src/parse-gram.c"
    break;

  case 41:
/* Line 1670 of yacc.c  */
#line 427 "src/parse-gram.y"
    { (yyval.code_type) = printer; }
/* Line 1670 of yacc.c  */
#line 2441 "src/parse-gram.c"
    break;

  case 42:
/* Line 1670 of yacc.c  */
#line 437 "src/parse-gram.y"
    {}
/* Line 1670 of yacc.c  */
#line 2449 "src/parse-gram.c"
    break;

  case 43:
/* Line 1670 of yacc.c  */
#line 438 "src/parse-gram.y"
    { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2457 "src/parse-gram.c"
    break;

  case 44:
/* Line 1670 of yacc.c  */
#line 443 "src/parse-gram.y"
    {
      union_seen = true;
      muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2469 "src/parse-gram.c"
    break;

  case 45:
/* Line 1670 of yacc.c  */
#line 454 "src/parse-gram.y"
    { current_class = nterm_sym; }
/* Line 1670 of yacc.c  */
#line 2477 "src/parse-gram.c"
    break;

  case 46:
/* Line 1670 of yacc.c  */
#line 455 "src/parse-gram.y"
    {
      current_class = unknown_sym;
      current_type = NULL;
    }
/* Line 1670 of yacc.c  */
#line 2488 "src/parse-gram.c"
    break;

  case 47:
/* Line 1670 of yacc.c  */
#line 459 "src/parse-gram.y"
    { current_class = token_sym; }
/* Line 1670 of yacc.c  */
#line 2496 "src/parse-gram.c"
    break;

  case 48:
/* Line 1670 of yacc.c  */
#line 460 "src/parse-gram.y"
    {
      current_class = unknown_sym;
      current_type = NULL;
    }
/* Line 1670 of yacc.c  */
#line 2507 "src/parse-gram.c"
    break;

  case 49:
/* Line 1670 of yacc.c  */
#line 465 "src/parse-gram.y"
    {
      symbol_list *list;
      tag_seen = true;
      for (list = (yyvsp[0].list); list; list = list->next)
        symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
      symbol_list_free ((yyvsp[0].list));
    }
/* Line 1670 of yacc.c  */
#line 2521 "src/parse-gram.c"
    break;

  case 50:
/* Line 1670 of yacc.c  */
#line 476 "src/parse-gram.y"
    {
      symbol_list *list;
      ++current_prec;
      for (list = (yyvsp[0].list); list; list = list->next)
        {
          symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
          symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
        }
      symbol_list_free ((yyvsp[0].list));
      current_type = NULL;
    }
/* Line 1670 of yacc.c  */
#line 2539 "src/parse-gram.c"
    break;

  case 51:
/* Line 1670 of yacc.c  */
#line 490 "src/parse-gram.y"
    { (yyval.assoc) = left_assoc; }
/* Line 1670 of yacc.c  */
#line 2547 "src/parse-gram.c"
    break;

  case 52:
/* Line 1670 of yacc.c  */
#line 491 "src/parse-gram.y"
    { (yyval.assoc) = right_assoc; }
/* Line 1670 of yacc.c  */
#line 2555 "src/parse-gram.c"
    break;

  case 53:
/* Line 1670 of yacc.c  */
#line 492 "src/parse-gram.y"
    { (yyval.assoc) = non_assoc; }
/* Line 1670 of yacc.c  */
#line 2563 "src/parse-gram.c"
    break;

  case 54:
/* Line 1670 of yacc.c  */
#line 493 "src/parse-gram.y"
    { (yyval.assoc) = precedence_assoc; }
/* Line 1670 of yacc.c  */
#line 2571 "src/parse-gram.c"
    break;

  case 55:
/* Line 1670 of yacc.c  */
#line 497 "src/parse-gram.y"
    { current_type = NULL; }
/* Line 1670 of yacc.c  */
#line 2579 "src/parse-gram.c"
    break;

  case 56:
/* Line 1670 of yacc.c  */
#line 498 "src/parse-gram.y"
    { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
/* Line 1670 of yacc.c  */
#line 2587 "src/parse-gram.c"
    break;

  case 57:
/* Line 1670 of yacc.c  */
#line 504 "src/parse-gram.y"
    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2595 "src/parse-gram.c"
    break;

  case 58:
/* Line 1670 of yacc.c  */
#line 506 "src/parse-gram.y"
    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
/* Line 1670 of yacc.c  */
#line 2603 "src/parse-gram.c"
    break;

  case 59:
/* Line 1670 of yacc.c  */
#line 510 "src/parse-gram.y"
    { (yyval.symbol) = (yyvsp[0].symbol); }
/* Line 1670 of yacc.c  */
#line 2611 "src/parse-gram.c"
    break;

  case 60:
/* Line 1670 of yacc.c  */
#line 511 "src/parse-gram.y"
    { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2619 "src/parse-gram.c"
    break;

  case 61:
/* Line 1670 of yacc.c  */
#line 517 "src/parse-gram.y"
    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2627 "src/parse-gram.c"
    break;

  case 62:
/* Line 1670 of yacc.c  */
#line 519 "src/parse-gram.y"
    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
/* Line 1670 of yacc.c  */
#line 2635 "src/parse-gram.c"
    break;

  case 63:
/* Line 1670 of yacc.c  */
#line 523 "src/parse-gram.y"
    { (yyval.list) = (yyvsp[0].list); }
/* Line 1670 of yacc.c  */
#line 2643 "src/parse-gram.c"
    break;

  case 64:
/* Line 1670 of yacc.c  */
#line 524 "src/parse-gram.y"
    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
/* Line 1670 of yacc.c  */
#line 2651 "src/parse-gram.c"
    break;

  case 65:
/* Line 1670 of yacc.c  */
#line 528 "src/parse-gram.y"
    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2659 "src/parse-gram.c"
    break;

  case 66:
/* Line 1670 of yacc.c  */
#line 529 "src/parse-gram.y"
    { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2667 "src/parse-gram.c"
    break;

  case 68:
/* Line 1670 of yacc.c  */
#line 534 "src/parse-gram.y"
    { (yyval.uniqstr) = uniqstr_new ("*"); }
/* Line 1670 of yacc.c  */
#line 2675 "src/parse-gram.c"
    break;

  case 69:
/* Line 1670 of yacc.c  */
#line 535 "src/parse-gram.y"
    { (yyval.uniqstr) = uniqstr_new (""); }
/* Line 1670 of yacc.c  */
#line 2683 "src/parse-gram.c"
    break;

  case 70:
/* Line 1670 of yacc.c  */
#line 541 "src/parse-gram.y"
    {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
/* Line 1670 of yacc.c  */
#line 2694 "src/parse-gram.c"
    break;

  case 71:
/* Line 1670 of yacc.c  */
#line 546 "src/parse-gram.y"
    {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
/* Line 1670 of yacc.c  */
#line 2705 "src/parse-gram.c"
    break;

  case 72:
/* Line 1670 of yacc.c  */
#line 551 "src/parse-gram.y"
    {
      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
    }
/* Line 1670 of yacc.c  */
#line 2717 "src/parse-gram.c"
    break;

  case 73:
/* Line 1670 of yacc.c  */
#line 557 "src/parse-gram.y"
    {
      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
      symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
    }
/* Line 1670 of yacc.c  */
#line 2729 "src/parse-gram.c"
    break;

  case 74:
/* Line 1670 of yacc.c  */
#line 563 "src/parse-gram.y"
    {
      symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
      symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
      symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
      symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
    }
/* Line 1670 of yacc.c  */
#line 2742 "src/parse-gram.c"
    break;

  case 81:
/* Line 1670 of yacc.c  */
#line 593 "src/parse-gram.y"
    {
      yyerrok;
    }
/* Line 1670 of yacc.c  */
#line 2752 "src/parse-gram.c"
    break;

  case 82:
/* Line 1670 of yacc.c  */
#line 599 "src/parse-gram.y"
    { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
/* Line 1670 of yacc.c  */
#line 2760 "src/parse-gram.c"
    break;

  case 83:
/* Line 1670 of yacc.c  */
#line 600 "src/parse-gram.y"
    {
    /* Free the current lhs. */
    current_lhs (0, (yylsp[-3]), 0);
  }
/* Line 1670 of yacc.c  */
#line 2771 "src/parse-gram.c"
    break;

  case 84:
/* Line 1670 of yacc.c  */
#line 607 "src/parse-gram.y"
    { grammar_current_rule_end ((yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2779 "src/parse-gram.c"
    break;

  case 85:
/* Line 1670 of yacc.c  */
#line 608 "src/parse-gram.y"
    { grammar_current_rule_end ((yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2787 "src/parse-gram.c"
    break;

  case 87:
/* Line 1670 of yacc.c  */
#line 614 "src/parse-gram.y"
    { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                  current_lhs_named_ref); }
/* Line 1670 of yacc.c  */
#line 2796 "src/parse-gram.c"
    break;

  case 88:
/* Line 1670 of yacc.c  */
#line 617 "src/parse-gram.y"
    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
/* Line 1670 of yacc.c  */
#line 2804 "src/parse-gram.c"
    break;

  case 89:
/* Line 1670 of yacc.c  */
#line 619 "src/parse-gram.y"
    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
/* Line 1670 of yacc.c  */
#line 2812 "src/parse-gram.c"
    break;

  case 90:
/* Line 1670 of yacc.c  */
#line 621 "src/parse-gram.y"
    { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
/* Line 1670 of yacc.c  */
#line 2820 "src/parse-gram.c"
    break;

  case 91:
/* Line 1670 of yacc.c  */
#line 623 "src/parse-gram.y"
    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2828 "src/parse-gram.c"
    break;

  case 92:
/* Line 1670 of yacc.c  */
#line 625 "src/parse-gram.y"
    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2836 "src/parse-gram.c"
    break;

  case 93:
/* Line 1670 of yacc.c  */
#line 627 "src/parse-gram.y"
    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2844 "src/parse-gram.c"
    break;

  case 94:
/* Line 1670 of yacc.c  */
#line 631 "src/parse-gram.y"
    { (yyval.named_ref) = 0; }
/* Line 1670 of yacc.c  */
#line 2852 "src/parse-gram.c"
    break;

  case 95:
/* Line 1670 of yacc.c  */
#line 633 "src/parse-gram.y"
    { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2860 "src/parse-gram.c"
    break;

  case 97:
/* Line 1670 of yacc.c  */
#line 644 "src/parse-gram.y"
    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
/* Line 1670 of yacc.c  */
#line 2868 "src/parse-gram.c"
    break;

  case 98:
/* Line 1670 of yacc.c  */
#line 649 "src/parse-gram.y"
    { (yyval.chars) = ""; }
/* Line 1670 of yacc.c  */
#line 2876 "src/parse-gram.c"
    break;

  case 99:
/* Line 1670 of yacc.c  */
#line 650 "src/parse-gram.y"
    { (yyval.chars) = (yyvsp[0].uniqstr); }
/* Line 1670 of yacc.c  */
#line 2884 "src/parse-gram.c"
    break;

  case 101:
/* Line 1670 of yacc.c  */
#line 661 "src/parse-gram.y"
    {
      code_props plain_code;
      (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
      code_props_plain_init (&plain_code, (yyvsp[0].code)+1, (yylsp[0]));
      code_props_translate_code (&plain_code);
      gram_scanner_last_string_free ();
      (yyval.chars) = plain_code.code;
    }
/* Line 1670 of yacc.c  */
#line 2899 "src/parse-gram.c"
    break;

  case 102:
/* Line 1670 of yacc.c  */
#line 681 "src/parse-gram.y"
    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2907 "src/parse-gram.c"
    break;

  case 103:
/* Line 1670 of yacc.c  */
#line 683 "src/parse-gram.y"
    {
      (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
      symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
    }
/* Line 1670 of yacc.c  */
#line 2919 "src/parse-gram.c"
    break;

  case 104:
/* Line 1670 of yacc.c  */
#line 691 "src/parse-gram.y"
    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
/* Line 1670 of yacc.c  */
#line 2927 "src/parse-gram.c"
    break;

  case 107:
/* Line 1670 of yacc.c  */
#line 703 "src/parse-gram.y"
    {
      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
    }
/* Line 1670 of yacc.c  */
#line 2938 "src/parse-gram.c"
    break;

  case 109:
/* Line 1670 of yacc.c  */
#line 712 "src/parse-gram.y"
    {
      code_props plain_code;
      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
      code_props_translate_code (&plain_code);
      gram_scanner_last_string_free ();
      muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
      code_scanner_last_string_free ();
    }
/* Line 1670 of yacc.c  */
#line 2953 "src/parse-gram.c"
    break;


/* Line 1670 of yacc.c  */
#line 2958 "src/parse-gram.c"
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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

#if 1
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
/* Line 1930 of yacc.c  */
#line 722 "src/parse-gram.y"


/* Return the location of the left-hand side of a rule whose
   right-hand side is RHS[1] ... RHS[N].  Ignore empty nonterminals in
   the right-hand side, and return an empty location equal to the end
   boundary of RHS[0] if the right-hand side is empty.  */

static YYLTYPE
lloc_default (YYLTYPE const *rhs, int n)
{
  int i;
  YYLTYPE loc;

  /* SGI MIPSpro 7.4.1m miscompiles "loc.start = loc.end = rhs[n].end;".
     The bug is fixed in 7.4.2m, but play it safe for now.  */
  loc.start = rhs[n].end;
  loc.end = rhs[n].end;

  /* Ignore empty nonterminals the start of the right-hand side.
     Do not bother to ignore them at the end of the right-hand side,
     since empty nonterminals have the same end as their predecessors.  */
  for (i = 1; i <= n; i++)
    if (! equal_boundaries (rhs[i].start, rhs[i].end))
      {
        loc.start = rhs[i].start;
        break;
      }

  return loc;
}


static void
add_param (param_type type, char *decl, location loc)
{
  static char const alphanum[26 + 26 + 1 + 10] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "_"
    "0123456789";

  char const *name_start = NULL;
  {
    char *p;
    /* Stop on last actual character.  */
    for (p = decl; p[1]; p++)
      if ((p == decl
           || ! memchr (alphanum, p[-1], sizeof alphanum))
          && memchr (alphanum, p[0], sizeof alphanum - 10))
        name_start = p;

    /* Strip the surrounding '{' and '}', and any blanks just inside
       the braces.  */
    --p;
  while (c_isspace ((unsigned char) *p))
      --p;
    p[1] = '\0';
    ++decl;
  while (c_isspace ((unsigned char) *decl))
      ++decl;
  }

  if (! name_start)
    complain (&loc, complaint, _("missing identifier in parameter declaration"));
  else
    {
      char *name = xmemdup0 (name_start, strspn (name_start, alphanum));
      if (type & param_lex)
        muscle_pair_list_grow ("lex_param", decl, name);
      if (type & param_parse)
        muscle_pair_list_grow ("parse_param", decl, name);
      free (name);
    }

  gram_scanner_last_string_free ();
}


static void
version_check (location const *loc, char const *version)
{
  if (strverscmp (version, PACKAGE_VERSION) > 0)
    {
      complain (loc, complaint, "require bison %s, but have %s",
                version, PACKAGE_VERSION);
      exit (EX_MISMATCH);
    }
}

static void
gram_error (location const *loc, char const *msg)
{
  complain (loc, complaint, "%s", msg);
}

char const *
token_name (int type)
{
  return yytname[YYTRANSLATE (type)];
}

static char const *
char_name (char c)
{
  if (c == '\'')
    return "'\\''";
  else
    {
      char buf[4];
      buf[0] = '\''; buf[1] = c; buf[2] = '\''; buf[3] = '\0';
      return quotearg_style (escape_quoting_style, buf);
    }
}
