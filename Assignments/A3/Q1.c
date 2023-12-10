#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 


// Dynamic allocation of the matrix
int **create_matrix(int n) {
    int **mat = (int **)malloc(sizeof(int *) * n);
    int *block = (int *)malloc(sizeof(int) * n * n);

    for (int i = 0; i < n; i++)
        mat[i] = block + i * n;

    return mat;
}

void read_file_matrix(FILE *fp, int **mat, int n) {
    char buffer[100];

    for (int i = 0; i < n; i++) {
        if (fgets(buffer, 100, fp) == NULL) {
            fprintf(stderr, "Error reading from file\n");
            exit(EXIT_FAILURE);
        }
        buffer[strcspn(buffer, "\n")] = 0; // Remove new line

        // Read through space-separated values in the file
        char *num = strtok(buffer, " ");
        for (int j = 0; num != NULL && j < n; j++) {
            mat[i][j] = atoi(num);
            num = strtok(NULL, " ");
        }
    }
}

void print_matrix(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-3d ", mat[i][j]);
        }
        printf("\n");
    }
}

int max(int **mat, int i, int j, int n) {
    int max_val = INT_MIN;

    // Checking for the entire square matrix's positions
    for (int k = 0, check[] = {0, 0, 1, 0, 1, 1, 0, 1}; k < 8;) {
        max_val = (mat[i + check[k++]][j + check[k++]] > max_val) ? mat[i + check[k - 2]][j + check[k - 1]] : max_val;
    }

    return max_val;
}

int **get_sub_matrix(int **mat, int n) {
    int **sub_mat = create_matrix(n / 2);

    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            // Assign max value to the sub matrix
            sub_mat[i / 2][j / 2] = max(mat, i, j, n);
        }
    }

    return sub_mat;
}

int main(int argc, char const *argv[]) {
    printf("\nName: Areeba Hasnain\nID:23K-0059\n");
    printf("\n");
		 
    // Check for the correct number of command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dimension> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);

    // Validate the dimension
    while (!(n == 2 || n == 4 || n == 8)) {
        printf("Incorrect dimension\nEnter dimension again: ");
        scanf("%d", &n);
    }

    FILE *fp = fopen(argv[2], "r");

    // Check if the file is successfully opened
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }

    int **mat = create_matrix(n);
    read_file_matrix(fp, mat, n);
    fclose(fp); // Close the file after reading

    printf("\nOriginal Matrix:\n");
    print_matrix(mat, n);

    int **sub_mat = get_sub_matrix(mat, n);
    printf("\nSubmatrix with Maximum Values:\n");
    print_matrix(sub_mat, n / 2);

    // Free original matrix
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    // Free submatrix
    for (int i = 0; i < n / 2; i++) {
        free(sub_mat[i]);
    }
    free(sub_mat);

    return EXIT_SUCCESS;
}
