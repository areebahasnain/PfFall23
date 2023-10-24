// Programmer: Areeba Hasnain
// Date: 24/10/23
// Description: swapping two integers using a user-defined function

#include<stdio.h>

void swapIntegers(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("\nAfter swapping: \nnum1 = %d\nnum2 = %d\n", a, b);
   
}


int main()
{
    int num1, num2;
   
    printf("Enter two integers you want to swap: ");
    scanf("%d%d", &num1, &num2);
   
    printf("\nBefore swapping: \nnum1 = %d\nnum2 = %d\n", num1, num2);
   
   // call the swapIntegers function to swap the values
    swapIntegers(num1, num2);
   
   
    return 0;
}