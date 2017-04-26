#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "sym_tab.h"

var_tab *symtab;

//Insere um novo identificador na cauda de uma lista ligada de simbolo
var_tab *insert_el(char *str, char *t)
{
  printf("Fodeu\n" );
	var_tab *newSymbol = (var_tab*) malloc(sizeof(var_tab));
	var_tab *aux;
	var_tab *previous;
  printf("Fodeu2\n" );
	strcpy(newSymbol->name, str);
  printf("Fodeu3\n" );
	strcpy(newSymbol->type, t);
	newSymbol->next = NULL;

  printf("Até aqui tudo sebem\n");
	if(symtab)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=symtab; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;

		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		symtab=newSymbol;

	return newSymbol;
}

void show_table()
{
  var_tab *aux;
  printf("\n");
  for(aux=symtab; aux; aux=aux->next)
	 printf("symbol %s, type %s\n", aux->name, aux->type);
}
