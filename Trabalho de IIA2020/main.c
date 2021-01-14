#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define DEFAULT_TRYES 10;

int main(int argc, char **argv){
  init_rand();
  psol ps = NULL;
  pdad pd = NULL;
  int pop, sub, cont;
    pdad pd = NULL;
    int pop, sub, cont, tryes;
    char nome_fich[10];
    if(argc == 3){
      tryes = atoi(argv[2]);
      strcpy(nome_fich, argv[1]);
    }
    else{
      if (argc == 2){
        tryes = DEFAULT_TRYES;
        strcpy(nome_fich, argv[1]);
      }
      else{
        tryes = DEFAULT_TRYES;
        printf("Nome do ficheiro:");
        gets(nome_fich);
      }
    }

    pd =init_dados(nome_fich, &pop, &sub, &cont);
      //ledados(pd,cont);
      gera_sol_inicial(pd, cont,pop,sub);
      //ledados(pd,cont);
      formagrupos(pd, pop, sub,cont);

    return 0;
}
