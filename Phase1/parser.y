%{ 

#include <iostream>
#include <cstdio>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line;
void yyerror(const char *s);
%}

//token types used
%union {
	int ival;
	float fval;
	char *sval;
	bool bval;
}

//define constant-string tokens or just return them 
%token ENDL
%token END
%token PROGRAM
%token CONST
%token S
%token INC
%token DEC
%token INT
%token FLOAT
%token BOOL
%token AND
%token OR 
%token NOT
%token WHILE
%token IF
%token THEN
%token ELSE
%token ENDIF
%token SWITCH
%token CASE
%token DEFAULT
%token BREAK
%token CONTINUE
%token ASSIGN
%token PLUS
%token MINUS
%token MUL
%token DIV
%token LB
%token RB
%token GTE
%token LTE
%token GT
%token LT
%token EQ
%token NE
%token LC
%token COLON
%token RC
%token DO
%token FOR


/* tokens with associated vlues*/
%token <fval> FNUM
%token <ival> INUM
%token <bval> TRUE
%token <bval> FALSE
%token <sval>  IDENTIFIER


/* define precedence of operations from lowest to highest */
%right ASSIGN 
%left OR 
%left AND
%left NOT
%left EQ NE
%left GT LT GTE LTE 
%left PLUS MINUS
%left MUL DIV

%%

/* define grammar */

program : PROGRAM  declarations S  statements  END   { cout<< "program skeleton defined"<<endl; }
        ;

type : INT | FLOAT | BOOL ;
declaration: CONST type IDENTIFIER ASSIGN inum {cout << "constant defined " << $3<<endl;}
	    | CONST type IDENTIFIER ASSIGN fnum {cout << "constant defined " << $3<<endl;}
	    | CONST type IDENTIFIER ASSIGN bval   {cout << "constant defined " << $3<<endl;}
            | type IDENTIFIER       { cout << "variable defined " << $2 <<endl;}
            ;
            
declarations:  
            | declarations declaration ENDL
            ;

/*  block of statements is a number of statements each folowed by a semicolon*/
statements: 
          | statements statement ENDL
          ;
/*	Different types of statements	*/        
statement: assignment {cout <<"assignemt statemet" <<endl;}
        | if_stmt    {cout <<"if statemet" <<endl;}
        | while_stsmt  {cout <<"while loop " <<endl;}
        | do_while_stmt {cout <<"do while loop" <<endl;}
        | for_stmt  { cout << "for loop" ;}
        |switch_stmt    {cout <<"switch statemet" <<endl;}
        |BREAK          {cout <<" break statement" <<endl;}
        |CONTINUE  {cout <<" cntinue statement" <<endl;}
        ;
        

/* definition  of assignment operator  */
bval : TRUE | FALSE;
assignment: IDENTIFIER ASSIGN expr /*{cout <<" correct expression defined"<<endl;}*/
            | IDENTIFIER ASSIGN bval
            ;


/* to handle positive and negative numbers with out errors */
fnum: FNUM | MINUS FNUM;
inum: INUM |  MINUS INUM;
number: fnum | inum;


    
/* all kinds of expressions */
expr: number 
    | IDENTIFIER 
    | expr PLUS expr
    | expr MINUS expr
    |expr MUL expr
    |expr DIV expr
    | expr GT expr
    | expr GTE expr
    | expr LT expr
    | expr LTE expr
    | expr NE expr
    | expr EQ expr
    | expr EQ TRUE
    | expr EQ FALSE
    | expr NE TRUE
    | expr NE FALSE
    | expr AND expr
    | expr OR expr 
    | NOT expr
    | LB expr RB
    ;

if_: IF LB expr RB THEN statements;
if_else:ENDIF|ELSE statements ENDIF;
if_stmt:if_ if_else; 

while_stsmt: WHILE LB expr RB LC statements RC ;

do_while_stmt:DO LC statements RC WHILE LB expr RB;


/*  switch case definition*/
pint : INUM | MINUS INUM;

s_stmt: cases default | cases;

case: CASE pint COLON statements; 
cases:  | cases case;
default: DEFAULT COLON statements ;

switch_stmt: SWITCH LB IDENTIFIER RB  LC s_stmt RC ;


///////////////////////////////////////////////////////////


/* For Statement */
for_stmt: FOR LB IDENTIFIER  ASSIGN expr COLON expr COLON number RB LC statements RC; 

%% 
//end of grammar

int main(int, char**) {
	// open a file handle to a particular file:
	FILE *myfile = fopen("b.txt", "r");
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
	
}

void yyerror(const char *s) {
	cout << "oops, parse error in line "<<line<<"!  Message: " << s << endl;
	//exit(-1);
}






