#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));

    if(q == NULL){
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE); 
    }

    q->front = NULL;
    q->rear = NULL;

    return q;
}

void enqueue(Queue* q, char data){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Falha ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if(q->rear == NULL){
        q->front = q->rear = newNode;
        return;
    }

    q->front->next = newNode;
    q->rear = newNode;
}

char dequeue(Queue* q){
    if(q->front == NULL){
        return '\0';
    }

    Node* temp = q->front;
    char data = temp->data;

    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int main(){
    Queue* tournamentQueue = createQueue();
    
    for(int i = 0; i < 16; i++){
        enqueue(tournamentQueue, 'A' + i);
    }

    int gols_m, gols_n;

    while(tournamentQueue->front != tournamentQueue->rear){
        char equipe1 = dequeue(tournamentQueue);
        char equipe2 = dequeue(tournamentQueue);
        scanf("%d %d", &gols_m, &gols_n);

        if(gols_m > gols_n){
            enqueue(tournamentQueue, equipe1);
        } else {
            enqueue(tournamentQueue, equipe2);
        }
    }

    char campeao = dequeue(tournamentQueue);
    printf("%c\n", campeao);

    free(tournamentQueue);

    return 0;
}