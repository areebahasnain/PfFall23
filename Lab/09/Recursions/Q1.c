// Programmer: Areeba Hasnain
// Date: 31/10/23
// Description: finding factorial
#include<stdio.h>

int factorial(int N){
        if(N==1){
         return 1;
        }
        else{
        int r=N*factorial(N-1);
        return r;
        }
}
int main(){ 
    int n, ans;
    printf("Enter a number: ");
    scanf("%d", &n);   
    ans=factorial(n);
    printf("Factorial of %d is %d",n, ans);
   
}