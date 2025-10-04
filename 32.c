#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Checks if a string of brackets is balanced using a stack.
 *
 * @param str The input string containing brackets.
 * @return "Balanced" if the brackets are balanced, otherwise "Not balanced".
 */
char* BalancedBrackets(char *str) {
    int n = strlen(str);
    // The stack can be a simple char array since we know the max length.
    char stack[110]; // Max length 102 + buffer
    int top = -1;

    for (int i = 0; i < n; i++) {
        // If it's an opening bracket, push it onto the stack.
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } 
        // If it's a closing bracket, check for a match.
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            // If stack is empty, there's no matching opener.
            if (top == -1) {
                return "Not balanced";
            }
            
            char last = stack[top--]; // Pop the top element.
            
            // Check if the popped bracket matches the current closing one.
            if ((str[i] == ')' && last != '(') ||
                (str[i] == '}' && last != '{') ||
                (str[i] == ']' && last != '[')) {
                return "Not balanced";
            }
        }
    }
    
    // If the stack is empty at the end, it's balanced. Otherwise, not.
    return (top == -1) ? "Balanced" : "Not balanced";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1; // Exit if no command-line argument is provided.
    }
    char *str = argv[1];
    // Corrected printf statement with a valid format string.
    printf("%s\n", BalancedBrackets(str));
    return 0;
}

