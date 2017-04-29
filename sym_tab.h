#ifndef SYM_TAB_H
#define SYM_TAB_H

/*Tabela de simbolos*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*A minha ideia seria criar dois tipos de tabelas
- Program, que vai gerar a tabela do tipo Class Symbol Table
- Method, que vai gerar a tabela do tipo Symbol Table*/
typedef enum {type_Class, type_Method, type_Global_Var} Table_type;

typedef struct var_tab1 {
  char *name;
  char *type;
  char *flags_params;
  struct var_tab1 *next;
} var_tab;

/*Lista de listas, para que possamos ter uma lista de tabelas.*/
/*Ainda nao pensei isto a fundo, ainda estou a ver como poderei aprofundar isto*/
typedef struct tab_of_tabs1 {
  char *header;
  var_tab *tabela;
  Table_type table_type;
  struct tab_of_tabs1 *next;
}tab_of_tabs;


var_tab *insert_el(char *token, char *type, char *flags_params);
void show_table();
tab_of_tabs *insert_el_header(char *token, Table_type table_type);
char *getTable_type(Table_type table_type);

#endif
