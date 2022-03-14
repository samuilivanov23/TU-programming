#include <iostream>
using namespace std;

int ExistsInResultNumbers( int number, int resultNumbersLength, int *numbers );

int main()
{
    int length = 7;
    int numbers[length] = {20, 100, 200, 100, 70, 20, 6};
    int resultNumbers[length];
    int result = 1;

    int j = 0;
    for( int i = 0; i < length-1; i++ )
    {
        if( numbers[i] + numbers[i+1] <= 120 )
        {
            if( !ExistsInResultNumbers( numbers[i], length, resultNumbers ) )
            {
                resultNumbers[j] = numbers[i];
                j++;
            }
            if( !ExistsInResultNumbers( numbers[i+1], length, resultNumbers ) )
            {
                resultNumbers[j] = numbers[i+1];
                j++;
            }
        }
    }

    for( int i = 0; i < j; i++ )
    {
        result *= resultNumbers[i];
    }

    cout << "Result: " << result << "\n";
    return 0;
}

int ExistsInResultNumbers( int number, int resultNumbersLength, int *resultNumbers )
{
    for ( int i = 0; i < resultNumbersLength; i++ )
    {
        if( number == resultNumbers[i] )
        {
            return 1;
        }
    }

    return 0;
}
