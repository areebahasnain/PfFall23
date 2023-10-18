// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: checking whether the 2D array is symmetric or not
#include<stdio.h>
#include<stdbool.h>

int main(){

    int r, c; // r: row, c: column
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    if(r!=c){
    printf("Not symmetric");
    return 0;
    } 

    int arr[r][c];

    //taking input for first matrix
    printf("enter the elements of the matrix: ");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
// Check if the matrix is symmetric
    bool isSymmetric = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != arr[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
} // end main()