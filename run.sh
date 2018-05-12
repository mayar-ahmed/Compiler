#!/bin/bash  
echo "script for running lexer and parser"  
bison -d --debug --verbose parser.y
flex lexer_dummy.l
g++  lex.yy.c parser.tab.c -lfl -o out
./out
echo "done running"

