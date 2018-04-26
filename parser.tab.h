/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ENDL = 258,
    END = 259,
    PROGRAM = 260,
    CONST = 261,
    S = 262,
    INC = 263,
    DEC = 264,
    INT = 265,
    FLOAT = 266,
    BOOL = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    WHILE = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    ENDIF = 275,
    SWITCH = 276,
    CASE = 277,
    DEFAULT = 278,
    BREAK = 279,
    CONTINUE = 280,
    ASSIGN = 281,
    PLUS = 282,
    MINUS = 283,
    MUL = 284,
    DIV = 285,
    LB = 286,
    RB = 287,
    GTE = 288,
    LTE = 289,
    GT = 290,
    LT = 291,
    EQ = 292,
    NE = 293,
    LC = 294,
    COLON = 295,
    RC = 296,
    DO = 297,
    FOR = 298,
    FNUM = 299,
    INUM = 300,
    TRUE = 301,
    FALSE = 302,
    IDENTIFIER = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:1909  */

	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;

#line 111 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
