#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_ast_to_table(Node *root){

  node_ no = cria_lista_nodes();
  no = insere_lista_nodes(no, "teste", "teste");
  imprime_lista(no);
  return;
}
