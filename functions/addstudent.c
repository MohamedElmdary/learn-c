#include <stdio.h>
#include <stdlib.h>
#include "../helpers/student.c"
#include "../helpers/isexist.c"
// #include "../helpers/getpath.c"

char path[50];
const struct Student getUserData() {
    struct Student student;
    int len;

/* take first name from user */
    char firstName[10];
    while(1) {
        printf("Enter your first name = ");
        scanf("%s", firstName);
        len = strlen(firstName);
        if (len < 2) {
            printf("Invalid first name min length 2 chars\n");
            continue;
        } else {
            strcpy(student.firstName, firstName);
            break;
        }
    }
    
/* take last name from user */
    char lastName[10];
    while(1) {
        printf("Enter your last name = ");
        scanf("%s", lastName);
        len = strlen(lastName);
        if (len < 2) {
            printf("Invalid last name min length 2 chars\n");
            continue;
        } else {
            strcpy(student.lastName, lastName);
            break;
        }
    }

/* take age from user */
    int age;
    while(1) {
        printf("Enter your age = ");
        scanf("%d", &age);
        if (age < 7 || age > 30) {
            printf("ages range 7 to 30\n");
            continue;
        } else {
            student.age = age;
            break;
        }
    }

/* take grade from user */
    char grade;
    while(1) {
        printf("Enter grade (A, B, C, D) = ");
        scanf(" %c", &grade);
        if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D') {
            printf("Invalid grade only allowed A-B-C-D\n");
            printf("%s\n", grade);
            continue;
        } else {
            student.grade = grade;
            break;
        }
    }

/* take phone from user */
    int phone;
    char phe[15];
    while(1) {
        printf("Your phone number = ");
        scanf("%d", &phone);
        if (!(  phone < 100000000000 &&
                phone > 999999999 &&
                (phone >> 2) > 99999999
            )) {
            printf("Invalid phone.\n");
            continue;
        } else {
            sprintf(phe, "%d", phone);
            strcpy(path, "students/");
            strcat(path, "0");
            strcat(path, phe);
            strcat(path, ".txt");
            if (isExist(path) == 1) {
                printf("User already exist\nyou tried to make something forbidden\n");
                exit(1);
            }
            student.phone = phone;
            break;
        }
    }

/* take password from user */
    char password[12];
    while(1) {
        printf("provide a strong password to make sure your info is safe\n");
        printf("password will be required to edit/remove a student\n");
        printf("Enter strong password (min 6, max 12) = ");
        scanf("%s", password);
        len = strlen(password);
        if (len < 6) {
            printf("password min length is 6\n");
            continue;
        } else {
            strcpy(student.password, password);
            break;
        }
    }

    return student;
}

const int addStudent() {
    struct Student student = getUserData();
    printf("path %s\n", path);
    FILE* newStudent = fopen(path, "w");

    char line[] = "############################\n";
    fprintf(
        newStudent,  
        "%s\n%s  first name # %s \n%s  last name  # %s \n%s     age     # %d \n%s    phone    # %d \n%s     grade   # %c \n%s",
        student.password,
        line,
        student.firstName,
        line,
        student.lastName,
        line,
        student.age,
        line,
        student.phone,
        line,
        student.grade,
        line);

    fclose(newStudent);
    return 0;
}


/* 
############################
# first name # mmmmmmmmmm  #
############################
# last name  # mmmmmmmmmm  #  
############################
# age        # 21          #
############################
# phone      # 01282859139 #
############################
# grade      # A           #
############################
 */ 