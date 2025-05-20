#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertEnd(Node* head, int value);
void printList(Node* head);
void freeList(Node* head);

int main() {
    int n, valor;
    Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        head = insertEnd(head, valor);
    }

    printList(head);
    freeList(head);

    return 0;
}

Node* insertEnd(Node* head, int value) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = value;
    novo->next = NULL;

    if (head == NULL) return novo;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = novo;

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
