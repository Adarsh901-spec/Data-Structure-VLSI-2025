#include <stdio.h>
#include <stdlib.h>

// Define a maximum size for the queue array.
#define MAX_SIZE 100

// Global variables for the linear queue.
int queue[MAX_SIZE];
int front = 0;
int rear = -1;

/**
 * @brief Adds an element to the rear of the queue.
 */
void enqueue(int value) {
    // Check for overflow condition (if rear is at the end of the array).
    if (rear >= MAX_SIZE - 1) {
        // Cannot add more elements.
        // For this problem, we can assume this limit won't be reached.
        return;
    }
    
    // Increment rear and insert the element.
    rear++;
    queue[rear] = value;
}

/**
 * @brief Removes an element from the front of the queue.
 */
void dequeue() {
    // Check for underflow condition (if the queue is empty).
    if (rear < front) {
        // Queue is empty, nothing to remove.
        return;
    }
    
    // "Remove" the element by advancing the front pointer.
    front++;
}

/**
 * @brief Prints the current elements in the queue from front to rear.
 */
void printQueue() {
    // Check if the queue is empty.
    if (rear < front) {
        printf("Empty\n");
        return;
    }
    
    // Loop from the front to the rear and print each element.
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        // Print a space if it's not the last element.
        if (i < rear) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n; // Number of operations.
    scanf("%d", &n);
    
    int op_type, value;
    
    // Loop to process all operations.
    for (int i = 0; i < n; i++) {
        scanf("%d", &op_type);
        
        if (op_type == 1) { // Enqueue operation
            scanf("%d", &value);
            enqueue(value);
        } else if (op_type == 2) { // Dequeue operation
            dequeue();
        }
    }
    
    // After all operations are done, print the final state of the queue.
    printQueue();
    
    return 0;
}
