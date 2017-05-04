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
            param_ params_method;
            method_params = method_name->brother;


            /*falta inserir os parametros*/
            param_decl = method_params->son;
            params_method = getParams_list(param_decl);

            //imprime_params(params_method);
            add_global_method(tabela_global,method_name->token, getNode_type(return_type->node_type), getNode_type(return_type->node_type),params_method);
            tabela_local = add_local_method_table(tabela_global,method_name->token,getNode_type(return_type->node_type),params_method);
            add_local_symbol(tabela_local, "return", getNode_type(return_type->node_type),"");
            insere_params_symbol_list(tabela_local,params_method);


            //method body
            method_body = method_header_node->brother;
            aux_node2 = method_body->son;
            while(aux_node2 != NULL)
            {
              if(aux_node2->node_type == type_VarDecl)
              {
                  add_local_symbol(tabela_local, aux_node2->son->brother->token, getNode_type(aux_node2->son->node_type),"");
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

void printAnotatedList(Node* root, int high) {
  int i;
  if(root != NULL){
    /*All the terminals with multiple values*/
    if(root->node_type == type_Id || root->node_type == type_BoolLit || root->node_type == type_RealLit || root->node_type == type_StrLit || root->node_type == type_DecLit){

      for(i=0; i < high; i++){
        printf(".");
      }
      printf("%s(%s)\n",getNode_type(root->node_type), root->token);
    }
    else if(root->node_type==type_Geq)
    {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s - boolean\n",getNode_type(root->node_type) );
    }
    else if(root->node_type==type_Length)
    {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s - int\n",getNode_type(root->node_type) );
    }
    else
    {
      if(root->node_type!=type_Null){
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s\n",getNode_type(root->node_type) );
    }}

    /*As it is a son, prints 2 more (.)*/
    printAnotatedList(root->son, high + 2);
    printAnotatedList(root->brother, high);
  }
}
