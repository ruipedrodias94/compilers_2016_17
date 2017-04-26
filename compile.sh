#!/bin/s
# Um compile top, aqui só para nós

echo "compiling..."
yacc -d jac.y
lex jac.l
gcc  -o jac lex.yy.c y.tab.c tree_functions.c sym_tab.c semantics.c

if [ $? -eq 0 ]; then
  echo "running..."
  ./jac -t < Echo.ja
  #echo "zippin..."
  #zip -r jac.zip jac.l jac.y estruturas.h tree_functions.c
else
  echo "error compiling..."
  exit 1
fi
