#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}


void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void printListForward(Node* head) {
    Node* temp = head;
    printf("Lista do início ao fim:\n");
    while (temp != NULL) {
        printf("Data: %d, Prev: %p (%d), Next: %p (%d)\n", 
               temp->data, 
               (void*)temp->prev, 
               temp->prev ? temp->prev->data : 0, 
               (void*)temp->next, 
               temp->next ? temp->next->data : 0);
        temp = temp->next;
    }
    printf("\n");
}


void printListBackward(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Lista do fim ao início:\n");
    while (temp != NULL) {
        printf("Data: %d, Prev: %p (%d), Next: %p (%d)\n", 
               temp->data, 
               (void*)temp->prev, 
               temp->prev ? temp->prev->data : 0, 
               (void*)temp->next, 
               temp->next ? temp->next->data : 0);
        temp = temp->prev;
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

int main() {
    Node* head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printListForward(head);
    printListBackward(head);

    freeList(head);

    return 0;
}

