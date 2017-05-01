#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_ast_to_table(Node *root){

  node_ nn = cria_lista_nodes();
  tab_ tabela = cria_lista_tab();

    if(root->node_type == type_Program)
    {
      //Program
      insere_lista_tab(tabela,root->son->token,"Class","",nn);

      Node *program_son  =  root->son;
      while(program_son!=NULL)
      {
        if(program_son->node_type == type_FieldDecl)
        {
          Node *FieldDecl_son = program_son->son;
          printf("TOKEN: %s\n", FieldDecl_son->brother->token);
          insere_lista_nodes(nn,FieldDecl_son->brother->token,FieldDecl_son->token);
        }
        program_son = program_son->brother;
      }

    }


  printf("TABELA\n");
  imprime_lista(tabela);
  printf("FIM TABELA\n");
  return;
}
