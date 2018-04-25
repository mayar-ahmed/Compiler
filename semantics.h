#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<map>
using namespace std;
//extern map<char*,symbolData> symbolTable;
struct symbolData{
char*val;
int type,cl,used;
};
//Expressions
struct exptype{
int type;	//int, float or bool
int id;		//1-> identifier, 0-> number or boolean value  
char* val;	//Value
char* name;	//name of identifier
};
void addConst(char*,int,char*,int);
void addVar(char*,int);
void checkAssignExp(char*,exptype*);
exptype*createExpr(int i, char* c, int id1, char*n);
exptype* checkArithm(exptype*,char,exptype*);
double calcFloat(double x1, char op, double x2);
long calcInt(long x1, char op, long x2);
char*fToCa(float n);
char*iToCa(int);
