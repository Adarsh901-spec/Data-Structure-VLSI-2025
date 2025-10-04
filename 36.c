#include <stdio.h>

/**
 * @brief Calculates the minimum number of moves for the Tower of Hanoi puzzle.
 *
 * @param n The number of discs.
 * @return The minimum number of moves required.
 */
long long calculate_hanoi_moves(int n) {
    // The formula for the minimum number of moves in Tower of Hanoi is 2^n - 1.
    // We can calculate 2^n efficiently using a bitwise left shift.
    // (1LL << n) shifts the bits of the long long value '1' to the left by 'n' positions,
    // which is equivalent to calculating 2 to the power of n.
    // Using 1LL ensures the calculation is done using long long to prevent overflow
    // for larger values of n.
    return (1LL << n) - 1;
}

int main() {
    int n;

    // Read the number of discs from standard input.
    scanf("%d", &n);
    
    // Calculate and print the result.
    printf("%lld\n", calculate_hanoi_moves(n));
    
    return 0;
}
