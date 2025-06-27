#include <stdio.h>
#define MAXN 10000

int stack[MAXN];
int top = -1;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int N, K;
        scanf("%d %d", &N, &K);
        top = -1; 
        int ok = 1; // Para verficar se o estacionamento funcionou

        for(int i = 0; i < N; i++){
            int Ci, Si;
            scanf("%d %d", &Ci, &Si);

            while(top >= 0 && stack[top] <= Ci){
                top--;
            }

            if(top + 1 >= K){
                ok = 0;
            }
            else if(top >= 0 && stack[top] < Si){
                ok = 0;
            } else {
                stack[++top] = Si;
            }
        }  
        printf("%s\n", ok? "Sim" : "Nao");

    }

    return 0;
}