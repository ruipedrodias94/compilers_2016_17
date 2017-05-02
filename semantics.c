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
             add_global_symbol(tabela_global,field_decl_node->brother->token,getNode_type(field_decl_node->node_type));
          }
          else if(aux_node->node_type == type_MethodDecl)
          {
            Node *return_type;
            Node *method_name;
            Node * method_type;
            method_header_node = aux_node->son;
            return_type =  method_header_node->son;
            method_name = return_type->brother;
            method_type = method_name->brother;
            add_global_method(tabela_global,method_name->token, getNode_type(method_type->node_type),getNode_type(return_type->node_type));
            add_local_method_table(tabela_global,method_name->token,getNode_type(return_type->node_type));


          }



        aux_node = aux_node->brother;
      }
    }




  imprime_lista(tabela_global);

  return;
}
