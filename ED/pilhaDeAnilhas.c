#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

Stack* createStack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack){
    return stack->top == NULL;
}

void push(Stack* stack, int valor){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = valor;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack){
    if(isEmpty(stack)) return -1;

    Node* temp = stack->top;
    int valorRetorna = stack->top->data;

    stack->top = stack->top->next;
    
    free(temp);
    return valorRetorna;
}

void freeList(Stack* stack){
    while(!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}

int main(){
    Stack* stack = createStack();
    int anilha;

    while(1){
        scanf("%d", &anilha);
        if(anilha == 0) break;
        push(stack, anilha);
    }

    int soma = 0;
    int totalRetirada = 0;
    int anilhaProcurada;
    scanf("%d", &anilhaProcurada);
    while(!isEmpty(stack)){
        int anilhaRetirada = pop(stack);
        if(anilhaRetirada == anilhaProcurada){
            break;
        }
        totalRetirada++;
        soma += anilhaRetirada;
        printf("Peso retirado: %d\n", anilhaRetirada);
    }

    printf("Anilhas retiradas %d\n", totalRetirada);
    printf("Peso retirado: %d\n", soma);
    freeList(stack);
    
    return 0;
}