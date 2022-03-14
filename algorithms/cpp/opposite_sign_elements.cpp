#include <iostream>
using namespace std;

int main() 
{
    int numbers[] = {1, -2, 3, 4, 5, -6};
    int length = 6;
    int oppositeSignElementsCount = 0;
    
    int j = 1;
    for( int i=0; i < length-1; i++ )
    {
        if( ( numbers[i] > 0 && numbers[j] < 0 ) || ( numbers[i] < 0 && numbers[j] > 0 ) )
        {
            oppositeSignElementsCount++;
        }

        j++;
    }

    cout << "opposite sign elements count: " << oppositeSignElementsCount << "\n";

    return 0;
}
