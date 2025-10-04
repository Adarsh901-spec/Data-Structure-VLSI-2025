#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Merges two sorted arrays, nums2 into nums1, in-place.
 *
 * @param nums1 The first array, with space for m + n elements.
 * @param m The number of initialized elements in nums1.
 * @param nums2 The second array.
 * @param n The number of elements in nums2.
 */
void merge(int* nums1, int m, int* nums2, int n) {
    // Pointer for the last element of the initial nums1
    int p1 = m - 1;
    // Pointer for the last element of nums2
    int p2 = n - 1;
    // Pointer for the last position in the merged nums1 array
    int p = m + n - 1;

    // Merge in reverse order
    while (p2 >= 0) {
        // If p1 is in bounds and its element is larger, place it at the end
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            // Otherwise, place the element from nums2 at the end
            nums1[p] = nums2[p2];
            p2--;
        }
        // Move to the next position from the end
        p--;
    }
}

/**
 * @brief Prints an array in the format [x,y,z].
 */
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Using static arrays with a size larger than typical constraints
    int nums1[200];
    int nums2[100];
    int m, n;
    int temp, i = 0;

    // Reading a line of space-separated integers for nums1
    while (scanf("%d", &temp) == 1) {
        nums1[i++] = temp;
        // Stop reading if the next character is a newline
        if (getchar() == '\n') {
            break;
        }
    }

    scanf("%d", &m);

    // Reading a line of space-separated integers for nums2
    i = 0;
    while (scanf("%d", &temp) == 1) {
        nums2[i++] = temp;
        if (getchar() == '\n') {
            break;
        }
    }

    scanf("%d", &n);

    // Perform the merge operation
    merge(nums1, m, nums2, n);

    // Print the final merged and sorted array
    printArray(nums1, m + n);

    return 0;
}