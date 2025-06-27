#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack();
int isEmpty(Stack* stack);
void push(Stack* stack, char value);
char pop(Stack* stack);
char peek(Stack* stack);
void freeStack(Stack* stack);

int isValid(char* s){
    Stack* stack = createStack();

    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];

        if(c == '('){
            push(stack, ')');
        }
        else if(c == '{'){
            push(stack, '}');
        }
        else if(c == '['){
            push(stack, ']');
        } else {
            if(isEmpty(stack)){
                return 0;
            }

            char topo = pop(stack);
            if(c != topo){
                return 0;
            }
        }
    }
    int resultado = isEmpty(stack);
    freeStack(stack);
    return resultado;
}