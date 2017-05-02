#ifndef SYM_TAB_H
#define SYM_TAB_H

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
  param_ *param;
  tab_ node;
  tab_ next;
} _tab;

tab_ cria_tabela (char *name, param_ *params );
void add_global_symbol(tab_ tabela, char *name, char *type);
void imprime_lista (tab_ tabela);
param_ insert_in_params(param_ param, char *name, char *type);
void getParams_list(Node *methodParams, param_ param);

#endif
