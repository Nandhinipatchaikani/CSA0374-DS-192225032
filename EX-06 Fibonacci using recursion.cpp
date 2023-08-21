#include <stdio.h>

int main() {
    int numTerms;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &numTerms);

    if (numTerms <= 0) {
        printf("Please enter a positive number of terms.\n");
    } else {
        int term1 = 0, term2 = 1, nextTerm;

        printf("Fibonacci sequence up to %d terms:\n", numTerms);
        printf("%d, %d", term1, term2);

        for (int i = 3; i <= numTerms; i++) {
            nextTerm = term1 + term2;
            printf(", %d", nextTerm);
            term1 = term2;
            term2 = nextTerm;
        }
        printf("\n");
    }

    return 0;
}

