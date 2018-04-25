%{ 
#include <iostream>
#include <cstdio>
#include<cstring>
#include"semantics.h"
#include<map>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line;
void yyerror(const char *s);

struct cmp_str
{
bool operator()(char const*a, char const *b ){
return strcmp(a,b)<0;
}
};
map<char*,symbolData*,cmp_str> symbolTable;
map <int,char*> types;

%}

//token types used  (kol elly elexer momken yraga3o)
%union {
	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
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

%type <eval> expr
%type <fval> fnum
%type <ival> inum
%type <ival> type
%type <sval> bval
%type <sval> number
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

type : INT {$$=1;}
| FLOAT {$$=2;}
| BOOL {$$=3;};

declaration:  CONST type IDENTIFIER ASSIGN number {addConst($3,$2,$5,1);/*cout << "constant defined " << $3<<endl;*/}
	    | CONST type IDENTIFIER ASSIGN bval   {addConst($3,$2,$5,3);/*cout << "constant defined " << $3<<endl;*/}
            | type IDENTIFIER      		  {addVar($2,$1); /*cout << "variable defined " << $2 <<endl;*/}
            ;
            
/* this rule wasn't written in the file*/
declarations:  
            | declarations declaration ENDL
            ;

/*  block of statements is a number of statements each folowed by a semicolon*/
statements: 
          | statements statement ENDL
          ;
          
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
bval : TRUE 	 {$$=(char*)"1";}
     | FALSE     {$$=(char*)"0";}
     ;

assignment: IDENTIFIER ASSIGN expr {checkAssignExp($1,$3);}
            | IDENTIFIER ASSIGN bval 
            ;


/* to handle positive and negative numbers with out errors */
/*
pnum: FNUM | INUM;
nnum: MINUS FNUM | MINUS INUM; 
number: pnum | nnum;
*/
/* to handle positive and negative numbers with out errors */
/*to separate float from integer for semantic analysis*/
fnum: FNUM {$$=$1;}
| MINUS FNUM {$$=-1*$2;};
inum: INUM {$$=$1;}
|  MINUS INUM{$$=-1*$2;};
number: fnum {$$=fToCa($1);}
| inum {$$=iToCa($1);};
    
/* all kinds of expressions */
expr: fnum 		{$$ = createExpr(2,fToCa($1),0,NULL); }
    | inum 		{$$ = createExpr(1,iToCa($1),0,NULL);}
    | IDENTIFIER 	{$$ = createExpr(0,NULL,1,$1);} 
    | expr PLUS expr 	{$$ = checkArithm($1,'+',$3);}
    | expr MINUS expr 	{$$ = checkArithm($1,'-',$3);}
    | expr MUL expr 	{$$ = checkArithm($1,'*',$3);}
    | expr DIV expr 	{$$ = checkArithm($1,'/',$3);}
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
    | LB expr RB	{$$=$2;}
    ;

if_stmt: IF LB expr RB THEN statements ENDIF /*{ cout << "if then endif "<<endl;}*/
        | IF LB expr RB THEN statements ELSE statements ENDIF /*{ cout<< "if then else statement"<<endl;}*/
        ;
        
        

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


/* needs modification to make sure it's correct */
for_stmt: FOR LB IDENTIFIER  ASSIGN expr COLON expr COLON number RB LC statements RC; 

        
/* old definition of expression */
/*factor : LB mexpr RB     
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
    ;*/


%% 
//end of grammar

int main(int, char**) {
	//initialize types map
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
	
}

void yyerror(const char *s) {
	cout << "oops, parse error in line "<<line<<"!  Message: " << s << endl;
	exit(-1);
}

/** Functions used for semantic analysis **/

// Constant declaration
void addConst(char*id, int t1,char* val, int t2){

map<char*,symbolData*>::iterator it = symbolTable.find(id);

if(it!=symbolTable.end())
{printf("Semantic ERROR line: %d :: Multiple declarations for Const %s",line,id);
return;
}

if(t1!=t2)
{
printf("Semantic ERROR line: %d :: Type Mismatch: can't assign %s to %s\n",line,types[t2],types[t1]);
}


symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
d->val=val;
d->type=t1;
d->cl=1;
d->used=0;
symbolTable[id]=d;
//cout<<"Const added to table\n";
}

//Variable declaration
void addVar(char*id, int t){

map<char*,symbolData*>::iterator it = symbolTable.find(id);
if(it!=symbolTable.end())
{printf("Semantic ERROR line: %d :: Multiple declarations for variable %s \n",line,id);
return;
}

symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
d->val=NULL;
d->type=t;
d->cl=0;
d->used=0;
symbolTable[id]=d;
//cout<<"Var added to table\n";
}

void checkAssignExp(char*id,exptype*e){
symbolData* d = symbolTable[id];
//Constant can't be changed
if(d->cl == 1){
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//Check type mismatch
if(d->type != e->type){
printf("Semantic ERROR line: %d :: Type Mismatch: can't assign %s to %s \n",line,types[e->type],types[d->type]);
}
}

char*fToCa(float n){
char *b = (char*)malloc(64);
int ret = snprintf(b, sizeof b, "%f", n);
cout<<"Converted Value: "<<b<<endl;
return b;
}

//1,NULL,1,$1 
exptype*createExpr(int i, char* c, int id1, char*n){

exptype* t = (exptype*)malloc(sizeof(struct exptype));

if(id1==1)
{
	map<char*,symbolData*>::iterator it = symbolTable.find(n);
	if(it==symbolTable.end())
	{	printf("Semantic ERROR line: %d :: Usage of undeclared variable %s \n",line,n);
		t-> type=i;
		t-> val=c;
	}
	else if(symbolTable[n]->val==NULL){
			printf("Semantic ERROR line: %d :: Usage of uninitialized variable %s \n",line,n);
			t->type=symbolTable[n]->type;
			t->val = c;
		}
	else{
		t->type=symbolTable[n]->type;
		t->val=symbolTable[n]->val;
	}
	
	
}
else{
	t->type=i;
	t->val=c;
}

t->id=id1;
t->name=n;

return t;
}

exptype* checkArithm(exptype*e1,char op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//One of the expressions is not integer or float
if((e1->type != 1 && e1->type != 2) || (e2->type != 1 && e2->type != 2))
{
	printf("Semantic ERROR line: %d :: Both expressions should have numerical values \n",line);
	t->type = 0;
	t->val = 0;
	t->id = 0;
	t->name = NULL;
	return t;
}
//One of the expressions is float
if(e1->type == 2 || e2->type == 2)
{
	double x1 = (double)atof(e1->val);
	double x2 = (double)atof(e2->val);
	double res = calcFloat(x1, op,x2);
	cout<<"Result: "<<res<<endl;
	t->type = 2;
	t->val = fToCa(res);
	t->id = 0;
	t->name = NULL;
	return t;
}
//Both expressions are integers
	long x1 = (long)atoi(e1->val);
	long x2 = (long)atoi(e2->val);
	long res = calcInt(x1, op,x2);
	cout<<"Result: "<<res<<endl;
	t->type = 1;
	t->val = iToCa(res);
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

char*iToCa(int i){
 char*str = (char*)malloc(sizeof(int));	
 sprintf(str, "%d", i);
return str;
}





