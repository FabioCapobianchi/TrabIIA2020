#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <Windows.h>
#include "utils.h"
#include "trepa.h"
#define DEFAULT_TRYES 100;


int main(int argc, char **argv){

    init_rand();
    //psol ps = NULL;
    pdad pd = NULL;
    int mbf=0, bestmbf=0, bestbest = 0;
    int i, pop, sub, cont, menu, res_trepa, tryes=0, escolha=0;
    int flag=0;
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
        printf("\nNome do ficheiro: ");
        scanf("%s", nome_fich);
      }
    }

    do{
      menu = startMenu();
      switch (menu) {
        case 1: //Algoritmo genético com vizinhança 2

        system("clear");
        if(escolha == 0){

          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == 3){
                      printf("Melhor solucao encontrada: %d\n\n",bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop, sub);
            mbf = genetico(pd, pop, sub, cont);
              if(mbf >= bestmbf){
               bestbest = bestmbf = mbf;
                flag = 0;
              }else if(mbf < bestmbf && flag < 3)
              bestmbf = mbf;
              flag += 1;
            }
            flag = 0;

          setQs();
          free(pd);
          mbf = 0;
        }else{
          imprime_fileList();
          scanf("%20s", nome_fich);
          printf("Ficheiro seleccionado: %s\n", nome_fich);
          puts("(100 iterações por defeito)\nNúmero de iterações desejadas: \n");
          scanf("%d", &tryes);
          system("clear");
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
           pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == 3){
                      printf("Melhor solucao encontrada: %d\n\n",bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf >= bestmbf){
          bestbest = bestmbf = mbf;
                flag = 0;
              }else if(mbf < bestmbf && flag < 3)
              bestmbf = mbf;
              flag += 1;
            }
            flag = 0;

          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;
 //Trepa-colinas com vizinhança 2
          break;

        case 2: //Algoritmo genético com vizinhança 1
        system("clear");
        if(escolha == 0){
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop, sub);
            mbf = genetico(pd, pop, sub, cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf("Melhor solucao encontrada: %d\n\n",bestmbf);
          setQs();
          free(pd);
        }else{
          imprime_fileList();
          scanf("%20s", nome_fich);
          printf("Ficheiro seleccionado: %s\n", nome_fich);
          puts("(100 iterações por defeito)\nNúmero de iterações desejadas: \n");
          scanf("%d", &tryes);
          system("clear");
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf("Melhor solucao encontrada: %d\n\n",bestmbf);
        }
          escolha = 1;
          break;

        case 3:
        system("clear");
        if(escolha == 0){
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop, sub);
            mbf = trepa(pd, pop, sub, res_trepa);
            }
          printf("Melhor solucao encontrada: %d\n\n", mbf);
          free(pd);
        }else{
          imprime_fileList();
          scanf("%20s", nome_fich);
          printf("Ficheiro seleccionado: %s\n", nome_fich);
          puts("(100 iterações por defeito)\nNúmero de iterações desejadas: \n");
          scanf("%d", &tryes);
          system("clear");
          printf("Ficheiro seleccionado: %s, com %d iterações.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop, sub);
            mbf = trepa(pd, pop, cont, res_trepa);
            }
          printf("Melhor solucao encontrada: %d\n\n",mbf);
        }
          escolha = 1;
          break;

        case 4:
          break;

        case 5: //Termina programa
          system("clear");
          puts("\n\n\t\t\t\t\t\t\t\t******************************************************\n");
          printf("\n\t\t\t\t\t\t\t\t\t\t  Programa terminado!\n\n");
          puts("\n\t\t\t\t\t\t\t\t******************************************************");
          return 0;
          }
        }while (menu != 5);

        return 0;
      }
