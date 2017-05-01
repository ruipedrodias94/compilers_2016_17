#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_ast_to_table(Node *root){

  node_ nn = cria_lista_nodes();
  tab_ tabela = cria_lista_tab();
  while(root!=NULL)
  {
    if(root->node_type == type_Program)
    {
      insere_lista_tab(tabela, root->son->token,"Class","",NULL);
    }
    root = root->son;
  }

  printf("TABELA\n");
  imprime_lista(tabela);
  printf("FIM TABELA\n");
  return;
}
