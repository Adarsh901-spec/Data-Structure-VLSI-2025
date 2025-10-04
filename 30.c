#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Global pointer to the top of the stack
struct Node *top = NULL;

// Function to push an element onto the stack
void push(int element) {
    // Create a new node and allocate memory
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return;
    }
    newNode->data = element;
    // New node points to the current top
    newNode->next = top;
    // The new node becomes the new top
    top = newNode;
}

// Function to pop the top element from the stack
void pop() {
    if (top == NULL) {
        return; // Stack is empty (underflow)
    }
    struct Node *temp = top;
    top = top->next; // Move top to the next node
    free(temp);      // Free the old top node
}

// Function to peek the top element of the stack
int peek() {
    if (top == NULL) {
        return -1; // Return a sentinel value for an empty stack
    }
    return top->data;
}

// Function to print the stack elements from top to bottom
void printStack() {
    if (top == NULL) {
        printf("Empty\n");
        return;
    }

    struct Node *current = top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    int numOperations, operationType, element;
    scanf("%d", &numOperations);

    // Array to store the results of peek operations
    int peekOutputs[numOperations];
    int numPeekOutputs = 0;

    for (int i = 0; i < numOperations; i++) {
        scanf("%d", &operationType);

        if (operationType == 1) {
            scanf("%d", &element);
            push(element);
        } else if (operationType == 2) {
            pop();
        } else if (operationType == 3) {
            int peekResult = peek();
            if (peekResult != -1) {
                // Store the peek result if the stack was not empty
                peekOutputs[numPeekOutputs++] = peekResult;
            }
        }
    }

    // --- Output Section ---

    // 1. Print all the stored peek results first
    for (int i = 0; i < numPeekOutputs; i++) {
        printf("%d\n", peekOutputs[i]);
    }

    // 2. Print the final state of the stack
    printStack();

    // 3. Free any remaining nodes in the stack to prevent memory leaks
    while (top != NULL) {
        pop();
    }

    return 0;
}
