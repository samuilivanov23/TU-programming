#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int counter;
pthread_mutex_t lock;

void* Print(void * arg)
{
	pthread_mutex_lock(&lock);
	unsigned long i = 0;
	counter+=1;

	printf("\n Job %d started \n", counter);
	sleep(10);
	printf("\n Job %d finished \n", counter);
	pthread_mutex_unlock(&lock);

	return NULL;

}

int main()
{
	pthread_t th1, th2;
	int err1, err2;

	err1 = pthread_create(&th1, NULL, Print, NULL);
	err2 = pthread_create(&th2, NULL, Print, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
