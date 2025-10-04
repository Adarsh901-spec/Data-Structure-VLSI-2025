#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly circular linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node into the doubly circular linked list
struct Node* insert(struct Node *head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev; // Point last to the last node
        newNode->next = head;
        newNode->prev = last;
       
        head->prev = newNode; 
        last->next = newNode; // Update the last node
    }
    return head;
}

// Function to delete the last node from the doubly circular linked list
struct Node* deleteLast(struct Node *head) {
    if (head == NULL) {
        return NULL; // List is empty
    }

    if (head->next == head) {
        // Only one node in the list
        free(head);
        return NULL;
    }

    struct Node *last = head->prev;
    struct Node *secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
    return head;
}

// Function to traverse and print the doubly circular linked list
void traverse(struct Node *head) {
    if (head == NULL) {
        return;
    }

    struct Node *current = head;
    struct Node *first = head;
    do {
        printf("%d", current->data);
        if (current->next != first) {
            printf(" ");
        }
        current = current->next;
    } while (current != first);
    printf(" \n");
}

int main() {
    int n, op, data;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &data);
            head = insert(head, data);
        } else if (op == 2) {
            head = deleteLast(head);
        }
    }

    traverse(head);

    return 0;
}