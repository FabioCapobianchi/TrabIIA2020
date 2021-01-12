#include <stdio.h>
#include <stdlib.h>
typedef struct dados dad,*pdad;
struct dados /*ppessoas*/
{
    int x;
    int y;
    int dist;
};

dad* init_dados(char *nome, int *pop, int *grupo,int *ctd)
{
	FILE *fi;
	dad *p, *p1 = NULL;
	int ct=0;
    char st[1000];

	fi=fopen(nome, "r");
	if(!fi)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	 p1 = malloc(sizeof(dad)*1);

    fscanf(fi, "%d %d %[^\n]",pop,grupo, st);
	printf(" pop %d grupo %d resto %s \n",*pop,*grupo,st);
	while(fscanf(fi,"%d %d %d",&p1[ct].x,&p1[ct].y,&p1[ct].dist)==3){
       ct++;
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

void ledados(pdad p,int ctd){

   int i;
   printf("ctd: %d\n",ctd);
   for(i=0;i<ctd;i++){
    printf("x: %d y: %d  dist: %d\n",p[i].x, p[i].y, p[i].dist);
   }

}
int main()
{
    pdad pd = NULL;
    int pop, sub, cont;
    char nome_fich[10];
    printf("Nome do Ficheiro: ");
    gets(nome_fich);
    pd =init_dados(nome_fich, &pop, &sub, &cont);
    ledados(pd,cont);
    return 0;
}
