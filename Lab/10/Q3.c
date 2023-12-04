// Programmer: Areeba Hasnain
// Description: populate a 2-d array with consecutive prime numbers using Dynamic memory allocation
// Date:14/22/23

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    
    int i;
    for ( i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to fill a 2D array with consecutive prime numbers
void fillWithPrimes(int **arr, int rows, int cols) {
    int currentNum = 2;
    
    int i,j;
    for ( i = 0; i < rows; ++i) {
        for ( j = 0; j < cols; ++j) {
            // Find the next prime number
            while (!isPrime(currentNum)) {
                ++currentNum;
            }

            // Fill the array with the prime number
            arr[i][j] = currentNum;
            ++currentNum;
        }
    }
}

// Function to print a 2D array
void printArray(int **arr, int rows, int cols) {
    int i,j;
	for ( i = 0; i < rows; ++i) {
        for ( j = 0; j < cols; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols,i;

    // Get the dimensions of the 2D array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the 2D array
    int **primeArray = (int **)malloc(rows * sizeof(int *));
    for ( i = 0; i < rows; ++i) {
        primeArray[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill the 2D array with consecutive prime numbers
    fillWithPrimes(primeArray, rows, cols);

    // Print the filled 2D array
    printf("\n2D Array filled with consecutive prime numbers:\n");
    printArray(primeArray, rows, cols);

    // Free dynamically allocated memory
    for ( i = 0; i < rows; ++i) {
        free(primeArray[i]);
    }
    
    free(primeArray);

    return 0;
}