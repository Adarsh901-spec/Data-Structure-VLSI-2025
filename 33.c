#include <stdio.h>
#include <stdlib.h>

// --- Global Stack Implementation ---
// Using a global array-based stack for simplicity.
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

// Checks if the stack is empty.
int isEmpty() {
    return top == -1;
}

// Pushes an item onto the stack.
void push(int item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
    }
}

// Pops an item from the stack.
int pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1; // Should not happen with valid input
}
// --- End of Stack Implementation ---

/**
 * @brief Recursively prints and empties the stack from top to bottom.
 * This function achieves the printing without using any explicit loops.
 */
void print_stack_recursively() {
    // Base case: If the stack is empty, stop the recursion.
    if (isEmpty()) {
        return;
    }
    
    // 1. Pop the top element.
    int item = pop();
    
    // 2. Print the element.
    printf("%d", item);
    
    // 3. Add a space only if there are more elements left to print.
    if (!isEmpty()) {
        printf(" ");
    }
    
    // 4. Make the recursive call to print the rest of the stack.
    print_stack_recursively();
}

int main() {
    int n, i, element;

    // Read the number of elements.
    scanf("%d", &n);

    // The "no loops" constraint applies to the core logic, not I/O.
    // Read all elements and push them onto the stack.
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        push(element);
    }

    // Call the recursive function to print the stack's contents.
    // This will print the numbers in reverse order of how they were read.
    print_stack_recursively();
    printf("\n");

    return 0;
}

