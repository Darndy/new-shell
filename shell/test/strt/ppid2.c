#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("ppid = %d\n", ppid);
	return 0;
}
