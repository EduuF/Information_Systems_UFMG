#include <stdio.h>
#include <stdlib.h>

int main(){

    int vec_len, *vec, sum, max_sum = 0, init_max_sum, end_max_sum;
    scanf("%d", &vec_len);

    vec = (int*)calloc(vec_len, sizeof(int));

    if(!vec){
        printf("Erro ao alocar memoria");
        return 0;
    }

    for(int i = 0; i<vec_len; i++){
        scanf("%d", &vec[i]);
    }

    for(int i = 0; i<vec_len; i++){
        for(int j = 0; j<vec_len; j++){
            sum = 0;
            for(int x = i; x<=j; x++){
                sum += vec[x];
            }
            if(sum>max_sum){
                max_sum = sum;
                init_max_sum = i+1;
                end_max_sum = j+1;
            }
        }
    }

    printf("Soma: %d\n", max_sum);
    printf("Indices: %d a %d", init_max_sum, end_max_sum);

    

    free(vec);

    return 0;
}