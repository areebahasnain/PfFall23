// Programmer: Areeba Hasnain
// Date: 23/10/23
// Description: find a path in a 2D maze from the starting point to the exit
#include <stdio.h>
#include <stdbool.h>

bool solve(char arr[][5], char temp[][5], int m, int n, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || arr[x][y] == 'W' || temp[x][y] == '1')
        return false;

    temp[x][y] = '1';

    if (arr[x][y] == 'E')
        return true;

    if (solve(arr, temp, m, n, x + 1, y) || solve(arr, temp, m, n, x, y + 1))
        return true;

    temp[x][y] = '0';
    return false;
}

int main() {
    char maze[5][5] = {
        {'S', 'O', 'O', 'W', 'W'},
        {'O', 'W', 'O', 'O', 'W'},
        {'O', 'O', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'E', 'W'} };

    char temp[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[i][j] = '0';
        }
    }

    if (solve(maze, temp, 5, 5, 0, 0)) {
        printf("Output: ");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (temp[i][j] == '1') {
                    printf("(%d,%d) ", i, j);
                }
            }
        }
        printf("\n");
    }
    else {
        printf("No path found.\n");
    }

    return 0;
}