#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createList();
Node* createNode(int key);
int isEmpty(LinkedList* list);
void insertStart(LinkedList* list, int key);
void insertEnd(LinkedList* list, int key);
int removeStart(LinkedList* list);
int removeEnd(LinkedList* list);
void printList(LinkedList* list);
void freeList(LinkedList* list);

// Function to create a empty list
LinkedList* createList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    if(list == NULL){
        printf("Falha ao alocar memoria dinamica.");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to create a new node
Node* createNode(int key){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Falha ao alocar memoria dinamica");
        exit(EXIT_FAILURE);
    }

    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Function to check if the list is empty
int isEmpty(LinkedList* list){
    return list->head == NULL;
}

// Function to insert the node in the beginning
void insertStart(LinkedList* list, int key){
    Node* newNode = createNode(key);
    if(isEmpty(list)){ // If the list is empty, the new node will be both
        list->head = newNode;
        list->tail = newNode;
    } else { 
        newNode->next = list->head; // The pointer of newNode must point to the old head
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to insert the node in the end
void insertEnd(LinkedList* list, int key){
    Node* newNode = createNode(key);
    if(isEmpty(list)){
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to remove a node in the beggining
int removeStart(LinkedList* list){
    if(isEmpty(list)){
        return -1;
    }

    Node* nodeToRemove = list->head;
    int keyValue = nodeToRemove->key;

    if(list->head == list->tail){ // Only element on list
        list->tail = NULL;
        list->head = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(nodeToRemove);
    return keyValue;
}

// Function to remove a node in the end
int removeEnd(LinkedList* list){
    if(isEmpty(list)){
        return -1;
    }

    Node* nodeToRemove = list->tail;
    int keyValue = nodeToRemove->key;

    if(list->tail == list->head){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(nodeToRemove);
    return keyValue;
}

// Function to print the linked list
void printList(LinkedList* list){
    Node* current = list->head;
    while(current != NULL){
        printf("%d\n", current->key);
        current = current->next;
    }
}

// Function to free the nodes
void freeList(LinkedList* list){
    Node* current = list->head;
    Node* next_Node = NULL;
    while(current != NULL){
        next_Node = current->next;
        free(current);
        current = next_Node;
    }
    free(list);
}

#define MAX_OUTPUTS 100

int main(){
    LinkedList* list = createList();
    char command[2]; // Para ler o caractere do comando
    int value;
    int outputs[MAX_OUTPUTS];
    int outputCount = 0;

    while(scanf("%1s", command) == 1 && command[0] != 'X'){
        if(command[0] == 'I'){
            scanf("%d", &value);
            if(value > 0){
                insertStart(list, value);
            } 
        } else if(command[0] == 'F'){
            scanf("%d", &value);
            if(value > 0){
                insertEnd(list, value);
            }
        } else if(command[0] == 'P'){
            if(!isEmpty(list)){ // Só remove se a lista não estiver vazia
                value = removeEnd(list);
                if(outputCount < MAX_OUTPUTS){
                    outputs[outputCount++] = value;
                }
            }
        } else if(command[0] == 'D'){
            if(!isEmpty(list)){
                value = removeStart(list);
                if(outputCount < MAX_OUTPUTS){
                    outputs[outputCount++] = value;
                }
            }
        }
    }

    int firstOutputPrinted = 0;

    for(int i = 0; i < outputCount; i++){
        printf("%d\n", outputs[i]);
        firstOutputPrinted = 1;
    }

    if(outputCount > 0){
        printf("\n");
    }


    printList(list);
    freeList(list);

    return 0;
}