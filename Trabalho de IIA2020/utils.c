#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


int qs = 1;

void setQs(){
qs = 1;
}

dad* init_dados(char *nome, int *ele, int *grupo,int *ctd)
{
	FILE *fi;
	dad *p, *p1 = NULL;
	int i=0,ct=0;
    char st[1000];

	fi=fopen(nome, "r");
	if(!fi)
	{
		puts("\n\n\t\t\t\t\t******************************************************\n");
		printf("\t\t\t\t\t\t Erro no acesso ao ficheiro dos dados\n");
		puts("\n\n\t\t\t\t\t******************************************************\n");
		exit(1);
	}
	 p1 = malloc(sizeof(dad)*1);

    fscanf(fi, "%d %d %[^\n]",ele,grupo, st);
	printf(" Elementos: %d grupos: %d \n\n",*ele,*grupo);

	while(fscanf(fi,"%d %d %d",&p1[ct].x,&p1[ct].y,&p1[ct].dist)==3){
       ct++;
       p1[i++].estado = 0;
        p = realloc(p1,sizeof(dad)*(ct+1));

        if(p == NULL)
        {
            printf(" *** Erro de alocacao.txt ***");
            return p;
        }
        p1 = p;
	}
    *ctd = ct;

	fclose(fi);
	return p1;
}
// Gera a solucao inicial
// Parametros: solucao, numero de vertices
void gera_sol_inicial(pdad solu, int v,int grp,int subg)
{
	int i, x;

	for(i=0; i<v; i++)
        solu[i].estado = 0;
	for(i=0; i<grp; i++)
    {
        do
			x = random_l_h(0, v-1);
        while(solu[x].estado != 0);
        solu[x].estado=1;
    }
}

int genetico(pdad a,int pop, int grupo,int ct){

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
  printf(" Qualidade(S%d)= %d\n\n",qs++,somat);

return somat;
}

void ledados(pdad p,int ctd){

   int i;
   printf("ctd: %d\n",ctd);
   for(i=0;i<ctd;i++){
    printf("Estado %d dist (%d,%d) = %d\n",p[i].estado ,p[i].x, p[i].y, p[i].dist );
   }

}

// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max-min+1);
}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01()
{
	return ((float)rand())/RAND_MAX;
}

int startMenu(){
	int i = 0;

	printf("--------------------- Menu ------------------\n"
			"Escolha uma opcao:\n"
			"Pesquisa 'Trepa-colinas vizinhos'............1\n"
			"Pesquisa 'Trepa-colinas prob 50%%'...........2\n"
			"Pesquisa 'Algoritmo genetico'................3\n"
			"Pesquisa 'Hibrida'...........................4\n"
			"Terminar.....................................5\n");

	do{
		i = 0;
		puts("\n\t\t\t\t\tEscolha uma opcao");
		scanf("%d", &i);

		if(i < 1 || i > 5){
			puts("\n\t\t\t\t\t!!!Opcao invalida!!!");
		}
	}while(i < 1 || i > 5);

	return i;
}

void imprimeFileList(){
	puts("Lista de ficheiros existentes:\n");
	puts("n010.txt");
	puts("n012.txt");
	puts("n030.txt");
	puts("n060.txt");
	puts("n120.txt");
	puts("n240.txt\n");
	printf("Insira o nome do ficheiro: ");
}
