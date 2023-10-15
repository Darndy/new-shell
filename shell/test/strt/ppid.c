#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("pid = %d\n", pid);
	printf("ppid = %d\n", ppid);

	return 0;
}
