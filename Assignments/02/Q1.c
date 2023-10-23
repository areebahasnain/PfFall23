// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: using 2D arrays, calculate and display the performance of each player in a cricket team

#include<stdio.h>

int main()
{
    int batsmen, innings;
    printf("Enter the number of batsmen and the number of innings played: ");
    scanf("%d%d", &batsmen, &innings);

    int performance[batsmen][innings];
    for (int i=0, fifty=0, hundred=0, score=0, highest=0; i<batsmen; i++){
        for(int j=0; j<innings; j++){
            printf("\nEnter the total runs scored by the batsman #%02d in the inning #%02d: ", i+1, j+1);
            scanf("%d",&performance[i][j]);

            score+=performance[i][j]; // total runs scored

            if(highest<performance[i][j]){
                highest=performance[i][j]; //highest score in single inning
            }
            if (performance[i][j]>=50 && performance[i][j]<100){
                fifty++; // no. of half-centuries
            }
            if (performance[i][j]>50 && performance[i][j]>=100){
                hundred++; // no. of centuries
            } 
        }

        printf("\nTotal Score: %d\n", score);
        printf("\nAverage runs per inning: %.2f\n", (float) score/innings);
        printf("\nHighest score: %d\n", highest);
        printf("\nNo. of half-centuries: %d\n", fifty);
        printf("\nNo. of centuries: %d\n", hundred);
    }

    return 0;
}