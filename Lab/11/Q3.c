// Programmer: Areeba Hasnain
// Description: Make a structure named Date to store the elements day, month and year to store two dates. 
// If the dates are equal, display "Dates are equal" otherwise display "Dates are not equal".

#include <stdio.h>

// Define the structure for a date
struct Date {
    int day;
    int month;
    int year;
} date1, date2;

// Function to compare two dates
int compareDates(struct Date date1, struct Date date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return 1; // Dates are equal
    } else {
        return 0; // Dates are not equal
    }
}

int main() {

    // Prompt user to enter details for the first date
    printf("Enter details for the first date:\n");
    printf("Day: ");
    scanf("%d", &date1.day);
    printf("Month: ");
    scanf("%d", &date1.month);
    printf("Year: ");
    scanf("%d", &date1.year);

    // Prompt user to enter details for the second date
    printf("Enter details for the second date:\n");
    printf("Day: ");
    scanf("%d", &date2.day);
    printf("Month: ");
    scanf("%d", &date2.month);
    printf("Year: ");
    scanf("%d", &date2.year);

    // Compare the two dates
    if (compareDates(date1, date2)) {
        printf("Dates are equal.\n");
    } else {
        printf("Dates are not equal.\n");
    }

    return 0;
}
