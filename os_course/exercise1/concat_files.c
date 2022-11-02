#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc ,char** argv)
{
	int fd;
	char buff[120];
	fd = open(argv[1], O_RDWR | O_CREAT);
	if (fd == -1)
	{
		perror("File cannot be opened");
		return EXIT_FAILURE;
	}

	scanf("%s\n", buff);
	write(fd, buff, strlen(buff));

	close(fd);
	return 0;
}
