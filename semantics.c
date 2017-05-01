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
      insere_lista_tab(tabela, program_son->token, "Class", "", nn);

      while(program_son != NULL)
      {
        if(program_son->node_type == type_FieldDecl)
        {

          Node *fieldDecl_son = program_son->son;

          insere_lista_nodes(nn, fieldDecl_son->brother->token, getNode_type(fieldDecl_son->node_type));
          fieldDecl_son = NULL;
        } else if(program_son->node_type == type_MethodDecl){
          Node *methodDecl_son = program_son->son;
          Node *methodHeader_son = methodDecl_son->son;
          insere_lista_nodes(nn, methodHeader_son->brother->token, getNode_type(methodHeader_son->node_type));

          /*Criação das novas tabelas*/
          node_ nn2 = cria_lista_nodes();
          insere_lista_tab(tabela, methodHeader_son->brother->token, "Method", "", nn2);

          /*Entrar no method body para podermos ir às variaveis*/
          while (methodDecl_son != NULL) {
            if (methodDecl_son->node_type == type_MethodBody) {
              printf("TEMOS CARALHO:\n");
              break;
            }
            methodDecl_son = methodDecl_son->brother;
          }

          /*Supostamente este no methodDecl_son = MethodBody quando aqui chega, contudo
          quando faço ->son dá-me null... MERDA*/
          
          Node *varDecl = methodDecl_son->son;
          printf("%s\n", varDecl->token);
          while (varDecl != NULL) {
            if (varDecl->node_type == type_VarDecl) {
              /* code */
            }
            Node *varDecl_son = varDecl->son;
            printf("UI VAMOS INSERIR: %s\n", varDecl_son->brother->token);
            insere_lista_nodes(nn2, varDecl_son->brother->token, getNode_type(varDecl_son->node_type));
            printf("BEM INSERIDO METE PROXIMO\n");
            varDecl_son = NULL;
            varDecl = varDecl->brother;
          }

          methodDecl_son = NULL;
          methodHeader_son = NULL;
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
