%{ 
#include <iostream>
#include <cstdio>
#include<cstring>
#include"semantics.h"
#include<map>
#include<list>
#include<vector>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line;
int lCount,sCount;
void yyerror(const char *s);
///////Symbol Table///////////////
struct cmp_str
{
bool operator()(char const*a, char const *b ){
return strcmp(a,b)<0;
}
};
map<char*,symbolData*,cmp_str> symbolTable;
map <int,char*> types;
///////// Quadruples//////////
FILE *file = fopen("quad.txt", "w");
struct code
{
	char* opr;
	char* opd1;
	char* opd2;
	char* res;
};
list<code> quads;
int tmp_count=0;
int label=0;
bool err=false;
vector<int> labels;
vector<int> loop_labels;
vector<int> con_labels;
vector<char*> swID;
char* jmp;
%}
%error-verbose
//token types used
%union {
	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;
}

//define constant-string tokens or just return them 
%token SEMICOLON
%token END
%token PROGRAM
%token CONST
%token S
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
%token '='
%token PLUS
%token MINUS
%token MUL
%token DIV
%token '('
%token ')'
%token GTE
%token LTE
%token GT
%token LT
%token EQ
%token NE
%token '{'
%token COLON
%token '}'
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
%right '=' 
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
/* Error Statement definition*/
err_stmt: error SEMICOLON {err=true;}
	| error ')' {err=true;}
	;
/* Types definition*/
type : INT {$$=1;}
| FLOAT {$$=2;}
| BOOL {$$=3;}
;
/* Constant declaration statement definition*/
 const_dec: CONST type IDENTIFIER '=' inum {addConst($3,$2,iToCa($5),1);/*cout << "constant defined " << $3<<endl;*/}
	    | CONST type IDENTIFIER '=' fnum {addConst($3,$2,fToCa($5),2);}
	    | CONST type IDENTIFIER '=' bval   {addConst($3,$2,$5,3);/*cout << "constant defined " << $3<<endl;*/}
	    ;
/* Variable declaration statement definition*/
var_dec: type IDENTIFIER {addVar($2,$1); /*cout << "variable defined " << $2 <<endl;*/};

/* Declaration statement definition*/
declaration:const_dec  
            | var_dec
            ;
            
declarations:  
            | declarations declaration SEMICOLON
	    | declarations err_stmt 
            ;

/*  block of statements is a number of statements each folowed by a semicolon*/
statements: 
          | statements statement SEMICOLON
	  | statements err_stmt
          ;
          
statement: assignment	
        |if_stmt	
        |while_stsmt 	
        |do_while_stmt	
        |for_stmt 	
        |switch_stmt    
        |BREAK          {checkBreak();if(!err){addQuad((char*)"goto",iToCa(loop_labels[loop_labels.size()-2]),NULL,NULL);}}
        |CONTINUE  	{checkContinue();if(!err){addQuad((char*)"goto",iToCa(con_labels.back()),NULL,NULL);}}
        ;
        

/* definition  of assignment operator  */
bval : TRUE 	 {$$=(char*)"1";}
     | FALSE     {$$=(char*)"0";}
     ;

assignment: IDENTIFIER '=' expr {checkAssignExp($1,$3);addQuad((char*)"=",$3->name,NULL,$1);}
          |IDENTIFIER'='bval
	  {checkAssignBool($1,$3);char* v;if($3=="1")v=(char*)"true";else v=(char*)"false";addQuad((char*)"=",v,NULL,$1);}
            ;

/* to handle positive and negative numbers with out errors */
/*to separate float from integer for semantic analysis*/
fnum: FNUM {$$=$1;}
     |MINUS FNUM {$$=-1*$2;};
inum: INUM {$$=$1;}
     |MINUS INUM{$$=-1*$2;};
number: fnum {$$=createNum(2,fToCa($1));} 
       |inum {$$=createNum(1,iToCa($1));};
    
/* all kinds of expressions */
expr: fnum 		{$$ = createExpr(2,fToCa($1),0,NULL);$$->name=addQuad((char*)"=",fToCa($1),NULL,NULL);}
    | inum 		{$$ = createExpr(1,iToCa($1),0,NULL);$$->name=addQuad((char*)"=",iToCa($1),NULL,NULL);}
    | IDENTIFIER 	{$$ = createExpr(0,NULL,1,$1);} 
    | expr PLUS expr 	{$$ = checkArithm($1,'+',$3);$$->name=addQuad((char*)"+",$1->name,$3->name,NULL);}
    | expr MINUS expr 	{$$ = checkArithm($1,'-',$3);$$->name=addQuad((char*)"-",$1->name,$3->name,NULL);}
    | expr MUL expr 	{$$ = checkArithm($1,'*',$3);$$->name=addQuad((char*)"*",$1->name,$3->name,NULL);}
    | expr DIV expr 	{$$ = checkArithm($1,'/',$3);$$->name=addQuad((char*)"/",$1->name,$3->name,NULL);}
    | expr GT expr	{$$ = checkComparison($1,(char*)">" ,$3);$$->name=addQuad((char*)">",$1->name,$3->name,NULL);}	
    | expr GTE expr	{$$ = checkComparison($1,(char*)">=",$3);$$->name=addQuad((char*)">=",$1->name,$3->name,NULL);}
    | expr LT expr	{$$ = checkComparison($1,(char*)"<" ,$3);$$->name=addQuad((char*)"<",$1->name,$3->name,NULL);}
    | expr LTE expr	{$$ = checkComparison($1,(char*)"<=",$3);$$->name=addQuad((char*)"<=",$1->name,$3->name,NULL);}
    | expr NE expr	{$$ = checkComparison($1,(char*)"!=",$3);$$->name=addQuad((char*)"!=",$1->name,$3->name,NULL);}
    | expr EQ expr	{$$ = checkComparison($1,(char*)"==",$3);$$->name=addQuad((char*)"==",$1->name,$3->name,NULL);}
    | expr EQ TRUE	{$$ = checkBoolComparison($1,(char*)"==",$3);$$->name=addQuad((char*)"==",$1->name,(char*)"true",NULL);}
    | expr EQ FALSE	{$$ = checkBoolComparison($1,(char*)"==",$3);$$->name=addQuad((char*)"==",$1->name,(char*)"false",NULL);}
    | expr NE TRUE	{$$ = checkBoolComparison($1,(char*)"!=",$3);$$->name=addQuad((char*)"!=",$1->name,(char*)"true",NULL);}
    | expr NE FALSE	{$$ = checkBoolComparison($1,(char*)"!=",$3);$$->name=addQuad((char*)"!=",$1->name,(char*)"false",NULL);}
    | expr AND expr	{$$ = checkLogical($1,(char*)"&",$3);$$->name=addQuad((char*)"and",$1->name,$3->name,NULL);}
    | expr OR expr 	{$$ = checkLogical($1,(char*)"|",$3);$$->name=addQuad((char*)"or",$1->name,$3->name,NULL);}
    | NOT expr		{$$ = checkNot($2);$$->name=addQuad((char*)"not",$2->name,NULL,NULL);}
    | '(' expr ')'	{$$=$2;}
    ;
 /* If statement definition*/
if_: IF '(' expr{checkCond($3);addQuad((char*)"if not",iToCa(label),$3->name,NULL);labels.push_back(label);label++;} ')'THEN 		statements;
if_else:ENDIF
	|ELSE {addQuad((char*)"goto",iToCa(label),NULL,NULL);addQuad((char*)"l",iToCa(labels.back()),NULL,NULL); 			labels.pop_back();labels.push_back(label);label++;}statements ENDIF;
if_stmt:if_ if_else {addQuad((char*)"l",iToCa(labels.back()),NULL,NULL);labels.pop_back();};        

/* While definition*/
while_stsmt: WHILE {addQuad((char*)"l",iToCa(label),NULL,NULL);label++;push_l();label--;}
		'(' expr {checkCond($4);addQuad((char*)"if not",iToCa(label),$4->name,NULL);label--;con_labels.push_back(label);
		push_l();label++;}')' '{'{lCount++;} statements '}'{lCount--;
		addQuad((char*)"goto",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();con_labels.pop_back();
		addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();};

/* Do While definition*/
do_while_stmt:DO '{'{lCount++;addQuad((char*)"l",iToCa(label),NULL,NULL);push_l();push_l();con_labels.push_back(label);push_l();}
		 statements '}'{lCount--;} WHILE '(' {addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();}
		 expr{checkCond($10);addQuad((char*)"if",iToCa(loop_labels[loop_labels.size()-2]),$10->name,NULL);
		addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();loop_labels.pop_back();
		con_labels.pop_back();}')';


/* Switch Case definition*/
s_stmt: cases default | cases;

case: CASE inum COLON {
	addQuad((char*)"if not",iToCa(label),addQuad((char*)"==",swID.back(),addQuad((char*)"=",iToCa($2),NULL,NULL),NULL),NULL);
	push_l();}
	statements
	{addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();}; 
cases:  | cases case;
default: DEFAULT COLON {push_l();} statements {loop_labels.pop_back();} ;

switch_stmt: SWITCH '(' IDENTIFIER{checkType($3,1,2);swID.push_back(addQuad((char*)"=",$3,NULL,NULL));push_l();} ')'  '{'
		{sCount++;} s_stmt '}'{sCount--;addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();
		swID.pop_back();} ;

/* For statement definition*/

for_stmt: FOR '(' IDENTIFIER{checkType($3,1,1);} '=' expr{checkAssignExp($3,$6);addQuad((char*)"=",$6->name,NULL,$3);
	addQuad((char*)"l",iToCa(label),NULL,NULL);push_l();} COLON expr 
	COLON number{checkType($3,$11->type,3);addQuad((char*)"if not",iToCa(label),$9->name,NULL);push_l();
	con_labels.push_back(label);push_l();}
	')' '{'{lCount++;} statements '}'
	{lCount--;addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();
	addQuad((char*)"=",addQuad((char*)"+",$3,addQuad((char*)"=",$11->val,NULL,NULL),NULL),NULL,$3);
	addQuad((char*)"goto",iToCa(loop_labels[loop_labels.size()-2]),NULL,NULL);
	addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);
	loop_labels.pop_back();loop_labels.pop_back();con_labels.pop_back();}; 

%% 
//end of grammar

int main(int, char**) {
	//yydebug=1;
	//Loops =0, Switch cases=0
	lCount=0;sCount=0;
	//initialize types map
	types[0]= (char*)"unknown";
	types[1]= (char*)"int"; 
	types[2]= (char*)"float";
	types[3]= (char*)"bool";
	// open a file handle to a particular file:
	FILE *myfile = fopen("quadTest.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	// make sure it is valid:
	if (!file) {
		cout << "can't open file" << endl;
		return -1;
	}
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	// Print unused variables
	checkUnused();
	//Display symbol table
	printST();
	//Display quadruples
	if(!err)
		printQuads();
	
}

void yyerror(const char *s) {
	fprintf(stderr,"Syntax ERROR line: %d :: %s\n", line,s);	
}
//Display symbol table
void printST(){
map<char*,symbolData*> ::iterator it;
printf("SYMBOL TABLE:\n");
printf("=============\n");
printf("IDENTIFIER\tTYPE\tUSED\tCLASS\n");
char* clss;
symbolData* data;
for(it=symbolTable.begin();it!=symbolTable.end();it++){
data = it->second;
if(data->cl==1)
clss = (char*)"Const";
else
clss = (char*)"Variable";
printf("%s\t\t%s\t%d\t%s\n",it->first,types[data->type],data->used,clss);
}

}
////////// Quadruples /////////////////
char* addQuad(char* opr,char* opd1,char* opd2,char* res)
{
	struct code q;
	q.opr=opr;
	q.opd1=opd1;
	q.opd2=opd2;
	if(res==NULL && opr!=(char*)"if not" && opr!=(char*)"if" && opr!=(char*)"l" && opr!=(char*)"goto")
	{
		char* t=(char*)"t";
		char* tmp = (char *) malloc(1 + strlen(t)+ strlen(iToCa(tmp_count)) );
		strcpy(tmp, t);
		strcat(tmp, iToCa(tmp_count));
		q.res=tmp;
		tmp_count++;
	}
	else
		q.res=res;
	quads.push_back(q);
	return q.res;
}
void printQuads()
{
	while(!quads.empty())
	{
		struct code q=quads.front();
		if(q.opr==(char*)"if not")
		{
			fprintf(file,"if not %s goto L%s\n",q.opd2,q.opd1);
		}
		else if(q.opr==(char*)"if")
		{
			fprintf(file,"if %s goto L%s\n",q.opd2,q.opd1);
		}
		else if(q.opr==(char*)"l")
		{
			fprintf(file,"L%s:\n",q.opd1);
		}
		else if(q.opr==(char*)"goto")
		{
			fprintf(file,"goto L%s\n",q.opd1);
		}
		else if(q.opr==(char*)"=")
		{
			fprintf(file, "MOV %s    %s\n",q.opd1,q.res);
		}
		else if(q.opr==(char*)"not")
		{
			fprintf(file,"Not %s    %s\n",q.opd1,q.res);
		}
		else
		{
			if(q.opr==(char*)"+")
			{
				fprintf(file,"Add ");
			}
			else if(q.opr==(char*)"-")
			{
				fprintf(file,"Sub ");
			}
			else if(q.opr==(char*)"*")
			{
				fprintf(file,"Mul ");
			}
			else if(q.opr==(char*)"/")
			{
				fprintf(file,"Div ");
			}
			else if(q.opr==(char*)"and")
			{
				fprintf(file,"And ");
			}
			else if(q.opr==(char*)"or")
			{
				fprintf(file,"Or ");
			}
			else if(q.opr==(char*)"<")
			{
				fprintf(file,"LT ");
				jmp=(char*)"JGE";
			}
			else if(q.opr==(char*)">")
			{
				fprintf(file,"GT ");
				jmp=(char*)"JLE";
			}
			else if(q.opr==(char*)"==")
			{
				fprintf(file,"EQ ");
				jmp=(char*)"JNE";
			}
			else if(q.opr==(char*)">=")
			{
				fprintf(file,"GE ");
				jmp=(char*)"JL";
			}
			else if(q.opr==(char*)"<=")
			{
				fprintf(file,"LE ");
				jmp=(char*)"JG";
			}
			else if(q.opr==(char*)"!=")
			{
				fprintf(file,"NE ");
				jmp=(char*)"JE";
			}
			fprintf(file,"%s %s %s\n",q.opd1,q.opd2,q.res);
		}
		quads.pop_front();
	}
}
void push_l()
{
	loop_labels.push_back(label);
	label++;
}
/** Functions used for semantic analysis **/

/******************Type check*******************/
//used in switch, for statements
void checkType(char*id,int t,int m){
//Mark used variable
if(isDeclared(id))
	symbolTable[id]->used=1;
//Switch case
if(m==2){
	if(!isDeclared(id)){
	err=true;
	msg(undeclared,line,id,NULL);
	return;
	}
	//Check if the variable is not integer
	if(symbolTable[id]->type!=1){
		printf("Semantic ERROR line: %d :: %s must have integer type\n",line,id);
		return;
	}

	if(!isInit(id)){
	err=true;
	msg(uninit,line,id,NULL);
	return;
	}
}
//For statement: check identifier type
else if(m==1){
	if(!isDeclared(id)){
	err=true;
	return;
	}
	//loop counter is not integer or float
	if(symbolTable[id]->type !=1 && symbolTable[id]->type !=2){
	err=true;
	printf("Semantic ERROR line: %d :: Loop counter must have int or float type",line);
	}
}
//For statement: check step type with identifier type
else{

	if(!isDeclared(id)){
	err=true;
	return;
	}
	if(symbolTable[id]->type == 2)
		return;
	if(t!=1){
	err=true;
	printf("Semantic ERROR line: %d :: Step has to be integer for integer counter\n",line);
}

}
}
/******************Print WARNINGS for unused variables*******************/
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
/************Check if identifier is previously declared***********/
bool isDeclared(char*id){
map<char*,symbolData*>::iterator it = symbolTable.find(id);
return it!=symbolTable.end();
}
/******************Convert integer to (char*)*******************/
char*iToCa(int i){
 char*str = (char*)malloc(sizeof(int));	
 sprintf(str, "%d", i);
return str;
}
/******************Convert float to (char*)*******************/
char*fToCa(float n){
char *b = (char*)malloc(sizeof(float));
int ret = snprintf(b, sizeof b, "%f", n);
//cout<<"Converted Value: "<<b<<endl;
return b;
}
/******************Print error messages*******************/
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
/**********Check if identidier is initialized************/
bool isInit(char*id){
return symbolTable[id]->val!=NULL;
}
/**************Semantics for break statement*************/
void checkBreak(){
if(lCount == 0 && sCount==0){
err=true;
msg(brk,line,NULL,NULL);
}
}
/**************Semantics for break statement*************/
void checkContinue(){
if(lCount == 0){
err=true;
msg(cont,line,NULL,NULL);
}
}

/************Semantics for Constant Declaration*********/
// Constant declaration
void addConst(char*id, int t1,char* val, int t2){

if(isDeclared(id)){
err=true;
printf("Semantic ERROR line: %d :: Multiple declarations for %s\n",line,id);
return;
}

symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
//Type mismatch
if(t1!=t2){
err=true;
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
//printf("%d: %s Const %s %s\n",line,types[t1],id,d->val);
}

/*********Semantics for Variable declaration************/

void addVar(char*id, int t){
if(isDeclared(id))
{
err=true;
printf("Semantic ERROR line: %d :: Multiple declarations for %s \n",line,id);
return;
}

symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
d->val=NULL;
d->type=t;
d->cl=0;
d->used=0;
symbolTable[id]=d;
//printf("%d: %s Var %s %s\n",line,types[t],id,d->val);
}
/**********Semantics for Bool Assignment Statement**********/
void checkAssignBool(char*id1,char*bolval){
if(!isDeclared(id1)){
err=true;
msg(undeclared,line,id1,NULL);
return;
}
symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
err=true;
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//Check type mismatch
if(d->type != 3){
err=true;
if(d->type!=0)
	msg(assignMismatch,line,types[3],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(bolval));
strncpy(d->val,bolval,sizeof(d->val));
//printf("%d: %s %s %s \n",line,types[3],id1,d->val);
}
/********************Expression Assignment Statement Check***********/
void checkAssignExp(char*id1,exptype*e){

//Check identifier is declared prevoiusly
if(!isDeclared(id1)){
	err=true;
	msg(undeclared,line,id1,NULL);
	return;
}
//If RHS is identifier
if(e->id){
	if(!isDeclared(e->name)){
	err=true;	
	return;
	}
	else{ 
	symbolTable[e->name]->used=1;
	if (!isInit(e->name)){
	err=true;
	printf("Semantic ERROR line: %d :: RHS has no value, LHS unchanged! \n",line);
	return;
	}
	}
}


symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
err=true;
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//
if(e->val == NULL){
err=true;
printf("Semantic ERROR line: %d :: RHS has no value, LHS unchanged! \n",line);
return;
}
//Check type mismatch
if(d->type != e->type){
err=true;
if(e->type!=0 && d->type!=0)
	msg(assignMismatch,line,types[e->type],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(e->val));
strncpy(d->val,e->val,sizeof(d->val));

//printf("%d: %s %s %s \n",line,types[d->type],id1,d->val);
}
/*******************Create Number *********************/
num*createNum(int t,char* v){
num* n = (num*)malloc(sizeof(struct num));
n->type=t;
n->val=v;
return n;
}

/*******************Create Expression *******************/
exptype*createExpr(int i, char* c, int id1, char*n){

exptype* t = (exptype*)malloc(sizeof(struct exptype));
//if expression is an identifier 
if(id1==1)
{
	if(!isDeclared(n))
	{
		err=true;
		msg(undeclared,line,n,NULL);
		t->type=0;
		t->val = NULL;
	}
	else if(!isInit(n)){
		err=true;
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
//Mark Used Variables
if(isDeclared(e1->name))
symbolTable[e1->name]->used=1;

if(isDeclared(e2->name))
symbolTable[e2->name]->used=1;

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
	err=true;
	if(e1->type!=0 && e2->type!=0)
		msg(numerical,line,NULL,NULL);
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
	return t;
}



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

//Mark Used Variables
if(isDeclared(e1->name))
symbolTable[e1->name]->used=1;

if(isDeclared(e2->name))
symbolTable[e2->name]->used=1;


//One of the expressions is not integer or float
if((e1->type != 1 && e1->type != 2) || (e2->type != 1 && e2->type != 2))
{
	//Comparison operands must have numerical values only
	if(op != "!="&&op!="=="){
		err=true;
		if(e1->type!=0 && e2->type!=0)
		msg(numerical,line,NULL,NULL);
		t->type = 0;
		t->val = NULL;
		t->id = 0;
		t->name = NULL;
		return t;
	}
}

if(invalidExpressions(e1,e2)){
	err=true;
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
return t;
}


//Compare 2 integers
if(e1->type == 1 && e2->type==1){

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
	err=true;
	printf("Semantic ERROR line: %d :: Can't Compare boolean values \n",line);
	t->type = 0;
	t->val = NULL;
	t->id = 0;
	t->name = NULL;
	return t;
	}

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
if(e1->type!=0 && e2->type!=0)
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
//Mark used variables
if(e->id && isDeclared(e->name))
symbolTable[e->name]->used=1;

bool v=false;
if(e->id &&!isDeclared(e->name)){
err=true;
msg(undeclared,line,e->name,NULL);
v=true;
}
else if(e->type!=3){
err=true;
if(e->type!=0)
	msg(compareMismatch,line,types[e->type],types[3]);
v=true;
}
//uninitialized
else if (e->id && !isInit(e->name)){
err=true;
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
err=true;
if(e1->type!=0 && e2->type!=0)
	printf("Semantic ERROR line: %d :: Both values have to be bool \n",line);
v=true;
}
//One of them is undeclared or unintialiazed
if(invalidExpressions(e1,e2)||v){
err=true;
t->type=0;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}

bool x1 = (strcmp(e1->val,"1")==0)?true:false; 
bool x2 = (strcmp(e2->val,"1")==0)?true:false;
bool res = logical(x1,op,x2);
t->type=3;
t->val=res?(char*)"1":(char*)"0";
cout<<line<<": Result: "<<res<<endl;
t->name=NULL;
t->id=0;
}
/**************** Check NOT Operation *********************/
exptype*checkNot(exptype*e){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
if(!isDeclared(e->name)){
err=true;
t->type=3;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}
if(e->type!=3){
printf("Semantic ERROR line: %d :: Can't apply NOT on %s variable!\n",line,types[e->type]);
err=true;
t->type=3;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}


bool x = (strcmp(e->val,"1")==0)?true:false;
if(!x)
t->val=(char*)"1";
else
t->val=(char*)"0";

t->type=3;
t->name=NULL;
t->id=0;
return t;

}
/**************** Check Conditions *********************/
void checkCond(exptype*e){
if(e->id==1){
if(!isDeclared(e->name)){
err=true;
msg(undeclared,line,e->name,NULL);
return;
}
if(!isInit(e->name))
err=true;
msg(uninit,line,e->name,NULL);
return;
}
if(e->type!=3){
err=true;
if(e->type!=0)
	printf("Semantic ERROR line: %d :: Condition must have a bool value \n",line);
}
}
/**************Apply Logical Operations *****************/
bool logical(bool x1, char*op,bool x2){
if(op == "&")
return x1&&x2;
if(op=="|")
return x1||x2;
if(op=="!")
return !x2;
}

/*********Check both expressions to be declared & initialized********/
bool invalidExpressions(exptype*e1,exptype*e2){
bool udec1 = false, udec2 = false, uin1 = false, uin2 = false;
//Expression 1 is identifier
if(e1->id){
	//undelcared
	if(!isDeclared(e1->name)){
	udec1=true;
	return true;
	}
	symbolTable[e1->name]->used=1;
	//uninitialized
	if (!isInit(e1->name)){
	uin1=true;
	}
		
}
//Expression 2 is identifier
if(e2->id){
	//undelcared
	if(!isDeclared(e2->name)){
	udec2=true;
	return true;
	}
	symbolTable[e2->name]->used=1;	
	//uninitialized
	if (!isInit(e2->name)){
	uin2=true;

	}
		
}

return (udec1 || udec2 || uin1 || uin2);
}
/****************Apply integer Comparison*********************/
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
/****************Apply float Comparison*********************/
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
/****************Apply Bool Comparison*********************/
bool compareBool(bool x1, char*op, bool x2){
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}
/****************Allocate memory*********************/
char*allocValue(int t){
if (t==1)
return (char*)malloc(sizeof(int));
else if(t==2)
return (char*)malloc(sizeof(float));
else
return (char*)malloc(2*sizeof(char));
}



