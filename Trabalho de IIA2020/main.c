#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "utils.h"

#define DEFAULT_TRYES 100;

int main(int argc, char **argv){

    init_rand();
    //psol ps = NULL;
    pdad pd = NULL;
    int mbf=0,bestmbf=0;
    int i, pop, sub, cont, menu, tryes=0, escolha=0;
    char nome_fich[15];

    system("cls");

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
        scanf("%s", nome_fich);
      }
    }

    do{
      menu = startMenu();
      switch (menu) {
        case 1:
          break;

        case 2:
        system("cls");
        if(escolha == 0){
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = formagrupos(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
<<<<<<< Updated upstream
          printf(" \t\t\t\t\t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestmbf);
          setQs();
=======
          printf("Melhor solucao encontrada: %d\n\n",bestmbf);
>>>>>>> Stashed changes
          free(pd);
        }else{
          puts("Lista de ficheiros existentes:\n");
          puts("\tn010.txt");
          puts("\tn012.txt");
          puts("\tn030.txt");
          puts("\tn060.txt");
          puts("\tn120.txt");
          puts("\tn240.txt\n");
          puts("\tInsira o nome do ficheiro:");
          scanf("%20s", nome_fich);
          printf("\tFicheiro seleccionado: %s\n", nome_fich);
          puts("(100 iterações por defeito)\nNúmero de iterações desejadas: \n");
          scanf("%d", &tryes);
<<<<<<< Updated upstream
          system("cls");
          printf("\t\t\t\t\t\t\t\t\tFicheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
=======
          system("clear");
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
>>>>>>> Stashed changes
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = formagrupos(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf("Melhor solucao encontrada: %d\n\n",bestmbf);
        }
          escolha = 1;
          break;

        case 3:
          system("cls");
          puts("\n\n\t\t\t\t\t\t\t\t******************************************************\n");
          printf("\n\t\t\t\t\t\t\t\t\t\t  Programa terminado!\n\n");
          puts("\n\t\t\t\t\t\t\t\t******************************************************");
          return 0;
          }
        }while (menu != 3);

        return 0;
      }
