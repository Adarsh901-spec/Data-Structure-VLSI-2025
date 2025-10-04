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

// Function to find the midpoint of the linked list
int findMidpoint(struct Node *head) {
    struct Node *slowPtr = head;
    struct Node *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr->data;
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

    // Find and print the midpoint
    printf("%d\n", findMidpoint(head));

     struct Node *current = head;
        while (current != NULL) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }

    return 0;
}