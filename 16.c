#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OFFSET 1000000 // To shift negative numbers to positive indices
#define MAX_RANGE 2000001 // Range from -1,000,000 to 1,000,000 inclusive

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) {
        printf("-1\n");
        return 0;
    }

    // Validate the range of n
    if (n < 1 || n > 1000) {
        printf("-1\n");
        return 0;
    }

    // Consume the newline character left in the buffer by scanf
    getchar();

    // Allocate a buffer to read the line of numbers
    char line[5000];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        // Handle cases with no input line after n
        printf("-1\n");
        return 0;
    }

    int arr[1000];
    int count = 0;
    // Tokenize the line to extract individual numbers
    char *token = strtok(line, " \n");
    while (token != NULL) {
        // If more numbers are found than expected, print -1
        if (count >= n) {
            printf("-1\n");
            return 0;
        }
        arr[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    // If fewer numbers are found than expected, print -1
    if (count != n) {
        printf("-1\n");
        return 0;
    }

    // Use a static array for frequency to avoid stack overflow.
    // This is automatically initialized to zeros.
    static int freq[MAX_RANGE];

    // Count the frequency of each element using the offset
    for (int i = 0; i < n; i++) {
        freq[arr[i] + OFFSET]++;
    }

    // A copy of n is used as a counter to manage spacing
    int elements_left = n;
    // Output the sorted elements by iterating through the frequency array
    for (int i = 0; i < MAX_RANGE; i++) {
        while (freq[i] > 0) {
            printf("%d", i - OFFSET);
            elements_left--;
            // Print a space if it's not the last element
            if (elements_left > 0) {
                printf(" ");
            }
            // CRITICAL FIX: Decrement the frequency to avoid an infinite loop
            freq[i]--;
        }
    }
    printf("\n");

    return 0;
}
