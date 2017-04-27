#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>


void check_ast_to_table(Node *root){
  
}

void check_ast(Node* root){
  Node* node_aux;
  node_aux = root;
  int i = 0;
  while (node_aux!= NULL) {
    printf("TENHO NODE: %d ---- %s;\n", i, node_aux->token);
    node_aux = node_aux->brother;
    i++;
  }
}
