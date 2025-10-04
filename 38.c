#include <stdio.h>
#include <stdlib.h>

// Define a maximum size for the queue array
#define MAX_SIZE 100

// Global variables for the circular queue
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

/**
 * @brief Adds an element to the rear of the circular queue.
 */
void enqueue(int value) {
    // Check for overflow condition
    if ((rear + 1) % MAX_SIZE == front) {
        // Queue is full, cannot add more elements.
        // In a real-world scenario, you might print an error.
        return;
    }
    
    // If the queue is empty, initialize front and rear
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        // Move rear to the next position in a circular manner
        rear = (rear + 1) % MAX_SIZE;
    }
    
    // Insert the element at the rear
    queue[rear] = value;
}

/**
 * @brief Removes an element from the front of the circular queue.
 */
void dequeue() {
    // Check for underflow condition
    if (front == -1) {
        // Queue is empty, nothing to remove.
        return;
    }
    
    // If this is the last element in the queue
    if (front == rear) {
        // Reset the queue to an empty state
        front = -1;
        rear = -1;
    } else {
        // Move front to the next position in a circular manner
        front = (front + 1) % MAX_SIZE;
    }
}

/**
 * @brief Prints the elements of the queue from front to rear.
 */
void printQueue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    
    int i;
    // Loop from the front to the rear, handling the circular wrap-around
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    // Print the last element (at the rear index)
    printf("%d\n", queue[i]);
}

int main() {
    int n; // Number of operations
    scanf("%d", &n);
    
    int op_type, value;
    
    // Loop to process all operations
    for (int i = 0; i < n; i++) {
        scanf("%d", &op_type);
        
        if (op_type == 1) { // Enqueue operation
            scanf("%d", &value);
            enqueue(value);
        } else if (op_type == 2) { // Dequeue operation
            dequeue();
        }
    }
    
    // After all operations are done, print the final state of the queue
    printQueue();
    
    return 0;
}
