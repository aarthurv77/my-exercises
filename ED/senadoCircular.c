#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct Queue{
    int data[MAX*2];
    int front, rear;
} Queue;

void createQueue(Queue* queue){
    queue->front = queue->rear = 0;
}

void enqueue(Queue* queue, int valor){
    queue->data[queue->rear++] = valor;
}

int dequeue(Queue* queue){
    return queue->data[queue->front++];
}

int isEmpty(Queue* queue){
    return queue->front == queue->rear;
}

int main(){
    int n;
    char senadores[MAX + 1];
    Queue filaR, filaI;

    scanf("%d", &n);
    scanf("%s", senadores);

    createQueue(&filaR);
    createQueue(&filaI);

    for(int i = 0; i < n; i++){
        if(senadores[i] == 'R'){
            enqueue(&filaR, i);
        } else {
            enqueue(&filaI, i);
        }
    }

    // Simulação das rodadas
    while(!isEmpty(&filaR) && !isEmpty(&filaI)){
        int r = dequeue(&filaR);
        int i = dequeue(&filaI);

        if(r > i){
            enqueue(&filaR, r + n);
        } else {
            enqueue(&filaI, i+ n);
        }
    }

    if(isEmpty(&filaR)){
        printf("Imperio\n");
    } else {
        printf("Republica\n");
    }
    
    return 0;
}