// Programmer: Areeba Hasnain
// Description: combine data from two files, namely "Department.txt" and "Personal.txt," and store the combined data in a 
// third file named "Combine.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("\nName: Areeba Hasnain\nID:23K-0059\n");
    printf("\n");
    // Open the input files for reading and the output file for appending
    FILE *departmentFile = fopen("Department.txt", "r");
    FILE *personalFile = fopen("Personal.txt", "r");
    FILE *combinedFile = fopen("Combine.txt", "a");

    // Temporary variables to store string data during processing
    char temp[20], combinedData[20], id[6];

    // Prompt user to enter an ID
    printf("Enter ID: ");
    scanf("%s", &id);

    // Read the first value (ID) from the "Personal.txt" file
    fscanf(personalFile, "%s", &combinedData);

    // Loop until the end of "Personal.txt" or until the desired ID is found
    while (!feof(personalFile) && (strcmp(id, combinedData)) != 0) {
        // Move to the next value
        fscanf(personalFile, "%s", &combinedData);

        // If the value is NULL, move to the next line using fgets
        if (combinedData == NULL)
            fgets(temp, 20, personalFile);
    }

    // Read the value next to the ID
    fscanf(personalFile, "%s", &temp);

    // Concatenate the values to form the combined data
    strcat(combinedData, " ");
    strcat(combinedData, temp);

    // Similar process for the "Department.txt" file
    fscanf(departmentFile, "%s", &temp);
    while ((strcmp(id, temp)) != 0) {
        fscanf(departmentFile, "%s", &temp);

        // If the value is NULL, move to the next line using fgets
        if (temp == NULL)
            fgets(temp, 20, departmentFile);
    }

    fscanf(departmentFile, "%s", &temp);
    strcat(combinedData, " ");
    strcat(combinedData, temp);

    // Write the combined data to the "Combine.txt" file
    fputs(combinedData, combinedFile);
    fprintf(combinedFile, "\n");

    // Close the file pointers
    fclose(departmentFile);
    fclose(personalFile);
    fclose(combinedFile);

    return 0;
}
