#include <stdio.h>
#include <stdlib.h>
#include "functions/hello.c"
#include "functions/addstudent.c"
#include "functions/displaystudent.c"
#include "functions/removestudent.c"

int main() {
    int c = displayHello();

    switch (c) {
        case 1:
            addStudent();
            break;
         case 2:
            displayStudentViaPhone(0);
            break;
        case 3:
            removeStudentViaPhone();
            break;
        /*case 4:
            break; */
        default:
            printf("good bye have a nice day!\n");
            exit(1);
    }

    return 0;
}