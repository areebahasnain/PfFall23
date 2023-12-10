// Programmer: Areeba Hasnain
// Description: Define a structure to store information about employees, including their names, salaries, and hours worked per day.
// Increase their salaries based on specified criteria, and finally print the names and final salaries of the employees.

#include <stdio.h>

// Structure to store information about employees
struct Employee {
    char name[50];
    double salary;
    int hoursWorkedPerDay;
};

// Function to increase salary based on hours worked
void increaseSalary(struct Employee *employee) {
    if (employee->hoursWorkedPerDay >= 12) {
        employee->salary += 150.0;
    } else if (employee->hoursWorkedPerDay >= 10) {
        employee->salary += 100.0;
    } else if (employee->hoursWorkedPerDay >= 8) {
        employee->salary += 50.0;
    }
}

int main() {
    // Array to store information about 10 employees
    struct Employee employees[10];

    // Input employee information
    for (int i = 0; i < 10; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
        printf("Hours of work per day: ");
        scanf("%d", &employees[i].hoursWorkedPerDay);
        printf("\n");
    }

    // Increase salary based on hours worked
    for (int i = 0; i < 10; i++) {
        increaseSalary(&employees[i]);
    }

    // Print the name and final salary of all employees
    printf("Name\tFinal Salary\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t$%.2lf\n", employees[i].name, employees[i].salary);
    }

    return 0;
}
