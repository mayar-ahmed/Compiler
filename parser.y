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

//token types used  (kol elly elexer momken yraga3o)
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
%token <ival> FNUM
%token <fval> INUM
%token <bval> TRUE
%token <bval> FALSE
%token <sval>  IDENTIFIER




%%

/* define grammar */

program : PROGRAM  declarations S  statements  END   { cout<< "program skeleton defined"<<endl; }
        ;

type : INT | FLOAT | BOOL ;
declaration: CONST type IDENTIFIER  { cout << "constant defined " << $3<<endl;}
            | type IDENTIFIER       { cout << "variable defined " << $2 <<endl;}
            ;
            
/* this rule wasn't written in the file*/
declarations:  
            | declarations declaration ENDL
            ;

statements: 
          | statements statement ENDL
          ;
          
statement: assignment {cout <<"assignemt" <<endl;}
        /*| if_stmt 
        | while_stsmt
        | do_while_stmt
        | for_stmt
        |switch_stmt*/ 
        ;
        

/* definition  of assignment operator  */
assignment: /*IDENTIFIER ASSIGN mexpr*/ rexp
		| IDENTIFIER ASSIGN rexp;


/* definition of mathematical expression */
pnum: FNUM | INUM;
nnum: MINUS FNUM | MINUS INUM; 
number: pnum | nnum;

factor : LB mexpr RB     
        | number         
        | IDENTIFIER     
        ;

term: term MUL factor    
    | term DIV factor    
    | factor             
    ;
    
mexpr: mexpr PLUS term  
    | mexpr MINUS term   
    | term               
    ;

bexpr: mexpr|TRUE|FALSE;

%% 
//end of grammar

int main(int, char**) {
	// open a file handle to a particular file:
	FILE *myfile = fopen("a.txt", "r");
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
	cout << "EEK, parse error in line "<<line<<"!  Message: " << s << endl;
	exit(-1);
}






