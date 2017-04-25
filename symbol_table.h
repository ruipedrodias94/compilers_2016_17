
/*Não sei se serão estes que usaremos*/
typedef enum {Bool, BoolLit, Double, DecLit, Id, Int, RealLit, StrLit, Void} var_type;

/*Estrutura de dados para a tabela de simbolos*/
typedef struct _tabela {
  char name[32];
  var_type type;
  struct _tabela *next;
} symbol_table;


table_element *insert_el(char *str, var_type t);
void show_table();
table_element *search_el(char *str);
