#include <iostream>

using namespace std;

int main()
{
  int number;
  int sum = 0;

  do 
  {
    cout << "Enter number: ";
    cin >> number;  
  }
  while( number < 99 );

  while( number > 0 )
  {
    sum += number % 10;
    
    number /= 10;
  }

  cout << "sum: " << sum << "\n";

  return 0;
}
