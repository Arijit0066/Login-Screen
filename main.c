#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

int menu();
void signup();
void takePass(char pass[20]);
void login();
void forgot();
void change_password();
void delete_account();
void change_username();

struct account
{
    char firstName[20];
    char lastName[20];
    char userName[20];
    char gender[20];
    char pass1[20];
};

int main()
{
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            forgot();
            break;

        case 4:
            change_password();
            break;

        case 5:
            delete_account();
            break;

        case 6:
            change_username();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

int menu()
{
    int c;
    system("cls");
    printf("\t\t\t  Developed By Arijit.\n");
    printf("\n");
    printf("***********MAIN MENU***********\n");
    printf("1. Signup\n");
    printf("2. Login\n");
    printf("3. Forgot\n");
    printf("4. Change Password\n");
    printf("5. Delete Account\n");
    printf("6. Change Username\n");
    printf("7. Exit");
    printf("\nENTER YOUR CHOICE = ");
    scanf("%d", &c);
    return c;
}

void takePass(char pass[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            i--;
            printf("\b \b");
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}

void signup()
{

    system("cls");
    struct account u;
    char save[100];
    char confPass[20];

    printf("Enter First Name = ");
    scanf("%s", u.firstName);
    printf("Enter Last Name = ");
    scanf("%s", u.lastName);
    printf("Enter UserName = ");
    scanf("%s", u.userName);
    printf("Enter Your Gender = ");
    scanf("%s", u.gender);

    printf("Enter Password = ");
    takePass(u.pass1);

conf_pass:

    printf("\nEnter Confirm Password = ");
    scanf("%s", confPass);

    if (strcmp(u.pass1, confPass))
    {
        printf("INCORRECT PASSWORD\n");
        goto conf_pass;
    }
    else
    {
        printf("ACCOUNT CREATED SUCESSFULLY(Press Up Key for Save Details)\n");
        getch();

        FILE *fptr;
        fptr = fopen("account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fptr);
        fclose(fptr);
    }
}

void login()
{

    struct account u;
    char userLogName[20];
    char passwordUser[20];

    FILE *fptr;
    fptr = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fptr);

user:
    printf("Enter Your Username = ");
    scanf("%s", userLogName);

    if (strcmp(userLogName, u.userName))
    {
        printf("\nPlease Enter Correct Username\n");
        goto user;
    }
    else
    {

    pass:
        printf("Enter Password = ");
        takePass(passwordUser);
        if (strcmp(passwordUser, u.pass1))
        {
            printf("\nPlease Enter Correct Password\n");
            goto pass;
        }
        else
        {   
            system("cls");
            printf("\n");
            printf("\n\tWelcome %s\n", u.firstName);
            printf("\n***********Your Details***********\n");
            printf("\n");
            printf("First Name   :   %s\n", u.firstName);
            printf("Last Name   :   %s\n", u.lastName);
            printf("Username   :   %s\n", u.userName);
            printf("Passsword   :   %s\n", u.pass1);
            printf("Gender   :   %s\n", u.gender);
        }
        getch();
    }
    fclose(fptr);
}

void forgot()
{   
    system("cls");
    struct account u;
    FILE *fptr = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fptr);

    char userNameFor[20];
    char passFor[20];
    int choice;
    printf("1. Search By Username\n");
    printf("2. Search By Password\n");
    printf("3. Main Menu\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter Username = ");
        scanf("%s", userNameFor);

        if (strcmp(userNameFor, u.userName))
        {
            printf("\nAccount Not Found\n");
            getch();
        }
        else
        {
            printf("\n\t  Welcome %s\n", u.firstName);
            printf("***********Your Details***********");
            printf("\n");
            printf("firstname = %s\n", u.firstName);
            printf("LastName = %s\n", u.lastName);
            printf("Your Username = %s\n", u.userName);
            printf("Your Password = %s\n", u.pass1);
            printf("Gender %s", u.gender);
            getch();
        }
        break;

    case 2:
        printf("Enter Your Password = ");
        scanf("%s", passFor);
        if (strcmp(passFor, u.pass1))
        {
            printf("\nACCOUNT NOT FOUND\n");
            getch();
        }
        else
        {
            printf("\n\tWelcome %s\n", u.userName);
            printf("***********Your Details***********");
            printf("\n");
            printf("firstname = %s\n", u.firstName);
            printf("LastName = %s\n", u.lastName);
            printf("Your Username = %s\n", u.userName);
            printf("Your Password = %s\n", u.pass1);
            printf("Gender %s", u.gender);
            getch();
        }
    case 3:
        return;

    default:
        printf("\nINVALID CHOICE\n");
        break;
    }
    fclose(fptr);
}

void change_password()
{
    int num1, num2;
    char passChange[20];

correctnumber:

    srand(time(0));
    num1 = rand();
    printf("%d\n", num1);
    printf("Enter The Number = ");
    scanf("%d", &num2);

    if (num1 == num2)
    {
        struct account u;
        FILE *fptr = fopen("account.txt", "r");
        fread(&u, sizeof(u), 1, fptr);

        printf("Enter New Password = ");
        takePass(u.pass1);
    pass:
        // we change the password here, after knowing the password, save the new password there on u.pass1;😊

        printf("\nConfirm Password = ");
        scanf("%s", passChange);
        if (strcmp(u.pass1, passChange))
        {
            printf("\nENTER CORRECT PASSWORD\n");
            goto pass;
            getch();
        }
        else
        {
            FILE *fptr = fopen("account.txt", "w");
            fwrite(&u, sizeof(u), 1, fptr);
            printf("\nPASSWORD CHANGED SUCCESSFULLY\n");
            getch();
        }
        fclose(fptr);
    }
    else
    {
        printf("\nPLEASE ENTER CORRECT NUMBER\n");
        goto correctnumber;
    }
}

void delete_account()
{
    FILE *fptr = fopen("account.txt", "r");

    printf("\nARE YOU SURE[Y/N] = \n");
    char ch = getch();
    if (ch == 'Y' || ch == 'y')
    {
        fprintf(fptr, " ");
        printf("ACCOUNT DELETED SUCCESSFULL\n");
        getch();
    }
    else if (ch == 'N' || ch == 'n')
    {
        printf("\nSTOPPED\n");
        getch();
    }
    fclose(fptr);
}

void change_username()
{
    system("cls");
    int user1, user2;
number:
    srand(time(0));
    user1 = rand();
    printf("Number : %d", user1);
    printf("\nEnter The Number = ");
    scanf("%d", &user2);

    struct account u;
    FILE *fptr = fopen("account.txt", "r");
    fread(&u, sizeof(u), 1, fptr);

    if(user1 == user2)
    {
        printf("Enter New Username = ");
        scanf("%s", u.userName);
        FILE *fptr = fopen("account.txt", "w");
        fwrite(&u, sizeof(u), 1, fptr);
        fclose(fptr);
        printf("\nUSERNAME CHANGED SUCCESSFULLY\n");
        getch();
    }
    else
    {
        printf("\nENTER THE CORRECT NUMBER\n");
        goto number;
    }


}
