// Programmer: Areeba Hasnain
// Description:For this task you are creating a universal array printing function.
//             Create a function in C that takes a void* as an argument along with
// 			   size and some way of know what kind of data is stored. Then prints 
// 			   the values stored in the memory location pointed to by the void pointer.
// 			   Use appropriate casting.
// Date:14/11/23

#include <stdio.h>
#include <stdlib.h>

// Enum structure to represent data types
enum DataType {
    INT,
    DOUBLE,
    CHAR,
};

// Function to print the elements of an array
void printArray(void *arr, /*holds size of the array*/size_t size,/*holds size of one element in the array*/ size_t elementSize, enum DataType datatype) {
    // Cast the void pointer to the appropriate type
    char *ptr = (char *)arr;//this enables easy bitewise movement
    size_t i;//size_t 
    
    // Print each element in the array
    for ( i = 0; i < size; ++i) {
        // Use appropriate casting and format specifier based on the data type
        switch (datatype) {
            case INT:
                printf("%d", *((int *)ptr));
                break;
            case DOUBLE:
                printf("%.2f", *((double *)ptr));
                break;
            case CHAR:
                printf("%c", *((char *)ptr));
                break;
            // Add additional cases for other data types as needed
        }

        // Move the pointer to the next element in the array
        ptr += elementSize;

        // Print a space between elements
        if (i < size - 1) {
            printf(" ");
        }
    }

    // Print a newline at the end
    printf("\n");
}

int main() {
    // Example usage with dynamically allocated arrays
    int *intArray = (int *)malloc(5 * sizeof(int));
    double *doubleArray = (double *)calloc(5, sizeof(double));
    char *charArray = (char *)realloc(NULL, 5 * sizeof(char));
    int i;
    // Populate the arrays with values
    for ( i = 0; i < 5; ++i) {
        intArray[i] = i + 1;
        doubleArray[i] = (i + 1) * 1.1;
        charArray[i] = 'a' + i;
    }

    // Print integer array
    printf("Printing intArray: ");
    printArray(intArray, 5, sizeof(int), INT);

    // Print double array
    printf("Printing doubleArray: ");
    printArray(doubleArray, 5, sizeof(double), DOUBLE);

    // Print char array
    printf("Printing charArray: ");
    printArray(charArray, 5, sizeof(char), CHAR);

    // Free dynamically allocated memory
    free(intArray);
    free(doubleArray);
    free(charArray);

    return 0;
}