#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t parentPID = getppid();
    printf("Parent Process ID: %d\n", parentPID);
    return 0;
}

