#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        // Stack overflow, do nothing as per problem constraints
        return; 
    }
    stack[++top] = element;
}

// Function to pop the top element from the stack
void pop() {
    if (top == -1) {
        // Stack underflow, do nothing as per note
        return;
    }
    top--;
}

// Function to peek the top element of the stack
int peek() {
    if (top == -1) {
        // Stack is empty
        return -1; // Return a sentinel value
    }
    return stack[top];
}

int main() {
    int numOperations, operationType, element, peekResult;
    scanf("%d", &numOperations);

    // Array to store peek outputs to print them all at the end
    int peekOutputs[MAX_SIZE]; 
    int numPeekOutputs = 0;

    for (int i = 0; i < numOperations; i++) {
        scanf("%d", &operationType);

        if (operationType == 1) {
            scanf("%d", &element);
            push(element);
        } else if (operationType == 2) {
            pop();
        } else if (operationType == 3) {
            peekResult = peek();
            // Store the result only if the stack was not empty
            if (peekResult != -1) {
                peekOutputs[numPeekOutputs++] = peekResult;
            }
        }
    }

    // --- Output Section ---

    // 1. Print all stored peek outputs first
    for (int i = 0; i < numPeekOutputs; i++) {
        printf("%d\n", peekOutputs[i]);
    }

    // 2. Print the final state of the stack
    if (top == -1) {
        printf("Empty\n");
    } else {
        // Print from top to bottom
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
            // Print a space if it's not the last element
            if (i > 0) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
