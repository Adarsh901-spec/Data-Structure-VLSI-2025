#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a doubly linked list
struct Node* reverseDoublyLinkedList(struct Node *head) {
    struct Node *current = head;
    struct Node *temp = NULL;

    while (current != NULL) {
        // Swap next and prev pointers for the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is now the previous node)
        current = current->prev;
    }

    // If the list was not empty, update the head to the last node
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

// Function to print a doubly linked list
void printDoublyLinkedList(struct Node *head) {
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

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Reverse the doubly linked list
    head = reverseDoublyLinkedList(head);

    // Print the reversed doubly linked list
    printDoublyLinkedList(head);

    // Free the memory allocated for the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}