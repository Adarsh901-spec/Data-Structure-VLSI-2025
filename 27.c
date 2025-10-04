#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

/**
 * @brief Detects a loop in a linked list using Floyd's Tortoise and Hare algorithm.
 * * @param head A pointer to the head of the linked list.
 * @return `true` if a loop is found, otherwise `false`.
 */
bool detectLoop(struct Node *head) {
    // Initialize two pointers, slow and fast, to the head of the list.
    struct Node *slow_p = head, *fast_p = head;

    // Traverse the list. The slow pointer moves one step at a time, 
    // and the fast pointer moves two steps at a time.
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        
        // If the pointers meet at any point, a loop is confirmed.
        if (slow_p == fast_p) {
            return true;
        }
    }
    
    // If the fast pointer reaches the end of the list, there is no loop.
    return false;
}

int main() {
    int N, data, X, i;
    struct Node *head = NULL, *tail = NULL;

    // Input the number of nodes
    scanf("%d", &N);

    // Create the linked list from user input
    for (i = 0; i < N; i++) {
        scanf("%d", &data);
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) return 1; // Memory allocation check
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Input the loop position
    scanf("%d", &X);

    // Create the loop if X is a valid position (1-based)
    if (X > 0 && X <= N) {
        struct Node *loopNode = head;
        for (i = 1; i < X; i++) {
            loopNode = loopNode->next;
        }
        // Connect the tail to the X-th node
        if (tail != NULL) {
            tail->next = loopNode;
        }
    }

    // Detect the loop
    bool hasLoop = detectLoop(head);

    if(hasLoop) {
        printf("True\n");
        // NOTE: We cannot free a list with a loop using simple traversal.
        // The program will exit here, and the OS will reclaim the memory.
    } else {
        printf("False\n");
        // If there's no loop, we can safely free the memory to prevent leaks.
        struct Node *current = head;
        struct Node *next_node;
        while(current != NULL) {
            next_node = current->next;
            free(current);
            current = next_node;
        }
    }
    
    return 0;
}
