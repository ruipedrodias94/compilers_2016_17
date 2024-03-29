#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *field_decl_verifier;


tab_ check_ast_to_table(Node *root){


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


  return tabela_global;
}

void printAnotatedList(char* father,Node* root, int high, tab_ tabela_global, tab_ tabela_local, Node* pai) {
  int i;
  tab_ tabela_global_copy;
  Node* no_pai = pai;
  tab_ tabela_local_copy;
  tabela_local_copy = tabela_local;
  tabela_global_copy = tabela_global;
  


  if(root != NULL){

    if(root->node_type == type_MethodHeader)
    {
      Node *method_decl_son = root->son;
      while(method_decl_son!=NULL)
      {
          //Quando entra aqui passa-se a tabela das variáveis locais
          if(method_decl_son->token!=NULL ){
          tabela_local_copy = get_local_table(method_decl_son->token, tabela_global);
        }
          method_decl_son = method_decl_son->brother;
      }
      for(i=0; i < high; i++){
        printf(".");
      }
      printf("%s\n",getNode_type(root->node_type));

    }
    /*All the terminals with multiple values*/

    else if(root->node_type == type_BoolLit || root->node_type == type_RealLit  ){

      for(i=0; i < high; i++){
        printf(".");
      }
      printf("%s(%s)\n",getNode_type(root->node_type), root->token);
    }
    else if (root->node_type == type_Id) {

      //AQUI ESTA MAL, TEMOS DE IR BUSCAR O TIPO DE ARGUMENTOS QUE RECEBE
      if(strcmp(father,getNode_type(type_ParamDecl))==0 || strcmp(father,getNode_type(type_VarDecl))==0 || strcmp(father,getNode_type(type_FieldDecl))==0 || strcmp(father,getNode_type(type_MethodHeader))==0){

        for(i=0; i < high; i++){
          printf(".");
        }
          printf("%s(%s)\n",getNode_type(root->node_type), root->token);
      }
      else{
          for(i=0; i < high; i++){
            printf(".");
          }
          char *tipo = "";
          tipo = get_type_var(root->token, tabela_global,tabela_local_copy );
          char* params = "";
          if (pai != NULL) 
          {
            
            if (pai->node_type == type_Call)
            {
              
              params = get_param_string_on_tree(pai, tabela_global_copy, tabela_local_copy);
              
              if (strcmp(params, "") == 0)
              {
                printf("NAO TEM PARAMS\n");
                printf("%s(%s) - %s\n",getNode_type(root->node_type), root->token, tipo);
              } else if(strcmp(tipo, "") == 0){
                printf("NAO TEM TIPO\n");
                strcpy(tipo, "undef");
                printf("%s(%s) - %s\n",getNode_type(root->node_type), root->token, tipo);
              }
              else {
                printf("TEM PARAMS\n");
                printf("%s(%s) - %s\n",getNode_type(root->node_type), root->token, params);
              }
            }
          }

          else{
            if (strcmp(tipo, "") == 0) {
              printf("%s(%s)\n",getNode_type(root->node_type), root->token);
            }else{
              printf("%s(%s) - %s\n",getNode_type(root->node_type), root->token, tipo);
            }
          }
          
    }
  }
    else if(root->node_type == type_StrLit ){

      for(i=0; i < high; i++){
        printf(".");
      }
      printf("%s(%s) - String\n",getNode_type(root->node_type), root->token);
    }
    else if(root->node_type == type_Not || root->node_type == type_Or || root->node_type == type_And || root->node_type==type_Eq || root->node_type==type_Neq || root->node_type==type_Lt || root->node_type==type_Gt || root->node_type==type_Leq || root->node_type==type_Geq)
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
    else if(root->node_type==type_DecLit)
    {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s(%s) - int\n",getNode_type(root->node_type),root->token );
    }
    else if(root->node_type==type_ParseArgs)
    {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s - int\n",getNode_type(root->node_type) );
    }
    else if(root->node_type == type_Call){
      for(i=0; i < high; i++){
          printf(".");
      }
      //printf("Buce %s\n", getNode_type(root->node_type));
      //get_param_string_on_tree(root,tabela_global,tabela_local_copy);
      char* params = (char* ) malloc(sizeof(char) + 20);
      strcpy(params, get_param_string_on_tree(root, tabela_global_copy, tabela_local_copy));

      char *rt =(char*) malloc (sizeof(char) + 10);
      strcpy(rt, get_return_type_method_global(root->son->token,tabela_global, params));
      
      /*O pai passa a ser a root*/
      no_pai = root;

      if (strcmp(rt, "") == 0){
        strcpy(rt, "undef");
      }
      printf("%s - %s\n", getNode_type(root->node_type), rt);
      //printf("\nRT: %s\n",rt);


    }
    else if (root->node_type == type_Plus || root->node_type == type_Mul || root->node_type == type_Sub || root->node_type == type_Div) {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s - %s\n", getNode_type(root->node_type), get_type_var(root->son->token, tabela_global_copy, tabela_local_copy));
    }
    else if (root->node_type == type_Assign) {
      for(i=0; i < high; i++){
          printf(".");
      }
      printf("%s - %s\n", getNode_type(root->node_type), get_type_var(root->son->token, tabela_global_copy, tabela_local_copy));
    }
    else
    {
      if(root->node_type!=type_Null){
        if (root->node_type!=type_Id) {
          for(i=0; i < high; i++){
            printf(".");
          }
          printf("%s\n", getNode_type(root->node_type));
        }

      }
    }

    /*As it is a son, prints 2 more (.)*/
    printAnotatedList(getNode_type(root->node_type),root->son, high + 2, tabela_global_copy, tabela_local_copy, no_pai);
    printAnotatedList(father, root->brother, high, tabela_global_copy, tabela_local_copy, no_pai);
  }
}
