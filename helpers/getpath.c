#include <string.h>

const char* getPath(char phone[]) {
    char* path;
    strcpy(path, "students/");
    strcat(path, phone);
    strcat(path, ".txt");
    printf("path = %s\n", path);
    return path;
}
