
/*  A Bison parser, made from parser.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ENDL	258
#define	END	259
#define	PROGRAM	260
#define	CONST	261
#define	S	262
#define	INC	263
#define	DEC	264
#define	INT	265
#define	FLOAT	266
#define	BOOL	267
#define	AND	268
#define	OR	269
#define	NOT	270
#define	WHILE	271
#define	IF	272
#define	THEN	273
#define	ELSE	274
#define	ENDIF	275
#define	SWITCH	276
#define	CASE	277
#define	DEFAULT	278
#define	BREAK	279
#define	CONTINUE	280
#define	ASSIGN	281
#define	PLUS	282
#define	MINUS	283
#define	MUL	284
#define	DIV	285
#define	LB	286
#define	RB	287
#define	GTE	288
#define	LTE	289
#define	GT	290
#define	LT	291
#define	EQ	292
#define	NE	293
#define	LC	294
#define	COLON	295
#define	RC	296
#define	DO	297
#define	FOR	298
#define	FNUM	299
#define	INUM	300
#define	TRUE	301
#define	FALSE	302
#define	IDENTIFIER	303

#line 1 "parser.y"
 
#include <iostream>
#include <cstdio>
#include<cstring>
#include"semantics.h"
#include<map>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yywrap();

extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line;
int lCount,sCount;
void yyerror(const char *s);

struct cmp_str
{
bool operator()(char const*a, char const *b ){
return strcmp(a,b)<0;
}
};
map<char*,symbolData*,cmp_str> symbolTable;
map <int,char*> types;


#line 31 "parser.y"
typedef union {
	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		130
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 77)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     6,     8,    10,    12,    18,    24,    30,    33,    34,
    38,    39,    43,    45,    47,    49,    51,    53,    55,    57,
    59,    61,    65,    69,    71,    74,    76,    79,    81,    83,
    85,    87,    89,    93,    97,   101,   105,   109,   113,   117,
   121,   125,   129,   133,   137,   141,   145,   149,   153,   156,
   160,   161,   169,   171,   175,   178,   179,   180,   190,   191,
   192,   193,   205,   206,   207,   208,   209
};

static const short yyrhs[] = {     5,
    52,     7,    53,     4,     0,    10,     0,    11,     0,    12,
     0,     6,    50,    48,    26,    58,     0,     6,    50,    48,
    26,    57,     0,     6,    50,    48,    26,    55,     0,    50,
    48,     0,     0,    52,    51,     3,     0,     0,    53,    54,
     3,     0,    56,     0,    64,     0,    65,     0,    68,     0,
    72,     0,    24,     0,    25,     0,    46,     0,    47,     0,
    48,    26,    60,     0,    48,    26,    55,     0,    44,     0,
    28,    44,     0,    45,     0,    28,    45,     0,    57,     0,
    58,     0,    57,     0,    58,     0,    48,     0,    60,    27,
    60,     0,    60,    28,    60,     0,    60,    29,    60,     0,
    60,    30,    60,     0,    60,    35,    60,     0,    60,    33,
    60,     0,    60,    36,    60,     0,    60,    34,    60,     0,
    60,    38,    60,     0,    60,    37,    60,     0,    60,    37,
    46,     0,    60,    37,    47,     0,    60,    38,    46,     0,
    60,    38,    47,     0,    60,    13,    60,     0,    60,    14,
    60,     0,    15,    60,     0,    31,    60,    32,     0,     0,
    17,    31,    60,    62,    32,    18,    53,     0,    20,     0,
    19,    53,    20,     0,    61,    63,     0,     0,     0,    16,
    31,    60,    66,    32,    39,    67,    53,    41,     0,     0,
     0,     0,    42,    39,    69,    53,    41,    70,    16,    31,
    60,    71,    32,     0,     0,     0,     0,     0,    43,    31,
    48,    73,    26,    60,    74,    40,    60,    40,    59,    75,
    32,    39,    76,    53,    41,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   112,   115,   116,   117,   119,   120,   121,   122,   126,   127,
   131,   132,   135,   136,   137,   138,   139,   141,   142,   147,
   148,   151,   152,   164,   165,   166,   167,   168,   169,   172,
   173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
   183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
   199,   199,   200,   200,   201,   203,   203,   203,   205,   205,
   205,   205,   217,   217,   217,   218,   218
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ENDL","END",
"PROGRAM","CONST","S","INC","DEC","INT","FLOAT","BOOL","AND","OR","NOT","WHILE",
"IF","THEN","ELSE","ENDIF","SWITCH","CASE","DEFAULT","BREAK","CONTINUE","ASSIGN",
"PLUS","MINUS","MUL","DIV","LB","RB","GTE","LTE","GT","LT","EQ","NE","LC","COLON",
"RC","DO","FOR","FNUM","INUM","TRUE","FALSE","IDENTIFIER","program","type","declaration",
"declarations","statements","statement","bval","assignment","fnum","inum","number",
"expr","if_","@1","if_else","if_stmt","while_stsmt","@2","@3","do_while_stmt",
"@4","@5","@6","for_stmt","@7","@8","@9","@10", NULL
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    50,    51,    51,    51,    51,    52,    52,
    53,    53,    54,    54,    54,    54,    54,    54,    54,    55,
    55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
    60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
    60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
    62,    61,    63,    63,    64,    66,    67,    65,    69,    70,
    71,    68,    73,    74,    75,    76,    72
};

static const short yyr2[] = {     0,
     5,     1,     1,     1,     5,     5,     5,     2,     0,     3,
     0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     2,     1,     2,     1,     1,     1,
     1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
     0,     7,     1,     3,     2,     0,     0,     9,     0,     0,
     0,    11,     0,     0,     0,     0,    17
};

static const short yydefact[] = {     0,
     9,     0,     0,    11,     2,     3,     4,     0,     0,     0,
     0,     8,    10,     0,     1,     0,     0,    18,    19,     0,
     0,     0,     0,    13,     0,    14,    15,    16,    17,     0,
     0,     0,    59,     0,     0,    12,    11,    53,    55,     0,
    24,    26,    20,    21,     7,     6,     5,     0,     0,    32,
    30,    31,    56,    51,    11,    63,    23,    22,     0,    25,
    27,    49,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
    50,    47,    48,    33,    34,    35,    36,    38,    40,    37,
    39,    43,    44,    42,    45,    46,    41,     0,     0,    60,
     0,    57,    11,     0,    64,    11,    52,     0,     0,     0,
     0,     0,    58,    61,     0,     0,     0,    62,    28,    29,
    65,     0,     0,    66,    11,     0,    67,     0,     0,     0
};

static const short yydefgoto[] = {   128,
     8,     9,     2,    11,    23,    45,    24,    51,    52,   121,
    53,    25,    77,    39,    26,    27,    76,   106,    28,    55,
   104,   116,    29,    79,   109,   122,   125
};

static const short yypact[] = {     0,
-32768,   102,    50,-32768,-32768,-32768,-32768,   -35,    12,   -32,
     8,-32768,-32768,    -7,-32768,    -5,    -2,-32768,-32768,    25,
     6,    39,    64,-32768,   -12,-32768,-32768,-32768,-32768,    27,
   -14,   -14,-32768,    22,    48,-32768,-32768,-32768,-32768,   -34,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -14,   -14,-32768,
-32768,-32768,   168,   168,-32768,-32768,-32768,   168,    86,-32768,
-32768,   198,   156,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
   -14,   -14,   -14,    53,    76,    45,    46,    11,    54,-32768,
-32768,   198,   186,    28,    28,-32768,-32768,   118,   118,   118,
   118,-32768,-32768,   210,-32768,-32768,   210,    43,    65,-32768,
   -14,-32768,-32768,    71,   168,-32768,   116,    74,    75,   101,
   -14,   -14,-32768,   168,   138,    84,   -24,-32768,-32768,-32768,
-32768,    87,    88,-32768,-32768,   114,-32768,   135,   136,-32768
};

static const short yypgoto[] = {-32768,
   134,-32768,-32768,   -37,-32768,   115,-32768,   -28,   -27,-32768,
   -26,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		246


static const short yytable[] = {    59,
    48,    46,    47,    40,     1,    54,    37,    38,    58,    60,
    61,    15,    12,    40,    13,    14,    49,    78,    30,    41,
    42,    62,    63,    16,    17,    31,    16,    17,    32,    41,
    42,    18,    19,    50,    18,    19,    34,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    94,    97,    20,
    21,   100,    20,    21,    40,    22,    68,    69,    22,     5,
     6,     7,    48,    33,    35,   107,    36,    48,   110,    56,
    41,    42,    43,    44,   105,    40,    98,    99,    49,   101,
    40,   102,   103,    49,   114,   115,   108,   126,   119,   120,
    48,    41,    42,    43,    44,    50,    41,    42,    92,    93,
    50,    16,    17,    40,   111,    80,    49,     3,     4,    18,
    19,     5,     6,     7,   112,   118,    16,    17,   123,    41,
    42,    95,    96,    50,    18,    19,   124,    20,    21,    16,
    17,    16,    17,    22,   129,   130,    10,    18,    19,    18,
    19,   113,    20,    21,    66,    67,    68,    69,    22,    57,
    64,    65,     0,     0,   127,    20,    21,    20,    21,     0,
     0,    22,     0,    22,    66,    67,    68,    69,    64,    65,
    70,    71,    72,    73,    74,    75,     0,   117,     0,     0,
    64,    65,    66,    67,    68,    69,     0,    81,    70,    71,
    72,    73,    74,    75,    66,    67,    68,    69,    64,     0,
    70,    71,    72,    73,    74,    75,     0,     0,     0,     0,
     0,     0,    66,    67,    68,    69,     0,     0,    70,    71,
    72,    73,    74,    75,    66,    67,    68,    69,     0,     0,
    70,    71,    72,    73,    74,    75,    66,    67,    68,    69,
     0,     0,    70,    71,    72,    73
};

static const short yycheck[] = {    37,
    15,    30,    30,    28,     5,    32,    19,    20,    35,    44,
    45,     4,    48,    28,     3,    48,    31,    55,    26,    44,
    45,    48,    49,    16,    17,    31,    16,    17,    31,    44,
    45,    24,    25,    48,    24,    25,    31,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    42,
    43,    41,    42,    43,    28,    48,    29,    30,    48,    10,
    11,    12,    15,    39,    26,   103,     3,    15,   106,    48,
    44,    45,    46,    47,   101,    28,    32,    32,    31,    26,
    28,    39,    18,    31,   111,   112,    16,   125,   117,   117,
    15,    44,    45,    46,    47,    48,    44,    45,    46,    47,
    48,    16,    17,    28,    31,    20,    31,     6,     7,    24,
    25,    10,    11,    12,    40,    32,    16,    17,    32,    44,
    45,    46,    47,    48,    24,    25,    39,    42,    43,    16,
    17,    16,    17,    48,     0,     0,     3,    24,    25,    24,
    25,    41,    42,    43,    27,    28,    29,    30,    48,    35,
    13,    14,    -1,    -1,    41,    42,    43,    42,    43,    -1,
    -1,    48,    -1,    48,    27,    28,    29,    30,    13,    14,
    33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
    13,    14,    27,    28,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    27,    28,    29,    30,    13,    -1,
    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
    -1,    -1,    27,    28,    29,    30,    -1,    -1,    33,    34,
    35,    36,    37,    38,    27,    28,    29,    30,    -1,    -1,
    33,    34,    35,    36,    37,    38,    27,    28,    29,    30,
    -1,    -1,    33,    34,    35,    36
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/cygnus/cygwin-b20/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/cygnus/cygwin-b20/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 112 "parser.y"
{ cout<< "program skeleton defined"<<endl; ;
    break;}
case 2:
#line 115 "parser.y"
{yyval.ival=1;;
    break;}
case 3:
#line 116 "parser.y"
{yyval.ival=2;;
    break;}
case 4:
#line 117 "parser.y"
{yyval.ival=3;;
    break;}
case 5:
#line 119 "parser.y"
{addConst(yyvsp[-2].sval,yyvsp[-3].ival,iToCa(yyvsp[0].ival),1);/*cout << "constant defined " << $3<<endl;*/;
    break;}
case 6:
#line 120 "parser.y"
{addConst(yyvsp[-2].sval,yyvsp[-3].ival,fToCa(yyvsp[0].fval),2);;
    break;}
case 7:
#line 121 "parser.y"
{addConst(yyvsp[-2].sval,yyvsp[-3].ival,yyvsp[0].sval,3);/*cout << "constant defined " << $3<<endl;*/;
    break;}
case 8:
#line 122 "parser.y"
{addVar(yyvsp[0].sval,yyvsp[-1].ival); /*cout << "variable defined " << $2 <<endl;*/;
    break;}
case 13:
#line 135 "parser.y"
{/*cout <<line<<": assignemt statemet" <<endl;*/;
    break;}
case 14:
#line 136 "parser.y"
{/*cout <<line<<": if statemet" <<endl;*/;
    break;}
case 15:
#line 137 "parser.y"
{/*cout <<"while loop " <<endl;*/;
    break;}
case 16:
#line 138 "parser.y"
{/*cout <<"do while loop" <<endl;*/;
    break;}
case 17:
#line 139 "parser.y"
{/*cout << "for loop" ;*/;
    break;}
case 18:
#line 141 "parser.y"
{checkBreak();/*cout <<" break statement" <<endl;*/;
    break;}
case 19:
#line 142 "parser.y"
{checkContinue();/*cout <<" cntinue statement" <<endl;*/;
    break;}
case 20:
#line 147 "parser.y"
{yyval.sval=(char*)"1";;
    break;}
case 21:
#line 148 "parser.y"
{yyval.sval=(char*)"0";;
    break;}
case 22:
#line 151 "parser.y"
{checkAssignExp(yyvsp[-2].sval,yyvsp[0].eval);;
    break;}
case 23:
#line 152 "parser.y"
{checkAssignBool(yyvsp[-2].sval,yyvsp[0].sval);;
    break;}
case 24:
#line 164 "parser.y"
{yyval.fval=yyvsp[0].fval;;
    break;}
case 25:
#line 165 "parser.y"
{yyval.fval=-1*yyvsp[0].fval;;
    break;}
case 26:
#line 166 "parser.y"
{yyval.ival=yyvsp[0].ival;;
    break;}
case 27:
#line 167 "parser.y"
{yyval.ival=-1*yyvsp[0].ival;;
    break;}
case 28:
#line 168 "parser.y"
{yyval.nval=createNum(2,fToCa(yyvsp[0].fval));;
    break;}
case 29:
#line 169 "parser.y"
{yyval.nval=createNum(1,iToCa(yyvsp[0].ival));;
    break;}
case 30:
#line 172 "parser.y"
{yyval.eval = createExpr(2,fToCa(yyvsp[0].fval),0,NULL);;
    break;}
case 31:
#line 173 "parser.y"
{yyval.eval = createExpr(1,iToCa(yyvsp[0].ival),0,NULL);;
    break;}
case 32:
#line 174 "parser.y"
{yyval.eval = createExpr(0,NULL,1,yyvsp[0].sval);;
    break;}
case 33:
#line 175 "parser.y"
{yyval.eval = checkArithm(yyvsp[-2].eval,'+',yyvsp[0].eval);;
    break;}
case 34:
#line 176 "parser.y"
{yyval.eval = checkArithm(yyvsp[-2].eval,'-',yyvsp[0].eval);;
    break;}
case 35:
#line 177 "parser.y"
{yyval.eval = checkArithm(yyvsp[-2].eval,'*',yyvsp[0].eval);;
    break;}
case 36:
#line 178 "parser.y"
{yyval.eval = checkArithm(yyvsp[-2].eval,'/',yyvsp[0].eval);;
    break;}
case 37:
#line 179 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)">" ,yyvsp[0].eval);;
    break;}
case 38:
#line 180 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)">=",yyvsp[0].eval);;
    break;}
case 39:
#line 181 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)"<" ,yyvsp[0].eval);;
    break;}
case 40:
#line 182 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)"<=",yyvsp[0].eval);;
    break;}
case 41:
#line 183 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)"!=",yyvsp[0].eval);;
    break;}
case 42:
#line 184 "parser.y"
{yyval.eval = checkComparison(yyvsp[-2].eval,(char*)"==",yyvsp[0].eval);;
    break;}
case 43:
#line 185 "parser.y"
{yyval.eval = checkBoolComparison(yyvsp[-2].eval,(char*)"==",yyvsp[0].bval);;
    break;}
case 44:
#line 186 "parser.y"
{yyval.eval = checkBoolComparison(yyvsp[-2].eval,(char*)"==",yyvsp[0].bval);;
    break;}
case 45:
#line 187 "parser.y"
{yyval.eval = checkBoolComparison(yyvsp[-2].eval,(char*)"!=",yyvsp[0].bval);;
    break;}
case 46:
#line 188 "parser.y"
{yyval.eval = checkBoolComparison(yyvsp[-2].eval,(char*)"!=",yyvsp[0].bval);;
    break;}
case 47:
#line 189 "parser.y"
{yyval.eval = checkLogical(yyvsp[-2].eval,(char*)"&",yyvsp[0].eval);;
    break;}
case 48:
#line 190 "parser.y"
{yyval.eval = checkLogical(yyvsp[-2].eval,(char*)"|",yyvsp[0].eval);;
    break;}
case 49:
#line 191 "parser.y"
{yyval.eval = checkLogical(NULL,(char*)"!",yyvsp[0].eval);;
    break;}
case 50:
#line 192 "parser.y"
{yyval.eval=yyvsp[-1].eval;;
    break;}
case 51:
#line 199 "parser.y"
{checkCond(yyvsp[0].eval);;
    break;}
case 56:
#line 203 "parser.y"
{checkCond(yyvsp[0].eval);;
    break;}
case 57:
#line 203 "parser.y"
{lCount++;;
    break;}
case 58:
#line 203 "parser.y"
{lCount--;;
    break;}
case 59:
#line 205 "parser.y"
{lCount++;;
    break;}
case 60:
#line 205 "parser.y"
{lCount--;;
    break;}
case 61:
#line 205 "parser.y"
{checkCond(yyvsp[0].eval);;
    break;}
case 63:
#line 217 "parser.y"
{checkType(yyvsp[0].sval,1,1);;
    break;}
case 64:
#line 217 "parser.y"
{checkAssignExp(yyvsp[-3].sval,yyvsp[0].eval);;
    break;}
case 65:
#line 218 "parser.y"
{checkType(yyvsp[-8].sval,yyvsp[0].nval->type,3);;
    break;}
case 66:
#line 218 "parser.y"
{lCount++;;
    break;}
case 67:
#line 218 "parser.y"
{lCount--;;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/cygnus/cygwin-b20/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 238 "parser.y"
 
//end of grammar

int main(int, char**) {
	//Loops =0, Switch cases=0
	lCount=0;sCount=0;
	//initialize types map
	types[0]= (char*)"unknown";
	types[1]= (char*)"int"; 
	types[2]= (char*)"float";
	types[3]= (char*)"bool";
	// open a file handle to a particular file:
	FILE *myfile = fopen("temp.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	checkUnused();
}

void yyerror(const char *s) {
	cout << "oops, parse error in line "<<line<<"!  Message: " << s << endl;
	/*	
	fprintf(stderr,"Error: %s at line %d\n", s,line);
	fprintf(stderr, "Parser does not expect '%s\n'",yytext);
	*/
	exit(-1);
}
/** Functions used for semantic analysis **/

void checkType(char*id,int t,int m){
if(!isDeclared(id)){
//msg(undeclared,line,id,NULL);
return;
}
//Switch case
if(m==2){
if(!isInit(id)){
msg(uninit,line,id,NULL);
return;
}
}
else if(m==1){
	if(symbolTable[id]->type !=1 && symbolTable[id]->type !=2){
	printf("Semantic ERROR line: %d :: Loop counter must have int or float type",line);
	}
}
else{
	if(symbolTable[id]->type == 2)
		return;
	if(t!=1)
	printf("Semantic ERROR line: %d :: Step has to be integer for integer counter",line);
}
}
void checkUnused(){
map<char*,symbolData*> ::iterator it;
for(it=symbolTable.begin();it!=symbolTable.end();it++){
	if(!it->second->used){
		if(it->second->cl==1)
		msg(unusedConst,0,it->first,NULL);
		else
		msg(unusedVar,0,it->first,NULL);
	}

}

}
bool isDeclared(char*id){
map<char*,symbolData*>::iterator it = symbolTable.find(id);
return it!=symbolTable.end();
}
//Convert integer to char*
char*iToCa(int i){
 char*str = (char*)malloc(sizeof(int));	
 sprintf(str, "%d", i);
return str;
}
//Convert float to char*
char*fToCa(float n){
char *b = (char*)malloc(sizeof(float));
int ret = snprintf(b, sizeof b, "%f", n);
//cout<<"Converted Value: "<<b<<endl;
return b;
}
//uninitVar=6,unusedVar=7

void msg(int m, int l,char* t1,char* t2){
if(m==1)
	printf("Semantic ERROR line: %d :: Usage of undeclared variable %s \n",line,t1);	
else if(m==2)
	printf("Semantic ERROR line: %d :: Usage of uninitialized variable %s \n",l,t1);
else if(m==3)
	printf("Semantic ERROR line: %d :: Type Mismatch: can't assign %s to %s \n",line,t1,t2);
else if(m==4)
	printf("Semantic ERROR line: %d :: Type Mismatch: can't Compare %s to %s \n",l,t1,t2);
else if(m==5)
	printf("Semantic ERROR line: %d :: Both expressions should have numerical values \n",l);
else if(m==6)
	printf("Semantic WARNING :: Uninitialized Variable %s \n",t1);
else if(m==7)
	printf("Semantic WARNING :: Unused Variable %s \n",t1);
else if(m==8)
	printf("Semantic ERROR line: %d :: Break statement not within loop or switch case \n",l);
else if(m==9)
	printf("Semantic ERROR line: %d :: Continue statement not within loop \n",l);
else if(m==10)
	printf("Semantic WARNING :: Constant %s is unused \n",t1);

}

bool isInit(char*id){
return symbolTable[id]->val!=NULL;
}

void checkBreak(){
if(lCount == 0 && sCount==0){
msg(brk,line,NULL,NULL);
//printf("Semantic ERROR line: %d :: Break statement not within loop or switch case \n",line);
}
}
void checkContinue(){
if(lCount == 0){
msg(cont,line,NULL,NULL);
//printf("Semantic ERROR line: %d :: Continue statement not within loop \n",line);
}
}

// Constant declaration
void addConst(char*id, int t1,char* val, int t2){

if(isDeclared(id)){
printf("Semantic ERROR line: %d :: Multiple declarations for Const %s",line,id);
return;
}
symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));

if(t1!=t2){
msg(assignMismatch,line,types[t2],types[t1]);
d->val=NULL;
}
else{
d->val = (char*)malloc(sizeof(val));
strncpy(d->val,val,sizeof(d->val));
}

d->type=t1;
d->cl=1;
d->used=0;
symbolTable[id]=d;
printf("%d: %s Const %s %s\n",line,types[t1],id,d->val);
}

/******************Variable declaration*******************/

void addVar(char*id, int t){
if(isDeclared(id))
{printf("Semantic ERROR line: %d :: Multiple declarations for variable %s \n",line,id);
return;
}

symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
d->val=NULL;
d->type=t;
d->cl=0;
d->used=0;
symbolTable[id]=d;
printf("%d: %s Var %s %s\n",line,types[t],id,d->val);
}
/********************Bool Assignment Statement Check***********/
void checkAssignBool(char*id1,char*bolval){
if(!isDeclared(id1)){
msg(undeclared,line,id1,NULL);
return;
}
	symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//Check type mismatch
if(d->type != 3){
msg(assignMismatch,line,types[3],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(bolval));
strncpy(d->val,bolval,sizeof(d->val));
printf("%d: %s %s %s \n",line,types[3],id1,d->val);
}
/********************Expression Assignment Statement Check***********/
void checkAssignExp(char*id1,exptype*e){

//Check identifier is declared prevoiusly
if(!isDeclared(id1)){
	msg(undeclared,line,id1,NULL);
//	printf("Semantic ERROR line: %d :: Usage of undeclared variable %s \n",line,id1);
	return;
}

if(e->id){
	if(!isDeclared(e->name)){
	msg(undeclared,line,e->name,NULL);
	return;
	}
	
	else if (!isInit(e->name)){
	msg(uninit,line,e->name,NULL);
	return;
	}
}


symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//
//Check type mismatch
if(d->type != e->type){
msg(assignMismatch,line,types[e->type],types[d->type]);
//printf("Semantic ERROR line: %d :: Type Mismatch: can't assign %s to %s \n",line,types[e->type],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(e->val));
strncpy(d->val,e->val,sizeof(d->val));
if(e->id==1)
{
symbolTable[e->name]->used=1;
}
printf("%d: %s %s %s \n",line,types[d->type],id1,d->val);
}
/*******************Create Expression *******************/
num*createNum(int t,char* v){
num* n = (num*)malloc(sizeof(struct num));
n->type=t;
n->val=v;
return n;
}
/*
fnum 		{$$ = createExpr(2,fToCa($1),0,NULL); }
inum 		{$$ = createExpr(1,iToCa($1),0,NULL);}
IDENTIFIER 	{$$ = createExpr(0,NULL,1,$1);} 
*/

//1,NULL,1,$1 
/*******************Create Expression *******************/
exptype*createExpr(int i, char* c, int id1, char*n){

exptype* t = (exptype*)malloc(sizeof(struct exptype));

if(id1==1)
{
	if(!isDeclared(n))
	{	//printf("Semantic ERROR line: %d :: Usage of undeclared variable %s \n",line,n);
		msg(undeclared,line,n,NULL);
		t->type=0;
		t->val = NULL;
	}
	else if(!isInit(n)){
		//printf("Semantic ERROR line: %d :: Usage of uninitialized variable %s \n",line,n);
		msg(uninit,line,n,NULL);
		t->type=symbolTable[n]->type;
		t->val = NULL;
		}
	else{
		t->type=symbolTable[n]->type;
		t->val=symbolTable[n]->val;
	}
}
else{
	t->type=i;
	t->val = allocValue(sizeof(c));
	strncpy(t->val,c,sizeof(t->val));	
}
t->id=id1;
t->name=n;

return t;
}

/*********************   Check Arithmetic Operations ******************/
exptype* checkArithm(exptype*e1,char op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));

if(invalidExpressions(e1,e2)){
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;

return t;
}


//One of the expressions is bool
if(e1->type==3 || e2->type==3)
{
	msg(numerical,line,NULL,NULL);
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
	return t;
}

//Mark Used Variables
if(e1->id)
symbolTable[e1->name]->used=1;
if(e2->id)
symbolTable[e2->name]->used=1;

//One of the expressions is float
if(e1->type == 2 || e2->type == 2)
{
	double x1 = (double)atof(e1->val);
	double x2 = (double)atof(e2->val);
	double res = calcFloat(x1, op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 2;
	t->val = fToCa(res);
	t->id = 0;
	t->name = NULL;
	return t;
}
//Both expressions are integers
	long x1 = (long)atoi(e1->val);
	long x2 = (long)atoi(e2->val);
	if(op=='/'){
	double res = calcFloat((double)x1,op,(double)x2);
	t->type = 2;
	t->val = fToCa(res);
	cout<<line<<": Result: "<<res<<endl;
	}
	else{
	long res = calcInt(x1, op,x2);
	t->type = 1;
	t->val = iToCa(res);
	cout<<line<<": Result: "<<res<<endl;
	}		
	
	t->id = 0;
	t->name = NULL;
	return t;
}

double calcFloat(double x1, char op, double x2){
switch(op){
case '+':
	return x1+x2;
	break;
case '-':
	return x1-x2;
	break;
case '*':
	return x1*x2;
	break;
case '/':
	if(x2==0.0){
	printf("Semantic ERROR line: %d :: Can't divide by zero\n",line);
	return 0;
	}
	else{
	return x1/x2;
	}
	break;
}
}

long calcInt(long x1, char op, long x2){
switch(op){
case '+':
	return x1+x2;
	break;
case '-':
	return x1-x2;
	break;
case '*':
	return x1*x2;
	break;
case '/':
	if(x2==0){
	printf("Semantic ERROR line: %d :: Can't divide by zero\n",line);
	return 0;
	}
	else{
	return x1/x2;
	}
	break;
}
}
/******************** Check Comparison statements ******************/
exptype* checkComparison(exptype*e1,char*op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//One of the expressions is not integer or float
if((e1->type != 1 && e1->type != 2) || (e2->type != 1 && e2->type != 2))
{
	//Comparison operands must have numerical values only
	if(op != "!="&&op!="=="){
		//printf("Semantic ERROR line: %d :: Both expressions should have numerical values \n",line);
		msg(numerical,line,NULL,NULL);
		t->type = 0;
		t->val = NULL;
		t->id = 0;
		t->name = NULL;
		return t;
	}
}

if(invalidExpressions(e1,e2)){
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
return t;
}


//Compare 2 integers
if(e1->type == 1 && e2->type==1){
	
	//Mark Used Variables
	if(e1->id)
	symbolTable[e1->name]->used=1;
	if(e2->id)
	symbolTable[e2->name]->used=1;

	long x1 = (long)atoi(e1->val);
	long x2 = (long)atoi(e2->val);
	bool res = compareInt(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}

//Compare 2 floats
if(e1->type == 2 && e2->type==2){
	
	//Mark Used Variables
	if(e1->id)
	symbolTable[e1->name]->used=1;
	if(e2->id)
	symbolTable[e2->name]->used=1;

	double x1 = (double)atoi(e1->val);
	double x2 = (double)atoi(e2->val);
	bool res = compareFloat(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}

//Compare 2 Booleans
if(e1->type == 3 && e2->type==3){
	if(op!="!=" && op!="==")
	{
	printf("Semantic ERROR line: %d :: Can't Compare boolean values \n",line);
	t->type = 0;
	t->val = NULL;
	t->id = 0;
	t->name = NULL;
	return t;
	}
	
	//Mark Used Variables
	if(e1->id)
	symbolTable[e1->name]->used=1;
	if(e2->id)
	symbolTable[e2->name]->used=1;

	bool x1,x2;
	if(e1->val=="1")
	x1=true;
	else 
	x1=false;
	if(e2->val=="1")
	x2=true;
	else 
	x2=false;
		
	bool res = compareBool(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}

//printf("Semantic ERROR line: %d :: Type Mismatch: can't Compare %s to %s \n",line,types[e1->type],types[e2->type]);
msg(compareMismatch,line,types[e1->type],types[e2->type]);
t->type =0;
t->val = NULL;
t->id = 0;
t->name = NULL;
return t;
}

/******************************Check boolean comparison***********************************/
exptype* checkBoolComparison(exptype*e,char*op,bool bolval){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
bool v=false;
if(e->id &&!isDeclared(e->name)){
msg(undeclared,line,e->name,NULL);
v=true;
}
else if(e->type!=3){
//printf("Semantic ERROR line: %d :: Type Mismatch: can't Compare %s to %s \n",line,types[e->type],types[3]);
msg(compareMismatch,line,types[e->type],types[3]);
v=true;
}
//uninitialized
else if (e->id && !isInit(e->name)){
msg(uninit,line,e->name,NULL);
v=true;
}

if(v){
t->type =0;
t->val = NULL;
t->id = 0;
t->name = NULL;
return t;
}

//Mark Used Variables
if(e->id)
symbolTable[e->name]->used=1;

bool x1;
if(e->val == "1")
x1=true;
else
x1=false;

bool res = compareBool(x1,op,bolval);
cout<<line<<": Result: "<<res<<endl;
t->type = 3;
if(res)
	t->val = (char*)"1";
else
	t->val=(char*)"0";
t->id = 0;
t->name = NULL;
return t;
}
/**************** Check Logical Operations *********************/
exptype*checkLogical(exptype*e1,char*op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//One of the expressions is not boolean
bool v = false;
if(e1->type!=3 || e2->type!=3){
printf("Semantic ERROR line: %d :: Both values have to be bool \n",line);
v=true;
}
//One of them is undeclared or unintialiazed
if(invalidExpressions(e1,e2)||v){
t->type=0;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}

//Mark Used Variables
if(e1->id)
symbolTable[e1->name]->used=1;
if(e2->id)
symbolTable[e2->name]->used=1;

bool x1 = (strcmp(e1->val,"1")==0)?true:false; 
bool x2 = (strcmp(e2->val,"1")==0)?true:false;
bool res = logical(x1,op,x2);
t->type=3;
t->val=res?(char*)"1":(char*)"0";
cout<<line<<": Result: "<<res<<endl;
t->name=NULL;
t->id=0;
}
void checkCond(exptype*e){
if(e->id==1){
if(!isDeclared(e->name)){
msg(undeclared,line,e->name,NULL);
return;
}
if(!isInit(e->name))
msg(uninit,line,e->name,NULL);
return;
}
if(e->type!=3){
printf("Semantic ERROR line: %d :: Condition must have a bool value \n",line);
}
}
bool logical(bool x1, char*op,bool x2){
if(op == "&")
return x1&&x2;
if(op=="|")
return x1||x2;
if(op=="!")
return !x2;
}


bool invalidExpressions(exptype*e1,exptype*e2){
bool udec1 = false, udec2 = false, uin1 = false, uin2 = false;
//Expression 1 is identifier
if(e1->id){
	//undelcared
	if(!isDeclared(e1->name)){
	//msg(undeclared,line,e1->name,NULL);
	udec1=true;
	return true;
	}
	//uninitialized
	else if (e1->id && !isInit(e1->name)){
	//msg(uninit,line,e1->name,NULL);
	uin1=true;
	}
	if(!udec1 && !uin1)
		symbolTable[e1->name]->used=1;
}
//Expression 2 is identifier
if(e2->id){
	//undelcared
	if(!isDeclared(e2->name)){
	//msg(undeclared,line,e2->name,NULL);
	udec2=true;
	return true;
	}	
	//uninitialized
	if (!isInit(e2->name)){
	//msg(uninit,line,e2->name,NULL);
	uin2=true;

	}
	if(!udec2&&!uin2)
		symbolTable[e2->name]->used=1;
}

return (udec1 || udec2 || uin1 || uin2);
}
bool compareInt(int x1,char*op, int x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

bool compareFloat(float x1, char*op, float x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

bool compareBool(bool x1, char*op, bool x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

char*allocValue(int t){
if (t==1)
return (char*)malloc(sizeof(int));
else if(t==2)
return (char*)malloc(sizeof(float));
else
return (char*)malloc(2*sizeof(char));
}



