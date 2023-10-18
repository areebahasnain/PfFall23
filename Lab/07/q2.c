// Programmer: Areeba Hasnain
// Date:m 10/10/23 
// Description: rotate array left by d positions
#include <stdio.h>

int main() {
   int N, d;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    printf("Enter the value of d: "); // number of positions to rotate left
    scanf("%d", &d);
    d=d%N;  

    printf("Enter the elements of the array: ");
    int arr[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

   for(int i=0; i<d; i++){ 
       int temp=arr[0];              //  Save the first element of the array in temp
       for(int j=0; j<N-1; j++){
        arr[j]=arr[j+1];            // Shifting elements to the left by one position
       }
       arr[N-1]=temp;              // Assigning temp to the last element
   }
       

printf("The rotated array is:\n");
for(int i=0; i<N; i++){
    printf("%d\t", arr[i]);
}
return 0;
}

