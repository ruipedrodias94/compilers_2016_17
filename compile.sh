#!/bin/s
# Um compile top, aqui só para nós

echo "compiling..."
yacc -d jac.y
lex jac.l
gcc  -o jac lex.yy.c y.tab.c

if [ $? -eq 0 ]; then
  echo "running..."
  ./jac  < Echo.ja
  echo "zippin..."
  zip -r jac.zip jac.l
else
  echo "error compiling..."
  exit 1
fi
