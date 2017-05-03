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
    Node *aux_node2;
  Node *field_decl_node;
  Node *method_header_node;
  Node *method_body;
  Node *method_params;
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
            Node *param_decl;

            tab_ tabela_local;
            method_header_node = aux_node->son;
            return_type =  method_header_node->son;

            method_name = return_type->brother;
            method_params = method_name->brother;

            if (method_params != NULL) {
              printf("TEMOS PARAMETROS \n");
            }
            /*falta inserir os parametros*/
            param_decl = method_params->son;
            int i = getNumberOfParams(param_decl);
            printf("%d\n", i);
            i = 0;
            param_ params_method = getParams_list(param_decl);
            if (params_method != NULL) {
              printf("DEU ALGUMA COISA?\n");
            }
            //imprime_params(params_method);
            param_ *ponteiro;
            ponteiro = &(params_method);
            param_ cópia_param;
            cópia_param = &(**ponteiro);
            printf("SS: %s",cópia_param->next->name);
            add_global_method(tabela_global,method_name->token, getNode_type(return_type->node_type), getNode_type(return_type->node_type),params_method);
            tabela_local = add_local_method_table(tabela_global,method_name->token,getNode_type(return_type->node_type));
            add_local_symbol(tabela_local, "return", getNode_type(return_type->node_type));

            //method body
            method_body = method_header_node->brother;
            aux_node2 = method_body->son;
            while(aux_node2 != NULL)
            {
              if(aux_node2->node_type == type_VarDecl)
              {
                  add_local_symbol(tabela_local, aux_node2->son->brother->token, getNode_type(aux_node2->son->node_type));
              }
              aux_node2 = aux_node2->brother;
            }

          }

        aux_node = aux_node->brother;
      }
    }

  imprime_lista(tabela_global);

  return;
}
