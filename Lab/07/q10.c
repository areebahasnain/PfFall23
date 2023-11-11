// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: finding a continuous sub-array which adds to a given number S.
#include <stdio.h>

int input(int *arr) {
    int n;
    do {
        printf("Enter size of array: ");
        scanf("%d", &n);
    } while (n > 99 || n < 1);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &(*(arr + i)));
    }
    return n;
} // end input(int *)

void subarray(int *arr, int n, int s) {
    for (int i = 0; i < n; i++) {
        for (int j = i, sum = 0; j < n && sum < s; j++) {
            sum += arr[j];
            // checking sum after adding to see if it's equal to user input
            if (sum == s) { printf("%d to %d", i, j); return; }
        }
    }
    printf("No subarray");
    return;
} // end subarray(int *, int, int)

int main() {
    int arr[100];
    int s;

    int n = input(arr);

    printf("Enter 's': ");
    scanf("%d", &s);

    subarray(arr, n, s);

    return 0;
} // end main()