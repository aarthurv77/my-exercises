#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        int iteracoes;
        scanf("%d", &iteracoes);

        int resultados[iteracoes];
        int tempoAtual = 0;
        for(int i = 0; i < iteracoes; i++){
            int l_i, r_i;
            scanf("%d %d", &l_i, &r_i);
            int tempoDeAtendimento = (tempoAtual > l_i) ? tempoAtual : l_i; // Forma de fazer o max()
            if(tempoDeAtendimento < r_i){
                resultados[i] = tempoDeAtendimento;
                tempoAtual = tempoDeAtendimento + 1;
            } else{
                resultados[i] = 0;
            }
        }

        for(int i = 0; i < iteracoes; i++){
            printf("%d ", resultados[i]);
        }
        printf("\n");
    }


    return 0;
}