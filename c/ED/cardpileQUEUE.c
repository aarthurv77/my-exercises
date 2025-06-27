#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(q == NULL){
        printf("Erro ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* queue){
    return queue->front == NULL;
}

void enqueue(Queue* queue, int valor){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    newNode->dado = valor;
    newNode->next = NULL;

    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;

}

int dequeue(Queue* queue){
    Node* temp = queue->front;
    int valor = queue->front->dado;

    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    free(temp);
    return valor;
}

void freeList(Queue* queue){
    Node* current = queue->front;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main(){
    int t;
    scanf("%d", &t);
    Queue* q = createQueue();

    for(int i = 0; i < t; i++){
        int consulta;
        scanf("%d", &consulta);
        if(consulta == 1){
            int valor;
            scanf("%d", &valor);
            enqueue(q, valor);
        } else if(consulta == 2){
            if(isEmpty(q)){
                printf("0\n");
            } else {
                int saida = dequeue(q);
                printf("%d\n", saida);
            }
            
        }

    }
    
    freeList(q);

    return 0;
}