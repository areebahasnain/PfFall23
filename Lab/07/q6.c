// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: checking frequency of the array

#include <stdio.h>

int main() {
    int N;

    printf("Enter the size of the array: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid input");
        return 0;
    }

    int arr[N];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int frequency[N];
    for (int i = 0; i < N; i++) {
        frequency[i] = -1;
    }

    // Calculate frequencies
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = 0; // Mark as counted
            }
        }
        if (frequency[i] != 0) {
            frequency[i] = count;
        }
    }

    // Display frequencies
    printf("Element frequencies:\n");
    for (int i = 0; i < N; i++) {
        if (frequency[i] != 0) {
            printf("Frequency of %d = %d\n", arr[i], frequency[i]);
        }
    }

    return 0;
}
