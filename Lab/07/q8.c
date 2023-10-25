// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: Sorting array in ascending order

#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    
    // Taking input
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // Output
    printf("Sorted array in ascending order: ");
    for (int n = 0; n < size; n++) {
        printf("%d ", arr[n]);
    }

    return 0;
}
