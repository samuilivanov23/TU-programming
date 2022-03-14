#include <iostream>
using namespace std;

int main() 
{
    int xn = 2;
    int result = 2*xn + 10;

    while( result < 100 )
    {
        xn = result;
        result = 2*xn + 10;
    }

    cout << "Result: " << result << "\n";
}
