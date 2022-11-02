#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void foo();
void bar(int x);

int main()
{
	thread first(foo);
	thread second(bar, 30);

	cout << "main, foo and bar now execute concurrently...\n";

	cout << "foo and bar starting execution\n";

	first.join();
	second.join();

	cout << "foo and bar thread completed.\n";

	return 0;
}

void foo()
{
	cout << "Waiting 1 second...\n";
	sleep(1);
	cout << "Thread 1 completed execution\n";
}

void bar(int x)
{
	cout << "Waiting 3 seconds...\n";
	sleep(3);
	cout << "Thread 2 completed execution" << " " << x << "  \n";
}

