#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "estruturas.h"

/*Implementação slides de PPP PQP*/

typedef struct lnode_ * param_;
typedef struct lnode_ {
  char *name;
  char *type;
  param_ next;
} _param;


typedef struct ltab_ * tab_;
typedef struct ltab_ {
  char *name;
  char *type;
  char *return_type;
  param_ param;
  tab_ node;
  tab_ next;
} _tab;

tab_ cria_tabela (char *name, param_ params );
void add_global_symbol(tab_ tabela, char *name, char *type);
void add_global_method(tab_ tabela, char *name, char *type, char *return_type, param_ params);
tab_ add_local_method_table(tab_ tabela, char *name, char *return_type);
void add_local_symbol(tab_ tabela, char *name, char *type);
void imprime_lista (tab_ tabela);
void insert_in_params(param_ param_list,char *name, char *type);
param_ getParams_list(Node *methodParams);
char *toLoweCase(char *string);
param_ cria_tabela_params ();

#endif
