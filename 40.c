#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Struct to hold the elements of the priority queue
typedef struct {
    int key;
    int value; // This field acts as the priority
    int time;  // Unique timestamp to track insertion order for tie-breaking
} Element;

// Global variables to manage the priority queue as a dynamic array
Element* pq = NULL;
int pq_size = 0;
int pq_capacity = 0;
int time_counter = 0; // Global counter to assign insertion times

/**
 * @brief Inserts a new element or updates an existing one.
 */
void insert_or_update(int key, int value) {
    // Search if the key already exists to perform an update.
    for (int i = 0; i < pq_size; i++) {
        if (pq[i].key == key) {
            pq[i].value = value; // Update value and return
            return;
        }
    }

    // If key was not found, insert a new element.
    // Ensure there is enough capacity in the dynamic array.
    if (pq_size == pq_capacity) {
        pq_capacity = (pq_capacity == 0) ? 10 : pq_capacity * 2;
        pq = realloc(pq, pq_capacity * sizeof(Element));
        if (pq == NULL) { exit(1); } // Handle memory allocation failure
    }
    
    // Add the new element to the end of the array.
    pq[pq_size].key = key;
    pq[pq_size].value = value;
    pq[pq_size].time = time_counter++; // Assign a unique, increasing timestamp
    pq_size++;
}

/**
 * @brief Deletes the element with the minimum priority (value).
 * If there's a tie in priority, the element inserted earliest is removed.
 */
void delete_min() {
    if (pq_size == 0) {
        return; // Nothing to delete
    }

    int min_val = INT_MAX;
    int min_time = INT_MAX;
    int min_idx = -1;

    // Find the index of the element with the minimum value, using time as a tie-breaker.
    for (int i = 0; i < pq_size; i++) {
        if (pq[i].value < min_val) {
            min_val = pq[i].value;
            min_time = pq[i].time;
            min_idx = i;
        } else if (pq[i].value == min_val) {
            if (pq[i].time < min_time) {
                min_time = pq[i].time;
                min_idx = i;
            }
        }
    }

    // Remove the element by swapping it with the last element and shrinking the size.
    if (min_idx != -1) {
        pq[min_idx] = pq[pq_size - 1];
        pq_size--;
    }
}

/**
 * @brief Comparison function for qsort.
 * Sorts primarily by value (ascending), then by key (ascending) for ties.
 */
int compare_elements(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;

    // Primary sort criterion: value
    if (elemA->value != elemB->value) {
        return elemA->value - elemB->value;
    }
    // Secondary sort criterion (if values are equal): key
    return elemA->key - elemB->key;
}

/**
 * @brief Prints the final priority queue, sorted according to the rules.
 */
void print_pq() {
    if (pq_size == 0) {
        printf("Empty\n");
        return;
    }

    // Sort the remaining elements before printing.
    qsort(pq, pq_size, sizeof(Element), compare_elements);

    for (int i = 0; i < pq_size; i++) {
        printf("%d (%d)", pq[i].key, pq[i].value);
        if (i < pq_size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}


int main() {
    int n, op, key, value;
    
    // Read number of operations
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &op) != 1) return 1;
        if (op == 1) {
            if (scanf("%d %d", &key, &value) != 2) return 1;
            insert_or_update(key, value);
        } else if (op == 2) {
            delete_min();
        }
    }

    print_pq();

    // Free the dynamically allocated memory
    if (pq != NULL) {
        free(pq);
    }

    return 0;
}

