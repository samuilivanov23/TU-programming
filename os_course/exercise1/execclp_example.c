#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("ps with execlp\n");
	execlp("ps", "ps", 0);
	printf("Bye!\n");
	exit(0);
}
