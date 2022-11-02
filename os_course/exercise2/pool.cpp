#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex mutexPool;
int currentPoolCapacity = 0;
int maxPoolCapacity = 5000;

void threadFunction(int updateVolume, int sleepMiliseconds);

int main()
{
	int timeRunning = 0;
	thread *th1, *th2, *th3;

	th1 = new thread(threadFunction, 10, 30);
	th2 = new thread(threadFunction, -50, 70);
	th3 = new thread(threadFunction, -300, 1000);

	while(true)
	{
		mutexPool.lock();
		printf("Time: %d -> Pool Capacity: %d\n", timeRunning, currentPoolCapacity);
		mutexPool.unlock();
		timeRunning++;
		this_thread::sleep_for(chrono::seconds(1));
	}

	th1->join();
	th2->join();
	th3->join();

	return 0;
}


void threadFunction(int updateVolume, int sleepMilliseconds)
{
	bool sleepFlag;
	
	while(true)
	{
		mutexPool.lock();

		if((currentPoolCapacity+updateVolume > maxPoolCapacity) || (currentPoolCapacity + updateVolume < 0))
		{
			sleepFlag = 1;
		}
		else
		{
			currentPoolCapacity += updateVolume;
		}
		
		mutexPool.unlock();

		if(sleepFlag)
		{
			this_thread::sleep_for(chrono::seconds(1));
			sleepFlag = false;
		}
		else
		{
			this_thread::sleep_for(chrono::milliseconds(sleepMilliseconds));
		}
	}
}
