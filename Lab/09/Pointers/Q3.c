// Programmer: Areeba Hasnain
// Date: 31/10/23
// Description: Printing the addresses and values stored in 3 different types of arrays one by one using pointer arithmetic.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    time_t t;
    srand((unsigned) time(&t));

    int int_arr[100];
    char char_arr[100];
    long long int lli_arr[100];
    for (int i = 0; i < n; i++) {
        int_arr[i] = rand();
        char_arr[i] = (rand() % 27) + 65;
        lli_arr[i] = (long long int) rand();
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d\n", i+1);
        printf("pointer: int_arr = %p, char_arr = %p, lli_arr = %p\n", 
            (int_arr + i),
            (char_arr + i),
            (lli_arr + i)
        );
        printf("value: int_arr = %d, char_arr = %c, lli_arr = %lli\n\n", 
            *(int_arr + i),
            *(char_arr + i),
            *(lli_arr + i)
        );
    }

    
    return 0;
}

/* 
        Even though pointers are of the same size, the pointer type defines the memory block
        allotted. You can simply do e.g *(int_arr + i) and the compiler will automatically know 
        how much memory to traverse and doesn't require memory size for each datatype
*/