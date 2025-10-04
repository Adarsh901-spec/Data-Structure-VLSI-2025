#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in a polynomial
struct Node {
    int coeff; // Coefficient
    int exp;   // Exponent
    struct Node *next;
};

/**
 * @brief Inserts a new term at the end of a polynomial linked list.
 */
void insertTerm(struct Node **poly, int coeff, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        // Otherwise, traverse to the end and append the new node
        struct Node *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/**
 * @brief Adds two polynomials represented by linked lists.
 * @return A new linked list representing the sum.
 */
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    // Traverse both lists and add terms
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else { // Exponents are equal
            int sum_coeff = p1->coeff + p2->coeff;
            // Only add the term if the resulting coefficient is not zero
            if (sum_coeff != 0) {
                insertTerm(&result, sum_coeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add any remaining terms from the first polynomial
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Add any remaining terms from the second polynomial
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

/**
 * @brief Prints a polynomial in the format: ax^b + cx^d ...
 */
void printPolynomial(struct Node *poly) {
    if (poly == NULL) {
        // If the polynomial is empty (e.g., result of adding P and -P)
        printf("0\n"); // Or just a newline as per convention
        return;
    }
    struct Node *temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Frees all nodes in a linked list to prevent memory leaks.
 */
void freePolynomial(struct Node *poly) {
    struct Node *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}


int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;
    int n, coeff, exp;

    // Read and create the first polynomial
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Read and create the second polynomial
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Print the input polynomials
    printPolynomial(poly1);
    printPolynomial(poly2);

    // Add the polynomials and store the result
    result = addPolynomials(poly1, poly2);

    // Print the resulting polynomial
    printPolynomial(result);
    
    // Free the memory allocated for all lists
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
