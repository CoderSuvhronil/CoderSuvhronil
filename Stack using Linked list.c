#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the stack
typedef struct {
    Node* top;
} Stack;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty stack
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack is full.\n");
        return;
    }

    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    Node* poppedNode = stack->top;
    int data = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, data;

    while (1) {
        printf("\nSTACK Operations using LINKEDLIST:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;

            case 3:
                display(&stack);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

