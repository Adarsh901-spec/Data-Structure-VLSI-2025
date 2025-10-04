#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Merges two sorted short integer arrays into a single sorted array.
 *
 * @param list1 The first sorted array.
 * @param list1Len The number of elements in list1.
 * @param list2 The second sorted array.
 * @param list2Len The number of elements in list2.
 * @param resultsArr A pointer to the array where the merged result will be stored.
 * @return The total number of elements in the merged array.
 */
int mergeTwoSLL(short list1[], int list1Len, short list2[], int list2Len, short *resultsArr) {
    int i = 0; // Pointer for list1
    int j = 0; // Pointer for list2
    int k = 0; // Pointer for resultsArr

    // Traverse both arrays and insert the smaller element into resultsArr
    while (i < list1Len && j < list2Len) {
        if (list1[i] <= list2[j]) {
            resultsArr[k++] = list1[i++];
        } else {
            resultsArr[k++] = list2[j++];
        }
    }

    // Copy any remaining elements from list1
    while (i < list1Len) {
        resultsArr[k++] = list1[i++];
    }

    // Copy any remaining elements from list2
    while (j < list2Len) {
        resultsArr[k++] = list2[j++];
    }

    return k; // Return the total number of elements in the merged array
}

// Helper function to parse a comma-separated string into a short array
int readShortArray(char *argsArray, short arr[]) {
    int count = 0;
    // Handle empty input string case (e.g., "[]")
    if (argsArray == NULL || strlen(argsArray) == 0) {
        return 0;
    }
    
    char *token = strtok(argsArray, ",");
    while (token != NULL) {
        arr[count++] = (short)atoi(token); // Convert token to short and store
        token = strtok(NULL, ",");
    }
    return count;
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    if (argc < 3) {
        // The problem expects two arguments, but can handle empty lists.
        // For simplicity, we assume valid inputs are provided as per samples.
        return 1;
    }

    // Allocate arrays with a size larger than the constraint to be safe
    short list1[10005];
    short list2[10005];
    short resultsArr[20010];

    // Read and parse the command line arguments into integer arrays
    int list1Len = readShortArray(argv[1], list1);
    int list2Len = readShortArray(argv[2], list2);

    // Call the merge function
    int resultsLen = mergeTwoSLL(list1, list1Len, list2, list2Len, resultsArr);

    // Print the merged and sorted array
    for (int i = 0; i < resultsLen; i++) {
        printf("%d", resultsArr[i]);
        if (i < resultsLen - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
