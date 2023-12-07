#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the Employee structure to represent individual employees
typedef struct {
	char name[20];
	char role[10];
	int communication;
	int teamWork;
	int creativity;
} Employee;

// Define arrays for department names, employee names, and employee roles
char *departmentNames[4] = {"HR", "Finance", "Marketing", "Logistics"};
char *employeeRoles[5] = {"Director", "Executive", "Manager", "Employee", "Trainee"};
char *employeeNames[20] = {"Alex Johnson", "Ella Miller", "Owen Smith", "Aria Davis", "Caleb Brown", "Paris Geller", "Nathan Taylor", "Ron Gryffin", "Neville Stardust", "Mila Brooks", "Jackson Anderson", "Aubrey Turner", "Aiden Sullivan", "Jackson Harrison", "Benjamin Garcia", "Emily Foster", "Aarav Khan", "Jess Mariano", "Dean Forester", "Aniket Desai"};

// Function to create an array of department structures
Employee **createDepartments()
{
    // Allocate memory for the array of department pointers
	Employee **departments = (Employee **)malloc(sizeof(Employee *) * 4);
    // Assign each department pointer to a corresponding block of employee structures
	Employee *employees = (Employee *)malloc(sizeof(Employee) * 5*4);

	for (int i = 0; i < 4; i++) departments[i] = &employees[i*5];

	return departments;
}

// Function to print the header and details of employees for a given department
void printEmployees(Employee *department)
{
    // Print the header of the table
	printf("%7c%-12s|%9s%4c|%15s%-2c|%11s%-2c|%12s%-2c|\n", 
		' ', "Name", "Role", ' ', "Communication", ' ', "Team Work", ' ', "Creativity", ' '
	);
    // Iterate through each employee in the department and print their details
	for (int i = 0, index; i < 5; i++) {
		printf("%2c%-17s|%2c%-11s|%10d%-7c|%8d%-5c|%8d%-6c|\n",
			' ', department[i].name, ' ', department[i].role, department[i].communication, ' ', department[i].teamWork, ' ', department[i].creativity, ' '
		);
	}
}

// Function to randomly assign roles, names, and skills to employees in a department
int assignEmployees(Employee *department)
{
    // Array to check if a role has been assigned
	bool rolesCheck[5] = {true, true, true, true, true};

	for (int i = 0, indexName, indexRole; i < 5; i++) {
        // Randomly select an employee name that has not been used
		do {
			indexName = rand() % 20; 
		} while (employeeNames[indexName] == NULL);
		// Randomly select a role that has not been assigned
		do {
			indexRole = rand() % 5; 
		} while (rolesCheck[indexRole] == false);
		// Assign the selected role, name, and random skills to the employee
		strcpy(department[i].role, employeeRoles[indexRole]);
		strcpy(department[i].name, employeeNames[indexName]);

		department[i].communication = rand() % 100 + 1;
		department[i].teamWork = rand() % 100 + 1;
		department[i].creativity = rand() % 100 + 1;
		
        // Mark the assigned name and role to avoid reuse
		employeeNames[indexName] = NULL, rolesCheck[indexRole] = false;
	}
	
	return 0;
}

// Function to determine the department with the highest combined skills
int HighestSkills(Employee **departments)
{
	int maxStats = 1 << 31, totalStats = 0, highestDepartment;
	for (int i = 0; i < 4; i++) {
		totalStats = 0;
        
        // Calculate the total skills for all employees in the department
		for (int j = 0; j < 5; j++) {
			totalStats += departments[i][j].communication + departments[i][j].teamWork + departments[i][j].creativity;
		}
		// Update the highest department if the current department has higher total skills
		if (totalStats > maxStats) maxStats = totalStats, highestDepartment = i;
	}

	return highestDepartment;
}

int main()
{
    printf("\nName: Areeba Hasnain\nID:23K-0059\n");
    srand(NULL);

	Employee **departments = createDepartments();

	for (int i = 0; i < 4; i++) assignEmployees(departments[i]);
	int k = HighestSkills(departments);	

	for (int i = 0; i < 4; i++) {
		if (i == k) continue;
		printf("%20cEmployees of department: %s\n", ' ', departmentNames[i]);
		printEmployees(departments[i]);
		printf("\n");
	}

	printf("%20cBest department award goes to: %s\n", ' ', departmentNames[k]);
	printEmployees(departments[k]);

	return 0;
}
