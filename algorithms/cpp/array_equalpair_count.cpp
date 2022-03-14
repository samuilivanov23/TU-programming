#include <iostream>
using namespace std;

int main() 
{
    int length = 8;
    int numbers[length] = {1, 2, 3, 4, 4, 5, 6, 6};
    int countEqualPairs = 0;

    for( int i = 0; i < length-1; i++ )
    {
        if( numbers[i] == numbers[i+1] )
        {
            countEqualPairs++;
        }
    }

    cout << "Count of equal pairs: " << countEqualPairs << "\n";
    
    return 0;
}
