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
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if(queue == NULL){
        printf("Erro ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear= NULL;

    return queue;
}

void enqueue(Queue* queue, int dado){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    newNode->dado = dado;
    newNode->next = NULL;

    if(queue->rear == NULL){
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue* queue){
    if(queue->front == NULL){
        printf("Fila vazia. Nao ha o que remover.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = queue->front;
    int valor = temp->dado;
    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    free(temp);
    return valor;
}

void freeQueue(Queue* queue){
    Node* current = queue->front;
    while(current->next != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main(){
    int t;
    scanf("%d", &t);
    Queue* queue = createQueue();

    for(int i = 0; i < t; i++){
        int entrada;
        scanf("%d", &entrada);

        if(entrada == 1){
            int menu;
            scanf("%d", &menu);
            enqueue(queue, menu);
        } else if(entrada == 2){
            int saida = dequeue(queue);
            printf("%d\n", saida);
        } else {
            printf("Operacao invalida\n");
        }

    }

    freeQueue(queue);

    return 0;
}