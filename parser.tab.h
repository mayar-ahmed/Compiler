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
    SEMICOLON = 258,
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
    PLUS = 281,
    MINUS = 282,
    MUL = 283,
    DIV = 284,
    GTE = 285,
    LTE = 286,
    GT = 287,
    LT = 288,
    EQ = 289,
    NE = 290,
    COLON = 291,
    DO = 292,
    FOR = 293,
    FNUM = 294,
    INUM = 295,
    TRUE = 296,
    FALSE = 297,
    IDENTIFIER = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:1909  */

	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;

#line 107 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
