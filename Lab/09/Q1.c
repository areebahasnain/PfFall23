// Programmer: Areeba Hasnain
// Date: 31/10/23
// Description: Modifying the function swap

//answer:- We need to use pointers to pass the addresses
#include<stdio.h>

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main(){
    int j=2, k=5;
    printf("j=%d, k=%d\n", j,k);
    swap(&j,&k);
    printf("j=%d, k=%d\n", j,k);
    return 0;
}