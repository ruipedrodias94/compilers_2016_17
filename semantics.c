#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"
#include <stdio.h>

tab_of_tabs *general = NULL;
var_tab *tab = NULL;


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
      general->tabela = tab;
      /*No auxiliar*/
      node_aux2 = node_aux;
      while (node_aux2 != NULL) {
        if (node_aux2->node_type == type_FieldDecl) {
          /*Se o nó for do tipo FieldDecl, ele vai ser igual ao seu filho
          E vai inserir na tabela*/
          node_aux3 = node_aux2->son;
          tab = insert_el(node_aux3->brother->token, getNode_type(node_aux3->node_type), "NULL");
          //general->tabela = tab;
          node_aux3 = NULL;
        } else if (node_aux2->node_type == type_MethodDecl) {
          /*Caso o node seja do tipo MethodDecl*/
          node_aux3 = node_aux2->son;
          /*Temos que entrar no filho pois temos (MethodDecl, MethodHeader, id())*/
          if (node_aux3->node_type == type_MethodHeader) {
            node_aux3 = node_aux3->son;
          }
          /*Aqui já obtivemos o id e o type. Inserimos na tabela dos filhos da classe e Criamos
          uma nova tabela, do tipo tab_of_tabs*/
          tab = insert_el(node_aux3->brother->token, getNode_type(node_aux3->node_type), "NULL");
          /*Depois de inserir o header na tabela ja criada, vamos criar a tabela do metodo*/
          /*Algo como: (ESTE CODIGO NAO FUNCIONA)*/
          general = insert_el_header(node_aux3->brother->token, type_Method);
          /*Os parametros também ainda nao estão a funcionar*/
          node_aux3 = NULL;
        }
        node_aux2 = node_aux2->brother;
      }
    }
    node_aux = node_aux->brother;
    i++;
  }
}
