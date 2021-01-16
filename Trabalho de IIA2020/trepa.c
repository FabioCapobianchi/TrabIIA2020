#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "trepa.h"

int tc = 1;
// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
void setQs(){
tc = 1;
}

int trepacol(pdad a,int pop, int grupo,int ct){

int i,j=0,soma=0, somat=0;
int cc=0, ccr= 0, g=1;

  for(i=0;i<grupo;i++){
     printf(" Div(G%d) = ",g++);
     while(cc < pop/grupo){
        if(a[j].estado == 1){
            printf(" dist(%d,%d) ",a[j].x , a[j].y);
            soma+= a[j].dist;
            if(cc+1==pop/grupo){
                printf("= %d",soma);
                somat += soma;
                soma = 0;
            }else{
            printf("+");
            }
            cc++;
        }
       j++;
     }printf("\n");
     ccr = j;
     cc=0;

  }
  printf(" Qualidade(S%d)= %d\n\n",tc++,somat);

return somat;
}
