#ifndef SYM_TAB_H
#define SYM_TAB_H

/*Implementação slides de PPP PQP*/

typedef struct lnode_ * node_;
typedef struct lnode_ {
  char *name;
  char *type;
  node_ next;
} _node;

typedef struct ltab_ * tab_;
typedef struct ltab_ {
  char *name;
  char *type;
  char *params;
  node_ node;
  tab_ next;
} _tab;

node_ cria_lista_nodes (void);
tab_ cria_lista_tab (void);
node_ insere_lista_nodes(node_ lista, char *name, char *type);
void imprime_lista (tab_ lista);
tab_ insere_lista_tab (tab_ lista, char *name, char *type, char *params, node_ node);
tab_ cria_tabela (char *name, char *params );

void add_global_symbol(tab_ t, char *name, char *type);

#endif
