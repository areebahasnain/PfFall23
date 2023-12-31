#include <stdio.h>

void print_spiral(int spiral[][100], int n)
{
	for (int i = 0; i < n && printf("\n"); i++) for (int j = 0; j < n; j++) printf("%-3d ", spiral[i][j]);
}  

void create_spiral(int spiral[][100], int n, int type) {
	int p, j, dir, i = 0;

	// creating spiral
	if (type) {
		p = 1;
		j = 0;
		dir = 1;
	} else {
		p = n*n;
		j = n-1;
		dir = 3;
	}

	// spiral loop
	for (; (p <= n*n && type) || (p >= 1 && !type); (type) ? p++ : p--) { //If type is true, p is incremented, otherwise, p is decremented.
		spiral[i][j] = p;

		switch (dir) {
			case 1: // right
				if (j+1 < n && !spiral[i][j+1]) j++;
				else { // changing directions
					if (type) {dir++;i++;}
					else {dir=4;i--;} 
				}
				break;
			case 2: // down
				if (i+1 < n && !spiral[i+1][j]) i++;
				else { // changing directions 
					if (type) {dir++;j--;}
					else {dir--;j++;} 
				}
				break;
			case 3: // left
				if (j > 0 && !spiral[i][j-1]) j--;
				else { // changing directions
					if (type) {dir++;i--;}
					else {dir--;i++;}
				}
				break;
			case 4: // up
				if (i > 0 && !spiral[i-1][j]) i--; 
				else { // changing directions
					if (type) {dir=1;j++;}
					else {dir--;j--;}
				}
				break;
		}
	}
} 

int main() 
{
	int spiral[100][100] = {0}, n, type;

	printf("Enter spiral length: ");
	scanf("%d", &n);
	printf("Enter spiral type\nInwards - 1\nOutwards - 0\n= ");
	scanf("%d", &type);

	create_spiral(spiral, n, type);
	print_spiral(spiral, n);

	return 0;
} // end main()