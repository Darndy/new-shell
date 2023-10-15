#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t parentPID = getppid();
    char pidString[15];
    sprintf(pidString, "%d", parentPID);
    puts("Parent Process ID: ");
    puts(pidString);
    return 0;
}

