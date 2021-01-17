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
    int mbf = 0, mbf_aux = 0, bestmbf = 0, bestbest = 0, max_val = 0;
    int i, ale, pop, sub, viz, cont, menu;
    int flag = 0, tryes = 0, escolha = 0;
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
        printf("\n\t\t\t\t\tNome do ficheiro: ");
        scanf("%s", nome_fich);
      }
    }

    do{
      menu = startMenu();
      switch (menu) {

case 1://TREPA COLINAS COM 2 VIZINHOS
      system("clear");
        if(escolha == 0){

        printf("Ficheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
        printf("Escolha a quantidade de vizinhos a aceitar com pior qualidade: ");
        scanf("%d",&viz);
        pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            if(flag == viz+1){
              puts("\n\n******************************************************\n");
              printf("\tMelhor solucao encontrada: '%d': %d",viz, bestbest);
              puts("\n\n******************************************************\n");
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
      imprimeFileList();
      scanf("%20s", nome_fich);
      printf("Ficheiro seleccionado: %s\n", nome_fich);
      puts("(100 iteracoes por defeito)\nNumero de iteracoes desejadas? : \n");
      printf("Digite '0' para default: ");
      scanf("%d", &tryes);
        if(tryes == 0){
          tryes = 100;
          }
      system("clear");
      printf("\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
      printf("\t\t\t\tEscolha a quantidade de vizinhos a aceitar com pior qualidade: ");
      scanf("%d",&viz);
      pd = init_dados(nome_fich, &pop, &sub, &cont);
        for(i=0;i<tryes;i++){
          if(flag == viz+1){
            puts("\n\n******************************************************\n");
            printf("\tMelhor solucao encontrada: '%d': %d",viz, bestbest);
            puts("\n******************************************************\n");
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
      system("clear");
        if(escolha == 0){
          printf("Ficheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
            for(i=0;i<tryes;i++){
              if(flag == 3){
                puts("\n\n******************************************************\n");
                printf("\tMelhor solucao encontrada: %d",bestbest);
                puts("\n\n******************************************************\n");
                break;
            }
        gera_sol_inicial(pd, cont, pop,sub);
        mbf = genetico(pd, pop, sub,cont);
          if(mbf >= bestmbf){
            bestbest = bestmbf = mbf;
            flag = 0;
            }else if(mbf < bestmbf && flag < 3)
            ale = random_l_h(0,1);
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
          imprimeFileList();
          scanf("%20s", nome_fich);
          printf("Ficheiro seleccionado: %s\n", nome_fich);
          puts("(100 iteracoes por defeito)\nNumero de iteracoes desejadas? : \n");
          printf("Digite '0' para default: ");
          scanf("%d", &tryes);
          if(tryes == 0){
            tryes = 100;
          }
      system("clear");
      printf("\t\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);

      pd = init_dados(nome_fich, &pop, &sub, &cont);
        for(i=0;i<tryes;i++){
          if(flag == 3){
            puts("\n\n******************************************************\n");
            printf("\tMelhor solucao encontrada: %d",bestbest);
            puts("\n\n******************************************************\n");
           break;
          }
      gera_sol_inicial(pd, cont, pop,sub);
      mbf = genetico(pd, pop, sub,cont);
        if(mbf >= bestmbf){
          bestbest = bestmbf = mbf;
          flag = 0;
        }else if(mbf < bestmbf && flag < 3)
          ale = random_l_h(0,1);
            if(ale == 1){
              bestmbf = mbf;
              flag += 1;
              }
            }
          if(flag != 3){
            puts("\n\n******************************************************\n");
            printf("\tMelhor solucao encontrada: %d", bestbest);
            puts("\n\n******************************************************\n");
              }
          flag = 0;
          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;

          break;

case 3: //encontra a melhor solucao entre um numero de interacoes
        system("clear");
        if(escolha == 0){
          printf("Ficheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
            puts("\n\n******************************************************\n");
            printf("\tMelhor solucao encontrada: %d", bestmbf);
            puts("\n\n******************************************************\n");
          setQs();
          free(pd);
          mbf = 0;;
        }else{
          imprimeFileList();
          scanf("%20s", nome_fich);
          printf("Ficheiro seleccionado: %s\n", nome_fich);
          puts("(100 iteracoes por defeito)\nNumero de iteracoes desejadas? : \n");
          printf("Digite '0' para default: ");
          scanf("%d", &tryes);
          if(tryes == 0){
            tryes = 100;
          }
          system("clear");
          printf("Ficheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
          pd = init_dados(nome_fich, &pop, &sub, &cont);
          for(i=0;i<tryes;i++){
            gera_sol_inicial(pd, cont, pop,sub);
            mbf = genetico(pd, pop, sub,cont);
              if(mbf > bestmbf){
                bestmbf = mbf;
              }
            }
          puts("\n\n******************************************************\n");
          printf("\tMelhor solucao encontrada: %d", bestmbf);
          puts("\n\n******************************************************\n");
          setQs();
          free(pd);
          mbf = 0;
        }
          escolha = 1;
          break;

case 4: //Pesquisa hibrida
system("clear");

  if(escolha == 0){
    printf("Ficheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
    pd = init_dados(nome_fich, &pop, &sub, &cont);
      for(i=0;i<tryes;i++){
        if(flag == 3 && mbf<=bestbest){
          puts("\n\n******************************************************\n");
          printf("\tMelhor solucao encontrada: %d",bestbest);
          puts("\n\n******************************************************\n");
      }
  gera_sol_inicial(pd, cont, pop,sub);
  mbf = genetico(pd, pop, sub,cont);
    if(mbf <= bestmbf){
      bestbest = bestmbf = mbf;
      flag = 0;
      }else if(mbf < bestmbf && flag < 3)
      ale = random_l_h(0,1);
        if(ale == 1){
        bestmbf = mbf;
        flag += 1;
      }
    }
  flag = 0;
  setQs();
  }else{
    imprimeFileList();
    scanf("%s", nome_fich);
    printf("Ficheiro seleccionado: %s\n", nome_fich);
    puts("(100 iteracoes por defeito)\nNumero de iteracoes desejadas? : \n");
    printf("Digite '0' para default: ");
    scanf("%d", &tryes);
    if(tryes == 0){
      tryes = 100;
    }
system("clear");
printf("\t\t\t\t\tFicheiro seleccionado: %s, com %d iteracoes.\n\n", nome_fich, tryes);
do{
//  pd = init_dados(nome_fich, &pop, &sub, &cont);
  mbf_aux = genetico(pd, pop, sub,cont);
    if(mbf_aux >= bestmbf){
      bestbest = bestmbf = mbf_aux;
      flag = 0;
    }else if(mbf_aux < bestmbf && flag < 3)
      ale = random_l_h(0,1);
        if(ale == 1){
          bestmbf = mbf_aux;
          flag += 1;
        }
      mbf_aux = genetico(pd, pop, sub,cont);
        if(mbf_aux > bestmbf){
          bestmbf = mbf_aux;
        }

  }while (bestbest < bestmbf);
    puts("\n\n******************************************************\n");
    printf("\tMelhor solucao encontrada: %d", mbf_aux);
    puts("\n\n******************************************************\n");
    }
    free(pd);
    flag = 0;
    mbf = 0;
    mbf_aux = 0;
    escolha = 1;
    break;
case 5:
        system("clear");
        puts("\n\n******************************************************\n");
        printf("\n\t\t  Programa terminado!\n\n");
        puts("\n******************************************************");
          return 0;
}
    }while (menu != 5);

return 0;
}
