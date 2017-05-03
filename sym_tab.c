#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_tab.h"
#include "estruturas.h"
#include <ctype.h>


void imprime_lista (tab_ tabela)
{

  tab_ tab_aux = tabela;
  tab_ table_content;
  char * param_string = NULL;

  while (tab_aux!=NULL)
  {

    if(strcmp(tab_aux->type,"Class")==0){
    printf("===== %s %s Symbol Table ===== \n", tab_aux->type, tab_aux->name);
    table_content = tab_aux->node;
    while(table_content!=NULL)
    {
      if(strcmp(table_content->type,"Method")==0){
        if(table_content->param!=NULL)
        {
          printf("TEM PARAMS");

          strcpy(param_string,"(");
          param_ lista_param = table_content->param;
          while(lista_param!=NULL)
          {
              if(strcmp(lista_param->name,"args")==0)
              {
                printf("aqui");
                strcat(param_string,"String[]");
              }
              lista_param = lista_param->next;
          }
          strcat(param_string,")");
        }
      printf("%s\t%s\t%s\t%s\n",table_content->name,param_string,table_content->return_type,"");
    }
      table_content = table_content->next;
    }
    printf("\n");
  }
  tab_aux = tab_aux->next;
}
}


//Função que cria a primeira tabela que é sempre do tipo Class
tab_ cria_tabela (char *name, param_ params )
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

param_ cria_tabela_params (char *name, char *type)
  {
    param_ aux;
    aux = (tab_) malloc (sizeof (_tab));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*2);
      strcpy(aux->name, name);
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, type);
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
    strcpy(aux->type, toLoweCase(type));
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
param_ getParams_list(Node *methodParams) {
  param_ param_list = NULL;
  if (methodParams->node_type == type_MethodParams) {
    Node *paramDelc = methodParams->son;

    while (paramDelc != NULL) {
      if(paramDelc->node_type == type_ParamDecl){
      insert_in_params(param_list, paramDelc->son->brother->token, getNode_type(paramDelc->son->node_type));
    }
    paramDelc = paramDelc->brother;
  }
  }
return param_list;
}


void insert_in_params(param_ param_list,char *name, char *type) {
  param_ aux;
  aux = (param_) malloc (sizeof(_param));
  if(aux != NULL){
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, type);
    aux->next = NULL;
  }
  if(param_list == NULL)
  {
    param_list = aux;
  }
  else
  {
    param_ global = param_list;
    while(global->next!=NULL)
    {
      global = global->next;
    }
    global->next = aux;
  }


}

void add_global_method(tab_ tabela, char *name, char *type, char *return_type, param_ params)
{
  tab_ aux;
  aux =  (tab_) malloc (sizeof (_tab));
  if(aux != NULL)
  {
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, "Method");
    aux->param = params;
    aux->node = NULL;
    aux->return_type =  (char *)malloc(sizeof(char)*2);
    strcpy(aux->return_type, toLoweCase(return_type));
    aux->next = NULL;
  }

  if(tabela->node == NULL)
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

tab_ add_local_method_table(tab_ tabela, char *name, char *return_type)
{
  tab_ aux;
  aux =  (tab_) malloc (sizeof (_tab));
  if(aux != NULL)
  {
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, "Method");
    aux->param = NULL;
    aux->node = NULL;
    aux->return_type =  (char *)malloc(sizeof(char)*2);
    strcpy(aux->return_type, toLoweCase(return_type));
    aux->next = NULL;
  }

  if(tabela->next == NULL)
  {
    tabela->next = aux;
    return aux;
  }
  else
  {
    tab_ global = tabela->next;
    while(global->next!=NULL)
    {
      global = global->next;
    }
    global->next = aux;
    return aux;
  }
}

void add_local_symbol(tab_ tabela, char *name, char *type)
{
  tab_ aux;
  aux =  (tab_) malloc (sizeof (_tab));
  if(aux != NULL)
  {
    aux->name = (char *)malloc(sizeof(char)*2);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, type);
    aux->param = NULL;
    aux->node = NULL;
    aux->next = NULL;
  }
  if(tabela->node == NULL)
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






/*TO LOWER CASE*/
char *toLoweCase(char *string){
  char *aux = (char*) malloc (sizeof(char) + strlen(string));
  int i = 0;
  for ( i = 0; string[i]; i++) {
    aux[i] = tolower(string[i]);
  }
  return aux;
}
