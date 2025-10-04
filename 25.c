#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure for the Doubly Linked List
struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
};

/**
 * @brief Creates a doubly linked list from a string array and finds its midpoint.
 *
 * @param N The expected number of elements (not directly used, ArrLen is used).
 * @param Arr An array of strings to populate the list.
 * @param ArrLen The actual number of strings in the array.
 * @return A string containing the data from the midpoint node.
 */
char * midPoint(int N, char *Arr[], int ArrLen) {
    // Handle edge case for an empty or invalid input array
	if (ArrLen <= 0) {
        return "List is empty";
    }

    // --- 1. Build the Doubly Linked List ---
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < ArrLen; i++) {
        // Allocate memory for the new node
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            // Handle memory allocation failure
            return "Memory Error";
        }
        newNode->data = Arr[i];
        newNode->next = NULL;
        newNode->prev = tail; // Link to the previous node

        if (head == NULL) {
            // This is the first node
            head = newNode;
            tail = newNode;
        } else {
            // Append the new node to the end of the list
            tail->next = newNode;
            tail = newNode; // Update the tail pointer
        }
    }

    // --- 2. Find the Midpoint using Slow and Fast Pointers ---
    struct Node *slow = head;
    struct Node *fast = head;

    // Move fast pointer by two and slow pointer by one
    // The condition ensures that for even lists, we get the first of the two middle nodes
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Store the result before freeing the list
    char* midpoint_data = slow->data;

    // --- 3. Free the allocated memory for the list ---
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp); // Free each node
    }

    return midpoint_data;
}

// Helper function to parse the comma-separated string into an array of strings
int readStringArray(char *argsArray, char *arr[]) {
	int col = 0;
	char *token = strtok(argsArray, ",");
	while (token != NULL) {
		arr[col] = token;
		token = strtok(NULL, ",");
		col++;
	}
	return col;
}

// Main function to read arguments and call the midpoint function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        // Ensure correct number of command line arguments are provided
        return 1;
    }
	int N = atoi(argv[1]);
    // Allocate a sufficiently large array of char pointers
	char *Arr[strlen(argv[2])]; 
	int ArrLen = readStringArray(argv[2], Arr);
	printf("%s\n", midPoint(N, Arr, ArrLen));
	return 0;
}
