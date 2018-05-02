#!/bin/bash  
echo "script for running lexer and parser"  
bison -d parser.y
flex lexer.l
g++  lex.yy.c parser.tab.c -lfl -o out
./out
echo "done running"

