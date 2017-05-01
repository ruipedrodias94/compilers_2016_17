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
node_ insere_lista_nodes(node_ lista, char *name, char *type);
void imprime_lista (node_ lista);

#endif
