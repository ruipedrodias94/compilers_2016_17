#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "sym_tab.h"

var_tab* symtab;
tab_of_tabs *tabela;

char *types[] = {"Class", "Method", "Global"};

/*Get Node Type*/
char *getTable_type(Table_type table_type){
  return types[table_type];
}

//Insere um novo identificador na cauda de uma lista ligada de simbolo
var_tab *insert_el(char *token, char *type, char *flags_params)
{
	var_tab *newSymbol1 = (var_tab*) malloc(sizeof(var_tab));
	var_tab *aux;
	var_tab *previous;
  newSymbol1->name = (char *)malloc(sizeof(char) + strlen(token));
	strcpy(newSymbol1->name, token);
  newSymbol1->type = (char *) malloc(sizeof(char)+strlen(type));
	strcpy(newSymbol1->type, type);
  newSymbol1->flags_params = (char *) malloc(sizeof(char)+strlen(flags_params));
  if (strcmp(flags_params, "NULL")) {
    newSymbol1->flags_params = NULL;
  }
  strcpy(newSymbol1->flags_params, flags_params);
	newSymbol1->next = NULL;

	if(symtab)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=symtab; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, token)==0)
				return NULL;
		previous->next=newSymbol1;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		symtab=newSymbol1;
	return newSymbol1;
}

tab_of_tabs *insert_el_header(char *token, Table_type table_type){
  tab_of_tabs *newSymbol = (tab_of_tabs*) malloc(sizeof(tab_of_tabs));
	tab_of_tabs *aux;
	tab_of_tabs *previous;
  newSymbol->header = (char*) malloc(sizeof(char)+strlen(token));
	strcpy(newSymbol->header, token);

  newSymbol->table_type = table_type;
  newSymbol->tabela = NULL;
	newSymbol->next = NULL;

	if(tabela)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=tabela; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->header, token)==0)
				return NULL;
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		tabela = newSymbol;
	return newSymbol;
}

void show_table()
{
  tab_of_tabs *aux;
  var_tab *aux2;
  printf("\n");
  for(aux=tabela; aux; aux=aux->next)
	  printf("===== %s %s Symbol Table =====\n", getTable_type(aux->table_type), aux->header);

    for (aux2 = tabela->tabela; aux2; aux2 = aux2->next) {
      printf("%s\t%s\n", aux2->name, aux2->type);
    }
}
