#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the list
void insert(struct Node **head_ref, int new_data) {
    // 1. Allocate a new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // 2. Put in the data
    new_node->data = new_data;

    // 3. This new node is going to be the last node, so make its next as NULL
    new_node->next = NULL;

    // 4. If the Linked List is empty, then the new node is the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // 5. Else, traverse till the last node
    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Change the next of the last node
    last->next = new_node;
}

// Function to delete a node with the given key
void delete(struct Node **head_ref, int key) {
    // Store head node
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf(" ");
        }
        node = node->next;
    }
    printf(" \n");
}

int main() {
    int n, op, data;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op, &data);
        if (op == 1) {
            insert(&head, data);
        } else if (op == 2) {
            delete(&head, data);
        }
    }

    printList(head);

    // Free allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}