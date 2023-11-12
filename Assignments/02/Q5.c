// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: Ramanujan-Hardy Numbers upto n^2
#include <stdio.h>
#include <math.h>

int main() {
    int n; 
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Ramanujan-Hardy numbers up to %d^2 are:\n", n);

    for (int i = 1; i <= n*n; i++) {
        for (int j = i + 1; j <= n*n; j++) {
            int num1 = pow(i, 3) + pow(j, 3);

            for (int a = i + 1; a <= n*n; a++) {
                for (int b = a + 1; b <= n*n; b++) {
                    int num2 = pow(a, 3) + pow(b, 3);

                    if (num1 == num2) {
                        printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", num1, i, j, a, b);
                    }
                }
            }
        }
    }

    return 0;
}
