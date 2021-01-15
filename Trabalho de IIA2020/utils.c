#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


int qs = 1;
// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
dad* init_dados(char *nome, int *ele, int *grupo,int *ctd)
{
	FILE *fi;
	dad *p, *p1 = NULL;
	int i=0,ct=0;
    char st[1000];

	fi=fopen(nome, "r");
	if(!fi)
	{
		puts("\n\n\t\t\t\t\t\t\t\t\t******************************************************\n");
		printf("\t\t\t\t\t\t\t\t\t\t Erro no acesso ao ficheiro dos dados\n");
		puts("\n\n\t\t\t\t\t\t\t\t\t******************************************************\n");
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


// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(int *sol, int vert)
{
	int i;

	printf("\nConjunto A: ");
	for(i=0; i<vert; i++)
		if(sol[i]==0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for(i=0; i<vert; i++)
		if(sol[i]==1)
			printf("%2d  ", i);
	printf("\n");
}

int formagrupos(pdad a,int pop, int grupo,int ct){

int i,j=0,soma=0, somat=0;
int cc=0, ctr=0, g=1;

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
     ctr = j;
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

// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
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

	puts("\t\t\t\t\t\t\t\t\t--------------- Menu ----------------\n");
	puts("\t\t\t\t\t\t\t\t\tEscolha uma opção");
	puts("\t\t\t\t\t\t\t\t\tPesquisa 'Trepa-colinas'............1");
	puts("\t\t\t\t\t\t\t\t\tPesquisa 'Algoritmo genético'.......2");
	puts("\t\t\t\t\t\t\t\t\tTerminar............................3");

	do{
		i = 0;
		puts("\n\t\t\t\t\t\t\t\t\tEscolha uma opção");
		scanf("%d", &i);

		if(i < 1 || i > 3){
			puts("\n\t\t\t\t\t\t\t\t\t\t!!!Opção inválida!!!");
		}
	}while(i < 1 || i > 3);

	return i;
}
