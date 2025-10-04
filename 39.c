#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// We will use two stacks to implement the queue
int stack1[MAX_SIZE];
int top1 = -1;

int stack2[MAX_SIZE];
int top2 = -1;

// --- Stack 1 Helper Functions ---
void push1(int data) {
    if (top1 < MAX_SIZE - 1) {
        stack1[++top1] = data;
    }
}

int pop1() {
    if (top1 >= 0) {
        return stack1[top1--];
    }
    return -1; // Indicates stack is empty
}

int isEmpty1() {
    return top1 == -1;
}

// --- Stack 2 Helper Functions ---
void push2(int data) {
    if (top2 < MAX_SIZE - 1) {
        stack2[++top2] = data;
    }
}

int pop2() {
    if (top2 >= 0) {
        return stack2[top2--];
    }
    return -1; // Indicates stack is empty
}

int isEmpty2() {
    return top2 == -1;
}

// --- Queue Operations ---

/**
 * @brief Enqueues an element by pushing it onto stack1.
 */
void enqueue(int data) {
    push1(data);
}

/**
 * @brief Dequeues an element.
 * Moves elements from stack1 to stack2 if needed to get the oldest element.
 */
void dequeue() {
    // If stack2 is empty, transfer all elements from stack1
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }
    
    // Pop from stack2 (if it's not empty)
    // The problem description implies we don't need to print the dequeued element,
    // just perform the operation.
    if (!isEmpty2()) {
        pop2();
    }
}

/**
 * @brief Prints the final contents of the queue in FIFO order.
 */
void printQueue() {
    if (isEmpty1() && isEmpty2()) {
        printf("Empty\n");
        return;
    }
    
    int i;
    int first_element_printed = 0;
    
    // Print elements from stack2 (top to bottom)
    for (i = top2; i >= 0; i--) {
        if (first_element_printed) {
            printf(" ");
        }
        printf("%d", stack2[i]);
        first_element_printed = 1;
    }
    
    // Print elements from stack1 (bottom to top)
    for (i = 0; i <= top1; i++) {
        if (first_element_printed) {
            printf(" ");
        }
        printf("%d", stack1[i]);
        first_element_printed = 1;
    }
    
    printf("\n");
}


int main() {
    int n, op, value;
    
    // Read the number of operations
    scanf("%d", &n);
    
    // Process each operation
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            enqueue(value);
        } else if (op == 2) {
            dequeue();
        }
    }
    
    // Print the final state of the queue
    printQueue();
    
    return 0;
}
