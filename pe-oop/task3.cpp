#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Worker
{
    private:
        int socialNumber, age, yearsOfExperience;
        string name;
        string employmentPosition;
        int* salariesTaken;
    public:
        Worker(int socialNumber, int age);
        Worker(string employmentPosition);
        
        int getSocialNumber();
        void setSocialNumber(int socialNumber);

        int getAge();
        void setAge(int age);

        int getYearsOfExperience();
        void setYearsOfExperience(int yearsOfExperience);

        string getName();
        void setName(string name);

        string getEmploymentPosition();
        void setEmploymentPosition(string employmentPosition);

        int* getSalariesTaken();
        void setSalariesTaken(int* salariesTaken);

        double GetAverageSalary();
        int GetMinSalary();
};

Worker::Worker(int socialNumber, int age)
{
    this->setSocialNumber(socialNumber);
    this->setAge(age);
}

Worker::Worker(string employmentPosition)
{
    this->setEmploymentPosition(employmentPosition);
}

int Worker::getSocialNumber()
{
    return this->socialNumber;
}

void Worker::setSocialNumber(int socialNumber)
{
    if(socialNumber > 0)
    {
        this->socialNumber = socialNumber;
    }
    else
    {
        cout << "Please enter valid social number greater than 0!";
    }
}

int Worker::getAge()
{
    return this->age;
}

void Worker::setAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
    else
    {
        cout << "Please enter a valid age number greater than 0!";
    }
}

string Worker::getEmploymentPosition()
{
    return this->employmentPosition;
}

void Worker::setEmploymentPosition(string employmentPosition)
{
    this->employmentPosition = employmentPosition;
}

int Worker::getYearsOfExperience()
{
    return this->yearsOfExperience;
}

void Worker::setYearsOfExperience(int yearsOfExperience)
{
    if(yearsOfExperience > 0)
    {
        this->yearsOfExperience = yearsOfExperience;
    }
    else
    {
        cout << "Please enter valid years of experience greater than 0!";
    }
}


int* Worker::getSalariesTaken()
{
    return this->salariesTaken;
}

void Worker::setSalariesTaken(int* salariesTaken)
{
    this->salariesTaken = salariesTaken;
}

double Worker::GetAverageSalary()
{
    int currentSalarySum = 0;
    int arraySize = sizeof(this->salariesTaken) / sizeof(int);
    for (int i = 0; i < arraySize; i++)
    {
        currentSalarySum+=this->salariesTaken[i];
    }

    return double(currentSalarySum)/arraySize;
}

int Worker::GetMinSalary()
{
    int currentMinSalary = salariesTaken[0];
    int arraySize = sizeof(this->salariesTaken) / sizeof(int);
    for(int i = 1; i < arraySize; i++)
    {
        if(currentMinSalary < salariesTaken[i])
        {
            currentMinSalary = salariesTaken[i];
        }
    }

    return currentMinSalary;
}

int main()
{
    int socialNumber, age, yearsOfExperience, countSalariesTaken;
    cout << "Enter social number: ";
    cin >> socialNumber;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter years of experience: ";
    cin >> yearsOfExperience;

    Worker worker(socialNumber, age);    

    cout << "Enter count of salaries taken: ";
    cin >> countSalariesTaken;

    for (int i = 0; i < countSalariesTaken; i++)
    {
    
    }


    return 0;
}
