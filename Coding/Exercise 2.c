#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int countElements(Node* top) {
    int count = 0;
    Node* current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int findMax(Node* top) {
    if (top == NULL) {
        fprintf(stderr, "Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    int max = top->data;
    Node* current = top->next;
    while (current != NULL) {
        if (current->data > max) max = current->data;
        current = current->next;
    }
    return max;
}

int findMin(Node* top) {
    if (top == NULL) {
        fprintf(stderr, "Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    int min = top->data;
    Node* current = top->next;
    while (current != NULL) {
        if (current->data < min) min = current->data;
        current = current->next;
    }
    return min;
}

void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
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
    
    push(&stack, 15);
    push(&stack, 7);
    push(&stack, 42);
    push(&stack, 3);
    
    printf("Number of elements: %d\n", countElements(stack)); 
    printf("Maximum value: %d\n", findMax(stack));            
    printf("Minimum value: %d\n", findMin(stack));            
    
    freeStack(&stack); 
    return 0;
}