// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: sorting data in ascending and descending order

#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortByAge(int shirtDetails[][2], int numShirts) {
    for (int i = 0; i < numShirts - 1; i++) {
        for (int j = 0; j < numShirts - i - 1; j++) {
            // Sort by age in ascending orde0r of ages
            if(shirtDetails[j][0] > shirtDetails[j + 1][0]) {
                swap(&shirtDetails[j][0], &shirtDetails[j + 1][0]);
                swap(&shirtDetails[j][1], &shirtDetails[j + 1][1]);
            }
        }
    }
    printf("Sorted list in ascending order with respect to Age:\n");
    printf("Age\tPrice\n");
    for (int i = 0; i < numShirts; i++) {
        printf("%d\t%d\n", shirtDetails[i][0], shirtDetails[i][1]);
    }
    printf("\n");
}

void sortByPrice(int shirtDetails[][2], int numShirts) {
    for (int j = 0; j < numShirts - 1; j++) {
        for (int i = 0; i < numShirts - 1; i++) {
            // Sort by price in descending order
            if(shirtDetails[i][1] < shirtDetails[i + 1][1]) {
                swap(&shirtDetails[i][0], &shirtDetails[i + 1][0]);
                swap(&shirtDetails[i][1], &shirtDetails[i + 1][1]);
            }
        }
    }
    printf("Sorted list in descending order with respect to Price:\n");
    printf("Age\tPrice\n");
    for (int i = 0; i < numShirts; i++) {
        printf("%d\t%d\n", shirtDetails[i][0], shirtDetails[i][1]);
    }
    printf("\n");
}
    
int main() {
    // Example data for shirts (age and price)
    int shirtDetails[][2] = {
        {10, 30},
        {20, 70},
        {30, 50},
        {15, 25}
    };

    int numShirts = 4;

    printf("Original list:\n");
    printf("Age\tPrice\n");
    for (int i = 0; i < numShirts; i++) {
        printf("%d\t%d\n", shirtDetails[i][0], shirtDetails[i][1]);
    }
    printf("\n");

    sortByAge(shirtDetails, numShirts);

    sortByPrice(shirtDetails, numShirts);

    return 0;
}
