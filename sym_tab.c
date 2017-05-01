#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_tab.h"

node_ cria_lista_nodes (void)
  {
    node_ aux;
    aux = (node_) malloc (sizeof (_node));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*2);
      strcpy(aux->name, "");
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, "");
      aux->next = NULL;
    }
    return aux;
}

tab_ cria_lista_tab (void)
  {
    tab_ aux;
    aux = (tab_) malloc (sizeof (_tab));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*2);
      strcpy(aux->name, "");
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, "");
      aux->params = (char *)malloc(sizeof(char)*2);
      strcpy(aux->params, "");
      aux->node = (node_) malloc(sizeof(_node));
      aux->next = NULL;
    }
    return aux;
}

node_ insere_lista_nodes(node_ lista, char *name, char *type)
{
    node_ aux = lista;
    node_ novo_no;

    while (aux -> next !=  NULL)
        aux = aux-> next;
    if ((novo_no = (node_) malloc (sizeof(node_)))!= NULL)
    {
        novo_no->name = (char*) malloc(strlen(name));
        novo_no->name = name;
        novo_no->type = (char*) malloc(strlen(type));
        novo_no->type = type;
        novo_no -> next = NULL;
    }
    aux->next = novo_no;
    return lista;
}

tab_ insere_lista_tab (tab_ lista, char *name, char *type, char *params, node_ node)
{
    tab_ aux = lista;
    tab_ novo_no = NULL;

    while (aux -> next !=  NULL)
        aux = aux-> next;

    if ((novo_no = (tab_) malloc (sizeof(tab_)))!= NULL)
    {

      novo_no->name = (char *)malloc(sizeof(char) + strlen(name));
      novo_no->name = name;
      novo_no->type = (char *)malloc(sizeof(char) + strlen(type));
      novo_no->type = type;
      novo_no->params = (char *)malloc(sizeof(char) + strlen(params));
      novo_no->node = (node_) malloc(sizeof(_node));
      novo_no->node = node;
      novo_no->next = NULL;
    }
    aux->next = novo_no;
    return lista;
}

void imprime_lista (tab_ lista)
{
  tab_ l = lista->next;
  while (l!=NULL)
  {
    printf("===== %s %s Symbol Table ===== \n", l->type, l->name);
    node_ aux = l->node;
    aux = aux->next;
    while(aux!=NULL)
    {
      printf("%s\t%s\t \n", aux->name, aux->type);
      aux = aux->next;
    }
    printf("\n");
    l=l->next;
  }
}

/*Fazer os métodos de obter os parâmetros*/

/*Fazer o método de meter os parametros com letra minuscula*/
