#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;


void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
}


void deleteNode(int data) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    
    do {
        if (current->data == data) {
            break; 
        }
        prev = current;
        current = current->next;
    } while (current != head);

    
    if (current == head && current->data != data && prev==NULL) {
        return;
    }
     if (current == head && current->data != data) {
          return;
     }

    

    
    if (current == head && current->next == head)
    {
         if(current->data == data){
                free(current);
                head = NULL;
                return;
         } else {
              return;
         }
        
    }
   

    if (current == head) {
         struct Node* last = head;
              while (last->next != head) {
                   last = last->next;
              }
              head = current->next;
              last->next = head;
                
    } else{
        prev->next = current->next;
    }
    
    
    free(current);
    
}


void printList() {
    if(head == NULL) return;
    
    struct Node* temp = head;
    do {
        printf("%d", temp->data);
        if (temp->next != head) {
            printf(" ");
        }
        temp = temp->next;
    } while (temp != head);
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
    struct Node* next;
    if(head){
      struct Node* last = head;
              while (last->next != head) {
                   last = last->next;
        }
        
    }
   

    return 0;
}