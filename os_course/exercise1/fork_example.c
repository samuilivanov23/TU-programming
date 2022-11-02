#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	int pid;
	pid = fork();
	printf("Hello: %d\n", pid);
	if (pid == 0)
	{
		printf("Child!\n");
	}
	else
	{
		printf("Parent!\n");
	}

	printf("Bye!\n");
	return 0;
}
