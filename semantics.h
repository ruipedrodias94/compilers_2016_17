#include "estruturas.h"
#include "sym_tab.h"

tab_ check_ast_to_table(Node *root);
void printAnotatedList(char* father,Node* root, int high, tab_ tabela_global, tab_ tabela_local, Node* pai);
