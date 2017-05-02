#!/bin/s
# Um compile top, aqui só para nós

echo "compiling..."
yacc -d jac.y
lex jac.l
gcc -Wall -g -o jac lex.yy.c y.tab.c tree_functions.c sym_tab.c semantics.c

if [ $? -eq 0 ]; then
  echo "running..."

  #valgrind --leak-check=yes ./jac -s < Echo.ja
  #./jac -t < Echo.ja

  #valgrind --leak-check=yes ./jac -t < Echo.ja
  ./jac -s < Echo.ja

  #echo "zippin..."
  zip -r jac.zip jac.l jac.y estruturas.h sym_tab.h semantics.h tree_functions.c sym_tab.c semantics.c
else
  echo "error compiling..."
  exit 1
fi
