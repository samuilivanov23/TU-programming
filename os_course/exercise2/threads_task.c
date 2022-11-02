#include <stdio.h>
#include <pthread.h>

void* PrintText(void* text);

int main()
{
	pthread_t th1, th2, th3;
	int ret1, ret2, ret3;
	
	char text1[] = "\n Hello 1 \n";
	char text2[] = "\n Hello 2 \n";
	char text3[] = "\n Hello 3 \n";

	ret1 = pthread_create(&th1, NULL, PrintText, text1);
	ret2 = pthread_create(&th2, NULL, PrintText, text2);
	ret3 = pthread_create(&th3, NULL, PrintText, text3);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);

	return 0;
}

void* PrintText(void* text)
{
	for(int i = 0; i < 10; i++)
	{
		printf("%s", text);
	}
}
