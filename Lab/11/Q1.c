// Programmer: Areeba Hasnain
// Description: Create a student data structure, then print names of students who joined a specific year, 
// and the data of a student based on their roll number, with a maximum limit of 450 students.

#include <stdio.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 450

// Structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    char department[50];
    char course[50];
    int yearOfJoining;
};

// Function to print names of students who joined in a particular year
void printStudentsByYear(struct Student students[], int numStudents, int targetYear) {
    printf("Students who joined in the year %d:\n", targetYear);
    
    for (int i = 0; i < numStudents; i++) {
        if (students[i].yearOfJoining == targetYear) {
            printf("%s\n", students[i].name);
        }
    }
}

// Function to print the data of a student based on the roll number
void printStudentByRollNumber(struct Student students[], int numStudents, int targetRollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == targetRollNumber) {
            printf("Student Information:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].yearOfJoining);
            return; // Found the student, exit the function
        }
    }
    
    // If the function reaches here, the student with the specified roll number was not found
    printf("Student with Roll Number %d not found.\n", targetRollNumber);
}

int main() {
    // Example data for demonstration
    struct Student students[MAX_STUDENTS] = {
        {101, "John Doe", "Computer Science", "B.Tech", 2021},
        {102, "Jane Smith", "Electrical Engineering", "B.Tech", 2022},
        // Add more students as needed
    };

    int numStudents = 2;
    
    printStudentsByYear(students, numStudents, 2021);
    printf("\n");
    printStudentByRollNumber(students, numStudents, 102);
    
    return 0;
}
