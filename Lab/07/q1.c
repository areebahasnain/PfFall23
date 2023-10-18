// Programmer: Areeba Hasnain
// Date: 10/10/2023
// Description: divivde 2 numbers without using division operator
#include <stdio.h>

int main() {
   
   int num, den;
   printf("Enter numerator: ");
   scanf("%d", &num);
   printf("Enter denominator: ");
   scanf("%d", &den);
   
   int ans=0;
   
   while (num >= den) {
       num-=den;
       ans++;
   }
   printf("the quotient is %d", ans);
    return 0;
}