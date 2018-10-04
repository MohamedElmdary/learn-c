#include <stdio.h>
#include <stdlib.h>

void displayStudentViaPhone(int error) {
    if (error == 1) printf("Invalid phone please enter valid one!\n");
    char phone[11];
    printf("Your phone = ");
    scanf("%s", &phone);
    int len = strlen(phone);
    if (len != 11) {
        return displayStudentViaPhone(1);
    }
    displayStudent(phone);
}

void displayStudent(char phone[11]) {
    char path[50];
    strcpy(path, "students/");
    strcat(path, phone);
    strcat(path, ".txt");
    if (isExist(path) == 0) {
        printf("User not found\nGood Bye!\n");
        exit(1);
    }
    char line[50];
    FILE *fileName = fopen(path, "r");
    printf("\n\n");
    int lines = 0;
    while (!feof(fileName)) {
        fgets(line, 50, fileName);
        if (lines > 0 && lines < 12) {
            printf("%s", line);
        }
        if (lines == 11) printf("\n\n");
        lines++;
    }
    fclose(fileName);
}