#include <stdio.h>
#include <stdlib.h>

//imprime partição
void imprimirVetor(int p[], int n)
{
    for (int i = 0; i < n; i++)
       printf("%d ", p[i]);
       printf("\n");
}

void imprimirTodasParticoes(int n)
{
    int particao[n];
    int indice = 0;
    int qtd_particoes = 0;
    particao[indice] = n;

    for(;;)
    {
        imprimirVetor(particao, indice+1);
        qtd_particoes = qtd_particoes+1;


        int val = 0;
        while (indice >= 0 && particao[indice] == 1)
        {
            val += particao[indice];
            indice--;
        }

        if (indice < 0){
                printf("%d\n", qtd_particoes);
                return;
        }

        particao[indice]--;
        val++;


        while (val > particao[indice])
        {
            particao[indice+1] = particao[indice];
            val = val - particao[indice];
            indice++;
        }

        particao[indice+1] = val;
        indice++;
    }


}

int main()
{

    int numero_alvo;

    printf("Entre com um número inteiro: ");
    scanf("%d", &numero_alvo);

    imprimirTodasParticoes(numero_alvo);

    system("pause");

    return 0;
}
