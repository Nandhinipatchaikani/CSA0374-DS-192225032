#include <stdio.h>
void multiplyMatrices(int m1, int n1, int mat1[][n1], int m2, int n2, int mat2[][n2], int result[][n2]) {
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int m, int n, int mat[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1, n1, m2, n2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &m2, &n2);

    if (n1 != m2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int mat1[m1][n1], mat2[m2][n2], result[m1][n2];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    multiplyMatrices(m1, n1, mat1, m2, n2, mat2, result);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(m1, n2, result);

    return 0;
}

