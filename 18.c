#include <stdio.h>
#include <stdlib.h>

// Node structure for the double-linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global head pointer
struct Node* head = NULL;


void insertAtEnd(int data) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL; 

    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    
    last->next = newNode;
    newNode->prev = last;
}


void deleteNode(int data) {
    struct Node* temp = head;

    
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

   
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

  
    if (temp == NULL) {
        return;
    }

   
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf(" \n");
}

int main() {
    int n, op, data;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op, &data);
        if (op == 1) {
            insertAtEnd(data);
        } else if (op == 2) {
            deleteNode(data);
        }
    }

    printList();

   
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    return 0;
}