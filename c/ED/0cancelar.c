#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
    int size;
} Stack;

Stack* createStack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Erro ao alocar memoria dinamica\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int dado){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar memoria dinamica\n");
        exit(EXIT_FAILURE);
    }

    newNode->dado = dado;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack){
    if(stack->top == NULL){
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int sumStack(Stack* stack){
    Node* current = stack->top;
    int soma = 0;
    while(current != NULL){
        soma += current->dado;
        current = current->next;
    }

    return soma;
}

void freeStack(Stack* stack){
    Node* current = stack->top;
    while(current != NULL){
        pop(stack);
    }   
    free(stack);
}

int main(){
    int t;
    scanf("%d", &t);
    Stack* stack = createStack();

    while(t--){
        int n;
        scanf("%d", &n);

        if(n != 0){
            push(stack, n);
        } else{
            pop(stack);
        }
    }

    int result = sumStack(stack);
    printf("%d\n", result);
    
    free(stack);

    return 0;
}