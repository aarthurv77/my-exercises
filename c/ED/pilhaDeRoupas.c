#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* next;
    char roupa[30];
    char cor[20];
    int tempo;
} Node;

typedef struct Stack{
    int size;
    struct Stack* top;
} Stack;

// Function to create a stack
Stack* createStack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    if(stack == NULL){
        printf("Erro ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    stack->size = 0;
    stack->top = NULL;

    return stack;
} 

void push(Stack* stack, const char* roupa, const char* cor, int tempo){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Erro ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->roupa, roupa);
    strcpy(newNode->cor, cor);
    newNode->tempo = tempo;

    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int main(){
    Stack* pilhadeRoupas = createStack();

    char roupaInput[51];
    char corInput[51];
    int tempoInput;
    int totalRoupas = 0;
    int tempoTotal = 0;

    while(scanf("%s", roupaInput) == 1){
        if(strcmp(roupaInput, "end") == 0){
            break;
        }

        scanf("%s %d", corInput, tempoInput);

        push(pilhadeRoupas, roupaInput, corInput, tempoInput);
    }

    totalRoupas = pilhadeRoupas->size;

    while(pilhadeRoupas->top != NULL){
        Node* noAtual = pilhadeRoupas->top;
        printf("Tipo: %s Cor %s", noAtual->roupa, noAtual->cor);

        tempoTotal += noAtual->tempo;

        pilhadeRoupas->top = noAtual->next;
        free(noAtual);
    }

    printf("Total de roupas = %d\n", totalRoupas);
    printf("Total de tempo = %d\n", tempoTotal);
    free(pilhadeRoupas);

    return 0;
}