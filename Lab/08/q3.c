// Programmer: Areeba Hasnain
// Date: 24/10/23
// Description: counting how many times a character comes in a string
#include <stdio.h>
#include <string.h>

int count(char *str, char ch) {
    int c = 0;
    for (char *ptr = strchr(str, ch); ptr != NULL; ptr = strchr(ptr + 1, ch)) c++;
    return c;  
} // count(char *, char)

int main() {
    char str[100];
    char ch;

    printf("Enter your text:\n");
    gets(str);
    printf("Enter character to find: ");
    scanf(" %c", &ch);

    printf("%d times", count(str, ch));

    return 0;
} // main()