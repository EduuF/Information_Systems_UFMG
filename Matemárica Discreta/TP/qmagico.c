#include <stdio.h>
#include <stdlib.h>

int** dynamic_allocation(int n);
void odd_matrix(int** matriz, int n, int first_number, int last_number);

int main(){

    int n, magic_const, first, current_x, current_y, future_x, future_y;
    scanf("%d", &n);
    if(n<3){
        printf("Nao existe quadrado magico com lado menor que 3");
        return 0;
    }

    magic_const = ((n * ((n * n) + 1 ))/2); //Formula da soma das linhas/colunas/diagonais

    int **matriz = dynamic_allocation(n); //alocação de memoria


    if(n%2 != 0){ //caso seja uma matriz impar
        odd_matrix(matriz, n, 1, n*n);
    } else { //caso seja uma matriz par
        if(n%4 != 0){ //quadrado par simples

        }else{
            int* A = &matriz[0][0]; //ponto de interesse da matriz
            int* B = &matriz[0][n-1];   //ponto de interesse da matriz
            int* C = &matriz[n-1][n-1]; //ponto de interesse da matriz
            int* D = &matriz[n-1][0];   //ponto de interesse da matriz

            int** secondary_matrix = dynamic_allocation(n/2);
            
            *A = 1; //define os pontos de interesse como 1 para diferenciá-los
            *B = 1; //define os pontos de interesse como 1 para diferenciá-los
            *C = 1; //define os pontos de interesse como 1 para diferenciá-los
            *D = 1; //define os pontos de interesse como 1 para diferenciá-los

            for(int i=0; i<n/2; i++){   //define os pontos de interesse como 1 para diferenciá-los
                for(int j=0; j<n/2; j++){
                    secondary_matrix[i][j] = 1;
                }
            }

            for(int i=0; i<n/2; i++){ //Coloca os valores na matriz original
                for(int j=0; j<n/2; j++){
                    matriz[i+1][j+1] = secondary_matrix[i][j];
                }
            }

            for(int i=0; i<n; i++){ //Coloca o devido valor nos campos onde contém o valor 1
                for(int j=0; j<n; j++){
                    if(matriz[i][j]!=0){
                        matriz[i][j] = ((i)*n)+(j+1);
                    }
                }
            }

            int contador = 0; //Coloca os devidos valores nos outros campos
            for(int i=n-1; i>=0; i--){
                for(int j=n-1; j>=0; j--){
                    contador++;
                    if(matriz[i][j] == 0){
                        matriz[i][j] = contador;
                    }
                }
            }
        }
    }

    //###### PRINTANDO A MATRIZ E SOMA #######
    magic_const = ((n * ((n * n) + 1 ))/2); //Formula da soma das linhas/colunas/diagonais
    printf("Soma: %d\n", magic_const);

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //##### LIBERAÇÃO DE MEMORIA #####
    for(int i=0; i<n; i++){
        free(matriz[i]);
    }
    free(matriz);
    //##### FIM DA LIBERAÇÃO #####


    return 0;
}

int** dynamic_allocation(int n){
    int **m = (int**)calloc(n, sizeof(int)); 
    for(int i=0; i<n; i++){
        m[i] = (int*)calloc(n, sizeof(int));
    }
    if (!m) {
        printf (" Erro na alocacao da memoria");
        return 0;
    }
    return m;
}

void odd_matrix(int** matriz, int n, int first_number, int last_number){
    int first = n/2; // Saber em qual casa na primeira linha colocarei o 1
    matriz[0][first] = first_number;
    int current_x = 0;
    int current_y = first;

    for(int i=first_number+1; i<=(last_number); i++){
        int future_x = current_x;
        int future_y = current_y;
        if(current_x == 0){
            future_x = n-1;
        } else {
            future_x--;
        }
        if(current_y == n-1){
            future_y = 0;
        } else {
            future_y++;
        }

        if(matriz[future_x][future_y] != 0){
            current_x++;
        } else {
            current_x = future_x;
            current_y = future_y;
        }

        matriz[current_x][current_y] = i;
    }
}