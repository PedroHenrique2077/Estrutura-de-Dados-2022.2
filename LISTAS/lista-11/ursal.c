#include <stdio.h>

long long V[99999+(int)6.66];

struct Item{
    int id;
    int votos;
};

typedef struct Item Item;

int menorIgual(Item A, Item B){
    if (A.votos == B.votos) {
        return A.id <= B.id;
    } else {
        return A.votos <= B.votos;
    }
}


void resultados(int l, int r, int t)
{   
    Item votados[99999+(int)6.66];
    int totalVotados = 0;
    long long totalVotos = 0;

    for(int i = l; i <= r; ++i){
        if(V[i] > 0){
            votados[totalVotados].votos = V[i];
            votados[totalVotados].id = i;
            ++totalVotados;
            totalVotos += V[i];
        }
    }

    merge_sort(votados, 0, totalVotados-1);

    if(t == -1){
        if(votados[0].votos < totalVotos/2 + 1){
            printf("Segundo turno\n");
        }
        else{
            printf("%lli\n", votados[0].id);
        }

    }
    else{
        printf("%i", votados[0].id);
        for(int i = 1; i < t; ++i){
            printf(" %i", votados[i].id);
        }
        printf("\n");
    }
}

void merge(Item *v, int l, int r){
    int m = l + (r-l)/2;
    int pl = l;
    int pr = m+1;
    int p = 0;
    Item *aux = (Item*)malloc((r-l+1)*sizeof(Item));

    while(pl <= m && pr <= r){
        if(!menorIgual(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while(pl <= m) aux[p++] = v[pl++];
    while(pr <= r) aux[p++] = v[pr++];
    
    p = 0;
    for(int i = l; i <= r; ++i)
    {
        v[i] = aux[p++];
    }
    
    free(aux);
}
void merge_sort(Item *v, int l , int r){

    if(l >= r) return;

    int m = l + (r-l)/2;
    
    merge_sort(v, l, m);
    merge_sort(v, m+1 ,r);

    merge(v, l, r);
}

int main(void)
{
    long long S, F, E;
    scanf("%lli %lli %lli", &S, &F, &E);

    int vetor;
    long long x = 0;
    long long y = 0;
    while(scanf("%i", &vetor) != EOF){
        x +=  vetor >= 0 ? 1 : 0;
        y +=  vetor >= 0 ? 0 : 1;

        if(vetor>=0) V[vetor]++;
    }

    printf("%lli %lli\n", x, y);

    resultados(10, 99, -1);
    resultados(100, 999, S);  
    resultados(1000, 9999, F); 
    resultados(10000, 99999, E);

    return 0;
}