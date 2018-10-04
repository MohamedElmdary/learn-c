#include <stdio.h>

int displayHello() {
    printf("#####################################################");
    printf("\n##        welcome in school project (c project)    ##\n");
    printf("#####################################################\n\n");
    printf("\t please choose one of the follow:\n");
    printf("1> add new student\n");
    printf("2> display a student\n");
    // printf("3> edit existed student\n"); maybe later
    printf("3> remove a student\n");
    printf("*> exit\n\n");
    return chooseAFunction(0);
}

int chooseAFunction(int inValid) {
    int c;
    if (inValid == 1) {
        printf("please choose correct number (1-2-3-4-5).\n");
    }
    printf(">> ");
    scanf("%d", &c);
    switch (c) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return c;
        default:
            return chooseAFunction(1);
    }
}