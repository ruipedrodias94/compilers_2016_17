  #include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_ast_to_table(Node *root){


  tab_ tabela_global = NULL;
  Node *program;
  Node *aux_node;
  Node *field_decl_node;
  Node *method_header_node;
  program = root;



    if(program->node_type == type_Program)
    {
      //Program

      //criacao da tabela global
      Node *program_son = program->son;
      tabela_global = cria_tabela(program_son->token,NULL);
      aux_node = program_son->brother;


      while(aux_node != NULL){


          if(aux_node->node_type == type_FieldDecl)
          {
             field_decl_node = aux_node->son;


          }
          else if(aux_node->node_type == type_MethodDecl)
          {
            method_header_node = aux_node->son;

          }



        aux_node = aux_node->brother;
      }
    }




  imprime_lista(tabela_global);

  return;
}
