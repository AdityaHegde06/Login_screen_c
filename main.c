
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menu();
void signup();
void login();
void forget();
void change_password();
void delete_account();
void takepassword(char* pass);

struct account {
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone[15];
    char gender;
    char DOB[10];
    char password[50];
};

int main() {
    while (1) {
        switch (menu()) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                forget();
                break;
            case 4:
                change_password();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}

int menu() {
    int c;
    printf("MAIN MENU\n");
    printf("1. SIGNUP\n");
    printf("2. LOGIN\n");
    printf("3. FORGET PASSWORD OR USERNAME\n");
    printf("4. CHANGE PASSWORD\n");
    printf("5. DELETE ACCOUNT\n");
    printf("6. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    return c;
}

void takepassword(char* pass) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == 13) { // Enter key
            pass[i] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (ch == 9 || ch == 32) { // Tab or Space key
            continue;
        } else if (i < 49) { // Limit input to 49 characters
            pass[i++] = ch;
            printf("*");
        }
    }
}

void signup() {
    struct account u;
    char pass2[50];

    printf("CREATING NEW ACCOUNT\n");
    printf("Enter your first name: ");
    scanf("%s", u.first_name);
    printf("Enter last name: ");
    scanf("%s", u.last_name);
    printf("Enter your username: ");
    scanf("%s", u.username);
    printf("Enter your phone number: ");
    scanf("%s", u.phone);
    printf("Enter Gender: ");
    scanf(" %c", &u.gender); // Note the space before %c to consume any leftover newline character
    printf("Enter your DOB (DD/MM/YYYY): ");
    scanf("%s", u.DOB);

    // We are not using scanf to show the password, so we are making another function
    printf("Enter password: ");
    takepassword(u.password);

    // Ask the user to confirm the password
    printf("\nConfirm password: ");
    takepassword(pass2);

    if (strcmp(u.password, pass2) != 0) {
        printf("\nPasswords do not match. Please try again.\n");
    } else {
        printf("\nACCOUNT CREATED SUCCESSFULLY\n");
        // Save account to a file or database

        FILE *fp = fopen("account.txt", "w");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return;
        }
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);
    }
    getch(); // Wait for user input before returning to the menu
}

void login() {
    // Implementation for login
}

void forget() {
    struct account u;
    char username[30], password[50], phone_no[15];
    char choice;

    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fread(&u, sizeof(struct account), 1, fp);
    fclose(fp);

    printf("\n1. Search by username\n");
    printf("2. Search by password\n");
    printf("3. Search by phone no\n");
    printf("4. MAIN MENU\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            printf("Enter the username: ");
            scanf("%s", username);
            if (strcmp(username, u.username) != 0) {
                printf("Username not found\n");
            } else {
                printf("ACCOUNT FOUND\n");
                printf("Username: %s\n", u.username);
                printf("First name: %s\n", u.first_name);
                printf("Last name: %s\n", u.last_name);
                printf("Phone no: %s\n", u.phone);
                printf("Password: %s\n", u.password);
            }
            break;
        case '2':
            printf("Enter the password: ");
            scanf("%s", password);
            if (strcmp(password, u.password) != 0) {
                printf("Password not found\n");
            } else {
                printf("ACCOUNT FOUND\n");
                printf("Username: %s\n", u.username);
                printf("First name: %s\n", u.first_name);
                printf("Last name: %s\n", u.last_name);
                printf("Phone no: %s\n", u.phone);
                printf("Password: %s\n", u.password);
            }
            break;
        case '3':
            printf("Enter the phone no: ");
            scanf("%s", phone_no);
            if (strcmp(phone_no, u.phone) != 0) {
                printf("Phone no not found\n");
            } else {
                printf("ACCOUNT FOUND\n");
                printf("Username: %s\n", u.username);
                printf("First name: %s\n", u.first_name);
                printf("Last name: %s\n", u.last_name);
                printf("Phone no: %s\n", u.phone);
                printf("Password: %s\n", u.password);
            }
            break;
        case '4':
            return;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void change_password() {
    // Implementation for changing password
}

void delete_account() {
    // Implementation for deleting account
}
