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

int pop(Node** top) {
    if (*top == NULL) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int isEmpty(Node* top) {
    return top == NULL;
}

void sortStack(Node** top) {
    Node* sortedStack = NULL;  
    
    while (!isEmpty(*top)) {
        int temp = pop(top);
        
        
        while (!isEmpty(sortedStack) && sortedStack->data > temp) {
            push(top, pop(&sortedStack));
        }
        
        
        push(&sortedStack, temp);
    }
    
    while (!isEmpty(sortedStack)) {
        push(top, pop(&sortedStack));
    }
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
    
    
    push(&stack, 30);
    push(&stack, -5);
    push(&stack, 18);
    push(&stack, 14);
    push(&stack, -3);
    
    printf("Original stack: ");
    printStack(stack);  
    
    sortStack(&stack);
    
    printf("Sorted stack (ascending order): ");
    printStack(stack);  
    
    freeStack(&stack);
    return 0;
}