#ifndef SYM_TAB_H
#define SYM_TAB_H

/*Tabela de simbolos*/

typedef struct var_tab1 {
  char *name;
  char *type;
  struct var_tab1 *next;

} var_tab;

var_tab *insert_el(char *str, char *t);
void show_table();

#endif
