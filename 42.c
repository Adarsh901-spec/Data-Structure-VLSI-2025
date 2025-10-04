#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    Node *result = NULL;

    if (strcmp(left->data, right->data) <= 0) {
        result = left;
        result->next = merge(left->next, right);
        if (result->next) result->next->prev = result;
    } else {
        result = right;
        result->next = merge(left, right->next);
        if (result->next) result->next->prev = result;
    }

    return result;
}

Node *mergeSortList(Node *head) {
    if (!head || !head->next) return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *midNext = slow->next;
    slow->next = NULL;
    if (midNext) midNext->prev = NULL; 

    Node *left = mergeSortList(head);
    Node *right = mergeSortList(midNext);

    return merge(left, right);
}

char *linkedListToString(Node *head) {
    char *result = (char *)malloc(1); 
    result[0] = '\0'; 
    Node *current = head;

    while (current) {
        char *temp;
        if (strlen(result) == 0) {
            asprintf(&temp, "%s", current->data);
        } else {
            asprintf(&temp, "%s -> %s", result, current->data);
            free(result);
        }
        result = temp;
        current = current->next;
    }

    return result;
}

char * mergeSort(char *Arr[], int ArrLen) {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < ArrLen; i++) {
        Node *newNode = createNode(Arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    head = mergeSortList(head);

    char *result = linkedListToString(head);

    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp->data); 
        free(temp); 
    }

    return result;
}

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

int main(int argc, char *argv[]) {
    char *Arr[100000];
    int ArrLen = readStringArray(argv[1], Arr);
    printf("%s\n", mergeSort(Arr, ArrLen));
    return 0;
}