#include <stdio.h>
int main() {
	int num1, num2;
	char operation;
	printf("Operations -> '+', '-', '*', '/' OR press 'D' to exit.\n");
	do {

		printf("Input choice: ");
		scanf(" %c", &operation);

		if (operation == 'd' || operation == 'D') {
			break;
		};
	
		printf("Input first number: ");
		scanf("%d", &num1);
		printf("Input second number: ");
		scanf("%d", &num2);
		if (operation == '+') {
			printf("Answer: %d\n", num1 + num2);
		} else if (operation == '-') {
			printf("Answer: %d\n", num1 - num2);
		} else if (operation == '*') {
			printf("Answer: %d\n", num1 * num2);
		} else if (operation == '/') {
			printf("Answer: %.1f\n", (float) num1 / num2);
		};

	} while(1);

	return 0;
}; // end main()
