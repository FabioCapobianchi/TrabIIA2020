#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define DEFAULT_TRYES 100;


int main(int argc, char **argv)
{
    init_rand();
    //psol ps = NULL;
    pdad pd = NULL;
    int mbf=0,bestmbf=0;
    int i,pop, sub, cont,tryes=0;
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
        printf("\nNome do ficheiro: ");
        gets(nome_fich);
        printf("\n\n");
      }
    }
     pd =init_dados(nome_fich, &pop, &sub, &cont);

    for(i=0;i<tryes;i++){

    gera_sol_inicial(pd, cont,pop,sub);

    mbf = formagrupos(pd, pop, sub,cont);
    if(mbf > bestmbf)
        bestmbf = mbf;
    }
    printf(" Melhor solucao encontrada: %d\n\n",bestmbf);
    free(pd);
    return 0;
}
