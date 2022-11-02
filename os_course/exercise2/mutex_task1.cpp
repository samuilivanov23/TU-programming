#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mtx;

void printBlock(int n, char c);

int main()
{
	thread th1(printBlock, 50, '*');
	thread th2(printBlock, 50, '$');

	th1.join();
	th2.join();

	return 0;
}

void printBlock(int n, char c)
{
	mtx.lock();
	cout << "Text here: " << c;
	for (int i=0; i<n; ++i)
	{
		cout << c;
	}

	cout << "\n";
	mtx.unlock();
}

