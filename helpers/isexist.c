#include <unistd.h>

int isExist(char* path) {
    return access(path, F_OK) != -1 ? 1 : 0;
}