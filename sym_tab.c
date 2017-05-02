#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_tab.h"


void imprime_lista (tab_ tabela)
{

  tab_ tab_aux = tabela;
  while (tab_aux!=NULL)
  {
    printf("===== %s %s Symbol Table ===== \n", tab_aux->type, tab_aux->name);


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
