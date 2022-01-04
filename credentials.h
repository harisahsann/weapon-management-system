#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_C 200




//  ************************************* Color Functions Definitions ************************************* //

void cyan()
{
    printf("\033[0;36m");
}
void purple()
{
    printf("\033[0;35m");
}
void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[0;34m");
}

void reset()
{
    printf("\033[0m");
}














//  ************************************* CREDENTIALS ************************************* //

typedef struct Credentials {
    char name[SIZE_C];
    char password[SIZE_C];
}cred;

cred creds[] = {
        {"Haris Ahsan","182"},
        {"Apple","Grey"},
        {"Snake","Knife"}
};

bool verify_credentials(char name[SIZE_C], char password[SIZE_C]) {
    char token_name[SIZE_C], token_password[SIZE_C];
    strcpy(token_name, strtok(name, "\n"));
    strcpy(token_password, strtok(password, "\n"));

    int creds_length = sizeof(creds) / sizeof(cred);
    bool valid_creds = false;
    bool password_verify = false;
    bool username_verify = false;

    for (int i = 0; i < creds_length; i++) {
        if (strcmp(token_name, creds[i].name) == 0) {
            username_verify = true;
            if (strcmp(token_password, creds[i].password) == 0) {
                password_verify = true;
                break;
            }
        }
    }
    red();
    if (!username_verify) {
        
        printf("\t\t\t\t************ Invalid Username! ************\n");
    }
    if (!password_verify) {
        printf("\t\t\t\t************ Invalid Password! ************\n");
        (void)getchar();
        system("cls");
    }

    if (username_verify && password_verify) {
        valid_creds = true;
    }

    return valid_creds;
}








//  ************************************* WELCOME NOTE ************************************* //
void first()
{

    int i, j;

    blue();
    printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DSA Project \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    red();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 50; i++)
    {
        for (j = 1; j <= 51000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
    blue();
    printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Presenter of this Project \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    red();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 50; i++)
    {
        for (j = 1; j <= 4000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
    red();
    printf("\n\t\t\t\t\t\t*******************************************");
    cyan();
    printf("\n\t\t\t\t\t|\t\t  Haris Ahsan  \t|");
    cyan();
    
    red();
    printf("\n\t\t\t\t\t\t*******************************************");
    purple();
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb MILITARY SYSTEM MANAGEMENT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    yellow();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 50; i++)
    {
        for (j = 1; j <= 4000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
}
