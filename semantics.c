#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_ast_to_table(Node *root){

  node_ nn = cria_lista_nodes();
  tab_ tabela = cria_lista_tab();
  Node *program;
  program = root;

  while (program != NULL) {

    if(program->node_type == type_Program)
    {
      //Program
      Node *program_son = program->son;
      printf("CONA: %s\n", program_son->token);
      insere_lista_tab(tabela, program_son->token, "Class", "", nn);

      while(program_son != NULL)
      {
        if(program_son->node_type == type_FieldDecl)
        {
          printf("Entra FIELD\n");
          Node *fieldDecl_son = program_son->son;
          printf("TOKEN: FIELD CARALHO %s\n", fieldDecl_son->brother->token);
          insere_lista_nodes(nn, fieldDecl_son->brother->token, getNode_type(fieldDecl_son->node_type));
          fieldDecl_son = NULL;
        } else if(program_son->node_type == type_MethodDecl){
          printf("GOSTO DE CONA\n");
        }
        program_son = program_son->brother;
      }
    }
    program = program->brother;
  }

  printf("TABELA\n");
  imprime_lista(tabela);
  printf("FIM TABELA\n");
  return;
}
