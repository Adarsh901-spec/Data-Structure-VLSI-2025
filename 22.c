#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if a linked list is a palindrome
bool isPalindrome(struct Node *head) {
    if (head == NULL) {
        return true; // Empty list is a palindrome
    }

    // Store the linked list elements in an array
    int arr[100000]; // Assuming a maximum size of 100000, adjust accordingly
    int size = 0;
    struct Node *current = head;

    while (current != NULL) {
        arr[size++] = current->data;
        current = current->next;
    }

    // Check if the array is a palindrome
    int left = 0;
    int right = size - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // It's a palindrome
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    bool results[numTestCases];
    for (int i = 0; i < numTestCases; i++) {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int data;

        // Read the linked list elements
        while (scanf("%d", &data) == 1 && data != -1) {
            struct Node *newNode = createNode(data);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        results[i] = isPalindrome(head);

        // Free the memory allocated for the linked list
        struct Node *current = head;
        while (current != NULL) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    for (int i = 0; i < numTestCases; i++) {
        printf("%s\n", results[i] ? "true" : "false");
    }

    return 0;
}