

typedef struct dados dad,*pdad;
typedef struct solucao sol,*psol;
struct dados
{   int estado ;
    int x;
    int y;
    int dist;
};

struct solucao
{   int qt;
    int *p;
};

void ledados(pdad p,int ctd);

int startMenu();
void setQs();
dad* init_dados(char *nome, int *pop, int *grupo,int *ctd);
void gera_sol_inicial(pdad solu, int v,int grp,int subg);
void escreve_sol(int *sol, int vert);
int formagrupos(pdad a,int ele, int grupo, int ct);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);
float rand_01();
