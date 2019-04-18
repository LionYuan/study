#include <unistd.h>
int main()
{
	pid_t pid = 0;
	pid = fork();
	printf("children pid = %d\n", pid);
	printf("parent pid = %d\n", getppid());
	return 0;
}
