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

%}

//token types used  (kol elly elexer momken yraga3o)
%union {
	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;
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
%token <sval> IDENTIFIER

%type <eval> expr
%type <fval> fnum
%type <ival> inum
%type <ival> type
%type <sval> bval
%type <nval> number
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

declaration:  CONST type IDENTIFIER ASSIGN inum {addConst($3,$2,iToCa($5),1);/*cout << "constant defined " << $3<<endl;*/}
	    | CONST type IDENTIFIER ASSIGN fnum {addConst($3,$2,fToCa($5),2);}
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
          
statement: assignment	{/*cout <<line<<": assignemt statemet" <<endl;*/}
        |if_stmt	{/*cout <<line<<": if statemet" <<endl;*/}
        |while_stsmt 	{/*cout <<"while loop " <<endl;*/}
        |do_while_stmt	{/*cout <<"do while loop" <<endl;*/}
        |for_stmt 	{/*cout << "for loop" ;*/}
        |switch_stmt    {/*cout <<"switch statemet" <<endl;*/}
        |BREAK          {checkBreak();/*cout <<" break statement" <<endl;*/}
        |CONTINUE  	{checkContinue();/*cout <<" cntinue statement" <<endl;*/}
        ;
        

/* definition  of assignment operator  */
bval : TRUE 	 {$$=(char*)"1";}
     | FALSE     {$$=(char*)"0";}
     ;

assignment: IDENTIFIER ASSIGN expr {checkAssignExp($1,$3);}
            | IDENTIFIER ASSIGN bval {checkAssignBool($1,$3);}
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
number: fnum {$$=createNum(2,fToCa($1));}
| inum {$$=createNum(1,iToCa($1));};
    
/* all kinds of expressions */
expr: fnum 		{$$ = createExpr(2,fToCa($1),0,NULL);}
    | inum 		{$$ = createExpr(1,iToCa($1),0,NULL);}
    | IDENTIFIER 	{$$ = createExpr(0,NULL,1,$1);} 
    | expr PLUS expr 	{$$ = checkArithm($1,'+',$3);}
    | expr MINUS expr 	{$$ = checkArithm($1,'-',$3);}
    | expr MUL expr 	{$$ = checkArithm($1,'*',$3);}
    | expr DIV expr 	{$$ = checkArithm($1,'/',$3);}
    | expr GT expr	{$$ = checkComparison($1,(char*)">" ,$3);}	
    | expr GTE expr	{$$ = checkComparison($1,(char*)">=",$3);}
    | expr LT expr	{$$ = checkComparison($1,(char*)"<" ,$3);}
    | expr LTE expr	{$$ = checkComparison($1,(char*)"<=",$3);}
    | expr NE expr	{$$ = checkComparison($1,(char*)"!=",$3);}
    | expr EQ expr	{$$ = checkComparison($1,(char*)"==",$3);}
    | expr EQ TRUE	{$$ = checkBoolComparison($1,(char*)"==",$3);}
    | expr EQ FALSE	{$$ = checkBoolComparison($1,(char*)"==",$3);}
    | expr NE TRUE	{$$ = checkBoolComparison($1,(char*)"!=",$3);}
    | expr NE FALSE	{$$ = checkBoolComparison($1,(char*)"!=",$3);}
    | expr AND expr	{$$ = checkLogical($1,(char*)"&",$3);}
    | expr OR expr 	{$$ = checkLogical($1,(char*)"|",$3);}
    | NOT expr		{$$ = checkLogical(NULL,(char*)"!",$2);}
    | LB expr RB	{$$=$2;}
    ;
/*
if_stmt: IF LB expr RB THEN statements ENDIF 
        | IF LB expr RB THEN statements ELSE statements ENDIF
        ;
  */      
if_: IF LB expr{checkCond($3);} RB THEN statements;
if_else:ENDIF|ELSE statements ENDIF;
if_stmt:if_ if_else;        

while_stsmt: WHILE LB expr {checkCond($3);} RB LC{lCount++;} statements RC{lCount--;};

do_while_stmt:DO LC{lCount++;} statements RC{lCount--;} WHILE LB expr{checkCond($9);}RB;


/*  switch case definition*/
pint : INUM | MINUS INUM;

s_stmt: cases default | cases;

case: CASE pint COLON statements; 
cases:  | cases case;
default: DEFAULT COLON statements ;

switch_stmt: SWITCH LB IDENTIFIER{checkType($3,1,2);} RB  LC{sCount++;} s_stmt RC{sCount--;} ;


///////////////////////////////////////////////////////////


/* needs modification to make sure it's correct */

for_stmt: FOR LB IDENTIFIER{checkType($3,1,1);} ASSIGN expr{checkAssignExp($3,$6);} COLON expr 
COLON number{checkType($3,$11->type,3);} RB LC{lCount++;} statements RC{lCount--;}; 

        
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
msg(undeclared,line,id,NULL);
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



