#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int dado;
    struct Node* next;
};
typedef struct Node Node;

// Function to insert a new node at the head of the linked list
Node* insertEnd(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Falha ao alocar memória dinâmica");
        exit(1);
    }

    newNode->dado = value;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }

    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to reverse a linked list
Node* reverseList(Node* head){
    Node* prev_node = NULL;
    Node* current_node = head;
    Node* next_node = NULL;

    while(current_node != NULL){
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;
    return head;
}

// Function to print the linked list
void printList(Node* head){
    Node* current = head;

    while(current != NULL){
        printf("%d ", current->dado);
        current = current->next;
    }

    printf("\n");
}

// Fuction to free the linked list
void freeList(Node* head){
    Node* current = head;
    Node* nextNode = NULL; //Nó temporário para guardar o próximo
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    head = reverseList(head);

    printList(head);

    freeList(head);

    return 0;
}