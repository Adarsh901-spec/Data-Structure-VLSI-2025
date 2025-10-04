#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse the linked list in-place
struct Node* reverseLinkedList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the pointer of current node
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    head = prev; // The new head will be the previous node
    return head;
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf(" \n");
}

int main() {
    int n, data;
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Input the number of nodes
    scanf("%d", &n);

    // Create the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    printLinkedList(head);

    // Free the memory allocated for the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}