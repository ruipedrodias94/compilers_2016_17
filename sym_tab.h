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
  char *flag;
  param_ param;
  tab_ node;
  tab_ next;
} _tab;

tab_ cria_tabela (char *name, param_ params );
char* get_param_string(tab_ table_content);
void add_global_symbol(tab_ tabela, char *name, char *type);
void add_global_method(tab_ tabela, char *name, char *type, char *return_type, param_ params);
tab_ add_local_method_table(tab_ tabela, char *name, char *return_type, param_ params);
void add_local_symbol(tab_ tabela, char *name, char *type, char *flag);
void insere_params_symbol_list(tab_ tabela, param_ list);
void imprime_lista (tab_ tabela);
void insert_in_params(param_ param_list,char *name, char *type);
param_ getParams_list(Node *methodParams);
char *toLoweCase(char *string);
char* concat(const char *s1, const char *s2);
param_ cria_tabela_params ();
int getNumberOfParams(Node *paramDelc);
void imprime_params(param_ tab);
tab_ get_local_table( char *method_name, tab_ tabela_global);
char* get_type_var(char * name,tab_ tabela_global, tab_ tabela_local);
char* get_type_var_global(char *name, tab_ tabela);
char* get_return_type_method_global(char *name, tab_ tabela);
char* get_param_string_on_tree(Node *call, tab_ tabela_global, tab_ tabela_local);
#endif
