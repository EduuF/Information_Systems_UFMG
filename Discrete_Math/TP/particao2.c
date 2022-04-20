#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int p[], int n)
{
    for (int i = 0; i < n; i++)
       printf("%d ", p[i]);
       printf("\n");
}

int numeros_distintos(int p[], int n){

    int nd = 1;



    for (int i = 0; i < n-1; i++){

        for (int j = i+1; j < n; j++){
            if (p[i] == p[j])
                nd = 0;
        }

    }


    return nd;
}

void imprimirTodasParticoes(int n, int k)
{
    int particao[n];
    int indice = 0;
    int qtd_particoes = 0;
    particao[indice] = n;

    for(;;)
    {

        int vetor_numeros_distintos = 0;

        if (numeros_distintos(particao, indice+1) == 1)
            vetor_numeros_distintos = 1;
        else vetor_numeros_distintos = 0;

        if(indice+1 ==k && vetor_numeros_distintos==1){
            imprimirVetor(particao, indice+1);
            qtd_particoes = qtd_particoes+1;
        }

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

    int numero_alvo, tam_particao;

    printf("Entre com um numero inteiro e o tamanho da particao: ");
    scanf("%d %d", &numero_alvo, &tam_particao);

    imprimirTodasParticoes(numero_alvo, tam_particao);

    system("pause");

    return 0;
}

