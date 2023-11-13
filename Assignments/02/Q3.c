// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: flight booking system that outputs flights based on preference and shows availability on selected day
#include <stdio.h>
#include <stdlib.h>

const char *days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

void get_preference(int arr[][2]) {
    int min = ~(1 << 31), min_day;

    // first preference
    printf("Flights available in the morning:\n");
    for (int i = 0; i < 5; i++) {
        if (arr[i][1] < min && arr[i][1] != 0) min = arr[i][1], min_day = i;
        if (arr[i][0]) (i - 4) ? printf("%s, ", days[i]) : printf("%s\n", days[i]);
    }
    
    if (min == ~(1 << 31))
        printf("No flights available in the morning.\n");
    else
        printf("Best option for morning flight on %s for price %d\n", days[min_day], min);

    printf("\nFlights available in the evening:\n");
    min = ~(1 << 31); // Reset min for evening
    for (int i = 5; i < 10; i++) {
        if (arr[i][1] < min && arr[i][1] != 0) min = arr[i][1], min_day = i % 5;
        if (arr[i][0]) (i - 9) ? printf("%s, ", days[i % 5]) : printf("%s\n", days[i % 5]);
    }
    
    if (min == ~(1 << 31))
        printf("No flights available in the evening.\n");
    else
        printf("Best option for evening flight on %s for price %d\n\n", days[min_day], min);
}

void get_flight(int arr[][2], int day) {
    if (day >= 1 && day <= 5) {
        if (arr[day - 1][0] || arr[day + 4][0])
            printf("\nFlight available on %s\n  Time  : Price\nMorning : %d\nEvening : %d", days[day - 1],
                   arr[day - 1][1], arr[day + 4][1]);
        else
            printf("\nNo flights available on %s", days[day - 1]);
    } else {
        printf("\nInvalid day. Please enter a number between 1 and 5.\n");
    }
}

int main() {
    int flights[10][2] = {
            // morning
            {1, 300},
            {1, 320},
            {0, 0},
            {1, 380},
            {1, 375},
            // evening
            {0, 0},
            {1, 310},
            {1, 280},
            {0, 0},
            {1, 400}
    };

    int day;

    get_preference(flights);
    printf("Select day (1 - 5): ");
    scanf("%d", &day);

    get_flight(flights, day);

    return 0;
}
