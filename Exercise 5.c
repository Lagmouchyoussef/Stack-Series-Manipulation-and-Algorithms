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

Node* mergeStacks(Node* A, Node* B) {
    Node* result = NULL;  
    
    while (!isEmpty(A) && !isEmpty(B)) {
    
        if (A->data <= B->data) {
            push(&result, pop(&A));
        } else {
            push(&result, pop(&B));
        }
    }
   
    while (!isEmpty(A)) {
        push(&result, pop(&A));
    }
  
    while (!isEmpty(B)) {
        push(&result, pop(&B));
    }
 
    Node* finalStack = NULL;
    while (!isEmpty(result)) {
        push(&finalStack, pop(&result));
    }
    
    return finalStack;
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
    Node* stackA = NULL;
    Node* stackB = NULL;
    
    push(&stackA, 15);
    push(&stackA, 10);
    push(&stackA, 5);
    push(&stackB, 12);
    push(&stackB, 8);
    push(&stackB, 3);
    
    printf("Stack A: ");
    printStack(stackA);  
    
    printf("Stack B: ");
    printStack(stackB);  
    
    Node* merged = mergeStacks(stackA, stackB);
    
    printf("Merged stack (ascending order): ");
    printStack(merged);  
    
    freeStack(&merged);
    return 0;
}