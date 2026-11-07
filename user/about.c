// about.c
// This program was written by Alexander Myska for COM S 3520 Project 1A.
// It writes my name, and optionally takes in an argument as well, printing it on a new line if provided.

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
    printf("COM S 3520 Project 1A\n");
    printf("Student: Alexander Myska\n");
    if (argc > 1) {
        printf("Argument: %s\n", argv[1]);
    }
    exit(0);
}