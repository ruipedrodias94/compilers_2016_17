#include "semantics.h"
#include "sym_tab.h"
#include "estruturas.h"


void check_ast_to_table(Node *root){

  /*Tentativa de inserção na tabela*/
  if (root != NULL) {
    printf("Pelo menos entra crl\n");
    var_tab* newel = insert_el(root->token , getNode_type(root->node_type));

    if(newel==NULL) {
        printf("Symbol %s already defined!\n", root->token);
    }
    check_ast_to_table(root->brother);
    check_ast_to_table(root->son);
  }
}
