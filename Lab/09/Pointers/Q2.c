// Programmer: Areeba Hasnain
// Date: 31/10/23
// Description: reversing array using function and pointers
#include<stdio.h>

void reverse(int *ptr, int size){  // *ptr stores the address of the first element
    
    int *start=ptr;       // index 0 for the first element of  the array
    int *end=ptr+size-1; // index 9 for last element of the array
   
    while(start < end){
        int temp=*start;  // store the first element of the array in temp
        *start=*end;     // change the first element to the last element
        *end=temp;      // change the last element to the first element
       
        end--;
        start++;
    }
}

int main(){
    int arr[10];
    printf("Enter 10 integers: ");
    for(int i=0; i<10; i++){
        scanf("%d",&arr[i]);
    }
    printf("Original Array:\n");
    for(int i=0; i<10; i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
   
    reverse(arr,10);
     printf("Reversed Array:\n");
     for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
return 0;
}