#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CityNode {
    char name[50];
    float area;
    int population;
    struct CityNode* next;
} CityNode;

CityNode* createCityNode() {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter city name: ");
    gets(newNode->name);

    printf("Enter city area: ");
    scanf("%f", &newNode->area);

    printf("Enter city population: ");
    scanf("%d", &newNode->population);

    getchar(); 
    newNode->next = NULL;
    return newNode;
}

void addCorso(CityNode** head) {
    CityNode* corso = (CityNode*)malloc(sizeof(CityNode));
    if (corso == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(corso->name, "Corso");
    corso->area = 10.5;
    corso->population = 50000;
    corso->next = *head;
    *head = corso;
}

void removeThirdCity(CityNode** head) {
    if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL) {
        return;
    }

    CityNode* thirdNode = (*head)->next->next;
    (*head)->next->next = thirdNode->next;
    free(thirdNode);
}

void deleteCitiesStartingWithB(CityNode** head) {
    CityNode dummy;
    dummy.next = *head;
    CityNode* prev = &dummy;
    CityNode* current = *head;

    while (current != NULL) {
        if (current->name[0] == 'B' || current->name[0] == 'b') {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    *head = dummy.next;
}

void freeStack(CityNode** head) {
    CityNode* current = *head;
    while (current != NULL) {
        CityNode* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void printStack(CityNode* head) {
    CityNode* current = head;
    while (current != NULL) {
        printf("City Name: %s\n", current->name);
        printf("Area: %.2f\n", current->area);
        printf("Population: %d\n", current->population);
        current = current->next;
    }
}

int main() {
    CityNode* stack = NULL;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a city\n");
        printf("2. Add Corso\n");
        printf("3. Remove third city\n");
        printf("4. Delete cities starting with 'B'\n");
        printf("5. Print stack\n");
        printf("6. Free stack and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character left by scanf

        switch (choice) {
            case 1:
                {
                    CityNode* newCity = createCityNode();
                    newCity->next = stack;
                    stack = newCity;
                }
                break;
            case 2:
                addCorso(&stack);
                break;
            case 3:
                removeThirdCity(&stack);
                break;
            case 4:
                deleteCitiesStartingWithB(&stack);
                break;
            case 5:
                printStack(stack);
                break;
            case 6:
                freeStack(&stack);
                printf("Stack freed. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}