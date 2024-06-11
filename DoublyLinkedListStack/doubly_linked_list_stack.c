#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top->prev = newNode;
        stack->top = newNode;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }
    free(temp);
    return data;
}


void printStack(Stack* stack) {
    Node* temp = stack->top;
    printf("Pilha: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void freeStack(Stack* stack) {
    Node* temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack);

    printf("Desempilhado: %d\n", pop(stack));
    printStack(stack);

    printf("Desempilhado: %d\n", pop(stack));
    printStack(stack);

    freeStack(stack);

    return 0;
}

