// Programmer: Areeba Hasnain
// Description: Display the details of the workers having maximum salary for each department.

#include <stdio.h>
#include <string.h>

typedef struct {
    int worker_ref_id;
    char bonus_date[20];
    int bonus_amount;
} Bonus;

typedef struct {
    int worker_ref_id;
    char worker_title[15];
    char affected_from[20];
} Title;

typedef struct {
    char worker_id[4];
    char first_name[10];
    char last_name[10];
    int salary;
    char joining_date[20];
    char department[10];
} Worker;

// Array of department names
char *departs_name[3] = {"HR", "Admin", "Account"};

// Function to find the worker with the maximum salary in a given department
Worker max_salary_worker(Worker workers[], int n, char *depart) {
    int max_salary = 1 << 31, worker_index = 0;

    for (int i = 0; i < n; i++)
        if (!strcmp(workers[i].department, depart))
            if (workers[i].salary > max_salary)
                max_salary = workers[i].salary, worker_index = i;

    return workers[worker_index];
}

// Function to calculate the total salary of workers in a given department
int total_salary(Worker workers[], int n, char *depart) {
    int total_salary = 0;

    for (int i = 0; i < n; i++)
        if (!strcmp(workers[i].department, depart))
            total_salary += workers[i].salary;

    return total_salary;
}

// Function to print the worker with the maximum salary in each department
void max(Worker workers[], int n) {
    for (int i = 0; i < 3; i++) {
        Worker worker = max_salary_worker(workers, 8, departs_name[i]);

        char *joining_date = strtok(worker.joining_date, " ");

        printf(" %-6s| %-12s| %-11s| %-11d| %-12s| %-11s|\n",
            worker.worker_id, worker.first_name, worker.last_name, worker.salary, joining_date, worker.department
        );
    }
}

// Function to print the total salary for each department
void total(Worker workers[], int n) {
    for (int i = 0; i < 3; i++)
        printf("%s - %d\n", departs_name[i], total_salary(workers, n, departs_name[i]));
}

int main() {
    printf("\nName: Areeba Hasnain\nID:23K-0059\n");
    printf("\n");
    // Sample data for workers, bonuses, and titles
    Worker workers[8] = {
        {"001", "Monika", "Arora", 100000, "2014-02-20 09:00:00", "HR"},
        {"002", "Niharika", "Verma", 80000, "2014-06-11 09:00:00", "Admin"},
        {"003", "Vishal", "Singhal", 300000, "2014-02-20 09:00:00", "HR"},
        {"004", "Amitabh", "Singh", 500000, "2014-02-20 09:00:00", "Admin"},
        {"005", "Vivek", "Bhati", 500000, "2014-06-11 09:00:00", "Admin"},
        {"006", "Vipul", "Dewan", 200000, "2014-06-11 09:00:00", "Account"},
        {"007", "Satish", "Kumar", 75000, "2014-01-20 09:00:00", "Account"},
        {"008", "Geetika", "Chauhan", 90000, "2014-04-11 09:00:00", "Admin"},
    };

    Bonus bonuses[5] = {
        {1, "2016-02-20 00:00:00", 5000},
        {2, "2016-06-11 00:00:00", 3000},
        {3, "2016-02-20 00:00:00", 4000},
        {1, "2016-02-20 00:00:00", 4500},
        {2, "2016-06-11 00:00:00", 3500}
    };

    Title titles[8] = {
        {1, "Manager", "2016-02-20 00:00:00"},
        {2, "Executive", "2016-06-11 00:00:00"},
        {8, "Executive", "2016-06-11 00:00:00"},
        {5, "Manager", "2016-06-11 00:00:00"},
        {4, "Manager", "2016-06-11 00:00:00"},
        {7, "Asst. Manager", "2016-06-11 00:00:00"},
        {6, "Executive", "2016-06-11 00:00:00"},
        {3, "Lead", "2016-06-11 00:00:00"}
    };

    // Print the worker with the highest salary in each department
    printf("Highest salaries:\n");

    printf("_________________________________________________________________________\n");
   
    max(workers, 8);

    printf("_________________________________________________________________________\n");
    
    // Print the total salary for each department
    printf("\nTotal salaries:\n");
    total(workers, 8);

    return 0;
}
