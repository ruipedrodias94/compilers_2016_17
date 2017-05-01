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
      aux->name = (char *)malloc(sizeof(char)+1);
      strcpy(aux->name, "");
      aux->type = (char *)malloc(sizeof(char)+1);
      strcpy(aux->type, "");
      aux->params = (char *)malloc(sizeof(char)+1);
      strcpy(aux->params, "");
      aux->node = NULL;
      aux->next = NULL;
    }
    return aux;
}

node_ insere_lista_nodes(node_ lista, char *name, char *type)
{
    node_ aux = lista;
    node_ novo_no = NULL;

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
    node_ aux = lista;
    node_ novo_no = NULL;

    while (aux -> next !=  NULL)
        aux = aux-> next;
    if ((novo_no = (node_) malloc (sizeof(node_)))!= NULL)
    {
      aux->name = (char *)malloc(sizeof(char) + strlen(name));
      strcpy(aux->name, name);
      aux->type = (char *)malloc(sizeof(char) + strlen(type));
      strcpy(aux->type, type);
      aux->params = (char *)malloc(sizeof(char) + strlen(params));
      strcpy(aux->params, "");
      aux->node = NULL;
      aux->next = NULL;
    }
    aux->next = novo_no;
    return lista;
}

void imprime_lista (node_ lista)
{
  node_ l = lista->next;
  while (l)
  {
    printf("%s \n", l->name);
    l=l->next;
  }
}
