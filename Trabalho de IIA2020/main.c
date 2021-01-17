#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "utils.h"
#include "trepac.h"
#define DEFAULT_TRYES 100;


int main(int argc, char **argv){

    init_rand();
    //psol ps = NULL;
    pdad pd = NULL;
    int mbf=0,bestmbf=0,bestbest = 0;
    int i, ale, pop, sub, viz, cont, menu, tryes=0, escolha=0;
    int flag=0;
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
        printf("\n\t\t\t\t\tNome do ficheiro: ");
        scanf("%s", nome_fich);
      }
    }

    do{
      menu = startMenu();
      switch (menu) {

case 1://TREPA COLINAS COM 2 VIZINHOS
         system("cls");
         if(escolha == 0){

          printf("\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          printf("\t\t\t\tEscolha a quantidade de vizinhos a aceitar com pior qualidade: ");
          scanf("%d",&viz);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == viz+1){
                      printf(" \t\t\t\tMelhor solucao encontrada com vizinhanca '%d': %d\n\n",viz,bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf >= bestmbf){
               bestbest = bestmbf = mbf;
                flag = 0;
              }else if(mbf < bestmbf && flag < viz+1)
                bestmbf = mbf;
              flag += 1;
            }
            flag = 0;

          setQs();
          free(pd);
          mbf = 0;
        }else{
          puts("\t\t\tLista de ficheiros existentes:\n");
          puts("\t\t\t\t\tn010.txt");
          puts("\t\t\t\t\tn012.txt");
          puts("\t\t\t\t\tn030.txt");
          puts("\t\t\t\t\tn060.txt");
          puts("\t\t\t\t\tn120.txt");
          puts("\t\t\t\t\tn240.txt\n");
          puts("\t\t\t\t\tInsira o nome do ficheiro:");
          scanf("%20s", nome_fich);
          printf("\t\t\t\t\tFicheiro seleccionado: %s\n", nome_fich);
          puts("\t\t\t\t\t(100 iteracoes por defeito)\n\t\t\t\t\tNumero de iteracoes desejadas? : \n");
          printf("\t\t\t\t\tDigite '0' para default: \n");
          scanf("%d", &tryes);
          if(tryes == 0){
            tryes = 100;
          }
          system("cls");
           printf("\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          printf("\t\t\t\tEscolha a quantidade de vizinhos a aceitar com pior qualidade: ");
          scanf("%d",&viz);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == viz+1){
                      printf(" \t\t\t\tMelhor solucao encontrada com vizinhanca '%d': %d\n\n",viz,bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf >= bestmbf){
               bestbest = bestmbf = mbf;
                flag = 0;
              }else if(mbf < bestmbf && flag < viz+1)
                bestmbf = mbf;
              flag += 1;
            }
            flag = 0;

          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;
          break;

case 2: //TREPA COLINAS PROB 50% DE ACEITAR SOLUÇÃO PIOR
        system("cls");
        if(escolha == 0){

          printf("\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == 3){
                      printf(" \t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf >= bestmbf){
               bestbest = bestmbf = mbf;
                flag = 0;
                ale = random_l_h(0,1);
              }else if(mbf < bestmbf && flag < 3)
              if(ale == 1){
                bestmbf = mbf;
                flag += 1;
              }
            }
          flag = 0;
          setQs();
          free(pd);
          mbf = 0;
        }else{
          puts("\t\t\t\t\tLista de ficheiros existentes:\n");
          puts("\t\t\t\t\tn010.txt");
          puts("\t\t\t\t\tn012.txt");
          puts("\t\t\t\t\tn030.txt");
          puts("\t\t\t\t\tn060.txt");
          puts("\t\t\t\t\tn120.txt");
          puts("\t\t\t\t\tn240.txt\n");
          puts("\t\t\tInsira o nome do ficheiro:");
          scanf("%20s", nome_fich);
          printf("\t\t\t\t\tFicheiro seleccionado: %s\n", nome_fich);
          puts("\t\t\t\t\t(100 iteracoes por defeito)\n\t\t\t\t\tNumero de iteracoes desejadas? : \n");
          printf("\t\t\t\t\tDigite '0' para default: \n");
          scanf("%d", &tryes);
          if(tryes == 0){
            tryes = 100;
          }
          system("cls");
          printf("\t\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);

           pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
                  if(flag == 3){
                      printf(" \t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestbest);
                 break;
              }
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf >= bestmbf){
          bestbest = bestmbf = mbf;
                flag = 0;
                ale = random_l_h(0,1);
              }else if(mbf < bestmbf && flag < 3)
              if(ale == 1){
                bestmbf = mbf;
                flag += 1;
              }
            }
          if(flag != 3){
                      printf(" \t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestbest);
              }
          flag = 0;
          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;

          break;

case 3: //encontra a melhor solucao entre um numero de interacoes
        system("cls");
        if(escolha == 0){
          printf("\t\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf(" \t\t\t\t\t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestmbf);
          setQs();
          free(pd);
          mbf = 0;;
        }else{
          puts("\t\t\t\t\tLista de ficheiros existentes:\n");
          puts("\t\t\t\t\tn010.txt");
          puts("\t\t\t\t\tn012.txt");
          puts("\t\t\t\t\tn030.txt");
          puts("\t\t\t\t\tn060.txt");
          puts("\t\t\t\t\tn120.txt");
          puts("\t\t\t\t\tn240.txt\n");
          puts("\t\t\t\t\tInsira o nome do ficheiro:");
          scanf("%20s", nome_fich);
          printf("\t\t\t\t\tFicheiro seleccionado: %s\n", nome_fich);
          puts("\t\t\t\t\t(100 iteracoes por defeito)\n\t\t\t\t\tNumero de iteracoes desejadas? : \n");
          printf("\t\t\t\t\tDigite '0' para default: \n");
          scanf("%d", &tryes);
          if(tryes == 0){
            tryes = 100;
          }
          system("cls");
          printf("\t\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          printf(" \t\t\t\t\tMelhor solucao encontrada: %d\n\n",bestmbf);
          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;
          break;

        case 4:
          system("cls");
          puts("\n\n\t\t\t\t******************************************************\n");
          printf("\n\t\t\t\t\t\t  Programa terminado!\n\n");
          puts("\n\t\t\t\t******************************************************");
          return 0;
          }
        }while (menu != 4);

        return 0;
      }
