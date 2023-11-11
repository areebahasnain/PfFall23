// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: Finding all different pairs that have a sum equal to t

#include<stdio.h>

int main()
{
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nThe array is:\n");
    for(int i=0; i<N; i++){
        printf("%d\t", arr[i]);
    }

    int t;
    printf("\n");
    printf("\nEnter the value of t: "); 
    scanf("%d", &t);

    printf("\nThe pairs in the array whose sum is equal to %d are: ", t);
    
    for(int i=0; i<=N; i++){
        for(int j=i+1; j<=N; j++){
           if(arr[i] + arr[j] == t){
            printf("\n(%d %d)", arr[i],arr[j]);
           }
        }
    }

    return 0;
}