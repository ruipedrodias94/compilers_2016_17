#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_tab.h"
#include "estruturas.h"
#include <ctype.h>

char* get_param_string(tab_ table_content)
{
   char *param_string = "";

  //ir buscar os parametros
  param_ aux = table_content->param->next;
  int count = 1;
  if(aux!=NULL){
  while(aux!=NULL){
    if(count>1)
      {
        param_string = concat(param_string,",");
      }
      if(strcmp(aux->type,"bool")==0)
      {
        param_string = concat(param_string,"boolean");
      }
      else{
      param_string = concat(param_string,aux->type);
    }

  count++;
  aux = aux->next;
}
param_string = concat("(",param_string);
param_string = concat(param_string,")");

return param_string;
}else{
  return "()";
}
}

void imprime_lista (tab_ tabela)
{

  tab_ tab_aux = tabela;
  tab_ table_content;

  while (tab_aux!=NULL)
  {

    if(strcmp(tab_aux->type,"Class")==0){

    printf("===== %s %s Symbol Table =====\n", tab_aux->type, tab_aux->name);
    table_content = tab_aux->node;

    while(table_content!=NULL)
    {
       char *param_string = "";
        if(strcmp(table_content->type,"Method")==0){
        param_string = get_param_string(table_content);
        printf("%s\t%s\t%s%s\n",table_content->name,param_string,table_content->return_type,"");
      }
      else{
        printf("%s\t%s\t%s%s\n",table_content->name,"",table_content->type,"");
      }

      table_content = table_content->next;
  }
  }else
  {
    table_content = tab_aux->node;
    //char *param_s  = "";
    char *param_s  = get_param_string(tab_aux);
    printf("===== %s %s%s Symbol Table =====\n", tab_aux->type, tab_aux->name,param_s);

    while(table_content!=NULL)
    {
      char *flag;
      if(strcmp(table_content->flag,"")!=0){
      flag = table_content->flag;
      flag = concat("\t",flag);
      }
      else{
        flag = "";
      }
      printf("%s\t%s\t%s%s\n",table_content->name,"",table_content->type,flag);
      table_content = table_content->next;
    }

  }

    printf("\n");
  tab_aux = tab_aux->next;
  }
}


//Função que cria a primeira tabela que é sempre do tipo Class
tab_ cria_tabela (char *name, param_ params )
  {
    tab_ aux;
    aux = (tab_) malloc (sizeof (_tab));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*strlen(name)+1);
      strcpy(aux->name, name);
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, "Class");
      aux->param = params;
      aux->node = NULL;
      aux->next = NULL;
    }
    return aux;
}

param_ cria_tabela_params ()
  {
    param_ aux;
    aux = (param_) malloc (sizeof (_param));
    if (aux != NULL) {
      aux->name = (char *)malloc(sizeof(char)*3);
      strcpy(aux->name, "header");
      aux->type = (char *)malloc(sizeof(char)*2);
      strcpy(aux->type, "");
      aux->next = NULL;
    }
    return aux;
}

void add_global_symbol(tab_ tabela, char *name, char *type)
{
  tab_ aux;
  aux = (tab_) malloc (sizeof (_tab));
  if (aux != NULL) {
    aux->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    if(strcmp(type,"String[]")==0){
    strcpy(aux->type, type);}
    else if(strcmp(type,"Bool")==0)
    {
      strcpy(aux->type, "boolean");
    }
    else
    {
        strcpy(aux->type, toLoweCase(type));

    }
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

int getNumberOfParams(Node *paramDelc){
  int i = 0;
  if (paramDelc->node_type == type_ParamDecl) {
    while (paramDelc != NULL) {
      if (paramDelc->node_type == type_ParamDecl) {
        i += 1;
      }
      paramDelc = paramDelc->brother;
    }
  }
  return i;
}

/*Função que recebe um no type_MethodParams e retorna uma lista ligada de parametros*/

param_ getParams_list(Node *paramDelc) {
  param_ param_list = cria_tabela_params();
  Node *aux = paramDelc;

  if (aux != NULL) {
    if (aux->node_type == type_ParamDecl) {
      while (aux != NULL) {
        if(aux->node_type == type_ParamDecl){
          insert_in_params(param_list, aux->son->brother->token, getNode_type(aux->son->node_type));
        }
        aux = aux->brother;
      }
    }
  }
  return param_list;
}

void imprime_params(param_ tab){
  param_ aux = tab;
  aux = aux->next;
  while (aux!=NULL) {
    printf("TESTE: %s TESTE: %s\n", aux->name, aux->type);
    aux = aux->next;
  }
}
void insere_params_symbol_list(tab_ tabela, param_ list)
{
  param_ aux = list;
  aux = aux->next;
  while (aux!=NULL) {
    add_local_symbol(tabela,aux->name, aux->type,"param");
    aux = aux->next;
  }
}


void insert_in_params(param_ param_list, char *name, char *type) {
  param_ aux;
  aux = (param_) malloc (sizeof(_param));
  if(aux != NULL){
    aux->name = (char *)malloc(sizeof(char)*2 + strlen(name)+1);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2 + strlen(type)+1);
    if (strcmp(type, "StringArray") == 0) {
      strcpy(aux->type, "String[]");
    }
    else if(strcmp(type,"Bool")==0)
    {
      strcpy(aux->type, "boolean");
    }
    else {
        strcpy(aux->type, toLoweCase(type));
    }
    aux->next = NULL;
  }

  if(param_list==NULL)
  {
    param_list = aux;
  }
  else{
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
    aux->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, "Method");
    aux->param = params;
    aux->node = NULL;
    aux->return_type =  (char *)malloc(sizeof(char)*2);
    if(strcmp(type,"String[]")==0){
    strcpy(aux->return_type, return_type);}
    else if(strcmp(return_type,"Bool")==0)
    {
      strcpy(aux->return_type, "boolean");
    }
    else
    {
        strcpy(aux->return_type, toLoweCase(return_type));

    }
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

tab_ add_local_method_table(tab_ tabela, char *name, char *return_type, param_ params)
{
  tab_ aux;
  aux =  (tab_) malloc (sizeof (_tab));
  if(aux != NULL)
  {
    aux->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    strcpy(aux->type, "Method");
    aux->param = params;
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

void add_local_symbol(tab_ tabela, char *name, char *type, char *flag)
{
  tab_ aux;
  aux =  (tab_) malloc (sizeof (_tab));
  if(aux != NULL)
  {
    aux->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(aux->name, name);
    aux->type = (char *)malloc(sizeof(char)*2);
    if(strcmp(type,"String[]")==0){
    strcpy(aux->type, type);}
    else if(strcmp(type,"Bool")==0)
    {
      strcpy(aux->type, "boolean");
    }
    else
    {
        strcpy(aux->type, toLoweCase(type));
    }
    aux->flag = (char *)malloc(sizeof(char)*2);
    strcpy(aux->flag, flag);
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

/*função para ir buscar os tipos de variaveis globais à tabela*/
char* get_type_var_global(char *name, tab_ tabela)
{
  tab_ tab_aux = tabela;
  tab_ table_content;



  if(strcmp(tab_aux->type,"Class")==0)
  {
      table_content = tab_aux->node;
      while(table_content!=NULL)
      {
        if(strcmp("Method",table_content->type)!=0){
          if(strcmp(name,table_content->name)==0){
        return table_content->type;
      }
    }
      table_content = table_content->next;
    }
}
return "";

}

char* get_type_var_local(char *name, tab_ tabela)
{
  tab_ tab_aux = tabela;
  tab_ table_content;


/*função para ir buscar os tipos de variaveis locais à tabela*/
      table_content = tab_aux->node;
      while(table_content!=NULL)
      {
        if(strcmp("Method",table_content->type)!=0){

          if(strcmp(name,table_content->name)==0){
        return table_content->type;
      }
    }
      table_content = table_content->next;
    }
return "";

}


void print_table(tab_ tabela)
{
  tab_ table_content = tabela->node;
  while(table_content!=NULL)
  {
    if(strcmp("Method",table_content->type)!=0){

    }
      table_content = table_content->next;
  }

}
/*funcao apra ir buscar a tabela local*/
//tem de ser alterada porque duas funçoes podem ter nomes iguais mar numero de argumentos diferentes
tab_ get_local_table( char *method_name, tab_ tabela_global)
{
  tab_ tab_aux = tabela_global;

  while(tab_aux!=NULL)
  {
    if(strcmp(tab_aux->name,method_name)==0)
    {
      return tab_aux;
    }
    tab_aux=tab_aux->next;
  }
  return NULL;

}

char* get_type_var(char * name,tab_ tabela_global, tab_ tabela_local){
print_table(tabela_local);
print_table(tabela_global);


  if(strcmp(get_type_var_local(name, tabela_local),"")!=0)
  {
    return get_type_var_local(name, tabela_local);
  }
  else if(strcmp(get_type_var_global(name, tabela_global),"")!=0)
  {
    return get_type_var_global(name, tabela_global);
  }
  else{
    return "";
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

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
