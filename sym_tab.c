#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_tab.h"


void imprime_lista (tab_ tabela)
{

  tab_ tab_aux = tabela;
  tab_ table_content;
  while (tab_aux!=NULL)
  {
    printf("===== %s %s Symbol Table ===== \n", tab_aux->type, tab_aux->name);
    table_content = tab_aux->node;
    while(table_content!=NULL)
    {
      printf("%s\t%s\t\n",table_content->name,table_content->type);
      table_content = table_content->next;
    }
    printf("\n");
    tab_aux = tab_aux->next;
  }
}


//Função que cria a primeira tabela que é sempre do tipo Class
tab_ cria_tabela (char *name, param_ *params )
  {
    tab_ aux;
    aux = (tab_) malloc (sizeof (_tab));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*2);
      strcpy(aux->name, name);
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, "Class");
      aux->param = params;
      aux->node = NULL;
      aux->next = NULL;
    }
    return aux;
}

void add_global_symbol(tab_ tabela, char *name, char *type)
{
  tab_ aux;
  aux = (tab_) malloc (sizeof (_tab));
  if (aux != NULL) {
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, type);
    aux->param = NULL;
    aux->node = NULL;
    aux->next = NULL;
  }
  if(tabela->node==NULL)
  {
    tabela->node = aux;
  }
  else
  {
    tab_ global = tabela->node;
    while(global->next!=NULL)
    {
      global = global->next;
    }
    global->next = aux;
  }
}


/*Função que recebe um no type_MethodParams e retorna uma lista ligada de parametros*/
void getParams_list(Node *methodParams, param_ param) {
  if (methodParams->node_type == type_MethodParams) {
    /*O filho será ParamDelc*/
    Node *paramDelc = methodParams->son;
    while (paramDelc != NULL) {
      /*Esta merda esta mal, tem que retorar uma merda que nao sei o que xD*/
      insert_in_params(parm, paramDelc->brother->token, getNode_type(paramDelc->node_type));
      paramDelc = paramDelc->brother;
    }
  }
}

/*Função para inserir na lista ligada de parametros*/
param_ insert_in_params(param_ param, char *name, char *type) {
  param_ aux;
  aux = (param_) malloc (sizeof(param_));
  if (aux != NULL) {
    aux = aux->next;
  }
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, type);
    aux->next = NULL;
    return aux;
}
