// Programmer: Areeba Hasnain
// Date: 24/10/23
// Description:creating basic arithemetic operations using function

#include <stdio.h>
void calculate(int num1, int num2, char operation)
{
    int ans;
    switch(operation)
    {
        case '+':
            ans = num1 + num2;
            printf("%d + %d = %d", num1, num2, ans);
            break;
        case '-':
            ans = num1 - num2;
            printf("%d - %d = %d", num1, num2, ans);
            break;
        case '*':
            ans = num1 * num2;
            printf("%d x %d = %d", num1, num2, ans);
            break;
        case '/':
            printf("%d / %d = %d", num1, num2, ans);
            ans = num1 / num2;
            break;
    }
     
}


int main()
{
  int num1, num2, ans;
  char operation;
 
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  printf("Enter an arithemetic operation: ");
  scanf(" %c", &operation);
 
  calculate(num1, num2, operation);
 
    return 0;
}
