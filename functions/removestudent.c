#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeStudent(char password[], char phone[]) {
    printf("student password = %s", password);
    printf("student phone = %s", phone);
}

void removeStudentViaPhone() {
    char path[50];
    char phone[11];
    printf("Enter you phone = ");
    scanf("%s", phone);
    strcpy(path, "students/");
    strcat(path, phone);
    strcat(path, ".txt");
    if (isExist(path) == 0) {
        printf("User not found!");
        exit(1);
    }
    char password[12];
    printf("Your password = ");
    scanf("%s", password);
    char savedPass[12];
    FILE *fileName = fopen(path, "r");
    fgets(savedPass, 12, fileName);
    fclose(fileName);
    int len = strlen(password);
    if (len < 6) {
        printf("\nInvalid password\n");
        exit(1);
    }
    for(int i = 0; i < len; i++) {
        if (password[i] != savedPass[i]) {
            printf("\nInvalid password\n");
            exit(1);
        }
    }
    remove(path);
    printf("\nUser removed successfully!\n\n");
}

