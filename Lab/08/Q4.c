// Programmer: Areeba Hasnain
// Date: 24/10/23
// Description:Verifying password

#include <stdio.h>
#include<string.h>

int main()
{
    char password[1000];
    char storedPassword[] = "Secure123";
   
    printf("Enter password\n");
    scanf(" %s", &password);
   
    if(strlen(password) >= 8){
        if (strcmp(password, storedPassword) == 0){
            printf("Login Successful. WELCOME!");
        }
        else{
            printf("Login Failed. Incorrect Password\n");
        }
    }
    else
    {
        printf("Password must be atleast 8 characters");
    }
    return 0;
}
