#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "utils.h"
#define DEFAULT_TRYES 100;


int main(int argc, char **argv){

    init_rand();
    //psol ps = NULL;
    pdad pd = NULL;
    int mbf=0,bestmbf=0;
    int i, pop, sub, cont, menu, me, tryes=0, escolha=0;
    char nome_fich[15];

    system("clear");

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
        printf("\n\t\t\t\t\t\t\t\t\tNome do ficheiro: ");
        scanf("%s", nome_fich);
      }
    }

    do{
      menu = startMenu();
      switch (menu) {
        case 1:
          break;

        case 2:
        system("clear");
        if(escolha == 0){
          printf("\t\t\t\t\t\t\t\t\tFicheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = formagrupos(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf(" \t\t\t\t\t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestmbf);
          free(pd);
        }else{
          puts("\t\t\t\t\t\t\t\t\tLista de ficheiros existentes:\n");
          puts("\t\t\t\t\t\t\t\t\tn010.txt");
          puts("\t\t\t\t\t\t\t\t\tn012.txt");
          puts("\t\t\t\t\t\t\t\t\tn030.txt");
          puts("\t\t\t\t\t\t\t\t\tn060.txt");
          puts("\t\t\t\t\t\t\t\t\tn120.txt");
          puts("\t\t\t\t\t\t\t\t\tn240.txt\n");
          puts("\t\t\t\t\t\t\t\t\tInsira o nome do ficheiro:");
          scanf("%20s", nome_fich);
          printf("\t\t\t\t\t\t\t\t\tFicheiro seleccionado: %s\n", nome_fich);
          puts("\t\t\t\t\t\t\t\t\t(100 iterações por defeito)\n\t\t\t\t\t\t\t\t\tNúmero de iterações desejadas: \n");
          scanf("%d", &tryes);
          system("clear");
          printf("\t\t\t\t\t\t\t\t\tFicheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = formagrupos(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf(" \t\t\t\t\t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestmbf);
        }
          escolha = 1;
          break;

        case 3:
          system("clear");
          puts("\n\n\t\t\t\t\t\t\t\t******************************************************\n");
          printf("\n\t\t\t\t\t\t\t\t\t\t  Programa terminado!\n\n");
          puts("\n\t\t\t\t\t\t\t\t******************************************************");
          return 0;
          }
        }while (menu != 3);

        return 0;
      }
