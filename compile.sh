#!/bin/s

lex jac.l
gcc -o jac lex.yy.c
./jac -l < Echo.ja
zip -r jac.zip jac.l 
