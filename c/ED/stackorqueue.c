#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int entrada[100], saida[100];
        
        for(int i = 0; i < n; i++){
            scanf("%d", &entrada[i]);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &saida[i]);
        }

        int queue = 0;
        int contQueue = 0;
        int stack = 0;
        int contStack = 0;

        for(int i = 0; i < n; i++){
            if(entrada[i] == saida[i]){
                contQueue++;
            }
        }
        if(contQueue == n){
            queue = 1;
        }

        for(int i = 0; i < n; i++){
            if(entrada[i] == saida[n-i-1]){
                contStack++;
            }
        }
        if(contStack == n){
            stack = 1;
        }

        if(stack == 1 && queue == 1){
            printf("both\n");
        } 
        else if(stack == 0 && queue == 0){
            printf("neither\n");
        }

        else if(stack == 1){
            printf("stack\n");
        }
        else if(queue == 1){
            printf("queue\n");
        }

    }


    return 0;
}