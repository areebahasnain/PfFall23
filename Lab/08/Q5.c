// Programmer: Areeba Hasnain
// Date: 24/10/23
// Description:

#include <stdio.h>

int decideCarUsage(int numeric, int day){
    if ((numeric%2 == 0 && day%2 == 0) || (numeric%2 != 0 && day%2 != 0)){
        return 1; //use the car
    }
    else return 0; // do not use the car
   
}
int main()
{
     int numeric, day;
     printf("Enter the numeric part of the car: ");
     scanf("%d", &numeric);
     printf("Enter the day: ");
     scanf("%d", &day);
     
     if(day<1 || day>7 ){
         printf("Invalid input. There are 7 days in a week");
     }
     else if (decideCarUsage(numeric, day)){
         printf("You should use your car on this day\n ");
     }
     else{
         printf("You should not use your car on this day\n ");
     }

}
