// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: Finding persistence for indefinite amount of numbers until EOF

#include <stdio.h>

int main()
{
    int num;
    while (1) {
        int count = 0;
        printf("Enter number: ");
        scanf("%d", &num);

        // checking if the number is not 1 digit
        while (num > 9) {
            int new_num = 1;

            // find the product of all digits
            for (; num > 0; num /= 10) {
                new_num *= num % 10;
            }

            // make num the product of the previous num's digit
            num = new_num;

            // keep track of the amount of times this has been done
            if(num==0) count = count;
            else count++;
        }
        // output
        printf("\nPersistence is %d\n", count);
    }
    return 0;
}
