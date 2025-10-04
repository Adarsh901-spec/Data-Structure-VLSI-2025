#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Generates Fibonacci numbers up to N and stores them in an array.
 *
 * @param N The upper bound for the Fibonacci numbers.
 * @param resultsArr A pointer to an integer array to store the results.
 * @return The number of Fibonacci numbers found and stored in resultsArr.
 */
int fibonacciNumbers(int N, int *resultsArr) {
    int count = 0;
    // Use long long to avoid overflow during calculation, as Fibonacci numbers grow quickly.
    long long a = 0, b = 1;

    // Handle the first Fibonacci number, 0.
    if (N >= 0) {
        resultsArr[count] = 0;
        count++;
    } else {
        // If N is negative, the series is empty.
        return 0;
    }

    // Handle the second Fibonacci number, 1.
    if (N >= 1) {
        resultsArr[count] = 1;
        count++;
    }

    // Generate the rest of the Fibonacci numbers iteratively.
    while (1) {
        long long next = a + b;

        // Stop if the next number in the sequence exceeds N.
        if (next > N) {
            break;
        }
        
        // Store the valid Fibonacci number in the results array.
        resultsArr[count] = (int)next;
        count++;
        
        // Update the values for the next iteration.
        a = b;
        b = next;
    }
    
    // Return the total count of numbers in the series.
    return count;
}

int main(int argc, char *argv[]) {
    // Ensure a command-line argument is provided.
    if (argc < 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument string to an integer.
    int N = atoi(argv[1]);

    // Declare an array to store the results.
    // A size of 100 is sufficient, as the 25th Fibonacci number
    // already exceeds the constraint N <= 10^5.
    int resultsArr[100]; 
    int count;

    // Call the function to populate the array and get the count.
    count = fibonacciNumbers(N, resultsArr);

    // Print the results in the required comma-separated format.
    for (int i = 0; i < count; i++) {
        printf("%d", resultsArr[i]);
        // Add a comma if it's not the last element.
        if (i < count - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
