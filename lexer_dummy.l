%{
#include <cstdio>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex() //to force the g++ compiler to not apply "name-mangling" to the yylex identifier.to force the g++ compiler to not apply "name-mangling" to the yylex identifier.

#include "parser.tab.h"

int line=1;
extern char *yytext;

%}

digit [0-9]
letter [a-zA-Z_]

%% 
and           {/*cout<<"AND"<<endl;*/ return  AND;}
not           {/*cout<<"NOT"<<endl;*/ return NOT;}
or            {/*cout<<"OR"<<endl;*/ return OR;}
do            {/*cout<<"DO"<<endl;*/ return DO;}
if            {/*cout<<"IF"<<endl;*/ return IF;}
while         {/*cout<<"WHILE"<<endl;*/ return WHILE;}
then          {/*cout<<"THEN"<<endl;*/ return THEN;}
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
true          {/*cout<<"TRUE"<<endl;*/ yylval.bval=true; /*cout<<"Val: "<<yylval.bval<<endl;*/ return TRUE;}
false         {/*cout<<"FALSE"<<endl;*/ yylval.bval=false; return FALSE; }

program       {/*cout<<"PROGRAM"<<endl;*/return  PROGRAM;}
begin         {/*cout<<"BEGIN"<<endl;*/return  S;}
end           {/*cout<<"END"<<endl;*/return  END;}
int           {/*cout<<"INT\n";*/yylval.ival=atoi(yytext);/*cout<<"IVal:"<<yylval.ival<<endl;*/ return  INT;}
float         {/*cout<<"FLOAT\n";*/yylval.fval=atof(yytext);/*cout<<"FVal:"<<yylval.fval<<endl;*/return  FLOAT;}
bool          {/*cout<<"BOOL"<<endl;*/return  BOOL;}
const         {/*cout<<"CONST"<<endl;*/return  CONST;}

"="             {/*cout<<"ASSIGN"<<endl;*/return  *yytext;}
"+"             {/*cout<<"PLUS"<<endl;*/return  PLUS;}
"-"             {/*cout<<"MINUS"<<endl;*/ return  MINUS;}
"*"             {/*cout<<"MUL"<<endl;*/ return  MUL;}
"/"             {/*cout<<"DIV"<<endl;*/ return  DIV;}
"("             {/*cout<<"("<<endl;*/ return  *yytext;}
")"             {/*cout<<")"<<endl;*/return  *yytext;}
"<"             {/*cout<<"<"<<endl;*/return  LT;}
">"             {/*cout<<">"<<endl;*/return  GT;}
"=="            {/*cout<<"=="<<endl;*/return  EQ;}
"<="            {/*cout<<"<="<<endl;*/return  LTE;}
">="            {/*cout<<">="<<endl;*/return  GTE;}
"!="            {/*cout<<"!="<<endl;*/return  NE; }
":"             {/*cout<<":"<<endl;*/return  COLON;}
"{"             {/*cout<<"{"<<endl;*/return *yytext;}
"}"             {/*cout<<"}"<<endl;*/return *yytext;}


[ \t]           ; //ignore spaces, tabs and new line
[\n]		{++line;}
{digit}+            {  /*cout<<"integer : " <<atoi(yytext) <<endl;*/ yylval.ival = atoi(yytext); return  INUM; }
[0-9]+\.?[0-9]+	  {  /*cout<<"float : " <<atof(yytext) <<endl;*/ yylval.fval = atof(yytext); return  FNUM; }
{letter}({letter}|{digit})*     {/*cout<<"identifier : " <<strdup(yytext) <<endl;*/   yylval.sval = strdup(yytext);return  IDENTIFIER;}
;               {return  SEMICOLON;}


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

