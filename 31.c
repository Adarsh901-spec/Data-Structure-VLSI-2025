#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- Stack Implementation ---
// A simple character stack implementation for this problem.
// A global stack is used for simplicity to avoid passing it as a parameter.
#define MAX_EXPR_SIZE 100005
char stack[MAX_EXPR_SIZE];
int top = -1;

// Pushes an item onto the stack.
void push(char item) {
    if (top >= MAX_EXPR_SIZE - 1) {
        return; // Stack overflow, should not happen with given constraints
    }
    stack[++top] = item;
}

// Pops an item from the stack.
char pop() {
    if (top < 0) {
        return '\0'; // Indicates an empty stack
    }
    return stack[top--];
}

// Returns the top item of the stack without removing it.
char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

// Checks if the stack is empty.
int isEmpty() {
    return top == -1;
}
// --- End of Stack Implementation ---


// --- Helper Functions ---
// Function to check if a character is an operand (letter or digit).
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to return the precedence of an operator.
// Higher value means higher precedence.
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^': // Exponentiation has the highest precedence
            return 3;
    }
    return -1; // Not an operator (e.g., parenthesis)
}
// --- End of Helper Functions ---


/**
 * @brief Converts an infix expression to a postfix expression.
 *
 * This function implements the Shunting-yard algorithm to perform the conversion.
 * It correctly handles operator precedence and associativity.
 *
 * @param expr The input string containing the infix expression.
 * @return A dynamically allocated string containing the equivalent postfix expression.
 */
char * InfixToPostfix(char *expr) {
	// Write code here
    // Reset the global stack for the new expression
    top = -1;
    int i;
    int k = 0; // Index for the postfix string
    int len = strlen(expr);

    // Allocate memory for the postfix string.
    char *postfix = (char*)malloc((len + 1) * sizeof(char));
    if (!postfix) {
        // Handle memory allocation failure
        return NULL;
    }

    // 1. Iterate through the infix expression character by character.
    for (i = 0; i < len; i++) {
        char currentChar = expr[i];

        // 2. If the character is an operand, add it to the postfix string.
        if (isOperand(currentChar)) {
            postfix[k++] = currentChar;
        }
        // 3. If the character is an opening parenthesis '(', push it onto the stack.
        else if (currentChar == '(') {
            push(currentChar);
        }
        // 4. If the character is a closing parenthesis ')', pop from the stack
        //    to the postfix string until an opening parenthesis is found.
        else if (currentChar == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Pop the opening parenthesis '(' and discard it.
        }
        // 5. If an operator is encountered.
        else {
            // Pop operators from the stack that have higher or equal precedence.
            // Note: '^' is right-associative, so we only pop if top has strictly higher precedence.
            // All other operators are left-associative.
            if (currentChar == '^') { // Right-associative case
                 while (!isEmpty() && peek() != '(' && precedence(currentChar) < precedence(peek())) {
                    postfix[k++] = pop();
                }
            } else { // Left-associative case
                 while (!isEmpty() && peek() != '(' && precedence(currentChar) <= precedence(peek())) {
                    postfix[k++] = pop();
                }
            }
            // Push the current operator onto the stack.
            push(currentChar);
        }
    }

    // 6. After the loop, pop all remaining operators from the stack to the postfix string.
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    // 7. Null-terminate the resulting postfix string.
    postfix[k] = '\0';

    return postfix;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"<infix_expression>\"\n", argv[0]);
        return 1;
    }
	char *expr = argv[1];
    char *postfix_result = InfixToPostfix(expr);
    if (postfix_result) {
	    printf("%s\n", postfix_result);
        free(postfix_result); // Good practice to free allocated memory
    }
	return 0;
}