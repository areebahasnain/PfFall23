// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: Matrix Multiplication

#include <stdio.h>

int main() {
    int r, c; // r: row, c: column of the first matrix
    int p, q; // p: row, q: column of the second matrix

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r, &c);

    int matrix1[r][c], matrix2[p][q], result[r][q]; 

    // Taking input for the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &p, &q);

    // Taking input for the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (c != p) { //checking matrix multiplication condition
        printf("Matrices with entered dimensions cannot be multiplied with each other\n");
        return 0;
    }

    // Matrix Multiplication
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display the result
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
