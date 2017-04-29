#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>

tab_of_tabs *general;


void check_ast_to_table(Node *root){
  Node* node_aux;
  Node* node_aux2;
  Node* node_aux3;
  node_aux = root;
  int i = 1;
  while (node_aux != NULL) {
    if (node_aux->node_type == type_Program) {
      /*Se for do tipo programa, podemos passar para os filhos dele,
      pois agora só teremos mais dois tipos de filhos:
      - FieldDecl e MethodDecl*/
      node_aux = node_aux->son;
      /*Criamos uma tab_of_tabs em que o header inicial será o class*/
      general = insert_el_header(node_aux->token, type_Class);

      /*No auxiliar*/
      node_aux2 = node_aux;
      while (node_aux2 != NULL) {
        if (node_aux2->node_type == type_FieldDecl) {

          node_aux3 = node_aux2->son;
          var_tab *tab = insert_el(node_aux3->brother->token, getNode_type(node_aux3->node_type), "NULL");
          general->tabela = tab;
          node_aux3 = NULL;
        }
        node_aux2 = node_aux2->brother;
      }
    }
    node_aux = node_aux->brother;
    i++;
  }
}
