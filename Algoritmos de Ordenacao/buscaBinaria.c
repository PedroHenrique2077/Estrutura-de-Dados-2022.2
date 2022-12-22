int buscaBinaria(int *vetor, int tam, int n)
{
    int ini=0;
    int fim = tam-1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;

        if(n < vetor[meio])
        {
            fim = meio-1;
        } 
        else if(n > vetor[meio])
        {
            ini = meio+1;
        } 
        else return meio;

        return -1;
        
    }
}

