#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node{
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the head of the linked list
Node* insertEnd(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
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

// Function to delete a node at a given position in the linked list
Node *deleteNode(Node* head, int position){
    if(head == NULL) return NULL;

    if(position == 0){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }   

    Node* current = head;
    for(int i = 0; current != NULL && i < position - 1; i++){ // Traverse to the node before the one to be deleted
        current = current->next;
        if(current == NULL || current->next == NULL){
            return head; // Position is out of bounds
        }
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Function to print all elements of the linked list
void printList(Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory alocated for the linked list
void freeList(Node* head){
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int n, pos;
    scanf("%d", &n);

    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &pos);
    head = deleteNode(head, pos);
    printList(head);
    freeList(head);

    return 0;
}