%{
#include <cstdio>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex() //to force the g++ compiler to not apply "name-mangling" to the yylex identifier.to force the g++ compiler to not apply "name-mangling" to the yylex identifier.

#include "parser.tab.h"

int line=1;

%}

digit [0-9]
letter [a-zA-Z0-9_]

%% 
and           {return  AND;}
not           { return NOT;}
or            { return OR;}
do            { return DO;}
if            { return IF;}
while         { return WHILE;}
then          { return THEN;}
else          { return ELSE;}
switch        { return SWITCH;}
case          { return CASE;}
default       { return DEFAULT;}
break         { return BREAK;}
continue      { return CONTINUE;}
for           { return FOR;}
endif         { return ENDIF;}
inc           { return INC;}
dec           { return DEC;}
true          {yylval.bval=true; return TRUE;}
false         { yylval.bval=false; return FALSE; }

program       { return  PROGRAM;}
begin         { return  S;}
end           { return  END;}
int           {return  INT;}
float         {return  FLOAT;}
bool          {return  BOOL;}
const         {return  CONST;}

"="             {return  ASSIGN;}
"+"             { return  PLUS;}
"-"             {return  MINUS;}
"*"             {return  MUL;}
"/"             {return  DIV;}
"("             {return  LB;}
")"             {return  RB;}
"<"             {return  LT;}
">"             {return  GT;}
"=="            {return  EQ;}
"<="            {return  LTE;}
">="            {return  GTE;}
"!="            {return  NE; }
":"             {return  COLON; }
"{"             {return LC;}
"}"             {return RC;}


[ \t]           ; //ignore spaces, tabs and new line
[\n]		{++line;}
"-"?[0-9]+\.?[0-9]+	  { /* cout<<"float : " <<atof(yytext) <<endl;*/ yylval.fval = atof(yytext); return  FNUM; }
"-"?{digit}+            {  /*cout<<"integer : " <<atoi(yytext) <<endl;*/ yylval.ival = atoi(yytext); return  INUM; }
{letter}({letter}|{digit})*     {/*cout<<"identifier : " <<strdup(yytext) <<endl;*/   yylval.sval = strdup(yytext);return  IDENTIFIER;}
;               {return  ENDL;}


%%

//remove main after adding parser file, it will automatically call it
// int main(int, char**) {
//     // open a file handle to a particular file:
// 	FILE *myfile = fopen("a.txt", "r");
// 	// make sure it's valid:
// 	if (!myfile) {
// 		cout << "I can't open a.snazzle.file!" << endl;
// 		return  -1;
// 	}
// 	// set lex to read from it instead of defaulting to STDIN:
// 	yyin = myfile;
// 
// 	// lex through the input:
// 	yylex();
//    
// }

