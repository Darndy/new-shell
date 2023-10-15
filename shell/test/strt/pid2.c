#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("pid = %d\n", pid);
	return 0;
}
