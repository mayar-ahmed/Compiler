%{
#include <stdio.h>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

%}
%% 
int printf("INT");
float printf("FLOAT");
bool printf("BOOL");
const printf("CONST");
^-?[0-9]+$  yylval.number=atoi(yytext);printf("INUM");
^-?[0-9]*\.?[0-9]+$ printf("FNUM");
"=" printf("Equal");
"+" printf("Plus");
"-" printf("Min");
"*" printf("Mul");
"/" printf("Div");
">" printf("gt");
"<" printf("lt");
"<=" printf("lte");
">=" printf("gte");
"==" printf("ee");
"!=" printf("ne");
"{" printf("lc");
"}" printf("rc");
"(" printf("lb");
")" printf("rb");
":" printf("cl");
and printf("AND");
not printf("NOT");
or printf("OR");
do printf("DO");
if printf("IF");
while printf("WHILE");
then printf("THEN");
else printf("ELSE");
switch printf("SWITCH");
case printf("CASE");
default printf("DEFAULT");
break printf("BREAK");
continue printf("CONTINUE");
for printf("FOR");
begin printf("BEGIN");
end printf("END");
program printf("PROGRAM");
endif printf("ENDIF");
endl printf("ENDL");
inc printf("INC");
dec printf("DEC");
true printf("TRUE");
false printf("FALSE");
[a-zA-Z_]([a-zA-Z_]|[0-9]) printf("IDENTIFIER");
%%
