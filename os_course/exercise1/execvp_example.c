#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	printf("Hello Parent!\n");
	sleep(1);
	int pid = fork();

	if ( pid == 0 )
	{
		printf( "Hello Child! \n" );
		puts( "Start of different executable binary! ==> " );
		execvp( "./hell_exec", NULL );
		puts( "Bye Child! " );
		sleep(1);
	}

	sleep(1);
	puts( "BYE PARENT" );
	return 0;
}
