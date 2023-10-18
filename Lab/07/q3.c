// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: Count the sum of the digits
#include <stdio.h>

int main() {
   int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }

    printf("Sum: %d", sum);
    return 0;
} // end main()