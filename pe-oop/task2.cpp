#include <iostream>
#include <math.h>

using namespace std;

class Time
{
    private:
        int hours, minutes, seconds, isTimeValid;
    public:
        Time(int hours, int minutes, int seconds);
        void PrintTime();
        int getIsTimeValid();
        ~Time()
        {
            cout << "Destructing Time object\n";
        }
};


Time::Time(int hours, int minutes, int seconds)
{
    if (hours >= 0 && hours <= 24)
    {
        this->hours = hours;
        this->isTimeValid = 1;
    }
    else 
    {
        cout << "Please enter a valid hours input\n";
        this->isTimeValid = 0;
    }

    if ( minutes >= 0 && minutes <= 59)
    {
        this->minutes = minutes;
        this->isTimeValid = 1;
    }
    else
    {
        cout << "Please enter a valid minutes input";
        this->isTimeValid = 0;
    }

    if (seconds >= 0 && seconds <= 59)
    {
        this->seconds = seconds;
        this->isTimeValid = 1;
    }
    else
    {
        cout << "Please enter a valid seconds input";
        this->isTimeValid = 0;
    }
}

int Time::getIsTimeValid()
{
    return this->isTimeValid;
}

void Time::PrintTime()
{
    cout << "Time is: " << hours << ":" << minutes << ":" << seconds << "\n"; 
}


int main()
{
    int hours, minutes, seconds;
    cout << "Enter hours: ";
    cin >> hours;

    cout << "Enter minuts: ";
    cin >> minutes;

    cout << "Enter seconds: ";
    cin >> seconds;

    Time obj1(hours, minutes, seconds);
    if(obj1.getIsTimeValid() == 1){ obj1.PrintTime(); }

    return 0;
}
