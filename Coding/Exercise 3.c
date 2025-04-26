#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

void insertInDescendingOrder(Node** top, int val) {
    Node* newNode = createNode(val);
    
    if (*top == NULL || val > (*top)->data) {
        newNode->next = *top;
        *top = newNode;
        return;
    }
  
    Node* current = *top;
    while (current->next != NULL && current->next->data > val) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void printStack(Node* top) {
    Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Node** top) {
    Node* current = *top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *top = NULL;
}

int main() {
    Node* stack = NULL;

    push(&stack, 20);
    push(&stack, 15);
    push(&stack, 10);
    push(&stack, 5);
    
    printf("Original stack: ");
    printStack(stack);  
   
    insertInDescendingOrder(&stack, 12);
    printf("After inserting 12: ");
    printStack(stack);  
    
    insertInDescendingOrder(&stack, 3);
    printf("After inserting 3: ");
    printStack(stack);  
    
    insertInDescendingOrder(&stack, 25);
    printf("After inserting 25: ");
    printStack(stack);  
    
    freeStack(&stack);
    return 0;
}